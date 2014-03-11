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
void DrawLine(int x1, int y1, int x2, int y2, int lineStyle, int lineWight, COLORREF lineColor)
{
    HWND hwnd;
    HDC hdc;
	HPEN hPen;
	HPEN hPenOld;

	//获取控制台设备句柄
    hwnd = GetConsoleWindow();
    hdc = GetDC(hwnd);

	//修改线条类型和颜色
    hPen = CreatePen(lineStyle, lineWight, lineColor);
    hPenOld = (HPEN)SelectObject(hdc, hPen);

	//画线
    MoveToEx(hdc, x1, y1, NULL);
    LineTo(hdc, x2, y2);

    //还原线条类型和颜色
	SelectObject(hdc, hPenOld);
	DeleteObject(hPen);

	//释放句柄
	ReleaseDC(hwnd,hdc);
}

/**
* @brief 改变控制台窗口大小
*/
void SetWindowSize(int width, int height)
{
    HANDLE hOut;
    COORD size;
    SMALL_RECT rc;
    CONSOLE_CURSOR_INFO cursor = {1, FALSE};

	size.X = width;
	size.Y = height;

    rc.Left = 0;
    rc.Top = 0;
	rc.Right = width - 1;
	rc.Bottom = height - 1;

    hOut = GetStdHandle(STD_OUTPUT_HANDLE);
    
    printf("%d",SetConsoleFont(hOut, 16));
    SetConsoleDisplayMode(hOut, 1, NULL);
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
    SetWindowSize(CHESSBOARD_WINDOW_WIDTH, CHESSBOARD_WINDOW_HEIGHT);
	//调整控制台背景颜色
    system(CHESSBOARD_COLOR);

    for (y=CHESSBOARD_RECT_TOP; y<=CHESSBOARD_RECT_BOTTOM; y+=CHESSBOARD_LINE_HEIGHT)
    {
        DrawLine(CHESSBOARD_RECT_LEFT, y, CHESSBOARD_RECT_RIGHT, y, CHESSBOARD_LINE_STYLE, CHESSBOARD_LINE_WIDTH, CHESSBOARD_LINE_COLOR);
    }

	printf("帅车马炮相仕兵\n%d\n", GetNumberOfConsoleFonts());
}