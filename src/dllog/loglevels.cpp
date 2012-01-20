/*
 * loglevels.cpp
 *
 *  Created on: Jan 16, 2012
 *      Author: dallinlauritzen
 */

#include "dllog/internal/loglevels.h"
#include "dllog/internal/logger.h"
using namespace std;

namespace dlauritz {

bool shouldPrint(LogLevel current) {
	// TODO figure in rejection
	//LogLevel root = GET_LOG_LEVEL();
	return true;
}

std::ostream & operator <<(std::ostream &out, LogLevel ll) {
	switch(ll) {
		case llFatal:
			out << "FATAL";
			break;
		case llError:
			out << "ERROR";
			break;
		case llWarning:
			out << "WARN";
			break;
		case llInfo:
			out << "INFO";
			break;
		case llDebug:
			out << "DEBUG";
			break;
		case llTrace:
			out << "TRACE";
			break;
		case llEnd:
			out << "END";
			break;
		default:
			out << "-- ERROR: update loglevels.cpp --";
			break;
	}
	return out;
}

}
