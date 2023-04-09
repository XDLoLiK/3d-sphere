#ifndef COLOR_H
#define COLOR_H

using color_t = unsigned char;

class Color {
private:
	color_t red_   = 255;
	color_t green_ = 0;
	color_t blue_  = 0;
	color_t alpha_ = 255;

public:
	Color(color_t red_,  color_t green_, 
		  color_t blue_, color_t alpha_);
	~Color();

	color_t red() const;
	color_t green() const;
	color_t blue() const;
	color_t alpha() const;
};

Color operator*(const Color &color, long double num);

#endif // COLOR_H
