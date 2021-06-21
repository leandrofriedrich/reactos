#include <asm.inc>

PUBLIC _APEntry
PUBLIC _APEntryEnd


_APEntry:
    cli
    hlt
_APEntryEnd
END