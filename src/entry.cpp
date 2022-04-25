/*
 *  Author: Peter Bou Saada
 *  Filename: entry.cpp
 *  Description: Entry point for the Renderer, creates an application object and runs it.
 */

#include <Renderer/Core.h>

int main()
{
	Renderer::Application *app = new Renderer::Application();

	app->OnRun();

	delete app;

	return 0;
}