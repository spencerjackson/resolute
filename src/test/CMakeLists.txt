set(TESTSOURCES clause_test.cpp resolution_test.cpp)
add_executable(testrunner ${SOURCES} ${TESTSOURCES} testrunner.cpp)
target_link_libraries(testrunner cppunit dl)
