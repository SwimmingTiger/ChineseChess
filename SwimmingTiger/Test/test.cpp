#include <windows.h>
#include <windowsx.h>
#include <stdio.h>
#include <conio.h>
#include "win32api.h"
#include <math.h>

/*void circle(POINT *center,int radius)
{
    HWND    hwnd;
    HDC    hdc;
    int    xmin = center->x - radius;
    int    xmax = center->x + radius;
    int    ymin = center->y - radius;
    int    ymax = center->y + radius;
    POINT    point;

    hwnd = GetConsoleWindow();
    hdc = GetDC(hwnd);

    point.x = xmin;
    point.y = ymin;
    MoveToEx(hdc,center->x,center->y - radius,NULL);
    while (TRUE)
    {
        if (fabs(sqrt(pow2(point.x - center->x) + pow2(point.y - center->y)) - radius) <= 1)
        {
            DrawPoint(hdc,&point);
        }
       //�Ƿ񵽴���ĩ
        if (point.x == xmax)
        {
            if (point.y == ymax)
            {
                break;
            }
            else
            {
                point.x = xmin;
                point.y++;
                continue;
            }
        }
        point.x++;
    }
}*/

int main()
{
    HWND hwnd;
    HDC hdc;
    unsigned char ch;

	//��ȡconsole���豸�����ľ��
    hwnd = GetConsoleWindow();
    hdc = GetDC(hwnd);

	//����һ��console������ɫ�����򿴲�������
    system("color 3D");

	//��ʼλ�ã�Windows�д��ڵ�����ϵ�൱��ֱ������ϵ��һ���޷�ת����������
    MoveToEx(hdc,10,250,NULL);

    //����׼������
    LineTo(hdc,650,250);

    //��ʼ��ͼ
    //MoveToEx(hdc,10,250,NULL);
    /*for (i = 0; i < NUMBER; i++)
    {
        LineTo(hdc,point[i].x,point[i].y);
    }*/
while((ch=getch())!=0x1B) /* ESC to quit */
{
   printf("%d ", ch);
}
    return 0;
}

