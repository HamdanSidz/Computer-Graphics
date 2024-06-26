#include <gl/glut.h>
#include <iostream>
#include <math.h>

using namespace std;

int screenWidth = 740;
int screenHeight = 480;

class Canvas {
public:
	float x, y;
	float angle;
	Canvas() {
		this->x = 150;
		this->y = 200;
	}
	void turnTo(float angle) {
		this->angle = angle;
	}
	void turn(float angle) {
		this->angle += angle;
	}
	void lineTo(float x, float y) {
		float t_x = x; float t_y = y;
		glColor3f(1.0, 0.0, 0.0);
		glLineWidth(2.0);
		glBegin(GL_LINES);
		glVertex2f(this->x, this->y);
		glVertex2f(x, y);
		glEnd();
		glFlush();
		moveTo(t_x, t_y);
	}
	void moveTo(float x, float y) {
		this->x = x;
		this->y = y;

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

float increment = 3;
Canvas cvs;

// Practice Question 3.5.9
void PolySpiral(float dist) {
	if (dist > 200) {
		return;
	}
	cvs.forward(dist, 1);
	cvs.turn(-144);
	dist += increment;
	PolySpiral(dist + increment);
}

void display() {
	glClear(GL_COLOR_BUFFER_BIT);

	// 3.5.1 a Drawing Turtle
        float L = 50.0;

        cvs.forward(L/2, 1);
        cvs.turn(90);
        cvs.forward(L/2, 1);
        cvs.turn(90);
        cvs.forward(L/2, 1);
        cvs.turn(90);
        cvs.forward(L/2, 1);

        cvs.turn(90);
        cvs.forward(L+5, 1);
        cvs.turnTo(90);
        cvs.forward(L+5, 1);
        cvs.turn(90);
        cvs.forward(L+5, 1);
        cvs.turn(90);
        cvs.forward(L+5, 1);

        cvs.turn(90);
        cvs.forward(L+40, 1);
        cvs.turnTo(90);
        cvs.forward(L+40, 1);
        cvs.turn(90);
        cvs.forward(L+40, 1);
        cvs.turn(90);
        cvs.forward(L+40, 1);

        cvs.turn(90);
        cvs.forward(L+75, 1);
        cvs.turnTo(90);
        cvs.forward(L+75, 1);
        cvs.turn(90);
        cvs.forward(L+75, 1);
        cvs.turn(90);
        cvs.forward(L+75, 1);



/*
        // 3.5.1 b Drawing Turtle

        float L = 120.0;

        cvs.forward(L, 1);
        cvs.turn(90);
        cvs.forward(L, 1);
        cvs.turn(90);
        cvs.forward(L, 1);

        cvs.turn(90);
        cvs.forward(L-20, 1);
        cvs.turn(90);
        cvs.forward(L-20, 1);

        cvs.turnTo(90);
        cvs.forward(L-40, 1);
        cvs.turn(90);
        cvs.forward(L-40, 1);
        cvs.turn(90);
        cvs.forward(L-60, 1);
        cvs.turn(90);
        cvs.forward(L-60, 1);

        cvs.turnTo(90);
        cvs.forward(L-80, 1);
        cvs.turn(90);
        cvs.forward(L-80, 1);
        cvs.turn(90);
        cvs.forward(L-100, 1);
        cvs.turn(90);
        cvs.forward(L-100, 1);


        cvs.turnTo(90);
        cvs.forward(L-110, 1);
        cvs.turn(90);
        cvs.forward(L-110, 1);

*/


 /*       // 3.5.1 c Drawing Turtle

        float L = 120.0;
        cvs.forward(L, 1);
        cvs.turnTo(120);
        cvs.forward(L, 1);
        cvs.turnTo(240);
        cvs.forward(L-60, 1);

        cvs.turnTo(360);
        cvs.forward(L-60, 1);

        cvs.turnTo(240);
        cvs.forward(L-60, 1);

        cvs.turnTo(120);
        cvs.forward(L-60, 1);

        cvs.turnTo(240);
        cvs.forward(L-60, 1);

*/

/*
    //3.5.2 Mistirbushi Logo Outline

    float L = 70.0;

    cvs.turnTo(50);
    cvs.forward(L, 1);

    cvs.turnTo(310);
    cvs.forward(L, 1);

    cvs.turnTo(360);
    cvs.forward(L, 1);

     cvs.turnTo(130);
     cvs.forward(L, 1);

     cvs.turnTo(180);
     cvs.forward(L+70, 1);

     cvs.turnTo(230);
     cvs.forward(L, 1);

     cvs.turnTo(360);
     cvs.forward(L, 1);

    cvs.turnTo(50);
    cvs.forward(L, 1);

    cvs.turnTo(60);
    cvs.forward(L, 1);

    cvs.turnTo(120);
    cvs.forward(L, 1);

    cvs.turnTo(240);
    cvs.forward(L, 1);

    cvs.turnTo(300);
    cvs.forward(L, 1);

*/

/*
    //3.5.3 Driving Trutle with string

    string to_par = "FLFLFLFRFLFLFLFRFLFLFLFR";

    for(int i=0;i<to_par.length();i++){

       if (to_par[i] == 'F') {
            cvs.forward(70.0,1);
       }
       else if (to_par[i] == 'L'){
            cvs.turn(60);
       }
       else if (to_par[i] == 'R'){
            cvs.turn(-60);
       }
    }

*/

/*
    // 3.5.4 Drawing Meanders

    int L = 50;
    for (int i = 0 ; i < 8; i++){
     cvs.turnTo(360);
     cvs.forward(L, 1);
     cvs.turnTo(90);
     cvs.forward(L-20, 1);
     cvs.turnTo(180);
     cvs.forward(L-30, 1);
     cvs.turnTo(270);
     cvs.forward(L-35, 1);
     cvs.turnTo(180);
     cvs.forward(L-35, 1);
     cvs.turnTo(90);
     cvs.forward(L-25, 1);
     cvs.turnTo(360);
     cvs.forward(L+2, 1);
     cvs.turnTo(270);
     cvs.forward(L-10, 1);

    }

*/



/*
    // 3.5.5 Classes of Meanders
    // part a
    float L = 70.0;
	for (int i = 0; i < 3; i++) {
		cvs.forward(L, 1);
		cvs.turn(90);
		cvs.forward(L - 20, 1);
		cvs.turn(90);
		cvs.forward(L / 2,1);
		cvs.turn(270);
		cvs.forward(L/2, 1);
		cvs.turn(270);
		cvs.forward(L + 20, 1);
		cvs.turn(270);
		cvs.forward(L / 2, 1);
		cvs.turn(270);
		cvs.forward(L / 2, 1);
		cvs.turn(90);
		cvs.forward(L - 20, 1);
		cvs.turn(90);
		cvs.forward(L, 1);
	}
*/

/*
	// 3.5.5 part b
	float L = 70.0;
	for (int i = 0; i < 3; i++) {
		cvs.forward(L, 1);
		cvs.turn(90);
		cvs.forward(L - 20, 1);
		cvs.turn(90);
		cvs.forward(L / 2, 1);
		cvs.turn(270);
        cvs.forward(L / 2, 1);
		cvs.turn(270);
		cvs.forward(L-20, 1);
		cvs.turn(270);
		cvs.forward(15, 1);
		cvs.turn(90);
		cvs.forward(25, 1);
		cvs.turn(90);
		cvs.forward(15, 1);
		cvs.turn(270);
		cvs.forward(L - 20, 1);
        cvs.turn(270);
        cvs.forward(L / 2, 1);
		cvs.turn(270);
		cvs.forward(L / 2, 1);
		cvs.turn(90);
		cvs.forward(L - 20, 1);
		cvs.turn(90);
		cvs.forward(L, 1);
	}
*/

/*
	// 3.5.6  Drawing Elaborate Meanders.
    float L = 80.0;
	bool limitReached = false;
	for (int i = 0; i < 24; i++) {
		if (!limitReached && L == 0) {
			L = 10;
			cvs.forward(L, 1);
			cvs.turn(-90);
			limitReached = true;
		}
		if (!limitReached && L >= 10) {
			cout << i << L << endl;
			cvs.forward(L, 1);
			cvs.turn(90);
			cout << "curr-angle:" << cvs.angle << endl;
			L -= 10;
		}
		if (limitReached && L <= 80 + 10) {
			cout << i << L << endl;
			cvs.forward(L, 1);
			cvs.turn(-90);
			L += 10;
		}
	}
*/

/*
	// 3.5.8 : Is a Polyspiral an IFS ? (example 3.5.3)
	float L = 80.0;
	for (int i = 0; i < 50; i++) {
		cvs.forward(L, 1);
		cvs.turn(144);
		L += increment;
	}

*/

/*
	// 3.5.9  Recursive form for Polyspiral()
	float L = 80.0;
	PolySpiral(L);
*/

	glFlush();
}

int main(int argc, char** argv) {
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
	glutInitWindowSize(screenWidth, screenHeight);
	glutInitWindowPosition(100, 100);
	glutCreateWindow("Week 5: 3.5.1 ~ 3.5.9");

	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluOrtho2D(0.0, screenWidth, 0.0, screenHeight);
	glMatrixMode(GL_MODELVIEW);

	glutDisplayFunc(display);

	glutMainLoop();
	return 0;
}
