//----------------------------------------------------------------------------
#ifndef ChildWinH
#define ChildWinH
//----------------------------------------------------------------------------
#include "Promotion.h" // My addition
#include <vcl\Controls.hpp>
#include <vcl\Forms.hpp>
#include <vcl\Graphics.hpp>
#include <vcl\Classes.hpp>
#include <vcl\Windows.hpp>
#include <vcl\System.hpp>
#include <StdCtrls.hpp>
#include <ExtCtrls.hpp>
#include <ImgList.hpp>
#include <Grids.hpp>
#include "SHDocVw_OCX.h"
#include <OleCtrls.hpp>
#include <Menus.hpp>
//----------------------------------------------------------------------------
class TMyDCObject : public TDragControlObject
{
    protected:
        virtual TDragImageList* __fastcall GetDragImages();
    private:
        TDragImageList* FDragImages;
    public:
        __fastcall TMyDCObject(TControl* AControl);
};
//----------------------------------------------------------------------------
class TMDIChild : public TForm
{
__published:
        TPanel *LeftPanel;
        TPanel *RightPanel;
        TImage *a8;
        TImage *b8;
        TImage *c8;
        TImage *d8;
        TImage *e8;
        TImage *f8;
        TImage *g8;
        TImage *h8;
        TImage *a7;
        TImage *b7;
        TImage *c7;
        TImage *d7;
        TImage *e7;
        TImage *f7;
        TImage *h7;
        TImage *g7;
        TImage *a5;
        TImage *h6;
        TImage *g6;
        TImage *f6;
        TImage *e6;
        TImage *d6;
        TImage *c6;
        TImage *b6;
        TImage *g5;
        TImage *h5;
        TImage *f5;
        TImage *e5;
        TImage *d5;
        TImage *c5;
        TImage *b5;
        TImage *a6;
        TImage *a3;
        TImage *h4;
        TImage *g4;
        TImage *f4;
        TImage *e4;
        TImage *d4;
        TImage *a2;
        TImage *b1;
        TImage *c1;
        TImage *c4;
        TImage *d1;
        TImage *e1;
        TImage *f1;
        TImage *h1;
        TImage *g1;
        TImage *b2;
        TImage *c2;
        TImage *d2;
        TImage *e2;
        TImage *f2;
        TImage *b4;
        TImage *g2;
        TImage *h2;
        TImage *a1;
        TImage *g3;
        TImage *h3;
        TImage *f3;
        TImage *e3;
        TImage *d3;
        TImage *c3;
        TImage *b3;
        TImage *a4;
        TLabel *Label1;
        TLabel *Label2;
        TLabel *Label3;
        TLabel *Label4;
        TLabel *Label5;
        TLabel *Label6;
        TLabel *Label7;
        TLabel *Label8;
        TLabel *Label9;
        TLabel *Label10;
        TLabel *Label11;
        TLabel *Label12;
        TLabel *Label13;
        TLabel *Label14;
        TLabel *Label15;
        TLabel *Label16;
        TEdit *Edit1;
        TMemo *Memo1;
        TImageList *ImageList1;
        TLabel *White;
        TLabel *Black;
        TImageList *ImageList2;
        TTimer *Timer1;
        TPanel *BottomPanel;
        TStringGrid *StringGrid1;
        TCppWebBrowser *CppWebBrowser1;
        TScrollBar *ScrollBar1;
        TImage *TheBorderImage1;
        TImage *TheBorderImage2;
        TImage *SqLight;
        TImage *SqDark;
        TPopupMenu *PopupAction;
        TMenuItem *Compute1;
        TButton *Button3;
        TMenuItem *Fast1;
        TPopupMenu *PopupBoard;
        TMenuItem *InvertBoard1;
        TPanel *Panel1;
        TImage *BlackP;
        TLabel *bp;
        TPanel *Panel2;
        TImage *BlackN;
        TLabel *bn;
        TPanel *Panel3;
        TImage *BlackB;
        TLabel *bb;
        TPanel *Panel4;
        TImage *BlackR;
        TLabel *br;
        TPanel *Panel5;
        TImage *BlackQ;
        TLabel *bq;
        TPanel *Panel6;
        TImage *WhiteQ;
        TLabel *wq;
        TPanel *Panel7;
        TImage *WhiteR;
        TLabel *wr;
        TPanel *Panel8;
        TImage *WhiteB;
        TLabel *wb;
        TPanel *Panel9;
        TImage *WhiteN;
        TLabel *wn;
        TPanel *Panel10;
        TImage *WhiteP;
        TLabel *wp;
        TMenuItem *N1;
        TMenuItem *Engine1;
        TMenuItem *FlipBoard1;
        TMenuItem *Speed1;
        TMenuItem *Medium1;
        TMenuItem *Slow1;
	void __fastcall FormClose(TObject *Sender, TCloseAction &Action);
        void __fastcall FormCreate(TObject *Sender);
        void __fastcall xyDragOver(TObject *Sender, TObject *Source, int X,
          int Y, TDragState State, bool &Accept);
        void __fastcall xyDragDrop(TObject *Sender, TObject *Source, int X,
          int Y);
        void __fastcall xyMouseDown(TObject *Sender, TMouseButton Button,
          TShiftState Shift, int X, int Y);
        void __fastcall xyStartDrag(TObject *Sender,
          TDragObject *&DragObject);
        void __fastcall Timer1Timer(TObject *Sender);
        void __fastcall StringGrid1MouseDown(TObject *Sender,
          TMouseButton Button, TShiftState Shift, int X, int Y);
        void __fastcall StringGrid1DrawCell(TObject *Sender, int ACol,
          int ARow, TRect &Rect, TGridDrawState State);
        void __fastcall ScrollBar1Scroll(TObject *Sender,
          TScrollCode ScrollCode, int &ScrollPos);
        void __fastcall Button3Click(TObject *Sender);
        void __fastcall Edit1KeyPress(TObject *Sender, char &Key);
        void __fastcall Compute1Click(TObject *Sender);
        void __fastcall Fast1Click(TObject *Sender);
        void __fastcall InvertBoard1Click(TObject *Sender);
        void __fastcall FlipBoard1Click(TObject *Sender);
        void __fastcall Medium1Click(TObject *Sender);
        void __fastcall Slow1Click(TObject *Sender);
private:
        TMyDCObject *MyDCObject;
        void __fastcall SetControlsControlStyle(TControl* Control); // addition
        HANDLE hProcess;
        HANDLE hStdInRead;
        HANDLE hStdInWrite;
        HANDLE hStdOutRead;
        HANDLE hStdOutWrite;
        PROCESS_INFORMATION pi;
        void __fastcall CloseHandles();

public:
	virtual __fastcall TMDIChild(TComponent *Owner);

        ///////////// MY ADDITIONS /////////////
        AnsiString EnPassSq, PromotedPawn, DraggedSq, SentPromoPawn;
        bool NoDrag, ComputerColor, LastMovedColor, a1moved, e1moved, h1moved, a8moved, e8moved, h8moved;
        int Counter50M;

        struct TPiece
        {
         AnsiString Name;
         bool Color; // 0 - Black, 1 - White
         Graphics::TBitmap *Face;
        };
        TPiece Piece[14]; // 12 pieces + 1 NULL + 1 Back Up

        struct TSquare
        {
         AnsiString Coordinates;
         TPiece Piece;
        };
        TSquare Square[64]; // 64 different squares

        TStringList *FENStrings;
        TStringList *SmithStrings;
        TGridRect grect;

        TImage *a8bg;
        TImage *a7bg;
        TImage *a6bg;
        TImage *a5bg;
        TImage *a4bg;
        TImage *a3bg;
        TImage *a2bg;
        TImage *a1bg;

        TImage *b8bg;
        TImage *b7bg;
        TImage *b6bg;
        TImage *b5bg;
        TImage *b4bg;
        TImage *b3bg;
        TImage *b2bg;
        TImage *b1bg;

        TImage *c8bg;
        TImage *c7bg;
        TImage *c6bg;
        TImage *c5bg;
        TImage *c4bg;
        TImage *c3bg;
        TImage *c2bg;
        TImage *c1bg;

        TImage *d8bg;
        TImage *d7bg;
        TImage *d6bg;
        TImage *d5bg;
        TImage *d4bg;
        TImage *d3bg;
        TImage *d2bg;
        TImage *d1bg;

        TImage *e8bg;
        TImage *e7bg;
        TImage *e6bg;
        TImage *e5bg;
        TImage *e4bg;
        TImage *e3bg;
        TImage *e2bg;
        TImage *e1bg;

        TImage *f8bg;
        TImage *f7bg;
        TImage *f6bg;
        TImage *f5bg;
        TImage *f4bg;
        TImage *f3bg;
        TImage *f2bg;
        TImage *f1bg;

        TImage *g8bg;
        TImage *g7bg;
        TImage *g6bg;
        TImage *g5bg;
        TImage *g4bg;
        TImage *g3bg;
        TImage *g2bg;
        TImage *g1bg;

        TImage *h8bg;
        TImage *h7bg;
        TImage *h6bg;
        TImage *h5bg;
        TImage *h4bg;
        TImage *h3bg;
        TImage *h2bg;
        TImage *h1bg;

        bool __fastcall CheckSq(AnsiString TheSquare);
        int __fastcall SqToNo(AnsiString TheSquare);
        bool __fastcall CanMove(AnsiString FirstSq, AnsiString SecondSq, bool CheckForPinAndMate);
        bool __fastcall PlayMove(AnsiString FirstSq, AnsiString SecondSq);
        TStringList* __fastcall LegalSquares(AnsiString Sq);
        void __fastcall WritePFile (AnsiString Data);
        void __fastcall AddEngine(AnsiString exeplace);
        void __fastcall TakeBack(AnsiString Move, bool Color);
        void __fastcall GoNext(AnsiString Move, bool Color);
        void __fastcall Scrollit(int ScrollPos);
        void __fastcall FillImageList(void);
        void __fastcall SelectBackGrounds(void);
        void __fastcall RefreshPieces(void);
        void __fastcall RefreshBoards(void);
};
//----------------------------------------------------------------------------
extern TMDIChild *MDIChild;
#endif
