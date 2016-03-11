//---------------------------------------------------------------------
#include <vcl.h>
#pragma hdrstop
//---------------------------------------------------------------------
USEFORM("main.cpp", MainForm);
USEFORM("ChildWin.cpp", MDIChild);
USEFORM("about.cpp", AboutBox);
USEFORM("Unit1.cpp", Form1);
USEFORM("Promotion.cpp", PromotionForm);
USEFORM("Unit2.cpp", Form2);
//---------------------------------------------------------------------------
WINAPI WinMain(HINSTANCE, HINSTANCE, LPSTR cmdLine, int)
{
 HANDLE hSemaphore = ::CreateSemaphore(NULL,1,1, "CHESSPEER.SEMAPHORE");
 if(hSemaphore && WaitForSingleObject(hSemaphore, 0) != WAIT_OBJECT_0) {
  CloseHandle(hSemaphore);

  HWND hWnd = ::FindWindow("TMainForm", NULL);

  if (strlen(cmdLine) != 0) {
   COPYDATASTRUCT cds;
   cds.cbData = strlen(cmdLine) + 1;
   cds.lpData = cmdLine;
   SendMessage(hWnd, WM_COPYDATA, 0, (LPARAM)&cds);
  }
  //return 0;
 }

 Application->Initialize();
 Application->Title = "ChessPeer 1.0";
 Application->CreateForm(__classid(TMainForm), &MainForm);
                 Application->CreateForm(__classid(TMDIChild), &MDIChild);
                 Application->CreateForm(__classid(TAboutBox), &AboutBox);
                 Application->CreateForm(__classid(TForm1), &Form1);
                 Application->CreateForm(__classid(TPromotionForm), &PromotionForm);
                 Application->CreateForm(__classid(TForm2), &Form2);
                 Application->Run();

 ReleaseSemaphore(hSemaphore,1,NULL); // My
 CloseHandle(hSemaphore); // My

 return 0;
}
//---------------------------------------------------------------------
