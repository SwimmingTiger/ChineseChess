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
#include "graphics.h"
#include "chess.h"

/**
* @brief ������
* 
* ��������ʱִ�У����Ƴ���ִ������
*/
int main()
{
    ChessBoard mainChessBoard;
    ChessBoard *cp; //ָ�������̵�ָ��

    cp = &mainChessBoard;
    
    InitChessBoard(cp, PL_BOTH);
	DrawChessBoard();
    
    getch();
    return 0;
}

/**
* @brief ��ʼ������
*/
void InitChessBoard(ChessBoard *cp, enum Player player)
{
    //�������
    memset(cp, CT_NULL, sizeof(*cp));

    //�ڷź췽����
    cp->map[0][0] = CT_K_JU;
    cp->map[0][1] = CT_K_MA;
    cp->map[0][2] = CT_K_XIANG;
    cp->map[0][3] = CT_K_SHI;
    cp->map[0][4] = CT_K_JIANG;
    cp->map[0][5] = CT_K_SHI;
    cp->map[0][6] = CT_K_XIANG;
    cp->map[0][7] = CT_K_MA;
    cp->map[0][8] = CT_K_JU;

    cp->map[2][1] = CT_K_PAO;
    cp->map[2][7] = CT_K_PAO;

    cp->map[3][0] = CT_K_JU;
    cp->map[3][2] = CT_K_JU;
    cp->map[3][4] = CT_K_JU;
    cp->map[3][6] = CT_K_JU;
    cp->map[3][8] = CT_K_JU;
    
    //�ڷźڷ�����
    cp->map[9][0] = CT_K_JU;
    cp->map[9][1] = CT_K_MA;
    cp->map[9][2] = CT_K_XIANG;
    cp->map[9][3] = CT_K_SHI;
    cp->map[9][4] = CT_K_JIANG;
    cp->map[9][5] = CT_K_SHI;
    cp->map[9][6] = CT_K_XIANG;
    cp->map[9][7] = CT_K_MA;
    cp->map[9][8] = CT_K_JU;

    cp->map[7][1] = CT_K_PAO;
    cp->map[7][7] = CT_K_PAO;

    cp->map[6][0] = CT_K_JU;
    cp->map[6][2] = CT_K_JU;
    cp->map[6][4] = CT_K_JU;
    cp->map[6][6] = CT_K_JU;
    cp->map[6][8] = CT_K_JU;

    //�������
    cp->player = player;
}