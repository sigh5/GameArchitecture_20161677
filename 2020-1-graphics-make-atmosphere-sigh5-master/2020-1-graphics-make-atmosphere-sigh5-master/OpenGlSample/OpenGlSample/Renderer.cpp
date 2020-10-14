#include <stdio.h>

#include "Object.h"
#include "Renderer.h"
#include "RenderingObject.h"
#include "Sphere.h"

#include "glm/glm.hpp"
#include "glm/gtc/matrix_transform.hpp"
#include "include/GL/glew.h"
#include "include/GLFW/glfw3.h" 
#include "Obj.h"

GLFWwindow* window;

void Renderer::init()
{

	if (!glfwInit())
	{
		fprintf(stderr, "Failed to initialize GLFW\n");
		getchar();
		return;
	}

	glfwWindowHint(GLFW_SAMPLES, 4);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
	glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

	window = glfwCreateWindow(1024, 768, "Graphics_FinalTest_20161651", NULL, NULL);
	
	if (window == NULL) {
		fprintf(stderr, "Failed to open GLFW window. If you have an Intel GPU, they are not 3.3 compatible. Try the 2.1 version of the tutorials.\n");
		getchar();
		glfwTerminate();
		return;
	}
	glfwMakeContextCurrent(window);

	glewExperimental = true;
	if (glewInit() != GLEW_OK) {
		fprintf(stderr, "Failed to initialize GLEW\n");
		getchar();
		glfwTerminate();
		return ;
	}

	glfwSetInputMode(window, GLFW_STICKY_KEYS, GL_TRUE);

	glfwPollEvents();
	glfwSetCursorPos(window, 1024 / 2, 768 / 2);

	glClearColor(0.0f, 0.5f, 0.0f, 0.0f);

	glEnable(GL_DEPTH_TEST);

	glDepthFunc(GL_LESS);

	glEnable(GL_CULL_FACE);

}


void Renderer::setXYZ(float x, float y, float z)
{
	
	_camera_a = x;
	_camera_b = y;
	_camera_c = z;

}

glm::mat4 Renderer::getCameraPosition() const
{
	float a, b, c = 0;
	a = _camera_a;
	b = _camera_b;
	c = _camera_c;

	glm::mat4 SunViewMatrix = glm::lookAt(
			glm::vec3(a, b, c),
			glm::vec3(0, 0, 0),
			glm::vec3(0, 1, 0)
		);

	return SunViewMatrix;
}

glm::mat4 Renderer::getMatrixTranslatePosition(glm::mat4 Model, RenderingObject *obj)
{
	float a, b, c = 0;
	
	a = obj->_Obj1PositionX;
	b = obj->_Obj1PositionY;
	c = obj->_Obj1PositionZ;

	Model = glm::translate(Model, glm::vec3(a, b, c));

	return Model;
}



void Renderer::renderer(RenderingObject* _object)
{
	if (_object == sphere)
	{
		sphere->loadVertexData();
	}


	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	glUseProgram(_object->programID);

	glm::mat4 SunProjectionMatrix = glm::perspective(glm::radians(45.0f), 4.0f / 3.0f, 0.1f, 100.0f);

	glm::mat4 SunViewMatrix = getCameraPosition();
	glm::mat4 SunModelMatrix = glm::mat4(1.0);
	
	

	//SunModelMatrix = glm::translate(SunModelMatrix, glm::vec3(5, 0, 0));
	SunModelMatrix = getMatrixTranslatePosition(SunModelMatrix, _object);

	glm::mat4 SunMVP = SunProjectionMatrix * SunViewMatrix*SunModelMatrix;


	glUniformMatrix4fv(_object->MatrixID, 1, GL_FALSE, &SunMVP[0][0]);
	glUniformMatrix4fv(_object->ModelMatrixID, 1, GL_FALSE, &SunModelMatrix[0][0]);
	glUniformMatrix4fv(_object->ViewMatrixID, 1, GL_FALSE, &SunViewMatrix[0][0]);

	


	glActiveTexture(GL_TEXTURE0);
	glBindTexture(GL_TEXTURE_2D, _object->Texture);

	glUniform1i(_object->TextureID, 0);

	//Vertex정보
	glEnableVertexAttribArray(0);
	glBindBuffer(GL_ARRAY_BUFFER, _object->vertexbuffer);
	glVertexAttribPointer(
		0,
		3,
		GL_FLOAT,
		GL_FALSE,
		0,
		(void*)0
	);

	//UV정보
	glEnableVertexAttribArray(1);
	glBindBuffer(GL_ARRAY_BUFFER, _object->uvbuffer);
	glVertexAttribPointer(
		1,
		2,
		GL_FLOAT,
		GL_FALSE,
		0,
		(void*)0
	);

	glEnableVertexAttribArray(2);
	glBindBuffer(GL_ARRAY_BUFFER, _object->normalbuffer);
	glVertexAttribPointer(
		2,
		3,
		GL_FLOAT,
		GL_FALSE,
		0,
		(void*)0
	);

	glDrawArrays(GL_TRIANGLES, 0, _object->vertices.size());

	glDisableVertexAttribArray(0);
	glDisableVertexAttribArray(1);
	glDisableVertexAttribArray(2);
	

	glfwSwapBuffers(window);
	glfwPollEvents();
}








void Renderer::shutDown()
{
	glfwTerminate();
}