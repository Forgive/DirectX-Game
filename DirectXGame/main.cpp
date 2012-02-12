/* ---------------------------------------------

Author: Forgive
Page: www.github.com/Forgive
Creation Date: 12 - 02 - 2012 (16:25)
Last UpdateD: 12 - 02 - 2012 (16:10)

This is the graphics engine.

--------------------------------------------*/

#include <Windows.h>

// We need to put this here before WinMain as C++ "fails" at this sort of things, i mean
// put it after WinMain and WndProc will be undefined.

LRESULT CALLBACK WndProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam) {
	switch(message) {
		case WM_CLOSE: {
			DestroyWindow(hWnd);
			break;
		}
		case WM_DESTROY: {
			PostQuitMessage(0);
			break;
		}
		default: {
			return DefWindowProc(hWnd, message, wParam, lParam);
		}
	}
	return 0;
}

// Default function called when the application is started.

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow)
{
	HWND window;
	WNDCLASSEX window_class;
	MSG message;

	window_class.cbSize        = sizeof(WNDCLASSEX);
	window_class.style		   = CS_DROPSHADOW | CS_HREDRAW | CS_VREDRAW;
	window_class.lpfnWndProc   = (WNDPROC)WndProc;
	window_class.cbClsExtra    = NULL;
	window_class.cbWndExtra    = NULL;
	window_class.hInstance     = hInstance;
	window_class.hIcon         = LoadIcon(NULL, IDI_APPLICATION);
	window_class.hCursor       = LoadCursor(NULL, IDC_ARROW);
	window_class.hbrBackground = (HBRUSH)COLOR_BACKGROUND;
	window_class.lpszMenuName  = NULL;
	window_class.lpszClassName = L"DirectX Game";
	window_class.hIconSm       = LoadIcon(NULL, IDI_APPLICATION);

	if(!RegisterClassEx(&window_class)) {
		MessageBox(NULL, L"Could not register the window.", L"Registration Error", MB_ICONERROR | MB_OK);
		return 0;
	}

	int width = ::GetSystemMetrics(SM_CXSCREEN);
	int height = ::GetSystemMetrics(SM_CYSCREEN);

	window = CreateWindowEx(WS_EX_CLIENTEDGE,
							L"DirectX Game",
							L"DirectX Game",
							WS_OVERLAPPEDWINDOW,
							CW_USEDEFAULT,
							CW_USEDEFAULT,
							width,
							height,
							NULL,
							NULL,
							hInstance,
							NULL);

	if(window == NULL) {
		MessageBox(NULL, L"Could not create the window", L"Window Creation Error", MB_ICONERROR | MB_OK);
		return 0;
	}

	ShowWindow(window, nCmdShow);
	UpdateWindow(window);

	while(GetMessage(&message, NULL, 0, 0) > 0) {
		TranslateMessage(&message);
		DispatchMessage(&message);
	}


}
