#include "Tetrahedron.h"

/// initalise tetrahedron variables
Tetrahedron::Tetrahedron() : xrot(0.0f), yrot(0.0f), zrot(0.0f){}

/// draw the tetrahedron
void Tetrahedron::Display()
{
	// Push the current transform matrix
	// for now just put it at the start and end of each draw call you make
    glPushMatrix();

	// Scale up the object
	glScalef(60.0f, 60.0f, 60.0f);

	// Apply an object space rotation 
	// this will rotate the object around its object space center
	glRotatef(zrot, 0.0f, 0.0f, 1.0f);
	glRotatef(yrot, 0.0f, 1.0f, 0.0f);
	glRotatef(xrot, 1.0f, 0.0f, 0.0f);

	// Set the draw colour to yellow
	glColor3ub(static_cast<GLubyte>(127), static_cast<GLubyte>(127), static_cast<GLubyte>(0));
    DrawTetrahedron();
	// Pop off the changes to the transform matrix
    glPopMatrix();
}

/// update the rotation of the tetrahedron with respect to the change in time
void Tetrahedron::Update(const double& deltaTime)
{
	// A simple update function just so we can see what we're doing
	xrot += 5.0f  * static_cast<float>(deltaTime);
	yrot += 12.0f * static_cast<float> (deltaTime);
	zrot += 14.0f * static_cast<float> (deltaTime);
}

/// draw 2D triforce
void Tetrahedron::DrawTetrahedron()
{
    //     Draw the Tetrahedron in Object Space Coordinates
    //     using only the GL_TRIANGLES
    //    /*
    //       @-------@
    //     / |     / |
    //    @--|----@  |
    //    |  @----|--@
    //    | /     | /
    //    @-------@
    
    // DrawTetrahedron
    glDisable(GL_CULL_FACE);
    // Enter triangle primitives
    glBegin(GL_TRIANGLES);
    glColor3f(1.0, 0.0, 0.0);  // Draw P1 red
    glVertex3f(1, 1, -1);
    glVertex3f(-1, 1, 1);
    glVertex3f(1, -1, 1);
    
    glColor3f(0.0, 1.0, 0.0);  // Draw P1 green
    glVertex3f(1, -1, 1);
    glVertex3f(-1, 1, 1);
    glVertex3f(-1, -1, -1);
    
    glColor3f(0.0, 0.0, 1.0);  // Draw P1 blue
    glVertex3f(-1, -1, -1);
    glVertex3f(-1, 1, 1);
    glVertex3f(1, 1, -1);
    
    glColor3f(1.0, 1.0, 0.0);  // Draw P1
    glVertex3f(1, 1, -1);
    glVertex3f(1, -1, 1);
    glVertex3f(-1, -1, -1);
    
    // Draw cobe using triangle
    glColor4f(0.5, 0.5, 0.5, 0.5);  // ABC
    glVertex3f(-1, 1, 1);
    glVertex3f(-1, -1, 1);
    glVertex3f(1, -1, 1);
    
    glColor4f(0.5, 0.5, 0.5, 0.5);  // ACD
    glVertex3f(-1, 1, 1);
    glVertex3f(1, -1, 1);
    glVertex3f(1, 1, 1);
    
    glColor4f(0.5, 0.5, 0.5, 0.5);  // DCG
    glVertex3f(1, 1, 1);
    glVertex3f(1, -1, 1);
    glVertex3f(1, 1, -1);
    
    glColor4f(0.5, 0.5, 0.5, 0.5);  // GCF
    glVertex3f(1, 1, -1);
    glVertex3f(1, -1, 1);
    glVertex3f(1, -1, -1);
    
    glColor4f(0.5, 0.5, 0.5, 0.5);  // ADG
    glVertex3f(-1, 1, 1);
    glVertex3f(1, 1, 1);
    glVertex3f(1, 1, -1);
    
    glColor4f(0.5, 0.5, 0.5, 0.5);  // AGH
    glVertex3f(-1, 1, 1);
    glVertex3f(1, 1, -1);
    glVertex3f(-1, 1, -1);
    
    glColor4f(0.5, 0.5, 0.5, 0.5);  // AEB
    glVertex3f(-1, 1, 1);
    glVertex3f(-1, -1, -1);
    glVertex3f(-1, -1, 1);
    
    glColor4f(0.5, 0.5, 0.5, 0.5);  // AHE
    glVertex3f(-1, 1, 1);
    glVertex3f(-1, 1, -1);
    glVertex3f(-1, -1, -1);
    
    glColor4f(0.5, 0.5, 0.5, 0.5);  // HGE
    glVertex3f(-1, 1, -1);
    glVertex3f(1, 1, -1);
    glVertex3f(-1, -1, -1);
    
    glColor4f(0.5, 0.5, 0.5, 0.5);  // GFE
    glVertex3f(1, 1, -1);
    glVertex3f(1, -1, -1);
    glVertex3f(-1, -1, -1);
    
    glColor4f(0.5, 0.5, 0.5, 0.5);  // ECB
    glVertex3f(-1, -1, -1);
    glVertex3f(1, -1, 1);
    glVertex3f(-1, -1, 1);
    
    glColor4f(0.5, 0.5, 0.5, 0.5);  // EFC
    glVertex3f(-1, -1, -1);
    glVertex3f(1, -1, -1);
    glVertex3f(1, -1, 1);
    
    // Stop triangle primitives
    glEnd();

    // draw border line to make the object more clear
    // Enter line primitives
    glBegin(GL_LINE_LOOP);
    glColor3f(0, 0, 0);     // ADCB
    glVertex3f(-1, 1, 1);
    glVertex3f(1, 1, 1);
    glVertex3f(1, -1, 1);
    glVertex3f(-1, -1, 1);
    
    glColor3f(0, 0, 0);     // DCFG
    glVertex3f(1, 1, 1);
    glVertex3f(1, -1, 1);
    glVertex3f(1, -1, -1);
    glVertex3f(1, 1, -1);
   
    glColor3f(0, 0, 0);     // ADGH
    glVertex3f(-1, 1, 1);
    glVertex3f(1, 1, 1);
    glVertex3f(1, 1, -1);
    glVertex3f(-1, 1, -1);
    
    glColor3f(0, 0, 0);     // AHEB
    glVertex3f(-1, 1, 1);
    glVertex3f(-1, 1, -1);
    glVertex3f(-1, -1, -1);
    glVertex3f(-1, -1, 1);

    glColor3f(0, 0, 0);     // HGFE
    glVertex3f(-1, 1, -1);
    glVertex3f(1, 1, -1);
    glVertex3f(1, -1, -1);
    glVertex3f(-1, -1, -1);
    
    glColor3f(0, 0, 0);     // EFCB
    glVertex3f(-1, -1, -1);
    glVertex3f(1, -1, -1);
    glVertex3f(1, -1, 1);
    glVertex3f(-1, -1, 1);
    glEnd();
    //    Reactivate backface culling so that it works for other objects in the scene
    //    glEnable(GL_CULL_FACE);
}
