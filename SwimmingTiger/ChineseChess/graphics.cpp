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
void DrawLine(HDC hdc, int x1, int y1, int x2, int y2, int lineStyle, int lineWight, COLORREF lineColor)
{
	HPEN hPen;
	HPEN hPenOld;

	//修改线条类型和颜色
    hPen = CreatePen(lineStyle, lineWight, lineColor);
    hPenOld = (HPEN)SelectObject(hdc, hPen);

	//画线
    MoveToEx(hdc, x1, y1, NULL);
    LineTo(hdc, x2, y2);

    //还原类型和颜色状态
	SelectObject(hdc, hPenOld);
	DeleteObject(hPen);
}

/**
* @brief 绘制棋盘线
* 
* 采用 style.h 里定义的颜色和风格绘制直线
*/
void DrawChessBoardLine(HDC hdc, int x1, int y1, int x2, int y2)
{
    DrawLine(hdc, x1, y1, x2, y2, CHESSBOARD_BORDER_STYLE, CHESSBOARD_BORDER_WIDTH, CHESSBOARD_BORDER_COLOR);
}

/**
* @brief 绘制矩形
*/
void DrawRect(HDC hdc, int left, int top, int right, int bottom, int borderStyle, int borderWidth, COLORREF borderColor, COLORREF insideColor)
{
    HPEN hPen;
	HPEN hPenOld;
    HBRUSH hBrush;
	HBRUSH hBrushOld;

	//修改矩形边框和内部颜色
    hPen = CreatePen(borderStyle, borderWidth, borderColor);
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
}

/** 
* @brief 绘制字符串
*/
void DrawString(HDC hdc, char *str, COLORREF textColor, COLORREF backgroundColor,
				COLORREF borderColor, int borderStyle, int borderWeight,
				int fontHeight, int fontWidth, int fontWeight, DWORD fontFamily, char* fontName,
				int offsetX, int offsetY)
{
	HFONT hFont;
    HFONT hFontOld;
	COLORREF backgroundColorOld;
	COLORREF textColorOld;

	//修改字体样式
	hFont = CreateFont(fontHeight, fontWidth, 0, 0, fontWeight, 0, 0, 0, GB2312_CHARSET, OUT_DEFAULT_PRECIS, CLIP_DEFAULT_PRECIS, PROOF_QUALITY, fontFamily, fontName);
    hFontOld = (HFONT)SelectObject(hdc, hFont);
	backgroundColorOld = SetBkColor(hdc, backgroundColor);
	textColorOld = SetTextColor(hdc, textColor);

	//绘制字体
	TextOut(hdc, offsetX, offsetY, str, strlen(str));

    //还原字体状态
	SelectObject(hdc, hFontOld);
	DeleteObject(hFont);
	SetBkColor(hdc, backgroundColorOld);
	SetTextColor(hdc, textColorOld);
}

/**
* @brief 绘制圆形
*/
void DrawCircle(HDC hdc, int radius, int centerX, int centerY, int borderStyle, int borderWidth, COLORREF borderColor, COLORREF insideColor)
{
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

	//修改圆形边框和内部颜色
    hPen = CreatePen(borderStyle, borderWidth, borderColor);
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
}

/**
* @brief 改变控制台窗口的大小、位置和层叠顺序
*/
void SetWindowSize(int contentWidth, int contentHeight, int width, int height, int left, int top, HWND zIndex)
{
    HANDLE hOut;
    COORD size;
    SMALL_RECT rc;
    CONSOLE_CURSOR_INFO cursor = {1, FALSE};

	size.X = contentWidth;
	size.Y = contentHeight;

    rc.Left = 0;
    rc.Top = 0;
	rc.Right = width - 1;
	rc.Bottom = height - 1;

    hOut = GetStdHandle(STD_OUTPUT_HANDLE);

    SetConsoleWindowInfo(hOut, TRUE, &rc);
    SetConsoleScreenBufferSize(hOut, size);
    SetConsoleCursorInfo(hOut, &cursor);

    SetWindowPos(GetConsoleWindow(), zIndex, left, top, width, height, SWP_SHOWWINDOW);
}

/**
* @brief 绘制棋盘
*/
void DrawChessBoard(HDC hdc, struct ChessBoard *cp)
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
    system(CONSOLE_COLOR);
    
    //绘制棋盘背景
    DrawRect(hdc, 0, 0, CONSOLE_WINDOW_WIDTH, CONSOLE_WINDOW_HEIGHT, 0, 0, CHESSBOARD_BACKGROUND_COLOR, CHESSBOARD_BACKGROUND_COLOR);

    //绘制光标
    DrawCursor(hdc, *ActiveCursor(cp), cp->activePlayer);
    if (cp->chessLocked)
    {
        //棋子锁定光标是两玩家共用的
        DrawCursor(hdc, cp->lockedCursor, PLY_BOTH);
    }

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
        DrawChessBoardLine(hdc, CHESSBOARD_RECT_LEFT, y, CHESSBOARD_RECT_RIGHT, y);
    }
    //画竖线
    for (x=CHESSBOARD_RECT_LEFT; x<=CHESSBOARD_RECT_RIGHT; x+=CHESSBOARD_ROW_WIDTH)
    {
        DrawChessBoardLine(hdc, x, CHESSBOARD_RECT_TOP, x, centerLineTop);
        DrawChessBoardLine(hdc, x, centerLineBottom, x, CHESSBOARD_RECT_BOTTOM);
    }

    //画边框贯通竖线
    DrawChessBoardLine(hdc, CHESSBOARD_RECT_LEFT, CHESSBOARD_RECT_TOP, CHESSBOARD_RECT_LEFT, CHESSBOARD_RECT_BOTTOM);
    DrawChessBoardLine(hdc, CHESSBOARD_RECT_RIGHT, CHESSBOARD_RECT_TOP, CHESSBOARD_RECT_RIGHT, CHESSBOARD_RECT_BOTTOM);
    //画九宫
    DrawChessBoardLine(hdc, kNineGridLeft, kNineGridTop, kNineGridRight, kNineGridBottom);
    DrawChessBoardLine(hdc, kNineGridRight, kNineGridTop, kNineGridLeft, kNineGridBottom);
    DrawChessBoardLine(hdc, rNineGridLeft, rNineGridTop, rNineGridRight, rNineGridBottom);
    DrawChessBoardLine(hdc, rNineGridRight, rNineGridTop, rNineGridLeft, rNineGridBottom);
}

/**
* @brief 绘制光标
*/
void DrawCursor(HDC hdc, struct ChessPos cursor, char player)
{
    int centerX;
    int centerY;
    COLORREF borderColor;
    RECT rc= CURSOR_RECT;

    //两玩家共用的是锁定光标，用另一种颜色绘制
    if (player == PLY_BOTH)
    {
        borderColor = LOCK_CURSOR_BORDER_COLOR;
    }
    else
    {
        borderColor = CURSOR_BORDER_COLOR;
    }

    centerX = CHESSBOARD_RECT_LEFT + (CHESSBOARD_ROW_WIDTH * cursor.row);
    centerY = CHESSBOARD_RECT_TOP + (CHESSBOARD_LINE_HEIGHT * cursor.line);

    rc.left += centerX;
    rc.right += centerX;
    rc.top += centerY;
    rc.bottom += centerY;

    DrawRect(hdc, rc.left, rc.top, rc.right, rc.bottom, CURSOR_BORDER_STYLE,
             CURSOR_BORDER_WIDTH, borderColor, CURSOR_INSIDE_COLOR);
}

/**
* @brief 绘制棋子
*/
void DrawChess(HDC hdc, char chessType, struct ChessPos pos)
{
    int centerX;
    int centerY;
    COLORREF chessColor;
    char chessName[3];

    centerX = CHESSBOARD_RECT_LEFT + (CHESSBOARD_ROW_WIDTH * pos.row);
    centerY = CHESSBOARD_RECT_TOP + (CHESSBOARD_LINE_HEIGHT * pos.line);

    if (chessType >= CHESS_R_SHUAI && chessType <= CHESS_R_BING)
    {
        chessColor = CHESS_RED_COLOR;
    }
    else if (chessType >= CHESS_K_JIANG && chessType <= CHESS_K_ZU)
    {
        chessColor = CHESS_BLACK_COLOR;
    }

    GetChessName(chessType, chessName);

    DrawCircle(hdc, CHESS_RADIUS + CHESS_BORDER_WIDTH, centerX , centerY, CHESS_BORDER_STYLE, 0, CHESS_INSIDE_COLOR, CHESS_INSIDE_COLOR);
    DrawCircle(hdc, CHESS_RADIUS, centerX, centerY, CHESS_BORDER_STYLE, CHESS_BORDER_WIDTH, chessColor, CHESS_INSIDE_COLOR);
	DrawString(hdc, chessName, chessColor, CHESS_INSIDE_COLOR,
		       0xffffff, 0, 0,
			   CHESS_FONT_HEIGHT, CHESS_FONT_WIDTH, CHESS_FONT_WEIGHT, CHESS_FONT_FAMILY, CHESS_FONT_NAME,
			   centerX+CHESS_FONT_OFFSET_X, centerY+CHESS_FONT_OFFSET_Y);
}

/**
* @brief 绘制所有棋子
*/
void DrawAllChess(HDC hdc, struct ChessBoard *cp)
{
    int line;
    int row;
    char chessPiece;
    struct ChessPos pos;

    for (line=0; line<CHESSBOARD_LINE; line++)
    {
        for (row=0; row<CHESSBOARD_ROW; row++)
        {
            chessPiece = cp->map[line][row];
            pos.line = line;
            pos.row = row;

            if (chessPiece != CHESS_NULL)
            {
                DrawChess(hdc, chessPiece, pos);
            }
        }
    }
}

/**
* @brief 刷新指定坐标的图像
*/
void RefreshPos(HDC hdc, HDC hMemDc, struct ChessBoard *cp, struct ChessPos pos)
{
    int centerX;
    int centerY;
    RECT rc= CURSOR_RECT;

    centerX = CHESSBOARD_RECT_LEFT + (CHESSBOARD_ROW_WIDTH * pos.row);
    centerY = CHESSBOARD_RECT_TOP + (CHESSBOARD_LINE_HEIGHT * pos.line);
    
    rc.left += centerX;
    rc.right -= rc.left;
    rc.top += centerY;
    rc.bottom -= rc.top;

    /*CURSOR_BORDER_WIDTH*/

    //DrawRect(hdc, , rc.top, rc.right, rc.bottom,
             //CURSOR_BORDER_STYLE, CURSOR_BORDER_WIDTH, borderColor, CURSOR_INSIDE_COLOR);
    DrawChessBoard(hMemDc, cp);
    DrawAllChess(hMemDc, cp);
    BitBlt(hdc, rc.left, rc.top, rc.bottom, rc.right, hMemDc, rc.left, rc.top, SRCCOPY);
}