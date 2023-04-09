#include "sphere.hpp"

Vector3D::Vector3D(long double x, long double y, long double z):
	x_(x),
	y_(y),
	z_(z),
	length_(sqrtl(powl(x_, 2) + powl(y_, 2) + powl(z_, 2)))
{

}

Vector3D::Vector3D(long double x0, long double y0, long double z0,
		           long double x1, long double y1, long double z1):
	x_(x1 - x0),
	y_(y1 - y0),
	z_(z1 - z0),
	length_(sqrtl(powl(x_, 2) + powl(y_, 2) + powl(z_, 2)))
{

}

Vector3D::~Vector3D()
{
	x_ = y_ = z_ = 0.0;
}

long double Vector3D::x() const
{
	return x_;
}

long double Vector3D::y() const
{
	return y_;
}

long double Vector3D::z() const
{
	return z_;
}

void Vector3D::resize(long double length)
{
	long double sqrtLength    = sqrtl(length_);
	long double sqrtNewLength = sqrtl(length );

	x_ = x_ / sqrtLength * sqrtNewLength;
	y_ = y_ / sqrtLength * sqrtNewLength;
	z_ = z_ / sqrtLength * sqrtNewLength;
}

long double cosAngle(const Vector3D &vec1, const Vector3D &vec2)
{
	long double numerator   = vec1.x() * vec2.x() + vec1.y() * vec2.y() + vec1.z() * vec2.z();
	long double denominator = sqrtl(powl(vec1.x(), 2) + powl(vec1.y(), 2) + powl(vec1.z(), 2)) *
	                          sqrtl(powl(vec2.x(), 2) + powl(vec2.y(), 2) + powl(vec2.z(), 2));
	return (compare(denominator, 0.0)) ? 0 : (numerator / denominator);
}
