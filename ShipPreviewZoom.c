#define WIN32_LEAN_AND_MEAN
#include <windows.h>

#define SHIP_PREVIEW_ZOOM_OFFSET ((PBYTE) 0x5855C8)

void ApplyPatch( void )
{
    float newZoomOffset = 5;

    //shipmesh
    DWORD _;
    VirtualProtect( SHIP_PREVIEW_ZOOM_OFFSET, sizeof(float), PAGE_READWRITE, &_ );
    memcpy( SHIP_PREVIEW_ZOOM_OFFSET, &newZoomOffset, sizeof( float ) );
}

BOOL WINAPI DllMain( HINSTANCE hinstDLL, DWORD fdwReason, LPVOID lpReserved )
{
    UNREFERENCED_PARAMETER(hinstDLL);
    UNREFERENCED_PARAMETER(lpReserved);

	if ( fdwReason == DLL_PROCESS_ATTACH )
    {
        ApplyPatch();
    }

    return TRUE;
}
