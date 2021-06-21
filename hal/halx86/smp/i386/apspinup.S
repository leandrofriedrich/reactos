#include <asm.inc>

PUBLIC _APSpinup
PUBLIC _APSpinupEnd

.code32
_APSpinup:
    mov   ax, HEX(10)
    mov   ds, ax
    mov   es, ax
    mov   ss, ax
    mov   fs, ax

    /* We hlt here until the next PR */
    hlt
_APSpinupEnd:
END
