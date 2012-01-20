/*
 * testlist.cpp
 *
 *  Created on: Jan 14, 2012
 *      Author: dallinlauritzen
 */

#include "dltest/dltest.h"
using namespace std;

namespace dlauritz {
testnode::testnode(void(*tst)(const std::string&), const std::string &tnm) {
	t = new test(tnm, tst);
	next = NULL;
}

testnode::~testnode() {
	delete t;
	delete next;
}

const testnode * testnode::getNext() const {
	return next;
}

testnode * testnode::getNext() {
	return next;
}

void testnode::setNext(testnode * n) {
	next = n;
}

void testnode::run() {
	t->run();
}

/// TEST LIST

testlist::testlist() {
	first = NULL;
	last = NULL;
	size = 0;
}

testlist::~testlist() {
	delete first;
}

int testlist::getSize() const {
	return size;
}

void testlist::run() {
	//cout << "Running testlist. Size=" << size << endl;
	testnode * current = first;
	while (current != NULL) {
		current->run();
		current = current->getNext();
	}
}

void testlist::addTest(void (*t)(const std::string&), const std::string &nm) {
	//cout << "Adding test " << nm << endl;

	testnode *n = new testnode(t, nm);
	if (size == 0) {
		first = n;
		last = first;
	} else {
		last->setNext(n);
		last = n;
	}

	++size;

	//cout << "Size now equals " << size << endl;
}

}

