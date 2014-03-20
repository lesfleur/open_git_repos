#include "BaseWindow.h"
#include "MainWindow.h"
#include "resource.h"

template<typename Derived>
BaseWindow<Derived>::BaseWindow()
	: hWnd_(NULL)
{
}

template<typename Derived>
BaseWindow<Derived>::~BaseWindow()
{
}

template<typename Derived>
LRESULT CALLBACK BaseWindow<Derived>::WindowProc(
	HWND hWnd, UINT uMsg, WPARAM wParam, LPARAM lParam
	)
{
	Derived *pDerived = nullptr;
	if (uMsg == WM_NCCREATE)
	{
		CREATESTRUCT *pCreate = reinterpret_cast<CREATESTRUCT *>(lParam);
		pDerived = reinterpret_cast<Derived *>(pCreate->lpCreateParams);
		SetWindowLongPtr(hWnd, GWLP_USERDATA, reinterpret_cast<LONG_PTR>(pDerived));
		pDerived->hWnd_ = hWnd;
	}
	else
	{
		pDerived = reinterpret_cast<Derived *>(GetWindowLongPtr(hWnd, GWLP_USERDATA));
	}
	if (pDerived)
	{
		return pDerived->HandleMessage(uMsg, wParam, lParam);
	}
	else
	{
		return DefWindowProc(hWnd, uMsg, wParam, lParam);
	}
}

template<typename Derived>
BOOL BaseWindow<Derived>::Create(
	LPTSTR lpWindowName,
	DWORD dwStyle,
	DWORD dwExStyle = 0,
	int x = CW_USEDEFAULT,
	int y = CW_USEDEFAULT,
	int nWidth = CW_USEDEFAULT,
	int nHeight = CW_USEDEFAULT,
	HWND hWndParent = 0,
	HMENU hMenu = 0
	)
{
	WNDCLASSEX wc = { 0 };

	wc.cbSize = sizeof(WNDCLASSEX);
	wc.style = CS_HREDRAW | CS_VREDRAW;
	wc.lpfnWndProc = Derived::WindowProc;
	wc.hInstance = GetModuleHandle(NULL);
	wc.hIcon = LoadIcon(wc.hInstance, MAKEINTRESOURCE(IDI_ICON1));
	wc.hCursor = LoadCursor(NULL, IDC_ARROW);
	wc.hbrBackground = (HBRUSH)(COLOR_WINDOW + 1);
	wc.lpszClassName =ClassName();
	wc.hIconSm = LoadIcon(wc.hInstance, MAKEINTRESOURCE(IDI_ICON1));

	RegisterClassEx(&wc);

	hWnd_ = CreateWindowEx(
		dwExStyle,
		ClassName(),
		lpWindowName,
		dwStyle,
		x,
		y,
		nWidth,
		nHeight,
		hWndParent,
		hMenu,
		GetModuleHandle(NULL),
		this
		);

	return (hWnd_ ? TRUE : FALSE);
}

template<typename Derived>
HWND BaseWindow<Derived>::Window() const
{
	return hWnd_;
}

// Explicit Instantiation
template class BaseWindow<MainWindow>;