add_executable(test_database test_database.cpp)
target_link_libraries(test_database database)
target_link_libraries(test_database build_settings)

add_test(NAME test_database COMMAND test_database)
