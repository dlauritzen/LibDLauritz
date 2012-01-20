/*
 * message.cpp
 *
 *  Created on: Jan 16, 2012
 *      Author: dallinlauritzen
 */

#include "dllog/internal/message.h"
#include <iomanip>
using namespace std;

namespace dlauritz {

logmessage::logmessage(LogLevel lvl) {
	level = lvl;
	msg = NULL;
	reset();
}

logmessage::~logmessage() {
	delete msg;
	msg = NULL;
}

std::stringstream & logmessage::getStream() {
	*msg << "[" << __TIME__ << "] " << setw(6) << left << level << __FILE__ << ":"
			<< __LINE__ << " ";
	return *msg;
}

LogLevel logmessage::getLevel() const {
	return level;
}

void logmessage::print() {
	if (!printed && shouldPrint(level)) {
		cout << "Length of message: " << msg->str().length() << endl;
		cout << msg->str() << endl;
		printed = true;
	}
}

void logmessage::reset() {
	printed = false;
	delete msg;
	msg = new stringstream();
}

logmessage & logmessage::getMessageForLevel(LogLevel lvl) {
	switch(lvl) {
		case llFatal:
			return lmsg_fatal;
		case llError:
			return lmsg_error;
		case llWarning:
			return lmsg_warn;
		case llInfo:
			return lmsg_info;
		case llDebug:
			return lmsg_debug;
		case llTrace:
			return lmsg_trace;
		case llEnd:
			return lmsg_end;
		default:
			return getMessageForLevel(DEFAULT_LOG_LEVEL);
	}
}

void operator <<(std::stringstream &strm, const logmessage &end) {
	cout << "Triggering end of message." << endl;
	if (end.getLevel() == llEnd) {
		cout << "Printing message from level " << GET_CUR_LEVEL() << "!" << endl;
		GET_CUR_MSG().print();
	}
}

}

