//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "Promotion.h"
#include "childwin.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TPromotionForm *PromotionForm;
//---------------------------------------------------------------------------
__fastcall TPromotionForm::TPromotionForm(TComponent* Owner)
        : TForm(Owner)
{
}
//---------------------------------------------------------------------------

void __fastcall TPromotionForm::Button1Click(TObject *Sender)
{

 MDIChild = dynamic_cast<TMDIChild*>(Application->MainForm->ActiveMDIChild);
 MDIChild->PromotedPawn = "Queen";
 Close();

}
//---------------------------------------------------------------------------

void __fastcall TPromotionForm::Button2Click(TObject *Sender)
{

 MDIChild = dynamic_cast<TMDIChild*>(Application->MainForm->ActiveMDIChild);
 MDIChild->PromotedPawn = "Rook";
 Close();

}
//---------------------------------------------------------------------------

void __fastcall TPromotionForm::Button3Click(TObject *Sender)
{

 MDIChild = dynamic_cast<TMDIChild*>(Application->MainForm->ActiveMDIChild);
 MDIChild->PromotedPawn = "Bishop";
 Close();

}
//---------------------------------------------------------------------------

void __fastcall TPromotionForm::Button4Click(TObject *Sender)
{

 MDIChild = dynamic_cast<TMDIChild*>(Application->MainForm->ActiveMDIChild);
 MDIChild->PromotedPawn = "Knight";
 Close();

}
//---------------------------------------------------------------------------

void __fastcall TPromotionForm::FormShow(TObject *Sender)
{
 MDIChild = dynamic_cast<TMDIChild*>(Application->MainForm->ActiveMDIChild);
 PromotionForm->Left = MDIChild->Left + 100;
 PromotionForm->Top = MDIChild->Top + 100;        
}
//---------------------------------------------------------------------------

