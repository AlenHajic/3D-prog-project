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
		desc.AlignedByteOffset = elements.empty() ? 0 : D3D11_APPEND_ALIGNED_ELEMENT, //om tom sätt 0 i affset annars sätt auto align by correct offset?
		desc.InputSlotClass = D3D11_INPUT_PER_VERTEX_DATA,
		desc.InstanceDataStepRate = 0
	};

	semanticNames.push_back(semanticName);
	elements.push_back(desc);
}

void InputLayoutD3D11::FinalizeInputLayout(ID3D11Device* device, const void* vsDataPtr, size_t vsDataSize)
{
	if (!device) throw::std::runtime_error("Inputlayout finalize - device is null");
	if (!vsDataPtr || vsDataPtr == 0) throw::std::runtime_error("Inputlayout finalize - vsData invalid");
	if (elements.size() != semanticNames.size()) throw::std::runtime_error("Inputlayout finalize - vectors mismatch");


	for (int i = 0; i < elements.size(); i++)
	{
		elements[i].SemanticName = semanticNames[i].c_str();
	}

	if (FAILED(device->CreateInputLayout(elements.data(), static_cast<UINT>(elements.size()), vsDataPtr, vsDataSize, inputLayout.ReleaseAndGetAddressOf()))) throw::std::runtime_error("Inputlayout finalize - failed to create inputlayout");
}																													 //release old data, give it new one?

ID3D11InputLayout* InputLayoutD3D11::GetInputLayout() const
{
	return this->inputLayout.Get();
}
