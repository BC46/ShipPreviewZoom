#define NAKED __declspec(naked)

// Defines a shim that converts the calling convention from __thiscall to __stdcall and then jumps to `addr`.
#define THISCALL_TO_STDCALL_SHIM(func, addr) \
    NAKED func \
    { \
        __asm pop eax \
        __asm push ecx \
        __asm push eax \
        __asm jmp addr \
    }

// Defines a shim that converts the calling convention from __stdcall to __thiscall and then jumps to `addr`.
#define STDCALL_TO_THISCALL_SHIM(func, addr) \
    NAKED func \
    { \
        __asm pop eax \
        __asm pop ecx \
        __asm push eax \
        __asm mov eax, addr \
        __asm jmp eax \
    }
