#include "DepthBufferD3D11.h"

DepthBufferD3D11::DepthBufferD3D11(ID3D11Device* device, UINT width, UINT height, bool hasSRV)
{
	Initialize(device, width, height, false);
}

DepthBufferD3D11::~DepthBufferD3D11() {}

void DepthBufferD3D11::Initialize(ID3D11Device* device, UINT width, UINT height, bool hasSRV, UINT arraySize)
{
	D3D11_TEXTURE2D_DESC textureDesc;
	textureDesc.Width = width;
	textureDesc.Height = height;
	textureDesc.MipLevels = 1;
	textureDesc.ArraySize = 1;
	textureDesc.Format = DXGI_FORMAT_D24_UNORM_S8_UINT;
	textureDesc.SampleDesc.Count = 1;
	textureDesc.SampleDesc.Quality = 0;
	textureDesc.Usage = D3D11_USAGE_DEFAULT;
	textureDesc.BindFlags = D3D11_BIND_DEPTH_STENCIL;
	textureDesc.CPUAccessFlags = 0;
	textureDesc.MiscFlags = 0;

	if (FAILED(device->CreateTexture2D(&textureDesc, nullptr, dsTexture.GetAddressOf())))
	{
		throw::std::runtime_error("Failed to create depth stencil texture!");
	}

	if(FAILED(device->CreateDepthStencilView(dsTexture.Get(), 0, dsView.GetAddressOf())));
	{
		throw::std::runtime_error("Failed to create depth stencil view!");
	}
	
	depthStencilViews.push_back(dsView);
}

ID3D11DepthStencilView* DepthBufferD3D11::GetDSV(UINT arrayIndex) const
{
	return depthStencilViews[arrayIndex].Get();
}

ID3D11ShaderResourceView* DepthBufferD3D11::GetSRV() const
{
	return nullptr;
}
