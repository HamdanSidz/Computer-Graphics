
#include <GL/freeglut.h>
#include <stdlib.h>
#include <mmsystem.h>

void mydisplay(void)
{


    glClear(GL_COLOR_BUFFER_BIT);
    glFlush();

}


void init(){

    glClearColor(0.39f,0.9f,0.9f,0.0);
    glColor3f(1,0,0);

}

int main(int argc, char *argv[])
{
    glutInit(&argc, argv);
    glutInitWindowSize(640,480);
    glutInitWindowPosition(30,30);
    glutInitDisplayMode(GLUT_RGB | GLUT_SINGLE);

    glutCreateWindow("Lab 1 : Basics");
    glutDisplayFunc(mydisplay);
    init();
    sndPlaySound("wav.h",SND_ASYNC);
    glutMainLoop();

    return EXIT_SUCCESS;
}
