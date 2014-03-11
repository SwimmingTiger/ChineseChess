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
#include "chess.h"
#include "graphics.h"
#include "style.h"

/**
* @brief 主函数
* 
* 程序启动时执行，控制程序执行流程
*/
int main()
{
    struct ChessBoard mainChessBoard;
    ChessBoard *cp; //指向主棋盘的指针

    cp = &mainChessBoard;
    
    //初始化棋盘数据
    InitChessBoard(cp, PL_BOTH);

    //改变控制台窗口的大小和位置，并使窗口总是置顶（防止窗口被其他窗口挡住使绘制的图形消失）
    SetWindowSize(CHESSBOARD_WINDOW_WIDTH, CHESSBOARD_WINDOW_HEIGHT, CHESSBOARD_WINDOW_LEFT, CHESSBOARD_WINDOW_TOP, HWND_TOPMOST);
    //绘制棋盘
	DrawChessBoard();

    DrawAllChessPiece(cp);
    
    getch();
    return 0;
}

/**
* @brief 初始化棋盘
*/
void InitChessBoard(struct ChessBoard *cp, enum Player player)
{
    //清空棋盘
    memset(cp, CT_NULL, sizeof(*cp));

    //摆放红方棋子
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
    
    //摆放黑方棋子
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

    //设置玩家
    cp->player = player;
}