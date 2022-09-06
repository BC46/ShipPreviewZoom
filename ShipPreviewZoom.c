#include <windows.h>

#define SHIP_PREVIEW_ZOOM_OFFSET ((PBYTE)0x5855C8)

DWORD _;

void ApplyPatch() {
	float newZoomOffset = 5;

	//shipmesh
	VirtualProtect(SHIP_PREVIEW_ZOOM_OFFSET, sizeof(float), PAGE_READWRITE, &_);
	memcpy(SHIP_PREVIEW_ZOOM_OFFSET, &newZoomOffset, sizeof(float));
}

BOOL WINAPI DllMain(HINSTANCE hinstDLL, DWORD fdwReason, LPVOID lpReserved) {
	if (fdwReason == DLL_PROCESS_ATTACH)
		ApplyPatch();
	
	return TRUE;
}