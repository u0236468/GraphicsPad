#include "ShapeData.h"

class ShapeGenerator
{
	static ShapeData makePlaneUnseamedIndices(uint tesselation);
public:
	static ShapeData makePlaneVerts(uint dimensions);
	static ShapeData makePlaneIndices(uint dimensions);
	static ShapeData makePlane(uint dimensions);
	static ShapeData makeSphere(uint tesselation);
	static ShapeData makeTorus(uint tesselation);
};

