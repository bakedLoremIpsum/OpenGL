#include<GLUT/glut.h>
#include<unistd.h>
#include<iostream>
#include <time.h>
using namespace std;

int i = 0;

void delay(float secs)
{
    float end = clock()/CLOCKS_PER_SEC + secs;
    while((clock()/CLOCKS_PER_SEC) < end);
}

void idle() {
    glutPostRedisplay();   // Post a re-paint request to activate display()
}

void myInit()
{
    glClearColor(0, 1, 1, 1);
    glPointSize(10);
    gluOrtho2D(-300, 300, -300, 300);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
}

void display(){
    glClear(GL_COLOR_BUFFER_BIT);
    
    glPushMatrix();
    glColor3f(0, 0, 1);
    glBegin(GL_POLYGON);
    glVertex2d(-5, -10);
    glVertex2d(5,-10);
    glVertex2d(25,-150);
    glVertex2d(-25,-150);
    glEnd();
    glPopMatrix();
    
    glPushMatrix();
    glColor3f(0, 0, 0);
    glBegin(GL_POINTS);
    glVertex2d(0, 0);
    glEnd();
    glPopMatrix();
    
    glPushMatrix();
    glColor3f(0, 1, 0);
    glBegin(GL_POLYGON);
    glVertex2d(-300, -150);
    glVertex2d(300,-150);
    glVertex2d(300, -300);
    glVertex2d(-300,-300);
    glEnd();
    glPopMatrix();
    
    glColor3f(1, 0, 0);
    glLineWidth(12);
    if(i%2){
        
        glPushMatrix();
        glBegin(GL_LINES);
        glVertex2d(10,10);
        glVertex2d(100, 100);
        glVertex2d(-10, 10);
        glVertex2d(-100, 100);
        glVertex2d(0, -10);
        glVertex2d(0,-100);
        glEnd();
        glPopMatrix();
    }
    else{
        glPushMatrix();
        glBegin(GL_LINES);
        glVertex2d(10,-10);
        glVertex2d(100, -100);
        glVertex2d(-10, -10);
        glVertex2d(-100, -100);
        glVertex2d(0, 10);
        glVertex2d(0,100);
        glEnd();
        glPopMatrix();
        
    }
    
    glutSwapBuffers();
    //sleep(1);
    delay(1);
    i++;
}
void plot(float x,float y,float xc,float yc){
    x+=xc;
    y+=yc;
    glVertex2d(x, y);
    glVertex2d(x, -y);
    glVertex2d(-x, y);
    glVertex2d(-x, -y);
    glVertex2d(y, x);
    glVertex2d(y, -x);
    glVertex2d(-y, x);
    glVertex2d(-y, x);
    
}


void plotCircle(float xc, float yc, float r)
{
    float p=1-r,x=0,y=r;
    plot(x,y,xc,yc);
    for(int i =0;x<y;i++){
        if(p<0){
            plot(x+1,y,xc,yc);
            x++;
            p=p+2*x+1;
            
        }
        else{
            plot(x+1,y-1,xc,yc);
            x++;
            p+=2*x+3 - 2*y;
            y--;
        }
    }
}

int main(int argc, char ** argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE);
    glutInitWindowSize(600, 600);
    glutCreateWindow("hello");
    glutDisplayFunc(display);
    glutIdleFunc(idle);
    myInit();
    glutMainLoop();
    return 0;
}

