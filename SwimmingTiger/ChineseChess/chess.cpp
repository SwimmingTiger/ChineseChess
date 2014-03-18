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
#include "debug.h"
#include "text.h"

/**
* @brief ������
* 
* ��������ʱִ�У����Ƴ���ִ������
*/
int main()
{
    struct ChessBoard mainChessBoard;
    struct ChessBoard *cp; //ָ�������̵�ָ��
    char action = ACT_UNKNOWN;
    signed char key = -1;
    struct KeyState keyStat={-1, -1, -1, -1};

    cp = &mainChessBoard;

    /*while (action != ACT_STOP_GAME)
    {
        key = getch();
        action = ParseKey(key, &keyStat);

        switch (action)
        {
        case 0:
            break;

        default:
            break;
        }
    }*/
    
    //��ʼ����������
    InitChessBoard(cp, PLY_BOTH);
    
    //�ı����̨���ڵĴ�С��λ�ã���ʹ���������ö�����ֹ���ڱ��������ڵ�סʹ���Ƶ�ͼ����ʧ��
    SetWindowSize(CONSOLE_CONTENT_WIDTH, CONSOLE_CONTENT_HEIGHT, CONSOLE_WINDOW_WIDTH, CONSOLE_WINDOW_HEIGHT, CONSOLE_WINDOW_LEFT, CONSOLE_WINDOW_TOP, HWND_TOPMOST);
    //���ô��ڱ���
    SetConsoleTitle(CONSOLE_WINDOW_TITLE);
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
    signed char key = -1;
    struct KeyState keyStat={-1, -1, -1, -1};
    char actionMap[GAME_CONTROL_KEY_NUM] =
    {
        ACT_KEY_UP,
        ACT_KEY_DOWN,
        ACT_KEY_LEFT,
        ACT_KEY_RIGHT,
        ACT_KEY_LOCK,
        ACT_STOP_GAME,
        ACT_REFRESH_SCREEN
    };
    struct KeyCode keyMap[GAME_CONTROL_KEY_NUM][KEYCODE_MAX_NUM] =
    {
        KEYCODE_UP,
        KEYCODE_DOWN,
        KEYCODE_LEFT,
        KEYCODE_RIGHT,
        KEYCODE_LOCK,
        KEYCODE_STOP_GAME,
        KEYCODE_REFRESH_SCREEN
    };

    while (action != ACT_STOP_GAME)
    {
        key = getch();
        action = ParseKey(key, &keyStat, actionMap, (struct KeyCode*)keyMap, GAME_CONTROL_KEY_NUM, KEYCODE_MAX_NUM);

        switch (action)
        {
        case ACT_KEY_UP:
            if (ActiveCursor(cp)->line > 0)
            {
                ActiveCursor(cp)->line--;
            }
            break;

        case ACT_KEY_DOWN:
            if (ActiveCursor(cp)->line < CHESSBOARD_LINE-1)
            {
                ActiveCursor(cp)->line++;
            }
            break;

        case ACT_KEY_LEFT:
            if (ActiveCursor(cp)->row > 0)
            {
                ActiveCursor(cp)->row--;
            }
            break;

        case ACT_KEY_RIGHT:
            if (ActiveCursor(cp)->row < CHESSBOARD_ROW-1)
            {
                ActiveCursor(cp)->row++;
            }
            break;

        case ACT_KEY_LOCK:
            //����δ��������������
            if (cp->chessLocked == 0)
            {
                //ֻ���������ڵ�ǰ��Ҳ�������
                if (cp->activePlayer == GetChessPlayer(GetChessType(cp, *ActiveCursor(cp))))
                {
                    cp->chessLocked = 1;
                    cp->lockedCursor = *ActiveCursor(cp);
                }
            }
            //��������λ��δ�䣬��������
            else if (MatchPos(cp->lockedCursor, ActiveCursor(cp)->line, ActiveCursor(cp)->row))
            {
                cp->chessLocked = 0;
            }
            //��������λ�øı䣬�����ƶ�����
            else
            {
                //����ƶ�λ��������Լ������ӣ����л�����������
                if (cp->activePlayer == GetChessPlayer(GetChessType(cp, *ActiveCursor(cp))))
                {
                    cp->chessLocked = 1;
                    cp->lockedCursor = *ActiveCursor(cp);
                }
                //�����ƶ��ɹ��������꣬�л���û�
                else if (MoveChess(cp, cp->lockedCursor, *ActiveCursor(cp), cp->activePlayer))
                {
                    cp->chessLocked = 0;
                    SwitchActivePlayer(cp);
                }
                //����δ�ƶ���������
                else
                {
                    
                }
            }
            break;

        case ACT_REFRESH_SCREEN:
            //��������
            DrawChessBoard(cp);
            //������������
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
* @brief ��ʼ������
*/
void InitChessBoard(struct ChessBoard *cp, enum Player player)
{
    //�������
    memset(cp, CHESS_NULL, sizeof(cp->map));
    
    //�ڷź췽����
    PutChess(cp, 9, 0, CHESS_R_JU);
    PutChess(cp, 9, 1, CHESS_R_MA);
    PutChess(cp, 9, 2, CHESS_R_XIANG);
    PutChess(cp, 9, 3, CHESS_R_SHI);
    PutChess(cp, 9, 4, CHESS_R_SHUAI);
    PutChess(cp, 9, 5, CHESS_R_SHI);
    PutChess(cp, 9, 6, CHESS_R_XIANG);
    PutChess(cp, 9, 7, CHESS_R_MA);
    PutChess(cp, 9, 8, CHESS_R_JU);
    
    PutChess(cp, 7, 1, CHESS_R_PAO);
    PutChess(cp, 7, 7, CHESS_R_PAO);
    
    PutChess(cp, 6, 0, CHESS_R_BING);
    PutChess(cp, 6, 2, CHESS_R_BING);
    PutChess(cp, 6, 4, CHESS_R_BING);
    PutChess(cp, 6, 6, CHESS_R_BING);
    PutChess(cp, 6, 8, CHESS_R_BING);
    
    //�ڷźڷ�����
    PutChess(cp, 0, 0, CHESS_K_JU);
    PutChess(cp, 0, 1, CHESS_K_MA);
    PutChess(cp, 0, 2, CHESS_K_XIANG);
    PutChess(cp, 0, 3, CHESS_K_SHI);
    PutChess(cp, 0, 4, CHESS_K_JIANG);
    PutChess(cp, 0, 5, CHESS_K_SHI);
    PutChess(cp, 0, 6, CHESS_K_XIANG);
    PutChess(cp, 0, 7, CHESS_K_MA);
    PutChess(cp, 0, 8, CHESS_K_JU);
    
    PutChess(cp, 2, 1, CHESS_K_PAO);
    PutChess(cp, 2, 7, CHESS_K_PAO);
    
    PutChess(cp, 3, 0, CHESS_K_ZU);
    PutChess(cp, 3, 2, CHESS_K_ZU);
    PutChess(cp, 3, 4, CHESS_K_ZU);
    PutChess(cp, 3, 6, CHESS_K_ZU);
    PutChess(cp, 3, 8, CHESS_K_ZU);

    //��������
    cp->redChessNum = CHESS_NUM_SUM;
    cp->blackChessNum = CHESS_NUM_SUM;
    //˫�����������
    cp->redShuaiExists = 1;
    cp->blackJiangExists = 1;
    
    //�������
    cp->player = player;
    //������򣺺췽����
    cp->activePlayer = PLY_RED;
    //����ʼ��
    cp->cursorRed = CreatePos(7, 4);
    cp->cursorBlack = CreatePos(2, 4);
    //����δ����
    cp->chessLocked = 0;
    //��Ϸ������
    cp->gameState = GSTAT_ACTIVE;
}

/**
* @brief ȡ��������
*/
void GetChessDisplayName(char chessType, char *ipName)
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
        printErr("GetChessType(): �����쳣���кŻ��кų���Ԥ��\n");
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
        printErr("SetChessType(): �����쳣���кŻ��кų���Ԥ��\n");
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
* @brief �л���ǰ����
*/
void SwitchActivePlayer(struct ChessBoard *cp)
{
    if (cp->activePlayer == PLY_RED)
    {
        cp->activePlayer = PLY_BLACK;
    }
    else
    {
        cp->activePlayer = PLY_RED;
    }
}

/**
* @brief ���ص�ǰ����
*/
char ActivePlayer(struct ChessBoard *cp)
{
    char ply;

    if (cp->activePlayer == PLY_RED)
    {
        ply = PLY_RED;
    }
    else
    {
        ply = PLY_BLACK;
    }

    return ply;
}

/**
* @brief ���ص�ǰ�ǻ���
*/
char InactivePlayer(struct ChessBoard *cp)
{
    char ply;

    if (cp->activePlayer == PLY_BLACK)
    {
        ply = PLY_RED;
    }
    else
    {
        ply = PLY_BLACK;
    }

    return ply;
}

/**
* @brief ȡ��ǰ���ҹ��
*/
struct ChessPos * ActiveCursor(struct ChessBoard *cp)
{
    struct ChessPos *pos;

    if (cp->activePlayer == PLY_RED)
    {
        pos = &cp->cursorRed;
    }
    else
    {
        pos = &cp->cursorBlack;
    }

    return pos;
}

/**
* @brief ȡ��ǰ�ǻ��ҹ��
*/
struct ChessPos * InactiveCursor(struct ChessBoard *cp)
{
    struct ChessPos *pos;

    if (cp->activePlayer == PLY_BLACK)
    {
        pos = &cp->cursorRed;
    }
    else
    {
        pos = &cp->cursorBlack;
    }

    return pos;
}

/**
* @brief ȡ��ǰ����������ָ��
*/
char * ActiveChessNum(struct ChessBoard *cp)
{
    char *num;

    if (cp->activePlayer == PLY_RED)
    {
        num = &cp->redChessNum;
    }
    else
    {
        num = &cp->blackChessNum;
    }

    return num;
}

/**
* @brief ȡ��ǰ�ǻ���������ָ��
*/
char * InactiveChessNum(struct ChessBoard *cp)
{
    char *num;

    if (cp->activePlayer == PLY_BLACK)
    {
        num = &cp->redChessNum;
    }
    else
    {
        num = &cp->blackChessNum;
    }

    return num;
}

/**
* @brief ��ǰ���һ�ʤ
*/
void ActivePlayerWin(struct ChessBoard *cp)
{
    if (cp->activePlayer == PLY_RED)
    {
        cp->gameState = GSTAT_RED_WIN;
    }
    else
    {
        cp->gameState = GSTAT_BLACK_WIN;
    }
}

/**
* @brief ��ǰ�ǻ��һ�ʤ
*/
void InactivePlayerWin(struct ChessBoard *cp)
{
    if (cp->activePlayer == PLY_BLACK)
    {
        cp->gameState = GSTAT_RED_WIN;
    }
    else
    {
        cp->gameState = GSTAT_BLACK_WIN;
    }
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
        printErr("PutChess(): �����쳣���кŻ��кų���Ԥ��\n");
    }
}

/**
* @brief ͳ����㵽�յ���;�����Ӹ����������������յ㣩
* 
* ����������������ˮƽ����ֱֱ�ߣ�����ͳ��б���ϵ�����
*/
int ChessCount(struct ChessBoard *cp, struct ChessPos destPos, struct ChessPos sourPos)
{
    int num = 0;
    int i;
    int posStart;
    int posEnd;
    struct ChessPos pos;
    
    //��ˮƽ����ֱֱ���޷�ͳ��
    if (destPos.line != sourPos.line && destPos.row != sourPos.row)
    {
        num = -1;
    }
    //��ʼ�ͽ�����ͬһ���ϣ��޷�ͳ��
    else if (destPos.line == sourPos.line && destPos.row == sourPos.row)
    {
        num = -1;
    }
    //����
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
    //����
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
* @brief ͳ��һ����ĳ���ӵĸ���
*/
int RowChessCount(struct ChessBoard *cp, char chessType, char row)
{
    int sum = 0;
    int i;
    struct ChessPos pos;

    pos.row = row;

    for (i = 0; i < CHESSBOARD_ROW; i++)
    {
        pos.line = i;

        if (GetChessType(cp, pos) == chessType)
        {
            sum++;
        }
    }

    return sum;
}

/**
* @brief �ƶ�����
* 
* �ɹ��ƶ�����1���ƶ�ʧ�ܻ������ƶ�����0
*/
char MoveChess(struct ChessBoard *cp, struct ChessPos sourPos, struct ChessPos destPos, char player)
{
    char moveSuccess = 0;
    char destType;
    char sourType;
    char oppChiefLost = 0; //�Է�����Ҫ���Ե�
    struct ChessPos tmpPos;
    
    destType = GetChessType(cp, destPos);
    sourType = GetChessType(cp, sourPos);

    //��Ϸ���ڽ���״̬����������
    if (cp->gameState != GSTAT_ACTIVE)
    {
        moveSuccess = 0;
    }
    //û�����ӿɹ��ƶ�
    else if (sourType == CHESS_NULL)
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
        //��ͼ�Ե��Է�����
        if (destType == CHESS_R_SHUAI || GetChessType(cp, destPos) == CHESS_K_JIANG)
        {
            oppChiefLost = 1;
        }

        switch (sourType)
        {
        /*******************�췽˧******************/
        case CHESS_R_SHUAI:
            //�ھŹ���
            if (sourPos.line < 7 || sourPos.line > 9 || sourPos.row < 3 || sourPos.row > 5)
            {
                printErr("MoveChess(): ����λ���쳣���췽˧�ھŹ���\n");
                moveSuccess = 0;
            }
            //��ͼ�߳��Ź�
            else if (destPos.line < 7 || destPos.line > 9 || destPos.row < 3 || destPos.row > 5)
            {
                //��ͼ�Ե��Է���
                if (GetChessType(cp, destPos) == CHESS_K_JIANG && ChessCount(cp, sourPos, destPos) == 0)
                {
                    moveSuccess = 1;
                }
                else
                {
                    moveSuccess = 0;
                }
            }
            //��ͼһ���߶��
            else if (abs(destPos.line - sourPos.line) > 1 || abs(destPos.row - sourPos.row) > 1)
            {
                moveSuccess = 0;
            }
            //��ͼ��б��
            else if (destPos.line != sourPos.line && destPos.row != sourPos.row)
            {
                moveSuccess = 0;
            }
            //���ӿ��ƶ�
            else
            {
                moveSuccess = 1;
            }
            break;
            
        /*******************�ڷ���*******************/
        case CHESS_K_JIANG:
            //�ھŹ���
            if (sourPos.line > 2 || sourPos.row < 3 || sourPos.row > 5)
            {
                printErr("MoveChess(): ����λ���쳣���ڷ����ھŹ���\n");
                moveSuccess = 0;
            }
            //��ͼ�߳��Ź�
            else if (destPos.line > 2 || destPos.row < 3 || destPos.row > 5)
            {
                //��ͼ�Ե��Է�˧
                if (GetChessType(cp, destPos) == CHESS_R_SHUAI && ChessCount(cp, sourPos, destPos) == 0)
                {
                    moveSuccess = 1;
                }
                else
                {
                    moveSuccess = 0;
                }
            }
            //��ͼһ���߶��
            else if (abs(destPos.line - sourPos.line) > 1 || abs(destPos.row - sourPos.row) > 1)
            {
                moveSuccess = 0;
            }
            //��ͼ��б��
            else if (destPos.line != sourPos.line && destPos.row != sourPos.row)
            {
                moveSuccess = 0;
            }
            //���ӿ��ƶ�
            else
            {
                moveSuccess = 1;
            }
            break;

        /*******************��ڷ���*******************/
        case CHESS_R_JU:
        case CHESS_K_JU:
            //��ͼ��б��
            if (destPos.line != sourPos.line && destPos.row != sourPos.row)
            {
                moveSuccess = 0;
            }
            //���ڵ�
            else if (ChessCount(cp, sourPos, destPos) != 0)
            {
                moveSuccess = 0;
            }
            //���ӿ��ƶ�
            else
            {
                moveSuccess = 1;
            }
            break;

        /*******************��ڷ���*******************/
        case CHESS_R_PAO:
        case CHESS_K_PAO:
            //��ͼ��б��
            if (destPos.line != sourPos.line && destPos.row != sourPos.row)
            {
                moveSuccess = 0;
            }
            //�������ұ��ڵ�
            else if (GetChessType(cp, destPos) == CHESS_NULL && ChessCount(cp, sourPos, destPos) != 0)
            {
                moveSuccess = 0;
            }
            //���ӵ��м�������Ӳ���һ��
            else if (GetChessType(cp, destPos) != CHESS_NULL && ChessCount(cp, sourPos, destPos) != 1)
            {
                moveSuccess = 0;
            }
            //���ӿ��ƶ�
            else
            {
                moveSuccess = 1;
            }
            break;

	    /*******************�췽��*******************/
		case CHESS_R_BING:
			//��ͼ����
			if (destPos.line > sourPos.line)
			{
			    moveSuccess = 0;
			}
			//��ͼ��б��
			else if (destPos.line != sourPos.line && destPos.row != sourPos.row)
			{
			    moveSuccess = 0;
			}
			//����ǰ��ͼ����
			else if (sourPos.line >= 5 && destPos.row != sourPos.row)
			{
			    moveSuccess = 0;
			}
            //��ͼһ���߶��
			else if (abs(destPos.line - sourPos.line) > 1 || abs(destPos.row - sourPos.row) > 1)
			{
			    moveSuccess = 0;
			}
			//���ӿ��ƶ�
			else
			{
			    moveSuccess = 1;
			}
			break;

		/*******************�ڷ���*******************/
		case CHESS_K_ZU:
			//��ͼ����
			if (destPos.line < sourPos.line)
			{
			    moveSuccess = 0;
			}
			//��ͼ��б��
			else if (destPos.line != sourPos.line && destPos.row != sourPos.row)
			{
			    moveSuccess = 0;
			}
			//����ǰ��ͼ����
			else if (sourPos.line <= 4 && destPos.row != sourPos.row)
			{
			    moveSuccess = 0;
			}
			//��ͼһ���߶��
			else if (abs(destPos.line - sourPos.line) > 1 || abs(destPos.row - sourPos.row) > 1)
			{
			    moveSuccess = 0;
			}
			//���ӿ��ƶ�
			else
			{
			    moveSuccess = 1;
			}
			break;

	    /*******************�췽��*******************/
		case CHESS_R_SHI:
			//��������λ�ã�����λ�ã��Ź��߽Ǻ��м䣩
			if (!MatchPos(sourPos, 7, 3) && !MatchPos(sourPos, 7, 5) && !MatchPos(sourPos, 8, 4) &&
				!MatchPos(sourPos, 9, 3) && !MatchPos(sourPos, 9, 5))
			{
			    printErr("MoveChess(): ����λ���쳣���췽�˲���Ԥ��λ��\n");
				moveSuccess = 0;
			}
            //��ͼ�߳��Ź�
            else if (destPos.line < 7 || destPos.line > 9 || destPos.row < 3 || destPos.row > 5)
            {
                moveSuccess = 0;
            }
			//��ͼ����б��
			else if (destPos.line == sourPos.line || destPos.row == sourPos.row)
			{
			    moveSuccess = 0;
			}
			//��ͼһ���߶��
			else if (abs(destPos.line - sourPos.line) > 1 || abs(destPos.row - sourPos.row) > 1)
			{
			    moveSuccess = 0;
			}
			//���ӿ��ƶ�
			else
			{
			    moveSuccess = 1;
			}
			break;

		/*******************�ڷ�ʿ*******************/
		case CHESS_K_SHI:
			//��������λ�ã�����λ�ã��Ź��߽Ǻ��м䣩
			if (!MatchPos(sourPos, 0, 3) && !MatchPos(sourPos, 0, 5) && !MatchPos(sourPos, 1, 4) &&
				!MatchPos(sourPos, 2, 3) && !MatchPos(sourPos, 2, 5))
			{
			    printErr("MoveChess(): ����λ���쳣���ڷ�ʿ����Ԥ��λ��\n");
				moveSuccess = 0;
			}
            //��ͼ�߳��Ź�
            else if (destPos.line > 2 || destPos.row < 3 || destPos.row > 5)
            {
                moveSuccess = 0;
            }
			//��ͼ����б��
			else if (destPos.line == sourPos.line || destPos.row == sourPos.row)
			{
			    moveSuccess = 0;
			}
			//��ͼһ���߶��
			else if (abs(destPos.line - sourPos.line) > 1 || abs(destPos.row - sourPos.row) > 1)
			{
			    moveSuccess = 0;
			}
			//���ӿ��ƶ�
			else
			{
			    moveSuccess = 1;
			}
			break;

        /*******************��ڷ���*******************/
        case CHESS_R_MA:
        case CHESS_K_MA:
            //�ߺ�����
            if (abs(destPos.line - sourPos.line) == 1 && abs(destPos.row - sourPos.row) == 2)
            {
                //�����ȡ�������
                tmpPos.line = sourPos.line;
                tmpPos.row = MAX2(sourPos.row, destPos.row) - 1;

                //������
                if (GetChessType(cp, tmpPos) != CHESS_NULL)
                {
                    moveSuccess = 0;
                }
                else
                {
                    moveSuccess = 1;
                }
            }
            //��������
            else if (abs(destPos.line - sourPos.line) == 2 && abs(destPos.row - sourPos.row) == 1)
            {
                //�����ȡ�������
                tmpPos.row = sourPos.row;
                tmpPos.line = MAX2(sourPos.line, destPos.line) - 1;

                //������
                if (GetChessType(cp, tmpPos) != CHESS_NULL)
                {
                    moveSuccess = 0;
                }
                //���ӿ��ƶ�
                else
                {
                    moveSuccess = 1;
                }
            }
            //��������
            else
            {
                moveSuccess = 0;
            }
            break;

        /*******************��ڷ���/��*******************/
        case CHESS_R_XIANG:
        case CHESS_K_XIANG:
            //��������λ�ã��ѹ��ӽ磩
            if ((sourType == CHESS_K_XIANG && sourPos.line > 4) ||
                (sourType == CHESS_R_XIANG && sourPos.line < 5))
            {
                printErr("MoveChess(): ����λ���쳣����/���ѹ��ӽ�\n");
                moveSuccess = 0;
            }
            //��ͼ�߹��ӽ�
            else if ((sourType == CHESS_K_XIANG && destPos.line > 4) ||
                (sourType == CHESS_R_XIANG && destPos.line < 5))
            {
                moveSuccess = 0;
            }
            //������
            else if (abs(destPos.line - sourPos.line) == 2 && abs(destPos.row - sourPos.row) == 2)
            {
                //�����ۡ�������
                tmpPos.line = MAX2(sourPos.line, destPos.line) - 1;
                tmpPos.row = MAX2(sourPos.row, destPos.row) - 1;
                
                //������
                if (GetChessType(cp, tmpPos) != CHESS_NULL)
                {
                    moveSuccess = 0;
                }
                //���ӿ��ƶ�
                else
                {
                    moveSuccess = 1;
                }
            }
            //��������
            else
            {
                moveSuccess = 0;
            }
            break;

        default:
            break;
        }

        if (moveSuccess)
        {
            char a[100] = {0};
            ChessMoveToManual(cp, sourPos, destPos, a);
            printErr(a);

            SetChessType(cp, sourPos, CHESS_NULL);
            SetChessType(cp, destPos, sourType);

            //�Ե��Է�������Է���������1
            if (destType != CHESS_NULL)
            {
                (*InactiveChessNum(cp))--;
            }

            //�Է�û�����ӣ�������ʤ
            if (*InactiveChessNum(cp) == 0)
            {
                ActivePlayerWin(cp);
            }

            //�Է��������Ե���������ʤ
            if (oppChiefLost)
            {
                ActivePlayerWin(cp);
            }
        }

    /******���� switch (����) �� else ��֧����******/
    }

    return moveSuccess;
}