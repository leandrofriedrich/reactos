
list(APPEND HAL_STUB_SOURCE
    generic/stub.c)

add_library(lib_hal_stub OBJECT ${HAL_STUB_SOURCE})
