/**
* @brief �й������ͼ����ʵ��
* 
* - ������Ϣ
*     - ���ߣ����ݺ�
*     - �༶�����131��
*     - ѧԺ���������ѧ�빤��ѧԺ
*     - ѧУ����������ѧԺ
*/
#include <stdio.h>
#include <windows.h>
#include "win32api.h"
#include "graphics.h"
#include "style.h"

/**
* @brief ����ֱ��
*/
void DrawLine(int x1, int y1, int x2, int y2)
{
    HWND hwnd;
    HDC hdc;
	HPEN hPen;
	HPEN hPenOld;

	//��ȡ����̨�豸���
    hwnd = GetConsoleWindow();
    hdc = GetDC(hwnd);

    hPen = CreatePen(PS_SOLID, 5, RGB(255, 0, 0));
    hPenOld = (HPEN)SelectObject(hdc, hPen);

	//����
    MoveToEx(hdc, x1, y1, NULL);
    LineTo(hdc, x2, y2);
	SelectObject(hdc, hPenOld);
	DeleteObject(hPen);

	ReleaseDC(hwnd,hdc);
}

/**
* @brief �ı����̨���ڴ�С
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

    SetConsoleWindowInfo(hOut, TRUE, &rc);
    SetConsoleScreenBufferSize(hOut, size);
    SetConsoleCursorInfo(hOut, &cursor);
}

/**
* @brief ��������
*/
void DrawChessBoard()
{
    int x, y;

    //�ı����̨���ڴ�С
    SetWindowSize(CHESSBOARD_WINDOW_WIDTH, CHESSBOARD_WINDOW_HEIGHT);
	//��������̨������ɫ
    system(CHESSBOARD_COLOR);

    for (y=CHESSBOARD_RECT_TOP; y<=CHESSBOARD_RECT_BOTTOM; y+=CHESSBOARD_LINE_HEIGHT)
    {
        DrawLine(CHESSBOARD_RECT_LEFT, y, CHESSBOARD_RECT_RIGHT, y);
    }
	//printf("˧���������˱�\n");
}