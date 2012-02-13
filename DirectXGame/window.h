/* ---------------------------------------------

Author: Forgive
Page: www.github.com/Forgive
Creation Date: 12 - 02 - 2012 (17:08)
Last Updated: 13 - 02 - 2012 (00:41)

This is the Main Window.

--------------------------------------------*/

#include <Windows.h>

class Window {
public:
	Window();
	~Window();
	int myWidth() const;
	int myHeight() const;
	HWND myWindow() const;
	bool initializeWindow(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow);

private:
	HWND m_Window;
	int width;
	int height;
};