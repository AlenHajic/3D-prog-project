#include "InputLayoutD3D11.h"

InputLayoutD3D11::~InputLayoutD3D11() {}

void InputLayoutD3D11::AddInputElement(const std::string& semanticName, DXGI_FORMAT format)
{
	semanticNames.push_back(semanticName);

	D3D11_INPUT_ELEMENT_DESC desc =
	{
		desc.SemanticName = nullptr,
		desc.SemanticIndex = 0,
		desc.Format = format,
		desc.InputSlot = 0,
		desc.AlignedByteOffset = D3D11_APPEND_ALIGNED_ELEMENT, //auto align by correct offset?
		desc.InputSlotClass = D3D11_INPUT_PER_VERTEX_DATA,
		desc.InstanceDataStepRate = 0
	};

	elements.push_back(desc);
}

void InputLayoutD3D11::FinalizeInputLayout(ID3D11Device* device, const void* vsDataPtr, size_t vsDataSize)
{

}

ID3D11InputLayout* InputLayoutD3D11::GetInputLayout() const
{
	return nullptr;
}
