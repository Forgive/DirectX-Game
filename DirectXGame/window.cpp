/* ---------------------------------------------

Author: Forgive
Page: www.github.com/Forgive
Creation Date: 12 - 02 - 2012 (17:08)
Last Updated: 13 - 02 - 2012 (00:41)

This is the Main Window.

--------------------------------------------*/

#include "window.h"

LRESULT CALLBACK WndProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam);

// Constructor

Window::Window() {

}

// Destructor

Window::~Window() {

}

int Window::myWidth() const {
	return width;
}

int Window::myHeight() const {
	return height;
}

// When we create the Engine, we'll need this.

HWND Window::myWindow() const {
	return m_Window; 
}

// To create the Window

bool Window::initializeWindow(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow) {
	WNDCLASSEX window_class;

	window_class.cbSize        = sizeof(WNDCLASSEX);
	window_class.style		   = CS_HREDRAW | CS_VREDRAW;
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
		return false;
	}

	width = ::GetSystemMetrics(SM_CXSCREEN);
	height = ::GetSystemMetrics(SM_CYSCREEN);

	m_Window = CreateWindowEx(WS_EX_CLIENTEDGE,
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

	if(m_Window == NULL) {
		MessageBox(NULL, L"Could not create the window", L"Window Creation Error", MB_ICONERROR | MB_OK);
		return false;
	}

	ShowWindow(m_Window, nCmdShow);
	UpdateWindow(m_Window);
	return true;
}

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