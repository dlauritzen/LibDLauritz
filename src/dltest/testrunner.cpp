/*
 * testrunner.cpp
 *
 *  Created on: Jan 14, 2012
 *      Author: dallinlauritzen
 */

#include "dltest/dltest.h"
using namespace std;

namespace dlauritz {

testrunner * runner = NULL;

testrunner & testrunner::getInstance() {
	if (runner == NULL) {
		runner = new testrunner();
	}

	return *runner;
}

void testrunner::construct() {
}

void testrunner::destruct() {
	delete runner;
	runner = NULL;
}

testrunner::testrunner() {
	//cout << "-- Initializing test runner" << endl;
	showPassedTests = false;
	testsRun = 0;
	testsPassed = 0;
	testsFailed = 0;
	tests = new testlist();
}

testrunner::~testrunner() {
	//cout << "-- Destructing test runner" << endl;
	delete tests;
}

void testrunner::runAllTests() {
	printWelcome();
	tests->run();
	printSummary();
}

int testrunner::registerTest(void (*func)(const std::string&), const std::string &fname) {
	cout << "Registering test: " << fname << endl;
	tests->addTest(func, fname);
	return tests->getSize();
}

void testrunner::pass() {
	++testsRun;
	++testsPassed;
}

void testrunner::fail() {
	++testsRun;
	++testsFailed;
}

void testrunner::printWelcome() {
	cout << "==================================================" << endl;
	cout << "Running " << tests->getSize() << " tests" << endl;
	cout << "==================================================" << endl;
}

void testrunner::printSummary() {
	cout << "==================================================" << endl;
	cout << "TEST SUMMARY" << endl;
	cout << endl;
	cout << "Run: " << testsRun << endl;
	cout << "Passed: " << testsPassed << endl;
	cout << "Failed: " << testsFailed << endl;
	cout << "==================================================" << endl;
}

}

