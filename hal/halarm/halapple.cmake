
list(APPEND HAL_APPLE_SOURCE
applesilicon/halinit.c
applesilicon/halup.rc)

add_library(lib_hal_apple OBJECT ${HAL_APPLE_SOURCE})
