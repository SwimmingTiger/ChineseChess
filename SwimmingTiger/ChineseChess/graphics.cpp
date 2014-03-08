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

	//��ȡ����̨�豸���
    hwnd = GetConsoleWindow();
    hdc = GetDC(hwnd);

	//����
    MoveToEx(hdc, x1, y1, NULL);
    LineTo(hdc, x2, y2);
}

/**
* @brief �ı����̨���ڴ�С
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
* @brief ��������
*/
void DrawChessBoard()
{
    int x, y;

    //�ı����̨���ڴ�С
    SetWindowSize(80, 40);
	//��������̨������ɫ
    system(CHESSBOARD_COLOR);

    for (y=0; y<=640; y+=64)
    {
        DrawLine(0, y, 640, y);
    }
}