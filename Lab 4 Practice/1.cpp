#include <GL/glut.h>
#include <GL/gl.h>
#include <math.h>

#define PI 3.1416

double angle = 0.0;

void initGL() {
   glClearColor(0.0f, 0.0f, 0.0f, 0.0f); //background clear
   glOrtho(-20,20,-20,20,-20,20);
}

void drawObjects(){
    glPushMatrix();
        glRotatef(angle,0,0,1);
        glBegin(GL_QUADS);
            glVertex2f(-15,-15);
            glVertex2f(15,-15);
            glVertex2f(15,15);
            glVertex2f(-15,15);
        glEnd();
    glPopMatrix();

    glBegin(GL_LINES);
        glColor3f(0.2,0.3,0.1);
        glVertex2f(-20,0);
        glVertex2f(20,0);

        glVertex2f(0,-20);
        glVertex2f(0,20);
    glEnd();

    /*glPushMatrix();
        glRotatef(angle,0,0,1);
        glBegin(GL_LINES);
            glColor3f(0.2,0.1,0.5);

            glVertex2f(0,0);
            glVertex2f(5,0);
        glEnd();
    glPopMatrix();*/
}

void display() {

   glClear(GL_COLOR_BUFFER_BIT);// Buffer CLear
   drawObjects();
   glFlush(); //render
}

void mouseEventHandler(int button, int state, int x, int y)
{

}
void keyboardEventHandler(unsigned char key, int x, int y)
{

}
void specialKeyboarddEventHandler(int key, int x, int y)
{
    switch (key) {

		case GLUT_KEY_LEFT:
				//tx -=5;
				glutPostRedisplay();
				break;

		case GLUT_KEY_RIGHT:
				//tx +=5;
				glutPostRedisplay();
				break;

        case GLUT_KEY_DOWN:
				//ty -=5;
                angle -=5;
				glutPostRedisplay();
				break;

		case GLUT_KEY_UP:
				//ty +=5;
                angle +=5;
				glutPostRedisplay();
				break;
	  default:
			break;
	}
}
int main(int argc, char *argv[])
{
    glutInit( & argc, argv );
    glutInitWindowSize(600,600);
    glutInitWindowPosition(0,0);
    glutCreateWindow("My_First_GL_program");
    glutMouseFunc(mouseEventHandler);
    glutKeyboardFunc(keyboardEventHandler);
    glutSpecialFunc(specialKeyboarddEventHandler);
    initGL();
    glutDisplayFunc(display);
    glutMainLoop();
    return 0;
}