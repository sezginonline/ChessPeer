//---------------------------------------------------------------------
#include <vcl.h>
#pragma hdrstop

#include "ChildWin.h"
#include "main.h"
//---------------------------------------------------------------------
#pragma link "SHDocVw_OCX"
#pragma resource "*.dfm"
TMDIChild *MDIChild; // Important
//---------------------------------------------------------------------
__fastcall TMDIChild::TMDIChild(TComponent *Owner)
	: TForm(Owner)
{
 SetControlsControlStyle(this);
 MyDCObject = new TMyDCObject(a1);
}
//---------------------------------------------------------------------
BOOL CALLBACK closeit(HWND hwnd,LPARAM lParam)
{
 DWORD hwnd_pid;
 GetWindowThreadProcessId(hwnd, &hwnd_pid);
 if (hwnd_pid == (DWORD)lParam) {
  SendMessage(hwnd, WM_CLOSE, 0,0);
  return false;
 }
 return true;
}
//---------------------------------------------------------------------
void __fastcall TMDIChild::CloseHandles()
{
 if(hProcess) {
  CloseHandle(hProcess);
  hProcess = NULL;
 }
 if(hStdInRead) {
  CloseHandle(hStdInRead);
  hStdInRead = NULL;
 }
 if(hStdInWrite) {
  CloseHandle(hStdInWrite);
  hStdInWrite = NULL;
 }
 if(hStdOutRead) {
  CloseHandle(hStdOutRead);
  hStdOutRead = NULL;
 }
 if(hStdInWrite) {
  CloseHandle(hStdOutWrite);
  hStdOutWrite = NULL;
 }
}
//---------------------------------------------------------------------
void __fastcall TMDIChild::SetControlsControlStyle(TControl* Control)
{
 Control->ControlStyle << csDisplayDragImage;
 TWinControl* pControl = dynamic_cast<TWinControl*>(Control);
 if(pControl)
 for(int x=0; x<pControl->ControlCount; ++x)
 SetControlsControlStyle(pControl->Controls[x]);
}
//---------------------------------------------------------------------
void __fastcall TMDIChild::FormClose(TObject *Sender, TCloseAction &Action)
{
 EnumWindows((WNDENUMPROC)closeit, pi.dwProcessId);
 Action = caFree;
}
//---------------------------------------------------------------------
void __fastcall TMDIChild::FormCreate(TObject *Sender)
{
 FillImageList();
 SelectBackGrounds();

 a8bg = new TImage(this);
 a8bg->Left = a8->Left;
 a8bg->Top = a8->Top;
 a8bg->Width = a8->Width;
 a8bg->Height = a8->Height;
 a8bg->Parent = a8->Parent;
 a8bg->SendToBack();

 b8bg = new TImage(this);
 b8bg->Left = b8->Left;
 b8bg->Top = b8->Top;
 b8bg->Width = b8->Width;
 b8bg->Height = b8->Height;
 b8bg->Parent = b8->Parent;
 b8bg->SendToBack();

 c8bg = new TImage(this);
 c8bg->Left = c8->Left;
 c8bg->Top = c8->Top;
 c8bg->Width = c8->Width;
 c8bg->Height = c8->Height;
 c8bg->Parent = c8->Parent;
 c8bg->SendToBack();

 d8bg = new TImage(this);
 d8bg->Left = d8->Left;
 d8bg->Top = d8->Top;
 d8bg->Width = d8->Width;
 d8bg->Height = d8->Height;
 d8bg->Parent = d8->Parent;
 d8bg->SendToBack();

 e8bg = new TImage(this);
 e8bg->Left = e8->Left;
 e8bg->Top = e8->Top;
 e8bg->Width = e8->Width;
 e8bg->Height = e8->Height;
 e8bg->Parent = e8->Parent;
 e8bg->SendToBack();

 f8bg = new TImage(this);
 f8bg->Left = f8->Left;
 f8bg->Top = f8->Top;
 f8bg->Width = f8->Width;
 f8bg->Height = f8->Height;
 f8bg->Parent = f8->Parent;
 f8bg->SendToBack();

 g8bg = new TImage(this);
 g8bg->Left = g8->Left;
 g8bg->Top = g8->Top;
 g8bg->Width = g8->Width;
 g8bg->Height = g8->Height;
 g8bg->Parent = g8->Parent;
 g8bg->SendToBack();

 h8bg = new TImage(this);
 h8bg->Left = h8->Left;
 h8bg->Top = h8->Top;
 h8bg->Width = h8->Width;
 h8bg->Height = h8->Height;
 h8bg->Parent = h8->Parent;
 h8bg->SendToBack();

 a7bg = new TImage(this);
 a7bg->Left = a7->Left;
 a7bg->Top = a7->Top;
 a7bg->Width = a7->Width;
 a7bg->Height = a7->Height;
 a7bg->Parent = a7->Parent;
 a7bg->SendToBack();

 b7bg = new TImage(this);
 b7bg->Left = b7->Left;
 b7bg->Top = b7->Top;
 b7bg->Width = b7->Width;
 b7bg->Height = b7->Height;
 b7bg->Parent = b7->Parent;
 b7bg->SendToBack();

 c7bg = new TImage(this);
 c7bg->Left = c7->Left;
 c7bg->Top = c7->Top;
 c7bg->Width = c7->Width;
 c7bg->Height = c7->Height;
 c7bg->Parent = c7->Parent;
 c7bg->SendToBack();

 d7bg = new TImage(this);
 d7bg->Left = d7->Left;
 d7bg->Top = d7->Top;
 d7bg->Width = d7->Width;
 d7bg->Height = d7->Height;
 d7bg->Parent = d7->Parent;
 d7bg->SendToBack();

 e7bg = new TImage(this);
 e7bg->Left = e7->Left;
 e7bg->Top = e7->Top;
 e7bg->Width = e7->Width;
 e7bg->Height = e7->Height;
 e7bg->Parent = e7->Parent;
 e7bg->SendToBack();

 f7bg = new TImage(this);
 f7bg->Left = f7->Left;
 f7bg->Top = f7->Top;
 f7bg->Width = f7->Width;
 f7bg->Height = f7->Height;
 f7bg->Parent = f7->Parent;
 f7bg->SendToBack();

 g7bg = new TImage(this);
 g7bg->Left = g7->Left;
 g7bg->Top = g7->Top;
 g7bg->Width = g7->Width;
 g7bg->Height = g7->Height;
 g7bg->Parent = g7->Parent;
 g7bg->SendToBack();

 h7bg = new TImage(this);
 h7bg->Left = h7->Left;
 h7bg->Top = h7->Top;
 h7bg->Width = h7->Width;
 h7bg->Height = h7->Height;
 h7bg->Parent = h7->Parent;
 h7bg->SendToBack();

 a6bg = new TImage(this);
 a6bg->Left = a6->Left;
 a6bg->Top = a6->Top;
 a6bg->Width = a6->Width;
 a6bg->Height = a6->Height;
 a6bg->Parent = a6->Parent;
 a6bg->SendToBack();

 b6bg = new TImage(this);
 b6bg->Left = b6->Left;
 b6bg->Top = b6->Top;
 b6bg->Width = b6->Width;
 b6bg->Height = b6->Height;
 b6bg->Parent = b6->Parent;
 b6bg->SendToBack();

 c6bg = new TImage(this);
 c6bg->Left = c6->Left;
 c6bg->Top = c6->Top;
 c6bg->Width = c6->Width;
 c6bg->Height = c6->Height;
 c6bg->Parent = c6->Parent;
 c6bg->SendToBack();

 d6bg = new TImage(this);
 d6bg->Left = d6->Left;
 d6bg->Top = d6->Top;
 d6bg->Width = d6->Width;
 d6bg->Height = d6->Height;
 d6bg->Parent = d6->Parent;
 d6bg->SendToBack();

 e6bg = new TImage(this);
 e6bg->Left = e6->Left;
 e6bg->Top = e6->Top;
 e6bg->Width = e6->Width;
 e6bg->Height = e6->Height;
 e6bg->Parent = e6->Parent;
 e6bg->SendToBack();

 f6bg = new TImage(this);
 f6bg->Left = f6->Left;
 f6bg->Top = f6->Top;
 f6bg->Width = f6->Width;
 f6bg->Height = f6->Height;
 f6bg->Parent = f6->Parent;
 f6bg->SendToBack();

 g6bg = new TImage(this);
 g6bg->Left = g6->Left;
 g6bg->Top = g6->Top;
 g6bg->Width = g6->Width;
 g6bg->Height = g6->Height;
 g6bg->Parent = g6->Parent;
 g6bg->SendToBack();

 h6bg = new TImage(this);
 h6bg->Left = h6->Left;
 h6bg->Top = h6->Top;
 h6bg->Width = h6->Width;
 h6bg->Height = h6->Height;
 h6bg->Parent = h6->Parent;
 h6bg->SendToBack();

 a5bg = new TImage(this);
 a5bg->Left = a5->Left;
 a5bg->Top = a5->Top;
 a5bg->Width = a5->Width;
 a5bg->Height = a5->Height;
 a5bg->Parent = a5->Parent;
 a5bg->SendToBack();

 b5bg = new TImage(this);
 b5bg->Left = b5->Left;
 b5bg->Top = b5->Top;
 b5bg->Width = b5->Width;
 b5bg->Height = b5->Height;
 b5bg->Parent = b5->Parent;
 b5bg->SendToBack();

 c5bg = new TImage(this);
 c5bg->Left = c5->Left;
 c5bg->Top = c5->Top;
 c5bg->Width = c5->Width;
 c5bg->Height = c5->Height;
 c5bg->Parent = c5->Parent;
 c5bg->SendToBack();

 d5bg = new TImage(this);
 d5bg->Left = d5->Left;
 d5bg->Top = d5->Top;
 d5bg->Width = d5->Width;
 d5bg->Height = d5->Height;
 d5bg->Parent = d5->Parent;
 d5bg->SendToBack();

 e5bg = new TImage(this);
 e5bg->Left = e5->Left;
 e5bg->Top = e5->Top;
 e5bg->Width = e5->Width;
 e5bg->Height = e5->Height;
 e5bg->Parent = e5->Parent;
 e5bg->SendToBack();

 f5bg = new TImage(this);
 f5bg->Left = f5->Left;
 f5bg->Top = f5->Top;
 f5bg->Width = f5->Width;
 f5bg->Height = f5->Height;
 f5bg->Parent = f5->Parent;
 f5bg->SendToBack();

 g5bg = new TImage(this);
 g5bg->Left = g5->Left;
 g5bg->Top = g5->Top;
 g5bg->Width = g5->Width;
 g5bg->Height = g5->Height;
 g5bg->Parent = g5->Parent;
 g5bg->SendToBack();

 h5bg = new TImage(this);
 h5bg->Left = h5->Left;
 h5bg->Top = h5->Top;
 h5bg->Width = h5->Width;
 h5bg->Height = h5->Height;
 h5bg->Parent = h5->Parent;
 h5bg->SendToBack();

 a4bg = new TImage(this);
 a4bg->Left = a4->Left;
 a4bg->Top = a4->Top;
 a4bg->Width = a4->Width;
 a4bg->Height = a4->Height;
 a4bg->Parent = a4->Parent;
 a4bg->SendToBack();

 b4bg = new TImage(this);
 b4bg->Left = b4->Left;
 b4bg->Top = b4->Top;
 b4bg->Width = b4->Width;
 b4bg->Height = b4->Height;
 b4bg->Parent = b4->Parent;
 b4bg->SendToBack();

 c4bg = new TImage(this);
 c4bg->Left = c4->Left;
 c4bg->Top = c4->Top;
 c4bg->Width = c4->Width;
 c4bg->Height = c4->Height;
 c4bg->Parent = c4->Parent;
 c4bg->SendToBack();

 d4bg = new TImage(this);
 d4bg->Left = d4->Left;
 d4bg->Top = d4->Top;
 d4bg->Width = d4->Width;
 d4bg->Height = d4->Height;
 d4bg->Parent = d4->Parent;
 d4bg->SendToBack();

 e4bg = new TImage(this);
 e4bg->Left = e4->Left;
 e4bg->Top = e4->Top;
 e4bg->Width = e4->Width;
 e4bg->Height = e4->Height;
 e4bg->Parent = e4->Parent;
 e4bg->SendToBack();

 f4bg = new TImage(this);
 f4bg->Left = f4->Left;
 f4bg->Top = f4->Top;
 f4bg->Width = f4->Width;
 f4bg->Height = f4->Height;
 f4bg->Parent = f4->Parent;
 f4bg->SendToBack();

 g4bg = new TImage(this);
 g4bg->Left = g4->Left;
 g4bg->Top = g4->Top;
 g4bg->Width = g4->Width;
 g4bg->Height = g4->Height;
 g4bg->Parent = g4->Parent;
 g4bg->SendToBack();

 h4bg = new TImage(this);
 h4bg->Left = h4->Left;
 h4bg->Top = h4->Top;
 h4bg->Width = h4->Width;
 h4bg->Height = h4->Height;
 h4bg->Parent = h4->Parent;
 h4bg->SendToBack();

 a3bg = new TImage(this);
 a3bg->Left = a3->Left;
 a3bg->Top = a3->Top;
 a3bg->Width = a3->Width;
 a3bg->Height = a3->Height;
 a3bg->Parent = a3->Parent;
 a3bg->SendToBack();

 b3bg = new TImage(this);
 b3bg->Left = b3->Left;
 b3bg->Top = b3->Top;
 b3bg->Width = b3->Width;
 b3bg->Height = b3->Height;
 b3bg->Parent = b3->Parent;
 b3bg->SendToBack();

 c3bg = new TImage(this);
 c3bg->Left = c3->Left;
 c3bg->Top = c3->Top;
 c3bg->Width = c3->Width;
 c3bg->Height = c3->Height;
 c3bg->Parent = c3->Parent;
 c3bg->SendToBack();

 d3bg = new TImage(this);
 d3bg->Left = d3->Left;
 d3bg->Top = d3->Top;
 d3bg->Width = d3->Width;
 d3bg->Height = d3->Height;
 d3bg->Parent = d3->Parent;
 d3bg->SendToBack();

 e3bg = new TImage(this);
 e3bg->Left = e3->Left;
 e3bg->Top = e3->Top;
 e3bg->Width = e3->Width;
 e3bg->Height = e3->Height;
 e3bg->Parent = e3->Parent;
 e3bg->SendToBack();

 f3bg = new TImage(this);
 f3bg->Left = f3->Left;
 f3bg->Top = f3->Top;
 f3bg->Width = f3->Width;
 f3bg->Height = f3->Height;
 f3bg->Parent = f3->Parent;
 f3bg->SendToBack();

 g3bg = new TImage(this);
 g3bg->Left = g3->Left;
 g3bg->Top = g3->Top;
 g3bg->Width = g3->Width;
 g3bg->Height = g3->Height;
 g3bg->Parent = g3->Parent;
 g3bg->SendToBack();

 h3bg = new TImage(this);
 h3bg->Left = h3->Left;
 h3bg->Top = h3->Top;
 h3bg->Width = h3->Width;
 h3bg->Height = h3->Height;
 h3bg->Parent = h3->Parent;
 h3bg->SendToBack();

 a2bg = new TImage(this);
 a2bg->Left = a2->Left;
 a2bg->Top = a2->Top;
 a2bg->Width = a2->Width;
 a2bg->Height = a2->Height;
 a2bg->Parent = a2->Parent;
 a2bg->SendToBack();

 b2bg = new TImage(this);
 b2bg->Left = b2->Left;
 b2bg->Top = b2->Top;
 b2bg->Width = b2->Width;
 b2bg->Height = b2->Height;
 b2bg->Parent = b2->Parent;
 b2bg->SendToBack();

 c2bg = new TImage(this);
 c2bg->Left = c2->Left;
 c2bg->Top = c2->Top;
 c2bg->Width = c2->Width;
 c2bg->Height = c2->Height;
 c2bg->Parent = c2->Parent;
 c2bg->SendToBack();

 d2bg = new TImage(this);
 d2bg->Left = d2->Left;
 d2bg->Top = d2->Top;
 d2bg->Width = d2->Width;
 d2bg->Height = d2->Height;
 d2bg->Parent = d2->Parent;
 d2bg->SendToBack();

 e2bg = new TImage(this);
 e2bg->Left = e2->Left;
 e2bg->Top = e2->Top;
 e2bg->Width = e2->Width;
 e2bg->Height = e2->Height;
 e2bg->Parent = e2->Parent;
 e2bg->SendToBack();

 f2bg = new TImage(this);
 f2bg->Left = f2->Left;
 f2bg->Top = f2->Top;
 f2bg->Width = f2->Width;
 f2bg->Height = f2->Height;
 f2bg->Parent = f2->Parent;
 f2bg->SendToBack();

 g2bg = new TImage(this);
 g2bg->Left = g2->Left;
 g2bg->Top = g2->Top;
 g2bg->Width = g2->Width;
 g2bg->Height = g2->Height;
 g2bg->Parent = g2->Parent;
 g2bg->SendToBack();

 h2bg = new TImage(this);
 h2bg->Left = h2->Left;
 h2bg->Top = h2->Top;
 h2bg->Width = h2->Width;
 h2bg->Height = h2->Height;
 h2bg->Parent = h2->Parent;
 h2bg->SendToBack();

 a1bg = new TImage(this);
 a1bg->Left = a1->Left;
 a1bg->Top = a1->Top;
 a1bg->Width = a1->Width;
 a1bg->Height = a1->Height;
 a1bg->Parent = a1->Parent;
 a1bg->SendToBack();

 b1bg = new TImage(this);
 b1bg->Left = b1->Left;
 b1bg->Top = b1->Top;
 b1bg->Width = b1->Width;
 b1bg->Height = b1->Height;
 b1bg->Parent = b1->Parent;
 b1bg->SendToBack();

 c1bg = new TImage(this);
 c1bg->Left = c1->Left;
 c1bg->Top = c1->Top;
 c1bg->Width = c1->Width;
 c1bg->Height = c1->Height;
 c1bg->Parent = c1->Parent;
 c1bg->SendToBack();

 d1bg = new TImage(this);
 d1bg->Left = d1->Left;
 d1bg->Top = d1->Top;
 d1bg->Width = d1->Width;
 d1bg->Height = d1->Height;
 d1bg->Parent = d1->Parent;
 d1bg->SendToBack();

 e1bg = new TImage(this);
 e1bg->Left = e1->Left;
 e1bg->Top = e1->Top;
 e1bg->Width = e1->Width;
 e1bg->Height = e1->Height;
 e1bg->Parent = e1->Parent;
 e1bg->SendToBack();

 f1bg = new TImage(this);
 f1bg->Left = f1->Left;
 f1bg->Top = f1->Top;
 f1bg->Width = f1->Width;
 f1bg->Height = f1->Height;
 f1bg->Parent = f1->Parent;
 f1bg->SendToBack();

 g1bg = new TImage(this);
 g1bg->Left = g1->Left;
 g1bg->Top = g1->Top;
 g1bg->Width = g1->Width;
 g1bg->Height = g1->Height;
 g1bg->Parent = g1->Parent;
 g1bg->SendToBack();

 h1bg = new TImage(this);
 h1bg->Left = h1->Left;
 h1bg->Top = h1->Top;
 h1bg->Width = h1->Width;
 h1bg->Height = h1->Height;
 h1bg->Parent = h1->Parent;
 h1bg->SendToBack();

 RefreshBoards();

 FENStrings = new TStringList;
 SmithStrings = new TStringList;

 try
 {
  TheBorderImage1->Picture->LoadFromFile(ExtractFilePath(Application->ExeName) + "Images\\border.bmp");
 }
 catch(...)
 {
 }
 TheBorderImage1->Left = -60;
 TheBorderImage1->Top = -60;
 TheBorderImage2->Left = -60;
 TheBorderImage2->Top = -60;
 TheBorderImage2->Picture = TheBorderImage1->Picture;

 TheBorderImage1->Picture->Bitmap->TransparentColor = clWhite;
 TheBorderImage1->Transparent = true;
 TheBorderImage2->Picture->Bitmap->TransparentColor = clWhite;
 TheBorderImage2->Transparent = true;

 CppWebBrowser1->Navigate(WideString("http://www.chesspeer.com/ad"));

 Counter50M = 0;

 StringGrid1->Cells[0][0] = "#";
 StringGrid1->Cells[1][0] = "White";
 StringGrid1->Cells[2][0] = "Black";

 this->Width = 742;
 this->Height = 641;
 if (this->Top < 1) this->Top = 1;
 if (this->Left < 1) this->Left = 1;

 // INITIALIZING...
 a1moved = false;
 e1moved = false;
 h1moved = false;
 a8moved = false;
 e8moved = false;
 h8moved = false;
 EnPassSq = "";
 ComputerColor = 0;
 LastMovedColor = 0;
 DraggedSq = "";
 SentPromoPawn = "";
 PromotedPawn = "";

 Piece[0].Name = "Pawn";
 Piece[0].Color = 1;
 Piece[0].Face = new Graphics::TBitmap();
 ImageList1->GetBitmap(0, Piece[0].Face);

 Piece[1].Name = "Pawn";
 Piece[1].Color = 0;
 Piece[1].Face = new Graphics::TBitmap();
 ImageList1->GetBitmap(1, Piece[1].Face);

 Piece[2].Name = "Knight";
 Piece[2].Color = 1;
 Piece[2].Face = new Graphics::TBitmap();
 ImageList1->GetBitmap(2, Piece[2].Face);

 Piece[3].Name = "Knight";
 Piece[3].Color = 0;
 Piece[3].Face = new Graphics::TBitmap();
 ImageList1->GetBitmap(3, Piece[3].Face);

 Piece[4].Name = "Bishop";
 Piece[4].Color = 1;
 Piece[4].Face = new Graphics::TBitmap();
 ImageList1->GetBitmap(4, Piece[4].Face);

 Piece[5].Name = "Bishop";
 Piece[5].Color = 0;
 Piece[5].Face = new Graphics::TBitmap();
 ImageList1->GetBitmap(5, Piece[5].Face);

 Piece[6].Name = "Rook";
 Piece[6].Color = 1;
 Piece[6].Face = new Graphics::TBitmap();
 ImageList1->GetBitmap(6, Piece[6].Face);

 Piece[7].Name = "Rook";
 Piece[7].Color = 0;
 Piece[7].Face = new Graphics::TBitmap();
 ImageList1->GetBitmap(7, Piece[7].Face);

 Piece[8].Name = "Queen";
 Piece[8].Color = 1;
 Piece[8].Face = new Graphics::TBitmap();
 ImageList1->GetBitmap(8, Piece[8].Face);

 Piece[9].Name = "Queen";
 Piece[9].Color = 0;
 Piece[9].Face = new Graphics::TBitmap();
 ImageList1->GetBitmap(9, Piece[9].Face);

 Piece[10].Name = "King";
 Piece[10].Color = 1;
 Piece[10].Face = new Graphics::TBitmap();
 ImageList1->GetBitmap(10, Piece[10].Face);

 Piece[11].Name = "King";
 Piece[11].Color = 0;
 Piece[11].Face = new Graphics::TBitmap();
 ImageList1->GetBitmap(11, Piece[11].Face);

 Piece[12].Name = "";


 Square[0].Coordinates = "a8";
 Square[0].Piece = Piece[7];
 a8->Picture->Bitmap = Piece[7].Face;

 Square[1].Coordinates = "b8";
 Square[1].Piece = Piece[3];
 b8->Picture->Bitmap = Piece[3].Face;

 Square[2].Coordinates = "c8";
 Square[2].Piece = Piece[5];
 c8->Picture->Bitmap = Piece[5].Face;

 Square[3].Coordinates = "d8";
 Square[3].Piece = Piece[9];
 d8->Picture->Bitmap = Piece[9].Face;

 Square[4].Coordinates = "e8";
 Square[4].Piece = Piece[11];
 e8->Picture->Bitmap = Piece[11].Face;

 Square[5].Coordinates = "f8";
 Square[5].Piece = Piece[5];
 f8->Picture->Bitmap = Piece[5].Face;

 Square[6].Coordinates = "g8";
 Square[6].Piece = Piece[3];
 g8->Picture->Bitmap = Piece[3].Face;

 Square[7].Coordinates = "h8";
 Square[7].Piece = Piece[7];
 h8->Picture->Bitmap = Piece[7].Face;

 Square[8].Coordinates = "a7";
 Square[8].Piece = Piece[1];
 a7->Picture->Bitmap = Piece[1].Face;

 Square[9].Coordinates = "b7";
 Square[9].Piece = Piece[1];
 b7->Picture->Bitmap = Piece[1].Face;

 Square[10].Coordinates = "c7";
 Square[10].Piece = Piece[1];
 c7->Picture->Bitmap = Piece[1].Face;

 Square[11].Coordinates = "d7";
 Square[11].Piece = Piece[1];
 d7->Picture->Bitmap = Piece[1].Face;

 Square[12].Coordinates = "e7";
 Square[12].Piece = Piece[1];
 e7->Picture->Bitmap = Piece[1].Face;

 Square[13].Coordinates = "f7";
 Square[13].Piece = Piece[1];
 f7->Picture->Bitmap = Piece[1].Face;

 Square[14].Coordinates = "g7";
 Square[14].Piece = Piece[1];
 g7->Picture->Bitmap = Piece[1].Face;

 Square[15].Coordinates = "h7";
 Square[15].Piece = Piece[1];
 h7->Picture->Bitmap = Piece[1].Face;

 Square[16].Coordinates = "a6";
 Square[17].Coordinates = "b6";
 Square[18].Coordinates = "c6";
 Square[19].Coordinates = "d6";
 Square[20].Coordinates = "e6";
 Square[21].Coordinates = "f6";
 Square[22].Coordinates = "g6";
 Square[23].Coordinates = "h6";
 Square[24].Coordinates = "a5";
 Square[25].Coordinates = "b5";
 Square[26].Coordinates = "c5";
 Square[27].Coordinates = "d5";
 Square[28].Coordinates = "e5";
 Square[29].Coordinates = "f5";
 Square[30].Coordinates = "g5";
 Square[31].Coordinates = "h5";
 Square[32].Coordinates = "a4";
 Square[33].Coordinates = "b4";
 Square[34].Coordinates = "c4";
 Square[35].Coordinates = "d4";
 Square[36].Coordinates = "e4";
 Square[37].Coordinates = "f4";
 Square[38].Coordinates = "g4";
 Square[39].Coordinates = "h4";
 Square[40].Coordinates = "a3";
 Square[41].Coordinates = "b3";
 Square[42].Coordinates = "c3";
 Square[43].Coordinates = "d3";
 Square[44].Coordinates = "e3";
 Square[45].Coordinates = "f3";
 Square[46].Coordinates = "g3";
 Square[47].Coordinates = "h3";

 for (int i=16; i<=47; i++) {
  Square[i].Piece = Piece[12];
 }

 Square[48].Coordinates = "a2";
 Square[48].Piece = Piece[0];
 a2->Picture->Bitmap = Piece[0].Face;

 Square[49].Coordinates = "b2";
 Square[49].Piece = Piece[0];
 b2->Picture->Bitmap = Piece[0].Face;

 Square[50].Coordinates = "c2";
 Square[50].Piece = Piece[0];
 c2->Picture->Bitmap = Piece[0].Face;

 Square[51].Coordinates = "d2";
 Square[51].Piece = Piece[0];
 d2->Picture->Bitmap = Piece[0].Face;

 Square[52].Coordinates = "e2";
 Square[52].Piece = Piece[0];
 e2->Picture->Bitmap = Piece[0].Face;

 Square[53].Coordinates = "f2";
 Square[53].Piece = Piece[0];
 f2->Picture->Bitmap = Piece[0].Face;

 Square[54].Coordinates = "g2";
 Square[54].Piece = Piece[0];
 g2->Picture->Bitmap = Piece[0].Face;

 Square[55].Coordinates = "h2";
 Square[55].Piece = Piece[0];
 h2->Picture->Bitmap = Piece[0].Face;

 Square[56].Coordinates = "a1";
 Square[56].Piece = Piece[6];
 a1->Picture->Bitmap = Piece[6].Face;

 Square[57].Coordinates = "b1";
 Square[57].Piece = Piece[2];
 b1->Picture->Bitmap = Piece[2].Face;

 Square[58].Coordinates = "c1";
 Square[58].Piece = Piece[4];
 c1->Picture->Bitmap = Piece[4].Face;

 Square[59].Coordinates = "d1";
 Square[59].Piece = Piece[8];
 d1->Picture->Bitmap = Piece[8].Face;

 Square[60].Coordinates = "e1";
 Square[60].Piece = Piece[10];
 e1->Picture->Bitmap = Piece[10].Face;

 Square[61].Coordinates = "f1";
 Square[61].Piece = Piece[4];
 f1->Picture->Bitmap = Piece[4].Face;

 Square[62].Coordinates = "g1";
 Square[62].Piece = Piece[2];
 g1->Picture->Bitmap = Piece[2].Face;

 Square[63].Coordinates = "h1";
 Square[63].Piece = Piece[6];
 h1->Picture->Bitmap = Piece[6].Face;

 // CAPTURED PIECES
 WhiteP->Picture->Bitmap = Piece[0].Face;
 BlackP->Picture->Bitmap = Piece[1].Face;
 WhiteN->Picture->Bitmap = Piece[2].Face;
 BlackN->Picture->Bitmap = Piece[3].Face;
 WhiteB->Picture->Bitmap = Piece[4].Face;
 BlackB->Picture->Bitmap = Piece[5].Face;
 WhiteR->Picture->Bitmap = Piece[6].Face;
 BlackR->Picture->Bitmap = Piece[7].Face;
 WhiteQ->Picture->Bitmap = Piece[8].Face;
 BlackQ->Picture->Bitmap = Piece[9].Face;

 // For Drag & Drop Images
 ImageList2->AddMasked(Piece[0].Face, Piece[0].Face->TransparentColor);
 ImageList2->AddMasked(Piece[1].Face, Piece[1].Face->TransparentColor);
 ImageList2->AddMasked(Piece[2].Face, Piece[2].Face->TransparentColor);
 ImageList2->AddMasked(Piece[3].Face, Piece[3].Face->TransparentColor);
 ImageList2->AddMasked(Piece[4].Face, Piece[4].Face->TransparentColor);
 ImageList2->AddMasked(Piece[5].Face, Piece[5].Face->TransparentColor);
 ImageList2->AddMasked(Piece[6].Face, Piece[6].Face->TransparentColor);
 ImageList2->AddMasked(Piece[7].Face, Piece[7].Face->TransparentColor);
 ImageList2->AddMasked(Piece[8].Face, Piece[8].Face->TransparentColor);
 ImageList2->AddMasked(Piece[9].Face, Piece[9].Face->TransparentColor);
 ImageList2->AddMasked(Piece[10].Face, Piece[10].Face->TransparentColor);
 ImageList2->AddMasked(Piece[11].Face, Piece[11].Face->TransparentColor);
}
//---------------------------------------------------------------------------
void __fastcall TMDIChild::xyMouseDown(TObject *Sender,
      TMouseButton Button, TShiftState Shift, int X, int Y)
{
 if (Shift.Contains(ssLeft)) {
  TImage *Image;
  Image = dynamic_cast<TImage*>(Sender); // Image variable is our square

  if (CheckSq(Image->Name) && ScrollBar1->Position == ScrollBar1->Max && !NoDrag) { // If there is a piece...
   if (Square[SqToNo(Image->Name)].Piece.Color != LastMovedColor && ((hProcess && Square[SqToNo(Image->Name)].Piece.Color != ComputerColor) || !hProcess)) {
    DraggedSq = Image->Name;
    Image->BeginDrag(true);
   }
  } else {
   Scrollit(ScrollBar1->Max);
  }
 }

 if (Shift.Contains(ssRight)) {
  PopupBoard->Popup(Mouse->CursorPos.x, Mouse->CursorPos.y);
 }
}
//---------------------------------------------------------------------------
void __fastcall TMDIChild::xyDragOver(TObject *Sender, TObject *Source,
      int X, int Y, TDragState State, bool &Accept)
{
 Accept = true;
}
//---------------------------------------------------------------------------

bool __fastcall TMDIChild::CheckSq(AnsiString TheSquare) // Is there a piece?
{
 if (Square[SqToNo(TheSquare)].Piece.Name != "") return true;
 return false;
}

//---------------------------------------------------------------------------

int __fastcall TMDIChild::SqToNo(AnsiString TheSquare)
{
 if (TheSquare == "a8") return 0;
 if (TheSquare == "b8") return 1;
 if (TheSquare == "c8") return 2;
 if (TheSquare == "d8") return 3;
 if (TheSquare == "e8") return 4;
 if (TheSquare == "f8") return 5;
 if (TheSquare == "g8") return 6;
 if (TheSquare == "h8") return 7;
 if (TheSquare == "a7") return 8;
 if (TheSquare == "b7") return 9;
 if (TheSquare == "c7") return 10;
 if (TheSquare == "d7") return 11;
 if (TheSquare == "e7") return 12;
 if (TheSquare == "f7") return 13;
 if (TheSquare == "g7") return 14;
 if (TheSquare == "h7") return 15;
 if (TheSquare == "a6") return 16;
 if (TheSquare == "b6") return 17;
 if (TheSquare == "c6") return 18;
 if (TheSquare == "d6") return 19;
 if (TheSquare == "e6") return 20;
 if (TheSquare == "f6") return 21;
 if (TheSquare == "g6") return 22;
 if (TheSquare == "h6") return 23;
 if (TheSquare == "a5") return 24;
 if (TheSquare == "b5") return 25;
 if (TheSquare == "c5") return 26;
 if (TheSquare == "d5") return 27;
 if (TheSquare == "e5") return 28;
 if (TheSquare == "f5") return 29;
 if (TheSquare == "g5") return 30;
 if (TheSquare == "h5") return 31;
 if (TheSquare == "a4") return 32;
 if (TheSquare == "b4") return 33;
 if (TheSquare == "c4") return 34;
 if (TheSquare == "d4") return 35;
 if (TheSquare == "e4") return 36;
 if (TheSquare == "f4") return 37;
 if (TheSquare == "g4") return 38;
 if (TheSquare == "h4") return 39;
 if (TheSquare == "a3") return 40;
 if (TheSquare == "b3") return 41;
 if (TheSquare == "c3") return 42;
 if (TheSquare == "d3") return 43;
 if (TheSquare == "e3") return 44;
 if (TheSquare == "f3") return 45;
 if (TheSquare == "g3") return 46;
 if (TheSquare == "h3") return 47;
 if (TheSquare == "a2") return 48;
 if (TheSquare == "b2") return 49;
 if (TheSquare == "c2") return 50;
 if (TheSquare == "d2") return 51;
 if (TheSquare == "e2") return 52;
 if (TheSquare == "f2") return 53;
 if (TheSquare == "g2") return 54;
 if (TheSquare == "h2") return 55;
 if (TheSquare == "a1") return 56;
 if (TheSquare == "b1") return 57;
 if (TheSquare == "c1") return 58;
 if (TheSquare == "d1") return 59;
 if (TheSquare == "e1") return 60;
 if (TheSquare == "f1") return 61;
 if (TheSquare == "g1") return 62;
 if (TheSquare == "h1") return 63;
 return -1;
}

//---------------------------------------------------------------------------

bool __fastcall TMDIChild::PlayMove(AnsiString FirstSq, AnsiString SecondSq)
{
 if (FirstSq == SecondSq) return false;

 if (FirstSq != "a1" &&
 FirstSq != "a2" &&
 FirstSq != "a3" &&
 FirstSq != "a4" &&
 FirstSq != "a5" &&
 FirstSq != "a6" &&
 FirstSq != "a7" &&
 FirstSq != "a8" &&
 FirstSq != "b1" &&
 FirstSq != "b2" &&
 FirstSq != "b3" &&
 FirstSq != "b4" &&
 FirstSq != "b5" &&
 FirstSq != "b6" &&
 FirstSq != "b7" &&
 FirstSq != "b8" &&
 FirstSq != "c1" &&
 FirstSq != "c2" &&
 FirstSq != "c3" &&
 FirstSq != "c4" &&
 FirstSq != "c5" &&
 FirstSq != "c6" &&
 FirstSq != "c7" &&
 FirstSq != "c8" &&
 FirstSq != "d1" &&
 FirstSq != "d2" &&
 FirstSq != "d3" &&
 FirstSq != "d4" &&
 FirstSq != "d5" &&
 FirstSq != "d6" &&
 FirstSq != "d7" &&
 FirstSq != "d8" &&
 FirstSq != "e1" &&
 FirstSq != "e2" &&
 FirstSq != "e3" &&
 FirstSq != "e4" &&
 FirstSq != "e5" &&
 FirstSq != "e6" &&
 FirstSq != "e7" &&
 FirstSq != "e8" &&
 FirstSq != "f1" &&
 FirstSq != "f2" &&
 FirstSq != "f3" &&
 FirstSq != "f4" &&
 FirstSq != "f5" &&
 FirstSq != "f6" &&
 FirstSq != "f7" &&
 FirstSq != "f8" &&
 FirstSq != "g1" &&
 FirstSq != "g2" &&
 FirstSq != "g3" &&
 FirstSq != "g4" &&
 FirstSq != "g5" &&
 FirstSq != "g6" &&
 FirstSq != "g7" &&
 FirstSq != "g8" &&
 FirstSq != "h1" &&
 FirstSq != "h2" &&
 FirstSq != "h3" &&
 FirstSq != "h4" &&
 FirstSq != "h5" &&
 FirstSq != "h6" &&
 FirstSq != "h7" &&
 FirstSq != "h8") return false;

 if (SecondSq != "a1" &&
 SecondSq != "a2" &&
 SecondSq != "a3" &&
 SecondSq != "a4" &&
 SecondSq != "a5" &&
 SecondSq != "a6" &&
 SecondSq != "a7" &&
 SecondSq != "a8" &&
 SecondSq != "b1" &&
 SecondSq != "b2" &&
 SecondSq != "b3" &&
 SecondSq != "b4" &&
 SecondSq != "b5" &&
 SecondSq != "b6" &&
 SecondSq != "b7" &&
 SecondSq != "b8" &&
 SecondSq != "c1" &&
 SecondSq != "c2" &&
 SecondSq != "c3" &&
 SecondSq != "c4" &&
 SecondSq != "c5" &&
 SecondSq != "c6" &&
 SecondSq != "c7" &&
 SecondSq != "c8" &&
 SecondSq != "d1" &&
 SecondSq != "d2" &&
 SecondSq != "d3" &&
 SecondSq != "d4" &&
 SecondSq != "d5" &&
 SecondSq != "d6" &&
 SecondSq != "d7" &&
 SecondSq != "d8" &&
 SecondSq != "e1" &&
 SecondSq != "e2" &&
 SecondSq != "e3" &&
 SecondSq != "e4" &&
 SecondSq != "e5" &&
 SecondSq != "e6" &&
 SecondSq != "e7" &&
 SecondSq != "e8" &&
 SecondSq != "f1" &&
 SecondSq != "f2" &&
 SecondSq != "f3" &&
 SecondSq != "f4" &&
 SecondSq != "f5" &&
 SecondSq != "f6" &&
 SecondSq != "f7" &&
 SecondSq != "f8" &&
 SecondSq != "g1" &&
 SecondSq != "g2" &&
 SecondSq != "g3" &&
 SecondSq != "g4" &&
 SecondSq != "g5" &&
 SecondSq != "g6" &&
 SecondSq != "g7" &&
 SecondSq != "g8" &&
 SecondSq != "h1" &&
 SecondSq != "h2" &&
 SecondSq != "h3" &&
 SecondSq != "h4" &&
 SecondSq != "h5" &&
 SecondSq != "h6" &&
 SecondSq != "h7" &&
 SecondSq != "h8") return false;

 if (!CheckSq(FirstSq)) return false;

 int FNo = SqToNo(FirstSq);
 int SNo = SqToNo(SecondSq);

 // Other color must be played!
 if (Square[FNo].Piece.Color == LastMovedColor) return false;

 // Are there any illegal move?
 if (CanMove(FirstSq, SecondSq, true) == false) return false;

 ////////////// LETS PREPARE TO MOVE ////////////////////

 TImage *imgF;
 TImage *imgS;

 for (int i = 0; i < ComponentCount; i++) {
  if (Components[i]->Name == FirstSq) {
   imgF = dynamic_cast<TImage *>(Components[i]);
  }
  if (Components[i]->Name == SecondSq) {
   imgS = dynamic_cast<TImage *>(Components[i]);
  }
 }

 if(ScrollBar1->Position != ScrollBar1->Max)
 Scrollit(ScrollBar1->Max);

 // PLAYED ON THE BOARD PICTURE
 imgS->Picture = imgF->Picture;
 imgF->Picture = NULL;

 TheBorderImage1->Left = imgF->Left;
 TheBorderImage1->Top = imgF->Top;
 TheBorderImage2->Left = imgS->Left;
 TheBorderImage2->Top = imgS->Top;

 // MAKE CASTLING PICTURE //
 bool BLC = false, BSC = false, WLC = false, WSC = false;
 if (FirstSq == "e1" && SecondSq == "g1" && Square[FNo].Piece.Name == "King") {
  f1->Picture = h1->Picture;
  h1->Picture = NULL;
  WSC = true;
 }
 if (FirstSq == "e1" && SecondSq == "c1" && Square[FNo].Piece.Name == "King") {
  d1->Picture = a1->Picture;
  a1->Picture = NULL;
  WLC = true;
 }
 if (FirstSq == "e8" && SecondSq == "g8" && Square[FNo].Piece.Name == "King") {
  f8->Picture = h8->Picture;
  h8->Picture = NULL;
  BSC = true;
 }
 if (FirstSq == "e8" && SecondSq == "c8" && Square[FNo].Piece.Name == "King") {
  d8->Picture = a8->Picture;
  a8->Picture = NULL;
  BLC = true;
 }
 ///////////////////

 // TAKEN EN PASSANT...
 bool EP = false;
 if (Square[FNo].Piece.Name == "Pawn" && FirstSq.SubString(1,1) != SecondSq.SubString(1,1)
 && !CheckSq(SecondSq)) EP = true;
 // END PASSANT...

 ScrollBar1->Max = ScrollBar1->Max + 1;
 ScrollBar1->Position = ScrollBar1->Max;

 if (Square[FNo].Piece.Name == "Pawn" &&
 (StrToInt(SecondSq.SubString(2,1)) == 8 || StrToInt(SecondSq.SubString(2,1)) == 1))
 if (PromotedPawn == "") {
  PromotionForm->ShowModal();
  if (PromotedPawn == "") PromotedPawn = "Queen"; 
 }

 // String Grids
 AnsiString Additions = "";
 if (EP == true) Additions += "E";
 if (WSC || BSC) Additions += "c";
 if (WLC || BLC) Additions += "C";
 if (CheckSq(SecondSq)) {
  if (Square[SNo].Piece.Name == "Knight")
  Additions += "n";
  else Additions += Square[SNo].Piece.Name.LowerCase().SubString(1,1);
 }
 if (PromotedPawn != "") {
  if (PromotedPawn == "Knight")
  Additions += "N";
  else Additions += PromotedPawn.UpperCase().SubString(1,1);
 }

 AnsiString Captured = "";
 if (CheckSq(SecondSq) || EP == true) Captured = "x";

 AnsiString FirstLetterOfFirstPiece = Square[FNo].Piece.Name.SubString(1, 1).UpperCase();
 if (Square[FNo].Piece.Name == "Pawn") {
  FirstLetterOfFirstPiece = "";
  if (Captured != "") {
   FirstLetterOfFirstPiece = Square[FNo].Coordinates[1];
  }
 }
 if (Square[FNo].Piece.Name == "Knight") FirstLetterOfFirstPiece = "N";

 AnsiString Identifier = "";
 bool Coor1IsSame = false, Coor2IsSame = false;

 if (Square[FNo].Piece.Color == 1) {

  if (Square[FNo].Piece.Name != "Pawn")
  for (int i=0; i<64; i++) {
   if (Square[i].Piece.Name == Square[FNo].Piece.Name)
   if (FNo != i)
   if (Square[i].Piece.Color == 1) {
    if (CanMove(Square[i].Coordinates, Square[SNo].Coordinates, true)) {
     if (Square[FNo].Coordinates.SubString(1, 1) != Square[i].Coordinates.SubString(1, 1)) {
      Coor1IsSame = true;
      Identifier = Square[FNo].Coordinates.SubString(1, 1);
     } else {
      Coor2IsSame = true;
      Identifier = Square[FNo].Coordinates.SubString(2, 1);
     }
     if (Coor1IsSame && Coor2IsSame) {
      Identifier = Square[FNo].Coordinates;
      break;
     }
    }
   }
  }

  StringGrid1->Cells[0][StringGrid1->RowCount - 8] = StringGrid1->RowCount - 8;
  StringGrid1->Cells[1][StringGrid1->RowCount - 8] = FirstLetterOfFirstPiece + Identifier + Captured + SecondSq;

  if (WSC) StringGrid1->Cells[1][StringGrid1->RowCount - 8] = "O-O";
  if (WLC) StringGrid1->Cells[1][StringGrid1->RowCount - 8] = "O-O-O";

  StringGrid1->Row = StringGrid1->RowCount - 8; // SET FOCUS
  grect.Left = grect.Right = 1;
  grect.Top = grect.Bottom = StringGrid1->RowCount - 8;
  StringGrid1->Selection = grect;
 } else {

  if (Square[FNo].Piece.Name != "Pawn")
  for (int i=0; i<64; i++) {
   if (Square[i].Piece.Name == Square[FNo].Piece.Name)
   if (FNo != i)
   if (Square[i].Piece.Color == 0) {
    if (CanMove(Square[i].Coordinates, Square[SNo].Coordinates, true)) {
     if (Square[FNo].Coordinates.SubString(1, 1) != Square[i].Coordinates.SubString(1, 1)) {
      Coor1IsSame = true;
      Identifier = Square[FNo].Coordinates.SubString(1, 1);
     } else {
      Coor2IsSame = true;
      Identifier = Square[FNo].Coordinates.SubString(2, 1);
     }
     if (Coor1IsSame && Coor2IsSame) {
      Identifier = Square[FNo].Coordinates;
      break;
     }
    }
   }
  }

  StringGrid1->Cells[2][StringGrid1->RowCount - 8] = FirstLetterOfFirstPiece + Identifier + Captured + SecondSq;

  if (BSC) StringGrid1->Cells[2][StringGrid1->RowCount - 8] = "O-O";
  if (BLC) StringGrid1->Cells[2][StringGrid1->RowCount - 8] = "O-O-O";

  StringGrid1->RowCount = StringGrid1->RowCount + 1;
  StringGrid1->Row = StringGrid1->RowCount - 9; // SET FOCUS
  grect.Left = grect.Right = 2;
  grect.Top = grect.Bottom = StringGrid1->RowCount - 9;
  StringGrid1->Selection = grect;
 }

 SmithStrings->Add(FirstSq + SecondSq + Additions);

 if (Square[FNo].Piece.Name != "Pawn" && !CheckSq(SecondSq)) Counter50M++;
 if(Counter50M == 100) {
  this->Caption = this->Caption + " - (Draw)";
  NoDrag = true;
  return true;
 }

 if (CheckSq(SecondSq) || EP == true) {

  if(Square[SqToNo(SecondSq)].Piece.Name == "Pawn" || EP == true) {
   if(Square[SqToNo(FirstSq)].Piece.Color == 0) {
    wp->Caption = IntToStr(StrToInt(wp->Caption) + 1);
    WhiteP->Visible = true;
    if (wp->Caption > 1) wp->Visible = true;
   } else {
    bp->Caption = IntToStr(StrToInt(bp->Caption) + 1);
    BlackP->Visible = true;
    if (bp->Caption > 1) bp->Visible = true;
   }
  }
  if(Square[SqToNo(SecondSq)].Piece.Name == "Knight") {
   if(Square[SqToNo(SecondSq)].Piece.Color == 1) {
    wn->Caption = IntToStr(StrToInt(wn->Caption) + 1);
    WhiteN->Visible = true;
    if (wn->Caption > 1) wn->Visible = true;
   } else {
    bn->Caption = IntToStr(StrToInt(bn->Caption) + 1);
    BlackN->Visible = true;
    if (bn->Caption > 1) bn->Visible = true;
   }
  }
  if(Square[SqToNo(SecondSq)].Piece.Name == "Bishop") {
   if(Square[SqToNo(SecondSq)].Piece.Color == 1) {
    wb->Caption = IntToStr(StrToInt(wb->Caption) + 1);
    WhiteB->Visible = true;
    if (wb->Caption > 1) wb->Visible = true;
   } else {
    bb->Caption = IntToStr(StrToInt(bb->Caption) + 1);
    BlackB->Visible = true;
    if (bb->Caption > 1) bb->Visible = true;
   }
  }
  if(Square[SqToNo(SecondSq)].Piece.Name == "Rook") {
   if(Square[SqToNo(SecondSq)].Piece.Color == 1) {
    wr->Caption = IntToStr(StrToInt(wr->Caption) + 1);
    WhiteR->Visible = true;
    if (wr->Caption > 1) wr->Visible = true;
   } else {
    br->Caption = IntToStr(StrToInt(br->Caption) + 1);
    BlackR->Visible = true;
    if (br->Caption > 1) br->Visible = true;
   }
  }
  if(Square[SqToNo(SecondSq)].Piece.Name == "Queen") {
   if(Square[SqToNo(SecondSq)].Piece.Color == 1) {
    wq->Caption = IntToStr(StrToInt(wq->Caption) + 1);
    WhiteQ->Visible = true;
    if (wq->Caption > 1) wq->Visible = true;
   } else {
    bq->Caption = IntToStr(StrToInt(bq->Caption) + 1);
    BlackQ->Visible = true;
    if (bq->Caption > 1) bq->Visible = true;
   }
  }
  MainForm->PlayMediaSound("Audio\\attack.wav");
 } else {
  MainForm->PlayMediaSound("Audio\\move.wav");
 }

 if (SecondSq == "a8") a8moved = true; // FOR CASTLING (ATE PIECES)
 if (SecondSq == "h8") h8moved = true;
 if (SecondSq == "a1") a1moved = true;
 if (SecondSq == "h1") h1moved = true;

 // TAKEN EN PASSANT...
 if (EP == true) {
  AnsiString EatPawnSq = SecondSq.SubString(1,1) + FirstSq.SubString(2,1);
  Square[SqToNo(EatPawnSq)].Piece = Piece[12];
  for (int i = 0; i < ComponentCount; i++) {
   if (Components[i]->Name == EatPawnSq) {
    TImage *img = dynamic_cast<TImage *>(Components[i]);
    img->Picture = NULL;
    break;
   }
  }
 }
 // END PASSANT...

 Square[SNo].Piece = Square[FNo].Piece; // MOVING
 Square[FNo].Piece = Piece[12];

 if (WSC == true) {
  Square[SqToNo("f1")].Piece = Piece[6];
  Square[SqToNo("h1")].Piece = Piece[12];
 }
 if (WLC == true) {
  Square[SqToNo("d1")].Piece = Piece[6];
  Square[SqToNo("a1")].Piece = Piece[12];
 }
 if (BSC == true) {
  Square[SqToNo("f8")].Piece = Piece[7];
  Square[SqToNo("h8")].Piece = Piece[12];
 }
 if (BLC == true) {
  Square[SqToNo("d8")].Piece = Piece[7];
  Square[SqToNo("a8")].Piece = Piece[12];
 }

 LastMovedColor = !LastMovedColor;

 ////////////// END OF MOVE ////////////////////////

 //////// LOOKING UP PROMOTION //////////
 if (PromotedPawn != "") {
  if (LastMovedColor == 1) {
   if (PromotedPawn == "Queen") {
    Square[SNo].Piece = Piece[8];
    imgS->Picture->Bitmap = Piece[8].Face;
    StringGrid1->Cells[1][StringGrid1->RowCount - 8] = StringGrid1->Cells[1][StringGrid1->RowCount - 8] + "=Q";
   }
   if (PromotedPawn == "Rook") {
    Square[SNo].Piece = Piece[6];
    imgS->Picture->Bitmap = Piece[6].Face;
    StringGrid1->Cells[1][StringGrid1->RowCount - 8] = StringGrid1->Cells[1][StringGrid1->RowCount - 8] + "=R";
   }
   if (PromotedPawn == "Bishop") {
    Square[SNo].Piece = Piece[4];
    imgS->Picture->Bitmap = Piece[4].Face;
    StringGrid1->Cells[1][StringGrid1->RowCount - 8] = StringGrid1->Cells[1][StringGrid1->RowCount - 8] + "=B";
   }
   if (PromotedPawn == "Knight") {
    Square[SNo].Piece = Piece[2];
    imgS->Picture->Bitmap = Piece[2].Face;
    StringGrid1->Cells[1][StringGrid1->RowCount - 8] = StringGrid1->Cells[1][StringGrid1->RowCount - 8] + "=N";
   }
  } else {
   if (PromotedPawn == "Queen") {
    Square[SNo].Piece = Piece[9];
    imgS->Picture->Bitmap = Piece[9].Face;
    StringGrid1->Cells[2][StringGrid1->RowCount - 9] = StringGrid1->Cells[2][StringGrid1->RowCount - 9] + "=Q";
   }
   if (PromotedPawn == "Rook") {
    Square[SNo].Piece = Piece[7];
    imgS->Picture->Bitmap = Piece[7].Face;
    StringGrid1->Cells[2][StringGrid1->RowCount - 9] = StringGrid1->Cells[2][StringGrid1->RowCount - 9] + "=R";
   }
   if (PromotedPawn == "Bishop") {
    Square[SNo].Piece = Piece[5];
    imgS->Picture->Bitmap = Piece[5].Face;
    StringGrid1->Cells[2][StringGrid1->RowCount - 9] = StringGrid1->Cells[2][StringGrid1->RowCount - 9] + "=B";
   }
   if (PromotedPawn == "Knight") {
    Square[SNo].Piece = Piece[3];
    imgS->Picture->Bitmap = Piece[3].Face;
    StringGrid1->Cells[2][StringGrid1->RowCount - 9] = StringGrid1->Cells[2][StringGrid1->RowCount - 9] + "=N";
   }
  }

  SentPromoPawn = PromotedPawn[1];
  if (SentPromoPawn == "K") SentPromoPawn = "N";
  PromotedPawn = "";
 }
 //////// END LOOKING UP PROMOTION //////////

 // INITALIZE EN PASSANT...

 EnPassSq = "";

 if (Square[SNo].Piece.Name == "Pawn") {
  int RankOfFirstSq = StrToInt(FirstSq.SubString(2,1));
  int RankOfSecondSq = StrToInt(SecondSq.SubString(2,1));
  if (Square[SNo].Piece.Color == 1) {
   if (RankOfFirstSq == 2 && RankOfSecondSq == 4) EnPassSq = FirstSq.SubString(1,1) + "3";
  } else {
   if (RankOfFirstSq == 7 && RankOfSecondSq == 5) EnPassSq = FirstSq.SubString(1,1) + "6";
  }
 }

 //////// LOOKING UP CHECK //////////

 int CheckerCounter = 0;
 int CheckerSqNo = -1;
 AnsiString KingsSquare = "";

 if (Square[SNo].Piece.Color == 1) { // if white is played
  // Search all pieces in order to understand can they move to king?

  for (int i=0; i<64; i++) {
   if (Square[i].Piece.Name == "King")
   if (Square[i].Piece.Color == 0) {
    KingsSquare = Square[i].Coordinates;
    break;
   }
  }
  for (int i=0; i<64; i++)
  if (Square[i].Piece.Color == 1)
  if (Square[i].Piece.Name != "" && Square[i].Piece.Name != "King")
  if (CanMove(Square[i].Coordinates, KingsSquare, false) == true) {
   CheckerSqNo = i;
   CheckerCounter++;
   if (CheckerCounter == 1)
   StringGrid1->Cells[1][StringGrid1->RowCount - 8] = StringGrid1->Cells[1][StringGrid1->RowCount - 8] + "+";
  }
 } else { // if black is played
  for (int i=0; i<64; i++) {
   if (Square[i].Piece.Name == "King")
   if (Square[i].Piece.Color == 1) {
    KingsSquare = Square[i].Coordinates;
    break;
   }
  }
  for (int i=0; i<64; i++)
  if (Square[i].Piece.Color == 0)
  if (Square[i].Piece.Name != "" && Square[i].Piece.Name != "King")
  if (CanMove(Square[i].Coordinates, KingsSquare, false) == true) {
   CheckerSqNo = i;
   CheckerCounter++;
   if (CheckerCounter == 1)
   StringGrid1->Cells[2][StringGrid1->RowCount - 9] = StringGrid1->Cells[2][StringGrid1->RowCount - 9] + "+";
  }
 }
 //////// END OF LOOKING UP CHECK ///

 // LOOK FOR CHECKMATE //
 bool IsCheckMate = true;
 if (CheckerCounter > 0) {

  char KingsSqFile = KingsSquare[1];
  int KingsSqRank = StrToInt(KingsSquare.SubString(2,1));

  char KingsSqPlus1 = KingsSqFile + 1;
  char KingsSqLess1 = KingsSqFile - 1;

  AnsiString AnsiOfKingsSq = KingsSqFile;
  AnsiString AnsiOfKingsSqPlus1 = KingsSqPlus1;
  AnsiString AnsiOfKingsSqLess1 = KingsSqLess1;

  // RUNNING and eating CONTROL for king (FOR MORE THAN ONE CHECKER)
  if (CanMove(KingsSquare, AnsiOfKingsSqLess1 + IntToStr(KingsSqRank-1), true)) IsCheckMate = false;
  else if (CanMove(KingsSquare, AnsiOfKingsSqLess1 + IntToStr(KingsSqRank), true)) IsCheckMate = false;
  else if (CanMove(KingsSquare, AnsiOfKingsSqLess1 + IntToStr(KingsSqRank+1), true)) IsCheckMate = false;
  else if (CanMove(KingsSquare, AnsiOfKingsSqPlus1 + IntToStr(KingsSqRank-1), true)) IsCheckMate = false;
  else if (CanMove(KingsSquare, AnsiOfKingsSqPlus1 + IntToStr(KingsSqRank), true)) IsCheckMate = false;
  else if (CanMove(KingsSquare, AnsiOfKingsSqPlus1 + IntToStr(KingsSqRank+1), true)) IsCheckMate = false;
  else if (CanMove(KingsSquare, AnsiOfKingsSq + IntToStr(KingsSqRank-1), true)) IsCheckMate = false;
  else if (CanMove(KingsSquare, AnsiOfKingsSq + IntToStr(KingsSqRank+1), true)) IsCheckMate = false;

  if (CheckerCounter == 1 && IsCheckMate == true) { // Only 1 piece is checking and King can not RUN or eat it...

   // EATING CONTROL
   for (int i=0; i<64; i++)
   if (Square[i].Piece.Color != Square[SNo].Piece.Color) // Opposite color
   if (Square[i].Piece.Name != "" && Square[i].Piece.Name != "King") // If King can eat we can find it in running control
   if (CanMove(Square[i].Coordinates, Square[CheckerSqNo].Coordinates, true)) IsCheckMate = false;

   // CLOSING CONTROL
   if (IsCheckMate == true){
    char CheckerSqFile = Square[CheckerSqNo].Coordinates[1];
    int CheckerSqRank = StrToInt(Square[CheckerSqNo].Coordinates.SubString(2,1));

    int LessOfFile = abs(KingsSqFile - CheckerSqFile);
    int LessOfRank = abs(KingsSqRank - CheckerSqRank);

    AnsiString ForChar = "";

    if (LessOfFile > 1 || LessOfRank > 1) { // must at least one bigger than 1

     if (Square[CheckerSqNo].Piece.Name == "Rook" || Square[CheckerSqNo].Piece.Name == "Queen") {
      if (LessOfFile > 0 && LessOfRank == 0) { // horizontal check
       if (CheckerSqFile < KingsSqFile) { // Rook .. .. .. King
        for (char i = CheckerSqFile + 1; i < KingsSqFile; i++) { // Look the sq.
         for (int j=0; j<64; j++) {
          if (Square[j].Piece.Name != "" && Square[j].Piece.Name != "King")
          if (Square[j].Piece.Color != Square[SNo].Piece.Color) {
           ForChar = i;
           if (CanMove(Square[j].Coordinates, ForChar + IntToStr(KingsSqRank), true)) {
            IsCheckMate = false;
            break;
           }
          }
         }
         if (IsCheckMate == false) break;
        }
       } else { // King .. .. .. Rook
        for (char i = KingsSqFile + 1; i < CheckerSqFile; i++) { // Look the sq.
         for (int j=0; j<64; j++) {
          if (Square[j].Piece.Name != "" && Square[j].Piece.Name != "King")
          if (Square[j].Piece.Color != Square[SNo].Piece.Color) {
           ForChar = i;
           if (CanMove(Square[j].Coordinates, ForChar + IntToStr(KingsSqRank), true)) {
            IsCheckMate = false;
            break;
           }
          }
         }
         if (IsCheckMate == false) break;
        }
       }
      } else if (LessOfFile == 0 && LessOfRank > 0) { //vertical check
       if (KingsSqRank < CheckerSqRank) { // Rook .. .. .. King
        for (int i = KingsSqRank + 1; i < CheckerSqRank; i++) { // Look the sq.
         for (int j=0; j<64; j++) {
          if (Square[j].Piece.Name != "" && Square[j].Piece.Name != "King")
          if (Square[j].Piece.Color != Square[SNo].Piece.Color)
          if (CanMove(Square[j].Coordinates, AnsiOfKingsSq + IntToStr(i), true)) {
           IsCheckMate = false;
           break;
          }
         }
         if (IsCheckMate == false) break;
        }
       } else { // King .. .. .. Rook
        for (int i = CheckerSqRank + 1; i < KingsSqRank; i++) { // Look the sq.
         for (int j=0; j<64; j++) {
          if (Square[j].Piece.Name != "" && Square[j].Piece.Name != "King")
          if (Square[j].Piece.Color != Square[SNo].Piece.Color)
          if (CanMove(Square[j].Coordinates, AnsiOfKingsSq + IntToStr(i), true)) {
           IsCheckMate = false;
           break;
          }
         }
         if (IsCheckMate == false) break;
        }
       }
      }
     }
     if ((Square[CheckerSqNo].Piece.Name == "Bishop" || Square[CheckerSqNo].Piece.Name == "Queen") && IsCheckMate != false) {
      AnsiString ControllingSq = "";

      if (KingsSqFile > CheckerSqFile && KingsSqRank > CheckerSqRank) { // top right
       int RankChange = CheckerSqRank;
       for (char i = CheckerSqFile + 1; i < KingsSqFile; i++) {
        AnsiString AnsiI = i;
        ControllingSq = AnsiI + IntToStr(++RankChange);
        for (int j=0; j<64; j++) {
         if (Square[j].Piece.Name != "" && Square[j].Piece.Name != "King")
         if (Square[j].Piece.Color != Square[SNo].Piece.Color)
         if (CanMove(Square[j].Coordinates, ControllingSq, true)) {
          IsCheckMate = false;
          break;
         }
        }
        if (IsCheckMate == false) break;
       }
      }
      if (KingsSqFile < CheckerSqFile && KingsSqRank > CheckerSqRank) { // top left
       int RankChange = KingsSqRank;
       for (char i = KingsSqFile + 1; i < CheckerSqFile; i++) {
        AnsiString AnsiI = i;
        ControllingSq = AnsiI + IntToStr(--RankChange);
        for (int j=0; j<64; j++) {
         if (Square[j].Piece.Name != "" && Square[j].Piece.Name != "King")
         if (Square[j].Piece.Color != Square[SNo].Piece.Color)
         if (CanMove(Square[j].Coordinates, ControllingSq, true)) {
          IsCheckMate = false;
          break;
         }
        }
        if (IsCheckMate == false) break;
       }
      }
      if (KingsSqFile > CheckerSqFile && KingsSqRank < CheckerSqRank) { // bottom right
       int RankChange = CheckerSqRank;
       for (char i = CheckerSqFile + 1; i < KingsSqFile; i++) {
        AnsiString AnsiI = i;
        ControllingSq = AnsiI + IntToStr(--RankChange);
        for (int j=0; j<64; j++) {
         if (Square[j].Piece.Name != "" && Square[j].Piece.Name != "King")
         if (Square[j].Piece.Color != Square[SNo].Piece.Color)
         if (CanMove(Square[j].Coordinates, ControllingSq, true)) {
          IsCheckMate = false;
          break;
         }
        }
        if (IsCheckMate == false) break;
       }
      }
      if (KingsSqFile < CheckerSqFile && KingsSqRank < CheckerSqRank) { // bottom left
       int RankChange = KingsSqRank;
       for (char i = KingsSqFile + 1; i < CheckerSqFile; i++) {
        AnsiString AnsiI = i;
        ControllingSq = AnsiI + IntToStr(++RankChange);
        for (int j=0; j<64; j++) {
         if (Square[j].Piece.Name != "" && Square[j].Piece.Name != "King")
         if (Square[j].Piece.Color != Square[SNo].Piece.Color)
         if (CanMove(Square[j].Coordinates, ControllingSq, true)) {
          IsCheckMate = false;
          break;
         }
        }
        if (IsCheckMate == false) break;
       }
      }
     }
    } // End bigger than 1

   } // End Closing Control

  }

  if (IsCheckMate == true) {
   MainForm->PlayMediaSound("Audio\\mate.wav");
   NoDrag = true;
   if (LastMovedColor == 1)
   this->Caption = this->Caption + " - (White Wins)";
   else
   this->Caption = this->Caption + " - (Black Wins)";
   return true;
  }

 }
 ////////////////////////

 if (FirstSq == "a8") a8moved = true; // FOR CASTLING
 if (FirstSq == "h8") h8moved = true;
 if (FirstSq == "a1") a1moved = true;
 if (FirstSq == "h1") h1moved = true;
 if (FirstSq == "e1") e1moved = true;
 if (FirstSq == "e8") e8moved = true;

 // INITIALIZE FEN

 AnsiString FENpart1 = "";

 for (int i = 0; i < 64; i++) {
  if (i % 8 == 0 && i != 0) {
   FENpart1 += "/";
  }
  if (Square[i].Piece.Name == "Rook") {
   if (Square[i].Piece.Color == 1) {
    FENpart1 += "R";
   } else {
    FENpart1 += "r";
   }
  }
  else if (Square[i].Piece.Name == "Knight") {
   if (Square[i].Piece.Color == 1) {
    FENpart1 += "N";
   } else {
    FENpart1 += "n";
   }
  }
  else if (Square[i].Piece.Name == "Bishop") {
   if (Square[i].Piece.Color == 1) {
    FENpart1 += "B";
   } else {
    FENpart1 += "b";
   }
  }
  else if (Square[i].Piece.Name == "Queen") {
   if (Square[i].Piece.Color == 1) {
    FENpart1 += "Q";
   } else {
    FENpart1 += "q";
   }
  }
  else if (Square[i].Piece.Name == "King") {
   if (Square[i].Piece.Color == 1) {
    FENpart1 += "K";
   } else {
    FENpart1 += "k";
   }
  }
  else if (Square[i].Piece.Name == "Pawn") {
   if (Square[i].Piece.Color == 1) {
    FENpart1 += "P";
   } else {
    FENpart1 += "p";
   }
  }
  else { // Space
   int FP1Len = FENpart1.Length();
   AnsiString LastFP1 = FENpart1.SubString(FP1Len, 1);
   if (LastFP1 == "1" || LastFP1 == "2" || LastFP1 == "3" ||
   LastFP1 == "4" || LastFP1 == "5" || LastFP1 == "6" || LastFP1 == "7") { // AFTER NUMBER
    FENpart1 = FENpart1.SubString(1, FP1Len - 1);
    FENpart1 += IntToStr(StrToInt(LastFP1) + 1);
   } else { // AFTER LETTER OR BECOME FIRST
    FENpart1 += "1";
   }
  }
 }

 if (LastMovedColor == 1) { // White played
  if (!FENpart1.AnsiPos("p") && !FENpart1.AnsiPos("q") && !FENpart1.AnsiPos("r")) {
   if((!FENpart1.AnsiPos("b") && !FENpart1.AnsiPos("n")) ||
      (FENpart1.AnsiPos("b") && !FENpart1.AnsiPos("n")) ||
      (FENpart1.AnsiPos("n") && !FENpart1.AnsiPos("b"))) { // Blacks null or n or b
  //
  if (!FENpart1.AnsiPos("P") && !FENpart1.AnsiPos("Q") && !FENpart1.AnsiPos("R")) {
   if((!FENpart1.AnsiPos("B") && !FENpart1.AnsiPos("N")) ||
      (FENpart1.AnsiPos("B") && !FENpart1.AnsiPos("N")) ||
      (FENpart1.AnsiPos("N") && !FENpart1.AnsiPos("B"))) { // Whites NULL or N or B
   NoDrag = true;
   this->Caption = this->Caption + " - (Draw)";
   return true;
   }
  }
  //
   }
  }
 } else {
  if (!FENpart1.AnsiPos("P") && !FENpart1.AnsiPos("Q") && !FENpart1.AnsiPos("R")) {
   if((!FENpart1.AnsiPos("B") && !FENpart1.AnsiPos("N")) ||
      (FENpart1.AnsiPos("B") && !FENpart1.AnsiPos("N")) ||
      (FENpart1.AnsiPos("N") && !FENpart1.AnsiPos("B"))) {
  //
  if (!FENpart1.AnsiPos("p") && !FENpart1.AnsiPos("q") && !FENpart1.AnsiPos("r")) {
   if((!FENpart1.AnsiPos("b") && !FENpart1.AnsiPos("n")) ||
      (FENpart1.AnsiPos("b") && !FENpart1.AnsiPos("n")) ||
      (FENpart1.AnsiPos("n") && !FENpart1.AnsiPos("b"))) {
   NoDrag = true;
   this->Caption = this->Caption + " - (Draw)";
   return true;
   }
  }
  //
   }
  }
 }

 FENStrings->Add(FENpart1);

 // Looking For Draw
 int y = 0;
 for (int i = 0; i < FENStrings->Count; i++) { // LOOK FOR 3 SAME POSITION
  if (FENStrings->Strings[i] == FENpart1) y++;
  if (y == 3) {
   NoDrag = true;
   this->Caption = this->Caption + " - (Draw)";
   return true;
  }
 }
 /////////////////


 TStringList *stalelist;
 bool stalemate = true;
 for (int i=0; i<64; i++)
 if (Square[i].Piece.Color != LastMovedColor)
 if (Square[i].Piece.Name != "") {
  stalelist = LegalSquares(Square[i].Coordinates);
  if (stalelist->Count > 0) {
   stalemate = false;
   break;
  }
 }

 if (stalemate) {
  NoDrag = true;
  this->Caption = this->Caption + " - (Stalemate)";
  return true;
 }

 return true;
}

//---------------------------------------------------------------------------

bool __fastcall TMDIChild::CanMove(AnsiString FirstSq, AnsiString SecondSq, bool CheckForPinAndMate)
{
 int FirstSquareNo = SqToNo(FirstSq);
 int SecondSquareNo = SqToNo(SecondSq);

 if (FirstSquareNo == -1 || SecondSquareNo == -1) return false;

 char FileOfFirstSq = FirstSq[1];
 char FileOfSecondSq = SecondSq[1];
 int RankOfFirstSq = StrToInt(FirstSq.SubString(2,1));
 int RankOfSecondSq = StrToInt(SecondSq.SubString(2,1));

 int LessOfFile = abs(FileOfSecondSq - FileOfFirstSq);
 int LessOfRank = abs(RankOfSecondSq - RankOfFirstSq);

 AnsiString AnsiFirstFile = FileOfFirstSq;
 AnsiString AnsiSecondFile = FileOfSecondSq;

 AnsiString ControllingSq = "";
 AnsiString ForI = "";

 if (!CheckSq(FirstSq)) return false;

 if (Square[FirstSquareNo].Piece.Name == "Rook") {
  // Gone file and rank
  if (LessOfFile != 0 && LessOfRank != 0) return false;

  if (LessOfFile == 0) { // Gone only file
   if (RankOfSecondSq > RankOfFirstSq) { // Gone top
    for (int i = RankOfFirstSq + 1; i < RankOfSecondSq; i++) { // Look the sq.
     ControllingSq = AnsiFirstFile + IntToStr(i);
     if (CheckSq(ControllingSq)) return false;
    }
   } else { // bottom
    for (int i = RankOfSecondSq + 1; i < RankOfFirstSq; i++) {
     ControllingSq = AnsiFirstFile + IntToStr(i);
     if (CheckSq(ControllingSq)) return false;
    }
   }
  }

  if (LessOfRank == 0) { // rank
   if (FileOfSecondSq > FileOfFirstSq) { // right
    for (char i = FileOfFirstSq + 1; i < FileOfSecondSq; i++) {
     ForI = i;
     ControllingSq = ForI + IntToStr(RankOfFirstSq);
     if (CheckSq(ControllingSq)) return false;
    }
   } else { // left
    for (char i = FileOfSecondSq + 1; i < FileOfFirstSq; i++) {
     ForI = i;
     ControllingSq = ForI + IntToStr(RankOfFirstSq);
     if (CheckSq(ControllingSq)) return false;
    }
   }
  }
 }
 if (Square[FirstSquareNo].Piece.Name == "Bishop") {
  // no diagonal
  if (LessOfFile != LessOfRank) return false;
  if (FileOfSecondSq > FileOfFirstSq && RankOfSecondSq > RankOfFirstSq) { // top right
   int RankChange = RankOfFirstSq;
   for (char i = FileOfFirstSq + 1; i < FileOfSecondSq; i++) {
    ForI = i;
    ControllingSq = ForI + IntToStr(++RankChange);
    if (CheckSq(ControllingSq)) return false;
   }
  }
  if (FileOfSecondSq < FileOfFirstSq && RankOfSecondSq > RankOfFirstSq) { // top left
   int RankChange = RankOfSecondSq;
   for (char i = FileOfSecondSq + 1; i < FileOfFirstSq; i++) {
    ForI = i;
    ControllingSq = ForI + IntToStr(--RankChange);
    if (CheckSq(ControllingSq)) return false;
   }
  }
  if (FileOfSecondSq > FileOfFirstSq && RankOfSecondSq < RankOfFirstSq) { // bottom right
   int RankChange = RankOfFirstSq;
   for (char i = FileOfFirstSq + 1; i < FileOfSecondSq; i++) {
    ForI = i;
    ControllingSq = ForI + IntToStr(--RankChange);
    if (CheckSq(ControllingSq)) return false;
   }
  }
  if (FileOfSecondSq < FileOfFirstSq && RankOfSecondSq < RankOfFirstSq) { // bottom left
   int RankChange = RankOfSecondSq;
   for (char i = FileOfSecondSq + 1; i < FileOfFirstSq; i++) {
    ForI = i;
    ControllingSq = ForI + IntToStr(++RankChange);
    if (CheckSq(ControllingSq)) return false;
   }
  }
 }
 if (Square[FirstSquareNo].Piece.Name == "Knight") {
  if ((abs(LessOfFile - LessOfRank) != 1) || (LessOfFile > 2) || (LessOfRank > 2) || (LessOfFile < 1) || (LessOfRank < 1)) return false;
 }
 if (Square[FirstSquareNo].Piece.Name == "Queen") {
  if (LessOfFile != 0 && LessOfRank != 0 && LessOfFile != LessOfRank) return false;

  if (LessOfFile == 0) { // Gone only file
   if (RankOfSecondSq > RankOfFirstSq) { // Gone top
    for (int i = RankOfFirstSq + 1; i < RankOfSecondSq; i++) { // Look the sq.
     ControllingSq = AnsiFirstFile + IntToStr(i);
     if (CheckSq(ControllingSq)) return false;
    }
   } else { // bottom
    for (int i = RankOfSecondSq + 1; i < RankOfFirstSq; i++) {
     ControllingSq = AnsiFirstFile + IntToStr(i);
     if (CheckSq(ControllingSq)) return false;
    }
   }
  }

  if (LessOfRank == 0) { // rank
   if (FileOfSecondSq > FileOfFirstSq) { // right
    for (char i = FileOfFirstSq + 1; i < FileOfSecondSq; i++) {
     ForI = i;
     ControllingSq = ForI + IntToStr(RankOfFirstSq);
     if (CheckSq(ControllingSq)) return false;
    }
   } else { // left
    for (char i = FileOfSecondSq + 1; i < FileOfFirstSq; i++) {
     ForI = i;
     ControllingSq = ForI + IntToStr(RankOfFirstSq);
     if (CheckSq(ControllingSq)) return false;
    }
   }
  }

  if (FileOfSecondSq > FileOfFirstSq && RankOfSecondSq > RankOfFirstSq) { // top right
   int RankChange = RankOfFirstSq;
   for (char i = FileOfFirstSq + 1; i < FileOfSecondSq; i++) {
    ForI = i;
    ControllingSq = ForI + IntToStr(++RankChange);
    if (CheckSq(ControllingSq)) return false;
   }
  }

  if (FileOfSecondSq < FileOfFirstSq && RankOfSecondSq > RankOfFirstSq) { // top left
   int RankChange = RankOfSecondSq;
   for (char i = FileOfSecondSq + 1; i < FileOfFirstSq; i++) {
    ForI = i;
    ControllingSq = ForI + IntToStr(--RankChange);
    if (CheckSq(ControllingSq)) return false;
   }
  }

  if (FileOfSecondSq > FileOfFirstSq && RankOfSecondSq < RankOfFirstSq) { // bottom right
   int RankChange = RankOfFirstSq;
   for (char i = FileOfFirstSq + 1; i < FileOfSecondSq; i++) {
    ForI = i;
    ControllingSq = ForI + IntToStr(--RankChange);
    if (CheckSq(ControllingSq)) return false;
   }
  }

  if (FileOfSecondSq < FileOfFirstSq && RankOfSecondSq < RankOfFirstSq) { // bottom left
   int RankChange = RankOfSecondSq;
   for (char i = FileOfSecondSq + 1; i < FileOfFirstSq; i++) {
    ForI = i;
    ControllingSq = ForI + IntToStr(++RankChange);
    if (CheckSq(ControllingSq)) return false;
   }
  }
 }
 if (Square[FirstSquareNo].Piece.Name == "King") {
  bool Castling = false, CanWLCastle = true, CanBLCastle = true, CanWSCastle = true, CanBSCastle = true;

  if ((FirstSq == "e1" && (SecondSq == "c1" || SecondSq == "g1")) || (FirstSq == "e8" && (SecondSq == "c8" || SecondSq == "g8"))) { // Castling Move

   if (CheckSq("f1") || CheckSq("g1")) CanWSCastle = false;
   if (CheckSq("c1") || CheckSq("d1")) CanWLCastle = false;
   if (CheckSq("f8") || CheckSq("g8")) CanBSCastle = false;
   if (CheckSq("c8") || CheckSq("d8")) CanBLCastle = false;

   for (int i=0; i<64; i++) { // For Optimization This Code Will Be Moved To Bottom
    if (Square[i].Piece.Name != "") {
     if (Square[i].Piece.Name != "King") {
      if (Square[i].Piece.Color == 0) {
       if (CanMove(Square[i].Coordinates, "f1", false) == true || CanMove(Square[i].Coordinates, "g1", false) == true) CanWSCastle = false;
       if (CanMove(Square[i].Coordinates, "c1", false) == true || CanMove(Square[i].Coordinates, "d1", false) == true) CanWLCastle = false;
       if (CanMove(Square[i].Coordinates, "e1", false) == true) {
        CanWSCastle = false;
        CanWLCastle = false;
       }
      } else {
       if (CanMove(Square[i].Coordinates, "f8", false) == true || CanMove(Square[i].Coordinates, "g8", false) == true) CanBSCastle = false;
       if (CanMove(Square[i].Coordinates, "c8", false) == true || CanMove(Square[i].Coordinates, "d8", false) == true) CanBLCastle = false;
       if (CanMove(Square[i].Coordinates, "e8", false) == true) {
        CanBSCastle = false;
        CanBLCastle = false;
       }
      }
     }
    }
   }

   if (Square[SqToNo("g2")].Piece.Name == "King" || Square[SqToNo("h2")].Piece.Name == "King") CanWSCastle = false;
   if (Square[SqToNo("b2")].Piece.Name == "King" || Square[SqToNo("c2")].Piece.Name == "King") CanWLCastle = false;
   if (Square[SqToNo("g7")].Piece.Name == "King" || Square[SqToNo("h7")].Piece.Name == "King") CanBSCastle = false;
   if (Square[SqToNo("b7")].Piece.Name == "King" || Square[SqToNo("c7")].Piece.Name == "King") CanBLCastle = false;

   if (e1moved == false) {
    if (CanWSCastle == true && SecondSq == "g1" && h1moved == false) Castling = true;
    if (CanWLCastle == true && SecondSq == "c1" && a1moved == false) Castling = true;
   }

   if (e8moved == false) {
    if (CanBSCastle == true && SecondSq == "g8" && h8moved == false) Castling = true;
    if (CanBLCastle == true && SecondSq == "c8" && a8moved == false) Castling = true;
   }

  } // End Of Castling Move

  // More than 1 square and don't make castling...
  if ((LessOfFile > 1 || LessOfRank > 1) && Castling == false) return false;
 }
 if (Square[FirstSquareNo].Piece.Name == "Pawn") {
  // No back
  if (Square[FirstSquareNo].Piece.Color == 1 && RankOfFirstSq > RankOfSecondSq) return false;
  if (Square[FirstSquareNo].Piece.Color == 0 && RankOfFirstSq < RankOfSecondSq) return false;
  // max. 1 step left and right, 2 step forward
  if (LessOfFile > 1 || LessOfRank > 2) return false;
  // left or right but not forward?
  if (LessOfFile == 1 && LessOfRank != 1) return false;
  // 2 step but not in 2. rank for white or 7. rank for black
  if ((LessOfRank == 2) && ((Square[FirstSquareNo].Piece.Color == 1 && RankOfFirstSq != 2) || (Square[FirstSquareNo].Piece.Color == 0 && RankOfFirstSq != 7))) return false;
  // diagonal but no pieces
  if (LessOfFile == 1 && LessOfRank == 1 && !CheckSq(SecondSq)) {
   if (Square[FirstSquareNo].Piece.Color == 1) {
    if (RankOfFirstSq != 5) return false;
    if (EnPassSq != AnsiSecondFile + "6") return false;
   } else {
    if (RankOfFirstSq != 4) return false;
    if (EnPassSq != AnsiSecondFile + "3") return false;
   }
  }
  // 1 or 2 step forward but there is a piece
  if (LessOfFile == 0 && LessOfRank >= 1 && CheckSq(SecondSq)) return false;
  // 2 step forward but there is a piece in 1. sq
  if (LessOfRank == 2) {
   if (RankOfFirstSq == 2 && CheckSq(AnsiFirstFile + "3")) return false;
   if (RankOfFirstSq == 7 && CheckSq(AnsiFirstFile + "6")) return false;
  }
 }

 if (CheckSq(SecondSq)) { // Is there any piece on second sq?
  if (Square[FirstSquareNo].Piece.Color == Square[SecondSquareNo].Piece.Color) return false; // same colors can't be on one sq.
 }




 if (CheckForPinAndMate == true) {

 bool returning = true;

 ///////// NEXT MOVE PLANNING /////////////////////////////
 Piece[13] = Square[SecondSquareNo].Piece; // BACK UP
 Square[SecondSquareNo].Piece = Square[FirstSquareNo].Piece;
 Square[FirstSquareNo].Piece = Piece[12];
 /////////////////////////////////////////////////////

 if (Square[SecondSquareNo].Piece.Color == 1) { // if white is played
  // Search all pieces in order to understand can they move to king?
  AnsiString KingsSquare = "";
  for (int i=0; i<64; i++) {
   if (Square[i].Piece.Name == "King")
   if (Square[i].Piece.Color == 1) {
    KingsSquare = Square[i].Coordinates;
    break;
   }
  }
  for (int i=0; i<64; i++)
  if (Square[i].Piece.Name != "")
  if (Square[i].Piece.Color == 0)
  if (CanMove(Square[i].Coordinates, KingsSquare, false) == true) {
   returning = false;
   break;
  }
 } else { // if black is played
  AnsiString KingsSquare = "";
  for (int i=0; i<64; i++) {
   if (Square[i].Piece.Name == "King")
   if (Square[i].Piece.Color == 0) {
    KingsSquare = Square[i].Coordinates;
    break;
   }
  }
  for (int i=0; i<64; i++)
  if (Square[i].Piece.Name != "")
  if (Square[i].Piece.Color == 1)
  if (CanMove(Square[i].Coordinates, KingsSquare, false) == true) {
   returning = false;
   break;
  }
 }
 ///////// END OF NEXT MOVE /////////////////////////////
 Square[FirstSquareNo].Piece = Square[SecondSquareNo].Piece;
 Square[SecondSquareNo].Piece = Piece[13];
 ////////////////////////////////////////////////////////
 if (returning == false) return false;

 }

 return true;
}

//---------------------------------------------------------------------------

void __fastcall TMDIChild::xyDragDrop(TObject *Sender, TObject *Source,
      int X, int Y)
{
 TImage *Image;
 Image=dynamic_cast<TImage*>(Sender);
 if (DraggedSq != Image->Name)
 if(PlayMove(DraggedSq, Image->Name)) {
  if (hProcess)
  WritePFile(DraggedSq + Image->Name + "\n");

  if (this->Caption.SubString(1, 11) == "Active Game") { // active game //////////////////

  if(MainForm->IdTCPServer1->Active == true) {

    TList *List = MainForm->IdTCPServer1->Threads->LockList();
    try
    {
        TIdPeerThread *Thread;
        for(int x = 0; x < List->Count; ++x)
        {
            Thread = (TIdPeerThread*) List->Items[x];
            Thread->Connection->WriteLn("/move " + DraggedSq + Image->Name + SentPromoPawn);
        }
    }
    __finally
    {
        MainForm->IdTCPServer1->Threads->UnlockList();
    }


  } else if (MainForm->IdTCPClient1->Connected()) {

     try
     {
      MainForm->IdTCPClient1->WriteLn("/move " + DraggedSq + Image->Name + SentPromoPawn);
     }
     __finally
     {
      //
     }

  }

  } ///////////////// end of active game

 }
}
//---------------------------------------------------------------------------

void __fastcall TMDIChild::xyStartDrag(TObject *Sender,
      TDragObject *&DragObject)
{
 DragObject = MyDCObject;
}
//---------------------------------------------------------------------------
__fastcall TMyDCObject::TMyDCObject(TControl* AControl) : TDragControlObject(Control)
{
 Control = AControl;
}
//-------------------------------------------------------------
TDragImageList* __fastcall TMyDCObject::GetDragImages()
{
  MDIChild = dynamic_cast<TMDIChild*>(Application->MainForm->ActiveMDIChild);

  FDragImages = new TDragImageList( NULL );
  FDragImages = MDIChild->ImageList2;

    if (MDIChild->Square[MDIChild->SqToNo(MDIChild->DraggedSq)].Piece.Name == "Pawn") {
     if (MDIChild->Square[MDIChild->SqToNo(MDIChild->DraggedSq)].Piece.Color == 1)
     FDragImages->SetDragImage(0, 30, 30);
     else
     FDragImages->SetDragImage(1, 30, 30);
    }
    if (MDIChild->Square[MDIChild->SqToNo(MDIChild->DraggedSq)].Piece.Name == "Knight") {
     if (MDIChild->Square[MDIChild->SqToNo(MDIChild->DraggedSq)].Piece.Color == 1)
     FDragImages->SetDragImage(2, 30, 30);
     else
     FDragImages->SetDragImage(3, 30, 30);
    }
    if (MDIChild->Square[MDIChild->SqToNo(MDIChild->DraggedSq)].Piece.Name == "Bishop") {
     if (MDIChild->Square[MDIChild->SqToNo(MDIChild->DraggedSq)].Piece.Color == 1)
     FDragImages->SetDragImage(4, 30, 30);
     else
     FDragImages->SetDragImage(5, 30, 30);
    }
    if (MDIChild->Square[MDIChild->SqToNo(MDIChild->DraggedSq)].Piece.Name == "Rook") {
     if (MDIChild->Square[MDIChild->SqToNo(MDIChild->DraggedSq)].Piece.Color == 1)
     FDragImages->SetDragImage(6, 30, 30);
     else
     FDragImages->SetDragImage(7, 30, 30);
    }
    if (MDIChild->Square[MDIChild->SqToNo(MDIChild->DraggedSq)].Piece.Name == "Queen") {
     if (MDIChild->Square[MDIChild->SqToNo(MDIChild->DraggedSq)].Piece.Color == 1)
     FDragImages->SetDragImage(8, 30, 30);
     else
     FDragImages->SetDragImage(9, 30, 30);
    }
    if (MDIChild->Square[MDIChild->SqToNo(MDIChild->DraggedSq)].Piece.Name == "King") {
     if (MDIChild->Square[MDIChild->SqToNo(MDIChild->DraggedSq)].Piece.Color == 1)
     FDragImages->SetDragImage(10, 30, 30);
     else
     FDragImages->SetDragImage(11, 30, 30);
    }

 return FDragImages;
}
//-------------------------------------------------------------

TStringList* __fastcall TMDIChild::LegalSquares(AnsiString Sq)
{
 TStringList* mystrings = new TStringList;
 int SquareNo = SqToNo(Sq);

 AnsiString SecondSq = "";

 if (SquareNo == -1) return mystrings;
 if (!CheckSq(Sq)) return mystrings;

 char CharOfSq = Sq[1];
 int RankOfSq = StrToInt(Sq.SubString(2,1));

 AnsiString AnsiOfSq = CharOfSq;
 AnsiString ForChar = "";

 char Plus1 = CharOfSq+1;
 char Plus2 = CharOfSq+2;
 char Less1 = CharOfSq-1;
 char Less2 = CharOfSq-2;

 AnsiString AnsiOfSqPlus1 = Plus1;
 AnsiString AnsiOfSqPlus2 = Plus2;
 AnsiString AnsiOfSqLess1 = Less1;
 AnsiString AnsiOfSqLess2 = Less2;

 if (Square[SquareNo].Piece.Name == "Rook") {
  for(int i=RankOfSq+1; i<=8; i++) { // top
   SecondSq = AnsiOfSq + IntToStr(i);
   if(CanMove(Sq, SecondSq, true)) mystrings->Add(SecondSq);
   if(CheckSq(SecondSq)) break;
  }
  for(int i=RankOfSq-1; i>=1; i--) { // bottom
   SecondSq = AnsiOfSq + IntToStr(i);
   if(CanMove(Sq, SecondSq, true)) mystrings->Add(SecondSq);
   if(CheckSq(SecondSq)) break;
  }
  for(char i=CharOfSq+1; i<='h'; i++) { // right
   ForChar = i;
   SecondSq = ForChar + IntToStr(RankOfSq);
   if(CanMove(Sq, SecondSq, true)) mystrings->Add(SecondSq);
   if(CheckSq(SecondSq)) break;
  }
  for(char i=CharOfSq-1; i>='a'; i--) { // left
   ForChar = i;
   SecondSq = ForChar + IntToStr(RankOfSq);
   if(CanMove(Sq, SecondSq, true)) mystrings->Add(SecondSq);
   if(CheckSq(SecondSq)) break;
  }
 }

 if (Square[SquareNo].Piece.Name == "Bishop") {
  char ControlFile = CharOfSq;
  AnsiString ControlSq = "";
  for(int i=RankOfSq+1; i<=8; i++) { // top right
   ControlFile++;
   ControlSq = ControlFile;
   SecondSq = ControlSq + IntToStr(i);
   if(CanMove(Sq, SecondSq, true)) mystrings->Add(SecondSq);
   if(CheckSq(SecondSq)) break;
  }
  ControlFile = CharOfSq;
  for(int i=RankOfSq+1; i<=8; i++) { // top left
   ControlFile--;
   ControlSq = ControlFile;
   SecondSq = ControlSq + IntToStr(i);
   if(CanMove(Sq, SecondSq, true)) mystrings->Add(SecondSq);
   if(CheckSq(SecondSq)) break;
  }
  ControlFile = CharOfSq;
  for(int i=RankOfSq-1; i>=1; i--) { // bottom right
   ControlFile++;
   ControlSq = ControlFile;
   SecondSq = ControlSq + IntToStr(i);
   if(CanMove(Sq, SecondSq, true)) mystrings->Add(SecondSq);
   if(CheckSq(SecondSq)) break;
  }
  ControlFile = CharOfSq;
  for(int i=RankOfSq-1; i>=1; i--) { // bottom left
   ControlFile--;
   ControlSq = ControlFile;
   SecondSq = ControlSq + IntToStr(i);
   if(CanMove(Sq, SecondSq, true)) mystrings->Add(SecondSq);
   if(CheckSq(SecondSq)) break;
  }
 }

 if (Square[SquareNo].Piece.Name == "Queen") {
  for(int i=RankOfSq+1; i<=8; i++) { // top
   SecondSq = AnsiOfSq + IntToStr(i);
   if(CanMove(Sq, SecondSq, true)) mystrings->Add(SecondSq);
   if(CheckSq(SecondSq)) break;
  }
  for(int i=RankOfSq-1; i>=1; i--) { // bottom
   SecondSq = AnsiOfSq + IntToStr(i);
   if(CanMove(Sq, SecondSq, true)) mystrings->Add(SecondSq);
   if(CheckSq(SecondSq)) break;
  }
  for(char i=CharOfSq+1; i<='h'; i++) { // right
   ForChar = i;
   SecondSq = ForChar + IntToStr(RankOfSq);
   if(CanMove(Sq, SecondSq, true)) mystrings->Add(SecondSq);
   if(CheckSq(SecondSq)) break;
  }
  for(char i=CharOfSq-1; i>='a'; i--) { // left
   ForChar = i;
   SecondSq = ForChar + IntToStr(RankOfSq);
   if(CanMove(Sq, SecondSq, true)) mystrings->Add(SecondSq);
   if(CheckSq(SecondSq)) break;
  }

  char ControlFile = CharOfSq;
  AnsiString ControlSq = "";
  for(int i=RankOfSq+1; i<=8; i++) { // top right
   ControlFile++;
   ControlSq = ControlFile;
   SecondSq = ControlSq + IntToStr(i);
   if(CanMove(Sq, SecondSq, true)) mystrings->Add(SecondSq);
   if(CheckSq(SecondSq)) break;
  }
  ControlFile = CharOfSq;
  for(int i=RankOfSq+1; i<=8; i++) { // top left
   ControlFile--;
   ControlSq = ControlFile;
   SecondSq = ControlSq + IntToStr(i);
   if(CanMove(Sq, SecondSq, true)) mystrings->Add(SecondSq);
   if(CheckSq(SecondSq)) break;
  }
  ControlFile = CharOfSq;
  for(int i=RankOfSq-1; i>=1; i--) { // bottom right
   ControlFile++;
   ControlSq = ControlFile;
   SecondSq = ControlSq + IntToStr(i);
   if(CanMove(Sq, SecondSq, true)) mystrings->Add(SecondSq);
   if(CheckSq(SecondSq)) break;
  }
  ControlFile = CharOfSq;
  for(int i=RankOfSq-1; i>=1; i--) { // bottom left
   ControlFile--;
   ControlSq = ControlFile;
   SecondSq = ControlSq + IntToStr(i);
   if(CanMove(Sq, SecondSq, true)) mystrings->Add(SecondSq);
   if(CheckSq(SecondSq)) break;
  }
 }

 if (Square[SquareNo].Piece.Name == "Knight") {
  if(CanMove(Sq, AnsiOfSqPlus1 + IntToStr(RankOfSq + 2), true)) mystrings->Add(AnsiOfSqPlus1 + IntToStr(RankOfSq + 2));
  if(CanMove(Sq, AnsiOfSqLess1 + IntToStr(RankOfSq + 2), true)) mystrings->Add(AnsiOfSqLess1 + IntToStr(RankOfSq + 2));
  if(CanMove(Sq, AnsiOfSqPlus1 + IntToStr(RankOfSq - 2), true)) mystrings->Add(AnsiOfSqPlus1 + IntToStr(RankOfSq - 2));
  if(CanMove(Sq, AnsiOfSqLess1 + IntToStr(RankOfSq - 2), true)) mystrings->Add(AnsiOfSqLess1 + IntToStr(RankOfSq - 2));
  if(CanMove(Sq, AnsiOfSqPlus2 + IntToStr(RankOfSq + 1), true)) mystrings->Add(AnsiOfSqPlus2 + IntToStr(RankOfSq + 1));
  if(CanMove(Sq, AnsiOfSqLess2 + IntToStr(RankOfSq + 1), true)) mystrings->Add(AnsiOfSqLess2 + IntToStr(RankOfSq + 1));
  if(CanMove(Sq, AnsiOfSqPlus2 + IntToStr(RankOfSq - 1), true)) mystrings->Add(AnsiOfSqPlus2 + IntToStr(RankOfSq - 1));
  if(CanMove(Sq, AnsiOfSqLess2 + IntToStr(RankOfSq - 1), true)) mystrings->Add(AnsiOfSqLess2 + IntToStr(RankOfSq - 1));
 }

 if (Square[SquareNo].Piece.Name == "King") {
  if(CanMove(Sq, AnsiOfSq + IntToStr(RankOfSq+1), true)) mystrings->Add(AnsiOfSq + IntToStr(RankOfSq+1));
  if(CanMove(Sq, AnsiOfSq + IntToStr(RankOfSq-1), true)) mystrings->Add(AnsiOfSq + IntToStr(RankOfSq-1));
  if(CanMove(Sq, AnsiOfSqPlus1 + IntToStr(RankOfSq+1), true)) mystrings->Add(AnsiOfSqPlus1 + IntToStr(RankOfSq+1));
  if(CanMove(Sq, AnsiOfSqPlus1 + IntToStr(RankOfSq), true)) mystrings->Add(AnsiOfSqPlus1 + IntToStr(RankOfSq));
  if(CanMove(Sq, AnsiOfSqPlus1 + IntToStr(RankOfSq-1), true)) mystrings->Add(AnsiOfSqPlus1 + IntToStr(RankOfSq-1));
  if(CanMove(Sq, AnsiOfSqLess1 + IntToStr(RankOfSq+1), true)) mystrings->Add(AnsiOfSqLess1 + IntToStr(RankOfSq+1));
  if(CanMove(Sq, AnsiOfSqLess1 + IntToStr(RankOfSq), true)) mystrings->Add(AnsiOfSqLess1 + IntToStr(RankOfSq));
  if(CanMove(Sq, AnsiOfSqLess1 + IntToStr(RankOfSq-1), true)) mystrings->Add(AnsiOfSqLess1 + IntToStr(RankOfSq-1));

  //if(CanMove(Sq, AnsiOfSqPlus2 + IntToStr(RankOfSq), true)) mystrings->Add(AnsiOfSqPlus2 + IntToStr(RankOfSq));
  //if(CanMove(Sq, AnsiOfSqLess2 + IntToStr(RankOfSq), true)) mystrings->Add(AnsiOfSqLess2 + IntToStr(RankOfSq));
 }

 if (Square[SquareNo].Piece.Name == "Pawn") {
  if(CanMove(Sq, AnsiOfSq + IntToStr(RankOfSq+1), true)) mystrings->Add(AnsiOfSq + IntToStr(RankOfSq+1));
  if(CanMove(Sq, AnsiOfSq + IntToStr(RankOfSq-1), true)) mystrings->Add(AnsiOfSq + IntToStr(RankOfSq-1));
  if(CanMove(Sq, AnsiOfSq + IntToStr(RankOfSq+2), true)) mystrings->Add(AnsiOfSq + IntToStr(RankOfSq+2));
  if(CanMove(Sq, AnsiOfSq + IntToStr(RankOfSq-2), true)) mystrings->Add(AnsiOfSq + IntToStr(RankOfSq-2));
  if(CanMove(Sq, AnsiOfSqPlus1 + IntToStr(RankOfSq+1), true)) mystrings->Add(AnsiOfSqPlus1 + IntToStr(RankOfSq+1));
  if(CanMove(Sq, AnsiOfSqLess1 + IntToStr(RankOfSq+1), true)) mystrings->Add(AnsiOfSqLess1 + IntToStr(RankOfSq+1));
  if(CanMove(Sq, AnsiOfSqPlus1 + IntToStr(RankOfSq-1), true)) mystrings->Add(AnsiOfSqPlus1 + IntToStr(RankOfSq-1));
  if(CanMove(Sq, AnsiOfSqLess1 + IntToStr(RankOfSq-1), true)) mystrings->Add(AnsiOfSqLess1 + IntToStr(RankOfSq-1));
 }

 return mystrings;
}

//---------------------------------------------------------------------------

void __fastcall TMDIChild::Timer1Timer(TObject *Sender)
{
 Timer1->Enabled = false;

 DWORD TotalBytes = 0;
 if(!PeekNamedPipe(hStdOutRead, NULL, 0, NULL, &TotalBytes, NULL))
 RaiseLastWin32Error();

 if(TotalBytes) {
  char Data[1024];
  DWORD BytesRead = 0;

  AnsiString Output = "";

  while(TotalBytes) {
   if(!ReadFile(hStdOutRead, Data, sizeof(Data)-1, &BytesRead, NULL))
   RaiseLastWin32Error();
   Output += AnsiString(Data, BytesRead);
   TotalBytes -= BytesRead;
  }

  if (Output != "") {
   int MovePos = Output.AnsiPos("move ");
   if (Output.SubString(MovePos + 9, 1).LowerCase() == "q") PromotedPawn = "Queen";
   if (Output.SubString(MovePos + 9, 1).LowerCase() == "r") PromotedPawn = "Rook";
   if (Output.SubString(MovePos + 9, 1).LowerCase() == "b") PromotedPawn = "Bishop";
   if (Output.SubString(MovePos + 9, 1).LowerCase() == "n") PromotedPawn = "Knight";

   if (Output.SubString(MovePos + 5, 5) == "O-O-O") {
    if (LastMovedColor == 0) { // White is playing..
     PlayMove("e1", "c1");
    } else {
     PlayMove("e8", "c8");
    }
   } else if (Output.SubString(MovePos + 5, 3) == "O-O") {
    if (LastMovedColor == 0) { // White is playing..
     PlayMove("e1", "g1");
    } else {
     PlayMove("e8", "g8");
    }
   } else PlayMove(Output.SubString(MovePos + 5, 2), Output.SubString(MovePos + 7, 2));
  }
 } else if(WaitForSingleObject(hProcess, 0) == WAIT_OBJECT_0) CloseHandles();

 Timer1->Enabled = true;
}
//---------------------------------------------------------------------------


void __fastcall TMDIChild::StringGrid1MouseDown(TObject *Sender,
      TMouseButton Button, TShiftState Shift, int X, int Y)
{
 if (StringGrid1->Col == 2) {
  if (StringGrid1->Row * 2 <= ScrollBar1->Max)
  Scrollit(StringGrid1->Row * 2);
 } else {
  if (StringGrid1->Row * 2 - 1 <= ScrollBar1->Max) 
  Scrollit(StringGrid1->Row * 2 - 1);
 }
}
//---------------------------------------------------------------------------


void __fastcall TMDIChild::StringGrid1DrawCell(TObject *Sender, int ACol,
      int ARow, TRect &Rect, TGridDrawState State)
{
 StringGrid1->Canvas->FillRect(Rect);
 AnsiString StringToAlign=StringGrid1->Cells[ACol][ARow];
 int StringStartH=(Rect.Left+Rect.Right)/2-StringGrid1->Canvas->TextWidth(StringToAlign)/2;
 int StringStartV=(Rect.Top+Rect.Bottom)/2-StringGrid1->Canvas->TextHeight(StringToAlign)/2;
 StringGrid1->Canvas->TextOut(StringStartH,StringStartV,StringToAlign);
}
//---------------------------------------------------------------------------



void __fastcall TMDIChild::ScrollBar1Scroll(TObject *Sender,
      TScrollCode ScrollCode, int &ScrollPos)
{
 Scrollit(ScrollPos);
}
//---------------------------------------------------------------------------

void __fastcall TMDIChild::AddEngine(AnsiString exeplace)
{
 if (hProcess) return;

 SECURITY_ATTRIBUTES sa = {0};
 sa.nLength = sizeof(SECURITY_ATTRIBUTES);
 sa.bInheritHandle = TRUE;
 sa.lpSecurityDescriptor = NULL;

 if(!CreatePipe(&hStdInRead, &hStdInWrite, &sa, 0)) {
  CloseHandles();
  RaiseLastWin32Error();
 }

 if(!CreatePipe(&hStdOutRead, &hStdOutWrite, &sa, 0)) {
  CloseHandles();
  RaiseLastWin32Error();
 }

 STARTUPINFO si = {0};

 si.cb = sizeof(STARTUPINFO);
 si.dwFlags = STARTF_USESHOWWINDOW | STARTF_USESTDHANDLES;
 si.wShowWindow = SW_HIDE;
 si.hStdInput = hStdInRead;
 si.hStdOutput = hStdOutWrite;
 si.hStdError = hStdOutWrite;

 if(!CreateProcess(exeplace.c_str(), NULL, NULL, NULL, TRUE, 0,
 NULL, NULL, &si, &pi)) {
  CloseHandles();
  RaiseLastWin32Error();
 }

 CloseHandle(pi.hThread);
 hProcess = pi.hProcess;

 Timer1->Enabled = true;

 WritePFile("xboard\nst 1\n");
 if(MessageBox(Handle, "Do you want to play white pieces?", "Color Selection", MB_YESNO | MB_ICONQUESTION) == IDNO) {
  InvertBoard1->Click();
  Compute1->Click();
 }
}
//---------------------------------------------------------------------------

void __fastcall TMDIChild::WritePFile (AnsiString Data)
{
 if(!hStdInWrite) return;

 char *ptr = Data.c_str();
 DWORD TotalBytes = Data.Length();
 DWORD BytesSent = 0;

 while(TotalBytes) {
  if(!WriteFile(hStdInWrite, ptr, TotalBytes, &BytesSent, NULL))
  RaiseLastWin32Error();

  ptr += BytesSent;
  TotalBytes -= BytesSent;
 }
}
//---------------------------------------------------------------------------

void __fastcall TMDIChild::TakeBack(AnsiString Move, bool Color)
{
 AnsiString FirstSq = Move.SubString(1, 2);
 AnsiString SecondSq = Move.SubString(3, 2);

 AnsiString ThirdPrm = Move.SubString(5, 1);
 AnsiString FourthPrm = Move.SubString(6, 1);

 TImage *imgF;
 TImage *imgS;

 for (int i = 0; i < ComponentCount; i++) {
  if (Components[i]->Name == FirstSq) {
   imgF = dynamic_cast<TImage *>(Components[i]);
  }
  if (Components[i]->Name == SecondSq) {
   imgS = dynamic_cast<TImage *>(Components[i]);
  }
 }

 imgF->Picture = imgS->Picture;
 imgS->Picture = NULL;

 if (ThirdPrm != "") {

  if (ThirdPrm == "Q" || ThirdPrm == "R" || ThirdPrm == "B" || ThirdPrm == "N") {
   if (Color == 1) imgF->Picture->Bitmap = Piece[0].Face;
   else imgF->Picture->Bitmap = Piece[1].Face;
  } else {
   if (FourthPrm != "")
   if (Color == 1) imgF->Picture->Bitmap = Piece[0].Face;
   else imgF->Picture->Bitmap = Piece[1].Face;

   if (ThirdPrm == "p")
   if (Color == 0) imgS->Picture->Bitmap = Piece[0].Face;
   else imgS->Picture->Bitmap = Piece[1].Face;

   if (ThirdPrm == "n")
   if (Color == 0) imgS->Picture->Bitmap = Piece[2].Face;
   else imgS->Picture->Bitmap = Piece[3].Face;

   if (ThirdPrm == "b")
   if (Color == 0) imgS->Picture->Bitmap = Piece[4].Face;
   else imgS->Picture->Bitmap = Piece[5].Face;

   if (ThirdPrm == "r")
   if (Color == 0) imgS->Picture->Bitmap = Piece[6].Face;
   else imgS->Picture->Bitmap = Piece[7].Face;

   if (ThirdPrm == "q")
   if (Color == 0) imgS->Picture->Bitmap = Piece[8].Face;
   else imgS->Picture->Bitmap = Piece[9].Face;

   if (ThirdPrm == "E") {
    TImage *imgE;
    if (Color == 1) {
     for (int i = 0; i < ComponentCount; i++) {
      if (Components[i]->Name == SecondSq.SubString(1, 1) + "5") {
       imgE = dynamic_cast<TImage *>(Components[i]);
       break;
      }
     }
     imgE->Picture->Bitmap = Piece[1].Face;
    } else {
     for (int i = 0; i < ComponentCount; i++) {
      if (Components[i]->Name == SecondSq.SubString(1, 1) + "4") {
       imgE = dynamic_cast<TImage *>(Components[i]);
       break;
      }
     }
     imgE->Picture->Bitmap = Piece[0].Face;
    }
   }

   if (ThirdPrm == "c") {
    if (Color == 1) {
     h1->Picture = f1->Picture;
     f1->Picture = NULL;
    } else {
     h8->Picture = f8->Picture;
     f8->Picture = NULL;
    }
   }
   if (ThirdPrm == "C") {
    if (Color == 1) {
     a1->Picture = d1->Picture;
     d1->Picture = NULL;
    } else {
     a8->Picture = d8->Picture;
     d8->Picture = NULL;
    }
   }

  }

 }

}

//---------------------------------------------------------------------------

void __fastcall TMDIChild::GoNext(AnsiString Move, bool Color)
{
 AnsiString FirstSq = Move.SubString(1, 2);
 AnsiString SecondSq = Move.SubString(3, 2);

 AnsiString ThirdPrm = Move.SubString(5, 1);
 AnsiString FourthPrm = Move.SubString(6, 1);

 TImage *imgF;
 TImage *imgS;

 for (int i = 0; i < ComponentCount; i++) {
  if (Components[i]->Name == FirstSq) {
   imgF = dynamic_cast<TImage *>(Components[i]);
  }
  if (Components[i]->Name == SecondSq) {
   imgS = dynamic_cast<TImage *>(Components[i]);
  }
 }

 imgS->Picture = imgF->Picture;
 imgF->Picture = NULL;

 if (ThirdPrm != "") {

  if (ThirdPrm == "Q" || ThirdPrm == "R" || ThirdPrm == "B" || ThirdPrm == "N") {
   if (Color == 1) {
    if (ThirdPrm == "Q") imgS->Picture->Bitmap = Piece[8].Face;
    if (ThirdPrm == "R") imgS->Picture->Bitmap = Piece[6].Face;
    if (ThirdPrm == "B") imgS->Picture->Bitmap = Piece[4].Face;
    if (ThirdPrm == "N") imgS->Picture->Bitmap = Piece[2].Face;
   } else {
    if (ThirdPrm == "Q") imgS->Picture->Bitmap = Piece[9].Face;
    if (ThirdPrm == "R") imgS->Picture->Bitmap = Piece[7].Face;
    if (ThirdPrm == "B") imgS->Picture->Bitmap = Piece[5].Face;
    if (ThirdPrm == "N") imgS->Picture->Bitmap = Piece[3].Face;
   }
  } else {
   if (FourthPrm != "")
   if (Color == 1) {
    if (FourthPrm == "Q") imgS->Picture->Bitmap = Piece[8].Face;
    if (FourthPrm == "R") imgS->Picture->Bitmap = Piece[6].Face;
    if (FourthPrm == "B") imgS->Picture->Bitmap = Piece[4].Face;
    if (FourthPrm == "N") imgS->Picture->Bitmap = Piece[2].Face;
   } else {
    if (FourthPrm == "Q") imgS->Picture->Bitmap = Piece[9].Face;
    if (FourthPrm == "R") imgS->Picture->Bitmap = Piece[7].Face;
    if (FourthPrm == "B") imgS->Picture->Bitmap = Piece[5].Face;
    if (FourthPrm == "N") imgS->Picture->Bitmap = Piece[3].Face;
   }

   if (ThirdPrm == "E") {
    TImage *imgE;
    if (Color == 1) {
     for (int i = 0; i < ComponentCount; i++) {
      if (Components[i]->Name == SecondSq.SubString(1, 1) + "5") {
       imgE = dynamic_cast<TImage *>(Components[i]);
       break;
      }
     }
     imgE->Picture = NULL;
    } else {
     for (int i = 0; i < ComponentCount; i++) {
      if (Components[i]->Name == SecondSq.SubString(1, 1) + "4") {
       imgE = dynamic_cast<TImage *>(Components[i]);
       break;
      }
     }
     imgE->Picture = NULL;
    }
   }

   if (ThirdPrm == "c") {
    if (Color == 1) {
     f1->Picture = h1->Picture;
     h1->Picture = NULL;
    } else {
     f8->Picture = h8->Picture;
     h8->Picture = NULL;
    }
   }
   if (ThirdPrm == "C") {
    if (Color == 1) {
     d1->Picture = a1->Picture;
     d1->Picture = NULL;
    } else {
     d8->Picture = a8->Picture;
     a8->Picture = NULL;
    }
   }

  }

 }

}

//---------------------------------------------------------------------------

void __fastcall TMDIChild::Scrollit(int ScrollPos)
{
 if (ScrollBar1->Position > ScrollPos) {
  for (int i = ScrollBar1->Position - 1; i >= ScrollPos; i--) { // Left
   int StrRow = (i - 1) / 2 + 1; // 0 and 1 -> 0    2 and 3 -> 1
   int StrCol = (i - 1) % 2 + 1;

   TakeBack(SmithStrings->Strings[i], StrCol - 1);

   try
   {
    StringGrid1->Row = StrRow; // THAT'S IT
    grect.Left = grect.Right = StrCol;
    grect.Top = grect.Bottom = StrRow;
    StringGrid1->Selection = grect;
   }
   catch(...)
   {
   }
  }
 } else if (ScrollBar1->Position < ScrollPos) { // Right
  for (int i = ScrollBar1->Position; i < ScrollPos; i++) {
   int StrRow = i / 2 + 1; // 0 and 1 -> 0    2 and 3 -> 1
   int StrCol = i % 2 + 1;

   GoNext(SmithStrings->Strings[i], !(StrCol - 1));

   try
   {
    StringGrid1->Row = StrRow; // THAT'S IT
    grect.Left = grect.Right = StrCol;
    grect.Top = grect.Bottom = StrRow;
    StringGrid1->Selection = grect;
   }
   catch(...)
   {
   }
  }
 }

 ScrollBar1->Position = ScrollPos;
}

//---------------------------------------------------------------------------

void __fastcall TMDIChild::Button3Click(TObject *Sender)
{
 if (hProcess) {
  Engine1->Enabled = true;
 } else {
  Engine1->Enabled = false;
 }

 TPoint tp = Point(0, 0);
 tp = Button3->ClientToScreen(tp);
 PopupAction->Popup(tp.x, tp.y + Button3->Height);
}
//---------------------------------------------------------------------------

void __fastcall TMDIChild::Edit1KeyPress(TObject *Sender, char &Key)
{
 if (Key == VK_RETURN) {
  Key = 0;

  if(MainForm->IdTCPServer1->Active == true) {

    TList *List = MainForm->IdTCPServer1->Threads->LockList();
    try
    {
        TIdPeerThread *Thread;
        for(int x = 0; x < List->Count; ++x)
        {
            Thread = (TIdPeerThread*) List->Items[x];
            Thread->Connection->WriteLn("/chat Server: " + Edit1->Text);
        }
        Memo1->Lines->Add("Server: " + Edit1->Text);
    }
    __finally
    {
        MainForm->IdTCPServer1->Threads->UnlockList();
    }


  } else if (MainForm->IdTCPClient1->Connected()) {

     try
     {
      MainForm->IdTCPClient1->WriteLn("/chat Client: " + Edit1->Text);
      Memo1->Lines->Add("Client: " + Edit1->Text);
     }
     __finally
     {
      //
     }

  }
  Edit1->Text = "";
 }
}
//---------------------------------------------------------------------------

void __fastcall TMDIChild::SelectBackGrounds(void)
{
 try
 {
  if (MainForm->SkyBlue1->Checked == true) {
   SqLight->Picture->LoadFromFile(ExtractFilePath(Application->ExeName) + "Images\\lightsq1.bmp");
   SqDark->Picture->LoadFromFile(ExtractFilePath(Application->ExeName) + "Images\\darksq1.bmp");
  } else {
   SqLight->Picture->LoadFromFile(ExtractFilePath(Application->ExeName) + "Images\\lightsq2.bmp");
   SqDark->Picture->LoadFromFile(ExtractFilePath(Application->ExeName) + "Images\\darksq2.bmp");
  }
 }
 catch(...)
 {
 }
}

//---------------------------------------------------------------------------

void __fastcall TMDIChild::FillImageList(void)
{
 ImageList1->Clear();

 Graphics::TBitmap *Bitmap = new Graphics::TBitmap(); // create the bitmap object
 try
 {
  if (MainForm->Modern11->Checked == true)
  Bitmap->LoadFromFile(ExtractFilePath(Application->ExeName) + "Images\\modern1.bmp"); // There is a path, because of "Open File" button.
  else if (MainForm->Modern21->Checked == true)
  Bitmap->LoadFromFile(ExtractFilePath(Application->ExeName) + "Images\\modern2.bmp"); // There is a path, because of "Open File" button.
  else if (MainForm->Classic1->Checked == true)
  Bitmap->LoadFromFile(ExtractFilePath(Application->ExeName) + "Images\\classic.bmp"); // There is a path, because of "Open File" button.
  else
  Bitmap->LoadFromFile(ExtractFilePath(Application->ExeName) + "Images\\sharp.bmp"); // There is a path, because of "Open File" button.
 }
 catch(...)
 {
 }
 TRect   MyRect, MyOther;
 MyOther = Rect(0,0,60,60); // Copied picture coordinates (constant)

 Graphics::TBitmap *BitmapRect = new Graphics::TBitmap();
 BitmapRect->Width = 60;
 BitmapRect->Height = 60;

 MyRect = Rect(0,0,60,60); // Picture which is going to be copied coordinates
 BitmapRect->Canvas->CopyRect(MyOther, Bitmap->Canvas, MyRect);
 ImageList1->Add(BitmapRect, NULL);

 MyRect = Rect(60,0,120,60);
 BitmapRect->Canvas->CopyRect(MyOther, Bitmap->Canvas, MyRect);
 ImageList1->Add(BitmapRect, NULL);

 MyRect = Rect(120,0,180,60);
 BitmapRect->Canvas->CopyRect(MyOther, Bitmap->Canvas, MyRect);
 ImageList1->Add(BitmapRect, NULL);

 MyRect = Rect(180,0,240,60);
 BitmapRect->Canvas->CopyRect(MyOther, Bitmap->Canvas, MyRect);
 ImageList1->Add(BitmapRect, NULL);

 MyRect = Rect(240,0,300,60);
 BitmapRect->Canvas->CopyRect(MyOther, Bitmap->Canvas, MyRect);
 ImageList1->Add(BitmapRect, NULL);

 MyRect = Rect(300,0,360,60);
 BitmapRect->Canvas->CopyRect(MyOther, Bitmap->Canvas, MyRect);
 ImageList1->Add(BitmapRect, NULL);

 MyRect = Rect(0,60,60,120);
 BitmapRect->Canvas->CopyRect(MyOther, Bitmap->Canvas, MyRect);
 ImageList1->Add(BitmapRect, NULL);

 MyRect = Rect(60,60,120,120);
 BitmapRect->Canvas->CopyRect(MyOther, Bitmap->Canvas, MyRect);
 ImageList1->Add(BitmapRect, NULL);

 MyRect = Rect(120,60,180,120);
 BitmapRect->Canvas->CopyRect(MyOther, Bitmap->Canvas, MyRect);
 ImageList1->Add(BitmapRect, NULL);

 MyRect = Rect(180,60,240,120);
 BitmapRect->Canvas->CopyRect(MyOther, Bitmap->Canvas, MyRect);
 ImageList1->Add(BitmapRect, NULL);

 MyRect = Rect(240,60,300,120);
 BitmapRect->Canvas->CopyRect(MyOther, Bitmap->Canvas, MyRect);
 ImageList1->Add(BitmapRect, NULL);

 MyRect = Rect(300,60,360,120);
 BitmapRect->Canvas->CopyRect(MyOther, Bitmap->Canvas, MyRect);
 ImageList1->Add(BitmapRect, NULL);

 delete BitmapRect;
 delete Bitmap;
}

//---------------------------------------------------------------------------

void __fastcall TMDIChild::RefreshBoards(void)
{
 a8bg->Picture = SqLight->Picture;
 b8bg->Picture = SqDark->Picture;
 c8bg->Picture = SqLight->Picture;
 d8bg->Picture = SqDark->Picture;
 e8bg->Picture = SqLight->Picture;
 f8bg->Picture = SqDark->Picture;
 g8bg->Picture = SqLight->Picture;
 h8bg->Picture = SqDark->Picture;

 a7bg->Picture = SqDark->Picture;
 b7bg->Picture = SqLight->Picture;
 c7bg->Picture = SqDark->Picture;
 d7bg->Picture = SqLight->Picture;
 e7bg->Picture = SqDark->Picture;
 f7bg->Picture = SqLight->Picture;
 g7bg->Picture = SqDark->Picture;
 h7bg->Picture = SqLight->Picture;

 a6bg->Picture = SqLight->Picture;
 b6bg->Picture = SqDark->Picture;
 c6bg->Picture = SqLight->Picture;
 d6bg->Picture = SqDark->Picture;
 e6bg->Picture = SqLight->Picture;
 f6bg->Picture = SqDark->Picture;
 g6bg->Picture = SqLight->Picture;
 h6bg->Picture = SqDark->Picture;

 a5bg->Picture = SqDark->Picture;
 b5bg->Picture = SqLight->Picture;
 c5bg->Picture = SqDark->Picture;
 d5bg->Picture = SqLight->Picture;
 e5bg->Picture = SqDark->Picture;
 f5bg->Picture = SqLight->Picture;
 g5bg->Picture = SqDark->Picture;
 h5bg->Picture = SqLight->Picture;

 a4bg->Picture = SqLight->Picture;
 b4bg->Picture = SqDark->Picture;
 c4bg->Picture = SqLight->Picture;
 d4bg->Picture = SqDark->Picture;
 e4bg->Picture = SqLight->Picture;
 f4bg->Picture = SqDark->Picture;
 g4bg->Picture = SqLight->Picture;
 h4bg->Picture = SqDark->Picture;

 a3bg->Picture = SqDark->Picture;
 b3bg->Picture = SqLight->Picture;
 c3bg->Picture = SqDark->Picture;
 d3bg->Picture = SqLight->Picture;
 e3bg->Picture = SqDark->Picture;
 f3bg->Picture = SqLight->Picture;
 g3bg->Picture = SqDark->Picture;
 h3bg->Picture = SqLight->Picture;

 a2bg->Picture = SqLight->Picture;
 b2bg->Picture = SqDark->Picture;
 c2bg->Picture = SqLight->Picture;
 d2bg->Picture = SqDark->Picture;
 e2bg->Picture = SqLight->Picture;
 f2bg->Picture = SqDark->Picture;
 g2bg->Picture = SqLight->Picture;
 h2bg->Picture = SqDark->Picture;

 a1bg->Picture = SqDark->Picture;
 b1bg->Picture = SqLight->Picture;
 c1bg->Picture = SqDark->Picture;
 d1bg->Picture = SqLight->Picture;
 e1bg->Picture = SqDark->Picture;
 f1bg->Picture = SqLight->Picture;
 g1bg->Picture = SqDark->Picture;
 h1bg->Picture = SqLight->Picture;
}

//---------------------------------------------------------------------------

void __fastcall TMDIChild::RefreshPieces(void)
{
 if (ScrollBar1->Position != ScrollBar1->Max)
 Scrollit(ScrollBar1->Max);

 ImageList1->GetBitmap(0, Piece[0].Face);
 ImageList1->GetBitmap(1, Piece[1].Face);
 ImageList1->GetBitmap(2, Piece[2].Face);
 ImageList1->GetBitmap(3, Piece[3].Face);
 ImageList1->GetBitmap(4, Piece[4].Face);
 ImageList1->GetBitmap(5, Piece[5].Face);
 ImageList1->GetBitmap(6, Piece[6].Face);
 ImageList1->GetBitmap(7, Piece[7].Face);
 ImageList1->GetBitmap(8, Piece[8].Face);
 ImageList1->GetBitmap(9, Piece[9].Face);
 ImageList1->GetBitmap(10, Piece[10].Face);
 ImageList1->GetBitmap(11, Piece[11].Face);

 a8->Picture->Bitmap = Square[SqToNo("a8")].Piece.Face;
 a7->Picture->Bitmap = Square[SqToNo("a7")].Piece.Face;
 a6->Picture->Bitmap = Square[SqToNo("a6")].Piece.Face;
 a5->Picture->Bitmap = Square[SqToNo("a5")].Piece.Face;
 a4->Picture->Bitmap = Square[SqToNo("a4")].Piece.Face;
 a3->Picture->Bitmap = Square[SqToNo("a3")].Piece.Face;
 a2->Picture->Bitmap = Square[SqToNo("a2")].Piece.Face;
 a1->Picture->Bitmap = Square[SqToNo("a1")].Piece.Face;

 b8->Picture->Bitmap = Square[SqToNo("b8")].Piece.Face;
 b7->Picture->Bitmap = Square[SqToNo("b7")].Piece.Face;
 b6->Picture->Bitmap = Square[SqToNo("b6")].Piece.Face;
 b5->Picture->Bitmap = Square[SqToNo("b5")].Piece.Face;
 b4->Picture->Bitmap = Square[SqToNo("b4")].Piece.Face;
 b3->Picture->Bitmap = Square[SqToNo("b3")].Piece.Face;
 b2->Picture->Bitmap = Square[SqToNo("b2")].Piece.Face;
 b1->Picture->Bitmap = Square[SqToNo("b1")].Piece.Face;

 c8->Picture->Bitmap = Square[SqToNo("c8")].Piece.Face;
 c7->Picture->Bitmap = Square[SqToNo("c7")].Piece.Face;
 c6->Picture->Bitmap = Square[SqToNo("c6")].Piece.Face;
 c5->Picture->Bitmap = Square[SqToNo("c5")].Piece.Face;
 c4->Picture->Bitmap = Square[SqToNo("c4")].Piece.Face;
 c3->Picture->Bitmap = Square[SqToNo("c3")].Piece.Face;
 c2->Picture->Bitmap = Square[SqToNo("c2")].Piece.Face;
 c1->Picture->Bitmap = Square[SqToNo("c1")].Piece.Face;

 d8->Picture->Bitmap = Square[SqToNo("d8")].Piece.Face;
 d7->Picture->Bitmap = Square[SqToNo("d7")].Piece.Face;
 d6->Picture->Bitmap = Square[SqToNo("d6")].Piece.Face;
 d5->Picture->Bitmap = Square[SqToNo("d5")].Piece.Face;
 d4->Picture->Bitmap = Square[SqToNo("d4")].Piece.Face;
 d3->Picture->Bitmap = Square[SqToNo("d3")].Piece.Face;
 d2->Picture->Bitmap = Square[SqToNo("d2")].Piece.Face;
 d1->Picture->Bitmap = Square[SqToNo("d1")].Piece.Face;

 e8->Picture->Bitmap = Square[SqToNo("e8")].Piece.Face;
 e7->Picture->Bitmap = Square[SqToNo("e7")].Piece.Face;
 e6->Picture->Bitmap = Square[SqToNo("e6")].Piece.Face;
 e5->Picture->Bitmap = Square[SqToNo("e5")].Piece.Face;
 e4->Picture->Bitmap = Square[SqToNo("e4")].Piece.Face;
 e3->Picture->Bitmap = Square[SqToNo("e3")].Piece.Face;
 e2->Picture->Bitmap = Square[SqToNo("e2")].Piece.Face;
 e1->Picture->Bitmap = Square[SqToNo("e1")].Piece.Face;

 f8->Picture->Bitmap = Square[SqToNo("f8")].Piece.Face;
 f7->Picture->Bitmap = Square[SqToNo("f7")].Piece.Face;
 f6->Picture->Bitmap = Square[SqToNo("f6")].Piece.Face;
 f5->Picture->Bitmap = Square[SqToNo("f5")].Piece.Face;
 f4->Picture->Bitmap = Square[SqToNo("f4")].Piece.Face;
 f3->Picture->Bitmap = Square[SqToNo("f3")].Piece.Face;
 f2->Picture->Bitmap = Square[SqToNo("f2")].Piece.Face;
 f1->Picture->Bitmap = Square[SqToNo("f1")].Piece.Face;

 g8->Picture->Bitmap = Square[SqToNo("g8")].Piece.Face;
 g7->Picture->Bitmap = Square[SqToNo("g7")].Piece.Face;
 g6->Picture->Bitmap = Square[SqToNo("g6")].Piece.Face;
 g5->Picture->Bitmap = Square[SqToNo("g5")].Piece.Face;
 g4->Picture->Bitmap = Square[SqToNo("g4")].Piece.Face;
 g3->Picture->Bitmap = Square[SqToNo("g3")].Piece.Face;
 g2->Picture->Bitmap = Square[SqToNo("g2")].Piece.Face;
 g1->Picture->Bitmap = Square[SqToNo("g1")].Piece.Face;

 h8->Picture->Bitmap = Square[SqToNo("h8")].Piece.Face;
 h7->Picture->Bitmap = Square[SqToNo("h7")].Piece.Face;
 h6->Picture->Bitmap = Square[SqToNo("h6")].Piece.Face;
 h5->Picture->Bitmap = Square[SqToNo("h5")].Piece.Face;
 h4->Picture->Bitmap = Square[SqToNo("h4")].Piece.Face;
 h3->Picture->Bitmap = Square[SqToNo("h3")].Piece.Face;
 h2->Picture->Bitmap = Square[SqToNo("h2")].Piece.Face;
 h1->Picture->Bitmap = Square[SqToNo("h1")].Piece.Face;

 WhiteP->Picture->Bitmap = Piece[0].Face;
 BlackP->Picture->Bitmap = Piece[1].Face;
 WhiteN->Picture->Bitmap = Piece[2].Face;
 BlackN->Picture->Bitmap = Piece[3].Face;
 WhiteB->Picture->Bitmap = Piece[4].Face;
 BlackB->Picture->Bitmap = Piece[5].Face;
 WhiteR->Picture->Bitmap = Piece[6].Face;
 BlackR->Picture->Bitmap = Piece[7].Face;
 WhiteQ->Picture->Bitmap = Piece[8].Face;
 BlackQ->Picture->Bitmap = Piece[9].Face;

 ImageList2->Clear();

 ImageList2->AddMasked(Piece[0].Face, Piece[0].Face->TransparentColor);
 ImageList2->AddMasked(Piece[1].Face, Piece[1].Face->TransparentColor);
 ImageList2->AddMasked(Piece[2].Face, Piece[2].Face->TransparentColor);
 ImageList2->AddMasked(Piece[3].Face, Piece[3].Face->TransparentColor);
 ImageList2->AddMasked(Piece[4].Face, Piece[4].Face->TransparentColor);
 ImageList2->AddMasked(Piece[5].Face, Piece[5].Face->TransparentColor);
 ImageList2->AddMasked(Piece[6].Face, Piece[6].Face->TransparentColor);
 ImageList2->AddMasked(Piece[7].Face, Piece[7].Face->TransparentColor);
 ImageList2->AddMasked(Piece[8].Face, Piece[8].Face->TransparentColor);
 ImageList2->AddMasked(Piece[9].Face, Piece[9].Face->TransparentColor);
 ImageList2->AddMasked(Piece[10].Face, Piece[10].Face->TransparentColor);
 ImageList2->AddMasked(Piece[11].Face, Piece[11].Face->TransparentColor);
}

//---------------------------------------------------------------------------
void __fastcall TMDIChild::Compute1Click(TObject *Sender)
{
 if (hProcess) {
  ComputerColor = !ComputerColor;
  WritePFile("go\n");
 }
}
//---------------------------------------------------------------------------

void __fastcall TMDIChild::Fast1Click(TObject *Sender)
{
 if (hProcess) {
  WritePFile("st 1\n");
  Fast1->Checked = true;
  Medium1->Checked = false;
  Slow1->Checked = false;
 }
}
//---------------------------------------------------------------------------

void __fastcall TMDIChild::InvertBoard1Click(TObject *Sender)
{
 int Coor;

 // First

 Coor = a8->Left;
 a8->Left = h1->Left;
 h1->Left = Coor;

 Coor = a8->Top;
 a8->Top = h1->Top;
 h1->Top = Coor;

 Coor = b8->Left;
 b8->Left = g1->Left;
 g1->Left = Coor;

 Coor = b8->Top;
 b8->Top = g1->Top;
 g1->Top = Coor;

 Coor = c8->Left;
 c8->Left = f1->Left;
 f1->Left = Coor;

 Coor = c8->Top;
 c8->Top = f1->Top;
 f1->Top = Coor;

 Coor = d8->Left;
 d8->Left = e1->Left;
 e1->Left = Coor;

 Coor = d8->Top;
 d8->Top = e1->Top;
 e1->Top = Coor;

 Coor = e8->Left;
 e8->Left = d1->Left;
 d1->Left = Coor;

 Coor = e8->Top;
 e8->Top = d1->Top;
 d1->Top = Coor;

 Coor = f8->Left;
 f8->Left = c1->Left;
 c1->Left = Coor;

 Coor = f8->Top;
 f8->Top = c1->Top;
 c1->Top = Coor;

 Coor = g8->Left;
 g8->Left = b1->Left;
 b1->Left = Coor;

 Coor = g8->Top;
 g8->Top = b1->Top;
 b1->Top = Coor;

 Coor = h8->Left;
 h8->Left = a1->Left;
 a1->Left = Coor;

 Coor = h8->Top;
 h8->Top = a1->Top;
 a1->Top = Coor;

 // Second

 Coor = a7->Left;
 a7->Left = h2->Left;
 h2->Left = Coor;

 Coor = a7->Top;
 a7->Top = h2->Top;
 h2->Top = Coor;

 Coor = b7->Left;
 b7->Left = g2->Left;
 g2->Left = Coor;

 Coor = b7->Top;
 b7->Top = g2->Top;
 g2->Top = Coor;

 Coor = c7->Left;
 c7->Left = f2->Left;
 f2->Left = Coor;

 Coor = c7->Top;
 c7->Top = f2->Top;
 f2->Top = Coor;

 Coor = d7->Left;
 d7->Left = e2->Left;
 e2->Left = Coor;

 Coor = d7->Top;
 d7->Top = e2->Top;
 e2->Top = Coor;

 Coor = e7->Left;
 e7->Left = d2->Left;
 d2->Left = Coor;

 Coor = e7->Top;
 e7->Top = d2->Top;
 d2->Top = Coor;

 Coor = f7->Left;
 f7->Left = c2->Left;
 c2->Left = Coor;

 Coor = f7->Top;
 f7->Top = c2->Top;
 c2->Top = Coor;

 Coor = g7->Left;
 g7->Left = b2->Left;
 b2->Left = Coor;

 Coor = g7->Top;
 g7->Top = b2->Top;
 b2->Top = Coor;

 Coor = h7->Left;
 h7->Left = a2->Left;
 a2->Left = Coor;

 Coor = h7->Top;
 h7->Top = a2->Top;
 a2->Top = Coor;

 // Third

 Coor = a6->Left;
 a6->Left = h3->Left;
 h3->Left = Coor;

 Coor = a6->Top;
 a6->Top = h3->Top;
 h3->Top = Coor;

 Coor = b6->Left;
 b6->Left = g3->Left;
 g3->Left = Coor;

 Coor = b6->Top;
 b6->Top = g3->Top;
 g3->Top = Coor;

 Coor = c6->Left;
 c6->Left = f3->Left;
 f3->Left = Coor;

 Coor = c6->Top;
 c6->Top = f3->Top;
 f3->Top = Coor;

 Coor = d6->Left;
 d6->Left = e3->Left;
 e3->Left = Coor;

 Coor = d6->Top;
 d6->Top = e3->Top;
 e3->Top = Coor;

 Coor = e6->Left;
 e6->Left = d3->Left;
 d3->Left = Coor;

 Coor = e6->Top;
 e6->Top = d3->Top;
 d3->Top = Coor;

 Coor = f6->Left;
 f6->Left = c3->Left;
 c3->Left = Coor;

 Coor = f6->Top;
 f6->Top = c3->Top;
 c3->Top = Coor;

 Coor = g6->Left;
 g6->Left = b3->Left;
 b3->Left = Coor;

 Coor = g6->Top;
 g6->Top = b3->Top;
 b3->Top = Coor;

 Coor = h6->Left;
 h6->Left = a3->Left;
 a3->Left = Coor;

 Coor = h6->Top;
 h6->Top = a3->Top;
 a3->Top = Coor;

 // Fourth

 Coor = a5->Left;
 a5->Left = h4->Left;
 h4->Left = Coor;

 Coor = a5->Top;
 a5->Top = h4->Top;
 h4->Top = Coor;

 Coor = b5->Left;
 b5->Left = g4->Left;
 g4->Left = Coor;

 Coor = b5->Top;
 b5->Top = g4->Top;
 g4->Top = Coor;

 Coor = c5->Left;
 c5->Left = f4->Left;
 f4->Left = Coor;

 Coor = c5->Top;
 c5->Top = f4->Top;
 f4->Top = Coor;

 Coor = d5->Left;
 d5->Left = e4->Left;
 e4->Left = Coor;

 Coor = d5->Top;
 d5->Top = e4->Top;
 e4->Top = Coor;

 Coor = e5->Left;
 e5->Left = d4->Left;
 d4->Left = Coor;

 Coor = e5->Top;
 e5->Top = d4->Top;
 d4->Top = Coor;

 Coor = f5->Left;
 f5->Left = c4->Left;
 c4->Left = Coor;

 Coor = f5->Top;
 f5->Top = c4->Top;
 c4->Top = Coor;

 Coor = g5->Left;
 g5->Left = b4->Left;
 b4->Left = Coor;

 Coor = g5->Top;
 g5->Top = b4->Top;
 b4->Top = Coor;

 Coor = h5->Left;
 h5->Left = a4->Left;
 a4->Left = Coor;

 Coor = h5->Top;
 h5->Top = a4->Top;
 a4->Top = Coor;

 // Hide BorderImages
 TheBorderImage1->Left = -60;
 TheBorderImage1->Top = -60;
 TheBorderImage2->Left = -60;
 TheBorderImage2->Top = -60;

 // Board Coordinates

 // Letters
 Coor = Label1->Left;
 Label1->Left = Label8->Left;
 Label8->Left = Coor;

 Coor = Label2->Left;
 Label2->Left = Label7->Left;
 Label7->Left = Coor;

 Coor = Label3->Left;
 Label3->Left = Label6->Left;
 Label6->Left = Coor;

 Coor = Label4->Left;
 Label4->Left = Label5->Left;
 Label5->Left = Coor;

 // Numbers
 Coor = Label9->Top;
 Label9->Top = Label16->Top;
 Label16->Top = Coor;

 Coor = Label10->Top;
 Label10->Top = Label15->Top;
 Label15->Top = Coor;

 Coor = Label11->Top;
 Label11->Top = Label14->Top;
 Label14->Top = Coor;

 Coor = Label12->Top;
 Label12->Top = Label13->Top;
 Label13->Top = Coor;

 // Names
 Coor = White->Top;
 White->Top = Black->Top;
 Black->Top = Coor;

 // Captured Pieces
 Coor = Panel1->Top;
 Panel1->Top = Panel10->Top;
 Panel10->Top = Coor;

 Coor = Panel2->Top;
 Panel2->Top = Panel9->Top;
 Panel9->Top = Coor;

 Coor = Panel3->Top;
 Panel3->Top = Panel8->Top;
 Panel8->Top = Coor;

 Coor = Panel4->Top;
 Panel4->Top = Panel7->Top;
 Panel7->Top = Coor;

 Coor = Panel5->Top;
 Panel5->Top = Panel6->Top;
 Panel6->Top = Coor;
}
//---------------------------------------------------------------------------

void __fastcall TMDIChild::FlipBoard1Click(TObject *Sender)
{
 InvertBoard1->Click();        
}
//---------------------------------------------------------------------------

void __fastcall TMDIChild::Medium1Click(TObject *Sender)
{
 if (hProcess) {
  WritePFile("st 8\n");
  Fast1->Checked = false;
  Medium1->Checked = true;
  Slow1->Checked = false;
 }
}
//---------------------------------------------------------------------------

void __fastcall TMDIChild::Slow1Click(TObject *Sender)
{
 if (hProcess) {
  WritePFile("st 15\n");
  Fast1->Checked = false;
  Medium1->Checked = false;
  Slow1->Checked = true;
 }
}
//---------------------------------------------------------------------------



