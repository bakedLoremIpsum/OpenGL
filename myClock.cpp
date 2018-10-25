//
//  main.cpp
//  model
//
//  Created by examb64 on 10/10/18.
//  Copyright © 2018 examb64. All rights reserved.
//

#include<GLUT/glut.h>
#include<iostream>
#include<time.h>
#include<math.h>
using namespace std;

int x = 0, y = 0, i = 0, j = 0, k = 0;
int p = 0;

void myInit()
{
    glClearColor(1, 1, 1, 0);
    glColor3d(0, 0, 0);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(-300, 300, -300, 300);
}

void delay(float secs)
{
    float end = clock()/CLOCKS_PER_SEC + secs;
    while((clock()/CLOCKS_PER_SEC)<end);
}

void idle()
{
    delay(1);
    glutPostRedisplay();
}

void plot(int xc, int yc, int x, int y)
{
    glBegin(GL_POINTS);
    glVertex2d(x+xc, y+yc);
    glEnd();
}

void drawLine(int x1, int y1, int x2, int y2) {
    int dx, dy, i, e;
    int incx, incy, inc1, inc2;
    int x,y;
    
    dx = x2-x1;
    dy = y2-y1;
    incx = 1;
    incy = 1;
    
    if (dx < 0)
    {
        dx = -dx;
        incx = -1;
    }
    
    if (dy < 0)
    {
        dy = -dy;
        incy = -1;
    }
    
    x = x1;
    y = y1;
    
    if (dx > dy) {
        plot(0, 0, x, y);
        e = 2 * dy-dx;
        inc1 = 2*(dy-dx);
        inc2 = 2*dy;
        for (i=0; i<dx; i++) {
            if (e >= 0) {
                y += incy;
                e += inc1;
            }
            else
                e += inc2;
            x += incx;
            plot(0, 0, x, y);
        }
        
    }
    else {
        plot(0, 0, x, y);
        e = 2*dx-dy;
        inc1 = 2*(dx-dy);
        inc2 = 2*dx;
        for (i=0; i<dy; i++) {
            if (e >= 0) {
                x += incx;
                e += inc1;
            }
            else
                e += inc2;
            y += incy;
            plot(0, 0, x, y);
        }
    }
}

void circle(int xc, int yc, int r)
{
    x = 0;
    y = r;
    p = 5/4 - r;
    plot(xc,yc, x, y);
    while(y > x)
    {
        if(p < 0)
        {
            x++;
            p += 2*x + 1;
        }
        else
        {
            x++;
            y--;
            p += 2*(x-y) + 1;
        }
        plot(xc, yc, x, y);
        plot(xc, yc, y, x);
        plot(xc, yc, x, -y);
        plot(xc, yc, y, -x);
        plot(xc, yc, -x, -y);
        plot(xc, yc, -y, -x);
        plot(xc, yc, -x, y);
        plot(xc, yc, -y, x);
    }
}

void display()
{
    if(i==360)
    {
        i = 0;
    }
    
    if(j==360)
    {
        j = 0;
    }
    glClear(GL_COLOR_BUFFER_BIT);
    
    //clock frame
    circle(0, 0, 80);
    
    
    //seconds hand
    glPushMatrix();
    glRotated(-i, 0, 0, 1);
    drawLine(0, 0, 0, 80);
    glPopMatrix();
    
    //minute hand
    if((i%359) == 0)
    {
        j+=6;
        glPushMatrix();
        glRotated(-j, 0, 0, 1);
        drawLine(0, 0, 0, 80);
        glPopMatrix();
    }
    else
    {
        glPushMatrix();
        glRotated(-j, 0, 0, 1);
        drawLine(0, 0, 0, 80);
        glPopMatrix();
    }
    
    //hour hand
    if((j%359) == 0)
    {
        k+=30;
        glPushMatrix();
        glRotated(-k, 0, 0, 1);
        drawLine(0, 0, 0, 80);
        glPopMatrix();
    }
    else
    {
        glPushMatrix();
        glRotated(-k, 0, 0, 1);
        drawLine(0, 0, 0, 80);
        glPopMatrix();
    }
    
    glFlush();
    i+=6;
}

int main(int argc, char * argv[])
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_RGB | GLUT_SINGLE);
    glutInitWindowSize(600,600);
    glutCreateWindow("model");
    glutIdleFunc(idle);
    glutDisplayFunc(display);
    myInit();
    glutMainLoop();
    return 0;
}
