
#include <GL/glut.h>
#include <GL/gl.h>
#include <math.h>

#define PI 3.1416

void initGL() {
   glClearColor(0.0f, 0.0f, 0.0f, 0.0f); //background clear
   glOrtho(-1,1,-1,1,-1,1);
}

void drawExamples()
{
    glBegin(GL_QUADS);
        glColor3f(1,0,0);
        glVertex2f(0,0);
        glVertex2f(4, 0);
        glVertex2f(4+2*cos(PI/6), 2*sin(PI/6));
        glVertex2f(2*cos(PI/6), 2*sin(PI/6));
    glEnd();

    glBegin(GL_QUADS);
        glColor3f(0,1,0);

        glVertex2f(-2,-2);
        glVertex2f(2,-2);
        glVertex2f(2,2);
        glVertex2f(-2,2);
    glEnd();

    glBegin(GL_TRIANGLES);
        glColor3f(0,0,1);

        glVertex2f(-2,0);
        glVertex2f(2,0);
        glVertex2f(0,4);
    glEnd();

    glBegin(GL_POLYGON);
        glColor3f(1,1,0);

        glVertex2f(-4,-4);
        glVertex2f(0,-2);
        glVertex2f(4,-4);
        glVertex2f(2,0);
        glVertex2f(4,4);
        glVertex2f(0,2);
        glVertex2f(-4,4);
        glVertex2f(-2,0);
        glVertex2f(-4,-4);
    glEnd();


    float rx=5,ry=5;
    glBegin(GL_POLYGON);
        glColor3f(0,1,1);
        for(int i=0; i<100; i++)
        {
            glVertex2f(rx*cos(2*PI*i/100), ry*sin(2*PI*i/100));
        }
    glEnd();

    glBegin(GL_POLYGON);
        glColor3f(1,0,1);

        glVertex2f(0,0);

        float rx2=4, ry2=4;
        for(int i=0;i<=100;i++)
        {
            glVertex2f(rx2*cos((PI/2)*i/100), ry2*sin((PI/2)*i/100));
        }
    glEnd();


    glBegin(GL_POLYGON);
        glColor3f(1,0,1);

        float rx3=5, ry3= 5;

        for(int i=0; i<=100; i++)
        {
            glVertex2f(rx3*cos(PI*i/100), ry3*sin(PI*i/100));
        }
    glEnd();

    glBegin(GL_POLYGON);
        glColor3f(0.3,0,0.2);

        float rx4=4,ry4=4;
        for(int i=-50;i<=50;i++){
            glVertex2f(rx4* cos(PI*i/100), ry4* sin(PI*i/100));
        }
    glEnd();
}

void practiceObjects(){
    glBegin(GL_TRIANGLES);
        glColor3f(0,1,0);

        glVertex2f(.2,.4);
        glVertex2f(.8,.4);
        glVertex2f(.5,.6);

        glVertex2f(.3,.5);
        glVertex2f(.7,.5);
        glVertex2f(.5,.8);

        glVertex2f(.4,.7);
        glVertex2f(.6,.7);
        glVertex2f(.5,.9);
    glEnd();

    glBegin(GL_QUADS);
        glColor3f(0.2,0,0.3);

        glVertex2f(.4,0);
        glVertex2f(.6,0);
        glVertex2f(.6,.4);
        glVertex2f(.4,.4);
    glEnd();
}

void drawObjects(){

    glBegin(GL_LINES);
        glColor3f(1,1,1);
        glVertex2f(-10,0);
        glVertex2f(10,0);

        glVertex2f(0,-10);
        glVertex2f(0,10);
    glEnd();

    /*glBegin(GL_TRIANGLES);
        glColor3f(0.3,0.4,0.3);

        glVertex2f(4,2);
        glVertex2f(10,2);
        glVertex2f(7,5);
    glEnd();

    glBegin(GL_QUADS);
        glColor3f(0.2,0.4,0.1);

        glVertex2f(5,0);
        glVertex2f(9,0);
        glVertex2f(9,3);
        glVertex2f(5,3);
    glEnd();

    glBegin(GL_POLYGON);
        glColor3f(0.5,0.5,0.1);

        glVertex2f(7,5);
        float radius = 5;

        for(int i=45;i<=135;i++)
        {
            glVertex2f(7+radius*cos((PI/2)*i/90), 9+ radius*sin((PI/2)*i/90));
        }
    glEnd();*/
    
}

void display() {

   glClear(GL_COLOR_BUFFER_BIT);// Buffer CLear
   drawObjects();
   //practiceObjects();
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