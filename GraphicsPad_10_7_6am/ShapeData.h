#pragma once
#include <glm\glm.hpp>
typedef unsigned int uint;
typedef unsigned short ushort;

struct Vertex
{
	//10 floats
	glm::vec3 position;
	glm::vec4 color;
	glm::vec3 normal;
};

struct ShapeData
{
	uint numVerts;
	Vertex* verts;
	uint numIndices;
	ushort* indices;

	uint vertexBufferSize() const
	{
		return numVerts * sizeof(Vertex);
	}

	uint indexBufferSize() const
	{
		return numIndices * sizeof(ushort);
	}

	void cleanup()
	{
		delete[] verts;
		delete[] indices;
		verts = 0;
		indices = 0;
	}
};