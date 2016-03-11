//---------------------------------------------------------------------------
#include <vcl.h>
#pragma hdrstop

#include "Unit2.h"
#include "main.h"
#include "ChildWin.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TForm2 *Form2;
//---------------------------------------------------------------------------
__fastcall TForm2::TForm2(TComponent* Owner)
        : TForm(Owner)
{
}
//---------------------------------------------------------------------------

void __fastcall TForm2::FormCreate(TObject *Sender)
{
 this->Width = 280;
 this->Height = 524;
 this->Top = 118;
 this->Left = 744;

 if(ParamCount() > 0 && MainForm->FirstFileOpened == false) { // if opened with external file like filename.cpf
  AnsiString Name = ParamStr(1);
	if (FileExists (Name)) {
         MDIChild->Caption = Name;
         MDIChild->NoDrag = true;
         MDIChild->SmithStrings->LoadFromFile(Name);
         for (int i=0; i < MDIChild->SmithStrings->Count; i++) {
          MDIChild->ScrollBar1->Max = i+1;
          if (i % 2 == 0) {
           MDIChild->StringGrid1->Cells[0][i/2 + 1] = i/2 + 1;
           MDIChild->StringGrid1->Cells[1][i/2 + 1] = MDIChild->SmithStrings->Strings[i];
          } else {
           MDIChild->StringGrid1->Cells[2][i/2 + 1] = MDIChild->SmithStrings->Strings[i];
           MDIChild->StringGrid1->RowCount = MDIChild->StringGrid1->RowCount + 1;
          }
         }
        }
  MainForm->FirstFileOpened = true;
 }
}
//---------------------------------------------------------------------------

void __fastcall TForm2::FormClose(TObject *Sender, TCloseAction &Action)
{
   MainForm->MainConsole1->Checked = false;
   Action = caFree;
}
//---------------------------------------------------------------------------
