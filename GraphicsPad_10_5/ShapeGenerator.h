#include "ShapeData.h"

class ShapeGenerator
{
public:
	static ShapeData makePlaneVerts(uint dimensions);
	static ShapeData makePlaneIndices(uint dimensions);
	static ShapeData makePlane(uint dimensions);
};

