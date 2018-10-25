#include <GL/glut.h>
#include <stdio.h>
#include <time.h>

int x1, y1, x2, y2,i=0;
int pntX1, pntY1, r;
void myInit() {
    glClear(GL_COLOR_BUFFER_BIT);
    glClearColor(0.0, 0.0, 0.0, 1.0);
    glMatrixMode(GL_PROJECTION);
    gluOrtho2D(0, 500, 0, 500);
}

void draw_pixel(int x, int y) {
    glBegin(GL_POINTS);
    glVertex2i(x, y);
    glEnd();
}

void draw_line(int x1, int x2, int y1, int y2)
{
    int dx,dy,p=-1,flag=0;
    int tempx=x1,tempy=y1;
    dx=x2-x1;
    dy=y2-y1;
    draw_pixel(tempx,tempy);
    while(tempx<=x2)
    {
        if(dx>=dy)
        {
            if(flag==0)
            {
                flag=1;
                p=2*dy-dx;
            }
            else if(flag==1)
            {
                if(p<0)
                {
                    p=p+(2*dy);
                    draw_pixel(tempx++,tempy);
                }
                if(p>=0)
                {
                    p=p+(2*dy-2*dx);
                    draw_pixel(tempx++,tempy++);
                }
            }
        }
    }
}
void idle()
{
	glutPostRedisplay();
}
void delay(float secs)
{
	float end=clock()/CLOCKS_PER_SEC +secs;
	while((clock()/CLOCKS_PER_SEC) < end);
}
void plot(int x, int y)
{
	glBegin(GL_POINTS);
	glVertex2i(x+pntX1, y+pntY1);
	glEnd();
}
void midPointCircleAlgo()
{
	int x = 0;
	int y = r;
	float decision = 5/4 - r;
	plot(x, y);

	while (y > x)
	{
		if (decision < 0)
		{
			x++; 
			decision += 2*x+1;
		}
		else
		{
			y--;
			x++;
			decision += 2*(x-y)+1;
		}
		plot(x, y);
		plot(x, -y);
		plot(-x, y);
		plot(-x, -y);
		plot(y, x);
		plot(-y, x);
		plot(y, -x);
		plot(-y, -x);
	}

}
void myDisplay() {
    //draw_line(20, 100, 20, 100);
    //draw_line(180, 100, 20,100);
    glClear(GL_COLOR_BUFFER_BIT);
    if(i==50)
    {
		exit(0);
	}
	//Bucket
    glBegin(GL_LINES);
    glPushMatrix();
    glColor3f(1,1,1);
	glVertex2d(20,80);
    glVertex2d(20,20);
    glVertex2d(20,20);
    glVertex2d(80,20);
    glVertex2d(80,20);
    glVertex2d(80,80);
    glPopMatrix();
    glEnd();
    //Water
    glBegin(GL_QUADS);
    glPushMatrix();
    glColor3f(0,0,1);
    glVertex2d(20,30+i);
    glVertex2d(20,20);
    glVertex2d(79,20);
    glVertex2d(79,30+i);
    glPopMatrix();
    glEnd();
    //Tap1
    glPushMatrix();
    glTranslated(20,0,0);
    glBegin(GL_QUADS);
	glColor3f(1,0,0);
    glVertex2d(40,150);
    glVertex2d(40,140);
    glVertex2d(60,140);
    glVertex2d(60,150);
    glTranslated(0,0,0);
    glEnd();
    glPopMatrix();
    //Tap2:
    glPushMatrix();
    glTranslated(20,0,0);
    glBegin(GL_QUADS);
	glColor3f(1,0,0);
    glVertex2d(50,130);
    glVertex2d(100,130);
    glVertex2d(100,140);
    glVertex2d(50,140);
    glEnd();
    glPopMatrix();
    //Tap3:
    glPushMatrix();
    glTranslated(20,0,0);
    glBegin(GL_QUADS);
	glColor3f(1,0,0);
    glVertex2d(30,120);
    glVertex2d(50,120);
    glVertex2d(50,140);
    glVertex2d(30,140);
    glEnd();
    glPopMatrix();
    if(i%2==0)
    {
		glColor3f(0,0,1);
		pntX1=60;
		pntY1=110;
		r=10;
		midPointCircleAlgo();
	}
	else
	{
		glColor3f(0,0,1);
		pntX1=60;
		pntY1=85;
		r=10;
		midPointCircleAlgo();
	}
    glFlush();
    i++;
    delay(1);
}

int main(int argc, char **argv) {
    
    //printf( "Enter (x1, y1, x2, y2)\n");
    //scanf("%d %d %d %d", &x1, &y1, &x2, &y2);
    
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE|GLUT_RGB);
    glutInitWindowSize(500, 500);
    glutInitWindowPosition(0, 0);
    glutCreateWindow("Bresenham's Line Drawing");
    myInit();
    glutDisplayFunc(myDisplay);
    glutIdleFunc(idle);
    glutMainLoop();
    return 0;
}

