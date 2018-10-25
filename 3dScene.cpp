#include <GLUT/glut.h>
#include<iostream>
#include<math.h>
#include<string.h>
using namespace std;

float tx,ty,tz,a[4][4]={0},px,py,pz,b[4][1]={0},d[4][1];
int i,j,k,c=0;
float x[10]; //= {250,250,250,250,-250,-250};
float y[10]; //= {250,250,-250,-250,-250,-250};
float z[10]; //= {250,-250,-250,250,250,-250};

void init()
{
    //glClearColor(1.0,1.0,1.0,1.0);
    //glColor3f(0.5f,0.5f,0.5f);
    glPointSize(3);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glOrtho(-500,500,-500,500,-500,500); //Setting up the Viewvolume
    glEnable(GL_DEPTH_TEST);
    glEnable(GL_LIGHTING);
    glEnable(GL_LIGHT0);
    glEnable(GL_NORMALIZE);
    glEnable(GL_TEXTURE_2D);
    glEnable(GL_COLOR_MATERIAL);
    
    // Create light components
    GLfloat ambientLight[] = { 1.0, 1.0, 1.0, 1.0 };
    GLfloat diffuseLight[] = { 1.0, 1.0, 1.0, 1.0 };
    GLfloat specularLight[] = { 1.0, 1.0, 1.0, 1.0 };
    GLfloat position[] = { -10.0, 10.0, 0.0, 0.0 };
    glShadeModel(GL_SMOOTH);
    
    // Assign created components to GL_LIGHT0
    glLightfv(GL_LIGHT0, GL_AMBIENT, ambientLight);
    glLightfv(GL_LIGHT0, GL_DIFFUSE, diffuseLight);
    glLightfv(GL_LIGHT0, GL_SPECULAR, specularLight);
    glLightfv(GL_LIGHT0, GL_POSITION, position);
    glLightModelf(GL_LIGHT_MODEL_TWO_SIDE, GL_TRUE);
    
    
    //GLuint tex;
    //glGenTextures(1, &tex);
    //glBindTexture(GL_TEXTURE_2D, tex);
    //glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
    //glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
    //float color[] = { 1.0f, 0.0f, 0.0f, 1.0f };
    //glTexParameterfv(GL_TEXTURE_2D, GL_TEXTURE_BORDER_COLOR, color);
    //glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
    //glGenerateMipmap(GL_TEXTURE_2D);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
    float pixels[] = {
        0.0f, 0.0f, 0.0f,   1.0f, 1.0f, 1.0f,
        1.0f, 1.0f, 1.0f,   0.0f, 0.0f, 0.0f
    };
    glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, 2, 2, 0, GL_RGB, GL_FLOAT, pixels);
}

void dispFace(float x[], float y[], float z[])
{
    glColor3ub(255, 0, 0);
    glBegin(GL_QUADS);
    glNormal3f(-1.0, 0.0, 0.0);
    glTexCoord2f(1, 0);
    glVertex3f(x[0],y[0],z[0]);
    glTexCoord2f(0, 1);
    glVertex3f(x[1],y[1],z[1]);
    glTexCoord2f(1, 0);
    glVertex3f(x[2],y[2],z[2]);
    glTexCoord2f(0, 1);
    glVertex3f(x[3],y[3],z[3]);
    glEnd();
    glFlush();
    
    glColor3ub(0, 255, 0);
    glBegin(GL_QUADS);
    glNormal3f(0.0, -1.0, 0.0);
    glVertex3f(x[2],y[2],z[2]);
    glVertex3f(x[3],y[3],z[3]);
    glVertex3f(x[4],y[4],z[4]);
    glVertex3f(x[5],y[5],z[5]);
    glEnd();
    glFlush();
}
void display()
{
    int opt = 3;
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    //int tx,ty,tz,a[4][4]={0},x[10],y[10],z[10],i,c=0,px,py,pz,b[4][1]={0},d[4][1],j,k;
    
    glBegin(GL_LINES);
    //x-axis
    glColor3ub(255, 0, 0);
    glVertex3f(-300, 0, 0);
    glVertex3f(300, 0, 0);
    //y-axis
    glColor3ub(0, 255, 0);
    glVertex3f(0, -300, 0);
    glVertex3f(0, 300, 0);
    //z-axis
    glColor3ub(0, 0, 255);
    glVertex3f(-0, 0, -300);
    glVertex3f(0, 0, 300);
    glEnd();
    
    glColor3ub(255, 0, 0);
    glRasterPos3d(300, 0, 0);
    glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, 'x');
    
    glColor3ub(0, 255, 0);
    glRasterPos3d(0, 300, 0);
    glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, 'y');
    
    glColor3ub(0, 0, 255);
    glRasterPos3d(0, 0, 300);
    glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, 'z');
    
    //cout<<"enter the translation factor:";
    //cin>>tx>>ty>>tz;
    
    //cout<<"\nROTATION\n1.x-axis\n2.y-axis\n3.z-axis\nEnter option: ";
    //cin>>opt;
    
    x[0]=250;
    y[0]=250;
    z[0]=250;
    
    x[1]=250;
    y[1]=250;
    z[1]=-250;
    
    x[2]=250;
    y[2]=-250;
    z[2]=-250;
    
    x[3]=250;
    y[3]=-250;
    z[3]=250;
    
    x[4]=-250;
    y[4]=-250;
    z[4]=250;
    
    x[5]=-250;
    y[5]=-250;
    z[5]=-250;
    
    glutSolidSphere(100, 50, 50);
    dispFace(x, y, z);
    
    glFlush();
    
    /*for(i=0;i<8;i++)
     {
     cout<<x[i]<<","<<y[i]<<","<<z[i]<<"\n";
     }*/
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

int main(int argc, char **argv)
{
    glutInit(&argc, argv);
    glutInitWindowSize(640,640);
    glutInitDisplayMode(GLUT_RGBA | GLUT_DEPTH | GLUT_SINGLE);
    glutCreateWindow("3D Scene");
    glutDisplayFunc(display);
    glutKeyboardFunc(keyboard);
    init();
    glutMainLoop();
    return 0;
}
