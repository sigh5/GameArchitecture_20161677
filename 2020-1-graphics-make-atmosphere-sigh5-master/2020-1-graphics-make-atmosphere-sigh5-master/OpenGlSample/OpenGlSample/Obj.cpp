#include "Obj.h"



void Obj::shutDown() {

	Object::shutDown();

	

}

void Obj::setXYZ(float x, float y, float z) {

	RenderingObject::setXYZ( x,  y,  z);

}

Obj::Obj()
{
	VertexArrayID;
	programID ;
	MatrixID;
	ViewMatrixID;
	ModelMatrixID;
	Texture ;
	TextureID ;
	vertices;
	uvs ;
	normals;
	vertexbuffer;
	uvbuffer;
	normalbuffer;
}