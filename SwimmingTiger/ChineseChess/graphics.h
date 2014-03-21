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
void DrawLine(int x1, int y1, int x2, int y2, int lineStyle, int lineWight, COLORREF lineColor);

/*����������*/
void DrawChessBoardLine(int x1, int y1, int x2, int y2);

/*�����ַ���*/
void DrawString(char *str, COLORREF textColor, COLORREF backgroundColor,
				COLORREF borderColor, int borderStyle, int borderWeight,
				int fontHeight, int fontWidth, int fontWeight, DWORD fontFamily, char* fontName,
				int offsetX, int offsetY);

/*���ƾ���*/
void DrawRect(int left, int top, int right, int bottom, int borderWidth, int borderStyle, COLORREF borderColor, COLORREF insideColor);

/*����Բ��*/
void DrawCircle(int radius, int centerX, int centerY, int borderStyle, int borderWidth, COLORREF borderColor, COLORREF insideColor);

/*��������*/
void DrawChessBoard(struct ChessBoard *cp);

/*���ƹ��*/
void DrawCursor(struct ChessPos cursor, char player);

/*��������*/
void DrawChess(char chessType, struct ChessPos pos);

/*������������*/
void DrawAllChess(struct ChessBoard *cp);

/*�ı����̨���ڵĴ�С��λ��*/
void SetWindowSize(int contentWidth, int contentHeight, int width, int height, int left, int top, HWND zIndex);

/*********************************Ԥ�������*********************************/
#endif