/*
* This File is a part of SK-Game Engine.
* 
* Copyright (c) 2009 by Dmitry skwo Kudryavtsev / SK-Software
* s.kwee357@gmail.com
*/

#ifndef SKGE_SYSTEM_H_
#define SKGE_SYSTEM_H_

#include "Skge.hpp"
#include "SkgeException.hpp"

namespace skge{
	namespace System{

		/** 
		 * Get current date and time.
		 * @return Current date and time as string.
		 */
		String getCurrentDateAndTime();

		/** 
		 * An easy way to display exception error dialog.
		 * @param _exception Exception to display dialog for.
		 */
		void SKGE_API showExceptionErrorDialog(const Exception& _exception);

		/** 
		 * Version
		 */
		//@{
		namespace Version{
			const byte MAJOR = 0;
			const byte MINOR = 0;
			const ushort BUILD = 0;
		}
		//@}

	}
}

#endif