
#include <GL/glut.h>
#include <math.h>

int currentShape = 0;


const int sides = 5;
const float PI = 3.14159265;

void drawPentagon(float centerX, float centerY, float radius) {
    glBegin(GL_POLYGON);
    for (int i = 0; i < sides; ++i) {
        float angle = 2 * PI * i / sides;
        float x = centerX + radius * cos(angle);
        float y = centerY + radius * sin(angle);
        glVertex2f(x, y);
    }
    glEnd();
    glFlush();
}



void display() {
    glClear(GL_COLOR_BUFFER_BIT);

    glColor3f(1.0, 1.0, 1.0);  // Set color to white

    if (currentShape == 0) {
        glBegin(GL_LINES);
        glVertex2f(-0.5, -0.5);
        glVertex2f(0.5, 0.5);
        glEnd();
    } else if (currentShape == 1) {
        glBegin(GL_TRIANGLES);
        glVertex2f(-0.5, -0.5);
        glVertex2f(0.5, -0.5);
        glVertex2f(0.0, 0.5);
        glEnd();
    } else if (currentShape == 2) {
        glBegin(GL_QUADS);
        glVertex2f(-0.5, -0.5);
        glVertex2f(0.5, -0.5);
        glVertex2f(0.5, 0.5);
        glVertex2f(-0.5, 0.5);
        glEnd();
    } else if (currentShape == 3){
        drawPentagon(0.0, 0.0, 0.5);
    }

    glFlush();
}

void menu(int option) {
    currentShape = option;
    glutPostRedisplay();
}

int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(400, 400);
    glutCreateWindow("Basic Drawing Shapes Menu");

    glClearColor(0.0, 0.0, 1.0, 0.0);  // Set clear color to black

    glutDisplayFunc(display);

    glutCreateMenu(menu);
    glutAddMenuEntry("Line", 0);
    glutAddMenuEntry("Triangle", 1);
    glutAddMenuEntry("Square", 2);
    glutAddMenuEntry("Pentagon", 3);
    glutAttachMenu(GLUT_RIGHT_BUTTON);

    glutMainLoop();

    return 0;
}

