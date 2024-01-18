#pragma once

#include "Common.h"


class Texture {
private:
	std::filesystem::path m_filePath;
	ComPtr<ID3D11ShaderResourceView> m_textureRV;
	ComPtr<ID3D11SamplerState> m_samplerLinear;
	
public:
	Texture(const std::filesystem::path&);
	~Texture();
	HRESULT Initialize(ID3D11Device*, ID3D11DeviceContext*);
	ComPtr<ID3D11ShaderResourceView>& GetTextureResourceView();
	ComPtr<ID3D11SamplerState>& GetSamplerState();
};