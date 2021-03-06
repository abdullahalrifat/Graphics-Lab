#include <GL/glut.h>
#include <math.h>

float rotationSpeedOfEarth = 0.05;
float rotationSpeedOfMoon  = 0.1;

float distanceOfEarth      = 50;
float distanceOfMoon       = 20;

float radiusOfEarth        = 6;
float radiusOfMoon         = 4;
float radiusOfSun          = 8;

float angleOfEarth         = 0;
float angleOfMoon          = 0;

void drawCirle(float radius){
    glBegin(GL_POLYGON);
        for(int i=0;i<360;i++){
            glVertex2f(radius*cos(i),radius*sin(i));
        }
    glEnd();
}

void drawAxes(){
    glColor3f(1,1,1);
    glBegin(GL_LINES);
        glVertex2f(-100,0);
        glVertex2f( 100,0);

        glVertex2f(0,-100);
        glVertex2f(0, 100);
    glEnd();
}

void animate(){
    angleOfEarth += rotationSpeedOfEarth;
    angleOfMoon += rotationSpeedOfMoon;
    glutPostRedisplay();
}

void display(void)
{
    glClear(GL_COLOR_BUFFER_BIT);
    drawAxes();

    glColor3f(1,0,0);
	drawCirle(radiusOfSun);
	glPushMatrix();
        glRotated(angleOfEarth,0,0,1);
        glTranslated(distanceOfEarth,0,0);
        glColor3f(0,1,0);
        drawCirle(radiusOfEarth);
        glPushMatrix();
            glRotated(angleOfMoon,0,0,1);
            glTranslated(distanceOfMoon,0,0);
            glColor3f(1,1,1);
            drawCirle(radiusOfMoon);
        glPopMatrix();
	glPopMatrix();

	glFlush();
}

void init(void)
{
	glClearColor (0.0, 0.0, 0.0, 0.0);
	glOrtho(-100.0, 100.0, -100.0,100.0, 0.0, 1.0);
}


int main(int argc, char *argv[])
{
    glutInit( & argc, argv );
    //PlaySound("Horn Honk-SoundBible.com-1162546405.wav", NULL, SND_FILENAME| SND_ASYNC);
	glutInitWindowSize (750, 750);
	glutInitWindowPosition (10, 10);

	glutCreateWindow ("Practice Space");
	init();
    glutDisplayFunc(display);
    glutIdleFunc(animate);

	glutMainLoop();
	return 0;
}