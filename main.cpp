//Definieren UNICODE für WindowProc Methode
#ifndef UNICODE
#define UNICODE
#endif
#ifndef _UNICODE
#define _UNICODE
#endif

//Einfügen von Klassen und Bibliotheken 
#include <Windows.h>
#include <Commctrl.h>
#include <iostream>
#include <tchar.h>

//Definieren von Button Values
#define BTN_BUTTON1 1000
#define BTN_BUTTON2 2000
#define WM_COMMAND 273

//Erstellen Buttons und Verwaltung Tastendruck
LRESULT CALLBACK WindowProc(HWND hWnd, UINT uMsg, WPARAM wParam, LPARAM lParam)
{
  switch (uMsg)
  {
  case WM_CREATE:
  {
    HINSTANCE hIns = ((LPCREATESTRUCT)lParam)->hInstance;
    CreateWindowEx(0,L"button",L"Love", WS_CHILD | WS_VISIBLE, 125, 15, 80, 30, hWnd, (HMENU)BTN_BUTTON1, hIns, 0);

    HINSTANCE hIns1 = ((LPCREATESTRUCT)lParam)->hInstance;
    CreateWindowEx(0,L"button", L"Hate", WS_CHILD | WS_VISIBLE, 180, 50, 110, 50, hWnd, (HMENU)BTN_BUTTON2, hIns1, 0);

    HINSTANCE hIns2 = ((LPCREATESTRUCT)lParam)->hInstance;
    CreateWindowEx(WS_EX_CLIENTEDGE, TEXT("Edit"), TEXT("test"),
                   WS_CHILD | WS_VISIBLE, 300, 300, 140,
                   20, hWnd, NULL, NULL, NULL);

    HINSTANCE hIns3 = ((LPCREATESTRUCT)lParam)->hInstance;
    CreateWindowEx(WS_EX_CLIENTEDGE, TEXT("Static"), TEXT("test"),
                   WS_CHILD | WS_VISIBLE, 500, 500, 140,
                   20, hWnd, NULL, NULL, NULL);

    return 0;
  }
  case WM_PAINT:
  {
    PAINTSTRUCT ps;
    HDC hdc = BeginPaint(hWnd, &ps);
    FillRect(hdc, &ps.rcPaint, (HBRUSH)(COLOR_WINDOW + 2));
    EndPaint(hWnd, &ps);
    return 0;
  }
  case WM_CLOSE:
  {
    if (MessageBox(hWnd, L"Do you want to exit?", L"EXIT", MB_OKCANCEL) == IDOK)
      DestroyWindow(hWnd);
    return 0;
  }
  case WM_DESTROY:
  {
    PostQuitMessage(0);
    return 0;
  }
}
  return DefWindowProc(hWnd, uMsg, wParam, lParam);
};

//Erstellen neues Fenster
int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevIns, LPSTR lpszArgument, int nCmdShow)
{

  const wchar_t CLASS_NAME[] = L"NULL"; 
  WNDCLASS wc = {};
  wc.lpfnWndProc = WindowProc;
  wc.lpszClassName = CLASS_NAME;
  wc.hInstance = hInstance;
  RegisterClass(&wc);
  HWND hWnd = CreateWindowEx(0, CLASS_NAME, L"WizardCardGame", WS_OVERLAPPEDWINDOW, CW_USEDEFAULT, CW_USEDEFAULT, CW_USEDEFAULT, CW_USEDEFAULT, NULL, NULL, hInstance, NULL);
  if (hWnd == 0)
    return 1;
  ShowWindow(hWnd, nCmdShow);
  nCmdShow = 1;
  MSG msg;
  while (GetMessage(&msg, NULL, 0, 0))
  {
    TranslateMessage(&msg);
    DispatchMessage(&msg);
  }

  return 0;
}