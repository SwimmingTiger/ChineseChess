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
void DrawLine(int x1, int y1, int x2, int y2, int lineStyle, int lineWight, COLORREF lineColor);

/*绘制棋盘线*/
void DrawChessBoardLine(int x1, int y1, int x2, int y2);

/*绘制矩形*/
void DrawRect(int left, int top, int right, int bottom, int borderStyle, int borderWight, COLORREF borderColor, COLORREF insideColor);

/*绘制圆形*/
void DrawCircle(int radius, int centerX, int centerY, int borderStyle, int borderWight, COLORREF borderColor, COLORREF insideColor);

/*绘制棋盘*/
void DrawChessBoard();

/*绘制棋子*/
void DrawChessPiece(char chessType, int line, int row);

/*绘制所有棋子*/
void DrawAllChessPiece(struct ChessBoard *cp);

/*改变控制台窗口的大小和位置*/
void SetWindowSize(int contentWidth, int contentHeight, int width, int height, int left, int top, HWND zIndex);

/*********************************预处理结束*********************************/
#endif