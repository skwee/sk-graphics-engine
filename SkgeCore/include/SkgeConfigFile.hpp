/*
* This File is a part of SK-Game Engine.
* 
* Copyright (c) 2009 by Dmitry skwo Kudryavtsev / SK-Software
* s.kwee357@gmail.com
*/

#ifndef SKGE_CONFIG_FILE_H_
#define SKGE_CONFIG_FILE_H_

#include "Skge.hpp"
#include "SkgeStringUtils.hpp"

namespace skge{

	/** 
	 * Config file. Used to read and write from and to config file.
	 */
	class SKGE_API ConfigFile{
	public:
		/** 
		 * Config settings map definition.
		 */
		typedef std::map<String, String> SettingsMap;

	private:
		SettingsMap m_Settings; /**< Settings map. */
		String m_FileName; /**< Filename currently in use. */
		bool m_AutoSave; /**< Should we save the values at object destruction? */

		static const char COMMENT_CHAR = '#'; /**< Comment character. */
		static const char KEY_VAL_DELIMITER = '='; /**< Key value delimiter. */

	public:
		/** 
		 * Constructor.
		 * @param _autoSave Auto save config settings at end?
		 */
		ConfigFile(bool _autoSave = false):m_AutoSave(_autoSave){}

		/** 
		 * Destructor.
		 */
		~ConfigFile();

		/** 
		 * Load settings from file.
		 * @param _filename File to load from.
		 */
		void load(const String& _filename);

		/** 
		 * Save settings to currently used file.
		 * @note If settings was not loaded, the function will return.
		 */
		void save();

		/** 
		 * Save content of configuration file to specified file.
		 * @param _filename File to save to.
		 */
		void save(const String& _filename);

		/** 
		 * Get setting as type <c>T</c>
		 * @param _key setting key.
		 * @param _defaultValue Default value if key is not found. This value will be added
		 * to the settings map.
		 * @return Value as type T specified by <c>_key</c>.
		 * @note The behaviour of this function is defined for core types as T like int, char, bool,
		 * also to get string value its suggested to use ConfigFile::getString instead, since its faster.
		 */
		template<typename T>
		T get(const String& _key, T _defaultValue);

		/** 
		 * A faster version of ConfigFile::get for string.
		 * @param _key setting key.
		 * @param _defaultValue Default value if key is not found. This value will be added
		 * to the settings map.
		 * @return String value specified by <c>_key</c>.
		 */
		const String& getString(const String& _key, const String& _defaultValue);

		/** 
		 * Set specific key->value pair.
		 * @param _key Key to set value for.
		 * @param _value Value to set.
		 * @note For string values please use ConfigFile::setString instead since its faster.
		 */
		template<typename T>
		void set(const String& _key, T _value);

		/** 
		 * Set specific key->value pair where value is String.
		 * @note If key not exists, it will be added.
		 * @param _key Key to set value for.
		 * @param _value Value to set.
		 */
		void setString(const String& _key, const String& _value);
	};

	template<typename T>
	T ConfigFile::get(const String& _key, T _defaultValue){
		//Convert key to lower case.
		String key = _key;
		StringUtils::toLower(key);

		//Get position of value identified by key
		SettingsMap::const_iterator it = m_Settings.find(key);

		//Storage for value
		T value;

		//Get the value
		if(it == m_Settings.end()){
			m_Settings[key] = StringUtils::toString(_defaultValue);
			value = _defaultValue;
		}else{
			value = StringUtils::fromString<T>(it->second);
		}

		return value;
	}

	template<typename T>
	void ConfigFile::set(const String& _key, T _value){
		String value = StringUtils::toString<T>(_value);

		setString(_key, value);
	}

}

#endif