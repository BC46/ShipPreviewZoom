#define WIN32_LEAN_AND_MEAN
#include <windows.h>

#define SHIP_PREVIEW_SCROLL_ADDR ( (PDWORD) 0x5E4C14 )

struct ShipPreviewWindow
{
    BYTE x00[0x3EC];
    float zoomLevel;
};
