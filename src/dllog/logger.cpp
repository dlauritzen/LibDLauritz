/*
 * logger.cpp
 *
 *  Created on: Jan 16, 2012
 *      Author: dallinlauritzen
 */

#include "dllog/internal/logger.h"
#include "dllog/internal/message.h"
#include <iomanip>
using namespace std;

namespace dlauritz {

logger::logger() {
	rootLevel = DEFAULT_LOG_LEVEL;
	currentLevel = llEnd;
}

logger::~logger() {

}

void logger::setRootLevel(LogLevel newlevel) {
	rootLevel = newlevel;
}

LogLevel logger::getRootLevel() const {
	return rootLevel;
}

void logger::setMessageLevel(LogLevel lvl) {
	currentLevel = lvl;
}

LogLevel logger::getMessageLevel() const {
	return currentLevel;
}

void logger::clearMessageLevel() {
	currentLevel = llEnd;
}

void logger::initialize() {
}

std::stringstream & logger::startMessage(LogLevel level) {
	cout << "Starting message at level " << level << endl;
	setMessageLevel(level);
	return logmessage::getMessageForLevel(level).getStream();
}

logger & logger::getInstance() {
	return logger_instance;
}

void logger::finalize() {
}

}
