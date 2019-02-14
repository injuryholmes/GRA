#pragma once

#include "DisplayableObject.h"
#include "Animation.h"

class Tetrahedron :
	public DisplayableObject,
	public Animation
{
public:
	Tetrahedron();
	~Tetrahedron(){};

	// Override the DisplayableObject's Draw function
	void Display();
	// Override the Animation Update function
	void Update(const double& deltaTime);

private:
	void DrawTetrahedron();
	// Private members to track the rotation of the Tetrahedron
	GLfloat xrot, yrot, zrot;
};

