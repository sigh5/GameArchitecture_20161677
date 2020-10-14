#include "FileManager.h"
#include "Object.h"
#include "FileManager.h"
#include "Renderer.h"

GLFWwindow* window;

using namespace glm;
using namespace std;




int main()
{
	FileManager *fileMgr;
	Object *cube;
	Object *human;

	fileMgr->loadCubeFileInfo(cube);
	fileMgr->loadHumanFileInfo(human);
	

	Renderer *renderer;

	
	renderer->draw(cube);
	renderer->draw(human);



}
