#define SHIP_PREVIEW_ZOOM_OFFSET ((PBYTE)0x5855C8)

#include <windows.h>

DWORD _;

void Patch() {
	VirtualProtect(SHIP_PREVIEW_ZOOM_OFFSET, 4, PAGE_READWRITE, &_);

	*SHIP_PREVIEW_ZOOM_OFFSET = 0x0000;
}

BOOL WINAPI DllMain(HINSTANCE hinstDLL, DWORD fwdReason, LPVOID lpReserved) {
	if (fwdReason == DLL_PROCESS_ATTACH)
		Patch();
	
	return TRUE;
}