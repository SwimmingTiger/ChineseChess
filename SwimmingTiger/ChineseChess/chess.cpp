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
#include <math.h>
#include "chess.h"
#include "graphics.h"
#include "style.h"
#include "control.h"
#include "debug.h"

/**
* @brief 主函数
* 
* 程序启动时执行，控制程序执行流程
*/
int main()
{
    struct ChessBoard mainChessBoard;
    struct ChessBoard *cp; //指向主棋盘的指针
    
    cp = &mainChessBoard;
    
    //初始化棋盘数据
    InitChessBoard(cp, PLY_BOTH);
    
    //改变控制台窗口的大小和位置，并使窗口总是置顶（防止窗口被其他窗口挡住使绘制的图形消失）
    SetWindowSize(CONSOLE_CONTENT_WIDTH, CONSOLE_CONTENT_HEIGHT, CONSOLE_WINDOW_WIDTH, CONSOLE_WINDOW_HEIGHT, CONSOLE_WINDOW_LEFT, CONSOLE_WINDOW_TOP, HWND_TOPMOST);
    //设置窗口标题
    SetConsoleTitle(CONSOLE_WINDOW_TITLE);
    //绘制棋盘
    DrawChessBoard(cp);
    //绘制所有棋子
    DrawAllChess(cp);
    
    StartGame(cp);

    return 0;
}

/**
* @brief 游戏流程控制函数
*/
void StartGame(struct ChessBoard *cp)
{
	char action = ACT_UNKNOWN;
    signed char key = -1;
    struct KeyState keyStat={-1, -1, -1, -1};


    while (action != ACT_STOP_GAME)
    {
        key = getch();
        action = ParseKey(key, &keyStat);

        switch (action)
        {
        case ACT_KEY_UP:
            if (cp->activeCursor->line > 0)
            {
                cp->activeCursor->line--;
            }
            break;

        case ACT_KEY_DOWN:
            if (cp->activeCursor->line < CHESSBOARD_LINE-1)
            {
                cp->activeCursor->line++;
            }
            break;

        case ACT_KEY_LEFT:
            if (cp->activeCursor->row > 0)
            {
                cp->activeCursor->row--;
            }
            break;

        case ACT_KEY_RIGHT:
            if (cp->activeCursor->row < CHESSBOARD_ROW-1)
            {
                cp->activeCursor->row++;
            }
            break;

        case ACT_KEY_LOCK:
            //棋子未锁定则锁定棋子
            if (cp->chessLocked == 0)
            {
                //只有棋子属于当前玩家才能锁定
                if (cp->activePlayer == GetChessPlayer(GetChessType(cp, *cp->activeCursor)))
                {
                    cp->chessLocked = 1;
                    cp->lockedCursor = *cp->activeCursor;
                }
            }
            //已锁定且位置未变，则解除锁定
            else if (MatchPos(cp->lockedCursor, cp->activeCursor->line, cp->activeCursor->row))
            {
                cp->chessLocked = 0;
            }
            //已锁定且位置改变，尝试移动棋子
            else
            {
                //如果移动位置是玩家自己的棋子，则切换锁定的棋子
                if (cp->activePlayer == GetChessPlayer(GetChessType(cp, *cp->activeCursor)))
                {
                    cp->chessLocked = 1;
                    cp->lockedCursor = *cp->activeCursor;
                }
                //棋子移动成功则解锁光标，切换活动用户
                else if (MoveChess(cp, cp->lockedCursor, *cp->activeCursor, cp->activePlayer))
                {
                    cp->chessLocked = 0;
                    SwitchActivePlayer(cp);
                }
                //棋子未移动，不动作
                else
                {
                    
                }
            }
            break;

        case ACT_REFRESH_SCREEN:
            //绘制棋盘
            DrawChessBoard(cp);
            //绘制所有棋子
            DrawAllChess(cp);
            break;

        default:
            break;
        }

        DrawChessBoard(cp);
        DrawAllChess(cp);
    }
}

/**
* @brief 初始化棋盘
*/
void InitChessBoard(struct ChessBoard *cp, enum Player player)
{
    //清空棋盘
    memset(cp, CHESS_NULL, sizeof(cp->map));
    
    //摆放红方棋子
    PutChess(cp, 0, 0, CHESS_R_JU);
    PutChess(cp, 0, 1, CHESS_R_MA);
    PutChess(cp, 0, 2, CHESS_R_XIANG);
    PutChess(cp, 0, 3, CHESS_R_SHI);
    PutChess(cp, 0, 4, CHESS_R_SHUAI);
    PutChess(cp, 0, 5, CHESS_R_SHI);
    PutChess(cp, 0, 6, CHESS_R_XIANG);
    PutChess(cp, 0, 7, CHESS_R_MA);
    PutChess(cp, 0, 8, CHESS_R_JU);
    
    PutChess(cp, 2, 1, CHESS_R_PAO);
    PutChess(cp, 2, 7, CHESS_R_PAO);
    
    PutChess(cp, 3, 0, CHESS_R_BING);
    PutChess(cp, 3, 2, CHESS_R_BING);
    PutChess(cp, 3, 4, CHESS_R_BING);
    PutChess(cp, 3, 6, CHESS_R_BING);
    PutChess(cp, 3, 8, CHESS_R_BING);
    
    //摆放黑方棋子
    PutChess(cp, 9, 0, CHESS_K_JU);
    PutChess(cp, 9, 1, CHESS_K_MA);
    PutChess(cp, 9, 2, CHESS_K_XIANG);
    PutChess(cp, 9, 3, CHESS_K_SHI);
    PutChess(cp, 9, 4, CHESS_K_JIANG);
    PutChess(cp, 9, 5, CHESS_K_SHI);
    PutChess(cp, 9, 6, CHESS_K_XIANG);
    PutChess(cp, 9, 7, CHESS_K_MA);
    PutChess(cp, 9, 8, CHESS_K_JU);
    
    PutChess(cp, 7, 1, CHESS_K_PAO);
    PutChess(cp, 7, 7, CHESS_K_PAO);
    
    PutChess(cp, 6, 0, CHESS_K_ZU);
    PutChess(cp, 6, 2, CHESS_K_ZU);
    PutChess(cp, 6, 4, CHESS_K_ZU);
    PutChess(cp, 6, 6, CHESS_K_ZU);
    PutChess(cp, 6, 8, CHESS_K_ZU);
    
    //设置玩家
    cp->player = player;
    //象棋规则：红方先手
    cp->activePlayer = PLY_RED;
    cp->activeCursor = &cp->cursorRed;

    //光标初始化
    cp->cursorRed = CreatePos(2, 4);
    cp->cursorBlack = CreatePos(7, 4);
    //棋子未锁定
    cp->chessLocked = 0;
}

/**
* @brief 取得棋子名
*/
void GetChessName(char chessType, char *ipName)
{
    switch (chessType)
    {
    case CHESS_R_SHUAI:
        strcpy(ipName, "帥");
        break;
    case CHESS_R_JU:
        strcpy(ipName, "車");
        break;
    case CHESS_R_MA:
        strcpy(ipName, "馬");
        break;
    case CHESS_R_PAO:
        strcpy(ipName, "炮");
        break;
    case CHESS_R_XIANG:
        strcpy(ipName, "相");
        break;
    case CHESS_R_SHI:
        strcpy(ipName, "仕");
        break;
    case CHESS_R_BING:
        strcpy(ipName, "兵");
        break;
        
    case CHESS_K_JIANG:
        strcpy(ipName, "將");
        break;
    case CHESS_K_JU:
        strcpy(ipName, "車");
        break;
    case CHESS_K_MA:
        strcpy(ipName, "馬");
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
* @brief 创建棋子坐标结构
*/
struct ChessPos CreatePos(char line, char row)
{
    struct ChessPos pos;

    pos.line = line;
    pos.row = row;

    return pos;
}

/**
* @brief 比较棋子坐标与给定坐标是否相等
*/
char MatchPos(struct ChessPos pos, char line, char row)
{
    char eq;

    if (pos.line == line && pos.row == row)
    {
        eq = 1;
    }
    else
    {
        eq = 0;
    }

    return eq;
}

/**
* @brief 取得棋子类型
*/
char GetChessType(struct ChessBoard *cp, struct ChessPos pos)
{
    char chessType = CHESS_NULL;

    if (pos.line < CHESSBOARD_LINE && pos.row < CHESSBOARD_ROW)
    {
        chessType = cp->map[pos.line][pos.row];
    }
    else
    {
        errPrint("GetChessType(): 坐标异常，行号或列号超出预期\n");
    }
    
    return chessType;
}

/**
* @brief 设置棋子类型
*/
void SetChessType(struct ChessBoard *cp, struct ChessPos pos, char chessType)
{
    if (pos.line < CHESSBOARD_LINE && pos.row < CHESSBOARD_ROW)
    {
        cp->map[pos.line][pos.row] = chessType;
    }
    else
    {
        errPrint("SetChessType(): 坐标异常，行号或列号超出预期\n");
    }
}

/**
* @brief 取得棋子所属的玩家
* 
* 返回值为 enum Player 类型，棋子为 CHESS_NULL 时返回 PLY_BOTH。
*/
char GetChessPlayer(char chessType)
{
    char player = PLY_BOTH;

    if (chessType >= CHESS_R_SHUAI && chessType <= CHESS_R_BING)
    {
        player = PLY_RED;
    }
    else if (chessType >= CHESS_K_JIANG && chessType <= CHESS_K_ZU)
    {
        player = PLY_BLACK;
    }

    return player;
}

/**
* @brief 切换当前活动玩家
*/
void SwitchActivePlayer(struct ChessBoard *cp)
{
    if (cp->activePlayer == PLY_RED)
    {
        cp->activePlayer = PLY_BLACK;
        cp->activeCursor = &cp->cursorBlack;
    }
    else
    {
        cp->activePlayer = PLY_RED;
        cp->activeCursor = &cp->cursorRed;
    }
}

/**
* @brief 摆放棋子到指定位置
* 
* 该函数与SetChessType()功能相同，但该函数直接给出棋子坐标，
* 不使用坐标结构体。
*/
void PutChess(struct ChessBoard *cp, char line, char row, char chessType)
{
    if (line < CHESSBOARD_LINE && row < CHESSBOARD_ROW)
    {
        cp->map[line][row] = chessType;
    }
    else
    {
        errPrint("PutChess(): 坐标异常，行号或列号超出预期\n");
    }
}

/**
* @brief 统计起点到终点沿途的棋子个数（不包括起点和终点）
* 
* 本函数仅能作用于水平或竖直直线，不能统计斜线上的棋子
*/
int ChessCount(struct ChessBoard *cp, struct ChessPos destPos, struct ChessPos sourPos)
{
    int num = 0;
    int i;
    int posStart;
    int posEnd;
    struct ChessPos pos;
    
    //非水平或竖直直线无法统计
    if (destPos.line != sourPos.line && destPos.row != sourPos.row)
    {
        num = -1;
    }
    //开始和结束在同一点上，无法统计
    else if (destPos.line == sourPos.line && destPos.row == sourPos.row)
    {
        num = -1;
    }
    //横线
    else if (destPos.line == sourPos.line)
    {
        if (destPos.row < sourPos.row)
        {
            posStart = destPos.row + 1;
            posEnd = sourPos.row - 1;
        }
        else
        {
            posStart = sourPos.row + 1;
            posEnd = destPos.row - 1;
        }
        for (i = posStart; i <= posEnd; i++)
        {
            pos.line = sourPos.line;
            pos.row = i;

            if (GetChessType(cp, pos) != CHESS_NULL)
            {
                num++;
            }
        }
    }
    //竖线
    else if (destPos.row == sourPos.row)
    {
        if (destPos.line < sourPos.line)
        {
            posStart = destPos.line + 1;
            posEnd = sourPos.line - 1;
        }
        else
        {
            posStart = sourPos.line + 1;
            posEnd = destPos.line - 1;
        }
        for (i = posStart; i <= posEnd; i++)
        {
            pos.row = sourPos.row;
            pos.line = i;

            if (GetChessType(cp, pos) != CHESS_NULL)
            {
                num++;
            }
        }
    }

    return num;
}

/**
* @brief 移动棋子
* 
* 成功移动返回1，移动失败或不允许移动返回0
*/
char MoveChess(struct ChessBoard *cp, struct ChessPos sourPos, struct ChessPos destPos, char player)
{
    char moveSuccess = 0;
    char destType;
    char sourType;
    
    destType = GetChessType(cp, destPos);
    sourType = GetChessType(cp, sourPos);

    //没有棋子可供移动
    if (sourType == CHESS_NULL)
    {
        moveSuccess = 0;
    }
    //原地移动棋子
    else if (destPos.line == sourPos.line && destPos.row == sourPos.row)
    {
        moveSuccess = 0;
    }
    //移动不属于自己的棋子
    else if (GetChessPlayer(sourType) != player)
    {
        moveSuccess = 0;
    }
    //试图吃掉自己的棋子
    else if (GetChessPlayer(destType) == player)
    {
        moveSuccess = 0;
    }
    else
    {
        switch (sourType)
        {
        //红方帅
        case CHESS_R_SHUAI:
            //在九宫外
            if (sourPos.line > 2 || sourPos.row < 3 || sourPos.row > 5)
            {
                errPrint("MoveChess(): 棋子位置异常，红方帅在九宫外\n");
                moveSuccess = 0;
            }
            //试图走出九宫
            else if (destPos.line > 2 || destPos.row < 3 || destPos.row > 5)
            {
                //试图吃掉对方将
                if (GetChessType(cp, destPos) == CHESS_K_JIANG && ChessCount(cp, sourPos, destPos) == 0)
                {
                    moveSuccess = 1;
                }
                else
                {
                    moveSuccess = 0;
                }
            }
            //试图一次走多格
            else if (abs(destPos.line - sourPos.line) > 1 || abs(destPos.row - sourPos.row) > 1)
            {
                moveSuccess = 0;
            }
            //试图走斜线
            else if (destPos.line != sourPos.line && destPos.row != sourPos.row)
            {
                moveSuccess = 0;
            }
            //棋子可移动
            else
            {
                moveSuccess = 1;
            }
            break;
            
        //黑方将
        case CHESS_K_JIANG:
            //在九宫外
            if (sourPos.line < 7 || sourPos.line > 9 || sourPos.row < 3 || sourPos.row > 5)
            {
                errPrint("MoveChess(): 棋子位置异常，黑方将在九宫外\n");
                moveSuccess = 0;
            }
            //试图走出九宫
            else if (destPos.line < 7 || destPos.line > 9 || destPos.row < 3 || destPos.row > 5)
            {
                //试图吃掉对方帅
                if (GetChessType(cp, destPos) == CHESS_R_SHUAI && ChessCount(cp, sourPos, destPos) == 0)
                {
                    moveSuccess = 1;
                }
                else
                {
                    moveSuccess = 0;
                }
            }
            //试图一次走多格
            else if (abs(destPos.line - sourPos.line) > 1 || abs(destPos.row - sourPos.row) > 1)
            {
                moveSuccess = 0;
            }
            //试图走斜线
            else if (destPos.line != sourPos.line && destPos.row != sourPos.row)
            {
                moveSuccess = 0;
            }
            //棋子可移动
            else
            {
                moveSuccess = 1;
            }
            break;

        //红黑方车
        case CHESS_R_JU:
        case CHESS_K_JU:
            //试图走斜线
            if (destPos.line != sourPos.line && destPos.row != sourPos.row)
            {
                moveSuccess = 0;
            }
            //被遮挡
            else if (ChessCount(cp, sourPos, destPos) != 0)
            {
                moveSuccess = 0;
            }
            //棋子可移动
            else
            {
                moveSuccess = 1;
            }
            break;

        //红黑方炮
        case CHESS_R_PAO:
        case CHESS_K_PAO:
            //试图走斜线
            if (destPos.line != sourPos.line && destPos.row != sourPos.row)
            {
                moveSuccess = 0;
            }
            //不吃子且被遮挡
            else if (GetChessType(cp, destPos) == CHESS_NULL && ChessCount(cp, sourPos, destPos) != 0)
            {
                moveSuccess = 0;
            }
            //吃子但中间隔的棋子不是一个
            else if (GetChessType(cp, destPos) != CHESS_NULL && ChessCount(cp, sourPos, destPos) != 1)
            {
                moveSuccess = 0;
            }
            //棋子可移动
            else
            {
                moveSuccess = 1;
            }
            break;

        default:
            break;
        }

        if (moveSuccess)
        {
            SetChessType(cp, sourPos, CHESS_NULL);
            SetChessType(cp, destPos, sourType);
        }
    }

    return moveSuccess;
}