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

/*���ƾ���*/
void DrawRect(int left, int top, int right, int bottom, int borderStyle, int borderWight, COLORREF borderColor, COLORREF insideColor);

/*����Բ��*/
void DrawCircle(int radius, int centerX, int centerY, int borderStyle, int borderWight, COLORREF borderColor, COLORREF insideColor);

/*��������*/
void DrawChessBoard();

/*��������*/
void DrawChessPiece(char chessType, int line, int row);

/*������������*/
void DrawAllChessPiece(struct ChessBoard *cp);

/*�ı����̨���ڵĴ�С��λ��*/
void SetWindowSize(int contentWidth, int contentHeight, int width, int height, int left, int top, HWND zIndex);

/*********************************Ԥ�������*********************************/
#endif