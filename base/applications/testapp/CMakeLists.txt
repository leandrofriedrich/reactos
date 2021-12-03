
list(APPEND SOURCE
    winmain.c
    calc.h)

add_executable(prog ${SOURCE})
set_module_type(prog win32gui UNICODE)
if(MSVC)
    add_importlibs(prog ntdll)
endif()

add_pch(prog calc.h SOURCE)
add_importlibs(prog advapi32 comctl32 user32 shell32 gdi32 kernel32)
set_entrypoint(prog _tWinMain)
#add_importlibs(calc advapi32 comctl32 user32 shell32 gdi32 msvcrt kernel32)
add_cd_file(TARGET prog DESTINATION reactos/system32 FOR all)
