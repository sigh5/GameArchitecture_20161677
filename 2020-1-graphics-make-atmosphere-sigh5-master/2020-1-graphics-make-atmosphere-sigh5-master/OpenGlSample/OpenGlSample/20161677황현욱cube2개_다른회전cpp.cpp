#define _CRT_SECURE_NO_WARNING

#pragma comment(lib, "OpenGL32.lib")
#pragma comment(lib, "lib-vc2017/glew32.lib")
#pragma comment(lib, "lib-vc2017/glfw3.lib")

#include "Object.h"
#include "FileManager.h"
#include "Renderer.h"
#include "RenderingObject.h"
#include "Sphere.h"
#include "Obj.h"



int main(void)
{
	FileManager *filemgr = FileManager::instance();

	Renderer *renderer = Renderer::instance();
	renderer->init();
	renderer->setXYZ(20.0f,2.0f,7.0f); //camera ���� �̵�


	Obj *cube = new Obj();
	
	filemgr->loadObj(
	cube,
	"cube.obj",
	"moon.bmp",
	"20161677_Ȳ����_vs.shader",
	"20161677_Ȳ����_fs.shader"
);
	cube->setXYZ(10.0f,5.0f,0.0f); //���� ��ġ�̵�



	Sphere *sphere = new Sphere();
	
	sphere->setXYZ(10.0f, 2.0f, 1.0f); //�� ��ǥ�̵�
	

	while (true)
		{	
			renderer->renderer(sphere);
		  //  renderer->renderer(cube);
		}
		


	cube->shutDown();
	sphere->shutDown();
	renderer->shutDown();
	

	//delete cube;
	
	delete sphere;
	delete cube;
	return 0;
}
