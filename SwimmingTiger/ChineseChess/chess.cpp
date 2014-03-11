/**
* @brief 中国象棋主函数及走棋函数实现
* 
* - 作者信息
*     - 作者：彭逸豪
*     - 班级：软件131班
*     - 学院：计算机科学与工程学院
*     - 学校：大连民族学院
*/
#include <stdio.h>
#include <conio.h>
#include <windows.h>
#include "graphics.h"
#include "chess.h"

/**
* @brief 主函数
* 
* 程序启动时执行，控制程序执行流程
*/
int main()
{
    ChessBoard mainChessBoard;
    ChessBoard *cp; //指向主棋盘的指针

    cp = &mainChessBoard;
    
    InitChessBoard(cp, PLY_BOTH);
	DrawChessBoard();
    
    getch();
    return 0;
}

/**
* @brief 初始化棋盘
*/
void InitChessBoard(ChessBoard *cp, enum Player player)
{
    //清空棋盘
    memset(cp, CHESS_NULL, sizeof(*cp));

    //摆放红方棋子
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
    
    //摆放黑方棋子
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

    //设置玩家
    cp->player = player;
}