/*
 * logger.h
 *
 *  Created on: Jan 16, 2012
 *      Author: dallinlauritzen
 */

#ifndef LOGGER_H_
#define LOGGER_H_

#include "loglevels.h"
#include <iostream>
#include <cstdlib>
#include <string>

namespace dlauritz {

class logger {

private:

	LogLevel rootLevel;

	LogLevel currentLevel;

public:

	logger();

	~logger();

	void setRootLevel(LogLevel newlevel);

	LogLevel getRootLevel() const;

	void setMessageLevel(LogLevel lvl);

	LogLevel getMessageLevel() const;

	void clearMessageLevel();

	std::stringstream & startMessage(LogLevel level);

	static void initialize();

	static logger & getInstance();

	static void finalize();

};

static logger logger_instance;

}

//dlauritz::logger::getInstance()
#define GET_LOGGER() logger_instance
#define GET_LOG_LEVEL() GET_LOGGER().getRootLevel()
#define GET_CUR_LEVEL() GET_LOGGER().getMessageLevel()

#define START_LOG_MSG(level) GET_LOGGER().startMessage(level)

#endif /* LOGGER_H_ */
