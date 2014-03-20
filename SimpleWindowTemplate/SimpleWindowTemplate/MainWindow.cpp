#include "MainWindow.h"

LRESULT MainWindow::HandleMessage(
	UINT uMsg, WPARAM wParam, LPARAM lParam)
{
	switch (uMsg)
	{
	case WM_CREATE:
		break;
	case WM_SIZE:
		break;
	case WM_PAINT:
		break;
	case WM_DESTROY:
		PostQuitMessage(0);
		break;
	default:
		return DefWindowProc(hWnd_, uMsg, wParam, lParam);
	}
	return 0;
}

LPCTSTR MainWindow::ClassName() const
{
	return LpctClassName;
}
