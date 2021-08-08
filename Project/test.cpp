#include <GL/glut.h>
#include <GL/gl.h>
#include <stdio.h>
#include<string>
using namespace std;

int main(int argc, char** argv)
{
    //create GL context
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_RGBA);
    glutInitWindowSize(800, 600);
    glutCreateWindow("windowname");

    //create test checker image
    unsigned char texDat[64];
    for (int i = 0; i < 64; ++i)
        texDat[i] = ((i + (i / 8)) % 2) * 128 + 127;

    // Actual RGB data
	unsigned char * data;
    unsigned char header[54];
	unsigned int dataPos;
	unsigned int imageSize;
	unsigned int width, height;
	// Open the file
    string imagepath = "asset/background.bmp";
	FILE * file = fopen("asset/background.bmp","rb");
	if (!file)							    
    {
        printf("%s could not be opened. Are you in the right directory ? Don't forget to read the FAQ !\n", "asset/background.bmp");
         getchar();
          return 0;
    }
    // If less than 54 bytes are read, problem
	if ( fread(header, 1, 54, file)!=54 ){ 
		printf("Not a correct BMP file\n");
		return 0;
	}
	// A BMP files always begins with "BM"
	if ( header[0]!='B' || header[1]!='M' ){
		printf("Not a correct BMP file\n");
		return 0;
	}
	// Make sure this is a 24bpp file
	if ( *(int*)&(header[0x1E])!=0  )         {printf("Not a correct BMP file\n");    return 0;}
	if ( *(int*)&(header[0x1C])!=24 )         {printf("Not a correct BMP file\n");    return 0;}

	// Read the information about the image
	dataPos    = *(int*)&(header[0x0A]);
	imageSize  = *(int*)&(header[0x22]);
	width      = *(int*)&(header[0x12]);
	height     = *(int*)&(header[0x16]);

	// Some BMP files are misformatted, guess missing information
	if (imageSize==0)    imageSize=width*height*3; // 3 : one byte for each Red, Green and Blue component
	if (dataPos==0)      dataPos=54; // The BMP header is done that way

	// Create a buffer
	data = new unsigned char [imageSize];

	// Read the actual data from the file into the buffer
	fread(data,1,imageSize,file);


	// Read the header, i.e. the 54 first bytes


    //upload to GPU texture
    GLuint tex;
    glGenTextures(1, &tex);
    glBindTexture(GL_TEXTURE_2D, tex);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
    glTexImage2D(GL_TEXTURE_2D, 0, GL_LUMINANCE, 8, 8, 0, GL_LUMINANCE, GL_UNSIGNED_BYTE, data);
    glBindTexture(GL_TEXTURE_2D, 0);

    //match projection to window resolution (could be in reshape callback)
    glMatrixMode(GL_PROJECTION);
    glOrtho(0, 800, 0, 600, -1, 1);
    glMatrixMode(GL_MODELVIEW);

    //clear and draw quad with texture (could be in display callback)
    glClear(GL_COLOR_BUFFER_BIT);
    glBindTexture(GL_TEXTURE_2D, tex);
    glEnable(GL_TEXTURE_2D);
    glBegin(GL_QUADS);
    glTexCoord2i(0, 0); glVertex2i(100, 100);
    glTexCoord2i(0, 1); glVertex2i(100, 500);
    glTexCoord2i(1, 1); glVertex2i(500, 500);
    glTexCoord2i(1, 0); glVertex2i(500, 100);
    glEnd();
    glDisable(GL_TEXTURE_2D);
    glBindTexture(GL_TEXTURE_2D, 0);
    glFlush(); //don't need this with GLUT_DOUBLE and glutSwapBuffers

    getchar(); //pause so you can see what just happened
    //System("pause"); //I think this works on windows

    return 0;
}