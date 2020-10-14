#include "RenderingObject.h"




void RenderingObject::shutDown() {

	Object::shutDown();

	glDeleteBuffers(1, &vertexbuffer);
	glDeleteBuffers(1, &uvbuffer);
	glDeleteBuffers(1, &normalbuffer);
	glDeleteProgram(programID);
	glDeleteTextures(1, &Texture);
	glDeleteVertexArrays(1, &VertexArrayID);

}

void RenderingObject::setXYZ(float x, float y, float z) {

	_Obj1PositionX = x;
	_Obj1PositionY = y;
	_Obj1PositionZ = z;

}
