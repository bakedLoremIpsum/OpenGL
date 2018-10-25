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
    glClearColor(1,1,1,0);
    glPointSize(10);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(-300,300,-300,300);
}

void display()
{
    if(i == 361)
    {
        i = 0;
    }
    glClear(GL_COLOR_BUFFER_BIT);
    glPushMatrix();
    glColor3f(1, 0, 0);
    //glTranslatef(-50, -50, 0);
    glRotatef(i, 0, 0, 1);
    //glTranslatef(50, 50, 0);
    glBegin(GL_LINES);
    glVertex2d(100, 100);
    glVertex2d(0, 0);
    glEnd();
    glPopMatrix();
    i++;
    //delay(1);
    sleep(1);
    
    glutSwapBuffers();
}


int main(int argc, char ** argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(600, 600);
    glutCreateWindow("clock");
    glutDisplayFunc(display);
    glutIdleFunc(idle);
    myInit();
    //for (int i=0; i<100; i++) {
        glutMainLoop();

    //}
    return 1;
}
