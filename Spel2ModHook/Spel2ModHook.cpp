
#include "Spel2ModHook.h"

#define DXGI_FORMAT_R8G8B8A8_UNORM 28
#define DXGI_FORMAT_R8_UNORM 61
#define DXGI_FORMAT_B8G8R8A8_UNORM 87

ReturnString GetLocalizedString(uint8_t language, const char *key, const char *defaultString) {
	return defaultString;
}

void TextureLoaded(const char *textureName, uint8_t **mipLevels, uint8_t numMipLevels, uint32_t dxgiFormat, uint32_t width, uint32_t height, uint32_t texturePitch) {
}

ReturnString LevelFileLoaded(uint8_t area, uint8_t level, uint8_t theme, const char *levelFileName, const char *defaultLevel) {
	return defaultLevel;
}

void NewGameStarted(uint8_t &area, uint8_t &level, uint8_t &theme) {
}

void NewLevelStarted(uint8_t &area, uint8_t &level, uint8_t &theme) {
}

void GetHookFuncs(HookFuncs *hookFuncs) {
	hookFuncs->GetLocalizedString = &GetLocalizedString;
	hookFuncs->TextureLoaded = &TextureLoaded;
	hookFuncs->LevelFileLoaded = &LevelFileLoaded;
	hookFuncs->NewGameStarted = &NewGameStarted;
	hookFuncs->NewLevelStarted = &NewLevelStarted;
}
