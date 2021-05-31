#include <GL/glut.h>
#include <stdlib.h>
#include <stdio.h>
#include <iostream>
using namespace std;
int X1, Y1, X2, Y2;
int flag;
int a[10];
void midpoint_line(int x1, int y1, int x2, int y2)///�е㻭�߷�
{
    int x, y, p1, p2, p0, xNext, yNext;    //���߱���p0��p0<=0ʱ����Ϊp2, p0>0ʱ����Ϊp1
    float k;
    if (x2 < x1)
    {
        p0 = x1, x1 = x2, x2 = p0;
        p0 = y1, y1 = y2, y2 = p0;
    }
    x = y1 - y2, y = x2 - x1;//x==a y==b
    if (y == 0)
        k = -1 * x * 100;
    else
        k = (float)x / (x1 - x2);
    xNext = x1, yNext = y1;
    glBegin(GL_POINTS);///���㺯��,ֻ����������,
    glVertex2i(xNext, yNext);///����x,y���л���
    //printf("%d %d\n",xNext,yNext);
    glEnd();
    if (k >= 0 && k <= 1)
    {
        p0 = 2 * x + y; p1 = 2 * x, p2 = 2 * (x + y);
        while (xNext < x2)
        {
            if (p0 <= 0)
            {
                xNext++, yNext++, p0 += p2;
            }
            else
            {
                xNext++, p0 += p1;
            }
            glBegin(GL_POINTS);///���㺯��,ֻ����������,
            glVertex2i(xNext, yNext);///����x,y���л���
            //printf("%d %d\n",xNext,yNext);
            glEnd();
        }
    }
    else if (k <= 0 && k >= -1)
    {
        p0 = 2 * x - y; p1 = 2 * x - 2 * y, p2 = 2 * x;
        while (xNext < x2)
        {
            if (p0 > 0)
            {
                xNext++, yNext--, p0 += p1;
            }
            else
            {
                xNext++, p0 += p2;
            }
            glBegin(GL_POINTS);///���㺯��,ֻ����������,
            glVertex2i(xNext, yNext);///����x,y���л���
            //printf("%d %d\n",xNext,yNext);
            glEnd();
        }
    }
    else if (k > 1)
    {
        p0 = x + 2 * y; p1 = 2 * (x + y), p2 = 2 * y;
        while (yNext < y2)
        {
            if (p0 > 0)
            {
                xNext++, yNext++, p0 += p1;
            }
            else
            {
                yNext++, p0 += p2;
            }
            glBegin(GL_POINTS);///���㺯��,ֻ����������,
            glVertex2i(xNext, yNext);///����x,y���л���
            //printf("%d %d\n",xNext,yNext);
            glEnd();
        }
    }
    else
    {
        p0 = x - 2 * y;
        p1 = -2 * y, p2 = 2 * (x - y);
        while (yNext > y2)
        {
            if (p0 <= 0)
            {
                xNext++, yNext--, p0 += p2;
            }
            else
            {
                yNext--, p0 += p1;
            }
            glBegin(GL_POINTS);///���㺯��,ֻ����������,
            glVertex2i(xNext, yNext);///����x,y���л���
            //printf("%d %d\n",xNext,yNext);
            glEnd();
        }
    }
}


void display(void)///����һ��û�в����ĺ�����������һ������
{
    glClear(GL_COLOR_BUFFER_BIT); ///ˢ�»���,�ڴ����г���
    switch (flag)
    {
    case 1:midpoint_line(a[0], a[1], a[2], a[3]); break;
    case 2:
            midpoint_line(a[0], a[1], a[2], a[3]);
            midpoint_line(a[2], a[3], a[4], a[5]);
            midpoint_line(a[4], a[5], a[0], a[1]);
            break;
    case 3:
        midpoint_line(a[0], a[1], a[0], a[3]);
        midpoint_line(a[0], a[1], a[2], a[1]);
        midpoint_line(a[2], a[1], a[2], a[3]);
        midpoint_line(a[2], a[3], a[0], a[3]);
        break;
    default:
        cout << "ERROR!" << endl;
        break;
    }
 
   
    glFlush();///��������������
}
void Scanf()
{
    cin >> flag;
    if (flag == 1)
    {
        cout << "��������ʼ����ֵ��\n";
        cin >> a[0] >> a[1];
        cout << "�������յ�����ֵ��\n";
        cin >> a[2] >> a[3];
    }
    else if (flag == 2)
    {
        cout << "��������������������ֵ��\n";
        for (int i = 0; i < 6; i++)
        {
            cin >> a[i];
        }
    }
    else if (flag == 3)
    {
        cout << "��������ζԽ���������ֵ��\n";
        for (int i = 0; i < 4; i++)
        {
            cin >> a[i];
        }
    }
    else {
        cout << "��������ȷѡ�\n";
        Scanf();
    }
}
int main(int argc, char* argv[])
{
    cout << "������Ҫ����ͼ�Σ�\n";
    cout << "1��ֱ��\n"; 
    cout << "2��������\n";
    cout << "3������\n";
    Scanf();
    glutInit(&argc, argv);///glut�ĳ�ʼ��
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(600, 600);///���ڵĴ�С500x500
    glutInitWindowPosition(0, 0);///���崰�ڵ�λ��,����Ļ�����0����,��Ļ��������0����
    glutCreateWindow("�е㻭���㷨��ͼ");
    glClearColor(1.0, 1.0, 1.0, 0.0); ///����1.0�ǰ�ɫ����,����0.0�Ǻ�ɫ����
    glColor3f(1, 0, 0); ///����
    gluOrtho2D(0.0, 600.0, 0.0, 600.0);///�ڴ����ڽ�����άֱ������ϵ,x1,x2,y1,y2
    glutDisplayFunc(display);///�ڴ�������ʾdiaplay
    glutMainLoop();
}