
#include <stdint.h>
#include <string>

#ifdef _USRDLL
#define DLLEXPORT extern "C" __declspec(dllexport)
#else
#define DLLEXPORT extern "C" __declspec(dllimport)
#endif

extern void *(*ExternalAlloc)(size_t size);

class ReturnString {
public:
	ReturnString(const char *str);
	ReturnString(std::string str);

	char *m_string;
};

struct HookFuncs {
	ReturnString (*GetLocalizedString)(uint8_t language, const char *key, const char *defaultString);
	void (*TextureLoaded)(const char *textureName, uint8_t **mipLevels, uint8_t numMipLevels, uint32_t dxgiFormat, uint32_t width, uint32_t height, uint32_t texturePitch);
	ReturnString (*LevelFileLoaded)(uint8_t area, uint8_t level, uint8_t theme, const char *levelFileName, const char *defaultLevel);
	void (*NewGameStarted)(uint8_t &area, uint8_t &level, uint8_t &theme);
	void (*NewLevelStarted)(uint8_t &area, uint8_t &level, uint8_t &theme);
};

DLLEXPORT void GetHookFuncsEntry(void *(*ExternalAlloc)(size_t), HookFuncs *hookFuncs);
