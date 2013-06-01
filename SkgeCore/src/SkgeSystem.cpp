/*
* This File is a part of SK-Game Engine.
* 
* Copyright (c) 2009 by Dmitry skwo Kudryavtsev / SK-Software
* s.kwee357@gmail.com
*/

#include "SkgeSystem.hpp"

namespace skge{
	namespace System{

		String getCurrentDateAndTime(){
			time_t rawtime;
			struct tm* tminfo;

			time(&rawtime);
			tminfo = localtime(&rawtime);
			String time(asctime(tminfo));

			std::replace(time.begin(), time.end(), '\n', ' ');

			return time;
		}

		void showExceptionErrorDialog(const Exception& _exception){
			MessageBoxA(NULL, _exception.what(), "An Error Occurred!", MB_ICONERROR | MB_OK);
		}

	}
}