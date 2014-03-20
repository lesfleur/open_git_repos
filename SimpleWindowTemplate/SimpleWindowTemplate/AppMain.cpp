#include "MainWindow.h"

namespace {
	const int WindowWidth = 800;
	const int WindowHeight = 640;
	LPTSTR LpctWindowName = _T("Simple Window");
};

int APIENTRY _tWinMain(
	_In_ HINSTANCE hInstance,
	_In_opt_ HINSTANCE hPrevInstance,
	_In_ LPTSTR    lpCmdLine,
	_In_ int       nCmdShow)
{
	UNREFERENCED_PARAMETER(hPrevInstance);
	UNREFERENCED_PARAMETER(lpCmdLine);

	MainWindow win;
	if (!win.Create(
		LpctWindowName, 	    // lpWindowName
		WS_OVERLAPPEDWINDOW,	// dwStyle
		0,				// dwExStyle
		CW_USEDEFAULT,	// x
		CW_USEDEFAULT,	// y
		WindowWidth,	// nWidth
		WindowHeight,	// nHeight
		NULL,			// hWndParent
		NULL			// hMenu
		)
		)
	{
		return 0;
	}
	ShowWindow(win.Window(), nCmdShow);

	MSG msg = { 0 };
	BOOL bRet;
	while (bRet = GetMessage(&msg, NULL, 0, 0))
	{
		if (bRet == 0 || bRet == -1)
		{
			break;
		}
		TranslateMessage(&msg);
		DispatchMessage(&msg);
	}

	return static_cast<int>(msg.wParam);
}