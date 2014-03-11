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
#include "chess.h"
#include "graphics.h"
#include "style.h"

/**
* @brief ����ֱ��
*/
void DrawLine(int x1, int y1, int x2, int y2, int lineStyle, int lineWight, COLORREF lineColor)
{
    HWND hwnd;
    HDC hdc;
	HPEN hPen;
	HPEN hPenOld;

	//��ȡ����̨�豸���
    hwnd = GetConsoleWindow();
    hdc = GetDC(hwnd);

	//�޸��������ͺ���ɫ
    hPen = CreatePen(lineStyle, lineWight, lineColor);
    hPenOld = (HPEN)SelectObject(hdc, hPen);

	//����
    MoveToEx(hdc, x1, y1, NULL);
    LineTo(hdc, x2, y2);

    //��ԭ���ͺ���ɫ״̬
	SelectObject(hdc, hPenOld);
	DeleteObject(hPen);

	//�ͷž��
	ReleaseDC(hwnd,hdc);
}

/**
* @brief ����������
* 
* ���� style.h �ﶨ�����ɫ�ͷ�����ֱ��
*/
void DrawChessBoardLine(int x1, int y1, int x2, int y2)
{
    DrawLine(x1, y1, x2, y2, CHESSBOARD_BORDER_STYLE, CHESSBOARD_BORDER_WIDTH, CHESSBOARD_BORDER_COLOR);
}

/**
* @brief ���ƾ���
*/
void DrawRect(int left, int top, int right, int bottom, int borderStyle, int borderWight, COLORREF borderColor, COLORREF insideColor) {
    HWND hwnd;
    HDC hdc;
    HPEN hPen;
	HPEN hPenOld;
    HBRUSH hBrush;
	HBRUSH hBrushOld;

	//��ȡ����̨�豸���
    hwnd = GetConsoleWindow();
    hdc = GetDC(hwnd);

	//�޸ľ��α߿���ڲ���ɫ
    hPen = CreatePen(borderStyle, borderWight, borderColor);
    hPenOld = (HPEN)SelectObject(hdc, hPen);
    hBrush = CreateSolidBrush(insideColor);
    hBrushOld = (HBRUSH)SelectObject(hdc, hBrush);

	//������
    Rectangle(hdc, left, top, right, bottom);

    //��ԭ��ɫ״̬
	SelectObject(hdc, hPenOld);
	SelectObject(hdc, hBrushOld);
	DeleteObject(hBrush);
    DeleteObject(hPen);

	//�ͷž��
	ReleaseDC(hwnd,hdc);
}

/**
* @brief ����Բ��
*/
void DrawCircle(int radius, int centerX, int centerY, int borderStyle, int borderWight, COLORREF borderColor, COLORREF insideColor)
{
    HWND hwnd;
    HDC hdc;
    HPEN hPen;
	HPEN hPenOld;
    HBRUSH hBrush;
	HBRUSH hBrushOld;
    int left;
    int top;
    int right;
    int bottom;

    //����Բ�����귶Χ
    left = centerX - radius;
    right = centerX + radius;
    top = centerY - radius;
    bottom = centerY + radius;

	//��ȡ����̨�豸���
    hwnd = GetConsoleWindow();
    hdc = GetDC(hwnd);

	//�޸�Բ�α߿���ڲ���ɫ
    hPen = CreatePen(borderStyle, borderWight, borderColor);
    hPenOld = (HPEN)SelectObject(hdc, hPen);
    hBrush = CreateSolidBrush(insideColor);
    hBrushOld = (HBRUSH)SelectObject(hdc, hBrush);

	//��Բ��
    Ellipse(hdc, left, top, right, bottom);

    //��ԭ��ɫ״̬
	SelectObject(hdc, hPenOld);
	SelectObject(hdc, hBrushOld);
	DeleteObject(hBrush);
    DeleteObject(hPen);

	//�ͷž��
	ReleaseDC(hwnd,hdc);
}

/**
* @brief �ı����̨���ڵĴ�С��λ�úͲ��˳��
*/
void SetWindowSize(int width, int height, int left, int top, HWND zIndex)
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

    SetWindowPos(GetConsoleWindow(), zIndex, left, top, 0, 0, SWP_NOSIZE);
}

/**
* @brief ��������
*/
void DrawChessBoard()
{
    int x;
    int y;
    int centerLineTop;
    int centerLineBottom;
    //�ڷ��Ź�����
    int kNineGridLeft;
    int kNineGridTop;
    int kNineGridRight;
    int kNineGridBottom;
    //�췽�Ź�����
    int rNineGridLeft;
    int rNineGridTop;
    int rNineGridRight;
    int rNineGridBottom;

	//��������̨������ɫ
    system(CHESSBOARD_COLOR);

    //����ӽ�����
    centerLineTop = CHESSBOARD_RECT_TOP + (CHESSBOARD_LINE_HEIGHT * 4);
    centerLineBottom = centerLineTop + CHESSBOARD_LINE_HEIGHT;
    //����ڷ��Ź�����
    kNineGridLeft = CHESSBOARD_RECT_LEFT + (CHESSBOARD_ROW_WIDTH * 3);
    kNineGridRight = kNineGridLeft + (CHESSBOARD_ROW_WIDTH * 2);
    kNineGridTop = CHESSBOARD_RECT_TOP;
    kNineGridBottom = kNineGridTop + (CHESSBOARD_LINE_HEIGHT * 2);
    //����췽�Ź�����
    rNineGridLeft = kNineGridLeft;
    rNineGridRight = kNineGridRight;
    rNineGridTop = kNineGridTop + (CHESSBOARD_LINE_HEIGHT * 7);
    rNineGridBottom = kNineGridBottom + (CHESSBOARD_LINE_HEIGHT * 7);

    //������
    for (y=CHESSBOARD_RECT_TOP; y<=CHESSBOARD_RECT_BOTTOM; y+=CHESSBOARD_LINE_HEIGHT)
    {
        DrawChessBoardLine(CHESSBOARD_RECT_LEFT, y, CHESSBOARD_RECT_RIGHT, y);
    }
    //������
    for (x=CHESSBOARD_RECT_LEFT; x<=CHESSBOARD_RECT_RIGHT; x+=CHESSBOARD_ROW_WIDTH)
    {
        DrawChessBoardLine(x, CHESSBOARD_RECT_TOP, x, centerLineTop);
        DrawChessBoardLine(x, centerLineBottom, x, CHESSBOARD_RECT_BOTTOM);
    }

    //���߿��ͨ����
    DrawChessBoardLine(CHESSBOARD_RECT_LEFT, CHESSBOARD_RECT_TOP, CHESSBOARD_RECT_LEFT, CHESSBOARD_RECT_BOTTOM);
    DrawChessBoardLine(CHESSBOARD_RECT_RIGHT, CHESSBOARD_RECT_TOP, CHESSBOARD_RECT_RIGHT, CHESSBOARD_RECT_BOTTOM);
    //���Ź�
    DrawChessBoardLine(kNineGridLeft, kNineGridTop, kNineGridRight, kNineGridBottom);
    DrawChessBoardLine(kNineGridRight, kNineGridTop, kNineGridLeft, kNineGridBottom);
    DrawChessBoardLine(rNineGridLeft, rNineGridTop, rNineGridRight, rNineGridBottom);
    DrawChessBoardLine(rNineGridRight, rNineGridTop, rNineGridLeft, rNineGridBottom);
}

/**
* @brief ��������
*/
void DrawChessPiece(char chessType, int line, int row)
{
    int centerX;
    int centerY;

    centerX = CHESSBOARD_RECT_LEFT + (CHESSBOARD_ROW_WIDTH * row);
    centerY = CHESSBOARD_RECT_TOP + (CHESSBOARD_LINE_HEIGHT * line);

    DrawCircle(CHESS_RADIUS, centerX, centerY, CHESS_BORDER_STYLE, CHESS_BORDER_WIDTH, CHESS_BORDER_COLOR, CHESS_INSIDE_COLOR);
}

/**
* @brief ������������
*/
void DrawAllChessPiece(struct ChessBoard *cp)
{
    int line;
    int row;
    char chessPiece;

    for (line=0; line<10; line++)
    {
        for (row=0; row<9; row++)
        {
            chessPiece = cp->map[line][row];

            if (chessPiece != CT_NULL)
            {
                DrawChessPiece(chessPiece, line, row);
            }
        }
    }
}