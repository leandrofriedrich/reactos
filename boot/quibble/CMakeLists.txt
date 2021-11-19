
add_definitions(-D_NTHAL_ -D_BLDR_ -D_NTSYSTEM_)

list(APPEND BOOTMGR_BASE_SOURCE
        src/apiset.c
        src/boot.c
        src/debug.c
        src/hw.c
        src/mem.c
        src/menu.c
        src/misc.c
        src/peload.c
        src/print.c
        src/reg.c
        src/tinymt32.c
    )

add_executable(quibble ${BOOTMGR_BASE_SOURCE})
set_target_properties(quibble PROPERTIES SUFFIX ".efi")

if(MSVC)
    if(ARCH STREQUAL "arm" OR ARCH STREQUAL "arm64")
        target_link_options(quibble PRIVATE /ignore:4078 /ignore:4254 /DRIVER)
    else()
        target_link_options(quibble PRIVATE /ignore:4078 /ignore:4254 /DRIVER /DYNAMICBASE:NO /NXCOMPAT:NO /FIXED)
    endif()
else()
    target_link_options(quibble PRIVATE "-Wl,--strip-all,--exclude-all-symbols")
endif()

set_image_base(quibble 0x10000)

if(MSVC)
    set_subsystem(quibble EFI_APPLICATION)
else()
    set_subsystem(quibble 10)
endif()

include_directories(gnu-efi)
if (ARCH STREQUAL "AMD64")
    include_directories(gnu-efi/x86_64)
elseif (ARCH STREQUAL "x86")
    include_directories(gnu-efi/ia32)
elseif (ARCH STREQUAL "arm" OR ARCH STREQUAL "arm64")
    include_directories(gnu-efi/aarch64)
endif()

set_entrypoint(quibble EfiEntry)
target_link_libraries(quibble freetype)
add_cd_file(TARGET quibble DESTINATION efi/boot/ NO_CAB FOR all)
