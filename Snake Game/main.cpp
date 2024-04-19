
#include <iostream>
#include <gl/glut.h>

using namespace std;

int s_widht = 640;
int s_height = 480;
int length_snake = 4;

enum Direction {STOP=0,UP,DOWN,LEFT,RIGHT} dir;

bool gameover = false;
int score = 0;
bool foodcheck = false;


int snake_x[20] = {300,300,300,300};
int snake_y[20] = {200,190,180,170};

int food_x = rand() % s_widht;
int food_y = rand() % s_height;


void draw_snake(){

    for (int i=length_snake-1;i>0;i--){
        snake_x[i] =  snake_x[i-1];
        snake_y[i] =  snake_y[i-1];
    }

    if (dir == UP){
          snake_y[0]++;
          for (int i=1;i<length_snake-1;i++){
              snake_y[i] +=10;
          }
    }
    else if (dir == DOWN){
          snake_y[0]--;
          for (int i=1;i<length_snake-1;i++){
              snake_y[i] +=10;
          }
	 }
     else if(dir == LEFT){
        snake_x[0]--;
        for (int i=1;i<length_snake-1;i++){
              snake_x[i] +=10;
          }
     }
     else if(dir == RIGHT){
          snake_x[0]++;
           for (int i=1;i<length_snake-1;i++){
              snake_x[i] +=10;
          }
     }


	for (int i=0;i<length_snake;i++){
        if (i == 0){
            glColor3f(0.0,0.0,0.0);
        }
        else{
            glColor3f(0.0,0.0,1.0);
        }
        glRectd(snake_x[i],snake_y[i],snake_x[i]+10,snake_y[i]+10);

	}

    if (snake_x[0] >= s_widht-1 || snake_x[0] <= 1){
        gameover = true;
    }
    else if(snake_x[0] >= s_widht-1 || snake_y[0] <= 1){
        gameover = true;
    }

    if (snake_x[0] == food_x && snake_y[0] == food_y){
        foodcheck = true;
        score ++;
        length_snake++;
    }
    else if (snake_x[0] == food_x-0.5 && snake_y[0] == food_y-0.5){
        foodcheck = true;
        score ++;
        length_snake++;
    }

}


void myKB_Handler_callback(int key, int mx, int my){
    switch(key)
	{
	  case GLUT_KEY_UP:
		  dir = UP;
		  break;

	  case GLUT_KEY_DOWN:
		  dir = DOWN;
		  break;

      case GLUT_KEY_RIGHT:
		  dir = RIGHT;
		  break;

      case GLUT_KEY_LEFT:
		  dir = LEFT;
		  break;

      default:
        break;
	}
}

void food(){

    if (foodcheck){
        food_x = rand() % s_widht;
        food_y = rand() % s_height;
    }
    foodcheck = false;
    glColor3f(1.0,1.0,0.0);
    glRectd(food_x,food_y,food_x+10,food_y+10);

}


void timer_callback(int a){
    if (gameover){
        char _score[10];
        itoa(score,_score,10);
        char text[50] = "Your Score: ";
        strcat(text,_score);
        MessageBox(NULL,text,"Game Over", score);
        exit(0);
     }
     else{
        glutPostRedisplay();
        glutTimerFunc(0,timer_callback,0);
    }
}

void display_callback(){

	 glClear(GL_COLOR_BUFFER_BIT);
     food();
     draw_snake();                                 // main 2
     glutTimerFunc(0,timer_callback,0);
     glutSwapBuffers();
}


void myInit(void)
    {
	  glClearColor(0.5, 1.0, 0.5,1.0);
	  glViewport(0,0,(GLsizei)s_widht,(GLsizei)s_height);
	  glMatrixMode(GL_PROJECTION);
	  glLoadIdentity();
	  gluOrtho2D(0,(GLdouble)s_widht ,0 ,(GLdouble)s_height);
	  glMatrixMode(GL_MODELVIEW);
	}

void reshape_callback(int w, int h){

      glViewport(0,0,w,h);
	  glMatrixMode(GL_PROJECTION);
	  glLoadIdentity();
	  gluOrtho2D(0,(GLdouble)s_widht ,0 ,(GLdouble)s_height);
	  glMatrixMode(GL_MODELVIEW);
}

// main driver code down here:~

int main(int argc, char **argv)
{
  glutInit(&argc,argv);
  glutInitDisplayMode(GLUT_SINGLE | GLUT_RGBA | GLUT_DEPTH);
  glutInitWindowSize(s_widht, s_height);
  glutInitWindowPosition(10, 10);
  glutCreateWindow("Snake Game");

  glutDisplayFunc(display_callback);
  glutReshapeFunc(reshape_callback);
  glutSpecialFunc(myKB_Handler_callback);

  myInit();
  glutMainLoop();
}


