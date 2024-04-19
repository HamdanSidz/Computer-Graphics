
#include <GL/glut.h>
#include <iostream>
#include <fstream>
#include <math.h>

using namespace std;


const int screenWidth = 640;	   // width of screen window in pixels
const int screenHeight = 460;	   // height of screen window in pixels

void init(void)
{
	glClearColor(1.0, 1.0, 1.0, 0.0);       // background color is white
	glColor3f(0.0f, 0.0f, 0.0f);         // drawing color is black
	glPointSize(2.0);		          // a 'dot' is 2 by 2 pixels
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluOrtho2D(0.0, (GLdouble)screenWidth, 0.0, (GLdouble)screenHeight);//dino window
	glViewport(0, 0, screenWidth, screenHeight);

}

void setWindow(int xs, int xe, int ys, int ye) {
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluOrtho2D((GLint)xs, (GLint)xe, (GLint)ys, (GLint)ye);
}


void drawPolyLineFile(const char* fileName)
{
	fstream inStream;

	inStream.open(fileName, ios::in);	// open the file

	if (inStream.fail())
	{
		cout << "can't open it!"; return;
	}

	GLfloat numpolys, numPoints, x, y;
	inStream >> numpolys;		           // read the number of polylines

	for (int j = 0; j < numpolys; j++)  // read each polyline
	{
		inStream >> numPoints;       //number of points in first PolyLine
		glBegin(GL_LINE_STRIP);	     // draw the next polyline
		for (int i = 0; i < numPoints; i++)
		{
			inStream >> x >> y;        // read the next x, y pair
			glVertex2f(x, y);
		}
		glEnd();
	}
	inStream.close();
}

void tiling(){
    setWindow(0,640.0,0,440.0);
    for( int i =0; i<10;i++){
        for (int j=0; j<10;j++){
            glViewport(i * 64, j * 44, 64, 44);
            	drawPolyLineFile("C:\\Users\\Home\\Desktop\\Varsity work hamdan\\Computer Graphics\\Coding Folder\\Lab 3\\Lab 3a Computer Graphics\\dino.dat");
        }
    }
    glFlush();
	glutSwapBuffers();
}

void flipping(){

	for (int i = 0; i < 10; i++) {
		for (int j = 0; j < 10; j++) {
			if ((i + j) % 2 == 0) {
                    setWindow(0, 640, 0, 480);
            }
			else{
                    setWindow(0, 640, 480, 0);
			}
			glViewport(i * 64, j * 44, 64, 44);
			drawPolyLineFile("C:\\Users\\Home\\Desktop\\Varsity work hamdan\\Computer Graphics\\Coding Folder\\Lab 3\\Lab 3b Computer Graphics\\dino.dat");
		}
	}
	glFlush();
	glutSwapBuffers();

}

void myDisplay(void)
{

    glClear(GL_COLOR_BUFFER_BIT);

	//drawPolyLineFile("C:\\Users\\Home\\Desktop\\Varsity work hamdan\\Computer Graphics\\Coding Folder\\Lab 3\\Lab 3a Computer Graphics\\dino.dat");
	//glutSwapBuffers();

    tiling();

    //flipping();

}


int main(int argc, char** argv)
{
    glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);   // set display mode
	glutInitWindowSize(screenWidth, screenHeight); // set window size
	glutInitWindowPosition(10, 10); // set window position on screen
	glutCreateWindow("Dino Line Drawing/Tiling/Flipping"); // open the screen window
	glutDisplayFunc(myDisplay);     // register redraw function
	init();
	glutMainLoop(); 		     // go into a perpetual loop
	return 1;
}


