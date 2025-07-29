#include "Freelancer.h"
#include "utils.h"

BOOLEAN WINAPI ShipPreviewScrollHook( struct ShipPreviewWindow* this, int scrollValue )
{
    UNREFERENCED_PARAMETER( this );
    UNREFERENCED_PARAMETER( scrollValue );

    return FALSE;
}

THISCALL_TO_STDCALL_FUNC( void ShipPreviewScrollEntry(), ShipPreviewScrollHook )

void Init( void )
{
    DWORD lpflOldProtect;

    VirtualProtect( SHIP_PREVIEW_SCROLL_ADDR, sizeof( PDWORD ), PAGE_READWRITE, &lpflOldProtect);
    *SHIP_PREVIEW_SCROLL_ADDR = (DWORD) ShipPreviewScrollEntry;
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
