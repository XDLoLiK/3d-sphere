#ifndef SCENE_H
#define SCENE_H

#include "canvas.hpp"

class Scene {
public:
	/* Parent canvas */
	const Canvas *canvas_;
	
	/* Light Sources exists only inside of a scene */
	class LightSource {
	private:
		/* USE VECTOR !!!!!!!!!!!!!!!! */
		long double xCU_ = 0.0;
		long double yCU_ = 0.0;
		long double zCU_ = 0.0;

		long double intensity_ = 1.0;

	public:
		LightSource(long double xCU, long double yCU, 
			        long double zCU, long double intensity = 1.0);
		~LightSource();

		long double xCU() const;
		long double yCU() const;
		long double zCU() const;
		long double intensity() const;

		void xCU(long double x);
		void yCU(long double y);
		void zCU(long double z);
	};

	/* Viewpoint exists only inside of a scene */
	class Viewpoint {
	private:
		/* USE VECTOR !!!!!!!!!!!!!!!! */
		long double xCU_ = 0.0;
		long double yCU_ = 0.0;
		long double zCU_ = 0.0;

	public:
		Viewpoint(long double xCU, long double yCU,
			      long double zCU);
		~Viewpoint();

		long double xCU() const;
		long double yCU() const;
		long double zCU() const;

		void xCU(long double x);
		void yCU(long double y);
		void zCU(long double z);
	};

private:
	LightSource lightSource_ = LightSource(0.0, 0.0, 0.0);
	Viewpoint   viewpoint_   = Viewpoint  (0.0, 0.0, 0.0);

public:
	Scene(const Canvas *canvas, const LightSource &lightSource = LightSource(0.0, 0.0, 0.0, 1.0), 
		  const Viewpoint &viewpoint = Viewpoint(0.0, 0.0, 0.0));
	Scene(const Scene &scene) = delete;
	Scene operator=(const Scene &scene) = delete;
	~Scene();

	/* Getters */
	LightSource lightSource() const;
	Viewpoint   viewpoint()   const;

	/* BAD!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!! */
	void rotateLightSource(long double angle, bool isRadians = false);
	void rotateViewpoint(long double angle, bool isRadians = false);
};

#endif // SCENE_H
