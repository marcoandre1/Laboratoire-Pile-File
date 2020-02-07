add_executable(first_test first_test.cc ContratException.cpp)
add_test(first_test first_test)
target_link_libraries(first_test ${GTEST_LIBRARIES})

add_executable(test_with_fixture test_with_fixture.cc)
add_test(test_with_fixture test_with_fixture)
target_link_libraries(test_with_fixture ${GTEST_LIBRARIES})