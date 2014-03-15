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
#include <math.h>
#include "chess.h"
#include "graphics.h"
#include "style.h"
#include "control.h"

/**
* @brief ������
* 
* ��������ʱִ�У����Ƴ���ִ������
*/
int main()
{
    struct ChessBoard mainChessBoard;
    struct ChessBoard *cp; //ָ�������̵�ָ��
    
    cp = &mainChessBoard;
    
    //��ʼ����������
    InitChessBoard(cp, PLY_BOTH);
    
    //�ı����̨���ڵĴ�С��λ�ã���ʹ���������ö�����ֹ���ڱ��������ڵ�סʹ���Ƶ�ͼ����ʧ��
    SetWindowSize(CONSOLE_CONTENT_WIDTH, CONSOLE_CONTENT_HEIGHT, CONSOLE_WINDOW_WIDTH, CONSOLE_WINDOW_HEIGHT, CONSOLE_WINDOW_LEFT, CONSOLE_WINDOW_TOP, HWND_TOPMOST);
    //��������
    DrawChessBoard(cp);
    //������������
    DrawAllChess(cp);
    
    StartGame(cp);

    return 0;
}

/**
* @brief ��Ϸ���̿��ƺ���
*/
void StartGame(struct ChessBoard *cp)
{
	char action = ACT_UNKNOWN;
    char chessLocked = 0;
    struct ChessPos lockedCursor;
    struct ChessPos *cursor;
    signed char key = -1;
    struct KeyState keyStat={-1, -1, -1, -1};


    while (action != ACT_STOP_GAME)
    {
        key = getch();
        action = ParseKey(key, &keyStat);
        cursor = GetActiveCursor(cp);

        switch (action)
        {
        case ACT_KEY_UP:
            break;
        case ACT_KEY_DOWN:
            break;
        case ACT_KEY_LEFT:
            break;
        case ACT_KEY_RIGHT:
            break;
        case ACT_KEY_LOCK:
            //����δ��������������
            if (chessLocked == 0)
            {
                chessLocked = 1;
                lockedCursor = *cursor;
            }
            //��������λ��δ�䣬��������
            else if (MatchPos(lockedCursor, cursor->line, cursor->row))
            {
                
            }
            break;
        }

        DrawChessBoard(cp);
        DrawAllChess(cp);
    }
}

/**
* @brief ��ʼ������
*/
void InitChessBoard(struct ChessBoard *cp, enum Player player)
{
    //�������
    memset(cp, CHESS_NULL, sizeof(cp->map));
    
    //�ڷź췽����
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
    
    //�ڷźڷ�����
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
    
    //�������
    cp->player = player;
    //������򣺺췽����
    cp->activePlayer = PLY_RED;

    //����ʼ��
    cp->cursorRed = CreatePos(2, 4);
    cp->cursorBlack = CreatePos(7, 4);
}

/**
* @brief ȡ��������
*/
void GetChessName(char chessType, char *ipName)
{
    switch (chessType)
    {
    case CHESS_R_SHUAI:
        strcpy(ipName, "��");
        break;
    case CHESS_R_JU:
        strcpy(ipName, "܇");
        break;
    case CHESS_R_MA:
        strcpy(ipName, "�R");
        break;
    case CHESS_R_PAO:
        strcpy(ipName, "��");
        break;
    case CHESS_R_XIANG:
        strcpy(ipName, "��");
        break;
    case CHESS_R_SHI:
        strcpy(ipName, "��");
        break;
    case CHESS_R_BING:
        strcpy(ipName, "��");
        break;
        
    case CHESS_K_JIANG:
        strcpy(ipName, "��");
        break;
    case CHESS_K_JU:
        strcpy(ipName, "܇");
        break;
    case CHESS_K_MA:
        strcpy(ipName, "�R");
        break;
    case CHESS_K_PAO:
        strcpy(ipName, "��");
        break;
    case CHESS_K_XIANG:
        strcpy(ipName, "��");
        break;
    case CHESS_K_SHI:
        strcpy(ipName, "ʿ");
        break;
    case CHESS_K_ZU:
        strcpy(ipName, "��");
        break;

    default:
        strcpy(ipName, "");
    }
}

/**
* @brief ������������ṹ
*/
struct ChessPos CreatePos(char line, char row)
{
    struct ChessPos pos;

    pos.line = line;
    pos.row = row;

    return pos;
}

/**
* @brief �Ƚ�������������������Ƿ����
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
* @brief ȡ����������
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
        perror("GetChessType(): �����쳣���кŻ��кų���Ԥ��\n");
    }
    
    return chessType;
}

/**
* @brief ������������
*/
void SetChessType(struct ChessBoard *cp, struct ChessPos pos, char chessType)
{
    if (pos.line < CHESSBOARD_LINE && pos.row < CHESSBOARD_ROW)
    {
        cp->map[pos.line][pos.row] = chessType;
    }
    else
    {
        perror("SetChessType(): �����쳣���кŻ��кų���Ԥ��\n");
    }
}

/**
* @brief ȡ���������������
* 
* ����ֵΪ enum Player ���ͣ�����Ϊ CHESS_NULL ʱ���� PLY_BOTH��
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
* @brief ȡ�õ�ǰ���ҹ��
*/
struct ChessPos * GetActiveCursor(struct ChessBoard *cp)
{
    struct ChessPos *cursor;

    if (cp->activePlayer == PLY_RED)
    {
        cursor = &cp->cursorRed;
    }
    else
    {
        cursor = &cp->cursorBlack;
    }

    return cursor;
}

/**
* @brief �ڷ����ӵ�ָ��λ��
* 
* �ú�����SetChessType()������ͬ�����ú���ֱ�Ӹ����������꣬
* ��ʹ������ṹ�塣
*/
void PutChess(struct ChessBoard *cp, char line, char row, char chessType)
{
    if (line < CHESSBOARD_LINE && row < CHESSBOARD_ROW)
    {
        cp->map[line][row] = chessType;
    }
    else
    {
        perror("PutChess(): �����쳣���кŻ��кų���Ԥ��\n");
    }
}

/**
* @brief �ƶ�����
* 
* �ɹ��ƶ�����1���ƶ�ʧ�ܻ������ƶ�����0
*/
char MoveChess(struct ChessBoard *cp, struct ChessPos destPos, struct ChessPos sourPos, char player)
{
    char moveSuccess = 0;
    char destType;
    char sourType;
    
    destType = GetChessType(cp, destPos);
    sourType = GetChessType(cp, sourPos);

    //û�����ӿɹ��ƶ�
    if (sourType == CHESS_NULL)
    {
        moveSuccess = 0;
    }
    //ԭ���ƶ�����
    else if (destPos.line == sourPos.line && destPos.row == sourPos.row)
    {
        moveSuccess = 0;
    }
    //�ƶ��������Լ�������
    else if (GetChessPlayer(sourType) != player)
    {
        moveSuccess = 0;
    }
    //��ͼ�Ե��Լ�������
    else if (GetChessPlayer(destType) == player)
    {
        moveSuccess = 0;
    }
    else
    {
        switch (sourType)
        {
        //�췽˧
        case CHESS_R_SHUAI:
            //�ھŹ���
            if (sourPos.line > 2 || sourPos.row < 3 || sourPos.row > 5)
            {
                perror("MoveChess(): ����λ���쳣���췽˧�ھŹ���\n");
                moveSuccess = 0;
            }
            //��ͼ�߳��Ź�
            else if (destPos.line > 2 || destPos.row < 3 || destPos.row > 5)
            {
                moveSuccess = 0;
            }
            //��ͼһ���߶��
            else if (abs(destPos.line - sourPos.line) > 1 || abs(destPos.row - sourPos.row) > 1)
            {
                moveSuccess = 0;
            }
            //��ͼ��û����ͨ�ĵط�
            else if ((MatchPos(sourPos, 0, 4) || MatchPos(sourPos, 1, 5) || MatchPos(sourPos, 2, 4) || MatchPos(sourPos, 1, 3)) &&
                     (MatchPos(destPos, 0, 4) || MatchPos(destPos, 1, 5) || MatchPos(destPos, 2, 4) || MatchPos(destPos, 1, 3)))
            {
                moveSuccess = 0;
            }
            //���ӿ��ƶ�
            else
            {
                moveSuccess = 1;
            }
            break;
            
            //�ڷ���
        case CHESS_K_JIANG:
            //�ھŹ���
            if (sourPos.line < 7 || sourPos.line > 9 || sourPos.row < 3 || sourPos.row > 5)
            {
                perror("MoveChess(): ����λ���쳣���ڷ����ھŹ���\n");
                moveSuccess = 0;
            }
            //��ͼ�߳��Ź�
            else if (destPos.line < 7 || destPos.line > 9 || destPos.row < 3 || destPos.row > 5)
            {
                moveSuccess = 0;
            }
            //��ͼһ���߶��
            else if (abs(destPos.line - sourPos.line) > 1 || abs(destPos.row - sourPos.row) > 1)
            {
                moveSuccess = 0;
            }
            //��ͼ��û����ͨ�ĵط�
            else if ((MatchPos(sourPos, 7, 4) || MatchPos(sourPos, 8, 5) || MatchPos(sourPos, 9, 4) || MatchPos(sourPos, 8, 3)) &&
                     (MatchPos(destPos, 7, 4) || MatchPos(destPos, 8, 5) || MatchPos(destPos, 9, 4) || MatchPos(destPos, 8, 3)))
            {
                moveSuccess = 0;
            }
            //���ӿ��ƶ�
            else
            {
                moveSuccess = 1;
            }
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