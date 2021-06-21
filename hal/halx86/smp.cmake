
list(APPEND HAL_SMP_SOURCE
    generic/buildtype.c
    generic/spinlock.c
    smp/smp.c
    smp/ipi.c)

if(ARCH STREQUAL "i386")
    list(APPEND HAL_SMP_ASM_SOURCE
        smp/i386/apentry.S
        smp/i386/apspinup.S)

elseif(ARCH STREQUAL "amd64")
    list(APPEND HAL_SMP_ASM_SOURCE
        smp/amd64/apentry.S
        smp/amd64/apspinup.S)
endif()

add_library(lib_hal_smp OBJECT ${HAL_SMP_SOURCE})
add_dependencies(lib_hal_smp bugcodes xdk)
target_compile_definitions(lib_hal_smp PRIVATE CONFIG_SMP)
