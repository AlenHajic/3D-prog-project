#include "RenderTargetD3D11.h"

RenderTargetD3D11::~RenderTargetD3D11() {}

void RenderTargetD3D11::Initialize(ID3D11Device* device, UINT width, UINT height, DXGI_FORMAT format, bool hasSRV)
{
	if (!device) throw::std::runtime_error("RenderTargetD3D11::Initialize - device is null");

	//create texture desc
	D3D11_TEXTURE2D_DESC textureDesc;
	textureDesc.Width = width;
	textureDesc.Height = height;
	textureDesc.MipLevels = 1;
	textureDesc.ArraySize = 1;
	textureDesc.Format = DXGI_FORMAT_D24_UNORM_S8_UINT;
	textureDesc.SampleDesc.Count = 1;
	textureDesc.SampleDesc.Quality = 0;
	textureDesc.Usage = D3D11_USAGE_DEFAULT;
	textureDesc.BindFlags = D3D11_BIND_RENDER_TARGET;
	textureDesc.CPUAccessFlags = 0;
	textureDesc.MiscFlags = 0;

	//create texture
	if (FAILED(device->CreateTexture2D(&textureDesc, nullptr, texture.ReleaseAndGetAddressOf()))) throw::std::runtime_error("RenderTargetD3D11::Initialize - failed to create texture2D");

	//Create RTV
	if (FAILED(device->CreateRenderTargetView(texture.Get(), nullptr, rtv.ReleaseAndGetAddressOf()))) throw::std::runtime_error("RenderTargetD3D11::Initialize - failed to create RTV");
}

ID3D11RenderTargetView* RenderTargetD3D11::GetRTV() const
{
	return rtv.Get();
}