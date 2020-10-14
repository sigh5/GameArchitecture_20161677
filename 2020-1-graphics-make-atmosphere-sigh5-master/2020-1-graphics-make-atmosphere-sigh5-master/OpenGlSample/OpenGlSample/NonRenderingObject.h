#include "Object.h"


class NonRenderingObject :public Object {

public:
	virtual void shutDown()override {} 

	virtual void setXYZ(float x, float y, float z)override;


};


