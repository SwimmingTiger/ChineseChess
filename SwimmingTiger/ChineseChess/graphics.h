#ifndef _GRAPHICS_H_
/**
* @brief 中国象棋游戏绘图函数声明
* 
* - 作者信息
*     - 作者：彭逸豪
*     - 班级：软件131班
*     - 学院：计算机科学与工程学院
*     - 学校：大连民族学院
*/
#define _GRAPHICS_H_

/**********************************函数声明**********************************/

/*绘制直线*/
void DrawLine(HDC hdc, int x1, int y1, int x2, int y2, int lineStyle, int lineWight, COLORREF lineColor);

/*绘制棋盘线*/
void DrawChessBoardLine(HDC hdc, int x1, int y1, int x2, int y2);

/*绘制字符串*/
void DrawString(HDC hdc, char *str, COLORREF textColor, COLORREF backgroundColor,
				COLORREF borderColor, int borderStyle, int borderWeight,
				int fontHeight, int fontWidth, int fontWeight, DWORD fontFamily, char* fontName,
				int offsetX, int offsetY);

/*绘制矩形*/
void DrawRect(HDC hdc, int left, int top, int right, int bottom, int borderStyle, int borderWidth, COLORREF borderColor, COLORREF insideColor);

/*绘制圆形*/
void DrawCircle(HDC hdc, int radius, int centerX, int centerY, int borderStyle, int borderWidth, COLORREF borderColor, COLORREF insideColor);

/*绘制棋盘*/
void DrawChessBoard(HDC hdc, struct ChessBoard *cp);

/*绘制光标*/
void DrawCursor(HDC hdc, struct ChessPos cursor, char player);

/*绘制棋子*/
void DrawChess(HDC hdc, char chessType, struct ChessPos pos);

/*绘制所有棋子*/
void DrawAllChess(HDC hdc, struct ChessBoard *cp);

/*改变控制台窗口的大小和位置*/
void SetWindowSize(int contentWidth, int contentHeight, int width, int height, int left, int top, HWND zIndex);

/*刷新指定坐标的图像*/
void RefreshPos(HDC hdc, HDC hMemDc, struct ChessBoard *cp, struct ChessPos pos);

/*********************************预处理结束*********************************/
#endif