/*
 * tester.cpp
 *
 *  Created on: Jan 16, 2012
 *      Author: dallinlauritzen
 */

#include "all.h"
using namespace dlauritz;
using namespace std;

DEF_TEST(logger1, "DLLog 01") {
	TEST_EQ(1,1);
	DL_INFO() << "Hey you!" << DL_ENDMSG();
	DL_WARN() << "Boo" << DL_ENDMSG();
}

DLTEST_MAIN(true);
