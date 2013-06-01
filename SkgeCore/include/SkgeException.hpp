/*
* This File is a part of SK-Game Engine.
* 
* Copyright (c) 2009 by Dmitry skwo Kudryavtsev / SK-Software
* s.kwee357@gmail.com
*/

#ifndef SKGE_EXCEPTION_H_
#define SKGE_EXCEPTION_H_

#include "SkgeStringUtils.hpp"

namespace skge{

	/** 
	 * Basic exception  in SKGE system.
	 */
	class SKGE_API Exception: public std::exception{
	private:
		String m_Name; /**< Exception name. */
		String m_Error; /**< Exception Error. */
		mutable String m_FullDescription; /**< Full exception description. */

	public:
		/** 
		 * Create exception.
		 * @param _name Exception name.
		 * @param _error Exception error.
		 */
		Exception(const String& _name, const String& _error):
		  m_Name(_name), m_Error(_error){}

	    /** 
	     * Get exception name.
		 * @return Exception name.
	     */
		const String& getName() const { return m_Name; }

		/** 
		 * Get error message.
		 * @return Error message.
		 */
		const String& getError() const { return m_Error; }

		/** 
		 * Get Full Description of exception.
		 */
		const String& getFullDescription() const {
			if(m_FullDescription.empty()){
				StringUtils::OutputStringStream ss;
				ss << "Exception Occurred! " << std::endl << m_Name << ": " << m_Error;
				m_FullDescription = ss.str();
			}

			return m_FullDescription;
		}

		/** 
		 * Override std::exception::what().
		 */
		const char* what() const throw() { return getFullDescription().c_str(); }
	};

	/** 
	 * Unexpected exception.
	 */
	class SKGE_API UnexpectedException: public Exception{
	public:
		UnexpectedException(const String& _error):
		  Exception("UnexpectedException", _error){}
	};

	/** 
	 * Invalid Resource Exception.
	 */
	class SKGE_API InvalidResourceException: public Exception{
	public:
		InvalidResourceException(const String& _error):
		  Exception("InvalidResourceException", _error){}
	};

	/** 
	 * Initialization Failed Exception.
	 */
	class SKGE_API InitializationFailedException: public Exception{
	public:
		InitializationFailedException(const String& _error):
		  Exception("InitializationFailedException", _error){}
	};

	/** 
	 * Dynamic Library Loading Failed.
	 */
	class SKGE_API DynamicLibraryLoadingFailed: public Exception{
	public:
		DynamicLibraryLoadingFailed(const String& _error):
		  Exception("DynamicLibraryLoadingFailed", _error){}
	};

}

#endif