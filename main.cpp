#include "canvas.hpp"
#include "sphere.hpp"

int main()
{
	Canvas canvas(400, 400);
	Scene scene(&canvas, Scene::LightSource(1.0, 1.0, 1.0, 1.0), Scene::Viewpoint(-1.0, -1.0, -1.0));
	Sphere3D sphere(&scene, 0.0, 0.0, 0.0, 0.5);

	while (!canvas.isHidden()) {
		canvas.clearRender();

		Event event{};
		event.poll();
		canvas.processEvent(event);

		scene.rotateViewpoint(0.5);
		scene.rotateLightSource(0.5);
		sphere.render();

		canvas.presentRender();
	}

	return 0;
}
