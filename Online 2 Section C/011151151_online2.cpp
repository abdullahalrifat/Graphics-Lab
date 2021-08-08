#include <GL/glut.h>
#include <math.h>


float speedOfSmallCircle    = 6;//Replace value here
float speedOfSquare         = 7;//Replace value here
float speedOfLargecirle     = 6;//Replace value here
float rotationSpeedOfSquare = 0.2;//Replace value here

typedef struct Point{
    float x,y;
}Point;

Point positionOfSmallCircle = {0,0};
Point positionOfSquare      = {0,0};
Point positionOfLargeCircle = {0,0};

float angleOfSquare =0;


void drawCirle(float radius){
    glColor3f(0.2,0.3,0.5);
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

void drawSquare(float length){
    glColor3f(0.9,0.1,0.7);
    glBegin(GL_QUADS);
        glVertex2f(-length/2,-length/2);
        glVertex2f(length/2,-length/2);
        glVertex2f(length/2,length/2);
        glVertex2f(-length/2,length/2);
    glEnd();
}

void display(void)
{
    glClear(GL_COLOR_BUFFER_BIT);
    drawAxes();
	glPushMatrix();
        glTranslated(positionOfLargeCircle.x,positionOfLargeCircle.y,0);
        drawCirle(12);
	glPopMatrix();

	glPushMatrix();
        glTranslated(positionOfSquare.x,positionOfSquare.y,0);
        glRotated(angleOfSquare,0,0,1);
        drawSquare(16);
	glPopMatrix();

	glPushMatrix();
        glTranslated(positionOfSmallCircle.x,positionOfSmallCircle.y,0);
        drawCirle(5);
	glPopMatrix();

	glFlush();
}

void spinDisplay_left(void)
{
    angleOfSquare += rotationSpeedOfSquare;
    glutPostRedisplay();
}

void spinDisplay_right(void)
{
    angleOfSquare -= rotationSpeedOfSquare;
    glutPostRedisplay();
}

void moveLeft(){
    positionOfLargeCircle.x -= speedOfLargecirle;
    positionOfSquare.x -= speedOfSquare;
}

void moveRight(){
    positionOfLargeCircle.x += speedOfLargecirle;
    positionOfSquare.x += speedOfSquare;
}

void moveUp(){
    positionOfLargeCircle.y += speedOfLargecirle;
    positionOfSquare.y += speedOfSquare;
}

void moveDown(){
    positionOfLargeCircle.y -= speedOfLargecirle;
    positionOfSquare.y -= speedOfSquare;
}

void init(void)
{
	glClearColor (0.0, 0.0, 0.0, 0.0);
	glOrtho(-100.0, 100.0, -100.0,100.0, 0.0, 1.0);
}


void my_keyboard(unsigned char key, int x, int y)
{

	switch (key) {

		case 'l':
			moveLeft();
			break;

		case 'r':
			moveRight();
			break;

		case 'u':
			 moveUp();
			 break;

        case 'd':
			 moveDown();
			 break;

	  default:
			break;
	}
	glutPostRedisplay();
}

void spe_key(int key, int x, int y)
{

	switch (key) {

		case GLUT_KEY_UP:
				positionOfSmallCircle.y += speedOfSmallCircle;
				glutPostRedisplay();
				break;



		case GLUT_KEY_DOWN:
				positionOfSmallCircle.y -= speedOfSmallCircle;
				glutPostRedisplay();
				break;

        case GLUT_KEY_RIGHT:
				positionOfSmallCircle.x += speedOfSmallCircle;
				glutPostRedisplay();
				break;



		case GLUT_KEY_LEFT:
                positionOfSmallCircle.x -= speedOfSmallCircle;
				glutPostRedisplay();
				break;



        default:
                break;
	}
}


void my_mouse(int button, int state, int x, int y)
{
   switch (button) {
      case GLUT_LEFT_BUTTON:
         if (state == GLUT_DOWN)
            glutIdleFunc(spinDisplay_left);
         break;
      case GLUT_RIGHT_BUTTON:
         if (state == GLUT_DOWN)
            glutIdleFunc(spinDisplay_right);
         break;
      case GLUT_MIDDLE_BUTTON:
        glutIdleFunc(NULL);
      default:
         break;
   }
}

int main(int argc, char *argv[])
{
    glutInit( & argc, argv );
	glutInitWindowSize (750, 750);
	glutInitWindowPosition (10, 10);

	glutCreateWindow ("Online 2");
	init();


    glutDisplayFunc(display);
	glutKeyboardFunc(my_keyboard);
    glutSpecialFunc(spe_key);

	glutMouseFunc(my_mouse);


	glutMainLoop();
	return 0;
}
