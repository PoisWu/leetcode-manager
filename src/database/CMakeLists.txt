
add_library(database database.cpp)
find_package (SQLite3)
include_directories(${SQLite3_INCLUDE_DIRS})
target_link_libraries (database PUBLIC ${SQLite3_LIBRARIES})
target_link_libraries(database PRIVATE build_settings)

