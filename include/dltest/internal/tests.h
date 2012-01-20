#ifndef TESTS_H_
#define TESTS_H_

/////////////////////////////////////////////////////////////////////////////////////////
/// tests.h
///
/// This header defines the macros used to run test cases. These macros should only
/// be called within a DEF_TEST method
/////////////////////////////////////////////////////////////////////////////////////////

/// PRINT() : Begins a line of output by printing the current test method's name
#define PRINT() std::cout << "[" << TEST_NAME << "] "

/// PRINTLOC : Used to send the current file and line to an output stream
#define PRINTLOC __FILE__ << ":" << __LINE__

/// PASS() : Signal to the test runner that a test case passed.
/// Also prints out success message if SHOW_PASSED is true
#define PASS() dlauritz::testrunner::getInstance().pass(); \
	if (SHOW_PASSED) PRINT() << "PASS (" << PRINTLOC << ")" << std::endl

/// FAIL() : Signal to the test runner that a test case failed.
/// Prints out a message with the file and line number.
#define FAIL() dlauritz::testrunner::getInstance().fail(); PRINT() << "FAIL (" << PRINTLOC << ")" << std::endl

/// TEST_EQ(a,b)
///  a : The actual expression to evaluate
///  b : The expected result
///
/// Tests that a and b evaluate to the equivalent values (checked with the == method).
/// Sends PASS() or FAIL() and prints out details upon failure.
#define TEST_EQ(a,b) \
	if (a == b) { PASS(); } \
	else { FAIL(); PRINT() << " - Expected " << b << " but got " << a << endl; }

/// TEST_NEQ(a,b)
///  a : The actual expression to evaluate
///  b : A value that should not be equal to the actual value
///
/// This may not be used, but it checks that two expressions are different
#define TEST_NEQ(a,b) \
	if (a != b) { PASS(); } \
	else { FAIL(); PRINT() << " - Expected options to be different" << endl; }

/// TEST_TRUE(a)
///  a : A boolean expression
///
/// Tests that a evaluates to true
#define TEST_TRUE(a) \
	if (a) { PASS(); } \
	else { FAIL(); PRINT() << " - Expected true" << endl; }

/// TEST_FALSE(a)
///  a : A boolean expression
///
/// Tests that a evaluates to false
#define TEST_FALSE(a) \
	if (!a) { PASS(); } \
	else { FAIL(); PRINT() << " - Expected false" << endl; }

#endif /* TESTS_H_ */
