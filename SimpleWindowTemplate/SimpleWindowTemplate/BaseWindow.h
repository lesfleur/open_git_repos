#pragma once
#include <SDKDDKVer.h>
#define WIN32_LEAN_AND_MEAN
#include <Windows.h>
#include <tchar.h>

template<typename Derived>
class BaseWindow
{
public:

	BaseWindow();

	virtual ~BaseWindow();

	static LRESULT CALLBACK WindowProc(
		HWND hWnd, UINT uMsg, WPARAM wParam, LPARAM lParam);

	BOOL Create(
		LPTSTR lpszWindowName, DWORD dwStyle, DWORD dwStyleEx = 0,
		int x = CW_USEDEFAULT, int y = CW_USEDEFAULT,
		int nWidth = CW_USEDEFAULT, int nHeight = CW_USEDEFAULT,
		HWND hWndParent = 0, HMENU = 0);

	HWND Window() const;

protected:

	HWND	hWnd_;

	virtual LPCTSTR ClassName() const = 0;

	virtual LRESULT HandleMessage(
		UINT uMsg, WPARAM wParam, LPARAM lParam) = 0;

};
