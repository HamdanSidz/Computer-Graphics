#include <windows.h>
#include <gl/glut.h>
#include <iostream>
#include <math.h>
using namespace std;


// Relative Arrow Drawing

class Canvas{

    public:
        int x ;
        int y ;

    Canvas(){
        x=0;
        y=0;
    }
    void moveTo(int a,int b){
        x=a;
        y=b;
    }
    void lineTo(int xx,int yy)
    {
        glLineWidth(3.0f);
        glBegin(GL_LINES);
            glVertex2i(x, y);
            glVertex2i(xx, yy);
        glEnd();

        glFlush();
        moveTo(xx,yy);
    }

};


void myInit(void)
{
	glClear(GL_COLOR_BUFFER_BIT);
	glClearColor(1.0f ,1.0f, 1.0f, 1.0);
	glColor3f(0, 0, 1);
	gluOrtho2D(0.0,600.0,0.0,500.0);

}


void render()
{
    Canvas cav;
    cav.moveTo(270.0,220.0);

	cav.lineTo(300.0,220.0);
	cav.lineTo(300.0,280.0);
	cav.lineTo(330.0,280.0);
	cav.lineTo(290.0,340.0);
	cav.lineTo(240.0,280.0);
	cav.lineTo(270.0,280.0);
	cav.lineTo(270.0,220.0);


}

int main(int argc, char** argv)
{
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glutInitWindowSize(640, 480);
	glutInitWindowPosition(30,30);
	glutCreateWindow("Arrow");
	glutDisplayFunc(render);
	myInit();
	glutMainLoop();
	return 0;
}
