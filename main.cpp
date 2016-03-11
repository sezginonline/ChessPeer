//---------------------------------------------------------------------------
#include <vcl.h>
#pragma hdrstop

#include "Main.h"
#include "About.h"
#include "ChildWin.h"
#include "Unit1.h"
#include "Unit2.h"
//---------------------------------------------------------------------------
#pragma link "RegExtension"
#pragma resource "*.dfm"
TMainForm *MainForm;
//---------------------------------------------------------------------------
__fastcall TMainForm::TMainForm(TComponent *Owner)
	: TForm(Owner)
{
 try
 {
  AnsiString CursorFile = ExtractFilePath(Application->ExeName) + "Images\\move.cur";
  HCURSOR hCursor = LoadCursorFromFile(CursorFile.c_str());
  if(hCursor) Screen->Cursors[crDrag] = hCursor;
 }
 catch(...)
 {
 }

 AnsiString sCmd = ParamStr(0);  //current program
 AnsiString sExt = ".cpf";
 TExtInfo *inf;
 try
 {
  inf = Reg1->GetExtInfo(sExt);
  if (inf->ExecutePath != "\"" + ParamStr(0) + "\" \"%1\"")
  RegisterExt();
 }
 catch(...)
 {
  RegisterExt();
 }

 NewClientWP = (FARPROC)MakeObjectInstance(MDIClientWndProc); // Bg additions
 OldClientWP = (FARPROC)SetWindowLong(ClientHandle, GWL_WNDPROC, (LONG)NewClientWP);
}
//---------------------------------------------------------------------------

void __fastcall TMainForm::CreateMDIChild(String Name)
{
	TMDIChild *Child;
	Child = new TMDIChild(Application);
	Child->Caption = Name;
	if (FileExists(Name)){
         Child->NoDrag = true;
         Child->SmithStrings->LoadFromFile(Name);
         for (int i=0; i < Child->SmithStrings->Count; i++) {
          Child->ScrollBar1->Max = i+1;
          if (i % 2 == 0) {
           Child->StringGrid1->Cells[0][i/2 + 1] = i/2 + 1;
           Child->StringGrid1->Cells[1][i/2 + 1] = Child->SmithStrings->Strings[i];
          } else {
           Child->StringGrid1->Cells[2][i/2 + 1] = Child->SmithStrings->Strings[i];
           Child->StringGrid1->RowCount = Child->StringGrid1->RowCount + 1;
          }
         }
        }
}
//---------------------------------------------------------------------------

void __fastcall TMainForm::FileNew1Execute(TObject *Sender)
{
 if (IdTCPServer1->Active == true || IdTCPClient1->Connected() == true) {
  CreateMDIChild("Active Game");
  if(IdTCPServer1->Active == true){
    TList *List = IdTCPServer1->Threads->LockList();
    try
    {
        TIdPeerThread *Thread;
        for(int x = 0; x < List->Count; ++x)
        {
            Thread = (TIdPeerThread*) List->Items[x];
            Thread->Connection->WriteLn("/new");
        }
    }
    __finally
    {
        MainForm->IdTCPServer1->Threads->UnlockList();
    }
  } else {
     try
     {
      IdTCPClient1->WriteLn("/new");
     }
     __finally
     {
      //
     }
  }
 }   else    {
  CreateMDIChild("Game Board");
 }
}
//---------------------------------------------------------------------------

void __fastcall TMainForm::FileOpen1Execute(TObject *Sender)
{
	if (OpenDialog->Execute())
		CreateMDIChild(OpenDialog->FileName);
}
//---------------------------------------------------------------------------

void __fastcall TMainForm::HelpAbout1Execute(TObject *Sender)
{
	AboutBox->ShowModal();
}
//---------------------------------------------------------------------------

void __fastcall TMainForm::FileExit1Execute(TObject *Sender)
{
	Close();
}
//---------------------------------------------------------------------------

void TileBlt(HDC HDestDC, int DestWidth, int DestHeight, HDC HSourceDC,
    int SourceWidth, int SourceHeight)
{
    for (int y = 0; y < DestHeight; y = y + SourceHeight)
    {
        for (int x = 0; x < DestWidth; x = x + SourceWidth)
        {
            ::BitBlt(HDestDC, x, y,
                     SourceWidth, SourceHeight,
                     HSourceDC, 0, 0,
                     SRCCOPY);
        }
    }
}
//---------------------------------------------------------------------------

void __fastcall TMainForm::MDIClientWndProc(TMessage &Msg)
{
    switch (Msg.Msg)
    {
        // No Scrollbars ;)
         case WM_NCCALCSIZE:
        {
            Msg.Result = WVR_REDRAW;
            return;
        }

        // draw the image to the device context of the client window
         case WM_ERASEBKGND:
        {
            HDC Hdc = (HDC)Msg.WParam;
            SelectPalette(Hdc, Image1->Picture->Bitmap->Palette, true);
            RealizePalette(Hdc);
            TileBlt(Hdc, Width, Height,
                    Image1->Canvas->Handle,
                    Image1->Picture->Bitmap->Width,
                    Image1->Picture->Bitmap->Height);

            Msg.Result = 0;
            return;
        }

        // handle the palette changes
        case WM_QUERYNEWPALETTE:
        {
            HDC Hdc = GetDC(ClientHandle); 
            SelectPalette(Hdc, Image1->Picture->Bitmap->Palette, true); 
            RealizePalette(Hdc); 
            InvalidateRect(ClientHandle, NULL, true); 
            ReleaseDC(ClientHandle, Hdc); 

            Msg.Result = 0; 
            return;
        }
        case WM_PALETTECHANGED:
        {
            if ((HWND)Msg.WParam != ClientHandle)
            {
                HDC Hdc = GetDC(ClientHandle);
                SelectPalette(Hdc, Image1->Picture->Bitmap->Palette, true);
                RealizePalette(Hdc);
                UpdateColors(Hdc);
                ReleaseDC(ClientHandle, Hdc);
            }

            Msg.Result = 0;
            return;
        }

        // refresh the image upon scrolling 
        case WM_HSCROLL: 
        case WM_VSCROLL: 
        { 
            InvalidateRect(ClientHandle, NULL, true); 
            break; 
        }  

        // un-subclass the client window 
        case WM_DESTROY: 
        { 
            SetWindowLong(ClientHandle, GWL_WNDPROC, (LONG)OldClientWP); 
            FreeObjectInstance(NewClientWP); 
        } 
    } 

    // call the default window procedure 
    Msg.Result = CallWindowProc(OldClientWP, ClientHandle, Msg.Msg,
                                Msg.WParam, Msg.LParam);
}
//---------------------------------------------------------------------------

void __fastcall TMainForm::FormClose(TObject *Sender, TCloseAction &Action)
{
 IdTCPServer1->Active = false;
 IdTCPClient1->Disconnect();

 for (int i=0; i<MainForm->MDIChildCount; i++)
 MainForm->MDIChildren[i]->Close();
 Action = caFree;
}
//---------------------------------------------------------------------------

void __fastcall TMainForm::RegisterExt(void)
{
 AnsiString sExt=".cpf";
 TExtInfo *inf;
 AnsiString sCmd = ParamStr(0);  //current program
 inf = new TExtInfo(sExt, sCmd, "Chess Peer File", (DWORD) 0) ;
 inf->Icon = ParamStr(0) + ",0"; //index to icon in the executable
 Reg1->Add(inf);
 Reg1->Register();
}

//---------------------------------------------------------------------------

void __fastcall TMainForm::Toolbar1Click(TObject *Sender)
{
 Toolbar1->Checked = !Toolbar1->Checked;
 ToolBar2->Visible = !ToolBar2->Visible;
}
//---------------------------------------------------------------------------

void __fastcall TMainForm::StatusBar1Click(TObject *Sender)
{
 StatusBar1->Checked = !StatusBar1->Checked;
 StatusBar->Visible = !StatusBar->Visible;
}
//---------------------------------------------------------------------------

void __fastcall TMainForm::PlayMediaSound(AnsiString FileLocation)
{
 if (PlaySounds1->Checked) {
  try
  {
   MediaPlayer1->FileName = ExtractFilePath(Application->ExeName) + FileLocation;
   MediaPlayer1->Open();
   MediaPlayer1->Play();
  }
  catch(...)
  {
  }
 }
}
//---------------------------------------------------------------------------

void __fastcall TMainForm::PlaySounds1Click(TObject *Sender)
{
 PlaySounds1->Checked = !PlaySounds1->Checked;

    TIniFile *MyIni;
    MyIni = new TIniFile(ExtractFilePath(ParamStr(0)) + "Settings.ini");
    if (PlaySounds1->Checked)
    MyIni->WriteString("Options", "Sound", "1");
    else
    MyIni->WriteString("Options", "Sound", "0");
    delete MyIni;
}
//---------------------------------------------------------------------------

void __fastcall TMainForm::AddEngine1Click(TObject *Sender)
{
 OpenDialog1->InitialDir = ExtractFilePath(Application->ExeName) + "Engines\\";
 if (OpenDialog1->Execute()) {
  if (OpenDialog1->FileName.AnsiPos(OpenDialog1->InitialDir)) {
   int SlashPlace = OpenDialog1->FileName.LastDelimiter("\\");
   int PointPlace = OpenDialog1->FileName.LastDelimiter(".");
   CreateMDIChild(OpenDialog1->FileName.SubString(SlashPlace + 1, PointPlace - SlashPlace - 1));
   TMDIChild *MDIChild = dynamic_cast<TMDIChild*>(ActiveMDIChild);
   MDIChild->AddEngine(OpenDialog1->FileName);
  } else Form2->Memo1->Lines->Add("\r\nPlease select an engine from the 'Engines' directory.");
 }
}
//---------------------------------------------------------------------------

void __fastcall TMainForm::FormCreate(TObject *Sender)
{
 DragAcceptFiles(Handle, True);

    AnsiString PieceNo, BoardNo;
    TIniFile *MyIni;
    MyIni = new TIniFile(ExtractFilePath(ParamStr(0)) + "Settings.ini");

    PieceNo = MyIni->ReadString("Options", "Pieces", "");
    if (PieceNo == 1) Modern11->Checked = true;
    else if (PieceNo == 4) Sharp1->Checked = true;
    else if (PieceNo == 3) Classic1->Checked = true;
    else Modern21->Checked = true;

    BoardNo = MyIni->ReadString("Options", "Board", "");
    if (BoardNo == 1) SkyBlue1->Checked = true;
    else BestGreen1->Checked = true;

    if (MyIni->ReadString("Options", "Sound", "") == 0)
    PlaySounds1->Checked = false;
    else PlaySounds1->Checked = true;

    delete MyIni;
}
//---------------------------------------------------------------------------
void __fastcall TMainForm::WmCopyData(TWMCopyData &Msg)
{
 AnsiString FileName = reinterpret_cast<char*>(Msg.CopyDataStruct->lpData);
 CreateMDIChild(FileName.SubString(2, FileName.Length() - 2));
 Application->Restore();
 Application->BringToFront();
}

void __fastcall TMainForm::WMDropFiles(TWMDropFiles &Msg)
{ 
 UINT filecount = DragQueryFile((HDROP)Msg.Drop, 0xFFFFFFFF, NULL, 0);
 for (UINT i = 0; i < filecount; ++i) {
  AnsiString filename;
  filename.SetLength(MAX_PATH);
  int length = DragQueryFile((HDROP)Msg.Drop, i, filename.c_str(), filename.Length());
  filename.SetLength(length);
  if (filename.SubString(filename.Length()-3, 4) == ".cpf")
  CreateMDIChild(filename);
 }
 DragFinish((HDROP)Msg.Drop);
}

//---------------------------------------------------------------------------

void __fastcall TMainForm::RefreshThePieces(void)
{
 for (int i=0; i<MainForm->MDIChildCount; i++) {
  TMDIChild *MDIChild = dynamic_cast<TMDIChild*>(MDIChildren[i]);
  if (MDIChild) {
   MDIChild->FillImageList();
   MDIChild->RefreshPieces();
  }
 }
}

//---------------------------------------------------------------------------

void __fastcall TMainForm::RefreshTheBoards(void)
{
 for (int i=0; i<MainForm->MDIChildCount; i++) {
  TMDIChild *MDIChild = dynamic_cast<TMDIChild*>(MDIChildren[i]);
  if (MDIChild) {
   MDIChild->SelectBackGrounds();
   MDIChild->RefreshBoards();
  }
 }
}

//---------------------------------------------------------------------------

void __fastcall TMainForm::Modern11Click(TObject *Sender)
{
 Modern11->Checked = true;
 Modern21->Checked = false;
 Classic1->Checked = false;
 Sharp1->Checked = false;

 RefreshThePieces();

    TIniFile *MyIni;
    MyIni = new TIniFile(ExtractFilePath(ParamStr(0)) + "Settings.ini");
    MyIni->WriteString("Options", "Pieces", "1");
    delete MyIni;
}
//---------------------------------------------------------------------------

void __fastcall TMainForm::Modern21Click(TObject *Sender)
{
 Modern11->Checked = false;
 Modern21->Checked = true;
 Classic1->Checked = false;
 Sharp1->Checked = false;

 RefreshThePieces();

    TIniFile *MyIni;
    MyIni = new TIniFile(ExtractFilePath(ParamStr(0)) + "Settings.ini");
    MyIni->WriteString("Options", "Pieces", "2");
    delete MyIni;
}
//---------------------------------------------------------------------------

void __fastcall TMainForm::Classic1Click(TObject *Sender)
{
 Modern11->Checked = false;
 Modern21->Checked = false;
 Classic1->Checked = true;
 Sharp1->Checked = false;

 RefreshThePieces();

    TIniFile *MyIni;
    MyIni = new TIniFile(ExtractFilePath(ParamStr(0)) + "Settings.ini");
    MyIni->WriteString("Options", "Pieces", "3");
    delete MyIni;
}
//---------------------------------------------------------------------------

void __fastcall TMainForm::Sharp1Click(TObject *Sender)
{
 Modern11->Checked = false;
 Modern21->Checked = false;
 Classic1->Checked = false;
 Sharp1->Checked = true;

 RefreshThePieces();

    TIniFile *MyIni;
    MyIni = new TIniFile(ExtractFilePath(ParamStr(0)) + "Settings.ini");
    MyIni->WriteString("Options", "Pieces", "4");
    delete MyIni;
}
//---------------------------------------------------------------------------

void __fastcall TMainForm::IdTCPServer1Execute(TIdPeerThread *AThread)
{
 IndyMsg = AThread->Connection->ReadLn();

 if(IndyMsg != "") {

  if (IndyMsg.SubString(1, 5) == "/move") {

   for (int i=0; i<MainForm->MDIChildCount; i++) {
    TMDIChild *MDIChild = dynamic_cast<TMDIChild*>(MDIChildren[i]);
    if (MDIChild->Caption.SubString(1, 11) == "Active Game") {

   if (IndyMsg.SubString(11, 1).LowerCase() == "q") MDIChild->PromotedPawn = "Queen";
   if (IndyMsg.SubString(11, 1).LowerCase() == "r") MDIChild->PromotedPawn = "Rook";
   if (IndyMsg.SubString(11, 1).LowerCase() == "b") MDIChild->PromotedPawn = "Bishop";
   if (IndyMsg.SubString(11, 1).LowerCase() == "n") MDIChild->PromotedPawn = "Knight";

     MDIChild->PlayMove(IndyMsg.SubString(7, 2), IndyMsg.SubString(9, 2));
     MDIChild->SentPromoPawn = "";
     IndyMsg = "";
     break;
    }
   }

  }

  if (IndyMsg.SubString(1, 5) == "/chat") {

   for (int i=0; i<MainForm->MDIChildCount; i++) {
    TMDIChild *MDIChild = dynamic_cast<TMDIChild*>(MDIChildren[i]);
    if (MDIChild->Caption.SubString(1, 11) == "Active Game") {
     MDIChild->Memo1->Lines->Add(IndyMsg.SubString(7, IndyMsg.Length()));
     break;
    }
   }

  }

  if (IndyMsg.SubString(1, 4) == "/new") {
   AThread->Synchronize(OnServerConVcl);
  }

 }
}
//---------------------------------------------------------------------------

void __fastcall TMainForm::HelpTopics1Click(TObject *Sender)
{
 AnsiString HelpLocation = ExtractFilePath(Application->ExeName) + "Help.chm";
 ShellExecute(0, "open", HelpLocation.c_str(), NULL, NULL, SW_SHOWNORMAL);
}
//---------------------------------------------------------------------------



void __fastcall TMainForm::SkyBlue1Click(TObject *Sender)
{
 SkyBlue1->Checked = true;
 BestGreen1->Checked = false;

 RefreshTheBoards();

    TIniFile *MyIni;
    MyIni = new TIniFile(ExtractFilePath(ParamStr(0)) + "Settings.ini");
    MyIni->WriteString("Options", "Board", "1");
    delete MyIni;
}
//---------------------------------------------------------------------------

void __fastcall TMainForm::BestGreen1Click(TObject *Sender)
{
 SkyBlue1->Checked = false;
 BestGreen1->Checked = true;

 RefreshTheBoards();

    TIniFile *MyIni;
    MyIni = new TIniFile(ExtractFilePath(ParamStr(0)) + "Settings.ini");
    MyIni->WriteString("Options", "Board", "2");
    delete MyIni;
}
//---------------------------------------------------------------------------

void __fastcall TMainForm::OpponentSeekingGames1Click(TObject *Sender)
{
 OpponentSeekingGames1->Checked = !OpponentSeekingGames1->Checked;
 if(OpponentSeekingGames1->Checked == true) {
  TForm1* Form1 = new TForm1(Application);
  Form1->Show();
 } else {
  for (int i=0; i<MainForm->MDIChildCount; i++) {
   TForm1 *Form1 = dynamic_cast<TForm1*>(MDIChildren[i]);
   if (Form1) {
    Form1->Close();
   }
  }
 }
}
//---------------------------------------------------------------------------

void __fastcall TMainForm::MainConsole1Click(TObject *Sender)
{
 MainConsole1->Checked = !MainConsole1->Checked;
 if(MainConsole1->Checked == true) {
  TForm2* Form2 = new TForm2(Application);
  Form2->Show();
 } else {
  for (int i=0; i<MainForm->MDIChildCount; i++) {
   TForm2 *Form2 = dynamic_cast<TForm2*>(MDIChildren[i]);
   if (Form2) {
    Form2->Close();
   }
  }
 }
}
//---------------------------------------------------------------------------

void __fastcall TMainForm::FileSave1Execute(TObject *Sender)
{
 TMDIChild *MDIChild = dynamic_cast<TMDIChild*>(ActiveMDIChild);
 if (MDIChild) {
  if (MDIChild->Caption.SubString(MDIChild->Caption.Length() - 3, 4) == ".cpf") {

   AnsiString Buf;
   Buf = MDIChild->SmithStrings->Text;

   if (Buf.Length() > 0) {
    TMemoryStream *DataOut;
    DataOut = new TMemoryStream;

    DataOut->Write(&Buf[1], Buf.Length());
    DataOut->Seek(0, soFromBeginning);
    DataOut->SaveToFile(MDIChild->Caption);
   }

  } else {
   FileSaveAs1->Execute();
  }
 }
}
//---------------------------------------------------------------------------

void __fastcall TMainForm::FileSaveAs1Execute(TObject *Sender)
{
 TMDIChild *MDIChild = dynamic_cast<TMDIChild*>(ActiveMDIChild);
 if (MDIChild) {
  AnsiString Buf;
  Buf = MDIChild->SmithStrings->Text;

  if (Buf.Length() > 0) {
   if(SaveDialog1->Execute()) {
    TMemoryStream *DataOut;
    DataOut = new TMemoryStream;

    DataOut->Write(&Buf[1], Buf.Length());
    DataOut->Seek(0, soFromBeginning);
    DataOut->SaveToFile(SaveDialog1->FileName);
    MDIChild->Caption = SaveDialog1->FileName;
   }
  }
 }
}
//---------------------------------------------------------------------------


void __fastcall TMainForm::DefaultLayout1Click(TObject *Sender)
{
 for (int i=0; i<MainForm->MDIChildCount; i++) {
  TMDIChild *MDIChild = dynamic_cast<TMDIChild*>(MDIChildren[i]);
  TForm1 *Form1 = dynamic_cast<TForm1*>(MDIChildren[i]);
  TForm2 *Form2 = dynamic_cast<TForm2*>(MDIChildren[i]);
  if (MDIChild) {
   MDIChild->Width = 742;
   MDIChild->Height = 641;
   if (MDIChild->Top < 1) MDIChild->Top = 1;
   if (MDIChild->Left < 1) MDIChild->Left = 1;
  }
  if (Form1) {
   Form1->Width = 280;
   Form1->Height = 116;
   Form1->Top = 1;
   Form1->Left = 744;
  }
  if (Form2) {
   Form2->Width = 280;
   Form2->Height = 524;
   Form2->Top = 118;
   Form2->Left = 744;
  }
 }
}
//---------------------------------------------------------------------------



void __fastcall TMainForm::Timer1Timer(TObject *Sender)
{
 Timer1->Enabled = false;
 try
 {

 if(IdTCPClient1->Connected()) {
  AnsiString TheCmd = IdTCPClient1->ReadLn("", IdTimeoutDefault);

  if (TheCmd.SubString(1, 5) == "/move") {

   for (int i=0; i<MainForm->MDIChildCount; i++) {
    TMDIChild *MDIChild = dynamic_cast<TMDIChild*>(MDIChildren[i]);
    if (MDIChild->Caption.SubString(1, 11) == "Active Game") {

   if (TheCmd.SubString(11, 1).LowerCase() == "q") MDIChild->PromotedPawn = "Queen";
   if (TheCmd.SubString(11, 1).LowerCase() == "r") MDIChild->PromotedPawn = "Rook";
   if (TheCmd.SubString(11, 1).LowerCase() == "b") MDIChild->PromotedPawn = "Bishop";
   if (TheCmd.SubString(11, 1).LowerCase() == "n") MDIChild->PromotedPawn = "Knight";

     MDIChild->PlayMove(TheCmd.SubString(7, 2), TheCmd.SubString(9, 2));

     MDIChild->SentPromoPawn = "";
     break;
    }
   }

  }

  if (TheCmd.SubString(1, 5) == "/chat") {
   for (int i=0; i<MainForm->MDIChildCount; i++) {
    TMDIChild *MDIChild = dynamic_cast<TMDIChild*>(MDIChildren[i]);
    if (MDIChild->Caption.SubString(1, 11) == "Active Game") {
     MDIChild->Memo1->Lines->Add(TheCmd.SubString(7, TheCmd.Length()));
     break;
    }
   }
  }

  if (TheCmd.SubString(1, 4) == "/new") {
   CreateMDIChild("Active Game");
  }

 }

 }
 catch(...)
 {
 }
 Timer1->Enabled = true;
}
//---------------------------------------------------------------------------

void __fastcall TMainForm::OnServerConVcl(void)
{
 CreateMDIChild("Active Game");
}
//---------------------------------------------------------------------------

void __fastcall TMainForm::IdTCPServer1Connect(TIdPeerThread *AThread)
{
 AThread->Synchronize(OnServerConVcl);
}
//---------------------------------------------------------------------------




