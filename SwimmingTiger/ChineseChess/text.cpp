/**
* @brief 中国象棋文本处理函数实现
* 
* - 作者信息
*     - 作者：彭逸豪
*     - 班级：软件131班
*     - 学院：计算机科学与工程学院
*     - 学校：大连民族学院
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "chess.h"
#include "debug.h"

/**
* @brief 取得棋子的记谱名称
*/
void GetChessManualName(char chessType, char *ipName)
{
    switch (chessType)
    {
    case CHESS_R_SHUAI:
        strcpy(ipName, "帅");
        break;
    case CHESS_R_JU:
        strcpy(ipName, "车");
        break;
    case CHESS_R_MA:
        strcpy(ipName, "马");
        break;
    case CHESS_R_PAO:
        strcpy(ipName, "炮");
        break;
    case CHESS_R_XIANG:
        strcpy(ipName, "相");
        break;
    case CHESS_R_SHI:
        strcpy(ipName, "士");
        break;
    case CHESS_R_BING:
        strcpy(ipName, "兵");
        break;
        
    case CHESS_K_JIANG:
        strcpy(ipName, "将");
        break;
    case CHESS_K_JU:
        strcpy(ipName, "车");
        break;
    case CHESS_K_MA:
        strcpy(ipName, "马");
        break;
    case CHESS_K_PAO:
        strcpy(ipName, "炮");
        break;
    case CHESS_K_XIANG:
        strcpy(ipName, "象");
        break;
    case CHESS_K_SHI:
        strcpy(ipName, "士");
        break;
    case CHESS_K_ZU:
        strcpy(ipName, "卒");
        break;

    default:
        strcpy(ipName, "");
    }
}

/**
* @brief 获取棋盘列名
* 
* 红黑方列名不同，红方
*/


/**
* @brief 将棋子走法转换成棋谱
* 
* 结果存入指针 char *result 中。
* 
* 返回值：转换成功返回1，失败返回0。
*/
char ChessMoveToManual(struct ChessBoard *cp, struct ChessPos sourPos, struct ChessPos destPos, char *result)
{
    char type; //欲走棋子类型
    char name[8]; //棋子名称
    char sourName[8]; //初始位置名称
    char destName[8]; //欲走到的位置名称
    char actionName[8]; //走子方式名称：进、退、平
    char success = 0;
    char rowChessSum = 0;

    type = GetChessType(cp, sourPos);

    //欲走棋子不存在
    if (type == CHESS_NULL)
    {
        printErr("ChessMoveToManual(): 棋盘异常，欲走动的棋子丢失（请先调用该函数再移动棋子位置）\n");
        success = 0;
    }
    else
    {
         GetChessManualName(type, name);

         //无法取得棋子名
         if (strlen(name) == 0)
         {
             success = 0;
         }
         else
         {
             rowChessSum = RowChessCount(cp, type, sourPos.row);

             //统计数据异常
             if (rowChessSum < 1)
             {
                 printErr("ChessMoveToManual(): 棋盘异常，欲走动的棋子丢失（请先调用该函数再移动棋子位置）\n");
                 success = 0;
             }
             //该列无重子，用普通记法
             else if (rowChessSum == 1)
             {
                 //平移
                 if (sourPos.line == destPos.line)
                 {
                     //strcpy();
                 }
             }
         }
    }
    
    return success;
}