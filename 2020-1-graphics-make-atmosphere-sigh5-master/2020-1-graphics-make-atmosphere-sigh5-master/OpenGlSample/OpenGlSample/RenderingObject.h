#pragma once
#include "Object.h"



class RenderingObject:public Object
{

public:
	GLuint VertexArrayID;
	GLuint programID;
	GLuint MatrixID;
	GLuint ViewMatrixID;
	GLuint ModelMatrixID;
	GLuint Texture;
	GLuint TextureID;

	std::vector<glm::vec3> vertices;
	std::vector<glm::vec2> uvs;
	std::vector<glm::vec3> normals;

	GLuint vertexbuffer;
	GLuint uvbuffer;
	GLuint normalbuffer;
	GLuint LightID;

public:
	float _Obj1PositionX;
	float _Obj1PositionY;
	float _Obj1PositionZ;

	

public:
	virtual void shutDown() override;
	virtual void setXYZ(float x, float y, float z)override;


};