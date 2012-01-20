#ifndef DLAURITZ_DLTEST_DLTEST_H_
#define DLAURITZ_DLTEST_DLTEST_H_

/////////////////////////////////////////////////////////////////////////////////////////
/// dltest.h
///
/// The entry point for classes that want to use the dltest library.
///
/// This header files includes the needed header files and defines a default main()
/// method that may be used to run all tests if nothing else is needed by the testing
/// code.
///
/// See the samples for examples on how to write tests and what the resulting programs
/// look like.
/////////////////////////////////////////////////////////////////////////////////////////

#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <string>
#include <sstream>
#include <time.h>

#include "internal/testrunner.h" // testrunner class. contains settings and other info
#include "internal/deftest.h" // DEF_TEST(name) macros
#include "internal/tests.h" // all the different TEST macros

/// SHOW_PASSED : Access the singleton's property of whether to show success messages
#define SHOW_PASSED dlauritz::testrunner::getInstance().showPassedTests

/// DLTEST_INIT() : Run the construct() method on the test runner
#define DLTEST_INIT() dlauritz::testrunner::construct()

/// RUN_ALL_TESTS() : Execute all registered test methods
#define RUN_ALL_TESTS() dlauritz::testrunner::getInstance().runAllTests()

/// DLTEST_FINALIZE() : Perform any cleanup by calling the destruct() method on the test runner
#define DLTEST_FINALIZE() dlauritz::testrunner::destruct()

/// DLTEST_MAIN(showpass)
///  showpass : Whether to show success messages for all tests.
///
/// A default main() method that may be used if nothing special is required by the
/// testing program. This calls the DLTEST_INIT(), RUN_ALL_TESTS(), and DLTEST_FINALIZE() macros.
#define DLTEST_MAIN(showpass) \
	int main(int argc, const char *argv[]) { \
		DLTEST_INIT(); \
		SHOW_PASSED = showpass; \
		RUN_ALL_TESTS(); \
		DLTEST_FINALIZE(); \
		return 0; \
	}

#endif
