#include "ConstantBufferD3D11.h"

ConstantBufferD3D11::ConstantBufferD3D11(ID3D11Device* device, size_t byteSize, void* initialData) : bufferSize(byteSize)
{
	//fill in desc
	D3D11_BUFFER_DESC bufferDesc = {
		bufferDesc.ByteWidth = static_cast<UINT>(byteSize), //byter på ett säkert sätt från size_t till UINT
		bufferDesc.Usage = D3D11_USAGE_IMMUTABLE, //what should this be?
		bufferDesc.BindFlags = D3D11_BIND_CONSTANT_BUFFER,
		bufferDesc.CPUAccessFlags = 0, //what shoudl this be? 
		bufferDesc.MiscFlags = 0,
		bufferDesc.StructureByteStride = 0,
	};

	//fill in subresource data, aka initial data
	D3D11_SUBRESOURCE_DATA data = {
		data.pSysMem = initialData,
		data.SysMemPitch = 0,
		data.SysMemSlicePitch = 0,
	};
	//check "did we manage to create constantbuffer? if not throw exception"
	HRESULT hr = device->CreateBuffer(&bufferDesc, &data, &this->buffer); //do we need to account for intialdata to be nullptr? Same for buffer
	if (FAILED(hr))
	{
		std::cerr << "Error creating constant buffer! (VS)" << std::endl;
		throw::std::runtime_error("failed to create constantbuffer");
	}
}

ConstantBufferD3D11::~ConstantBufferD3D11() {}

ConstantBufferD3D11::ConstantBufferD3D11(ConstantBufferD3D11&& other) noexcept
{
	this->buffer = other.buffer;
	this->bufferSize = other.bufferSize;
}

ConstantBufferD3D11& ConstantBufferD3D11::operator=(ConstantBufferD3D11&& other) noexcept //why double &&
{
	//check if this object(our object) is equal to the other object
	if (this != &other) {
		this->buffer = std::move(other.buffer); //we transfer ownership of the buffer from other to our object, do we need this?

	}
}

void ConstantBufferD3D11::Initialize(ID3D11Device* device, size_t byteSize, void* initialData)
{
	//fill in desc
	D3D11_BUFFER_DESC bufferDesc = {
		bufferDesc.ByteWidth = static_cast<UINT>(byteSize), //byter på ett säkert sätt från size_t till UINT
		bufferDesc.Usage = D3D11_USAGE_DYNAMIC, //what should this be?
		bufferDesc.BindFlags = D3D11_BIND_CONSTANT_BUFFER,
		bufferDesc.CPUAccessFlags = D3D11_CPU_ACCESS_WRITE, //what shoudl this be? 
		bufferDesc.MiscFlags = 0,
		bufferDesc.StructureByteStride = 0,
	};

	//fill in subresource data, aka initial data
	D3D11_SUBRESOURCE_DATA data = {
		data.pSysMem = initialData,
		data.SysMemPitch = 0,
		data.SysMemSlicePitch = 0,
	};
	//check "did we manage to create constantbuffer? if not throw exception"
	HRESULT hr = device->CreateBuffer(&bufferDesc, &data, &this->buffer);
	if (FAILED(hr))
	{
		std::cerr << "Error creating constant buffer! (VS)" << std::endl;
		throw::std::runtime_error("failed to create constantbuffer");
	}
}

size_t ConstantBufferD3D11::GetSize() const
{
	return this->bufferSize;
}

ID3D11Buffer* ConstantBufferD3D11::GetBuffer() const
{
	return this->buffer.Get();
}

void ConstantBufferD3D11::UpdateBuffer(ID3D11DeviceContext* context, void* data)
{
	//memcpy?
}
