#ifndef TESTRUNNER_H_
#define TESTRUNNER_H_

/////////////////////////////////////////////////////////////////////////////////////////
/// testrunner.h
///
/// This header defines the class used to remember all registered tests,
/// store statistics about test execution, and begin testing.
/////////////////////////////////////////////////////////////////////////////////////////

#include <iostream>
#include <cstdlib>
#include <string>
#include "test.h"
#include "testlist.h"

namespace dlauritz {

/// class: testrunner
///
/// Runs the registered tests and reports success/failure
class testrunner {

private:

	/// The total number of TESTs run (this is not the same as number of
	/// registered tests.
	int testsRun;

	/// The number of tests PASSed
	int testsPassed;

	/// The number of tests that FAILed
	int testsFailed;

	/// The list of registered test methods
	testlist * tests;

	/// Constructor. This is private to make it a singleton
	testrunner();

public:

	/// Whether to show messages for PASSed tests
	bool showPassedTests;

	/// Destructor. Delete the test list
	~testrunner();

	/// Run all tests
	void runAllTests();

	/// Signal that a test case passed. Called by the PASS() macro
	void pass();

	/// Signal that a test case failed. Called by the FAIL() macro
	void fail();

	/// Register a new test method.
	///
	/// \param func : The function to run
	/// \param fname : The name of the test
	int registerTest(void (*func)(const std::string&), const std::string &fname);

	/// Print a message to show that tests are about to be run
	void printWelcome();

	/// Print a summary of tests run/passed/failed after testing is complete
	void printSummary();

	/// Run any initialization before execution
	static void construct();

	/// Access the test runner singleton
	static testrunner & getInstance();

	/// Destroy the singleton test runner
	static void destruct();

};

}

#endif /* TESTRUNNER_H_ */
