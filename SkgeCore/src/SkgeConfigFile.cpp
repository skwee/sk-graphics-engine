/*
* This File is a part of SK-Game Engine.
* 
* Copyright (c) 2009 by Dmitry skwo Kudryavtsev / SK-Software
* s.kwee357@gmail.com
*/

#include "SkgeConfigFile.hpp"
#include "Filesystem/SkgeFilesystem.hpp"
#include "SkgeException.hpp"
#include "SkgeLogger.hpp"
#include "SkgeSystem.hpp"

namespace skge{

	ConfigFile::~ConfigFile(){
		if(m_AutoSave){
			save();
		}

		m_Settings.clear();
	}

	void ConfigFile::load(const String& _filename){
		m_FileName = _filename;

		Filesystem::InputFile configFile;
		configFile.open(_filename.c_str());

		//throw we file can not be opened
		if( ! configFile.is_open()){
			throw InvalidResourceException("Can not open config file " + _filename);
		}

		//Helper variables
		String data; //the full data as read from file
		String key, value; //key and value as extracted from data
		String::size_type pos;
		uint line = 0; //line count, for error reporting

		while(std::getline(configFile, data)){
			line++;

			//remove whitespaces
			StringUtils::trim(data);

			//skip empty lines
			if(data.empty()){
				continue;
			}

			//if first character is comment character, dont bother parsing this line
			if(data[0] == COMMENT_CHAR){
				continue;
			}

			//Find the key->value delimiter
			pos = data.find(KEY_VAL_DELIMITER);

			//If we cant find the delimiter, this line is bad so log it
			if(pos == String::npos){
				StringUtils::StringStream ss;
				ss << "Invalid line in config file " << _filename << " line " << line << ". No delimiter found!"
					<< " Line skipped!";
				Logger::getInstance()->log(ss.str(), Logger::LOG_WARNING);
				continue;
			}

			//Extract the key and value
			key = data.substr(0, pos);
			value = data.substr(pos + 1, data.length() - pos);

			//Trim white spaces from the key, value
			StringUtils::trim(key);
			StringUtils::trim(value);

			//if one of them is empty, line is bad
			if(key.empty() || value.empty()){
				StringUtils::StringStream ss;
				ss << "Invalid line in config file " << _filename << " line " << line << ". Bad key or value!"
					<< "Line skipped!";
				Logger::getInstance()->log(ss.str(), Logger::LOG_WARNING);
				continue;
			}

			//Convert key to lowercase
			StringUtils::toLower(key);

			//Save them.
			m_Settings[key] = value;
		}

		//Close file.
		configFile.close();
	}

	void ConfigFile::save(){
		//We can not save a file that was not opened oO
		if(m_FileName.empty()){
			Logger::getInstance()->log("Trying to save a not loaded config file!", Logger::LOG_WARNING);
			return;
		}

		save(m_FileName);
	}

	void ConfigFile::save(const String& _filename){
		Filesystem::OutputFile file;
		file.open(_filename.c_str());

		//throw we file can not be opened
		if( ! file.is_open()){
			throw InvalidResourceException("Can not open config file " + _filename);
		}

		//Write header
		String time = System::getCurrentDateAndTime();
		file << COMMENT_CHAR << "Config file create at " << time << std::endl;
		file << COMMENT_CHAR << "This file was auto created by SKGE system" << std::endl;
		file << COMMENT_CHAR << "Please do NOT edit it manually unless you know what you are doing!" << std::endl << std::endl;

		SettingsMap::iterator it = m_Settings.begin();
		SettingsMap::iterator endIt = m_Settings.end();

		while(it != endIt){
			file << static_cast<String>(it->first) << " " << KEY_VAL_DELIMITER << " " <<
				static_cast<String>(it->second) << std::endl;

			it++;
		}

		file << std::endl << COMMENT_CHAR << "End of config file!";
		file.flush();
		file.close();
	}

	const String& ConfigFile::getString(const String& _key, const String& _defaultValue){
		//Convert key to lowercase.
		String key = _key;
		StringUtils::toLower(key);

		//Get position of the value identified by key.
		SettingsMap::const_iterator it = m_Settings.find(key);

		//If position == end of the settings container, get default values
		if(it == m_Settings.end()){
			m_Settings[key] = _defaultValue;
			return _defaultValue;
		}

		//Get the needed value
		return it->second;
	}

	void ConfigFile::setString(const String& _key, const String& _value){
		//Convert to lowercase.
		String key = _key;
		StringUtils::toLower(key);

		//Set value
		m_Settings[key] = _value;
	}

}