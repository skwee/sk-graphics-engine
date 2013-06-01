/*
* This File is a part of SK-Game Engine.
* 
* Copyright (c) 2009 by Dmitry skwo Kudryavtsev / SK-Software
* s.kwee357@gmail.com
*/

#ifndef SKGE_LOGGER_H_
#define SKGE_LOGGER_H_

#include "SkgeSingleton.hpp"
#include "Filesystem/SkgeFilesystem.hpp"

namespace skge{

	/** 
	 * Logger class.
	 */
	class SKGE_API Logger: public Singleton<Logger>{
	public:
		/** 
		 * Types of logs.
		 */
		enum LogType{
			LOG_NORMAL,
			LOG_WARNING,
			LOG_ERROR
		};

	private:
		Filesystem::OutputFile m_LogFile; /**< The log file itself. */

		static const String LOG_FILE; /**< Log filename. */

	public:
		/** 
		 * Constructor.
		 */
		Logger();

		/** 
		 * Destructor.
		 */
		~Logger();

		/** 
		 * Log single line.
		 * @param _str String to lone
		 * @param _type Log type.
		 */
		void log(const String& _str, LogType _type = LOG_NORMAL);
	};

}

#endif