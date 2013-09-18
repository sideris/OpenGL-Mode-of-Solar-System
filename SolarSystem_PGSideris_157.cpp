#include "stdafx.h"
#include "Solar.h"   
#include <stdlib.h> 
#include <GL/glut.h>
#include <math.h>
#include <windows.h>

static GLfloat year = 0, day = 0, year2=0;
static GLfloat pitch = 0, rot = 90.0;
static GLfloat xdist = 0, ydist = 0, zdist = 10.0;
static GLfloat xlook = 0.0, ylook = 0.0, zlook = 0.0;
static GLfloat xup = 0.0, yup = 0.0, zup= 0.0;
static int lastx = 0, lasty = 0;
int a=200;
int b=58;
int c=30,d=20,e=58,f=5;

void GetKey();

void Rotate()//sinartisi peristrofis planitwn
{
	day += 1;
	if(day > 360)
		day = day - 360;
	year += .1;
	if(year > 360)
		year = year - 360;
	glPushMatrix();
	year2 += .1;
	if(year2 > 3600)
		year2 = year2 - 3600;
	glPopMatrix();
	glutPostRedisplay();
}

void DrawOrbit(GLfloat rad, GLfloat inc)//sinartisi gia to sxediasmo troxias(klemmeni apo proggrama dimiourgias elleipsewn)
{
	glPushMatrix();

	GLfloat y = 0.0;
	glColor3f(0.5, 0.5, 0.5);

	glBegin(GL_POINTS);
	for(GLfloat angle = 0; angle <= 360; angle+=inc)
	{
		GLfloat x = rad*sin((angle)*3.1415926535/180);
		GLfloat z = rad*cos((angle)*3.1415926535/180);

		glVertex3f(x, y, z);
	}
	glEnd();

	glPopMatrix();
}
//planites
void Mercury(void)
{	glRotatef( 7.0, 0.0, 0.0, 1.0 );
	DrawOrbit(1.5,12);

	
	glRotatef((GLfloat) year*8, 0.0, 1.0, 0.0); //Peristrofitou planiti
	glTranslatef(1.5, 0.0, 0.0);
	glColor3f(238, 221, 130);
	glutSolidSphere(0.08, 10, 8); //Ermis
}

void Venus(void)
{	glRotatef( 3.0, 0.0, 0.0, 1.0 );
	DrawOrbit(3.5,10);


	glRotatef((GLfloat) year*3, 0.0, 1.0, 0.0); //Afroditi
	glTranslatef(3.5, 0.0, 0.0);
	glColor3f(1.0, 0.5, 0.0);
	glutSolidSphere(0.19, 10, 8); 
}


void Earth(void)
{	glRotatef( 2.0, 0.0, 0.0, 1.0 );
	DrawOrbit(5.0, 7);
	
	glRotatef((GLfloat) year*2, 0.0, 1.0, 0.0); 
	glTranslatef(5.0, 0.0, 0.0);
	glColor3f(0.0, 0.3, 1.0);
	glutSolidSphere(0.2, 10, 8); //Gi

	glRotatef((GLfloat) day*3, 0.0, 1.0, 0.0); 
	glTranslatef(0.5, 0.0, 0.0);
	glColor3f(1, 1, 1);
	glutSolidSphere(0.05, 5, 4); //feggari

}
void Mars(void)
{
	DrawOrbit(7.0, 6);

	glRotatef((GLfloat) year*1, 0.0, 1.0, 0.0); 
	glTranslatef(7.0, 0.0, 0.0);
	glColor3f(1.0, 0.0, 0.0);
	glutSolidSphere(0.1, 10, 8); //Aris
	
	glPushMatrix();
	glRotatef((GLfloat) day*a, 0.0, 1.0, 0.0); //Phobos
	glTranslatef(0.5, 0.0, 0.0);
	glColor3f(1, 1, 1);
	glutSolidSphere(0.04, 5, 4); 
	glPopMatrix();
	
	glPushMatrix();
	glRotatef((GLfloat) day*b, 0.0, 1.0, 0.0); //Deimos
	glTranslatef(0.9, 0.0, 0.0);
	glColor3f(1, 1, 1);
	glutSolidSphere(0.04, 5, 4);
	glPopMatrix();

}
/*
void Asteroid_Belt(void)
{
	int y=0.0;
	for(float x=9;x<=12;x=x+0.1){
		
#if(x%2==0)
		
	y=3;
#else
	y=19;
#endif
		DrawOrbit(x, y);
	}
}
*/
void Jupiter(void)
{	glRotatef( 1.0, 0.0, 0.0, 1.0 );
	DrawOrbit(14.0, 5);

	glRotatef((GLfloat) year2*0.2, 0.0, 1.0, 0.0); //Dias
	glTranslatef(14.0, 0.0, 0.0);
	glColor3f(139, 129, 76);
	glutSolidSphere(2.24, 20, 20); 
	


	glPushMatrix();
	glRotatef((GLfloat) day*c, 0.0, 1.0, 0.0); //Io
	glTranslatef(2.7, 0.0, 0.0);
	glColor3f(1, 0, 0.0);
	glutSolidSphere(0.06, 5, 4); 
	glPopMatrix();
	
	glPushMatrix();
	glRotatef((GLfloat) day*d, 0.0, 1.0, 0.0); //europa
	glTranslatef(2.8, 0.4, 0.0);
	glColor3f(0, 1, 0);
	glutSolidSphere(0.055, 5, 4); 
	glPopMatrix();

	glPushMatrix();
	glRotatef((GLfloat) day*e, 0.0, 1.0, 0.0); //ganymede
	glTranslatef(3, -0.3, 0.0);
	glColor3f(0, 0, 1);
	glutSolidSphere(0.08, 5, 4); 
	glPopMatrix();

	glPushMatrix();
	glRotatef((GLfloat) day*f, 0.0, 1.0, 0.0); //callisto
	glTranslatef(3.1, 0.7, 0.0);
	glColor3f(1, 0, 1);
	glutSolidSphere(0.07, 5, 4); 
	glPopMatrix();
}

void GetKey(void)
{
		if(GetAsyncKeyState(0x41)) //a
	{
		xdist += (cos(rot*3.1415926535/180)* cos((pitch+90)*3.1415926535/180));
		zdist += -(sin(rot*3.1415926535/180) * cos((pitch+90)*3.1415926535/180));
		ydist += sin((pitch+90)*3.1415926535/180);
	}
	if(GetAsyncKeyState(0x5a)) //z
	{
		xdist -= (cos(rot*3.1415926535/180)* cos((pitch+90)*3.1415926535/180));
		zdist -= -(sin(rot*3.1415926535/180) * cos((pitch+90)*3.1415926535/180));
		ydist -= sin((pitch+90)*3.1415926535/180);
	}

	xlook = xdist + (cos(rot*3.1415926535/180) * cos(pitch*3.1415926535/180));
	zlook = zdist - (sin(rot*3.1415926535/180) * cos(pitch*3.1415926535/180));
	ylook = ydist + sin(pitch*3.1415926535/180);

	xup = cos(rot*3.1415926535/180) * cos((pitch+90)*3.1415926535/180);
	zup = -sin(rot*3.1415926535/180) * cos((pitch+90)*3.1415926535/180);
	yup = sin((pitch+90)*3.1415926535/180);

	glutPostRedisplay();
}

//telos planitwn

//Animation-Σχεδιασμος

static void Animate(void)
{
	
   GetKey();
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	
	// Clear the current matrix (Modelview)
    glLoadIdentity();
	gluLookAt(xdist, ydist, zdist,  xlook, ylook, zlook,  xup, yup, zup);
	// 20 monades pisw gia tin optiki mas
    glTranslatef ( 0.0, 0.0, -20.0 );
	// 45 moires gwnia gia optiki thesi
	glRotatef( 45.0, 1.0, 0.0, 0.0 );

    // Ilios
	glColor3f( 1.0, 1.0, 0.0 );			
    glutSolidSphere( 1, 200, 200 );
	
	glPushMatrix();
	Mercury();
	glPopMatrix();

	glPushMatrix();
	Venus();
	glPopMatrix();
	
	glPushMatrix();
	Earth();
	glPopMatrix();
	
	glPushMatrix();
	Mars();
	glPopMatrix();

	/*glPushMatrix();
	Asteroid_Belt();
	glPopMatrix();*/

	glPushMatrix();
	Jupiter();
	glPopMatrix();
	

	
	Rotate();//kaloume gia to animation
    glFlush();
    glutSwapBuffers();

}



//klemmena

static void SpecialKeyFunc( int Key, int x, int y )
{
	switch ( Key ) {
	case GLUT_KEY_UP:		
		Key_up();
		break;
	case GLUT_KEY_DOWN:
		Key_down();
		break;
	}
}
static void Key_up(void)
{
   a *=2;
   b *=2;	
   c *=2;
   d *=2;
   e *=2;
   
}

static void Key_down(void)
{
   a /=2;
   b /=2;
   c /=2;
   d /=2;
   e /=2;
   
}
void OpenGLInit(void)
{
    glShadeModel( GL_FLAT );
    glClearColor( 0.0, 0.0, 0.0, 0.0 );
    glClearDepth( 1.0 );
    glEnable( GL_DEPTH_TEST );
}

static void ResizeWindow(int w, int h)
{
    float aspectRatio;
	h = (h == 0) ? 1 : h;
	w = (w == 0) ? 1 : w;
	glViewport( 0, 0, w, h );	// xrisimopoiei olo to parathiro
	aspectRatio = (float)w/(float)h;

	// Simeio theasis
    glMatrixMode( GL_PROJECTION );
    glLoadIdentity();
    gluPerspective( 60.0, aspectRatio, 1.0, 1000.0 );//exei min k max apostasi, kati san vathos to thema einai oti eppireazei kai to geniko vathos oxi mono otan kanoume resize

    glMatrixMode( GL_MODELVIEW );
}

void PassiveMouse(int x, int y)
{
	if( (lastx - x) >50 || (lastx - x) <-50 ||
		(lasty - y) >50 || (lasty - y) <-50 )
	{
		lastx = x;
		lasty = y;
	}

	rot += (((GLfloat)lastx - (GLfloat)x)/2);
	lastx = x;

	if(rot>360)
		rot-=360;
	if(rot<0)
		rot+=360;

	pitch += (((GLfloat)lasty - (GLfloat)y))/2;
	lasty = y;

	if(pitch > 90)
		pitch = 90.0;
	if(pitch<-90)
		pitch = -90.0;

	glutPostRedisplay();
}
//telos klemmenwn

// Main

int main( int argc, char** argv )
{
	
	glutInit(&argc,argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH );
    glutInitWindowPosition( 0, 0 );
    glutInitWindowSize( 1280, 768 );
    glutCreateWindow( "Solar System" );

	// Initialize
    OpenGLInit();

	glutSpecialFunc( SpecialKeyFunc );
	//reshape gia to resize
    glutReshapeFunc( ResizeWindow );

	//Kaloume gia na emfanisoume
    glutDisplayFunc( Animate );
	glutPassiveMotionFunc(PassiveMouse);
	
	glutMainLoop(  );

    return(0);			
}
