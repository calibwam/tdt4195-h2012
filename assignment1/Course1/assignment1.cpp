#include <stdio.h>
#include <cstdlib>
#include "gl/glut.h"
#include "visuals.h"

void A1Render(){
	
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT); 
	glMatrixMode(GL_MODELVIEW); 
	glLoadIdentity();

	for (int i = 0; i<20; i++){
		//random color
		glColor3f(rand()/(float)RAND_MAX,rand()/(float)RAND_MAX,rand()/(float)RAND_MAX);

		// make the teapots easier to see
		glPushMatric();
		glTranslatef((rand()-(RAND_MAX/2))/(RAND_MAX/2)*20,(rand()-(RAND_MAX/2))/(RAND_MAX/2)*20,(rand()-(RAND_MAX/2))/(RAND_MAX/2)*20);

		//draw the teapot
		glutSolidTeapot(rand()%30+1);

		glPopMatrix();
	}

	glutReverseBuffers();
}

void A2Render() {
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT); 
	glMatrixMode(GL_MODELVIEW); 
	glLoadIdentity();
	
	// rotate the teapot
	glPushMatrix();
	glRotatef(30,0,0,-1);

	// draw the wireframe teapot
	glutWireTeapot(20.0);
	glPopMatrix();

	//set a blueish color
	glColor3f(0.2,0.3,1);

	// draw three water droplets
	glTranslatef(35,-20.0);
	glutSolidSphere(2.0,30,24);
	glTranslatef(0,-10.0);
	glutSolidSphere(2.0,30,24);
	glTranslatef(0,-10.0);
	glutSolidSphere(2.0,30,24);
	
	glutSwapBuffers();
}
