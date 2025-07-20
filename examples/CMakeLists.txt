aux_source_directory(. DIR_EXAMPLES_SRCS)

include_directories(../lib/config)
include_directories(../lib/lcd)
include_directories(../lib/font)
include_directories(../lib/fatfs)
include_directories(../lib/sdcard)

add_library(examples ${DIR_EXAMPLES_SRCS})
target_link_libraries(examples PUBLIC config lcd font fatfs sdcard)
