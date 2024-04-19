
#include <GL/freeglut.h>
#include <stdlib.h>
#include <mmsystem.h>



void init(void){

    glClearColor(0.0f ,0.5f, 1.0f, 0.0);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();                      // BACKGROUND SETUP
    gluOrtho2D(0.0,600.0,0.0,500.0);

}

void mydisplay(void)
{
    glClear(GL_COLOR_BUFFER_BIT);

    glColor3f(0,0.80,0);
    glBegin(GL_QUADS);
        glVertex2i(600.0,300.0);
        glVertex2i(600.0,0.0);         // GRASS AREA CONSTRUCTION
        glVertex2i(100.0,0.0);
        glVertex2i(140.0,100.0);
    glEnd();

    glColor3f(1,1,1);
    glLineWidth(2.0);
    glBegin(GL_LINES);
        glVertex2i(350.0+30.0,120.0);
        glVertex2i(350.0+30.0,150.0);
        glVertex2i(370.0+30.0,120.0);
        glVertex2i(370.0+30.0,150.0);
        glVertex2i(420.0+30.0,120.0);
        glVertex2i(420.0+30.0,150.0);
                                              // 1ST HOME DESIGN
        glVertex2i(350.0+30.0,120.0);
        glVertex2i(370.0+30.0,120.0);
        glVertex2i(370.0+30.0,150.0);
        glVertex2i(420.0+30.0,150.0);

        glVertex2i(350.0+30.0,150.0);    // 1ST HOME GATE DESIGN
        glVertex2i(370.0+30.0,150.0);
        glVertex2i(370.0+30.0,120.0);
        glVertex2i(420.0+30.0,120.0);

        glVertex2i(354.0+30.0,138.0);
        glVertex2i(354.0+30.0,120.0);

        glVertex2i(365.0+30.0,138.0);
        glVertex2i(365.0+30.0,120.0);

        glVertex2i(354.0+30.0,138.0);
        glVertex2i(365.0+30.0,138.0);
    glEnd();


    glColor3f(0.0f, 0.5f, 0.5f);//Blue-Green
    glBegin(GL_TRIANGLES);
        glVertex2i(350.0+30.0,150.0);     // JOIN VERTEX triangle 1ST HOME
        glVertex2i(370.0+20.0,171.0);
        glVertex2i(370.0+30.0,150.0);
    glEnd();


    glColor3f(1,1,1);
    glLineWidth(2.0);
    glBegin(GL_LINES);
        glVertex2i(370.0+20.0,170.0);
        glVertex2i(420.0+30.0,170.0);    // JOIN VERTEX OF 1ST HOME
        glVertex2i(420.0+30.0,170.0);
        glVertex2i(420.0+30.0,120.0);

        glVertex2i(240.0,40.0);
        glVertex2i(240.0,70.0);
        glVertex2i(300.0,40.0);       // 2ND HOME DESIGN
        glVertex2i(300.0,70.0);

        glVertex2i(240.0,40.0);
        glVertex2i(300.0,40.0);       // JOIN VERTEX OF 2ND HOME
        glVertex2i(240.0,70.0);
        glVertex2i(300.0,70.0);

        glVertex2i(263.0,59.0);      // MAKING 2ND HOME GATE
        glVertex2i(263.0,40.0);

        glVertex2i(278.0,59.0);
        glVertex2i(278.0,40.0);

        glVertex2i(263.0,59.0);   // ship pipe work
        glVertex2i(278.0,59.0);

        glVertex2i(267.0,250.0);
        glVertex2i(267.0,265.0);

    glEnd();

         // TREES
    glColor3f(0.1f, 0.0f, 0.0f);
    glBegin(GL_QUADS);
        glVertex2i(560.0,230.0);
        glVertex2i(560.0,270.0);
        glVertex2i(568.0,230.0);
        glVertex2i(568.0,270.0);

        glVertex2i(573.0,230.0);
        glVertex2i(573.0,274.0);
        glVertex2i(578.0,230.0);
        glVertex2i(578.0,274.0);

        glVertex2i(546.0,230.0);
        glVertex2i(546.0,276.0);
        glVertex2i(553.0,230.0);
        glVertex2i(553.0,276.0);
   glEnd();

        // LEAVES OF TREES
   glColor3f(0.0f, 0.50f, 0.0f);//Forest Green
   glBegin(GL_POLYGON);
        glVertex2i(530.0,290.0);
        glVertex2i(590.0,290.0);

        glVertex2i(530.0,275.0);
        glVertex2i(590.0,275.0);
    glEnd();


        // Electric Generator Pole Design
    glLineWidth(6.0);
    glColor3f(1.0f, 1.0f, 1.0f);
    glLineWidth(6.0);
    glBegin(GL_LINES);
        glVertex2i(180.0,120.0);
        glVertex2i(180.0,60.0);
    glEnd();

    glColor3f(0.1f, 0.1f, 0.1f);//Dark Grey
    glLineWidth(6.0);
    glBegin(GL_LINES);
        glVertex2i(180.0,120.0);
        glVertex2i(195.0,133.0);

        glVertex2i(180.0,120.0);
        glVertex2i(165.0,107.0);

        glVertex2i(180.0,120.0);
        glVertex2i(194.0,107.0);

        glVertex2i(180.0,120.0);
        glVertex2i(166.0,133.0);
    glEnd();


   glColor3f(0.0f, 0.5f, 0.5f);
   glBegin(GL_QUADS);
        glVertex2i(232.0,70.0);
        glVertex2i(248.0,85.0);       // MAKING OF HUT OF 2ND HOME

        glVertex2i(295.0,85.0);
        glVertex2i(310.0,70.0);
    glEnd();


    glPointSize(2.0);
    glColor3f(1.0,1.0,1.0);
    glBegin(GL_POINTS);
        glVertex2i(362.0+30.0,127.0);   // DOOR LOCKS 1ST
        glVertex2i(274.0,48.0);        // DOOR LOCKS 2ND
        glVertex2i(180.0,120.0);      // Electric Generator point
    glEnd();


    //  Ship working site
    glLineWidth(2.0);
    glColor4f(0.0f, 1.0f, 1.0f, 1.0f);//light blue
    glBegin(GL_QUADS);
        glVertex2i(240.0,250.0);
        glVertex2i(290.0,250.0);

        glVertex2i(250.0,240.0);
        glVertex2i(280.0,240.0);

        glVertex2i(240.0,250.0);
        glVertex2i(250.0,240.0);

        glVertex2i(290.0,250.0);
        glVertex2i(280.0,240.0);

        glVertex2i(260.0,250.0);
        glVertex2i(260.0,265.0);

        glVertex2i(260.0,265.0);
        glVertex2i(240.0,250.0);

    glEnd();

      // Mountain working site
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


int main(int argc, char *argv[])
{
    glutInit(&argc, argv);
    glutInitWindowSize(640,480);
    glutInitWindowPosition(30,30);
    glutInitDisplayMode(GLUT_RGB | GLUT_SINGLE);
    glutCreateWindow("Lab 2 : Scenery Implementation");

    glutDisplayFunc(mydisplay);
    init();
    sndPlaySound("wav.h",SND_ASYNC);
    glutMainLoop();

    return EXIT_SUCCESS;
}
