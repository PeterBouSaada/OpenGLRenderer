#include <Renderer/Core.h>

int main()
{
	Renderer::Application *app = new Renderer::Application();

	app->OnRun();

	delete app;

	return 0;
}