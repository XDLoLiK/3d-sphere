#ifndef SPHERE_H
#define SPHERE_H

#include <cmath>

#include "scene.hpp"
#include "color.hpp"
#include "maths.hpp"

class Sphere3D {
public:
	const Scene *scene_;

private:
	long double xCenter_ = 0.0;
	long double yCenter_ = 0.0;
	long double zCenter_ = 0.0;
	long double radius_  = 0.0;

	Color color_= Color(255, 255, 255, 255);

public:	
	Sphere3D(const Scene *scence,
		     long double xCenter, long double yCenter, long double zCenter,
		     long double radius, const Color &color = Color(255, 255, 255, 255));
	Sphere3D(const Sphere3D &sphere) = delete;
	Sphere3D operator=(const Sphere3D &sphere) = delete;
	~Sphere3D();

	void render() const;
};

class Vector3D {
private:
	long double x_ = 0.0;
	long double y_ = 0.0;
	long double z_ = 0.0;

	long double length_ = 0.0;

public:
	Vector3D(long double x,  long double y,  long double z);
	Vector3D(long double x0, long double y0, long double z0,
		     long double x1, long double y1, long double z1);
	~Vector3D();

	/* Getters */
	long double x() const;
	long double y() const;
	long double z() const;

	void resize(long double length);
};

long double cosAngle(const Vector3D &vec1, const Vector3D &vec2);

#endif // SPHERE_H
