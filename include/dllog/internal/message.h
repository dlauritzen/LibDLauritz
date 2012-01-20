/*
 * message.h
 *
 *  Created on: Jan 16, 2012
 *      Author: dallinlauritzen
 */

#ifndef MESSAGE_H_
#define MESSAGE_H_

#include "loglevels.h"
#include "logger.h"

#include <iostream>
#include <cstdlib>
#include <string>
#include <sstream>

namespace dlauritz {

class logmessage {

private:

	LogLevel level;
	bool printed;

	std::stringstream * msg;

public:

	logmessage(LogLevel lvl);

	~logmessage();

	std::stringstream & getStream();

	void print();

	void reset();

	LogLevel getLevel() const;

	static logmessage & getMessageForLevel(LogLevel lvl);

};

void operator <<(std::ostream &strm, const logmessage &msg);

static logmessage lmsg_fatal(llFatal);
static logmessage lmsg_error(llError);
static logmessage lmsg_warn(llWarning);
static logmessage lmsg_info(llInfo);
static logmessage lmsg_debug(llDebug);
static logmessage lmsg_trace(llTrace);
static logmessage lmsg_end(llEnd);

}

#define GET_CUR_MSG() dlauritz::logmessage::getMessageForLevel(GET_CUR_LEVEL())

#endif /* MESSAGE_H_ */
