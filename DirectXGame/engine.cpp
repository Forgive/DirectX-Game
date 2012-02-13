/* ---------------------------------------------

Author: Forgive
Page: www.github.com/Forgive
Creation Date: 13 - 02 - 2012 (00:47)
Last Updated: 13 - 02 - 2012 (07:04)

This is the graphics engine, rendering, D3D Stuff, etc goes here.

--------------------------------------------*/

#include "engine.h"

Engine::Engine() {

}

Engine::~Engine() {

}

void Engine::clearData() {
	m_d3device->Release();
	m_deviceCon->Release();
	m_swapChain->Release();
}

bool Engine::initializeEngine(HWND hWnd, int width, int height) {
	DXGI_SWAP_CHAIN_DESC swapChainDesc;
	ZeroMemory(&swapChainDesc, sizeof(swapChainDesc));
	swapChainDesc.BufferCount = 2;
	swapChainDesc.BufferDesc.Width = width;
	swapChainDesc.BufferDesc.Height = height;
	swapChainDesc.BufferUsage = DXGI_USAGE_RENDER_TARGET_OUTPUT;
	swapChainDesc.BufferDesc.Format = DXGI_FORMAT_R8G8B8A8_UNORM;
	swapChainDesc.BufferDesc.RefreshRate.Numerator = 60;
	swapChainDesc.BufferDesc.RefreshRate.Denominator = 1;
	swapChainDesc.SampleDesc.Quality = 0;
	swapChainDesc.SampleDesc.Count = 1;
	swapChainDesc.OutputWindow = hWnd;
	swapChainDesc.Windowed = true;
	HRESULT createDevice;
	createDevice = D3D11CreateDeviceAndSwapChain(NULL,
												 D3D_DRIVER_TYPE_HARDWARE,
												 NULL,
												 NULL,
												 NULL,
												 NULL,
												 D3D11_SDK_VERSION,
												 &swapChainDesc,
												 &m_swapChain,
												 &m_d3device,
												 NULL,
												 &m_deviceCon);
	if(FAILED(createDevice)) {
		// We'll get a nicely error handler here. ;)
		return 0;
	}
	return 1;
}
