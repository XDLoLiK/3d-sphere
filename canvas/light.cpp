#include "scene.hpp"

Scene::LightSource::LightSource(long double xCU, long double yCU, 
	                            long double zCU, long double intensity):
	xCU_(xCU),
	yCU_(yCU),
	zCU_(zCU),
	intensity_((intensity > 1.0) ? 1.0 : intensity)
{

}

Scene::LightSource::~LightSource()
{
	xCU_ = yCU_ = zCU_ = 0.0;
}

long double Scene::LightSource::xCU() const
{
	return xCU_;
}

long double Scene::LightSource::yCU() const
{
	return yCU_;
}

long double Scene::LightSource::zCU() const
{
	return zCU_;
}

long double Scene::LightSource::intensity() const
{
	return intensity_;
}

void Scene::LightSource::xCU(long double x)
{
	xCU_ = x;
}

void Scene::LightSource::yCU(long double y)
{
	yCU_ = y;
}

void Scene::LightSource::zCU(long double z)
{
	zCU_ = z;
}

void Scene::rotateLightSource(long double angle, bool isRadians)
{
	if (!isRadians)
		angle = angle * M_PI / 180.0;

	long double cosAngle = cosl(angle);
	long double sinAngle = sinl(angle);

	long double newX = cosAngle * lightSource_.xCU() - sinAngle * lightSource_.yCU();
	long double newY = sinAngle * lightSource_.xCU() + cosAngle * lightSource_.yCU();

	lightSource_.xCU(newX);
	lightSource_.yCU(newY);
}
