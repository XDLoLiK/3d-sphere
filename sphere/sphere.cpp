#include "sphere.hpp"

Sphere3D::Sphere3D(const Scene *scene,
	               long double xCenter, long double yCenter, long double zCenter,
	               long double radius,  const Color &color):
	scene_(scene),
	xCenter_(xCenter),
	yCenter_(yCenter),
	zCenter_(zCenter),
	radius_(radius),
	color_(color)
{

}

Sphere3D::~Sphere3D()
{
	xCenter_ = yCenter_ = zCenter_ = radius_ = 0.0;
}

void Sphere3D::render() const
{
	const Canvas *canvas   = scene_->canvas_;
	SDL_Renderer *renderer = canvas->renderer();
	SDL_Window   *window   = canvas->window();

	int widthPixels  = 0;
	int heightPixels = 0;
	SDL_GetWindowSize(window, &widthPixels, &heightPixels);

	Scene::Viewpoint   viewpoint   = scene_->viewpoint();
	Scene::LightSource lightSource = scene_->lightSource();

	long double radiusSquared  = powl(radius_, 2);
    long double lightIntensity = scene_->lightSource().intensity();

	for (int y = 0; y < heightPixels; y++) {
		for (int x = 0; x < widthPixels; x++) {
			/* X, Y coordinates in CU */
			long double xCoord = canvas->xToCU(x);
			long double yCoord = canvas->yToCU(y);

			if (powl(xCenter_ - xCoord, 2) + powl(yCenter_ - yCoord, 2) <= radiusSquared) {
				/* Z coordinate in CU */
				long double zCoord = sqrtl(radiusSquared - powl(xCenter_ - xCoord, 2) - powl(yCenter_ - yCoord, 2)) + zCenter_;

				Vector3D normalVector(xCenter_, yCenter_, zCenter_, xCoord, yCoord, zCoord);
				Vector3D  lightVector(xCoord, yCoord, zCoord, lightSource.xCU(), lightSource.yCU(), lightSource.zCU());

				long double cosDiffuse = cosAngle(normalVector, lightVector);
				cosDiffuse = (cosDiffuse > 0) ? cosDiffuse : 0;

				normalVector.resize(2 * cosDiffuse);
				 lightVector.resize(1);

				Vector3D vectorReflected(normalVector.x() - lightVector.x(), normalVector.y() - lightVector.y(), normalVector.z() - lightVector.z());
				Vector3D vectorViewpoint(xCoord, yCoord, zCoord, viewpoint.xCU(), viewpoint.yCU(), viewpoint.zCU());

				long double ambientCoeff = 2.5;
				long double cosAmbient = cosAngle(vectorReflected, vectorViewpoint);
				cosAmbient = (cosAmbient > 0) ? cosAmbient : 0;

				Color color = color_ * cosDiffuse * cosAmbient * lightIntensity * ambientCoeff;
				SDL_SetRenderDrawColor(renderer, color.red(),  color.green(), color.blue(), color.alpha());
				SDL_RenderDrawPoint(renderer, x, y);
			}
		} /* for X end */
	} /* for Y end */
}
