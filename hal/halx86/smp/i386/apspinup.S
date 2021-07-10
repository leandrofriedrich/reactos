  #include <asm.inc>

PUBLIC _APSpinup
PUBLIC _APSpinupEnd

EXTERN _APEntry:DWORD
EXTERN _APEntryEnd:DWORD

.code32
_APSpinup:
    mov   bx, HEX(10)
    mov   ds, bx
    mov   es, bx
    mov   ss, bx
    mov   fs, bx

    mov   eax, cr0
    or    eax, HEX(80000000)
    mov   cr0, eax
  
    hlt
_APSpinupEnd:
END