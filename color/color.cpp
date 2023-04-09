#include "color.hpp"

Color::Color(color_t red, color_t green, 
	         color_t blue, color_t alpha):
	red_(red),
	green_(green),
	blue_(blue),
	alpha_(alpha)
{

}

Color::~Color()
{
	red_   = 255;
	green_ = 255;
	blue_  = 255;
	alpha_ = 255;
}

color_t Color::red() const
{
	return red_;
}

color_t Color::green() const
{
	return green_;
}

color_t Color::blue() const
{
	return blue_;
}

color_t Color::alpha() const
{
	return alpha_;
}

Color operator*(const Color &color, long double num)
{
	return Color(((unsigned)(color.red()   * num) > 255) ? 255 : (color_t)(color.red()   * num),
		         ((unsigned)(color.green() * num) > 255) ? 255 : (color_t)(color.green() * num),
		         ((unsigned)(color.blue()  * num) > 255) ? 255 : (color_t)(color.blue()  * num),
		         ((unsigned)(color.alpha() * num) > 255) ? 255 : (color_t)(color.alpha() * num));
}
