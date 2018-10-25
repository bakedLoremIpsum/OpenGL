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
using namespace std;

int x = 0, y = 0, i = 0;
int p = 0;
int a[10] = {0,50,50,0,0,50,50,0};
int b[10] = {0,0,0,0,50,50,50,50};
int c[10] = {0,0,50,50,0,0,50,50};

void myInit()
{
    glClearColor(0, 0, 0, 0);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glOrtho(-300, 300, -300, 300, -300, 300);
    gluLookAt(150, 150, -150, 0, 0, 0, 0, 1, 0);
    glEnable(GL_DEPTH_TEST);
}

void delay(float secs)
{
    float end = clock()/CLOCKS_PER_SEC + secs;
    while((clock()/CLOCKS_PER_SEC)<end);
}

void idle()
{
    //delay(1);
    glutPostRedisplay();
}

void plot(int xc, int yc, int zc, int x, int y, int k)
{
    glBegin(GL_POINTS);
    glVertex3d(x+xc+k, y+yc, 0+zc);
    glEnd();
}
void circle(int xc, int yc,int zc, int r, int i)
{
    x = 0;
    y = r;
    p = 5/4 - r;
    plot(xc,yc, zc, x, y, i);
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
        plot(xc, yc, zc, x, y, i);
        plot(xc, yc, zc, y, x, i);
        plot(xc, yc, zc, x, -y, i);
        plot(xc, yc, zc, y, -x, i);
        plot(xc, yc, zc, -x, -y, i);
        plot(xc, yc, zc, -y, -x, i);
        plot(xc, yc, zc, -x, y, i);
        plot(xc, yc, zc, -y, x, i);
    }
}

void cuboid(int x[], int y[], int z[], int k)
{
    glBegin(GL_QUADS);
    glColor3d(1, 0, 0);
    glVertex3d(x[0]+k, y[0], z[0]);
    glVertex3d(x[1]+k, y[1], z[1]);
    glVertex3d(x[2]+k, y[2], z[2]);
    glVertex3d(x[3]+k, y[3], z[3]);
    glEnd();
    
    glBegin(GL_QUADS);
    glColor3d(0, 1, 0);
    glVertex3d(x[4]+k, y[4], z[4]);
    glVertex3d(x[5]+k, y[5], z[5]);
    glVertex3d(x[6]+k, y[6], z[6]);
    glVertex3d(x[7]+k, y[7], z[7]);
    glEnd();
    
    glBegin(GL_QUADS);
    glColor3d(0, 0, 1);
    glVertex3d(x[3]+k, y[3], z[3]);
    glVertex3d(x[7]+k, y[7], z[7]);
    glVertex3d(x[6]+k, y[6], z[6]);
    glVertex3d(x[2]+k, y[2], z[2]);
    glEnd();
    
    glBegin(GL_QUADS);
    glColor3d(1, 1, 0);
    glVertex3d(x[2]+k, y[2], z[2]);
    glVertex3d(x[6]+k, y[6], z[6]);
    glVertex3d(x[5]+k, y[5], z[5]);
    glVertex3d(x[1]+k, y[1], z[1]);
    glEnd();
    
    glBegin(GL_QUADS);
    glColor3d(1, 0, 1);
    glVertex3d(x[1]+k, y[1], z[1]);
    glVertex3d(x[5]+k, y[5], z[5]);
    glVertex3d(x[4]+k, y[4], z[3]);
    glVertex3d(x[0]+k, y[0], z[0]);
    glEnd();
    
    glBegin(GL_QUADS);
    glColor3d(0, 1, 1);
    glVertex3d(x[0]+k, y[0], z[0]);
    glVertex3d(x[4]+k, y[4], z[4]);
    glVertex3d(x[7]+k, y[7], z[7]);
    glVertex3d(x[3]+k, y[3], z[3]);
    glEnd();
    
}

void display()
{
    if(i==200)
    {
        i = 0;
    }
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    cuboid(a, b, c, i);//Car body
    
    //tyres
    circle(12, 0, 0, 20, i);
    circle(34, 0, 0, 20, i);
    circle(12, 0, 50, 20, i);
    circle(34, 0, 50, 20, i);
    
    glFlush();
    i++;
}

void keyboard(unsigned char key,int x,int y)
{
    switch(key)
    {
        case 'w':
        case 'W':
            glRotatef(-10.0,1.0,0.0,0.0);
            break;
        case 's':
        case 'S':
            glRotatef(10.0,1.0,0.0,0.0);
            break;
        case 'a':
        case 'A':
            glRotatef(-10.0,0.0,1.0,0.0);
            break;
        case 'd':
        case 'D':
            glRotatef(10.0,0.0,1.0,0.0);
            break;
    }
    display();
}

int main(int argc, char * argv[])
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_RGB | GLUT_SINGLE | GLUT_DEPTH);
    glutInitWindowSize(600,600);
    glutCreateWindow("model");
    glutIdleFunc(idle);
    glutKeyboardFunc(keyboard);
    glutDisplayFunc(display);
    myInit();
    glutMainLoop();
    return 0;
}
