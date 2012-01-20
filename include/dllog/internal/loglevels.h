/*
 * loglevels.h
 *
 *  Created on: Jan 16, 2012
 *      Author: dallinlauritzen
 */

#ifndef LOGLEVELS_H_
#define LOGLEVELS_H_

#include <string>
#include <iostream>
#include <cstdlib>

namespace dlauritz {

enum LogLevel {

	llFatal,

	llError,

	llWarning,

	llInfo,

	llDebug,

	llTrace,

	llEnd // special level to signal end of message

};

bool shouldPrint(LogLevel current);

std::ostream & operator <<(std::ostream &out, LogLevel ll);

#ifndef DEFAULT_LOG_LEVEL
#define DEFAULT_LOG_LEVEL dlauritz::llInfo
#endif

}


#endif /* LOGLEVELS_H_ */
