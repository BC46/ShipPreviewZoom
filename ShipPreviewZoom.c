#include "Freelancer.h"
#include "Common.h"
#include "Utils.h"

float g_scrollingSpeed = 3.0f;
float g_minDistance = 0.0f;
float g_maxDistance = 100.0f;
BOOLEAN g_inverse = FALSE;

void ReadConfig( void )
{
    INI_Reader reader;
    INI_Reader_constructor( &reader );

    if ( !INI_Reader_open( &reader, "ShipPreviewZoom.ini", FALSE ) )
    {
        return;
    }

    while ( INI_Reader_read_header( &reader ) )
    {
        if ( !INI_Reader_is_header( &reader, "Options" ) )
        {
            continue;
        }

        while ( INI_Reader_read_value( &reader ) )
        {
            if ( INI_Reader_is_value( &reader, "scrolling_speed" ) )
            {
                g_scrollingSpeed = INI_Reader_get_value_float( &reader, 0 );
            }
            else if ( INI_Reader_is_value( &reader, "min_distance" ) )
            {
                g_minDistance = INI_Reader_get_value_float( &reader, 0 );
            }
            else if ( INI_Reader_is_value( &reader, "max_distance" ) )
            {
                g_maxDistance = INI_Reader_get_value_float( &reader, 0 );
            }
            else if ( INI_Reader_is_value( &reader, "inverse" ) )
            {
                g_inverse = INI_Reader_get_value_bool( &reader, 0 );
            }
        }
    }

    INI_Reader_close( &reader );
    INI_Reader_destructor( &reader );
}

BOOLEAN WINAPI ShipPreview_ScrollHook( ShipTrader3DShip* this, int scrollValue )
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
