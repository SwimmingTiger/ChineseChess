/**
* @brief 中国象棋绘图函数实现
* 
* - 作者信息
*     - 作者：彭逸豪
*     - 班级：软件131班
*     - 学院：计算机科学与工程学院
*     - 学校：大连民族学院
*/
#include <stdio.h>
#include <windows.h>
#include "win32api.h"
#include "graphics.h"
#include "style.h"

/**
* @brief 绘制直线
*/
void DrawLine(int x1, int y1, int x2, int y2)
{
    HWND hwnd;
    HDC hdc;

	//获取控制台设备句柄
    hwnd = GetConsoleWindow();
    hdc = GetDC(hwnd);

	//画线
    MoveToEx(hdc, x1, y1, NULL);
    LineTo(hdc, x2, y2);
}

/**
* @brief 改变控制台窗口大小
*/
void SetWindowSize(int width, int height)
{
    HANDLE hOut;
    COORD size = {width, height};
    SMALL_RECT rc = {0, 0, width-1, height-1};
    CONSOLE_CURSOR_INFO cursor = {1, FALSE};
    
    hOut = GetStdHandle(STD_OUTPUT_HANDLE);

    SetConsoleWindowInfo(hOut, TRUE, &rc);
    SetConsoleScreenBufferSize(hOut, size);
    SetConsoleCursorInfo(hOut, &cursor);
}

/**
* @brief 绘制棋盘
*/
void DrawChessBoard()
{
    int x, y;

    //改变控制台窗口大小
    SetWindowSize(80, 40);
	//调整控制台背景颜色
    system(CHESSBOARD_COLOR);

    for (y=0; y<=640; y+=64)
    {
        DrawLine(0, y, 640, y);
    }
}