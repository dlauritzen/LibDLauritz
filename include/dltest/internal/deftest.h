#ifndef DLAURITZ_DLTEST_DEFTEST_H_
#define DLAURITZ_DLTEST_DEFTEST_H_

/////////////////////////////////////////////////////////////////////////////////////////
/// deftest.h
///
/// This header file defines macros used when defining or running
/// test cases. Each macro is explained in its documentation below.
/////////////////////////////////////////////////////////////////////////////////////////


/// TIMED_CODE(diffname, code)
///  diffname : The name of the float to store the difference in
///  code : The code to execute
///
/// Used by the system to wrap a test's execution to provide timing information.
/// The user doesn't need to worry about this.
#define TIMED_CODE(diffname, code) \
	clock_t dl_start, dl_finish; \
	dl_start = clock(); \
	code; \
	dl_finish = clock(); \
	float diffname = ((dl_finish - dl_start) / (float)CLOCKS_PER_SEC) * 1000.0;


/// DEF_TEST(keyword, name)
///  keyword : A keyword, suitable for inclusion as a variable or method name
///            that will be used to uniquely identify this test.
///  name : The string-quoted name of the test. This is used when printing messages
///         within the test and reporting pass/fail/done
///
/// This is the macro used to define and register a named test with the program.
/// It creates a method `void defTest_XXX(const std::string&)` where `XXX` is
/// the keyword provided. It then registers the test with the singleton static
/// test runner. This registration returns an integer, stored in regTest_##, where
/// ## is the index of the test in the registration queue.
///
/// Tests defined this way are automatically run when RUN_ALL_TESTS() is used.
/// The default DLTEST_MAIN() handles this for the user.
#define DEF_TEST(keyword, name) void defTest_ ## keyword(const std::string&); \
	static int regTest_ ## keyword = dlauritz::testrunner::getInstance().registerTest(&defTest_ ## keyword, name); \
	void defTest_ ## keyword(const std::string &testname)

/// TEST_NUM(keyword)
///  keyword : The keyword used in the DEF_TEST macro
///
/// This macro extracts the test number created when registering a test. It
/// can be used for information or fun.
#define TEST_NUM(keyword) regTest_ ## keyword

/// TEST_NAME
///
/// This macro extracts the test name. This can only be used within a DEF_TEST
/// method.
#define TEST_NAME testname

#endif
