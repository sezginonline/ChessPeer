//---------------------------------------------------------------------------
#include <vcl.h>
#pragma hdrstop

#include "Unit1.h"
#include "main.h"
#include "Unit2.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TForm1 *Form1;
//---------------------------------------------------------------------------
__fastcall TForm1::TForm1(TComponent* Owner)
        : TForm(Owner)
{
}
//---------------------------------------------------------------------------

void __fastcall TForm1::FormClose(TObject *Sender, TCloseAction &Action)
{
   MainForm->OpponentSeekingGames1->Checked = false;
   Action = caFree;        
}
//---------------------------------------------------------------------------

void __fastcall TForm1::FormCreate(TObject *Sender)
{
 this->Width = 280;
 this->Height = 116;
 this->Top = 1;
 this->Left = 744;
}
//---------------------------------------------------------------------------


void __fastcall TForm1::Button2Click(TObject *Sender)
{
 MainForm->IdTCPClient1->Host = Edit1->Text;
 try
 {
  MainForm->IdTCPClient1->Connect();
  MainForm->CreateMDIChild("Active Game");
 }
 catch(...)
 {
  for (int i=0; i<MainForm->MDIChildCount; i++) {
   TForm2 *Form2 = dynamic_cast<TForm2*>(MainForm->MDIChildren[i]);
   if (Form2) {
    Form2->Memo1->Lines->Add("\r\nConnection could not be established!");
   }
  }
 }
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Button1Click(TObject *Sender)
{
 MainForm->IdTCPServer1->Active = true;
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Button3Click(TObject *Sender)
{
 MainForm->IdTCPServer1->Active = false;
 MainForm->IdTCPClient1->Disconnect();
}
//---------------------------------------------------------------------------

