#ifndef TESTLIST_H_
#define TESTLIST_H_

/////////////////////////////////////////////////////////////////////////////////////////
/// testlist.h
///
/// This defines a linked list that stores tests.
/// Since tests are executed in order of registration, a linked list
/// is an easy way to store an indefinite number of test cases
/////////////////////////////////////////////////////////////////////////////////////////

#include "test.h"

namespace dlauritz {

/// class: testnode
///
/// This class acts as a node in the linked list. It stores the
/// test and a pointer to the next node.
class testnode {

private:

	/// The test
	test * t;

	/// The next test to run
	testnode * next;

public:

	/// Constructor. Pass the parameters in to create the test. Set next to NULL.
	testnode(void (*tst)(const std::string&), const std::string &tnm);

	/// Destructor. Delete the node after this one.
	~testnode();

	/// Get the next test (const version)
	const testnode * getNext() const;

	/// Get the next test
	testnode * getNext();

	/// Set the next test
	void setNext(testnode * n);

	/// Run the stored test
	void run();

};

/// class: testlist
///
/// This is the linked list of testnodes
class testlist {

private:

	/// The first test, where testing begins
	testnode * first;

	/// The last node, where tests are added on
	testnode * last;

	/// The number of tests
	int size;

public:

	/// Constructor. Create an empty list
	testlist();

	/// Destructor. Delete all the test nodes
	~testlist();

	/// Get the number of tests
	int getSize() const;

	/// Run all tests
	void run();

	/// Add a test to the list
	void addTest(void (*t)(const std::string&), const std::string &nm);

};
}


#endif /* TESTLIST_H_ */
