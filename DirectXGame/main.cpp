/* ---------------------------------------------

Author: Forgive
Page: www.github.com/Forgive
Creation Date: 12 - 02 - 2012 (16:25)
Last Updated: 13 - 02 - 2012 (00:40)

This is the main stuff.

--------------------------------------------*/

#include <Windows.h>
#include "window.h"
#include "engine.h"

// Default function called when the application is started.

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow)
{
	Window *window = new Window;
	if(!window->initializeWindow(hInstance, hPrevInstance, lpCmdLine, nCmdShow)) {
		MessageBox(NULL, L"Could not initialize window", L"Initializing Error", MB_ICONERROR | MB_OK);
		return 0;
	}
	Engine *myEngine = new Engine;
	if(!myEngine->initializeEngine(window->myWindow(), window->myWidth(), window->myHeight())) {
		MessageBox(NULL, L"Could not initialize the engine", L"Initializing Error", MB_ICONERROR | MB_OK);
		return 0;
	}

	MSG message = {0};
	while(WM_QUIT != message.message) {
		while(PeekMessage(&message, NULL, 0, 0, PM_REMOVE) == TRUE) {
			TranslateMessage(&message);
			DispatchMessage(&message);
		}
		// render stuff. blabla.
	}
	return 0;
}