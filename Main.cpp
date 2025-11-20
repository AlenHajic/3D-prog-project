#include <Windows.h>
#include <iostream>
#include <d3d11.h>

#include "WindowHelper.h"
#include "RenderTargetD3D11.h"
#include "DepthBufferD3D11.h"   

int APIENTRY wWinMain(_In_ HINSTANCE hInstance,
    _In_opt_ HINSTANCE hPrevInstance,
    _In_ LPWSTR lpCmdLine,
    _In_ int nCmdShow)
{
    const UINT WIDTH = 1024;
    const UINT HEIGHT = 560;

    // -------------------------------------------
    // 1. Create window
    // -------------------------------------------
    HWND window;
    if (!SetupWindow(hInstance, WIDTH, HEIGHT, nCmdShow, window))
    {
        std::cerr << "Failed to create window!" << std::endl;
        return -1;
    }

    // -------------------------------------------
    // 2. Setup Direct3D (device, context, swapchain, backbuffer)
    // -------------------------------------------
    ID3D11Device* device = nullptr;
    ID3D11DeviceContext* context = nullptr;
    IDXGISwapChain* swapChain = nullptr;
    ID3D11RenderTargetView* backbufferRTV = nullptr;
    ID3D11Texture2D* depthTexture = nullptr;
    ID3D11DepthStencilView* depthView = nullptr;
    D3D11_VIEWPORT viewport = {};

   /* if (!SetupD3D11(WIDTH, HEIGHT, window,
        device, context, swapChain,
        backbufferRTV, depthTexture, depthView,
        viewport))
    {
        std::cerr << "Failed to setup D3D11!" << std::endl;
        return -1;
    }*/

    // -------------------------------------------
    // 3. Create your own render targets (optional)
    // -------------------------------------------
   /* RenderTargetD3D11 myRT;
    myRT.Initialize(device, WIDTH, HEIGHT, DXGI_FORMAT_R8G8B8A8_UNORM, true);*/

    // -------------------------------------------
    // 4. Message loop + rendering
    // -------------------------------------------
    MSG msg = {};
    while (msg.message != WM_QUIT)
    {
        if (PeekMessage(&msg, nullptr, 0, 0, PM_REMOVE))
        {
            TranslateMessage(&msg);
            DispatchMessage(&msg);
            continue;
        }

        // ---------------------
        // Rendering
        // ---------------------
        float clear[4] = { 0.0f, 0.0f, 0.0f, 0.0f };

        // Clear backbuffer
        /*context->ClearRenderTargetView(backbufferRTV, clear);
        context->ClearDepthStencilView(depthView,
            D3D11_CLEAR_DEPTH | D3D11_CLEAR_STENCIL,
            1.0f, 0);*/

        // Set render targets
        /*context->OMSetRenderTargets(1, &backbufferRTV, depthView);*/

        // Set viewport
        /*context->RSSetViewports(1, &viewport);*/

        // TODO: draw your things here...

        // Present
       /* swapChain->Present(1, 0);*/
    }

    // -------------------------------------------
    // 5. Cleanup
    // -------------------------------------------
    if (backbufferRTV) backbufferRTV->Release();
    if (depthView) depthView->Release();
    if (depthTexture) depthTexture->Release();

    if (swapChain) swapChain->Release();
    if (context) context->Release();
    if (device) device->Release();

    return 0;
}
