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
       //是否到达行末
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

	//获取console的设备上下文句柄
    hwnd = GetConsoleWindow();
    hdc = GetDC(hwnd);

	//调整一下console背景颜色，否则看不清线条
    system("color 3D");

	//起始位置，Windows中窗口的坐标系相当于直角坐标系第一象限翻转到第四象限
    MoveToEx(hdc,10,250,NULL);

    //画基准坐标线
    LineTo(hdc,650,250);

    //开始绘图
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

