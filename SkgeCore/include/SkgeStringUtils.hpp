/*
* This File is a part of SK-Game Engine.
* 
* Copyright (c) 2009 by Dmitry skwo Kudryavtsev / SK-Software
* s.kwee357@gmail.com
*/

#ifndef SKGE_STRING_UTILS_H_
#define SKGE_STRING_UTILS_H_

#include "Skge.hpp"

namespace skge{

	namespace StringUtils{

		/** 
		 * String streams definition.
		 */
		//@{
#ifdef SKGE_UNICODE
		typedef std::wstringstream StringStream;
		typedef std::wostringstream OutputStringStream;
		typedef std::wistringstream InputStringStream;
#else
		typedef std::stringstream StringStream;
		typedef std::ostringstream OutputStringStream;
		typedef std::istringstream InputStringStream;
#endif
		//@}

		/** 
		 * Trim <c>_toRemove</c> characters from <c>_string</c>.
		 * @param _string String to remove characters from.
		 * @param _toRemove Set of characters to remove.
		 * @note <c>_string</c> Is changed to contain new string.
		 */
		void SKGE_API trim(String& _string, const char* _toRemove = " ");

		/** 
		 * Convert string to lower case.
		 * @param _str String to convert.
		 * @note <c>_str</c> Will be changed!
		 */
		void SKGE_API toLower(String& _str);

		/** 
		 * Convert string to upper case.
		 * @param _str String to convert.
		 * @note <c>_str</c> Will be changed!
		 */
		void SKGE_API toUpper(String& _str);

		/** 
		 * Converting String to T.
		 * @param _string String to convert;
		 * @@return T as converted <c>_string</c>.
		 */
		template<typename T>
		T fromString(const String& _string){
			StringStream ss;
			T data;

			ss << _string;
			ss >> data;

			return data;
		}

		/** 
		 * Convert T to String.
		 * @param _value T value to convert.
		 * @return Converted <c>_value</c> as string.
		 */
		template<typename T>
		String toString(const T& _value){
			StringStream ss;

			ss << _value;

			return ss.str();
		}

	}

}

#endif