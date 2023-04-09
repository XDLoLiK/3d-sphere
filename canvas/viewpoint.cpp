#include "scene.hpp"

Scene::Viewpoint::Viewpoint(long double xCU, long double yCU,
	                        long double zCU):
	xCU_(xCU),
	yCU_(yCU),
	zCU_(zCU)
{

}

Scene::Viewpoint::~Viewpoint()
{
	xCU_ = yCU_ = zCU_ = 0.0;
}

long double Scene::Viewpoint::xCU() const
{
	return xCU_;
}

long double Scene::Viewpoint::yCU() const
{
	return yCU_;
}

long double Scene::Viewpoint::zCU() const
{
	return zCU_;
}

void Scene::Viewpoint::xCU(long double x)
{
	xCU_ = x;
}

void Scene::Viewpoint::yCU(long double y)
{
	yCU_ = y;
}

void Scene::Viewpoint::zCU(long double z)
{
	zCU_ = z;
}

void Scene::rotateViewpoint(long double angle, bool isRadians)
{
	if (!isRadians)
		angle = angle * M_PI / 180.0;

	long double cosAngle = cos(angle);
	long double sinAngle = sin(angle);

	long double newX = cosAngle * viewpoint_.xCU() - sinAngle * viewpoint_.yCU();
	long double newY = sinAngle * viewpoint_.xCU() + cosAngle * viewpoint_.yCU();

	viewpoint_.xCU(newX);
	viewpoint_.yCU(newY);
}
