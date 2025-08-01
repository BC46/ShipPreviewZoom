#include "Common.h"
#include "Freelancer.h"
#include "Utils.h"

// The shims themselves technically don't use the parameters, so temporarily disable the warning.
#pragma warning( push )
#pragma warning( disable: 4100 )

STDCALL_TO_THISCALL_SHIM
(
    INI_Reader* WINAPI  INI_Reader_constructor( INI_Reader* this ),
    dword ptr ds:[INI_READER_CONSTRUCTOR_IMPORT_ADDR]
)

STDCALL_TO_THISCALL_SHIM
(
    void WINAPI         INI_Reader_destructor( INI_Reader* this ),
    dword ptr ds:[INI_READER_DESTRUCTOR_IMPORT_ADDR]
)

STDCALL_TO_THISCALL_SHIM
(
    BOOLEAN WINAPI      INI_Reader_open( INI_Reader* this, LPCSTR path, BOOLEAN throwExceptionOnFail ),
    dword ptr ds:[INI_READER_OPEN_IMPORT_ADDR]
)

STDCALL_TO_THISCALL_SHIM
(
    BOOLEAN WINAPI      INI_Reader_read_header( INI_Reader* this ),
    dword ptr ds:[INI_READER_READ_HEADER_IMPORT_ADDR]
)

STDCALL_TO_THISCALL_SHIM
(
    BOOLEAN WINAPI      INI_Reader_is_header( INI_Reader* this, LPCSTR name ),
    dword ptr ds:[INI_READER_IS_HEADER_IMPORT_ADDR]
)

STDCALL_TO_THISCALL_SHIM
(
    BOOLEAN WINAPI      INI_Reader_read_value( INI_Reader* this ),
    dword ptr ds:[INI_READER_READ_VALUE_IMPORT_ADDR]
)

STDCALL_TO_THISCALL_SHIM
(
    BOOLEAN WINAPI      INI_Reader_is_value( INI_Reader* this, LPCSTR name ),
    dword ptr ds:[INI_READER_IS_VALUE_IMPORT_ADDR]
)

STDCALL_TO_THISCALL_SHIM
(
    BOOLEAN WINAPI      INI_Reader_get_value_bool( INI_Reader* this, UINT index ),
    dword ptr ds:[INI_READER_GET_VALUE_BOOL_IMPORT_ADDR]
)

STDCALL_TO_THISCALL_SHIM
(
    float WINAPI        INI_Reader_get_value_float( INI_Reader* this, UINT index ),
    dword ptr ds:[INI_READER_GET_VALUE_FLOAT_IMPORT_ADDR]
)

STDCALL_TO_THISCALL_SHIM
(
    void WINAPI         INI_Reader_close( INI_Reader* this ),
    dword ptr ds:[INI_READER_CLOSE_IMPORT_ADDR]
)

#pragma warning( pop )
