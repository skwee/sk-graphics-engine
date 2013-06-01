/*
* This File is a part of SK-Game Engine.
* 
* Copyright (c) 2009 by Dmitry skwo Kudryavtsev / SK-Software
* s.kwee357@gmail.com
*/

#include "SkgeLogger.hpp"
#include "SkgeException.hpp"
#include "SkgeSystem.hpp"

namespace skge{

	DECLARE_SINGLETON(Logger);

	//Log file
	const String Logger::LOG_FILE = "SkgeLog.txt";

	Logger::Logger(){
		//open file for append
		m_LogFile.open(LOG_FILE.c_str(), std::ios::app);

		//make sure file was opened
		if( ! m_LogFile.is_open()){
			throw UnexpectedException("Ooops failed to create log file, your pc is probably bugged :)");
		}

		//Write start time of log.
		String time = System::getCurrentDateAndTime();
		m_LogFile << "[ LOG STARTED AT " << time << "]" << std::endl;
	}

	Logger::~Logger(){
		//If file is open
		if(m_LogFile.is_open()){
			//Write end time of log
			String time = System::getCurrentDateAndTime();
			m_LogFile << "[ LOG ENDED AT " << time << "]" << std::endl << std::endl;

			//Flush and close
			m_LogFile.flush();
			m_LogFile.close();
		}
	}

	void Logger::log(const String& _str, LogType _type){
		//This can not happen but assume the previous exception was ignored somehow, make sure we are safe
		if( ! m_LogFile.is_open()){
			throw InvalidResourceException("Trying to write to a log file that is not opened!");
		}

		//Get the log type.
		String type;
		switch(_type){
			case LOG_NORMAL:
				type = "(NN)";
				break;

			case LOG_WARNING:
				type = "(WW)";
				break;
				
			case LOG_ERROR:
				type = "(EE)";
				break;

			default:
				type = "(??)";
		}

		//Get time and write log
		String time = System::getCurrentDateAndTime();
		m_LogFile << type << "[ " << time << "] " << _str << std::endl;
	}

}