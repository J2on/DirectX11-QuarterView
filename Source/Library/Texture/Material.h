#pragma once
#include "Common.h"
#include "Texture.h"



class Material {
public:
	std::shared_ptr<Texture> pDiffuse;
	std::shared_ptr<Texture> pSpecular;
	XMFLOAT3 AmbientColor;
	XMFLOAT3 DiffuseColor;
	XMFLOAT3 SpecularColor; 

	Material();
	~Material();
};