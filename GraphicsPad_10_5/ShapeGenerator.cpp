#include "ShapeGenerator.h"
#include <glm\glm.hpp>
#include <random>

glm::vec4 randomColor()
{
	glm::vec4 ret;
	ret.x = rand() / (float)RAND_MAX;
	ret.y = rand() / (float)RAND_MAX;
	ret.z = rand() / (float)RAND_MAX;
	ret.w = 1;
	return ret;
}

ShapeData ShapeGenerator::makePlaneVerts(uint dimensions)
{
	ShapeData ret;
	uint vertsPerDimension = dimensions + 1; // + 1 for last row/col of verts
	ret.numVerts = vertsPerDimension * vertsPerDimension;
	ret.verts = new Vertex[ret.numVerts];
	float half = dimensions / 2.0f;
	glm::vec3 runner(-half, 0.0f, -half);
	for (int i = 0; i < vertsPerDimension; i++)
	{
		for (int j = 0; j < vertsPerDimension; j++)
		{
			Vertex& thisVert = ret.verts[i * vertsPerDimension + j];
			thisVert.position = runner;
			thisVert.color = randomColor();
			thisVert.normal = glm::vec3(0, 1, 0);
			runner.x++;
		}
		runner.x = -half;
		runner.z++;
	}
	return ret;
}

ShapeData ShapeGenerator::makePlaneIndices(uint dimensions)
{
	ShapeData ret;
	uint vertsPerDimension = dimensions + 1;
	ret.numIndices = dimensions * dimensions * 2 * 3; // 2 triangles per square, 3 indices per triangle
	ret.indices = new unsigned short[ret.numIndices];
	int runner = 0;
	for (int row = 0; row < dimensions; row++)
	{
		for (int col = 0; col < dimensions; col++)
		{
			ret.indices[runner++] = vertsPerDimension * row + col;
			ret.indices[runner++] = vertsPerDimension * row + col + vertsPerDimension;
			ret.indices[runner++] = vertsPerDimension * row + col + vertsPerDimension + 1;

			ret.indices[runner++] = vertsPerDimension * row + col;
			ret.indices[runner++] = vertsPerDimension * row + col + vertsPerDimension + 1;
			ret.indices[runner++] = vertsPerDimension * row + col + 1;
		}
	}
	assert(runner = ret.numIndices);
	return ret;
}

ShapeData ShapeGenerator::makePlane(uint dimensions)
{
	ShapeData ret = makePlaneVerts(dimensions);
	ShapeData ret2 = makePlaneIndices(dimensions);
	ret.numIndices = ret2.numIndices;
	ret.indices = ret2.indices;
	return ret;
}
