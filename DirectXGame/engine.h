/* ---------------------------------------------

Author: Forgive
Page: www.github.com/Forgive
Creation Date: 13 - 02 - 2012 (00:47)
Last Updated: 13 - 02 - 2012 (07:01)

This is the graphics engine, rendering, D3D Stuff, etc goes here.

--------------------------------------------*/

#include <Windows.h>
#include <d3d11.h>
#include <d3dx11.h>
#include <d3d10.h>
#include <d3dx10.h>

#pragma comment(lib, "d3d11.lib")
#pragma comment(lib, "d3dx11.lib")
#pragma comment(lib, "d3dx10.lib")

class Engine {
public:
	Engine();
	~Engine();
	bool initializeEngine(HWND hWnd, int width, int height);
	void clearData();

private:
	ID3D11Device*		    m_d3device;
	ID3D11DeviceContext*    m_deviceCon;
	IDXGISwapChain*		    m_swapChain;
};


