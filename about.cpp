//---------------------------------------------------------------------
#include <vcl.h>
#pragma hdrstop

#include "About.h"
//--------------------------------------------------------------------- 
#pragma resource "*.dfm"
TAboutBox *AboutBox;
//--------------------------------------------------------------------- 
__fastcall TAboutBox::TAboutBox(TComponent *Owner)
	: TForm(Owner)
{
}
//---------------------------------------------------------------------

void __fastcall TAboutBox::Label1Click(TObject *Sender)
{
 ShellExecute(0, "open", "http://www.sezginserin.com", NULL, NULL, SW_SHOWNORMAL);
}
//---------------------------------------------------------------------------

