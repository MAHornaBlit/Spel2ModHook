
#include "Spel2ModTools.h"

void *(*ExternalAlloc)(size_t size) = NULL;

void GetHookFuncs(HookFuncs *hookFuncs);

ReturnString::ReturnString(const char *str) {
	size_t size = strlen(str) + 1;
	m_string = (char*)ExternalAlloc(size);
	memcpy(m_string, str, size);
}

ReturnString::ReturnString(std::string str) {
	size_t size = str.size() + 1;
	m_string = (char*)ExternalAlloc(size);
	memcpy(m_string, str.c_str(), size);
}

void GetHookFuncsEntry(void *(*_ExternalAlloc)(size_t), HookFuncs *hookFuncs) {
	ExternalAlloc = _ExternalAlloc;

	GetHookFuncs(hookFuncs);
}
