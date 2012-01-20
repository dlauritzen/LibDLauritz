/*
 * dllog.h
 *
 *  Created on: Jan 16, 2012
 *      Author: dallinlauritzen
 */

#ifndef DLLOG_H_
#define DLLOG_H_

#include <iomanip>

#include "internal/loglevels.h"
#include "internal/logger.h"
#include "internal/message.h"

#define DL_FATAL() START_LOG_MSG(dlauritz::llFatal)
#define DL_ERROR() START_LOG_MSG(dlauritz::llError)
#define DL_WARN() START_LOG_MSG(dlauritz::llWarning)
#define DL_INFO() START_LOG_MSG(dlauritz::llInfo)
#define DL_DEBUG() START_LOG_MSG(dlauritz::llDebug)
#define DL_TRACE() START_LOG_MSG(dlauritz::llTrace)

#define DL_ENDMSG() dlauritz::lmsg_end

#endif /* DLLOG_H_ */
