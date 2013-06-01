/*
* This File is a part of SK-Game Engine.
* 
* Copyright (c) 2009 by Dmitry skwo Kudryavtsev / SK-Software
* s.kwee357@gmail.com
*/

#ifndef SKGE_MESH_MANAGER_H_
#define SKGE_MESH_MANAGER_H_

#include "SkgeResourceManager.hpp"
#include "SkgeMesh.hpp"
#include "SkgeSingleton.hpp"

namespace skge{

	/** 
	 * Mesh Manager.
	 */
	class SKGE_API MeshManager: public ResourceManager<MeshPtr>, public Singleton<MeshManager>{
	public:
		/** 
		 * Constructor.
		 */
		MeshManager(){}

		/** 
		 * Destructor.
		 */
		~MeshManager(){}

		/** 
		 * Create raw mesh.
		 * @param _name Mesh name.
		 * @param _vertexes Vertexes to create mesh from.
		 * @param _type Primitive type.
		 */
		MeshPtr createRaw(const String& _name, const Mesh::VertexList& _vertexes, Mesh::PrimitiveType _type);
	};

}

#endif