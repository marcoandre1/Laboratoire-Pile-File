add_executable(first_test first_test.cc ContratException.cpp)
add_test(first_test first_test)
target_link_libraries(first_test gtest gtest_main)
