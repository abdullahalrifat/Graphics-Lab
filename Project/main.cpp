
#include <GL/glut.h>
#include <GL/gl.h>
#include <math.h>
#include <fstream>
#include <string.h>
#include "SOIL/SOIL.h"
#include "include/RGBpixmap/RGBpixmap.h"


#define PI 3.1416

int playerXOffset = 0, playerYOffset = 0;

class vertex2f
{
public:
    float x, y;

    vertex2f(float a, float b){x=a; y=b;}
};
vertex2f pa(-.5,0);
vertex2f pb(.5,0);
vertex2f pc(-.5,.5);
vertex2f pd(.5,.5);


void initGL() {
    glClearColor(0.0f, 0.0f, 0.0f, 0.0f); //background clear
    glMatrixMode(GLUT_SINGLE | GLUT_RGB);
    glLoadIdentity();
    glOrtho(-1,1,-1,1,-1,1);
   
}


GLuint texture[0];

void resize(int height, int width) {
    const float ar = (float) width / (float) height;
    glViewport(0, 10, width, height);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();

    glFrustum(-ar, ar, -1.0, 1.0, 2.0, 90.0);
    //gluLookAt(0, 2, 0, -1, 1, -3, 0, 1, 0);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity() ;
}
static void Draw(void)
{
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glLoadIdentity();
    glTranslatef(0.0f,0.0f,-5.0f);
    texture[0] = SOIL_load_OGL_texture // load an image file directly as a new OpenGL texture
    (
        "asset/player.png",
        SOIL_LOAD_AUTO,
        SOIL_CREATE_NEW_ID,
        SOIL_FLAG_MIPMAPS | SOIL_FLAG_INVERT_Y | SOIL_FLAG_NTSC_SAFE_RGB | SOIL_FLAG_COMPRESS_TO_DXT
    );
// allocate a texture name
    glEnable(GL_TEXTURE_2D);

    glBindTexture(GL_TEXTURE_2D, texture[0]);
    /*glBegin(GL_TRIANGLES);
    glTexCoord2f(0.0f, 0.0f);glVertex3f(0.0f, 0.0f, 0.0f);
    glTexCoord2f(1.0f, 0.0f);glVertex3f(1.0f, 0.0f, 0.0f);
    glTexCoord2f(0.0f, 1.0f);glVertex3f(0.0f, 1.0f, 0.0f);*/
    glPushMatrix();
    glBegin(GL_QUADS);
    pa.x += playerXOffset;
    pb.x += playerXOffset;
    pc.x += playerXOffset;
    pd.x += playerXOffset;

    pa.y += playerYOffset;
    pb.y += playerYOffset;
    pc.y += playerYOffset;
    pd.y += playerYOffset;

    glTexCoord2f(pa.x, pa.y);glVertex2f(pa.x,pa.y);
    glTexCoord2f(pb.x, pb.y);glVertex2f(pb.x,pb.y);
    glTexCoord2f(pc.x, pc.y);glVertex2f(pc.x,pc.y);
    glTexCoord2f(pd.x, pd.y);glVertex2f(pd.x,pd.y);
    glEnd();
    glPopMatrix();
    glutSwapBuffers();
}
void display() {
/*
   glClear(GL_COLOR_BUFFER_BIT);// Buffer CLear
   //drawObjects();
   //practiceObjects();
   glBegin(GL_LINES);
        glColor3f(1,1,1);
        glVertex2f(-10,0);
        glVertex2f(10,0);

        glVertex2f(0,-10);
        glVertex2f(0,10);
    glEnd();

    

    loadImage();
    
    glBegin(GL_QUADS);
        //glColor3f(0.2,0,0.3);

        glVertex2f(.4,0);
        glVertex2f(.6,0);
        glVertex2f(.6,.4);
        glVertex2f(.4,.4);
    glEnd();

   glFlush(); //render
   */
  /*glMatrixMode(GL_PROJECTION);
  glLoadIdentity();
  glOrtho(-20,20,-20,20,-1,1);

  glEnable(GL_ALPHA_TEST);
  glAlphaFunc(GL_EQUAL,1.0);

  glPixelZoom(1,1);
  glRasterPos2i(-20,-20);
  pix[0].draw();

  glutSwapBuffers();
   glFlush();
  */
 glClear(GL_COLOR_BUFFER_BIT);
    

     glFlush();

}
void specialKeyboarddEventHandler(int key, int x, int y)
{
    float change_value = 1;
    switch (key) {

		case GLUT_KEY_LEFT:
				playerXOffset = change_value*-1;
				glutPostRedisplay();
				break;

		case GLUT_KEY_RIGHT:
				playerXOffset = change_value;
				glutPostRedisplay();
				break;

        case GLUT_KEY_DOWN:
                playerYOffset = change_value*-1;
				glutPostRedisplay();
				break;

		case GLUT_KEY_UP:
				playerYOffset = change_value;
				glutPostRedisplay();
				break;
	  default:
			break;
	}
}
int main(int argc, char *argv[])
{
    glutInit(& argc, argv);
    glutInitWindowSize(600,600);
    glutInitWindowPosition(0,0);
    glutCreateWindow("My_First_GL_program");
    glutReshapeFunc(resize);
    glutSpecialFunc(specialKeyboarddEventHandler);

    glutDisplayFunc(Draw);
    //glutDisplayFunc(display);
    

    glutMainLoop();
    return 0;
}