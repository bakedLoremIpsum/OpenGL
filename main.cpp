//
//  main.cpp
//  model
//
//  Created by examb64 on 10/10/18.
//  Copyright © 2018 examb64. All rights reserved.
//

#include<GLUT/glut.h>
#include<iostream>
using namespace std;

int x = 0, y = 0, p = 0;
void myInit()
{
    glClearColor(0, 0, 0, 0);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(-300, 300, -300, 300);
}

void plot(int xc, int yc, int x, int y)
{
    glBegin(GL_POINTS);
    glVertex2d(x+xc, y+yc);
    glEnd();
}
void circle(int xc, int yc, int r, int flag)
{
    x = 0;
    y = r;
    p = 5/4 - r;
    plot(xc,yc,x,y);
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
        if(flag == 1)
        {
            plot(xc, yc, x, y);
            plot(xc, yc, y, x);
        }
        if(flag == 2)
        {
            plot(xc, yc, x, -y);
            plot(xc, yc, y, -x);
        }
        if(flag == 3)
        {
            plot(xc, yc, -x, -y);
            plot(xc, yc, -y, -x);
        }
        if(flag == 4)
        {
            plot(xc, yc, -x, y);
            plot(xc, yc, -y, x);
        }
    }
}

void display()
{
    glClear(GL_COLOR_BUFFER_BIT);
    circle(0, 40, 10, 1);
    circle(0, 40, 10, 2);
    circle(0, 40, 10, 3);
    circle(0, 40, 10, 4);
    
    circle(-90, 40, 100, 2);
    
    circle(-10, -60, 77, 4);
    circle(-10, -60, 77, 1);
    
    //circle(70, 40, 100, 3);
    circle(70, 80, 140, 3);
    
    circle(0, 80, 70, 4);
    circle(0, 80, 70, 1);
    glFlush();
}

int main(int argc, char * argv[])
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_RGB | GLUT_SINGLE);
    glutInitWindowSize(600,600);
    glutCreateWindow("model");
    glutDisplayFunc(display);
    myInit();
    glutMainLoop();
    return 0;
}
