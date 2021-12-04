
list(APPEND SOURCE
    winmain.c
    calc.h)

add_executable(prog ${SOURCE} prog.rc)
set_module_type(prog win32gui UNICODE)
add_importlibs(prog advapi32 comctl32 user32 shell32 gdi32 kernel32)
add_pch(prog calc.h SOURCE)
set_entrypoint(prog _tWinMain)
add_cd_file(TARGET prog DESTINATION reactos/system32 FOR all)
