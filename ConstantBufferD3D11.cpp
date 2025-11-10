#include "ConstantBufferD3D11.h"

ConstantBufferD3D11::ConstantBufferD3D11(ID3D11Device* device, size_t byteSize, void* initialData) : bufferSize(byteSize)
{
	D3D11_BUFFER_DESC bufferDesc = {
		bufferDesc.ByteWidth = static_cast<UINT>(byteSize), //byter på ett säkert sätt från size_t till UINT
		bufferDesc.Usage = D3D11_USAGE_DYNAMIC, //what should this be?
		bufferDesc.BindFlags = D3D11_BIND_CONSTANT_BUFFER,
		bufferDesc.CPUAccessFlags = D3D11_CPU_ACCESS_WRITE, //what shoudl this be? 
		bufferDesc.MiscFlags = 0,
		bufferDesc.StructureByteStride = 0,
	};

	//fill in desc
	//fill in subresource data, aka initial data
	//check "did we manage to create constantbuffer? if not throw exception"
}

ConstantBufferD3D11::~ConstantBufferD3D11()
{
}

ConstantBufferD3D11::ConstantBufferD3D11(ConstantBufferD3D11&& other) noexcept
{
}

ConstantBufferD3D11& ConstantBufferD3D11::operator=(ConstantBufferD3D11&& other) noexcept
{
	// TODO: insert return statement here
}

void ConstantBufferD3D11::Initialize(ID3D11Device* device, size_t byteSize, void* initialData)
{
}

size_t ConstantBufferD3D11::GetSize() const
{
	return size_t();
}

ID3D11Buffer* ConstantBufferD3D11::GetBuffer() const
{
	return nullptr;
}

void ConstantBufferD3D11::UpdateBuffer(ID3D11DeviceContext* context, void* data)
{
}
