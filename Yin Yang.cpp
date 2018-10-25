#include<GLUT/glut.h>
#include<iostream>
#include<cmath>
using namespace std;
void myInit() {
    glClearColor(1.0,1.0,1.0,0.0);
    glColor3f(0.0f,0.0f,0.0f);
    glPointSize(1);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(0.0,640.0,0.0,480.0);
    
}
void plot(int x,int y,int xc,int yc)
{
    glBegin(GL_POINTS);
    glVertex2d(x+xc+320, y+yc+240);
    glEnd();
}
void colouring(int xc,int yc,int r,int flag)
{
    if(flag==0)
    {
        glColor3f(0.0f,0.0f,0.0f);
    }
    else
    {
        glColor3f(1.0f,1.0f,1.0f);
    }
    for(int j=0;j<r;j++)
    {
        for(int i=0;i<r;i++)
        {
            if((i*i)+(j*j)<=(r*r))
            {
                glBegin(GL_POINTS);
                glVertex2d(i+320+xc, j+240+yc);
                glVertex2d(-i+320+xc, j+240+yc);
                glVertex2d(-i+320+xc, -j+240+yc);
                glVertex2d(i+320+xc, -j+240+yc);
                glEnd();
            }
        }
    }
}
void colouringleft(int xc,int yc,int r,int flag)
{
    if(flag==0)
    {
        glColor3f(0.0f,0.0f,0.0f);
    }
    else
    {
        glColor3f(1.0f,1.0f,1.0f);
    }
    for(int j=0;j<r;j++)
    {
        for(int i=0;i<r;i++)
        {
            if((i*i)+(j*j)<=(r*r))
            {
                glBegin(GL_POINTS);
                glVertex2d(-i+320+xc, j+240+yc);
                glVertex2d(-i+320+xc, -j+240+yc);
                glEnd();
            }
        }
    }
}
void colouringright(int xc,int yc,int r,int flag)
{
    if(flag==0)
    {
        glColor3f(0.0f,0.0f,0.0f);
    }
    else
    {
        glColor3f(1.0f,1.0f,1.0f);
    }
    for(int j=0;j<r;j++)
    {
        for(int i=0;i<r;i++)
        {
            if((i*i)+(j*j)<=(r*r))
            {
                glBegin(GL_POINTS);
                glVertex2d(i+320+xc, j+240+yc);
                glVertex2d(i+320+xc, -j+240+yc);
                glEnd();
            }
        }
    }
}
void drawcircle(int xc,int yc,int r)
{
    glBegin(GL_LINES);
    glColor3f(0.0, 0.0, 0.0);
    glEnd();
    int x=0;
    int y=r;
    float decision=5/4-r;
    plot(x,y,xc,yc);
    while(y>x)
    {
        if(decision<0)
        {
            decision+=((2*x)+3);
            x++;
        }
        else
        {
            decision+=(2*(x-y)+5);
            y--;
            x++;
        }
        plot(x,y,xc,yc);
        plot(x, -y,xc,yc);
        plot(-x, y,xc,yc);
        plot(-x, -y,xc,yc);
        plot(y, x,xc,yc);
        plot(-y, x,xc,yc);
        plot(y, -x,xc,yc);
        plot(-y, -x,xc,yc);
    }
}
void drawcircle1(int xc,int yc,int r)
{
    glBegin(GL_LINES);
    glColor3f(1.0, 1.0, 1.0);
    glEnd();
    int x=0;
    int y=r;
    float decision=5/4-r;
    plot(x,y,xc,yc);
    while(y>x)
    {
        if(decision<0)
        {
            decision+=((2*x)+3);
            x++;
        }
        else
        {
            decision+=(2*(x-y)+5);
            y--;
            x++;
        }
        plot(x,y,xc,yc);
        plot(x, -y,xc,yc);
        plot(-x, y,xc,yc);
        plot(-x, -y,xc,yc);
        plot(y, x,xc,yc);
        plot(-y, x,xc,yc);
        plot(y, -x,xc,yc);
        plot(-y, -x,xc,yc);
    }
}
void drawLine(float a,float b,float c, float d) {
    glBegin(GL_POINTS);
    float xInc,yInc,x1 = a,x2 = c, y1 = b,y2 = d,dx,dy,steps,k;
    float x,y;
    dx = x2 - x1;
    dy = y2 - y1;
    if( abs(dx) > abs(dy))
        steps = abs(dx);
    else
        steps = abs(dy);
    xInc = dx / steps;
    yInc = dy / steps;
    x = x1;
    y = y1;
    glVertex2d(x+320, y+240);
    for( k = 0; k < steps; k++)
    {
        x = x + xInc;
        y = y + yInc;
        glVertex2d(x+320, y+240);
    }
    glEnd();
    glFlush();
}
void myDisplay() {
    glClear(GL_COLOR_BUFFER_BIT);
    drawcircle(0,0,100);
    drawcircle(0,50,50);
    drawcircle1(0,-50,50);
    drawcircle(0,50,25);
    drawcircle(0,-50,25);
    colouringright(0,0,100,0);
    colouring(0, -50, 50,1);
    colouring(0, -50, 25,0);
    colouringleft(0, 50, 50,0);
    colouring(0, 50, 25,1);
    drawcircle(0,0,100);
    drawLine(100, 100, 200, 200);
    drawLine(-100, 100, -200, 200);
    drawLine(100, -100, 200, -200);
    drawLine(-100, -100, -200, -200);
    glFlush();
}
int main(int argc,char* argv[]) {
    glutInit(&argc,argv);
    glutInitDisplayMode(GLUT_SINGLE|GLUT_RGB);
    glutInitWindowSize(640,480);
    glutCreateWindow("Circle and Line");
    glutDisplayFunc(myDisplay);
    myInit();
    glutMainLoop();
    return 1;
}
