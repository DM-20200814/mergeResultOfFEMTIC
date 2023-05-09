file(GLOB_RECURSE srcs CONFIGURE_DEPENDS ./main.cpp)

add_executable(mergeResult ${srcs})
# target_include_directories(mergeResult PUBLIC include)

target_link_libraries(mergeResult PUBLIC mergeResultLib)