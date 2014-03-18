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
#include <math.h>
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
* 红黑方列名不同，红方从右往左数为一到九（用汉字），黑方从左往右数为1到9（用阿拉伯数字）
* 
* 结果存入指针 char *result 中，失败得到空字符串。
*/
void GetRowName(char row, char player, char *result)
{
    //红方列名
    if (player == PLY_RED)
    {
        switch (row)
        {
        case 8:
            strcpy(result, "一");
            break;
        case 7:
            strcpy(result, "二");
            break;
        case 6:
            strcpy(result, "三");
            break;
        case 5:
            strcpy(result, "四");
            break;
        case 4:
            strcpy(result, "五");
            break;
        case 3:
            strcpy(result, "六");
            break;
        case 2:
            strcpy(result, "七");
            break;
        case 1:
            strcpy(result, "八");
            break;
        case 0:
            strcpy(result, "九");
            break;
        default:
            strcpy(result, "");
            break;
        }
    }
    else if (player == PLY_BLACK)
    {
        switch (row)
        {
        case 0:
            strcpy(result, "1");
            break;
        case 1:
            strcpy(result, "2");
            break;
        case 2:
            strcpy(result, "3");
            break;
        case 3:
            strcpy(result, "4");
            break;
        case 4:
            strcpy(result, "5");
            break;
        case 5:
            strcpy(result, "6");
            break;
        case 6:
            strcpy(result, "7");
            break;
        case 7:
            strcpy(result, "8");
            break;
        case 8:
            strcpy(result, "9");
            break;
        default:
            strcpy(result, "");
            break;
        }
    }
}

/**
* @brief 获取步数记法
* 
* 红黑方记法不同，红方为一到九（用汉字），黑方为1到9（用阿拉伯数字）
* 
* 例：走了5步，红方得到“五”，黑方得到5。
* 
* 结果存入指针 char *result 中，失败得到空字符串。
*/
void GetStepName(char step, char player, char *result)
{
    //红方步名
    if (player == PLY_RED)
    {
        switch (step)
        {
        case 1:
            strcpy(result, "一");
            break;
        case 2:
            strcpy(result, "二");
            break;
        case 3:
            strcpy(result, "三");
            break;
        case 4:
            strcpy(result, "四");
            break;
        case 5:
            strcpy(result, "五");
            break;
        case 6:
            strcpy(result, "六");
            break;
        case 7:
            strcpy(result, "七");
            break;
        case 8:
            strcpy(result, "八");
            break;
        case 9:
            strcpy(result, "九");
            break;
        //棋盘共十行，只可能从进一到进九
        default:
            strcpy(result, "");
            break;
        }
    }
    else if (player == PLY_BLACK)
    {
        switch (step)
        {
        case 1:
            strcpy(result, "1");
            break;
        case 2:
            strcpy(result, "2");
            break;
        case 3:
            strcpy(result, "3");
            break;
        case 4:
            strcpy(result, "4");
            break;
        case 5:
            strcpy(result, "5");
            break;
        case 6:
            strcpy(result, "6");
            break;
        case 7:
            strcpy(result, "7");
            break;
        case 8:
            strcpy(result, "8");
            break;
        case 9:
            strcpy(result, "9");
            break;
        default:
            strcpy(result, "");
            break;
        }
    }
}


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
    char player; //走子玩家
    char success = 0;
    char rowChessSum = 0;
    
    type = GetChessType(cp, sourPos);
    GetChessManualName(type, name); //例：车
    rowChessSum = RowChessCount(cp, type, sourPos.row);
    player = GetChessPlayer(type);

    //欲走棋子不存在
    if (type == CHESS_NULL)
    {
        printErr("ChessMoveToManual(): 棋盘异常，欲走动的棋子丢失（请先调用该函数再移动棋子位置）\n");
        success = 0;
    }
    //无法取得棋子名
    else if (strlen(name) == 0)
    {
        success = 0;
    }
    //统计数据异常
    else if (rowChessSum < 1)
    {
        printErr("ChessMoveToManual(): 棋盘异常，欲走动的棋子丢失（请先调用该函数再移动棋子位置）\n");
        success = 0;
    }
    //该列无重子，用普通记法
    else if (rowChessSum == 1)
    {
        success = 1;

        //平移
        if (sourPos.line == destPos.line)
        {
            GetRowName(sourPos.row, player, sourName); //例：车三
            strcpy(actionName, "平"); //例：车三平
            GetRowName(destPos.row, player, destName); //例：车三平一
        }
        //进退
        else
        {
            GetRowName(sourPos.row, player, sourName); //例：车三

            if ((player==PLY_RED && destPos.line-sourPos.line<0) || (player==PLY_BLACK && destPos.line-sourPos.line>0))
            {
                strcpy(actionName, "进"); //例：车三进
            }
            else
            {
                strcpy(actionName, "退"); //例：车三退
            }

            //走斜线棋子，destName为进退到的列名
            if (type == CHESS_R_SHI || type == CHESS_K_SHI ||
                type == CHESS_R_MA || type == CHESS_K_MA ||
                type == CHESS_R_XIANG || type == CHESS_K_XIANG)
            {
                
            }
            //走直线棋子，destName为进退行数
            else
            {
                GetStepName(abs(destPos.line-sourPos.line), player, destName); //例：车三退二（第三列车退两行）
            }
        }
    }
    //该列有重子且非兵/卒，记例：前马进五，后马进五
    else if (rowChessSum == 2 && type != CHESS_R_BING && type != CHESS_K_ZU)
    {
        
    }

    if (success)
    {
        sprintf(result, "%s%s%s%s", name, sourName, actionName, destName);
    }

    return success;
}