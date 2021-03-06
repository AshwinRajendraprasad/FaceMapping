#ifndef __SAMPLE_UTIL__
#define __SAMPLE_UTIL__

#include <D3D11.h>
#include <string>
#include "cput.h"
#include "CPUT.h"

#ifndef DISABLE_RSSDK
#include "pxcimage.h"
#endif // #ifndef DISABLE_RSSDK

struct SCodeTextureWrap
{
	ID3D11Texture2D *Texture;
	ID3D11Resource *Resource;
	ID3D11ShaderResourceView *SRV;
	D3D11_TEXTURE2D_DESC Desc;
};

bool TextureWrap_Init(SCodeTextureWrap* wrap, D3D11_TEXTURE2D_DESC *desc);
bool TextureWrap_AdjustSize(SCodeTextureWrap* wrap, int width, int height);
void TextureWrap_Release(SCodeTextureWrap* wrap);

#ifndef DISABLE_RSSDK
void CopyPXCImageToTexture(PXCImage *srcImage, SCodeTextureWrap *dstTexture);
#endif // #ifndef DISABLE_RSSDK

const std::string &GetUserDataDirectory();
const std::string &GetMyAssetsDirectory();

void DebugPrintf(char *fmt, ...);

void DebugPrintBeginFileCapture( const char *filename);
void DebugPrintEndFileCapture();

class ProfileBlockScoped
{
public:
	ProfileBlockScoped( std::string blockName );
	~ProfileBlockScoped();
private:
	uint64 mStartTime;
	std::string mBlockName;
};

void SampleUtil_Init();


void SetCodeTexture(int index, ID3D11ShaderResourceView *srv);
void SetCodeTexture(int index, SCodeTextureWrap *texture);

class CPUTMaterial;
CPUTMaterial *GetCodeSpriteMaterial();
CPUTMaterial *GetMeshPreviewMaterial();

class CPUTModel;
CPUTModel *LoadObjAsCPUTModel(const char *objFilename);


void DrawCube(CPUTRenderParameters &renderParams, float3 position, float size, CPUTColor4 color);
void DrawBox(CPUTRenderParameters &renderParams, float3 position, float3 size, CPUTColor4 color);

#endif