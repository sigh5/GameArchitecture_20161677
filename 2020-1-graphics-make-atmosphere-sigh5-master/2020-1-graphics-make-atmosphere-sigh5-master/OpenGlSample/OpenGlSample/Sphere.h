#include "RenderingObject.h"

class RenderingObject;
class FileManager;

class Sphere :public RenderingObject {

public:

	GLuint VertexArrayID2;
	GLuint programID2;
	GLuint MatrixID2;
	GLuint ViewMatrixID2;
	GLuint ModelMatrixID2;
	GLuint Texture2;
	GLuint TextureID2;

	std::vector<glm::vec3> vertices2;
	std::vector<glm::vec2> uvs2;
	std::vector<glm::vec3> normals2;

	GLuint vertexbuffer2;
	GLuint uvbuffer2;
	GLuint normalbuffer2;
	GLuint LightID2;

private:

	FileManager *file;
	
	RenderingObject *_reobj;


public:
	Sphere();
	void loadSphere();
	
	void loadVertexData();


public:
	virtual void shutDown() override;
	virtual void setXYZ(float x, float y, float z)override;

};