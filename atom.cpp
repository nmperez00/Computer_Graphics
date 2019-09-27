//Atom
//Description: Creates an animated atom-like structure which has a nucleus and orbiting particles around it
//Authors: Nicholas Perez, Chad McAdams
//California State University San Bernardino
//CSE 420: Computer Graphics
//Professor: Dr. Tong Lai Yu

#include <stdlib.h>
#include <math.h>
#include <GL/glut.h>

//Initial variables
static int rotate_x = 0, rotate_y = 0;
int state = 1;
int initial_translate = -10;
int new_color1 = 1;
int new_color2 = 1;
GLfloat angle = 0.0f;
GLfloat rotate = 0.0f;
GLfloat z_control = 7.0f;
GLfloat Red_c1 = 1.0f;
GLfloat Green_c1 = 0.0f;
GLfloat Blue_c1 = 0.0f;
GLfloat Red_c2 = 0.1f;
GLfloat Green_c2 = 0.0f;
GLfloat Blue_c2 = 0.0f;


//Time function
int refreshmill = 1;
void timer(int value)
{
	glutPostRedisplay();
	glutTimerFunc(refreshmill, timer, 0);
}


//Other light sources
void init(void)
{
	GLfloat ambient[] = { 0.0, 0.0, 0.0, 1.0 };
	GLfloat diffuse[] = { 1.0, 1.0, 1.0, 1.0 };
	GLfloat position[] = { 0.0, 3.0, 2.0, 0.0 };
	GLfloat lmodel_ambient[] = { 0.4, 0.4, 0.4, 1.0 };
	GLfloat local_view[] = { 0.0 };

	glClearColor(0.0, 0.0, 0.0, 0.0); //Black Background
	glEnable(GL_DEPTH_TEST);
	glShadeModel(GL_SMOOTH);
	glLightfv(GL_LIGHT0, GL_AMBIENT, ambient);
	glLightfv(GL_LIGHT0, GL_DIFFUSE, diffuse);
	glLightfv(GL_LIGHT0, GL_POSITION, position);
	glLightModelfv(GL_LIGHT_MODEL_AMBIENT, lmodel_ambient);
	glLightModelfv(GL_LIGHT_MODEL_LOCAL_VIEWER, local_view);
	glEnable(GL_LIGHTING);
	glEnable(GL_LIGHT0);
}

void display(void)
{
	GLfloat mat_diffuse[] = { 1.0, 1.0, 1.0, 1.0 };
	GLfloat mat_specular[] = { 1.0, 1.0, 1.0, 1.0 };
	GLfloat high_shininess[] = { 100.0 };
	GLfloat red_particle[] = { 1.0, 0.0, 0.0, 1.0 };
	GLfloat blue_particle[] = { 0.0, 0.0, 1.0, 1.0 };
	GLfloat yellow_particle[] = { 1.0, 1.0, 0.0, 1.0 };
	GLfloat rainbow_mat1[] = { Red_c2, Green_c2, Blue_c2, 1.0 };
	GLfloat white_mat[] = { 0.1, 0.1, 0.1, 1.0 };
	GLfloat white_ring[] = { 1.0, 1.0, 1.0, 1.0 };
	GLfloat rainbow[] = { Red_c1, Green_c1, Blue_c1, 1.0 };

	//Orbiting Light around the Nucleus
	GLfloat position[] = { 0.0, 0.0, 0.0, 1.0 };
	glPushMatrix();
	glRotatef(-angle * 2, .0, 1.0, 1.0); //Oribtal Animation
	glTranslatef(-8.0, 0.0, 0.0); //Move translated object leftwards
	glLightfv(GL_LIGHT0, GL_POSITION, position); //Creates light source
	glPopMatrix();


	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	//----------Nucleus----------

	//Upper Sphere
	glPushMatrix();
	glMaterialfv(GL_FRONT, GL_AMBIENT, rainbow_mat1);
	glMaterialfv(GL_FRONT, GL_DIFFUSE, red_particle);
	glMaterialfv(GL_FRONT, GL_SPECULAR, mat_specular);
	glMaterialfv(GL_FRONT, GL_SHININESS, high_shininess);
	glMaterialfv(GL_FRONT, GL_EMISSION, rainbow_mat1);
	glTranslatef(0.0, 0.0, initial_translate); //Moves back z-axis
	glTranslatef(0.0, 0.0, (GLfloat)z_control); //Z-axis Animation
	glRotatef((GLint)rotate_x, 1.0, 0.0, 0.0); //Rotation X-axis control
	glRotatef((GLint)rotate_y, 0.0, 1.0, 0.0); //Rotation Y-axis control
	glRotatef(-angle * 0.5, 1.0, 1.0, 1.0); //Animation rotation
	glTranslatef(0.0, 1.0, 0.0); //Moves translated object to the top
	glutSolidSphere(1, 20, 20); //Creates Upper Sphere
	glPopMatrix();

	//Bottom Sphere
	glPushMatrix();
	glMaterialfv(GL_FRONT, GL_AMBIENT, rainbow_mat1);
	glMaterialfv(GL_FRONT, GL_DIFFUSE, red_particle);
	glMaterialfv(GL_FRONT, GL_SPECULAR, mat_specular);
	glMaterialfv(GL_FRONT, GL_SHININESS, high_shininess);
	glMaterialfv(GL_FRONT, GL_EMISSION, rainbow_mat1);
	glTranslatef(0.0, 0.0, initial_translate); //Moves back z-axis
	glTranslatef(0.0, 0.0, (GLfloat)z_control); //Z-axis Animation
	glRotatef((GLint)rotate_x, 1.0, 0.0, 0.0); //Rotation X-axis control
	glRotatef((GLint)rotate_y, 0.0, 1.0, 0.0); //Rotation Y-axis control
	glRotatef(-angle * 0.5, 1.0, 1.0, 1.0); //Orbital Animation
	glTranslatef(0.0, -1.0, 0.0); //Moves translated object to the bottom
	glutSolidSphere(1, 20, 20); //Creates Bottom Sphere
	glPopMatrix();

	//Right Sphere
	glPushMatrix();
	glMaterialfv(GL_FRONT, GL_AMBIENT, rainbow_mat1);
	glMaterialfv(GL_FRONT, GL_DIFFUSE, blue_particle);
	glMaterialfv(GL_FRONT, GL_SPECULAR, mat_specular);
	glMaterialfv(GL_FRONT, GL_SHININESS, high_shininess);
	glMaterialfv(GL_FRONT, GL_EMISSION, rainbow_mat1);
	glTranslatef(0.0, 0.0, initial_translate); //Moves back z-axis
	glTranslatef(0.0, 0.0, (GLfloat)z_control); //Z-axis Animation
	glRotatef((GLint)rotate_x, 1.0, 0.0, 0.0); //Rotation X-axis control
	glRotatef((GLint)rotate_y, 0.0, 1.0, 0.0); //Rotation Y-axis control
	glRotatef(-angle * 0.5, 1.0, 1.0, 1.0); //Orbital Animation
	glTranslatef(1, 0.0, 0.0); //Moves translated object to the right
	glutSolidSphere(1, 20, 20); //Creates Right Sphere
	glPopMatrix();


	//Left Sphere
	glPushMatrix();
	glMaterialfv(GL_FRONT, GL_AMBIENT, rainbow_mat1);
	glMaterialfv(GL_FRONT, GL_DIFFUSE, blue_particle);
	glMaterialfv(GL_FRONT, GL_SPECULAR, mat_specular);
	glMaterialfv(GL_FRONT, GL_SHININESS, high_shininess);
	glMaterialfv(GL_FRONT, GL_EMISSION, rainbow_mat1);
	glTranslatef(0.0, 0.0, initial_translate); //Moves back z-axis
	glTranslatef(0.0, 0.0, (GLfloat)z_control); //Z-axis Animation
	glRotatef((GLint)rotate_x, 1.0, 0.0, 0.0); //Rotation X-axis control
	glRotatef((GLint)rotate_y, 0.0, 1.0, 0.0); //Rotation Y-axis control
	glRotatef(-angle * 0.5, 1.0, 1.0, 1.0); //Orbital Animation
	glTranslatef(-1, 0.0, 0.0); //Moves translated object to the left
	glutSolidSphere(1, 20, 20); //Creates Left Sphere
	glPopMatrix();


	//Front Sphere
	glPushMatrix();
	glMaterialfv(GL_FRONT, GL_AMBIENT, rainbow_mat1);
	glMaterialfv(GL_FRONT, GL_DIFFUSE, yellow_particle);
	glMaterialfv(GL_FRONT, GL_SPECULAR, mat_specular);
	glMaterialfv(GL_FRONT, GL_SHININESS, high_shininess);
	glMaterialfv(GL_FRONT, GL_EMISSION, rainbow_mat1);
	glTranslatef(0.0, 0.0, initial_translate); //Moves object back on its z-axis
	glTranslatef(0.0, 0.0, (GLfloat)z_control); //Z-axis Animation
	glRotatef((GLint)rotate_x, 1.0, 0.0, 0.0); //Rotation X-axis control
	glRotatef((GLint)rotate_y, 0.0, 1.0, 0.0); //Rotation Y-axis control
	glRotatef(-angle * 0.5, 1.0, 1.0, 1.0); //Orbital Animation
	glTranslatef(0.0, 0.0, 1.0); //Moves translated object to the front
	glutSolidSphere(1, 20, 20); //Creates Front Sphere
	glPopMatrix();

	//Back Sphere
	glPushMatrix();
	glMaterialfv(GL_FRONT, GL_AMBIENT, rainbow_mat1);
	glMaterialfv(GL_FRONT, GL_DIFFUSE, yellow_particle);
	glMaterialfv(GL_FRONT, GL_SPECULAR, mat_specular);
	glMaterialfv(GL_FRONT, GL_SHININESS, high_shininess);
	glMaterialfv(GL_FRONT, GL_EMISSION, rainbow_mat1);
	glTranslatef(0.0, 0.0, initial_translate); //Moves object back on its z-axis
	glTranslatef(0.0, 0.0, (GLfloat)z_control); //Z-axis Animation
	glRotatef((GLint)rotate_x, 1.0, 0.0, 0.0); //Rotation X-axis control
	glRotatef((GLint)rotate_y, 0.0, 1.0, 0.0); //Rotation Y-axis control
	glRotatef(-angle * 0.5, 1.0, 1.0, 1.0); //Orbital Animation
	glTranslatef(0.0, 0.0, -1.0); //Moves translated object to the back
	glutSolidSphere(1, 20, 20); //Creates Back Sphere
	glPopMatrix();


	//----------Orbiting Spheres----------

	//Right Tilted Orbiting Sphere
	glPushMatrix();
	glMaterialfv(GL_FRONT, GL_AMBIENT, white_mat);
	glMaterialfv(GL_FRONT, GL_DIFFUSE, mat_diffuse);
	glMaterialfv(GL_FRONT, GL_SPECULAR, mat_specular);
	glMaterialfv(GL_FRONT, GL_SHININESS, high_shininess);
	glMaterialfv(GL_FRONT, GL_EMISSION, rainbow);
	glTranslatef(0.0, 0.0, initial_translate); //Moves object back on its z-axis
	glTranslatef(0.0, 0.0, (GLfloat)z_control); //Z-axis Animation
	glRotatef((GLint)rotate_x, 1.0, 0.0, 0.0); //Rotation X-axis control
	glRotatef((GLint)rotate_y, 0.0, 1.0, 0.0); //Rotation Y-axis control
	glRotatef(rotate, 1.0, 1.0, 1.0); //Rotation Animation
	glRotatef(-45, 0.0, 0.0, 1.0); //Tilts sphere -45 degrees on its z-axis
	glRotatef(-angle, 0.0, 1.0, 0.0); //Orbital Animation
	glRotatef(180, 0.0, 1.0, 0.0); //Positions sphere along the ring
	glTranslatef(-8.0, 0.0, 0.0); //Moves translated object to the right
	glutSolidSphere(0.2, 20, 20); //Creates sphere
	glPopMatrix();


	//Left Tilted Orbiting Sphere
	glPushMatrix();
	glMaterialfv(GL_FRONT, GL_AMBIENT, white_mat);
	glMaterialfv(GL_FRONT, GL_DIFFUSE, mat_diffuse);
	glMaterialfv(GL_FRONT, GL_SPECULAR, mat_specular);
	glMaterialfv(GL_FRONT, GL_SHININESS, high_shininess);
	glMaterialfv(GL_FRONT, GL_EMISSION, rainbow);
	glTranslatef(0.0, 0.0, initial_translate); //Moves object back on its z-axis
	glTranslatef(0.0, 0.0, (GLfloat)z_control); //Z-axis Animation
	glRotatef((GLint)rotate_x, 1.0, 0.0, 0.0); //Rotation X-axis control
	glRotatef((GLint)rotate_y, 0.0, 1.0, 0.0); //Rotation Y-axis control
	glRotatef(rotate, 1.0, 1.0, 1.0); //Rotation Animation
	glRotatef(45, 0.0, 0.0, 1.0); //Tilts sphere 45 degrees on its z-axis
	glRotatef(angle, 0.0, 1.0, 0.0); //Orbital Animation
	glRotatef(90, 0.0, 1.0, 0.0); //Positions sphere along the ring
	glTranslatef(8.0, 0.0, 0.0);  //Moves translated object to the left
	glutSolidSphere(0.2, 20, 20); //Creates sphere
	glPopMatrix();

	//vertical orbiting sphere
	glPushMatrix();
	glMaterialfv(GL_FRONT, GL_AMBIENT, white_mat);
	glMaterialfv(GL_FRONT, GL_DIFFUSE, mat_diffuse);
	glMaterialfv(GL_FRONT, GL_SPECULAR, mat_specular);
	glMaterialfv(GL_FRONT, GL_SHININESS, high_shininess);
	glMaterialfv(GL_FRONT, GL_EMISSION, rainbow);
	glTranslatef(0.0, 0.0, initial_translate); //Moves object back on its z-axis
	glTranslatef(0.0, 0.0, (GLfloat)z_control); //Z-axis Animation
	glRotatef((GLint)rotate_x, 1.0, 0.0, 0.0); //Rotation X-axis control
	glRotatef((GLint)rotate_y, 0.0, 1.0, 0.0); //Rotation Y-axis control
	glRotatef(rotate, 1.0, 1.0, 1.0); //Rotation Animation
	glRotatef(90, 0.0, 0.0, 1.0); //Tilts sphere 90 degrees on its z-axis
	glRotatef(angle, 0.0, 0.0, 1.0); //Orbital Animation
	glTranslatef(8.0, 0.0, 0.0);  //Moves translated object to the left
	glutSolidSphere(0.2, 20, 20); //Creates sphere
	glPopMatrix();


	//Horizontal orbiting sphere
	glPushMatrix();
	glMaterialfv(GL_FRONT, GL_AMBIENT, white_mat);
	glMaterialfv(GL_FRONT, GL_DIFFUSE, mat_diffuse);
	glMaterialfv(GL_FRONT, GL_SPECULAR, mat_specular);
	glMaterialfv(GL_FRONT, GL_SHININESS, high_shininess);
	glMaterialfv(GL_FRONT, GL_EMISSION, rainbow);
	glTranslatef(0.0, 0.0, initial_translate); //Moves object back on its z-axis
	glTranslatef(0.0, 0.0, (GLfloat)z_control); //Z-axis Animation
	glRotatef((GLint)rotate_x, 1.0, 0.0, 0.0); //Rotation X-axis control
	glRotatef((GLint)rotate_y, 0.0, 1.0, 0.0); //Rotation Y-axis control
	glRotatef(rotate, 1.0, 1.0, 1.0); //Rotation Animation
	glRotatef(angle, 0.0, 1.0, 0.0); //Orbital Animatino
	glTranslatef(6.0, 0.0, 0.0);  //Moves translated object to the left
	glutSolidSphere(1, 20, 20); //Creates sphere
	glPopMatrix();


	//----------Orbital Rings-----------


	//Right Titled Ring
	glPushMatrix();
	glMaterialfv(GL_FRONT, GL_AMBIENT, white_ring);
	glMaterialfv(GL_FRONT, GL_DIFFUSE, white_ring);
	glMaterialfv(GL_FRONT, GL_SPECULAR, mat_specular);
	glMaterialfv(GL_FRONT, GL_SHININESS, high_shininess);
	glMaterialfv(GL_FRONT, GL_EMISSION, rainbow);
	glTranslatef(0.0, 0.0, initial_translate); //Moves object back on its z-axis
	glTranslatef(0.0, 0.0, (GLfloat)z_control); //Z-axis Animation
	glRotatef((GLint)rotate_x, 1.0, 0.0, 0.0); //Rotation X-axis control
	glRotatef((GLint)rotate_y, 0.0, 1.0, 0.0); //Rotation Y-axis control
	glRotatef(rotate, 1.0, 1.0, 1.0); //Rotation Animation
	glRotatef(-45, 0.0, 0.0, 1.0); //Tilts ring -45 degrees on its z-axis
	glRotatef(90, 1.0, 0.0, 0.0); //Tilts ring 90 degrees on its x-axis
	glutSolidTorus(0.02, 8, 50, 50); //Creates ring
	glPopMatrix();

	//Left Tilted Ring
	glPushMatrix();
	glMaterialfv(GL_FRONT, GL_AMBIENT, white_ring);
	glMaterialfv(GL_FRONT, GL_DIFFUSE, white_ring);
	glMaterialfv(GL_FRONT, GL_SPECULAR, mat_specular);
	glMaterialfv(GL_FRONT, GL_SHININESS, high_shininess);
	glMaterialfv(GL_FRONT, GL_EMISSION, rainbow);
	glTranslatef(0.0, 0.0, initial_translate); //Moves object back on its z-axis
	glTranslatef(0.0, 0.0, (GLfloat)z_control); //Z-axis Animation
	glRotatef((GLint)rotate_x, 1.0, 0.0, 0.0); //Rotation X-axis control
	glRotatef((GLint)rotate_y, 0.0, 1.0, 0.0); //Rotation Y-axis control
	glRotatef(rotate, 1.0, 1.0, 1.0); //Rotation Rotation
	glRotatef(45, 0.0, 0.0, 1.0); //Tilts ring 45 degrees on its z-axis
	glRotatef(90, 1.0, 0.0, 0.0); //Tilts ring 90 degrees on its x-axis
	glutSolidTorus(0.02, 8, 50, 50); //Creates ring
	glPopMatrix();


	//Vertical Ring
	glPushMatrix();
	glMaterialfv(GL_FRONT, GL_AMBIENT, white_ring);
	glMaterialfv(GL_FRONT, GL_DIFFUSE, white_ring);
	glMaterialfv(GL_FRONT, GL_SPECULAR, mat_specular);
	glMaterialfv(GL_FRONT, GL_SHININESS, high_shininess);
	glMaterialfv(GL_FRONT, GL_EMISSION, rainbow);
	glTranslatef(0.0, 0.0, initial_translate); //Moves object back on its z-axis
	glTranslatef(0.0, 0.0, (GLfloat)z_control); //Z-axis Animation
	glRotatef((GLint)rotate_x, 1.0, 0.0, 0.0); //Rotation X-axis control
	glRotatef((GLint)rotate_y, 0.0, 1.0, 0.0); //Rotation Y-axis control
	glRotatef(rotate, 1.0, 1.0, 1.0); //Rotation Rotation
	//glRotatef(0, 0.0, 1.0, 0.0); //Rotation control
	glutSolidTorus(0.02, 8, 50, 50); //Creates ring
	glPopMatrix();

	//Inner Ring
	glPushMatrix();
	glMaterialfv(GL_FRONT, GL_AMBIENT, white_ring);
	glMaterialfv(GL_FRONT, GL_DIFFUSE, white_ring);
	glMaterialfv(GL_FRONT, GL_SPECULAR, mat_specular);
	glMaterialfv(GL_FRONT, GL_SHININESS, high_shininess);
	glMaterialfv(GL_FRONT, GL_EMISSION, rainbow);
	glTranslatef(0.0, 0.0, initial_translate); //Moves object back on its z-axis
	glTranslatef(0.0, 0.0, (GLfloat)z_control); //Z-axis Animation
	glRotatef((GLint)rotate_x, 1.0, 0.0, 0.0); //Rotation control
	glRotatef((GLint)rotate_y, 0.0, 1.0, 0.0); //Rotation control
	glRotatef(rotate, 1.0, 1.0, 1.0); //Rotation Rotation
	glRotatef(90, 1.0, 0.0, 0.0); //Tilts ring 90 degrees on its x-axis
	glutSolidTorus(0.02, 6, 50, 50); //Creates ring
	glPopMatrix();

	glutSwapBuffers();

	angle += 0.08; //Controls the orbiting animation
	rotate += 0.01; //Controls the entire rotation animation

	//Controls the Z-axis animation
	if (state == 1)
	{
		z_control -= 0.001;
		if (z_control <= -1.0f)
		{
			state = 0;
		}
	}
	else if (state == 0)
	{
		z_control += 0.001;
		if (z_control >= 7.0f)
		{
			state = 1;
		}
	}

	//Controls the color animation for the orbiting spheres
	if (new_color1 == 1)
	{
		Green_c1 += 0.001f;
		if (Green_c1 >= 1.0f)
		{
			new_color1 = 2;
		}
	}
	else if (new_color1 == 2)
	{
		Red_c1 -= 0.001f;
		if (Red_c1 <= 0.0f)
		{
			new_color1 = 3;
		}
	}
	else if (new_color1 == 3)
	{
		Blue_c1 += 0.001f;
		if (Blue_c1 >= 1.0f)
		{
			new_color1 = 4;
		}
	}
	else if (new_color1 == 4)
	{
		Green_c1 -= 0.001f;
		if (Green_c1 <= 0.0f)
		{
			new_color1 = 5;
		}
	}
	else if (new_color1 == 5)
	{
		Red_c1 += 0.001f;
		if (Red_c1 >= 1.0f)
		{
			new_color1 = 6;
		}
	}
	else if (new_color1 == 6)
	{
		Blue_c1 -= 0.001f;
		if (Blue_c1 <= 0.0f)
		{
			new_color1 = 1;
		}
	}


	//Controls the ambient color animtion of the rings and the nucleus
	if (new_color2 == 1)
	{
		Green_c2 += 0.0001f;
		if (Green_c2 >= 0.2f)
		{
			new_color2 = 2;
		}
	}
	else if (new_color2 == 2)
	{
		Red_c2 -= 0.0001f;
		if (Red_c2 <= 0.0f)
		{
			new_color2 = 3;
		}
	}
	else if (new_color2 == 3)
	{
		Blue_c2 += 0.0001f;
		if (Blue_c2 >= 0.2f)
		{
			new_color2 = 4;
		}
	}
	else if (new_color2 == 4)
	{
		Green_c2 -= 0.0001f;
		if (Green_c2 <= 0.0f)
		{
			new_color2 = 5;
		}
	}
	else if (new_color2 == 5)
	{
		Red_c2 += 0.0001f;
		if (Red_c2 >= 0.2f)
		{
			new_color2 = 6;
		}
	}
	else if (new_color2 == 6)
	{
		Blue_c2 -= 0.0001f;
		if (Blue_c2 <= 0.0f)
		{
			new_color2 = 1;
		}
	}

}

void reshape(int w, int h)
{
	glViewport(0, 0, (GLint)w, (GLint)h);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluPerspective(100.0, (GLfloat)w / (GLfloat)h, 1.0, 200.0);
	//Orthographic perspective
	/*if (w <= (h * 2))
		glOrtho(-12.0, 12.0, -6.0*((GLfloat)h * 2) / (GLfloat)w, 6.0*((GLfloat)h * 2) / (GLfloat)w, -10.0, 100.0);
	else
		glOrtho(-6.0*(GLfloat)w / ((GLfloat)h * 2), 12.0*(GLfloat)w / ((GLfloat)h * 2), -6.0, 6.0, -10.0, 100.0);*/
	glMatrixMode(GL_MODELVIEW);
}

//Keyboard Controls
void keyboard(unsigned char key, int x, int y)
{
	switch (key) {
	case 'w': //Move forward
		z_control = (z_control + 0.05);
		break;
	case 's': //Move backwards
		z_control = (z_control - 0.05);
		//do something here
		break;
	case '8': //Rotate up
		rotate_x = (rotate_x - 5);
		break;
	case '2': //Rotate down
		rotate_x = (rotate_x + 5);
		break;
	case '4': //Rotate left
		rotate_y = (rotate_y - 5);
		break;
	case '6': //Rotate right
		rotate_y = (rotate_y + 5);
		break;
	case 27:
		exit(0);
		break;
	}
}

//Main function
int main(int argc, char** argv)
{
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB | GLUT_DEPTH);
	glutInitWindowSize(600, 450);
	glutCreateWindow(argv[0]);
	init();
	glutReshapeFunc(reshape);
	glutDisplayFunc(display);
	glutKeyboardFunc(keyboard);
	glutTimerFunc(0, timer, 0);
	glutMainLoop();
	return 0;
}
