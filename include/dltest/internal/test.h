#ifndef TEST_H_
#define TEST_H_

/////////////////////////////////////////////////////////////////////////////////////////
/// test.h
///
/// This header file defines the test class, which is a wrapper for
/// a named test case that can be registered with the system and run
/// on demand.
///
/// It stores the name and a pointer to the generated method.
/////////////////////////////////////////////////////////////////////////////////////////

#include <iostream>
#include <string>
#include <cstdlib>

namespace dlauritz {
class test {

private:

	/// The test name, defined in the DEF_TEST macro
	const std::string * name;

	/// The test. This is passed into testrunner's registerTest method when
	/// a new test is defined.
	void (*func)(const std::string&);

public:

	/// Constructor. Remember the name and pointer for later execution
	test(const std::string &tname, void (*fptr)(const std::string&));

	/// Destructor. Deletes the locally-copied test name
	~test();

	/// Run the stored test.
	///
	/// This method calls the function stored by this test.
	void run();

};
}


#endif /* TEST_H_ */
