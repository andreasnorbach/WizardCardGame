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
#define BTN_BUTTON1 1000 //StartButton
#define BTN_BUTTON2 2000 //ExitButton
#define WM_COMMAND 273

//Erstellen Buttons und Verwaltung Tastendruck
LRESULT CALLBACK WindowProc(HWND hWnd, UINT uMsg, WPARAM wParam, LPARAM lParam)
{
  switch (uMsg)
  {
  case WM_CREATE:
  {
    HINSTANCE StartButton = ((LPCREATESTRUCT)lParam)->hInstance;
    CreateWindowEx(0, L"button", L"START THE GAME", WS_CHILD | WS_VISIBLE, 600, 15, 130, 70, hWnd, (HMENU)BTN_BUTTON1, StartButton, 0);

    HINSTANCE ExitButton = ((LPCREATESTRUCT)lParam)->hInstance;
    CreateWindowEx(0, L"button", L"QUIT THE GAME", WS_CHILD | WS_VISIBLE, 600, 600, 130, 70, hWnd, (HMENU)BTN_BUTTON2, ExitButton, 0);

    HINSTANCE player1Title = ((LPCREATESTRUCT)lParam)->hInstance;
    CreateWindowEx(WS_EX_CLIENTEDGE, TEXT("Static"), TEXT("Player 1: "),
                   WS_CHILD | WS_VISIBLE, 400, 15, 140,
                   20, hWnd, NULL, NULL, NULL);

    HINSTANCE player1Name = ((LPCREATESTRUCT)lParam)->hInstance;
    CreateWindowEx(WS_EX_CLIENTEDGE, TEXT("Edit"), TEXT("P1"),
                   WS_CHILD | WS_VISIBLE, 400, 50, 140,
                   20, hWnd, NULL, NULL, NULL);

    HINSTANCE player2Title = ((LPCREATESTRUCT)lParam)->hInstance;
    CreateWindowEx(WS_EX_CLIENTEDGE, TEXT("Static"), TEXT("Player 2: "),
                   WS_CHILD | WS_VISIBLE, 800, 15, 140,
                   20, hWnd, NULL, NULL, NULL);

    HINSTANCE player2Name = ((LPCREATESTRUCT)lParam)->hInstance;
    CreateWindowEx(WS_EX_CLIENTEDGE, TEXT("Edit"), TEXT("P2"),
                   WS_CHILD | WS_VISIBLE, 800, 50, 140,
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