
add_definitions(-D_NTHAL_ -D_BLDR_ -D_NTSYSTEM_)

list(APPEND BOOTMGR_BASE_SOURCE
        efiloader/entry.c
    )

add_executable(reactosefi ${BOOTMGR_BASE_SOURCE})
set_target_properties(reactosefi PROPERTIES SUFFIX ".efi")

if(MSVC)
    if(ARCH STREQUAL "arm" OR ARCH STREQUAL "arm64")
        target_link_options(reactosefi PRIVATE /ignore:4078 /ignore:4254 /DRIVER)
    else()
        target_link_options(reactosefi PRIVATE /ignore:4078 /ignore:4254 /DRIVER /DYNAMICBASE:NO /NXCOMPAT:NO /FIXED)
    endif()
else()
    target_link_options(reactosefi PRIVATE "-Wl,--strip-all,--exclude-all-symbols")
endif()

set_image_base(reactosefi 0x10000)

if(MSVC)
    set_subsystem(reactosefi EFI_APPLICATION)
else()
    set_subsystem(reactosefi 10)
endif()

set_entrypoint(reactosefi EfiEntry)

target_link_libraries(reactosefi cportlib cmlib rtl libcntpr)

# dynamic analysis switches
if(STACK_PROTECTOR)
    target_sources(reactosefi PRIVATE $<TARGET_OBJECTS:gcc_ssp_nt>)
endif()

if(RUNTIME_CHECKS)
    target_link_libraries(reactosefi runtmchk)
endif()

add_cd_file(TARGET reactosefi DESTINATION efi/boot/ NO_CAB FOR all)
