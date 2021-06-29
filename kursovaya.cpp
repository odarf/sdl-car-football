#include <windows.h>
#define _USE_MATH_DEFINES
#include <math.h>

#include <glut.h>  
#include <stdlib.h>
#include <time.h>
#include < GL/gl.h >
#include < GL/glu.h >
#include <SOIL.h>
#include <iostream>
#include <tchar.h>


static float  camera = 0, s=0;
static int px = 0, py = 0,angle = 0, z = -1, k =0, w = 0;
static float pov = 0;
static int angel = 0, povz = 0 , povz1 =0 , flag=0;
GLuint texture[10];
GLuint kol[10];
GLuint sky[6];
GLuint kr[2], svet[4], panel[2], avto[8],car[7],roof[2],j[2];
double r = .05;
float i = 0, y = 2,pz = 35, u=2 ;
GLfloat ambient0[4] = { 0.7,0.7,0.7,0 };


using namespace std;

void init(void)
{
	glEnable(GL_TEXTURE_2D);
	glShadeModel(GL_SMOOTH);
	glEnable(GL_DEPTH_TEST);
	
	glDepthFunc(GL_LEQUAL);
	glHint(GL_PERSPECTIVE_CORRECTION_HINT, GL_NICEST);
	
	glDepthMask(GL_TRUE);
	glClearColor(.15, .7, .59, 1.0);
	glShadeModel(GL_FLAT);
	
}

GLvoid LoadGLTextures()
{
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glLoadIdentity();
	texture[0] = SOIL_load_OGL_texture // load an image file directly as a new OpenGL texture
	(
		"resources/dom.png",
		SOIL_LOAD_AUTO,
		SOIL_CREATE_NEW_ID,
		SOIL_FLAG_MIPMAPS | SOIL_FLAG_INVERT_Y | SOIL_FLAG_NTSC_SAFE_RGB | SOIL_FLAG_COMPRESS_TO_DXT
	);

	texture[1] = SOIL_load_OGL_texture // load an image file directly as a new OpenGL texture
	(
		"resources/sun.bmp",
		SOIL_LOAD_AUTO,
		SOIL_CREATE_NEW_ID,
		SOIL_FLAG_MIPMAPS | SOIL_FLAG_INVERT_Y | SOIL_FLAG_NTSC_SAFE_RGB | SOIL_FLAG_COMPRESS_TO_DXT
	);

	
	texture[4] = SOIL_load_OGL_texture // load an image file directly as a new OpenGL texture
	(
		"resources/wall.jpg",
		SOIL_LOAD_AUTO,
		SOIL_CREATE_NEW_ID,
		SOIL_FLAG_MIPMAPS | SOIL_FLAG_INVERT_Y | SOIL_FLAG_NTSC_SAFE_RGB | SOIL_FLAG_COMPRESS_TO_DXT

	);
	texture[5] = SOIL_load_OGL_texture // load an image file directly as a new OpenGL texture
	(
		"resources/wall.jpg",
		SOIL_LOAD_AUTO,
		SOIL_CREATE_NEW_ID,
		SOIL_FLAG_MIPMAPS | SOIL_FLAG_INVERT_Y | SOIL_FLAG_NTSC_SAFE_RGB | SOIL_FLAG_COMPRESS_TO_DXT
	);

	texture[6] = SOIL_load_OGL_texture // load an image file directly as a new OpenGL texture
	(
		"resources/wall.jpg",
		SOIL_LOAD_AUTO,
		SOIL_CREATE_NEW_ID,
		SOIL_FLAG_MIPMAPS | SOIL_FLAG_INVERT_Y | SOIL_FLAG_NTSC_SAFE_RGB | SOIL_FLAG_COMPRESS_TO_DXT
	);

	kol[0] = SOIL_load_OGL_texture // load an image file directly as a new OpenGL texture
	(
		"resources/a.png",
		SOIL_LOAD_AUTO,
		SOIL_CREATE_NEW_ID,
		SOIL_FLAG_MIPMAPS | SOIL_FLAG_INVERT_Y | SOIL_FLAG_NTSC_SAFE_RGB | SOIL_FLAG_COMPRESS_TO_DXT
	);
	
	kol[1] = SOIL_load_OGL_texture // load an image file directly as a new OpenGL texture
	(
		"resources/r.png",
		SOIL_LOAD_AUTO,
		SOIL_CREATE_NEW_ID,
		SOIL_FLAG_MIPMAPS | SOIL_FLAG_INVERT_Y | SOIL_FLAG_NTSC_SAFE_RGB | SOIL_FLAG_COMPRESS_TO_DXT
	);

	kol[2] = SOIL_load_OGL_texture // load an image file directly as a new OpenGL texture
	(
		"resources/asf.png",
		SOIL_LOAD_AUTO,
		SOIL_CREATE_NEW_ID,
		SOIL_FLAG_MIPMAPS | SOIL_FLAG_INVERT_Y | SOIL_FLAG_NTSC_SAFE_RGB | SOIL_FLAG_COMPRESS_TO_DXT
	);
	sky[0] = SOIL_load_OGL_texture // load an image file directly as a new OpenGL texture   skybox
	(
		"resources/skybox_front.bmp",
		SOIL_LOAD_AUTO,
		SOIL_CREATE_NEW_ID,
		SOIL_FLAG_MIPMAPS | SOIL_FLAG_INVERT_Y | SOIL_FLAG_NTSC_SAFE_RGB | SOIL_FLAG_COMPRESS_TO_DXT
	);
	sky[1] = SOIL_load_OGL_texture // load an image file directly as a new OpenGL texture   skybox
	(
		"resources/skybox_back.bmp",
		SOIL_LOAD_AUTO,
		SOIL_CREATE_NEW_ID,
		SOIL_FLAG_MIPMAPS | SOIL_FLAG_INVERT_Y | SOIL_FLAG_NTSC_SAFE_RGB | SOIL_FLAG_COMPRESS_TO_DXT
	);
	sky[2] = SOIL_load_OGL_texture // load an image file directly as a new OpenGL texture   skybox
	(
		"resources/skybox_left.bmp",
		SOIL_LOAD_AUTO,
		SOIL_CREATE_NEW_ID,
		SOIL_FLAG_MIPMAPS | SOIL_FLAG_INVERT_Y | SOIL_FLAG_NTSC_SAFE_RGB | SOIL_FLAG_COMPRESS_TO_DXT
	);
	sky[3] = SOIL_load_OGL_texture // load an image file directly as a new OpenGL texture   skybox
	(
		"resources/skybox_right.bmp",
		SOIL_LOAD_AUTO,
		SOIL_CREATE_NEW_ID,
		SOIL_FLAG_MIPMAPS | SOIL_FLAG_INVERT_Y | SOIL_FLAG_NTSC_SAFE_RGB | SOIL_FLAG_COMPRESS_TO_DXT
	);
	sky[4] = SOIL_load_OGL_texture // load an image file directly as a new OpenGL texture   skybox
	(
		"resources/skybox_bottom.bmp",
		SOIL_LOAD_AUTO,
		SOIL_CREATE_NEW_ID,
		SOIL_FLAG_MIPMAPS | SOIL_FLAG_INVERT_Y | SOIL_FLAG_NTSC_SAFE_RGB | SOIL_FLAG_COMPRESS_TO_DXT
	);
	sky[5] = SOIL_load_OGL_texture // load an image file directly as a new OpenGL texture   skybox
	(
		"resources/skybox_top.bmp",
		SOIL_LOAD_AUTO,
		SOIL_CREATE_NEW_ID,
		SOIL_FLAG_MIPMAPS | SOIL_FLAG_INVERT_Y | SOIL_FLAG_NTSC_SAFE_RGB | SOIL_FLAG_COMPRESS_TO_DXT
	);

	kr[0] = SOIL_load_OGL_texture // load an image file directly as a new OpenGL texture   skybox
	(
		"resources/kr.png",
		SOIL_LOAD_AUTO,
		SOIL_CREATE_NEW_ID,
		SOIL_FLAG_MIPMAPS | SOIL_FLAG_INVERT_Y | SOIL_FLAG_NTSC_SAFE_RGB | SOIL_FLAG_COMPRESS_TO_DXT
	);

	panel[0] = SOIL_load_OGL_texture // load an image file directly as a new OpenGL texture   skybox
	(
		"resources/panel.jpg",
		SOIL_LOAD_AUTO,
		SOIL_CREATE_NEW_ID,
		SOIL_FLAG_MIPMAPS | SOIL_FLAG_INVERT_Y | SOIL_FLAG_NTSC_SAFE_RGB | SOIL_FLAG_COMPRESS_TO_DXT
	);


	panel[1] = SOIL_load_OGL_texture // load an image file directly as a new OpenGL texture   skybox
	(
		"resources/panel2.jpg",
		SOIL_LOAD_AUTO,
		SOIL_CREATE_NEW_ID,
		SOIL_FLAG_MIPMAPS | SOIL_FLAG_INVERT_Y | SOIL_FLAG_NTSC_SAFE_RGB | SOIL_FLAG_COMPRESS_TO_DXT
	);

	svet[0] = SOIL_load_OGL_texture // load an image file directly as a new OpenGL texture   skybox
	(
		"resources/kra.jpg",
		SOIL_LOAD_AUTO,
		SOIL_CREATE_NEW_ID,
		SOIL_FLAG_MIPMAPS | SOIL_FLAG_INVERT_Y | SOIL_FLAG_NTSC_SAFE_RGB | SOIL_FLAG_COMPRESS_TO_DXT
	);

	svet[1] = SOIL_load_OGL_texture // load an image file directly as a new OpenGL texture   skybox
	(
		"resources/zh.jpg",
		SOIL_LOAD_AUTO,
		SOIL_CREATE_NEW_ID,
		SOIL_FLAG_MIPMAPS | SOIL_FLAG_INVERT_Y | SOIL_FLAG_NTSC_SAFE_RGB | SOIL_FLAG_COMPRESS_TO_DXT
	);

	svet[2] = SOIL_load_OGL_texture // load an image file directly as a new OpenGL texture   skybox
	(
		"resources/zel.jpg",
		SOIL_LOAD_AUTO,
		SOIL_CREATE_NEW_ID,
		SOIL_FLAG_MIPMAPS | SOIL_FLAG_INVERT_Y | SOIL_FLAG_NTSC_SAFE_RGB | SOIL_FLAG_COMPRESS_TO_DXT
	);

	avto[0] = SOIL_load_OGL_texture // load an image file directly as a new OpenGL texture   skybox
	(
		"resources/car/back-text.png",
		SOIL_LOAD_AUTO,
		SOIL_CREATE_NEW_ID,
		SOIL_FLAG_MIPMAPS | SOIL_FLAG_INVERT_Y | SOIL_FLAG_NTSC_SAFE_RGB | SOIL_FLAG_COMPRESS_TO_DXT
	);

	avto[1] = SOIL_load_OGL_texture // load an image file directly as a new OpenGL texture   skybox
	(
		"resources/car/front-text.png",
		SOIL_LOAD_AUTO,
		SOIL_CREATE_NEW_ID,
		SOIL_FLAG_MIPMAPS | SOIL_FLAG_INVERT_Y | SOIL_FLAG_NTSC_SAFE_RGB | SOIL_FLAG_COMPRESS_TO_DXT
	);

	avto[2] = SOIL_load_OGL_texture // load an image file directly as a new OpenGL texture   skybox
	(
		"resources/car/side-text.png",
		SOIL_LOAD_AUTO,
		SOIL_CREATE_NEW_ID,
		SOIL_FLAG_MIPMAPS | SOIL_FLAG_INVERT_Y | SOIL_FLAG_NTSC_SAFE_RGB | SOIL_FLAG_COMPRESS_TO_DXT
	);
	avto[3] = SOIL_load_OGL_texture // load an image file directly as a new OpenGL texture   skybox
	(
		"resources/car/front-back-window.png",
		SOIL_LOAD_AUTO,
		SOIL_CREATE_NEW_ID,
		SOIL_FLAG_MIPMAPS | SOIL_FLAG_INVERT_Y | SOIL_FLAG_NTSC_SAFE_RGB | SOIL_FLAG_COMPRESS_TO_DXT
	);

	avto[4] = SOIL_load_OGL_texture // load an image file directly as a new OpenGL texture   skybox
	(
		"resources/car/right-window.png",
		SOIL_LOAD_AUTO,
		SOIL_CREATE_NEW_ID,
		SOIL_FLAG_MIPMAPS | SOIL_FLAG_INVERT_Y | SOIL_FLAG_NTSC_SAFE_RGB | SOIL_FLAG_COMPRESS_TO_DXT
	);

	avto[5] = SOIL_load_OGL_texture // load an image file directly as a new OpenGL texture   skybox
	(
		"resources/car/left-window.png",
		SOIL_LOAD_AUTO,
		SOIL_CREATE_NEW_ID,
		SOIL_FLAG_MIPMAPS | SOIL_FLAG_INVERT_Y | SOIL_FLAG_NTSC_SAFE_RGB | SOIL_FLAG_COMPRESS_TO_DXT
	);

	roof[0] = SOIL_load_OGL_texture // load an image file directly as a new OpenGL texture   skybox
	(
		"resources/roof.jpg",
		SOIL_LOAD_AUTO,
		SOIL_CREATE_NEW_ID,
		SOIL_FLAG_MIPMAPS | SOIL_FLAG_INVERT_Y | SOIL_FLAG_NTSC_SAFE_RGB | SOIL_FLAG_COMPRESS_TO_DXT
	);


	j[0] = SOIL_load_OGL_texture // load an image file directly as a new OpenGL texture   skybox
	(
		"resources/j.jpg",
		SOIL_LOAD_AUTO,
		SOIL_CREATE_NEW_ID,
		SOIL_FLAG_MIPMAPS | SOIL_FLAG_INVERT_Y | SOIL_FLAG_NTSC_SAFE_RGB | SOIL_FLAG_COMPRESS_TO_DXT
	);
	glutSwapBuffers();
}

// солнце
void Sun()
{
	
	glMatrixMode(GL_MODELVIEW);
	GLUquadricObj* q1,*q2;
	q1 = gluNewQuadric();
	q2 = gluNewQuadric();
	glPushMatrix();
	glTranslatef(8, 10, -10);
	glRotatef(60, 0, 1, 0);
	glBindTexture(GL_TEXTURE_2D, texture[1]);
	gluQuadricTexture(q1, texture[1]);
	gluSphere(q1, 3.0, 2000, 2000);
	glColor3f(1, 1, 1);

	glPopMatrix();

	/*glTranslatef(2, 5, 4);
	gluSphere(q2, 3.0, 200, 20);
	glTranslatef(-2, -5, -4);*/
} // солнце  


// корпус машины
void drawQube()
{
	 float size = 1.f;
	 int s = 1;
	 float x = 1, y = 0, z = 2.7;
	 //glPushMatrix();
	
	 
	 GLfloat material1_specular[] = { 0, 0, 0, 1.0 };
	glMaterialfv(GL_FRONT_AND_BACK, GL_SPECULAR, material1_specular);
	glBindTexture(GL_TEXTURE_2D, avto[2]);
	glPushMatrix();
	glTexEnvf(GL_TEXTURE_ENV,
		GL_TEXTURE_ENV_MODE, GL_MODULATE
	);
	glTranslatef(-2.5,1,-4);
	glBegin(GL_QUADS);
	glTexCoord2f(1.0f, 1.0f); glVertex3f(-2.4 * size+ x, -size, -1.1 *size+z);
	glTexCoord2f(0.0f, 1.0f); glVertex3f(2.4 * size + x, -size, -1.1 *size+z);
	glTexCoord2f(0.0f, 0.0f); glVertex3f(2.7 * size + x, size * 0.08, -1.1 *size+z);
	glTexCoord2f(1.0f, 0.0f); glVertex3f(-2.7 * size + x, size * 0.08, -1.1 *size+z);
	glEnd();
	glPopMatrix();
	
	glBindTexture(GL_TEXTURE_2D, avto[2]);
	glPushMatrix();
	glTranslatef(-2.5, 1, -4);
	glBegin(GL_QUADS);
	glTexCoord2f(0.0f, 1.0f); glVertex3f(2.4 * size + x, -size, 1.1 *size+z);
	glTexCoord2f(1.0f, 1.0f); glVertex3f(-2.4 * size + x, -size, 1.1 * size+z);
	glTexCoord2f(1.0f, 0.0f); glVertex3f(-2.7 * size + x, size * 0.08, 1.1 * size+z);
	glTexCoord2f(0.0f, 0.0f); glVertex3f(2.7 * size + x, size * 0.08, 1.1 * size+z);
	glEnd();
	glPopMatrix();
	

	glBindTexture(GL_TEXTURE_2D, avto[0]);
	glPushMatrix();
	glTranslatef(-2.5, 1, -4);
	glBegin(GL_QUADS);
	glTexCoord2f(0.0f, 0.0f);	glVertex3f(2.7 * size + x, size * 0.08, 1.1 * size + z);// zad
	glTexCoord2f(0.0f, 1.0f);	glVertex3f(2.4 * size + x, -size, 1.1 * size + z);
	glTexCoord2f(1.0f, 1.0f);	glVertex3f(2.4 * size + x, -size, -1.1 * size + z);
	glTexCoord2f(1.0f, 0.0f);	glVertex3f(2.7 * size + x, size * 0.08, -1.1 * size + z);
	glEnd();
	glPopMatrix();
	

	glBindTexture(GL_TEXTURE_2D, avto[1]);
	glPushMatrix();
	glTranslatef(-2.5, 1, -4);
	glBegin(GL_QUADS);
	glTexCoord2f(0.0f, 1.0f);	glVertex3f(-2.4 * size + x, -size, 1.1 * size+z); //pered
	glTexCoord2f(1.0f, 1.0f);	glVertex3f(-2.4 * size + x, -size, -1.1 * size+z);
	glTexCoord2f(1.0f, 0.0f);	glVertex3f(-2.7 * size + x, size * 0.08, -1.1 * size+z);
	glTexCoord2f(0.0f, 0.0f);	glVertex3f(-2.7 * size + x, size * 0.08, 1.1 * size+z);
	glEnd();
	glPopMatrix();
	
	glBindTexture(GL_TEXTURE_2D, avto[3]);
	glPushMatrix();
	
	glTranslatef(-2.5, 1, -4);
	glBegin(GL_QUADS);
	glTexCoord2f(1.0f, 1.0f); glVertex3f(-2.7 * size + x, size * 0.08, 1.1 * size + z);
	glTexCoord2f(0.0f, 1.0f); glVertex3f(-2.7 * size + x, size * 0.08, -1.1 * size + z);
	glTexCoord2f(0.0f, 0.0f); glVertex3f(-.2 * size + x, size * 0.9, -1.1 * size + z);
	glTexCoord2f(1.0f, 0.0f); glVertex3f(-.2 * size + x, size * 0.9, 1.1 * size + z);
	glEnd();
	glPopMatrix();


	glBindTexture(GL_TEXTURE_2D, roof[0]);
	glPushMatrix();
	glTexEnvf(GL_TEXTURE_ENV,
		GL_TEXTURE_ENV_MODE, GL_MODULATE
	);
	glTranslatef(-2.5, 1, -4);
	glBegin(GL_QUADS);
	glTexCoord2f(1.0f, 0.0f); glVertex3f(-.2 * size + x, size * 0.9, 1.1 * size + z);
	glTexCoord2f(0.0f, 0.0f); glVertex3f(-.2 * size + x, size * 0.9, -1.1 * size + z);
	glTexCoord2f(0.0f, 1.0f); glVertex3f(.8 * size + x, size * 0.9, -1.1 * size + z);
	glTexCoord2f(1.0f, 1.0f); glVertex3f(.8 * size + x, size * 0.9, 1.1 * size + z);
	glEnd();
	glPopMatrix();


	glBindTexture(GL_TEXTURE_2D, avto[3]);
	glPushMatrix();
	glTexEnvf(GL_TEXTURE_ENV,
		GL_TEXTURE_ENV_MODE, GL_MODULATE
	);
	glTranslatef(-2.5, 1, -4);
	glBegin(GL_QUADS);
	glTexCoord2f(1.0f, 0.0f); glVertex3f(.8 * size + x, size * 0.9, 1.1 * size + z);
	glTexCoord2f(0.0f, 0.0f); glVertex3f(.8 * size + x, size * 0.9, -1.1 * size + z);
	glTexCoord2f(0.0f, 1.0f); glVertex3f(2.7 * size + x, size * 0.08, -1.1 * size + z);
	glTexCoord2f(1.0f, 1.0f); glVertex3f(2.7 * size + x, size * 0.08, 1.1 * size + z);
	glEnd();
	glPopMatrix();
	
	
	glBindTexture(GL_TEXTURE_2D, avto[4]);
	glPushMatrix();
	glTexEnvf(GL_TEXTURE_ENV,
		GL_TEXTURE_ENV_MODE, GL_MODULATE
	);
	glTranslatef(-2.5, 1, -4);
	glBegin(GL_QUADS);
	glTexCoord2f(1.0f, 1.0f); glVertex3f(2.7 * size + x, size * 0.08, 1.1 * size + z);
	glTexCoord2f(1.0f, 0.0f); glVertex3f(.8 * size + x, size * 0.9, 1.1 * size + z);
	glTexCoord2f(0.0f, 0.0f); glVertex3f(-.2 * size + x, size * 0.9, 1.1 * size + z);
	glTexCoord2f(0.0f, 1.0f); glVertex3f(-2.7 * size + x, size * 0.08, 1.1 * size + z);
	glEnd();
	glPopMatrix();

	glBindTexture(GL_TEXTURE_2D, avto[5]);
	glPushMatrix();
	glTexEnvf(GL_TEXTURE_ENV,
		GL_TEXTURE_ENV_MODE, GL_MODULATE
	);
	glTranslatef(-2.5, 1, -4);
	glBegin(GL_QUADS);
	glTexCoord2f(1.0f, 1.0f); glVertex3f(2.7 * size + x, size * 0.08, 1.1 * -size + z);
	glTexCoord2f(1.0f, 0.0f); glVertex3f(.8 * size + x, size * 0.9, 1.1 * -size + z);
	glTexCoord2f(0.0f, 0.0f); glVertex3f(-.2 * size + x, size * 0.9, 1.1 * -size + z);
	glTexCoord2f(0.0f, 1.0f); glVertex3f(-2.7 * size + x, size * 0.08, 1.1 * -size + z);
	glEnd();
	glPopMatrix();
	
	//glPopMatrix();
} 


void look() {
	glMatrixMode(GL_MODELVIEW);

}
//свет
void Light() // функция света 
{
	glEnable(GL_LIGHTING);
	glEnable(GL_LIGHT1);
	glEnable(GL_LIGHT2);
	GLfloat ambient0[] = { 0.4, 0.4, 0.4, 1 };
	glLightModelfv(GL_LIGHT_MODEL_AMBIENT, ambient0);

	GLfloat pos1[] = { 1, 1, 1, 0 };
	GLfloat light1_diffuse[] = { .9,.9,.9,1 };
	GLfloat light1_specular[] = { .8,.8,.2,1 };
	glLightfv(GL_LIGHT1, GL_POSITION, pos1);
	glLightfv(GL_LIGHT1, GL_DIFFUSE, light1_diffuse);
	glLightfv(GL_LIGHT1, GL_SPECULAR, light1_specular);

	GLfloat light2_position[] = { 5, 3, 3.64, 1 };
	GLfloat light2_diffuse[] = { .9, .7, .5, 1 };
	GLfloat light2_specular[] = { .3, .2, .1, 1 };
	GLfloat light2_linear_attenuation[] = { .015 };
	glLightfv(GL_LIGHT2, GL_DIFFUSE, light2_diffuse);
	glLightfv(GL_LIGHT2, GL_POSITION, light2_position);
	glLightfv(GL_LIGHT2, GL_SPECULAR, light2_specular);
	glLightfv(GL_LIGHT2, GL_LINEAR_ATTENUATION, light2_linear_attenuation);

	GLfloat material_emission[] = { 0, 0, 0, 1 };
	GLfloat material_diffuse[] = { .8, .8, .8, 1.0 };
	GLfloat material_ambient[] = { .5, .5, .5, 1.0 };
	GLfloat material_specular[] = { .1, .1, .1, 1.0 };
	glMaterialfv(GL_FRONT_AND_BACK, GL_EMISSION, material_emission);
	glMaterialfv(GL_FRONT_AND_BACK, GL_DIFFUSE, material_diffuse);
	glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT, material_ambient);
	glMaterialfv(GL_FRONT_AND_BACK, GL_SPECULAR, material_specular);

	GLUquadricObj* cylinder;
	cylinder = gluNewQuadric();
	GLUquadricObj* disk;
	disk = gluNewQuadric();
	GLUquadricObj* sphere;
	sphere = gluNewQuadric();

	gluQuadricTexture(cylinder, GLU_TRUE);
	gluQuadricNormals(cylinder, GLU_SMOOTH);
	gluQuadricDrawStyle(cylinder, GLU_FILL);
	gluQuadricTexture(disk, GLU_TRUE);
	gluQuadricNormals(disk, GLU_SMOOTH);
	gluQuadricDrawStyle(disk, GLU_FILL);
	Sun();
}



// крыша
void Roof()
{
	float size = 1.f;
	int s = 1;
	float x = 1, y = 0, z = 2.7;
	GLfloat material1_specular[] = { 0, 0, 0, 1.0 };
	glMaterialfv(GL_FRONT_AND_BACK, GL_SPECULAR, material1_specular);
	glBindTexture(GL_TEXTURE_2D, kr[0]);

	gluBuild2DMipmaps(GL_TEXTURE_2D, 0, 3,
		3, GL_RGB, GL_UNSIGNED_BYTE, kr);

	glTexParameteri(GL_TEXTURE_2D,
		GL_TEXTURE_MIN_FILTER,
		GL_LINEAR_MIPMAP_NEAREST);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER,
		GL_LINEAR_MIPMAP_LINEAR);


	glTexEnvf(GL_TEXTURE_ENV,
		GL_TEXTURE_ENV_MODE, GL_MODULATE
	);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);

	glPushMatrix();
	glTranslatef(-5, 0, -10);
	glBegin(GL_TRIANGLES);
	glTexCoord2f(0.0f, 0.0f); glVertex3f(-2.8, 1, 0);
	glTexCoord2f(0.0f, 1.0f); glVertex3f(2.8, 1, 0);
	glTexCoord2f(1.0f, 0.0f); glVertex3f(0, 2, 0);
	glEnd();
	glPopMatrix();
	
	glPushMatrix();
	glTranslatef(-5, 0, -10);
	glBegin(GL_TRIANGLES);
	glTexCoord2f(0.0f, 0.0f); glVertex3f(-2.8, 1, -8);
	glTexCoord2f(0.0f, 1.0f); glVertex3f(2.8, 1, -8);
	glTexCoord2f(1.0f, 0.0f); glVertex3f(0, 2, -8);
	glEnd();
	glPopMatrix();

	glPushMatrix();
	glTranslatef(-5, 0, -10);
	glBegin(GL_QUADS);
	glTexCoord2f(0.0f, 0.0f); glVertex3f(2.8, 1, 0);
	glTexCoord2f(1.0f, 0.0f); glVertex3f(2.8, 1, -8);
	glTexCoord2f(1.0f, 1.0f); glVertex3f(0, 2, -8);
	glTexCoord2f(0.0f, 1.0f); glVertex3f(0, 2, 0);
	glEnd();
	glPopMatrix();

	glPushMatrix();
	glTranslatef(-5, 0, -10);
	glBegin(GL_QUADS);
	glTexCoord2f(0.0f, 0.0f); glVertex3f(-2.8, 1, 0);
	glTexCoord2f(1.0f, 0.0f); glVertex3f(-2.8, 1, -8);
	glTexCoord2f(1.0f, 1.0f); glVertex3f(0, 2, -8);
	glTexCoord2f(0.0f, 1.0f); glVertex3f(0, 2, 0);
	glEnd();
	glPopMatrix();
	glColor3f(1, 1, 1);
	Sun();
}

// дом
void drawHouse()
{
	float size = 1.f;
	int s = 1;
	float x = 1, y = 0, z = 2.7;
	gluBuild2DMipmaps(GL_TEXTURE_2D, 0, 3,
		3, GL_RGB, GL_UNSIGNED_BYTE, texture);
	glTexParameteri(GL_TEXTURE_2D,
		GL_TEXTURE_MIN_FILTER,
		GL_LINEAR_MIPMAP_NEAREST);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER,
		GL_LINEAR_MIPMAP_LINEAR);
	glTexEnvf(GL_TEXTURE_ENV,
		GL_TEXTURE_ENV_MODE,GL_MODULATE
		);

	glTexEnvf(GL_TEXTURE_ENV,
		GL_TEXTURE_ENV_MODE, GL_MODULATE
	);

	GLfloat material1_specular[] = { 0, 0, 0, 1.0 };
	glMaterialfv(GL_FRONT_AND_BACK, GL_SPECULAR, material1_specular);

	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
	glBindTexture(GL_TEXTURE_2D, texture[4]);
	glPushMatrix();
	glTranslatef(-5, 0, -10);
	glBegin(GL_QUADS);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
	glTexCoord2f(1.0f, 1.0f); 
	glVertex3f(-2.8, 1, 0);
	glTexCoord2f(1.0f, 0.0f); 
	glVertex3f(-2.8, -2.5, 0);
	glTexCoord2f(0.0f, 0.0f); 
	glVertex3f(-2.8, -2.5, -8);
	glTexCoord2f(0.0f, 1.0f); 
	glVertex3f(-2.8, 1, -8);
	glEnd();
	glPopMatrix();



	glBindTexture(GL_TEXTURE_2D, texture[5]);
	glPushMatrix();
	glTranslatef(-5, 0, -10);
	glBegin(GL_QUADS);
	glTexCoord2f(0.0f, 1.0f); 
	glVertex3f(2.8, 1, 0);
	glTexCoord2f(0.0f, 0.0f); 
	glVertex3f(2.8, -2.5, 0);
	glTexCoord2f(1.0f, 0.0f); 
	glVertex3f(2.8, -2.5, -8);
	glTexCoord2f(1.0f, 1.0f); 
	glVertex3f(2.8, 1, -8);
	glEnd();
	glPopMatrix();


	glPushMatrix();
	glTranslatef(-5, 0, -10);
	glBegin(GL_QUADS);
	glTexCoord2f(0.0f, 0.0f); 
	glVertex3f(-2.8, -2.5, -8);
	glTexCoord2f(1.0f, 0.0f); 
	glVertex3f(2.8, -2.5, -8);
	glTexCoord2f(1.0f, 1.0f); 
	glVertex3f(2.8, 1, -8);
	glTexCoord2f(0.0f, 1.0f);
	glVertex3f(-2.8, 1, -8);
	glEnd();
	glPopMatrix();
	
	
	glBindTexture(GL_TEXTURE_2D, texture[0]);
	glPushMatrix();
	glTranslatef(-5, 0, -10);
	glEnable(GL_POLYGON_SMOOTH);
	glBegin(GL_QUADS); // основание
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
	glTexCoord2f(0.0f, 0.0f);
	glVertex3f(-2.8, -2.5, 0);
	glTexCoord2f(1.0f, 0.0f);
	glVertex3f(2.8, -2.5, 0);
	glTexCoord2f(1.0f, 1.0f);
	glVertex3f(2.8, 1, 0);
	glTexCoord2f(0.0f, 1.0f);
	glVertex3f(-2.8, 1, 0);
	glEnd();
	glDisable(GL_POLYGON_SMOOTH);
	glPopMatrix();
	
	Roof();




}

void light()
{
	float x=1.5, y=0.8, z=-1 , x0=0, y0=0, z0=0;
	GLfloat material1_specular[] = { 0, 0, 0, 1.0 };
	GLUquadricObj* q;
	GLUquadricObj* k;
	GLUquadricObj* zh;
	GLUquadricObj* zel;
	
	q = gluNewQuadric();
	k = gluNewQuadric();
	zh = gluNewQuadric();
	zel = gluNewQuadric();

	glBindTexture(GL_TEXTURE_2D, panel[0]);
	glBindTexture(GL_TEXTURE_2D, panel[1]);

	
	GLfloat material_emission9[] = { .7, .6, .3, 1 };
	glMaterialfv(GL_FRONT_AND_BACK, GL_EMISSION, material_emission9);
	gluQuadricNormals(q, GLU_SMOOTH);
	gluQuadricDrawStyle(q, GLU_FILL);
	glMaterialfv(GL_FRONT_AND_BACK, GL_EMISSION, material_emission9);
	gluQuadricNormals(k, GLU_SMOOTH);
	gluQuadricDrawStyle(k, GLU_FILL);
	glMaterialfv(GL_FRONT_AND_BACK, GL_EMISSION, material_emission9);
	gluQuadricNormals(zh, GLU_SMOOTH);
	gluQuadricDrawStyle(zh, GLU_FILL);

	glMaterialfv(GL_FRONT_AND_BACK, GL_EMISSION, material_emission9);
	gluQuadricNormals(zel, GLU_SMOOTH);
	gluQuadricDrawStyle(zel, GLU_FILL);


	gluBuild2DMipmaps(GL_TEXTURE_2D, 0, 3,
		3, GL_RGB, GL_UNSIGNED_BYTE, panel);
	glTexParameteri(GL_TEXTURE_2D,
		GL_TEXTURE_MIN_FILTER,
		GL_LINEAR_MIPMAP_NEAREST);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER,
		GL_LINEAR_MIPMAP_LINEAR);
	glTexEnvf(GL_TEXTURE_ENV,
		GL_TEXTURE_ENV_MODE, GL_MODULATE
	);
	glMaterialfv(GL_FRONT_AND_BACK, GL_EMISSION, material_emission9);
	glTranslatef(-3, 0, -10);
	glPushMatrix(); //pered

	glTranslatef(10, -2, 0);


	glEnable(GL_POLYGON_SMOOTH);
	glBegin(GL_QUADS);
	glTexCoord2f(0.0f, 0.0f); glVertex3f(x0, y0, z0);
	glTexCoord2f(1.0f, 0.0f); glVertex3f(x, y0, z0);
	glTexCoord2f(1.0f, 1.0f); glVertex3f(x, y, z0);
	glTexCoord2f(0.0f, 1.0f); glVertex3f(x0, y, z0);
	glEnd();
	glDisable(GL_POLYGON_SMOOTH);
	glPopMatrix();
	glMaterialfv(GL_FRONT_AND_BACK, GL_SPECULAR, material1_specular);
	glPushMatrix();	//zad
	glTranslatef(10, -2, 0);
	glEnable(GL_POLYGON_SMOOTH);
	glBegin(GL_QUADS); 
	glTexCoord2f(0.0f, 0.0f); glVertex3f(x0, y0, z);
	glTexCoord2f(1.0f, 0.0f); glVertex3f(x, y0, z);
	glTexCoord2f(1.0f, 1.0f); glVertex3f(x, y, z);
	glTexCoord2f(0.0f, 1.0f); glVertex3f(x0, y, z);
	glEnd();
	glDisable(GL_POLYGON_SMOOTH);
	glPopMatrix();

	glPushMatrix();//levo
	glTranslatef(10, -2, 0);
	glEnable(GL_POLYGON_SMOOTH);
	glBegin(GL_QUADS); 
	glTexCoord2f(0.0f, 0.0f); glVertex3f(x0, y0, z0);
	glTexCoord2f(0.0f, 1.0f); glVertex3f(x0, y0, z);
	glTexCoord2f(1.0f, 0.0f); glVertex3f(x0, y, z0);
	glTexCoord2f(1.0f, 1.0f); glVertex3f(x0, y, z);
	glEnd();
	glDisable(GL_POLYGON_SMOOTH);
	glPopMatrix();

	glPushMatrix();//pravo
	glTranslatef(10, -2, 0);
	glEnable(GL_POLYGON_SMOOTH);
	glBegin(GL_QUADS); 
	glTexCoord2f(0.0f, 0.0f); glVertex3f(x, y0, z0);
	glTexCoord2f(1.0f, 0.0f); glVertex3f(x, y, z0);
	glTexCoord2f(1.0f, 1.0f); glVertex3f(x, y, z);
	glTexCoord2f(0.0f, 1.0f); glVertex3f(x, y0, z);
	glEnd();
	glDisable(GL_POLYGON_SMOOTH);
	glPopMatrix();

	glPushMatrix();//vverh
	glTranslatef(10, -2, 0);
	glEnable(GL_POLYGON_SMOOTH);
	glBegin(GL_QUADS);
	glTexCoord2f(0.0f, 0.0f); glVertex3f(x0, y, z0);
	glTexCoord2f(1.0f, 0.0f); glVertex3f(x0, y, z);
	glTexCoord2f(1.0f, 1.0f); glVertex3f(x, y, z);
	glTexCoord2f(0.0f, 1.0f); glVertex3f(x, y, z0);
	glEnd();
	glDisable(GL_POLYGON_SMOOTH);
	glPopMatrix();

	glPushMatrix();
	glBindTexture(GL_TEXTURE_2D, panel[0]);
	gluQuadricTexture(q, panel[0]);
	glTranslatef(10+x/2, 3, z/2);
	glRotatef(90, 1, 0, 0);
	gluCylinder(q, 0.2, 0.2, 5, 100, 20);
	glPopMatrix();
	
	glPushMatrix();
	glBindTexture(GL_TEXTURE_2D, panel[1]);
	glTranslatef(10 + x / 4, 3, 0); 
	glBegin(GL_QUADS); //pered2
	glTexCoord2f(0.0f, 0.0f); glVertex3f(x0 / 2, y0, z0);
	glTexCoord2f(1.0f, 0.0f); glVertex3f(x / 2, y0, z0);
	glTexCoord2f(1.0f, 1.0f); glVertex3f(x / 2, y * 1.5, z0);
	glTexCoord2f(0.0f, 1.0f); glVertex3f(x0 / 2, y * 1.5, z0);
	glEnd();
	glPopMatrix();

	glBindTexture(GL_TEXTURE_2D, j[0]);
	glPushMatrix();
	glTranslatef(10+x/4, 3, 0);
	glBegin(GL_QUADS);//zad
	//k.coglTexCoord2f(0.0f, 0.0f); 
	glVertex3f(x0/2, y0, z);
	//glTexCoord2f(1.0f, 0.0f);
	glVertex3f(x/2, y0, z);
	//glTexCoord2f(1.0f, 1.0f);
	glVertex3f(x/2, y * 1.5, z);
	//glTexCoord2f(0.0f, 1.0f);
	glVertex3f(x0/2, y * 1.5, z);
	glEnd();
	glBegin(GL_QUADS);//levo
	glTexCoord2f(0.0f, 1.0f); glVertex3f(x0/2, y0, z0);
	glTexCoord2f(0.0f, 0.0f); glVertex3f(x0 / 2, y * 1.5, z0);
	glTexCoord2f(1.0f, 0.0f); glVertex3f(x0 / 2, y * 1.5, z);
	glTexCoord2f(1.0f, 1.0f); glVertex3f(x0/2, y0, z);
	glEnd();
	glBegin(GL_QUADS);//pravo
	//glTexCoord2f(0.0f, 1.0f); 
	glVertex3f(x/2, y0, z0);
	//glTexCoord2f(0.0f, 0.0f); 
	glVertex3f(x/2, y * 1.5, z0);
	//glTexCoord2f(1.0f, 0.0f); 
	glVertex3f(x/2, y * 1.5, z);
	//glTexCoord2f(1.0f, 1.0f); 
	glVertex3f(x/2, y0, z);
	glEnd();
	glBegin(GL_QUADS);//verh
	glTexCoord2f(0.0f, 0.0f); glVertex3f(x0/2, y * 1.5, z0);
	glTexCoord2f(0.0f, 1.0f); glVertex3f(x0/2, y * 1.5, z);
	glTexCoord2f(1.0f, 1.0f); glVertex3f(x/2, y * 1.5, z);
	glTexCoord2f(1.0f, 0.0f); glVertex3f(x/2, y * 1.5, z0);
	glEnd();
	glPopMatrix();

	
	glPushMatrix();
	glMatrixMode(GL_MODELVIEW);
	glBindTexture(GL_TEXTURE_2D, svet[0]);
	gluQuadricTexture(k, svet[0]);
	glTranslatef(10+x/2, 3+y*1.3, 0);
	gluDisk(k, 0, 0.2, 500, 20);
	glLoadIdentity();
	glPopMatrix();

	glPushMatrix();
	glMatrixMode(GL_MODELVIEW);
	glBindTexture(GL_TEXTURE_2D, svet[1]);
	gluQuadricTexture(k, svet[1]);
	glTranslatef(10 + x / 2, 3 + y*0.8 , 0);
	gluDisk(k, 0, 0.2, 500, 20);
	glLoadIdentity();
	glPopMatrix();

	glPushMatrix();
	glMatrixMode(GL_MODELVIEW);
	glBindTexture(GL_TEXTURE_2D, svet[2]);
	gluQuadricTexture(k, svet[2]);
	glTranslatef(10 + x / 2, 3 + y * 0.3, 0);
	gluDisk(k, 0, 0.2, 500, 20);
	glLoadIdentity();
	glPopMatrix();
	glTranslatef(3, 0, 10);
}


void surface()
{
	float size = 1.f;
	int s = 100;
	GLfloat material1_specular[] = { 0, 0, 0, 1.0 };
	glBindTexture(GL_TEXTURE_2D, texture[3]);
	gluBuild2DMipmaps(GL_TEXTURE_2D, 0, 3,
		3, GL_RGB, GL_UNSIGNED_BYTE, texture);
	glTexParameteri(GL_TEXTURE_2D,
		GL_TEXTURE_MIN_FILTER,
		GL_LINEAR_MIPMAP_NEAREST);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER,
		GL_LINEAR_MIPMAP_LINEAR);
	glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_MAG_FILTER,GL_LINEAR);
	GLUquadricObj* q;
	q = gluNewQuadric();
	glMaterialfv(GL_FRONT_AND_BACK, GL_SPECULAR, material1_specular);
	glPushMatrix();
	glTranslatef(0, -2, 0);
	glRotatef(90, 1, 0, 0);
	glBindTexture(GL_TEXTURE_2D, kol[2]);
	gluQuadricTexture(q, kol[2]);
	gluDisk(q, 0, 30, 200, 200);
	glColor3f(1, 1, 1);
	glPopMatrix();
}


void skybox(GLuint *box)
{
	float size = 500.f;
	glBindTexture(GL_TEXTURE_2D, box[0]);
	glBegin(GL_QUADS);
	//front
	glTexCoord2f(0, 0);   glVertex3f(-size, -size, -size);
	glTexCoord2f(1, 0);   glVertex3f(size, -size, -size);
	glTexCoord2f(1, 1);   glVertex3f(size, size, -size);
	glTexCoord2f(0, 1);   glVertex3f(-size, size, -size);
	glEnd();

	glBindTexture(GL_TEXTURE_2D, box[1]);
	glBegin(GL_QUADS);
	//back
	glTexCoord2f(0, 0); glVertex3f(size, -size, size);
	glTexCoord2f(1, 0); glVertex3f(-size, -size, size);
	glTexCoord2f(1, 1); glVertex3f(-size, size, size);
	glTexCoord2f(0, 1); glVertex3f(size, size, size);
	glEnd();

	glBindTexture(GL_TEXTURE_2D, box[2]);
	glBegin(GL_QUADS);
	//left
	glTexCoord2f(0, 0); glVertex3f(-size, -size, size);
	glTexCoord2f(1, 0); glVertex3f(-size, -size, -size);
	glTexCoord2f(1, 1); glVertex3f(-size, size, -size);
	glTexCoord2f(0, 1); glVertex3f(-size, size, size);
	glEnd();

	glBindTexture(GL_TEXTURE_2D, box[3]);
	glBegin(GL_QUADS);
	//right
	glTexCoord2f(0, 0); glVertex3f(size, -size, -size);
	glTexCoord2f(1, 0); glVertex3f(size, -size, size);
	glTexCoord2f(1, 1); glVertex3f(size, size, size);
	glTexCoord2f(0, 1); glVertex3f(size, size, -size);
	glEnd();

	glBindTexture(GL_TEXTURE_2D, box[4]);
	glBegin(GL_QUADS);
	//bottom
	glTexCoord2f(0, 0); glVertex3f(-size, -size, size);
	glTexCoord2f(1, 0); glVertex3f(size, -size, size);
	glTexCoord2f(1, 1); glVertex3f(size, -size, -size);
	glTexCoord2f(0, 1); glVertex3f(-size, -size, -size);
	glEnd();

	glBindTexture(GL_TEXTURE_2D, box[5]);
	glBegin(GL_QUADS);
	//top  		
	glTexCoord2f(0, 0); glVertex3f(-size, size, -size);
	glTexCoord2f(1, 0); glVertex3f(size, size, -size);
	glTexCoord2f(1, 1); glVertex3f(size, size, size);
	glTexCoord2f(0, 1); glVertex3f(-size, size, size);
	glEnd();
}


void display(void) //РАДУГУ!!!
{
	glFrontFace(GL_CW);
	GLfloat material1_specular[] = { 0, 0, 0, 1.0 };
	
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	Light();
	gluLookAt(i, u, pz, -5, 0.0, -10, 0.0, 1.0, 0.0);
	GLUquadricObj* q;
	GLUquadricObj* r;

	q = gluNewQuadric();
	r = gluNewQuadric();
	gluBuild2DMipmaps(GL_TEXTURE_2D, 0, 3,
		3, GL_RGB, GL_UNSIGNED_BYTE, texture);

	glTexParameteri(GL_TEXTURE_2D,
		GL_TEXTURE_MIN_FILTER,
		GL_LINEAR_MIPMAP_NEAREST);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER,
		GL_LINEAR_MIPMAP_LINEAR);
	gluQuadricNormals(q, GLU_SMOOTH);
	gluQuadricDrawStyle(q, GLU_FILL);

	skybox(sky);
	light();

	surface();
	glMaterialfv(GL_FRONT_AND_BACK, GL_SPECULAR, material1_specular);
	glPushMatrix();  //1
	glTranslatef(0, -1.5, 0);
	glRotatef(angel, 0, 1, 0);
	glTranslatef(0 + camera, 0 , 0);
	if (flag == 1)
	{
		glRotatef(povz, 0, 1, 0);
	}
	else if (flag == 2)
		glRotatef(0, 0, 1, 0);
	
	glBindTexture(GL_TEXTURE_2D, kol[1]);
	gluQuadricTexture(r, kol[1]);
	glLoadIdentity;
	glRotatef(py, 0, 0, 1);
	gluCylinder(r, 0.5, 0.5, 0.5, 100, 20);
	glBindTexture(GL_TEXTURE_2D, kol[0]);
	gluQuadricTexture(q, kol[0]);
	gluDisk(q, 0, 0.5, 200, 20);
	glPopMatrix();
	glMaterialfv(GL_FRONT_AND_BACK, GL_SPECULAR, material1_specular);
	glPushMatrix();  //2
	
	glTranslatef(0, -1.5, 0);

	glRotatef(angel, 0, 1, 0);
	glTranslatef(2.54 + camera, 0 , 0+w);

	glLoadIdentity;
	glRotatef(py, 0, 0, 1);
	gluQuadricTexture(r, kol[1]);
	glBindTexture(GL_TEXTURE_2D, kol[1]);
	gluCylinder(r, 0.5, 0.5, 0.5, 500, 20);
	glBindTexture(GL_TEXTURE_2D, kol[0]);
	gluQuadricTexture(q, kol[0]);
	gluDisk(q, 0, 0.5, 500, 20);
	glPopMatrix();

	
	
	glMaterialfv(GL_FRONT_AND_BACK, GL_SPECULAR, material1_specular);
	glPushMatrix();  //3
	
	glTranslatef(0, -1.5, 0);
	
	glRotatef(angel, 0, 1, 0);
	glTranslatef(0+camera, 0 , 3+w);
	if (flag == 1)
	{
		glRotatef(povz, 0, 1, 0);
	}
	else if (flag == 2)
	{
		glRotatef(0, 0, 1, 0);

	}
		//glRotatef(povz, 0, 1, 0);
	glLoadIdentity;
	glRotatef(py, 0, 0, 1);
	glBindTexture(GL_TEXTURE_2D, kol[1]);
	gluCylinder(r, 0.5, 0.5, 0.5, 500, 20);
	glTranslatef(0 , 0, 0.5);
	glBindTexture(GL_TEXTURE_2D, kol[0]);
	gluDisk(q,0, 0.5,500,20);
	glPopMatrix();
	glMaterialfv(GL_FRONT_AND_BACK, GL_SPECULAR, material1_specular);
	glPushMatrix();  //4
	
	glTranslatef(0, -1.5, 0);
	glRotatef(angel, 0, 1, 0);
	glTranslatef(2.54+camera, 0 , 3+w);
	drawQube();
	glRotatef(py, 0, 0, 1);
	glTexEnvf(GL_TEXTURE_ENV,
		GL_TEXTURE_ENV_MODE, GL_MODULATE
	);

	glBindTexture(GL_TEXTURE_2D, kol[1]);
	gluCylinder(r, 0.5, 0.5, 0.5, 500, 20);
	glTranslatef(0, 0, 0.5);
	glBindTexture(GL_TEXTURE_2D, kol[0]);
	gluDisk(q, 0, 0.5, 500, 20);
	glPopMatrix();
	drawHouse();
	glutSwapBuffers();
}
void reshape(int w, int h)
{
	glViewport(0, 0, (GLsizei)w, (GLsizei)h);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluPerspective(20.0, (GLfloat)w / (GLfloat)h, 1.0, 800.0);
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	
	
}

void keyboard(unsigned char key, int x, int y)
{
	int flagup = 0;
	switch (key) {
	case 's':
		camera = camera + 0.3;
		if(k)
		pov = pov - 0.05;
		else
		pov = pov - 0.05;
		flag = 2;
		py = (py - 15) % 360;
		glutPostRedisplay();
		break;
	case 'w':
		if (k)
			pov = pov - 0.05;
		else
			pov = pov - 0.05;
		flag= 2;
		camera = camera - 0.3;
		//if(camera== -10)
		py = (py + 15) % 360;
		glutPostRedisplay();
		break;
	case 'a':
		k = 0;
		pov = pov - 0.1;
		camera = camera + 0.3;
		glutPostRedisplay();
		break;
	case 'd':
		k = 1;
		pov = pov - 0.1;
		camera = camera + 0.3;
		//py = (py + 15) % 360;
		glutPostRedisplay();
		break;
	case 'e':
		angel = (angel - 2) % 360;
		py = (py + 5) % 360;
		povz = -30;
		flag = 1;
		glutPostRedisplay();
		break;
	case 'q':
		angel = (angel + 2) % 360;
		flag = 1;
		py = (py - 5) % 360;
		glutPostRedisplay();
		break;
	case 't':
		pz = pz + 0.5;
		glutPostRedisplay();
		break;
	case 'y':
		pz = pz - 0.5;
		glutPostRedisplay();
		break;
	case 'u':
		i += 0.5;
		//u += 0.1;
		glutPostRedisplay();
		break;
	case 'i':
		i -= 0.5;
		//u -= 0.1;
		glutPostRedisplay();
		break;
	default:
		break;
	}
}
int main(int argc, char** argv)
{
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DEPTH | GLUT_DOUBLE | GLUT_RGBA);
	glutInitWindowPosition(0, 0);
	glutInitWindowSize(1920, 1080);
	glutCreateWindow("Scene");
	
	glEnable(GL_BLEND);

	glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);	
	glLightModelf(GL_LIGHT_MODEL_TWO_SIDE, GL_TRUE);
	glEnable(GL_NORMALIZE);
	glTexEnvf(GL_TEXTURE_ENV,
		GL_TEXTURE_ENV_MODE, GL_MODULATE
	);
	init();
	glutDisplayFunc(display);
	glutReshapeFunc(reshape);
	glutKeyboardFunc(keyboard);
	LoadGLTextures();
	look();
	glColor3f(1, 1, 1);
	glutMainLoop();
	return 0;
}