
add_definitions(-D_NTHAL_ -D_BLDR_ -D_NTSYSTEM_)

include_directories(BEFORE include)
include_directories(${REACTOS_SOURCE_DIR}/ntoskrnl/include)
include_directories(${REACTOS_SOURCE_DIR}/sdk/lib/cmlib)
include_directories(${REACTOS_SOURCE_DIR}/sdk/include/reactos/libs)

function(add_target _boardname)
    cmake_parse_arguments(_boarddata "" "" "SOURCES;COMPONENTS" ${ARGN})

    # Create the actual target
    foreach(_component ${_boarddata_COMPONENTS})
        list(APPEND _boarddata_SOURCES "$<TARGET_OBJECTS:lib_board_${_component}>")
    endforeach()

    add_library(${_boardname} ${_boarddata_SOURCES})
    set_image_base(${_boardname} 0xF000)
    set_subsystem(${_boardname} native)
    set_entrypoint(${_boardname} ARMLLBEntryPoint)

    #create_armllb(${_boardname} ${_boarddata_SOURCES} ${CMAKE_CURRENT_BINARY_DIR}/${_boardname}.bin)
endfunction()

include(generic.cmake)

if(ARCH STREQUAL "arm")
    include(versatile.cmake)

    #add_target(versatile COMPONENTS generic versatile)
    #add_target(omap3-beagle COMPONENTS generic omap3-beagle)
    #add_target(omap3-zoom2 COMPONENTS generic omap3-zoom2)
elseif(ARCH STREQUAL "arm64")

    #add_target(apple-silicon COMPONENTS generic apple-silicon)
endif()
