//---------------------------------------------------------------------------
#ifndef RegExtH
#define RegExtH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Registry.hpp>
#include <shlobj.h>

#define EXT_OPEN    "open"
#define EXT_EDIT    "edit"
#define EXT_PRINT   "print"
#define EXT_PLAY    "play"
#define DEFAULT     ""

#define FTA_Exclude         0x00000001
#define FTA_Show            0x00000002
#define FTA_HasExtension    0x00000004
#define FTA_NoEdit          0x00000008
#define FTA_NoRemove        0x00000010
#define FTA_NoNewVerb       0x00000020
#define FTA_NoEditVerb      0x00000040
#define FTA_NoRemoveVerb    0x00000080
#define FTA_NoEditDesc      0x00000100
#define FTA_NoEditIcon      0x00000200
#define FTA_NoEditDflt      0x00000400
#define FTA_NoEditVerbCmd   0x00000800
#define FTA_NoEditVerbExe   0x00001000
#define FTA_NoDDE           0x00002000
#define FTA_NoEditMIME      0x00008000
#define FTA_OpenIsSafe      0x00010000
#define FTA_AlwaysUnsafe    0x00020000
#define FTA_AlwaysShowExt   0x00040000
#define FTA_NoRecentDocs    0x00100000
//---------------------------------------------------------------------------

namespace FileExtension
{

typedef struct
{
    LPITEMIDLIST pidlPath;
    BOOL bWatchSubtree;
} TNotifyRegister;

typedef struct
{
    LPITEMIDLIST PIDL1;
    LPITEMIDLIST PIDL2;
} TTwoPIDLArray;

class PACKAGE TExtCommand
{
    private:
        System::AnsiString FAction, FActionDesc, FCommand;

    public:
        __fastcall TExtCommand(System::AnsiString Action, System::AnsiString ActionDesc, System::AnsiString Command);

        __property System::AnsiString Action = {read=FAction};
        __property System::AnsiString ActionDesc = {read=FActionDesc};
        __property System::AnsiString Command = {read=FCommand};
};
//---------------------------------------------------------------------------
class PACKAGE TExtCommands
{
    private:
        System::AnsiString FDefAction;
        TList *FActions;
        bool FCreate;
        
        FileExtension::TExtCommand*  __fastcall GetCommand(int index);
        int __fastcall GetCount(void);
    public:
        __fastcall TExtCommands(void);
        __fastcall ~TExtCommands(void);
        int __fastcall Add(TExtCommand *C);
        int __fastcall Add(System::AnsiString Action, System::AnsiString ActionDesc);
        int __fastcall Add(System::AnsiString Action, System::AnsiString ActionDesc, System::AnsiString Command);
        void __fastcall Clear(void);

        __property bool AutoCreate = {read=FCreate,write=FCreate};
        __property FileExtension::TExtCommand* Command[int Index] = {read=GetCommand};
        __property int Count = {read=GetCount};
        __property System::AnsiString DefaultAction = {read=FDefAction,write=FDefAction};
};
//---------------------------------------------------------------------------
class PACKAGE TExtInfo
{
    private:
        System::AnsiString FExt, FPath, FDesc, FIcon;
        DWORD FEditFlags;
        FileExtension::TExtCommands *FCommands;

        void __fastcall SetExt(System::AnsiString NewExt);
        void __fastcall SetPath(System::AnsiString NewPath);
    public:
        __fastcall TExtInfo(System::AnsiString Ext, System::AnsiString ExecPath, System::AnsiString Desc, DWORD EditFlags);
        __fastcall ~TExtInfo(void);

        __property FileExtension::TExtCommands* Commands = {read=FCommands,write=FCommands};
        __property DWORD EditFlags = {read=FEditFlags, write=FEditFlags};
        __property System::AnsiString ExecutePath = {read=FPath,write=SetPath};
        __property System::AnsiString Extension = {read=FExt,write=SetExt};
        __property System::AnsiString FileDesc = {read=FDesc,write=FDesc};
        __property System::AnsiString Icon = {read=FIcon,write=FIcon};
};
//---------------------------------------------------------------------------
class PACKAGE TRegExtension : public TComponent
{
private:
    TRegistry *Reg;
    TList *FExtensions;
    FileExtension::TExtInfo *E;
    TStringList *FRegExts;
    bool FUpdateExts, FMonitor, isNT;
    HWND hWnd;
    HANDLE hNotifyHandle;
    HINSTANCE hDll;

    typedef HANDLE (__stdcall *fpSHChangeNotifyRegister)(HWND, DWORD, ULONG, UINT, DWORD, TNotifyRegister*);
    typedef BOOL (__stdcall *fpSHChangeNotifyDeregister)(HANDLE);
    typedef HANDLE (__stdcall *fpSHChangeNotification_Lock)(HANDLE, DWORD, TTwoPIDLArray*, ULONG);
    typedef BOOL (__stdcall *fpSHChangeNotification_Unlock)(HANDLE);

    fpSHChangeNotifyRegister SHChangeNotifyRegister;
    fpSHChangeNotifyDeregister SHChangeNotifyDeregister;
    fpSHChangeNotification_Lock SHChangeNotification_Lock;
    fpSHChangeNotification_Unlock SHChangeNotification_Unlock;

    void __fastcall AssocChanged(void);
    bool __fastcall CreateExtension(FileExtension::TExtInfo *E);
    bool __fastcall DeleteKey(System::AnsiString key);
    FileExtension::TExtInfo* __fastcall GetExt(int index);
    Classes::TStringList* __fastcall GetRegExts(void);
    void __fastcall GetSubkeys(System::AnsiString key, Classes::TStringList*);
    void __fastcall HandleMessage(TMessage &Message);
    bool __fastcall ReadBinary(System::AnsiString key, System::AnsiString name, void *data, int size);
    System::AnsiString __fastcall ReadValue(System::AnsiString key, System::AnsiString name);
    void __fastcall SetMonitor(bool value);
    void __fastcall StartWatching(void);
    void __fastcall StopWatching(void);
    void __fastcall UpdateRegExts(bool DoUpdate);
    bool __fastcall WriteBinary(System::AnsiString key, System::AnsiString name, void *data, int size);
    bool __fastcall WriteValue(System::AnsiString key, System::AnsiString name, System::AnsiString value);
protected:
    TNotifyEvent FOnAssocChange;
public:
    __fastcall TRegExtension(TComponent* Owner);
    __fastcall ~TRegExtension();

    int __fastcall Add(FileExtension::TExtInfo *E);
    int __fastcall Add(System::AnsiString Ext, System::AnsiString ExecPath);
    int __fastcall Add(System::AnsiString Ext, System::AnsiString ExecPath, System::AnsiString Desc);
    int __fastcall Add(System::AnsiString Ext, System::AnsiString ExecPath, System::AnsiString Desc, DWORD Flags);
    void __fastcall Clear(void);
    FileExtension::TExtInfo* __fastcall GetExtInfo(System::AnsiString Ext);
    bool __fastcall IsRegistered(System::AnsiString Ext);
    bool __fastcall Register(void);
    bool __fastcall Unregister(System::AnsiString Ext);

    __property FileExtension::TExtInfo* Extensions[int Index] = {read=GetExt};
    __property Classes::TStringList* RegisteredExtensions = {read=GetRegExts};
__published:
    __property bool Monitor = {read=FMonitor, write=SetMonitor};
    __property TNotifyEvent OnAssocChange = {read=FOnAssocChange, write=FOnAssocChange};
};
//---------------------------------------------------------------------------
}
#if !defined(NO_IMPLICIT_NAMESPACE_USE)
using namespace FileExtension;
#endif

#endif
