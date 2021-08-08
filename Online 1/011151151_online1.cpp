#include <GL/glut.h>
#include <GL/gl.h>
#include <math.h>

#define PI 3.1416

void initGL() {
   glClearColor(0.0f, 0.0f, 0.0f, 0.0f); //background clear
   glOrtho(-1,1,-1,1,-1,1);
}

void drawObjects(){
   glBegin(GL_LINES);
        glColor3f(1,1,1);
        glVertex2f(-10,0);
        glVertex2f(10,0);

        glVertex2f(0,-10);
        glVertex2f(0,10);
    glEnd();

    glBegin(GL_QUADS);
        glColor3f(0.2,0,0.3);

        glVertex2f(-.4,0);
        glVertex2f(-.8,.4);
        glVertex2f(-.4,.8);
        glVertex2f(0,.4);
    glEnd();


    glBegin(GL_QUADS);
        glColor3f(0.2,0,0.3);

        glVertex2f(.3,0);
        glVertex2f(.3,.4);
        glVertex2f(.7,.4);
        glVertex2f(.7,.0);
    glEnd();

      glBegin(GL_TRIANGLES);
        glColor3f(0,0,1);

        glVertex2f(.2,.4);
        glVertex2f(.5,.7);
        glVertex2f(.8,.4);
    glEnd();

    glBegin(GL_POLYGON);
        glColor3f(1,0,1);

        glVertex2f(0,0);

        float rx2=-.4, ry2=-.3;
        for(int i=0;i<=100;i++)
        {
            glVertex2f(rx2*cos((PI/2)*i/100), ry2*sin((PI/2)*i/100));
        }
    glEnd();
    
}

void display() {

   glClear(GL_COLOR_BUFFER_BIT);// Buffer CLear
   drawObjects();
   glFlush(); //render
}

int main(int argc, char *argv[])
{
    glutInit(& argc, argv);
    glutInitWindowSize(600,600);
    glutInitWindowPosition(0,0);
    glutCreateWindow("My_First_GL_program");
    initGL();
    glutDisplayFunc(display);
    glutMainLoop();
    return 0;
}
