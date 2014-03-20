#pragma once
#include "BaseWindow.h"

namespace {
	LPCTSTR LpctClassName = _T("Application");
};

class MainWindow : public BaseWindow<MainWindow>
{
public:

	LRESULT HandleMessage(UINT uMsg, WPARAM wParam, LPARAM lParam) override;

	LPCTSTR ClassName() const override;

private:

};

