/*
* This File is a part of SK-Game Engine.
* 
* Copyright (c) 2009 by Dmitry skwo Kudryavtsev / SK-Software
* s.kwee357@gmail.com
*/

#ifndef SKGE_MESH_H_
#define SKGE_MESH_H_

#include "SkgeResource.hpp"
#include "Math/SkgeVector3.hpp"

#include "SkgeLogger.hpp"

namespace skge{

	/** 
	 * Mesh holds geometric information of 3D Object.
	 */
	class SKGE_API Mesh: public Resource{
	public:
		/** 
		* Define vector list
		*/
		typedef std::vector<Vector3> VertexList;

		/** 
		 * Primitive Type.
		 */
		enum PrimitiveType{
			TriangleList,
			TriangleFan,
			TriangleStrip
		};

	protected:
		VertexList m_Vertexes; /**< Vertexes. */
		PrimitiveType m_Type; /**< Primitive type. */

	public:
		/** 
		 * Mesh constructor.
		 * @param _name Mesh name.
		 */
		Mesh(const String& _name):Resource(_name){}

		/** 
		 * Raw mesh constructor.
		 * @param _name Mesh name.
		 * @param _vertexes Vertexes to create mesh from.
		 * @param _type Primitive type.
		 */
		Mesh(const String& _name, const VertexList& _vertexes, PrimitiveType _type):
		Resource(_name), m_Vertexes(_vertexes), m_Type(_type){
			m_Loaded = true;

			Logger::getInstance()->log("Mesh " + _name + " created!");
		}

		/** 
		 * Destructor.
		 */
		virtual ~Mesh(){
			m_Vertexes.clear();

			Logger::getInstance()->log("Mesh " + m_Info.getName() + " destroyed!");
		}

		/** 
		 * Get mesh vertexes.
		 * @return Mesh vertexes.
		 */
		const VertexList& getVertexes() const { return m_Vertexes; }

		/** 
		 * Get primitive type.
		 * @return Mesh primitive type.
		 */
		PrimitiveType getPrimitiveType() const { return m_Type; }
	};

	/** 
	 * Define mesh pointer.
	 */
	typedef boost::shared_ptr<Mesh> MeshPtr;

}

#endif