#pragma once
#include <vector>

#include "glm/glm.hpp"
#include "include/GL/glew.h"

#include "ICleanUp.h"
#include "ISetPosition.h"


class Object :public ICleanUp, ISetPosition
{
public:

	virtual ~Object(){ }
};