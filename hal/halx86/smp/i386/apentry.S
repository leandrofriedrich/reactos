
#include <asm.inc>

PUBLIC _APEntry
PUBLIC _APEntryEnd

.code16
_APEntry:
    cli
    hlt
_APEntryEnd
END