add_library(glad)
target_sources(glad PRIVATE ${CMAKE_CURRENT_LIST_DIR}/src/gl.c)
target_include_directories(glad PUBLIC ${CMAKE_CURRENT_LIST_DIR}/include)
