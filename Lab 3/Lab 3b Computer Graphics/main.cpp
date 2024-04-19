#include <GL/glut.h>
#include <fstream>
#include <iostream>
#include <vector>
#include <fstream>
using namespace std;
std::vector<std::vector<float> > vertices;
std::vector<std::vector<int> > faces;

float zoom = 1.0f;
float rotationX = 0.0f;
float rotationY = 0.0f;

void drawPolyLineFile(const char* fileName)
{
	std::fstream inStream;

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


void display() {

    glClear(GL_COLOR_BUFFER_BIT);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    glTranslatef(0.0f, 0.0f, -3.0f);
    glScalef(zoom, zoom, zoom);
    glRotatef(rotationX, 1.0f, 0.0f, 0.0f);
    glRotatef(rotationY, 0.0f, 1.0f, 0.0f);

    glColor3f(1.0, 1.0, 1.0);  // Set color to white
    drawPolyLineFile("C:\\Users\\Home\\Desktop\\Varsity work hamdan\\Computer Graphics\\Coding Folder\\Lab 3\\Lab 3b Computer Graphics\\dino.dat");

    glutSwapBuffers();
}

void reshape(int width, int height) {
    glViewport(0, 0, width, height);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluPerspective(45.0, (double)width / (double)height, 0.1, 100.0);
    glMatrixMode(GL_MODELVIEW);
}

void specialKeys(int key, int x, int y) {
    switch (key) {
        case GLUT_KEY_UP:
            rotationX -= 5;
            break;
        case GLUT_KEY_DOWN:
            rotationX += 5;
            break;
        case GLUT_KEY_LEFT:
            rotationY -= 5;
            break;
        case GLUT_KEY_RIGHT:
            rotationY += 5;
            break;
    }
    glutPostRedisplay();
}

void mouseWheel(int wheel, int direction, int x, int y) {
    if (direction == 1) {
        zoom *= 1.1f;
    } else {
        zoom /= 1.1f;
    }
    glutPostRedisplay();
}

int main(int argc, char** argv) {


    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
    glutInitWindowSize(800, 600);
    glutCreateWindow("Dinosaur Zoom in out ");


    glClearColor(0.0, 0.0, 0.0, 1.0);  // Set clear color to black
    glEnable(GL_DEPTH_TEST);
    glutDisplayFunc(display);
    glutReshapeFunc(reshape);
    glutSpecialFunc(specialKeys);
    glutMouseFunc(mouseWheel);

    glutMainLoop();

    return 0;
}
