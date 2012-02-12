/* ---------------------------------------------

Author: Forgive
Page: www.github.com/Forgive
Creation Date: 12 - 02 - 2012 (16:25)
Last Updated: 12 - 02 - 2012 (17:17)

This is the graphics engine.

--------------------------------------------*/

#include <Windows.h>
#include "window.h"

// Default function called when the application is started.

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow)
{
	Window *window = new Window;
	if(!window->initializeWindow(hInstance, hPrevInstance, lpCmdLine, nCmdShow)) {
		MessageBox(NULL, L"Could not initialize window", L"Initializing Error", MB_ICONERROR | MB_OK);
		return 0;
	}
	return 0;
}