#include <windows.h>
#include <gl/glut.h>
#include <iostream>
#include <math.h>
using namespace std;

const float PI = 3.1415926536;

class GLintPoint
{
public:
	GLint x, y;
};

class Point2
{
public:
	float x, y;

	void set(float dx, float dy)
	{

		x = dx;
		y = dy;
		//cout<<"x---------------"<<x<<endl;
		//cout<<"y---------------"<<y<<endl;
	}

	void set(Point2& p)
	{
		x = p.x;
		y = p.y;
		//cout<<"next outside func x---------"<<x<<endl;
		//cout<<"next outside func y---------"<<y<<endl;
	}

	Point2(float xx, float yy)
	{
		x = xx;
		y = yy;
	}

	Point2()
	{
		x = y = 0;
	}
};

Point2 currPos;
Point2 CP;

void moveTo(Point2 p)
{
	CP.set(p);
}

void lineTo(Point2 p)
{
    //cout<<"global value of object-----------"<<CP.x<<"   "<<CP.y<<endl;
	glBegin(GL_LINES);
	glVertex2f(CP.x, CP.y);
	glVertex2f(p.x, p.y);
	//cout<<"global value of object-----------"<<p.x<<"   "<<p.y<<endl;
	glEnd();
	glFlush();
	CP.set(p);
}

void myInit(void)
{
	glClear(GL_COLOR_BUFFER_BIT);
	glColor3f(0, 0, 1);
}

void rosette(int N, float radius)
{   int a;
	Point2* pointlist = new Point2[N];
	GLfloat theta = (2 * PI) / N;
	//cout<<"theta-----------"<<theta<<endl;

	for (int c = 0; c < N; c++)
	{
		pointlist[c].set(radius * sin(theta * c), radius * cos(theta * c));
	}
	//cout<<"first input: ";
	//cin>>a;
	for (int i = 0; i < N; i++)
	{
        //cout<<"LOOP STARTS--------"<<endl;
		for (int j = 0; j < N; j++)
		{
			moveTo(pointlist[i]);
			lineTo(pointlist[j]);
			//cout<<"second input: ";
			//cin>>a;
		}
		//cout<<"LOOP ENDS--------"<<endl;
	}
}

void render()
{
	glClear(GL_COLOR_BUFFER_BIT);
	glClearColor(0.1f ,0.0f, 0.0f, 0.0);
	glViewport(10, 10, 480,480);
	rosette(8, 0.66f);
}

int main(int argc, char** argv)
{
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glutInitWindowSize(640, 480);
	glutCreateWindow("Rosette");
	glutDisplayFunc(render);
	myInit();
	glutMainLoop();
	return 0;
}
