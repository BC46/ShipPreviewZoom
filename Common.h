#ifndef _COMMON_H_
#define _COMMON_H_

#define WIN32_LEAN_AND_MEAN
#include <windows.h>

struct INI_Reader
{
    BYTE x00[0x1565];
};

void WINAPI     INI_Reader_constructor( struct INI_Reader* this );
void WINAPI     INI_Reader_destructor( struct INI_Reader* this );
BOOLEAN WINAPI  INI_Reader_open( struct INI_Reader* this, LPCSTR path, BOOLEAN throwExceptionOnFail );
BOOLEAN WINAPI  INI_Reader_read_header( struct INI_Reader* this );
BOOLEAN WINAPI  INI_Reader_is_header( struct INI_Reader* this, LPCSTR name );
BOOLEAN WINAPI  INI_Reader_read_value( struct INI_Reader* this );
BOOLEAN WINAPI  INI_Reader_is_value( struct INI_Reader* this, LPCSTR name );
BOOLEAN WINAPI  INI_Reader_get_value_bool( struct INI_Reader* this, UINT index );
float WINAPI    INI_Reader_get_value_float( struct INI_Reader* this, UINT index );
void WINAPI     INI_Reader_close( struct INI_Reader* this );

#endif
