/*
 * test.cpp
 *
 *  Created on: Jan 14, 2012
 *      Author: dallinlauritzen
 */

#include "dltest/dltest.h"
using namespace std;

namespace dlauritz {
test::test(const std::string &tname, void (*fptr)(const std::string&)) {
	name = new string(tname);
	func = fptr;
}

test::~test() {
	delete name;
}

void test::run() {
	TIMED_CODE(runtime, (*func)(*name));
	cout << "[" << *name << "] DONE - Time taken: " << runtime << " seconds" << endl;
	cout << endl;
}
}

