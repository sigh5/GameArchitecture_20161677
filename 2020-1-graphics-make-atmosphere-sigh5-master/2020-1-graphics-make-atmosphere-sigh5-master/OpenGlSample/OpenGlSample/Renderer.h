#include "ICleanUp.h"
#include "ISetPosition.h"

class Object;
class RenderingObject;
class Sphere;

class Renderer :public ICleanUp, ISetPosition
{
private:
	
	float _camera_a;
	float _camera_b;
	float _camera_c;

	Sphere *sphere;
public:

	static Renderer* instance() {

		static Renderer instance;

		return &instance;
	}
	
public:

	void init();
	void renderer(RenderingObject* _object);  //쉐이더1
	glm::mat4 getMatrixTranslatePosition(glm::mat4 Model, RenderingObject *obj);
	glm::mat4 getCameraPosition()const; //camera 시점 이동
	

public:
	
	virtual void shutDown()override;
	virtual void setXYZ(float x, float y, float z)override; 

};