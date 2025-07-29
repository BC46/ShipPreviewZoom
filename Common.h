#ifndef _COMMON_H_
#define _COMMON_H_

#define WIN32_LEAN_AND_MEAN
#include <windows.h>

typedef struct INI_Reader
{
    BYTE x00[0x1565];
} INI_Reader;

void WINAPI     INI_Reader_constructor( INI_Reader* this );
void WINAPI     INI_Reader_destructor( INI_Reader* this );
BOOLEAN WINAPI  INI_Reader_open( INI_Reader* this, LPCSTR path, BOOLEAN throwExceptionOnFail );
BOOLEAN WINAPI  INI_Reader_read_header( INI_Reader* this );
BOOLEAN WINAPI  INI_Reader_is_header( INI_Reader* this, LPCSTR name );
BOOLEAN WINAPI  INI_Reader_read_value( INI_Reader* this );
BOOLEAN WINAPI  INI_Reader_is_value( INI_Reader* this, LPCSTR name );
BOOLEAN WINAPI  INI_Reader_get_value_bool( INI_Reader* this, UINT index );
float WINAPI    INI_Reader_get_value_float( INI_Reader* this, UINT index );
void WINAPI     INI_Reader_close( INI_Reader* this );

#endif
