set(ARCH_DEFINES -D_LINUX -DTARGET_POSIX -DTARGET_LINUX)
set(SYSTEM_DEFINES -D__STDC_CONSTANT_MACROS -D_FILE_DEFINED
                   -D_LARGEFILE64_SOURCE -D_FILE_OFFSET_BITS=64)
if(WITH_ARCH)
  set(ARCH ${WITH_ARCH})
else()
  if(CPU STREQUAL "x86_64")
    set(ARCH x86_64-linux)
  elseif(CPU MATCHES "i.86")
    set(ARCH i486-linux)
  else()
    message(WARNING "unknown CPU: ${CPU}")
  endif()
endif()

set(LIRC_DEVICE          "\"/dev/lircd\"" CACHE STRING "LIRC device to use")
set(DEP_DEFINES -DLIRC_DEVICE=${LIRC_DEVICE})