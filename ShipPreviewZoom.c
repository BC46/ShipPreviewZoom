#include "Freelancer.h"
#include "utils.h"

BOOLEAN WINAPI ShipPreviewScrollHook( struct ShipPreviewWindow* this, int scrollValue )
{
    this->zoomLevel += (float) scrollValue;

    return FALSE;
}

THISCALL_TO_STDCALL_SHIM( void ShipPreviewScrollShim(), ShipPreviewScrollHook )

void Init( void )
{
    DWORD lpflOldProtect;

    VirtualProtect( SHIP_PREVIEW_SCROLL_ADDR, sizeof( PDWORD ), PAGE_READWRITE, &lpflOldProtect);
    *SHIP_PREVIEW_SCROLL_ADDR = (DWORD) ShipPreviewScrollShim;
}

BOOL WINAPI DllMain( HINSTANCE hinstDLL, DWORD fdwReason, LPVOID lpReserved )
{
    UNREFERENCED_PARAMETER(hinstDLL);
    UNREFERENCED_PARAMETER(lpReserved);

	if ( fdwReason == DLL_PROCESS_ATTACH )
    {
        Init();
    }

    return TRUE;
}
