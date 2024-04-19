#include <gl/glut.h>
#include <iostream>
#include <math.h>

using namespace std;

class Canvas{
 public:
    float x,y,angle;

    Canvas(){
        this->x = 400;
        this->y = 150;
    }

    void turn(float angle){
        this->angle += angle;
    }

    void turnTo(float angle) {
		this->angle = angle;
	}

    void moveTo(float x,float y){
        this->x = x;
        this->y = y;
    }

    void lineTo(float x,float y){

        glColor3f(0.0,1.0,0.0);
        glLineWidth(3.0);
        glBegin(GL_LINES);
            glVertex2f(this->x,this->y);
            glVertex2f(x,y);
        glEnd();
        glFlush();

        moveTo(x,y);
    }

    void forward(float dist, int isVisible) {
		const float RadPerDeg = 0.017453393;
		float x = this->x + dist * cos(RadPerDeg * this->angle);
		float y = this->y + dist * sin(RadPerDeg * this->angle);
		if (isVisible >= 1 ) {
			lineTo(x, y);
		}
		else {
			moveTo(x, y);
		}
	}
};

Canvas cvs;


void display() {
	glClear(GL_COLOR_BUFFER_BIT);

    float inc = 3.0;
    float l = 70.0;
    string to_par = "FLFLFLFRFLFLFLFRFLFLFLFR";

    for(int j=0;j<12;j++){
        for(int i=0;i<to_par.length();i++){

           if (to_par[i] == 'F') {
                cvs.forward(l,1);
           }
           else if (to_par[i] == 'L'){
                cvs.turn(60);
           }
           else if (to_par[i] == 'R'){
                cvs.turn(-60);
           }
        }
    l+=inc;
    }
    glFlush();
}



int screenWidth = 740;
int screenHeight = 480;

int main(int argc, char** argv){

    glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
	glutInitWindowSize(screenWidth, screenHeight);
	glutInitWindowPosition(100, 100);
	glutCreateWindow("Home Task, Week:08");

	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluOrtho2D(0.0, screenWidth, 0.0, screenHeight);
	glMatrixMode(GL_MODELVIEW);

	glutDisplayFunc(display);

	glutMainLoop();
	return 0;


}












