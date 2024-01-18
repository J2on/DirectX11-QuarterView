#pragma once
#include "Common.h"
#include "Renderable.h"

struct aiScene;
struct aiMesh;
struct aiMaterial;

class Model : public Renderable {
protected:
	std::filesystem::path m_filePath;
	std::vector<SimpleVertex> m_aVertices;
	std::vector<WORD> m_aIndices;
public:
	Model(_In_ const std::filesystem::path& filePath);
	Model() = default;
	~Model() = default;
	virtual HRESULT Initialize(_In_ ID3D11Device* pDevice, _In_ ID3D11DeviceContext* pImmediateContext);
	void Update(_In_ FLOAT deltaTime);

	UINT GetNumVertices() const override;
	UINT GetNumIndices() const override;
protected:
	void countVerticesAndIndices(_Inout_ UINT& uOutNumVertices, _Inout_ UINT& uOutNumIndices, _In_ const aiScene* pScene);
	const SimpleVertex* getVertices() const override;
	const WORD* getIndices() const override;
	
	void initAllMeshes(_In_ const aiScene* pScene);
	HRESULT initFromScene(_In_ ID3D11Device* pDevice, _In_ ID3D11DeviceContext* pImmediateContext, _In_ const aiScene* pScene, _In_ const std::filesystem::path& filePath);
	HRESULT initMaterials(_In_ ID3D11Device* pDevice, _In_ ID3D11DeviceContext* pImmediateContext, _In_ const aiScene* pScene, _In_ const std::filesystem::path& filePath);
	void initSingleMesh(_In_ const aiMesh* pMesh);
	void loadColors(_In_ const aiMaterial* pMaterial, _In_ UINT uIndex);
	HRESULT loadDiffuseTexture(ID3D11Device*, ID3D11DeviceContext* pImmediateContext, const std::filesystem::path&, const aiMaterial*, UINT);
	HRESULT loadSpecularTexture(_In_ ID3D11Device* pDevice, _In_ ID3D11DeviceContext* pImmediateContext, _In_ const std::filesystem::path& parentDirectory, _In_ const aiMaterial* pMaterial, _In_ UINT uIndex);
	HRESULT loadTextures(_In_ ID3D11Device* pDevice, _In_ ID3D11DeviceContext* pImmediateContext, _In_ const std::filesystem::path& parentDirectory, _In_ const aiMaterial* pMaterial, _In_ UINT uIndex);
	void reserveSpace(_In_ UINT uNumVertices, _In_ UINT uNumIndices);
};