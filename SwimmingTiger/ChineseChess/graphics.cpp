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
#include "chess.h"
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

    //还原类型和颜色状态
	SelectObject(hdc, hPenOld);
	DeleteObject(hPen);

	//释放句柄
	ReleaseDC(hwnd,hdc);
}

/**
* @brief 绘制棋盘线
* 
* 采用 style.h 里定义的颜色和风格绘制直线
*/
void DrawChessBoardLine(int x1, int y1, int x2, int y2)
{
    DrawLine(x1, y1, x2, y2, CHESSBOARD_BORDER_STYLE, CHESSBOARD_BORDER_WIDTH, CHESSBOARD_BORDER_COLOR);
}

/**
* @brief 绘制矩形
*/
void DrawRect(int left, int top, int right, int bottom, int borderStyle, int borderWight, COLORREF borderColor, COLORREF insideColor) {
    HWND hwnd;
    HDC hdc;
    HPEN hPen;
	HPEN hPenOld;
    HBRUSH hBrush;
	HBRUSH hBrushOld;

	//获取控制台设备句柄
    hwnd = GetConsoleWindow();
    hdc = GetDC(hwnd);

	//修改矩形边框和内部颜色
    hPen = CreatePen(borderStyle, borderWight, borderColor);
    hPenOld = (HPEN)SelectObject(hdc, hPen);
    hBrush = CreateSolidBrush(insideColor);
    hBrushOld = (HBRUSH)SelectObject(hdc, hBrush);

	//画矩形
    Rectangle(hdc, left, top, right, bottom);

    //还原颜色状态
	SelectObject(hdc, hPenOld);
	SelectObject(hdc, hBrushOld);
	DeleteObject(hBrush);
    DeleteObject(hPen);

	//释放句柄
	ReleaseDC(hwnd,hdc);
}

/**
* @brief 绘制圆形
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

    //计算圆形坐标范围
    left = centerX - radius;
    right = centerX + radius;
    top = centerY - radius;
    bottom = centerY + radius;

	//获取控制台设备句柄
    hwnd = GetConsoleWindow();
    hdc = GetDC(hwnd);

	//修改圆形边框和内部颜色
    hPen = CreatePen(borderStyle, borderWight, borderColor);
    hPenOld = (HPEN)SelectObject(hdc, hPen);
    hBrush = CreateSolidBrush(insideColor);
    hBrushOld = (HBRUSH)SelectObject(hdc, hBrush);

	//画圆形
    Ellipse(hdc, left, top, right, bottom);

    //还原颜色状态
	SelectObject(hdc, hPenOld);
	SelectObject(hdc, hBrushOld);
	DeleteObject(hBrush);
    DeleteObject(hPen);

	//释放句柄
	ReleaseDC(hwnd,hdc);
}

/**
* @brief 改变控制台窗口的大小、位置和层叠顺序
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
* @brief 绘制棋盘
*/
void DrawChessBoard()
{
    int x;
    int y;
    int centerLineTop;
    int centerLineBottom;
    //黑方九宫坐标
    int kNineGridLeft;
    int kNineGridTop;
    int kNineGridRight;
    int kNineGridBottom;
    //红方九宫坐标
    int rNineGridLeft;
    int rNineGridTop;
    int rNineGridRight;
    int rNineGridBottom;

	//调整控制台背景颜色
    system(CHESSBOARD_COLOR);

    //计算河界坐标
    centerLineTop = CHESSBOARD_RECT_TOP + (CHESSBOARD_LINE_HEIGHT * 4);
    centerLineBottom = centerLineTop + CHESSBOARD_LINE_HEIGHT;
    //计算黑方九宫坐标
    kNineGridLeft = CHESSBOARD_RECT_LEFT + (CHESSBOARD_ROW_WIDTH * 3);
    kNineGridRight = kNineGridLeft + (CHESSBOARD_ROW_WIDTH * 2);
    kNineGridTop = CHESSBOARD_RECT_TOP;
    kNineGridBottom = kNineGridTop + (CHESSBOARD_LINE_HEIGHT * 2);
    //计算红方九宫坐标
    rNineGridLeft = kNineGridLeft;
    rNineGridRight = kNineGridRight;
    rNineGridTop = kNineGridTop + (CHESSBOARD_LINE_HEIGHT * 7);
    rNineGridBottom = kNineGridBottom + (CHESSBOARD_LINE_HEIGHT * 7);

    //画横线
    for (y=CHESSBOARD_RECT_TOP; y<=CHESSBOARD_RECT_BOTTOM; y+=CHESSBOARD_LINE_HEIGHT)
    {
        DrawChessBoardLine(CHESSBOARD_RECT_LEFT, y, CHESSBOARD_RECT_RIGHT, y);
    }
    //画竖线
    for (x=CHESSBOARD_RECT_LEFT; x<=CHESSBOARD_RECT_RIGHT; x+=CHESSBOARD_ROW_WIDTH)
    {
        DrawChessBoardLine(x, CHESSBOARD_RECT_TOP, x, centerLineTop);
        DrawChessBoardLine(x, centerLineBottom, x, CHESSBOARD_RECT_BOTTOM);
    }

    //画边框贯通竖线
    DrawChessBoardLine(CHESSBOARD_RECT_LEFT, CHESSBOARD_RECT_TOP, CHESSBOARD_RECT_LEFT, CHESSBOARD_RECT_BOTTOM);
    DrawChessBoardLine(CHESSBOARD_RECT_RIGHT, CHESSBOARD_RECT_TOP, CHESSBOARD_RECT_RIGHT, CHESSBOARD_RECT_BOTTOM);
    //画九宫
    DrawChessBoardLine(kNineGridLeft, kNineGridTop, kNineGridRight, kNineGridBottom);
    DrawChessBoardLine(kNineGridRight, kNineGridTop, kNineGridLeft, kNineGridBottom);
    DrawChessBoardLine(rNineGridLeft, rNineGridTop, rNineGridRight, rNineGridBottom);
    DrawChessBoardLine(rNineGridRight, rNineGridTop, rNineGridLeft, rNineGridBottom);
}

/**
* @brief 绘制棋子
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
* @brief 绘制所有棋子
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