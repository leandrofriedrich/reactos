#include <asm.inc>

PUBLIC _APSpinup
PUBLIC _APSpinupEnd

EXTERN _APEntry:DWORD
EXTERN _APEntryEnd:DWORD

.code32
_APSpinup:
    mov   ax, HEX(10)
    mov   ds, ax
    mov   es, ax
    mov   ss, ax
    mov   fs, ax

    xor eax, eax
    mov eax, (HEX(4082))
    mov cr3, eax

    mov   eax, cr0
    hlt
    or    eax, HEX(80000000)
    mov   cr0, eax
    
_APSpinupEnd:
END
