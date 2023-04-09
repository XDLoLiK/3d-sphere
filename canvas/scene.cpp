#include "scene.hpp"

Scene::Scene(const Canvas *canvas, const LightSource &lightSource, 
	         const Viewpoint &viewpoint):
	canvas_(canvas),
	lightSource_(lightSource),
	viewpoint_(viewpoint)
{

}

Scene::~Scene()
{

}

Scene::LightSource Scene::lightSource() const
{
	return lightSource_;
}

Scene::Viewpoint Scene::viewpoint() const
{
	return viewpoint_;
}
