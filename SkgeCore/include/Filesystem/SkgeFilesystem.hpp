/*
* This File is a part of SK-Game Engine.
* 
* Copyright (c) 2009 by Dmitry skwo Kudryavtsev / SK-Software
* s.kwee357@gmail.com
*/

#ifndef SKGE_FILESYSTEM_H_
#define SKGE_FILESYSTEM_H_

#include "Skge.hpp"

namespace skge{
	namespace Filesystem{

		/** 
		 * Files definition.
		 */
		//@{
		typedef std::fstream File;
		typedef std::ofstream OutputFile;
		typedef std::ifstream InputFile;
		//@}

	}
}

#endif