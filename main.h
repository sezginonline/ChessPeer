//----------------------------------------------------------------------------
#ifndef MainH
#define MainH
//----------------------------------------------------------------------------
#include <vcl\ComCtrls.hpp>
#include <vcl\ExtCtrls.hpp>
#include <vcl\Messages.hpp>
#include <vcl\Buttons.hpp>
#include <vcl\Dialogs.hpp>
#include <vcl\StdCtrls.hpp>
#include <vcl\Menus.hpp>
#include <vcl\Controls.hpp>
#include <vcl\Forms.hpp>
#include <vcl\Graphics.hpp>
#include <vcl\Classes.hpp>
#include <vcl\SysUtils.hpp>
#include <vcl\Windows.hpp>
#include <vcl\System.hpp>
#include <ActnList.hpp>
#include <ImgList.hpp>
#include <StdActns.hpp>
#include <ToolWin.hpp>
#include "RegExtension.h"
#include <MPlayer.hpp>
#include <IdBaseComponent.hpp>
#include <IdComponent.hpp>
#include <IdTCPClient.hpp>
#include <IdTCPConnection.hpp>
#include <IdTCPServer.hpp>
//----------------------------------------------------------------------------
class TMainForm : public TForm
{
__published:
	TMainMenu *MainMenu1;
	TMenuItem *File1;
	TMenuItem *FileNewItem;
	TMenuItem *FileOpenItem;
	TMenuItem *FileCloseItem;
	TMenuItem *Window1;
	TMenuItem *Help1;
	TMenuItem *N1;
	TMenuItem *FileExitItem;
	TMenuItem *HelpAboutItem;
	TOpenDialog *OpenDialog;
	TMenuItem *FileSaveItem;
	TMenuItem *FileSaveAsItem;
	TMenuItem *Edit1;
	TMenuItem *CutItem;
	TMenuItem *CopyItem;
	TMenuItem *PasteItem;
        TStatusBar *StatusBar;
        TActionList *ActionList1;
        TEditCut *EditCut1;
        TEditCopy *EditCopy1;
        TEditPaste *EditPaste1;
        TAction *FileNew1;
        TAction *FileSave1;
        TAction *FileExit1;
        TAction *FileOpen1;
        TAction *FileSaveAs1;
        TAction *HelpAbout1;
        TWindowClose *FileClose1;
        TToolBar *ToolBar2;
        TToolButton *ToolButton1;
        TToolButton *ToolButton2;
        TToolButton *ToolButton3;
        TToolButton *ToolButton4;
        TToolButton *ToolButton5;
        TToolButton *ToolButton6;
        TToolButton *ToolButton9;
        TImageList *ImageList1;
        TMenuItem *Options1;
        TMenuItem *Tools1;
        TImage *Image1;
        TRegExtension *Reg1;
        TMenuItem *AddEngine1;
        TMenuItem *DefaultLayout1;
        TMenuItem *N2;
        TMenuItem *Toolbar1;
        TMenuItem *StatusBar1;
        TMenuItem *View1;
        TMenuItem *HelpTopics1;
        TMenuItem *PlaySounds1;
        TMediaPlayer *MediaPlayer1;
        TOpenDialog *OpenDialog1;
        TMenuItem *Pieces1;
        TMenuItem *Board1;
        TMenuItem *N5;
        TMenuItem *Classic1;
        TMenuItem *Modern11;
        TMenuItem *Sharp1;
        TMenuItem *SkyBlue1;
        TMenuItem *BestGreen1;
        TMenuItem *Modern21;
        TIdTCPClient *IdTCPClient1;
        TIdTCPServer *IdTCPServer1;
        TMenuItem *N6;
        TMenuItem *OpponentSeekingGames1;
        TMenuItem *MainConsole1;
        TSaveDialog *SaveDialog1;
        TTimer *Timer1;
        TMenuItem *N3;
        void __fastcall FileNew1Execute(TObject *Sender);
        void __fastcall FileOpen1Execute(TObject *Sender);
        void __fastcall HelpAbout1Execute(TObject *Sender);
        void __fastcall FileExit1Execute(TObject *Sender);
        void __fastcall FormClose(TObject *Sender, TCloseAction &Action);
        void __fastcall Toolbar1Click(TObject *Sender);
        void __fastcall StatusBar1Click(TObject *Sender);
        void __fastcall PlaySounds1Click(TObject *Sender);
        void __fastcall AddEngine1Click(TObject *Sender);
        void __fastcall FormCreate(TObject *Sender);
        void __fastcall Modern11Click(TObject *Sender);
        void __fastcall Modern21Click(TObject *Sender);
        void __fastcall Classic1Click(TObject *Sender);
        void __fastcall Sharp1Click(TObject *Sender);
        void __fastcall IdTCPServer1Execute(TIdPeerThread *AThread);
        void __fastcall HelpTopics1Click(TObject *Sender);
        void __fastcall SkyBlue1Click(TObject *Sender);
        void __fastcall BestGreen1Click(TObject *Sender);
        void __fastcall OpponentSeekingGames1Click(TObject *Sender);
        void __fastcall MainConsole1Click(TObject *Sender);
        void __fastcall FileSave1Execute(TObject *Sender);
        void __fastcall FileSaveAs1Execute(TObject *Sender);
        void __fastcall DefaultLayout1Click(TObject *Sender);
        void __fastcall Timer1Timer(TObject *Sender);
        void __fastcall IdTCPServer1Connect(TIdPeerThread *AThread);
private:
        FARPROC NewClientWP; // My BG additions
        FARPROC OldClientWP; // My BG additions
        void __fastcall RegisterExt(void); // Me
        void __fastcall RefreshThePieces(void); //Me
        void __fastcall RefreshTheBoards(void); //Me
        void __fastcall WMDropFiles(TWMDropFiles &Msg); // DragDrop
        void __fastcall WmCopyData(TWMCopyData &Msg);
        void __fastcall MDIClientWndProc(TMessage &Msg); // My BG additions

public:
        void __fastcall CreateMDIChild(const String Name);
	virtual __fastcall TMainForm(TComponent *Owner);
        void __fastcall PlayMediaSound(AnsiString FileLocation); //Me
        void __fastcall OnServerConVcl(void); // Me

        AnsiString IndyMsg; //Me
        bool FirstFileOpened;

        #pragma warn -inl
        BEGIN_MESSAGE_MAP
        MESSAGE_HANDLER(WM_COPYDATA, TWMCopyData, WmCopyData)
        MESSAGE_HANDLER(WM_DROPFILES,TWMDropFiles,WMDropFiles)
        END_MESSAGE_MAP(TForm)
        #pragma warn .inl
};
//----------------------------------------------------------------------------
extern TMainForm *MainForm;
//----------------------------------------------------------------------------
#endif
