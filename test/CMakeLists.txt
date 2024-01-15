add_executable(test_database test_database.cpp)
target_link_libraries(test_database database)
target_link_libraries(test_database build_settings)

add_test(NAME test_database COMMAND test_database)

add_executable(curlpp_test curlcpp_test.cpp)
target_link_libraries(test_database build_settings)
target_include_directories(test_database PUBLIC ../libs/curlpp)
