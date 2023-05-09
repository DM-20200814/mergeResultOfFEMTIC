file(GLOB_RECURSE srcs CONFIGURE_DEPENDS src/*.cpp include/*.h)
# message(WARNING "mergeResultLib srcs: ${srcs}")
add_library(mergeResultLib STATIC ${srcs})
target_include_directories(mergeResultLib PUBLIC include)