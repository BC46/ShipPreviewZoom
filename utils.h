#define NAKED __declspec(naked)

#define THISCALL_TO_STDCALL_FUNC(func, addr) \
    NAKED func \
    { \
        __asm pop eax \
        __asm push ecx \
        __asm push eax \
        __asm lea edx, [addr] \
        __asm jmp edx \
    }
