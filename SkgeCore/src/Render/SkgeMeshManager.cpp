/*
* This File is a part of SK-Game Engine.
* 
* Copyright (c) 2009 by Dmitry skwo Kudryavtsev / SK-Software
* s.kwee357@gmail.com
*/

#include "Render/SkgeMeshManager.hpp"
#include "SkgeException.hpp"

namespace skge{

	DECLARE_SINGLETON(MeshManager);

	MeshPtr MeshManager::createRaw(const String& _name, const Mesh::VertexList& _vertexes, Mesh::PrimitiveType _type){
		if( ! isNameUnique(_name)){
			throw InvalidResourceException("Mesh with name " + _name + " was already loaded!");
		}

		//Create mesh
		MeshPtr mesh = MeshPtr(new Mesh(_name, _vertexes, _type));

		//Add to resource map
		m_ResourceMap[_name] = mesh;

		//Return mesh
		return mesh;
	}

}