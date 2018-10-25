#include <GLUT/glut.h>
#include<iostream>
#include<math.h>
using namespace std;

float tx,ty,tz,a[4][4]={0},px,py,pz,b[4][1]={0},d[4][1];
int i,j,k,c=0;
float x[10]; //= {0,50,50,0,0,50,50,0};
float y[10]; //= {0,0,0,0,50,50,50,50};
float z[10]; //= {0,0,50,50,0,0,50,50};

void init()
{
    //glClearColor(1.0,1.0,1.0,1.0);
    //glColor3f(0.5f,0.5f,0.5f);
    glPointSize(3);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glOrtho(-500,500,-500,500,-500,500); //Setting up the Viewvolume
    glEnable(GL_DEPTH_TEST);
}

void matrixMul()
{
    for(i=0;i<4;++i)
    {
        for(j=0;j<1;++j)
        {
            d[i][j]=0;
            for(k=0;k<4;++k)
                d[i][j]+=a[i][k]*b[k][j];
        }
    }
}

void rotate(int opt)
{
    for(i=0;i<4;++i)
    {
        a[i][i]=1;
    }
    if(opt == 1)
    {
        a[1][1] = cos(1.0472);//60 degree in radians
        a[1][2] = -sin(1.0472);
        a[2][1] = -a[1][2];
        a[2][2] = a[1][1];
    }
    else if(opt == 2)
    {
        a[0][0] = cos(1.0472);//60 degree in radians
        a[0][2] = -sin(1.0472);
        a[2][0] = -a[0][2];
        a[2][2] = a[0][0];
    }
    
    else if(opt == 3)
    {
        a[0][0] = cos(1.0472);//60 degree in radians
        a[0][1] = -sin(1.0472);
        a[1][0] = -a[0][1];
        a[1][1] = a[0][0];
    }
    
    c = 0;
    while(c<8)
    {
        if(c==0)
        {
            px=x[0];
            py=y[0];
            pz=z[0];
        }
        else if(c==1)
        {
            px=x[1];
            py=y[1];
            pz=z[1];
        }
        if(c==2)
        {
            px=x[2];
            py=y[2];
            pz=z[2];
        }
        if(c==3)
        {
            px=x[3];
            py=y[3];
            pz=z[3];
            
        }
        if(c==4)
        {
            px=x[4];
            py=y[4];
            pz=z[4];
        }
        if(c==5)
        {
            px=x[5];
            py=y[5];
            pz=z[5];
        }
        if(c==6)
        {
            px=x[6];
            py=y[6];
            pz=z[6];
        }
        if(c==7)
        {
            px=x[7];
            py=y[7];
            pz=z[7];
        }
        b[0][0]=px;
        b[1][0]=py;
        b[2][0]=pz;
        b[3][0]=1;
        
        matrixMul();
        
        x[c]=d[0][0];
        y[c]=d[1][0];
        z[c]=d[2][0];
        c++;
    }
}

void dispFace(float x[], float y[], float z[])
{
    glColor3ub(255, 0, 0);
    glBegin(GL_QUADS);//bottom
    glVertex3f(x[0],y[0],z[0]);
    glVertex3f(x[1],y[1],z[1]);
    glVertex3f(x[2],y[2],z[2]);
    glVertex3f(x[3],y[3],z[3]);
    glEnd();
    glFlush();
    
    glColor3ub(0, 255, 0);
    glBegin(GL_QUADS);//top
    glVertex3f(x[4],y[4],z[4]);
    glVertex3f(x[5],y[5],z[5]);
    glVertex3f(x[6],y[6],z[6]);
    glVertex3f(x[7],y[7],z[7]);
    glEnd();
    glFlush();
    
    glColor3ub(0, 0, 255);
    glBegin(GL_QUADS);//front
    glVertex3f(x[3],y[3],z[3]);
    glVertex3f(x[7],y[7],z[7]);
    glVertex3f(x[6],y[6],z[6]);
    glVertex3f(x[2],y[2],z[2]);
    glEnd();
    glFlush();
    
    glColor3ub(255, 255, 0);
    glBegin(GL_QUADS);//right
    glVertex3f(x[2],y[2],z[2]);
    glVertex3f(x[1],y[1],z[1]);
    glVertex3f(x[5],y[5],z[5]);
    glVertex3f(x[6],y[6],z[6]);
    glEnd();
    glFlush();
    
    glColor3ub(0, 255, 255);
    glBegin(GL_QUADS);//back
    glVertex3f(x[0],y[0],z[0]);
    glVertex3f(x[1],y[1],z[1]);
    glVertex3f(x[5],y[5],z[5]);
    glVertex3f(x[4],y[4],z[4]);
    glEnd();
    glFlush();
    
    glColor3ub(255, 0, 255);
    glBegin(GL_QUADS);//left
    glVertex3f(x[0],y[0],z[0]);
    glVertex3f(x[3],y[3],z[3]);
    glVertex3f(x[7],y[7],z[7]);
    glVertex3f(x[4],y[4],z[4]);
    glEnd();
    glFlush();
}
void display()
{
    int opt = 1;
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
    
    x[0]=50;
    y[0]=50;
    z[0]=50;
    
    x[1]=100;
    y[1]=50;
    z[1]=50;
    
    x[2]=100;
    y[2]=50;
    z[2]=100;
    
    x[3]=50;
    y[3]=50;
    z[3]=100;
    
    x[4]=50;
    y[4]=100;
    z[4]=50;
    
    x[5]=100;
    y[5]=100;
    z[5]=50;
    
    x[6]=100;
    y[6]=100;
    z[6]=100;
    
    x[7]=50;
    y[7]=100;
    z[7]=100;
    
    dispFace(x, y, z);
    
    rotate(opt);
    
    dispFace(x, y, z);
    
    for(i=0;i<8;i++)
    {
        cout<<x[i]<<","<<y[i]<<","<<z[i]<<"\n";
    }
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
    glutCreateWindow("3D Rotation along x-axis by 60 degrees");
    glutDisplayFunc(display);
    glutKeyboardFunc(keyboard);
    init();
    glutMainLoop();
    return 0;
}
