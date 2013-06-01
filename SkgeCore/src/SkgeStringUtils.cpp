/*
* This File is a part of SK-Game Engine.
* 
* Copyright (c) 2009 by Dmitry skwo Kudryavtsev / SK-Software
* s.kwee357@gmail.com
*/

#include "SkgeStringUtils.hpp"

namespace skge{

	namespace StringUtils{

		void trim(String& _string, const char* _toRemove){
			//Make sure that the string is not empty.
			if( ! _string.empty()){

				//Find the position of last character that is not the one to remove.
				String::size_type pos = _string.find_last_not_of(_toRemove);

				//If positions is not the end of the string
				if(pos != String::npos){
					//Erase all from pos + 1 to the  end
					_string.erase(pos + 1);

					//Find the position of the first that is not to remove.
					pos = _string.find_first_not_of(_toRemove);

					//If position is not end of string
					if(pos != String::npos){
						//remove from beginning to pos
						_string.erase(0, pos);
					}
				}else{
					//erase all string.
					_string.erase(_string.begin(), _string.end());
				}
			}
		}

		void toLower(String& _str){
			std::transform(_str.begin(), _str.end(), _str.begin(), tolower);
		}

		void toUpper(String& _str){
			std::transform(_str.begin(), _str.end(), _str.begin(), toupper);
		}

	}

}