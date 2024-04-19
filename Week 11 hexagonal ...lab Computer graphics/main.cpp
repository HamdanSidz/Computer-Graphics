
#include <gl/glut.h>
#include <math.h>



void setWindow(int xs, int xe, int ys, int ye) {
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluOrtho2D((GLint)xs, (GLint)xe, (GLint)ys, (GLint)ye);
}


void tooth0(){
    glBegin(GL_LINE_STRIP);
    glColor3f(0.0,1.0,0.0);
    glVertex2f(0.0,0.0);
    glVertex2f(.2,.2);
    glVertex2f(.6,.2);
    glVertex2f(.6,.8);
    glVertex2f(.2,.8);
    glVertex2f(0.0,1.0);
    glEnd();
}

void tooth1(double r){
    double rad = 6.0*3.1416/180.0,
    sin6 = r*sin(rad), cos6 = r*cos(rad);
    glPushMatrix();
        glTranslatef(cos6,-sin6,0.0);
        glScalef(2.0*sin6,2.0*sin6,1.0);
        tooth0();
    glPopMatrix();

}

void gear(double r){

    setWindow(-15.0, 15.0 ,-15.0, 15.0);

    glPushMatrix();
    for(int i=1; i<31; ++i){
        glPointSize(4.0);
        glBegin(GL_POINTS);
            glVertex2f(0.0,0.0);
        glEnd();
        tooth1(r);
        glRotatef(12.0, 0.0, 0.0, 1.0);
    }
    glPopMatrix();

}

void pushCT(){
    glMatrixMode(GL_MODELVIEW);
    glPushMatrix();
}

void popCT(){
    glMatrixMode(GL_MODELVIEW);
    glPopMatrix();
}


void drawPentagon(float centerX, float centerY, float radius) {
    glBegin(GL_POLYGON);
    int sides = 6;
    for (int i = 0; i < sides; ++i) {
        float angle = 2 * 3.412 * i / sides;
        float x = centerX + radius * cos(angle);
        float y = centerY + radius * sin(angle);
        glVertex2f(x, y);
    }
    glEnd();
    glFlush();
}

// Function to draw a single hexagon
void drawHexagon(float x, float y, float size) {
    glBegin(GL_POLYGON);
    for (int i = 0; i < 6; ++i) {
        float angle = 2.0 * M_PI * i / 6;
        float x_i = x + size * cos(angle);
        float y_i = y + size * sin(angle);
        glVertex2f(x_i, y_i);
    }
    glEnd();
}

void drawHexagonalGrid(int rows, int cols, float hexSize) {

    setWindow(0.0, 5.0, 0.0, 5.0);
    glColor3f(0.0, 1.0, 0.0);

    float yOffset = sqrt(3.20) * hexSize;

    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            float x = j * 1.55 * hexSize;
            float y = i * yOffset;

            if (j % 2 == 1) {
                y += yOffset / 2.0;
            }
            drawHexagon(x, y, hexSize);
        }
    }
}

void tilling_design(double r){

     setWindow(-10.0, 10.0 ,-10.0, 10.0);

     pushCT();
     glTranslated(-8.0,0.0,0.0);

     for(int i = 0 ; i<5 ;i++){
        pushCT();
        for(int j = 0 ; j<6 ;j++){
            tooth0();
            glTranslated(1.0,0.0,0.0);
        }
        popCT();
        glTranslated(0.0,1.0,0.0);
    }
     popCT();
}

void display()
{
    glClear(GL_COLOR_BUFFER_BIT);

    gear(4.0);
    //tilling_design(5.0);

    int rows = 3;
    int cols = 8;
    float hexSize = 0.3;      // Size of each hexagon
    //drawHexagonalGrid(rows, cols, hexSize);

    glutSwapBuffers();
    glFlush();
}


void init()
{
    glClearColor(1.0, 1.0, 1.0, 0.0);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(0.0, 250.0, 0.0, 250.0);

    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
}

int main(int argc, char** argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGBA);
    glutInitWindowPosition(50, 50);
    glutInitWindowSize(500, 500);
    glutCreateWindow("Week 11");
    init();
    glutDisplayFunc(display);

    glutMainLoop();
    return 0;
}
