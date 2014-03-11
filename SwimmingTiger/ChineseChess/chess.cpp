/**
* @brief �й����������������庯��ʵ��
* 
* - ������Ϣ
*     - ���ߣ����ݺ�
*     - �༶�����131��
*     - ѧԺ���������ѧ�빤��ѧԺ
*     - ѧУ����������ѧԺ
*/
#include <stdio.h>
#include <conio.h>
#include <windows.h>
#include "chess.h"
#include "graphics.h"
#include "style.h"

/**
* @brief ������
* 
* ��������ʱִ�У����Ƴ���ִ������
*/
int main()
{
    struct ChessBoard mainChessBoard;
    ChessBoard *cp; //ָ�������̵�ָ��

    cp = &mainChessBoard;
    
    //��ʼ����������
    InitChessBoard(cp, PLY_BOTH);

    //�ı����̨���ڵĴ�С��λ�ã���ʹ���������ö�����ֹ���ڱ��������ڵ�סʹ���Ƶ�ͼ����ʧ��
    SetWindowSize(CONSOLE_CONTENT_WIDTH, CONSOLE_CONTENT_HEIGHT, CONSOLE_WINDOW_WIDTH, CONSOLE_WINDOW_HEIGHT, CONSOLE_WINDOW_LEFT, CONSOLE_WINDOW_TOP, HWND_TOPMOST);
    //��������
	DrawChessBoard();
    //������������
    DrawAllChessPiece(cp);
    
    getch();
    return 0;
}

/**
* @brief ��ʼ������
*/
void InitChessBoard(struct ChessBoard *cp, enum Player player)
{
    //�������
    memset(cp, CHESS_NULL, sizeof(*cp));

    //�ڷź췽����
    cp->map[0][0] = CHESS_K_JU;
    cp->map[0][1] = CHESS_K_MA;
    cp->map[0][2] = CHESS_K_XIANG;
    cp->map[0][3] = CHESS_K_SHI;
    cp->map[0][4] = CHESS_K_JIANG;
    cp->map[0][5] = CHESS_K_SHI;
    cp->map[0][6] = CHESS_K_XIANG;
    cp->map[0][7] = CHESS_K_MA;
    cp->map[0][8] = CHESS_K_JU;

    cp->map[2][1] = CHESS_K_PAO;
    cp->map[2][7] = CHESS_K_PAO;

    cp->map[3][0] = CHESS_K_JU;
    cp->map[3][2] = CHESS_K_JU;
    cp->map[3][4] = CHESS_K_JU;
    cp->map[3][6] = CHESS_K_JU;
    cp->map[3][8] = CHESS_K_JU;
    
    //�ڷźڷ�����
    cp->map[9][0] = CHESS_K_JU;
    cp->map[9][1] = CHESS_K_MA;
    cp->map[9][2] = CHESS_K_XIANG;
    cp->map[9][3] = CHESS_K_SHI;
    cp->map[9][4] = CHESS_K_JIANG;
    cp->map[9][5] = CHESS_K_SHI;
    cp->map[9][6] = CHESS_K_XIANG;
    cp->map[9][7] = CHESS_K_MA;
    cp->map[9][8] = CHESS_K_JU;

    cp->map[7][1] = CHESS_K_PAO;
    cp->map[7][7] = CHESS_K_PAO;

    cp->map[6][0] = CHESS_K_JU;
    cp->map[6][2] = CHESS_K_JU;
    cp->map[6][4] = CHESS_K_JU;
    cp->map[6][6] = CHESS_K_JU;
    cp->map[6][8] = CHESS_K_JU;

    //�������
    cp->player = player;
}