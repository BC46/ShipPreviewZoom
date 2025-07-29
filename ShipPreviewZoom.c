#include "Freelancer.h"
#include "Common.h"
#include "Utils.h"

void ReadConfig( void )
{
    struct INI_Reader reader;

    INI_Reader_constructor( &reader );
}

BOOLEAN WINAPI ShipPreview_ScrollHook( struct ShipTrader3DShip* this, int scrollValue )
{
    this->zoomLevel += (float) scrollValue;

    return FALSE;
}

THISCALL_TO_STDCALL_SHIM( void ShipPreview_ScrollShim(), ShipPreview_ScrollHook )

void InitHooks( void )
{
    DWORD oldProtect;

    VirtualProtect( SHIP_PREVIEW_SCROLL_ADDR, sizeof( PDWORD ), PAGE_READWRITE, &oldProtect);
    *SHIP_PREVIEW_SCROLL_ADDR = (DWORD) ShipPreview_ScrollShim;
}

BOOL WINAPI DllMain( HINSTANCE hinstDLL, DWORD fdwReason, LPVOID lpReserved )
{
    UNREFERENCED_PARAMETER(hinstDLL);
    UNREFERENCED_PARAMETER(lpReserved);

    if ( fdwReason == DLL_PROCESS_ATTACH )
    {
        ReadConfig();
        InitHooks();
    }

    return TRUE;
}
