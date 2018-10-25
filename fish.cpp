#include<GLUT/glut.h>
#include<unistd.h>
#include<time.h>

float i = 0;
int flag = 0;

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
    glClearColor(0,1,1,0);
    glPointSize(10);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(-300,300,-300,300);
}

void display()
{
    glClear(GL_COLOR_BUFFER_BIT);
    
    if (i == 400)
    {
        i = 0;
        flag = (flag+1)%2;
    }
    if(!flag)
    {
        //fish body
        glPushMatrix();
        glColor3f(1.0f,0.5f,0.0f);
        glBegin(GL_POLYGON);
        glVertex2d(-250+i,0); //This also works
        glVertex2d(-200+i,180);
        glVertex2d(-150+i,0);
        glVertex2d(-200+i,-180);
        glEnd();
        glPopMatrix();
        
        //fish tail
        glPushMatrix();
        glTranslated(+i, 0, 0); //This also works
        glColor3f(2.0f,0.5f,1.0f);
        glBegin(GL_TRIANGLES);
        glVertex2d(-250,0);
        glVertex2d(-270,120);
        glVertex2d(-270,-120);
        glEnd();
        glPopMatrix();
        
        //fish eyes
        glPushMatrix();
        glColor3f(1.0f,1.0f,1.0f);
        glBegin(GL_POLYGON);
        glVertex2d(-160+i,0);
        glVertex2d(-155+i,0);
        glVertex2d(-155+i,5);
        glVertex2d(-160+i,5);
        glEnd();
        glPopMatrix();
        
        //bubbles
        glPushMatrix();
        glColor3f(0.0,0.5,1.0);
        glBegin(GL_POLYGON);
        glVertex2d(-160+i,175);
        glVertex2d(-155+i,180);
        glVertex2d(-160+i,185);
        glVertex2d(-159+i,180);
        glEnd();
        glPopMatrix();
        
        glPushMatrix();
        glColor3f(0.0,0.5,1.0);
        glBegin(GL_POLYGON);
        glVertex2d(-160+i,245);
        glVertex2d(-155+i,250);
        glVertex2d(-160+i,255);
        glVertex2d(-159+i,250);
        glEnd();
        glPopMatrix();
    }

    else
    {
        //fish body
        glPushMatrix();
        glColor3f(1.0f,0.5f,0.0f);
        glBegin(GL_POLYGON);
        glVertex2d(150-i,0);
        glVertex2d(200-i,180);
        glVertex2d(250-i,0);
        glVertex2d(200-i,-180);
        glEnd();
        glPopMatrix();
     
        //fish tail
        glPushMatrix();
        glTranslated(-i, 0, 0);
        glColor3f(2.0f,0.5f,1.0f);
        glBegin(GL_TRIANGLES);
        glVertex2d(250,0);
        glVertex2d(270,120);
        glVertex2d(270,-120);
        glEnd();
        glPopMatrix();
     
        //fish eyes
        glPushMatrix();
        glColor3f(1.0f,1.0f,1.0f);
        glBegin(GL_POLYGON);
        glVertex2d(160-i,0);
        glVertex2d(165-i,0);
        glVertex2d(165-i,5);
        glVertex2d(160-i,5);
        glEnd();
        glPopMatrix();
     
        //bubbles
        glPushMatrix();
        glColor3f(0.0,0.5,1.0);
        glBegin(GL_POLYGON);
        glVertex2d(155-i,175);
        glVertex2d(160-i,180);
        glVertex2d(155-i,185);
        glVertex2d(151-i,180);
        glEnd();
        glPopMatrix();
     
        glPushMatrix();
        glColor3f(0.0,0.5,1.0);
        glBegin(GL_POLYGON);
        glVertex2d(155-i,245);
        glVertex2d(160-i,250);
        glVertex2d(155-i,255);
        glVertex2d(151-i,250);
        glEnd();
        glPopMatrix();
    }
    
    glutSwapBuffers();
    //delay(1);
    i += 0.5;
}


int main(int argc, char ** argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(600, 600);
    glutCreateWindow("fish");
    glutDisplayFunc(display);
    glutIdleFunc(idle);
    myInit();
    glutMainLoop();
    return 1;
}
