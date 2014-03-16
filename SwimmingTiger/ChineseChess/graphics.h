#ifndef _GRAPHICS_H_
/**
* @brief �й�������Ϸ��ͼ��������
* 
* - ������Ϣ
*     - ���ߣ����ݺ�
*     - �༶�����131��
*     - ѧԺ���������ѧ�빤��ѧԺ
*     - ѧУ����������ѧԺ
*/
#define _GRAPHICS_H_

/**********************************��������**********************************/

/*����ֱ��*/
void DrawLine(HDC hdc, int x1, int y1, int x2, int y2, int lineStyle, int lineWight, COLORREF lineColor);

/*����������*/
void DrawChessBoardLine(HDC hdc, int x1, int y1, int x2, int y2);

/*�����ַ���*/
void DrawString(HDC hdc, char *str, COLORREF textColor, COLORREF backgroundColor,
				COLORREF borderColor, int borderStyle, int borderWeight,
				int fontHeight, int fontWidth, int fontWeight, DWORD fontFamily, char* fontName,
				int offsetX, int offsetY);

/*���ƾ���*/
void DrawRect(HDC hdc, int left, int top, int right, int bottom, int borderStyle, int borderWidth, COLORREF borderColor, COLORREF insideColor);

/*����Բ��*/
void DrawCircle(HDC hdc, int radius, int centerX, int centerY, int borderStyle, int borderWidth, COLORREF borderColor, COLORREF insideColor);

/*��������*/
void DrawChessBoard(HDC hdc, struct ChessBoard *cp);

/*���ƹ��*/
void DrawCursor(HDC hdc, struct ChessPos cursor, char player);

/*��������*/
void DrawChess(HDC hdc, char chessType, struct ChessPos pos);

/*������������*/
void DrawAllChess(HDC hdc, struct ChessBoard *cp);

/*�ı����̨���ڵĴ�С��λ��*/
void SetWindowSize(int contentWidth, int contentHeight, int width, int height, int left, int top, HWND zIndex);

/*ˢ��ָ�������ͼ��*/
void RefreshPos(HDC hdc, HDC hMemDc, struct ChessBoard *cp, struct ChessPos pos);

/*********************************Ԥ�������*********************************/
#endif