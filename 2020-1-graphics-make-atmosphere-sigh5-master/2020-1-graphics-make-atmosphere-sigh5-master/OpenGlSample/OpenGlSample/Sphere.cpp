#include "Sphere.h"
#include "FileManager.h"

void Sphere::shutDown() {

	Object::shutDown();

	glDeleteBuffers(1, &vertexbuffer);
	glDeleteBuffers(1, &uvbuffer);
	glDeleteBuffers(1, &normalbuffer);
	glDeleteProgram(programID);
	glDeleteTextures(1, &Texture);
	glDeleteVertexArrays(1, &VertexArrayID);

}


void Sphere::setXYZ(float x, float y, float z) {

	_Obj1PositionX = x;
	_Obj1PositionY = y;
	_Obj1PositionZ = z;

}

void Sphere::loadSphere()
{

		file->loadObj(
			this,
			"sphere.obj",
			"moon.bmp",
			"20161677_황현욱_vs.shader",
			"20161677_황현욱_fs.shader"
		);
}


Sphere::Sphere()
{
	
	file = FileManager::instance();

	loadSphere();
}


void Sphere::loadVertexData()
{
	 _reobj->VertexArrayID= VertexArrayID2;
     _reobj->programID= programID2;
	 _reobj->MatrixID= MatrixID2;
	 _reobj->ViewMatrixID= ViewMatrixID2;
     _reobj->ModelMatrixID= ModelMatrixID2;
     _reobj->Texture= Texture2;
     _reobj->TextureID= TextureID2;

     _reobj->vertices= vertices2;
	 _reobj->uvs = uvs2;
	 _reobj->normals= normals2;

	 _reobj->vertexbuffer= vertexbuffer2;
	 _reobj->uvbuffer= uvbuffer2;
	 _reobj->normalbuffer= normalbuffer2;
     _reobj->LightID= LightID2;
}
  
