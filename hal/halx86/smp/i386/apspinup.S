#include <asm.inc>

PUBLIC _APSpinup
PUBLIC _APSpinupEnd

.code32
_APSpinup:
    mov eax, HEX(DEADBEEF)
    hlt  
_APSpinupEnd:
END
