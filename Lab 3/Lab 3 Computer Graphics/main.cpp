
#include <GL/freeglut.h>
#include <stdlib.h>
#include <mmsystem.h>
#include <string>
using namespace std;

int Sw = 600;
int Sh = 480;


void init(void){

    glClearColor(0.0f ,0.5f, 1.0f, 0.0);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();                     // BACKGROUND SETUP
    gluOrtho2D(0.0,600.0,0.0,500.0);

}

void bitmap_output(int x,int y, string s, void* font){


    glColor3f(1.0f,0.0f,0.0f);
    glRasterPos2f(x,y);
    int len = s.size();
    for(int i = 0 ; i<len ; i++ ){
        glutBitmapCharacter(font,s[i]);
    }

}




void mydisplay(void)
{
    glClear(GL_COLOR_BUFFER_BIT);

   glColor4f(0.0f, 1.0f, 1.0f, 1.0f);//light blue
    glLineWidth(0.6f);
    glBegin(GL_QUAD_STRIP);
        glVertex2i(200.0,290.0);
        glVertex2i(400.0,290.0);

        glVertex2i(200.0,200.0);
        glVertex2i(400.0,200.0);

        glVertex2i(400.0,290.0);
        glVertex2i(400.0,200.0);

        glVertex2i(200.0,290.0);
        glVertex2i(200.0,200.0);
    glEnd();


        //bitmap_output(210,240,"this is test string 1",GLUT_BITMAP_TIMES_ROMAN_24);

        bitmap_output(210,240,"this is test string 2",GLUT_BITMAP_HELVETICA_18);

       // bitmap_output(210,240,"this is test string 3",GLUT_BITMAP_9_BY_15);


    glFlush();

}


void myreshape(int w,int h)
{
    Sw = w;
    Sh = h;
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(0.0,(GLdouble)Sw,0.0,(GLdouble)Sh);


    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();

}

void drawdots(int x , int y){
    glColor3f(1.0f, 1.0f, 1.0f);
    glPointSize(5.0);
    glBegin(GL_POINTS);
        glVertex2i(x,y);
    glEnd();
    glFlush();
}

void mymouse(int button,int state,int x,int y){

    if(button == GLUT_LEFT_BUTTON && state == GLUT_DOWN){
        drawdots(x,Sh-y);
    }
    if(button == GLUT_RIGHT_BUTTON && state == GLUT_DOWN){

        glutPostRedisplay();
    }

}


void mousemove(int x,int y){
    glutPostRedisplay();
}


void mykeys(unsigned char keys,int x,int y){

    if (keys == 'm'){
    glColor3f(0.0f, 0.70f, 0.0f);
    glBegin(GL_QUADS);
        glVertex2i(0.0,340.0);
        glVertex2i(0.0,371.0);

        glVertex2i(640.0,340.0);
        glVertex2i(640.0,380.0);
    glEnd();

    glColor3f(0.40f, 0.0f, 0.0f);//Brown
    glBegin(GL_TRIANGLES);
        glVertex2i(640.0,370.0);
        glVertex2i(540.0,420.0);
        glVertex2i(420.0,370.0);

        glVertex2i(450.0,370.0);
        glVertex2i(350.0,420.0);
        glVertex2i(270.0,370.0);

        glVertex2i(300.0,370.0);
        glVertex2i(210.0,420.0);
        glVertex2i(150.0,370.0);

        glVertex2i(190.0,370.0);
        glVertex2i(90.0,425.0);
        glVertex2i(0.0,370.0);
    glEnd();

    glFlush();
    }
    else if (keys == 'l'){
          glClearColor(0.0f ,0.0f, 0.80f, 0.0);
          glFlush();

    }
    else if (keys == 'c'){
        glClear(GL_COLOR_BUFFER_BIT);
        glFlush();
    }

}





int main(int argc, char *argv[])
{
    glutInit(&argc, argv);
    glutInitWindowSize(Sw,Sh);
    glutInitWindowPosition(30,30);
    glutInitDisplayMode(GLUT_RGB | GLUT_SINGLE);
    glutCreateWindow("Lab 3 : Events & Callback Functions");

    glutReshapeFunc(myreshape);
    glutDisplayFunc(mydisplay);
    glutKeyboardFunc(mykeys);
    glutMouseFunc(mymouse);
    glutMotionFunc(mousemove);

    init();
    sndPlaySound("wav.h",SND_ASYNC);
    glutMainLoop();

    return EXIT_SUCCESS;
}
