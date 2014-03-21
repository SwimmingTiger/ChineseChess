/**
* @brief �й������ı�������ʵ��
* 
* - ������Ϣ
*     - ���ߣ����ݺ�
*     - �༶�����131��
*     - ѧԺ���������ѧ�빤��ѧԺ
*     - ѧУ����������ѧԺ
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <windows.h>
#include "chess.h"
#include "debug.h"
#include "text.h"
#include "control.h"

/**
* @brief ȡ�����ӵļ�������
*/
void GetChessManualName(char chessType, char *ipName)
{
    switch (chessType)
    {
    case CHESS_R_SHUAI:
        strcpy(ipName, "˧");
        break;
    case CHESS_R_JU:
        strcpy(ipName, "��");
        break;
    case CHESS_R_MA:
        strcpy(ipName, "��");
        break;
    case CHESS_R_PAO:
        strcpy(ipName, "��");
        break;
    case CHESS_R_XIANG:
        strcpy(ipName, "��");
        break;
    case CHESS_R_SHI:
        strcpy(ipName, "ʿ");
        break;
    case CHESS_R_BING:
        strcpy(ipName, "��");
        break;
        
    case CHESS_K_JIANG:
        strcpy(ipName, "��");
        break;
    case CHESS_K_JU:
        strcpy(ipName, "��");
        break;
    case CHESS_K_MA:
        strcpy(ipName, "��");
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
* @brief ��ȡ��������
* 
* ��ڷ�������ͬ���췽����������Ϊһ���ţ��ú��֣����ڷ�����������Ϊ1��9���ð��������֣�
* 
* �������ָ�� char *result �У�ʧ�ܵõ����ַ�����
*/
void GetRowName(char row, char player, char *result)
{
    //�췽����
    if (player == PLY_RED)
    {
        switch (row)
        {
        case 8:
            strcpy(result, "һ");
            break;
        case 7:
            strcpy(result, "��");
            break;
        case 6:
            strcpy(result, "��");
            break;
        case 5:
            strcpy(result, "��");
            break;
        case 4:
            strcpy(result, "��");
            break;
        case 3:
            strcpy(result, "��");
            break;
        case 2:
            strcpy(result, "��");
            break;
        case 1:
            strcpy(result, "��");
            break;
        case 0:
            strcpy(result, "��");
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
* @brief ��ȡ�����Ƿ�
* 
* ��ڷ��Ƿ���ͬ���췽Ϊһ���ţ��ú��֣����ڷ�Ϊ1��9���ð��������֣�
* 
* ��������5�����췽�õ����塱���ڷ��õ�5��
* 
* �������ָ�� char *result �У�ʧ�ܵõ����ַ�����
*/
void GetStepName(char step, char player, char *result)
{
    //�췽����
    if (player == PLY_RED)
    {
        switch (step)
        {
        case 1:
            strcpy(result, "һ");
            break;
        case 2:
            strcpy(result, "��");
            break;
        case 3:
            strcpy(result, "��");
            break;
        case 4:
            strcpy(result, "��");
            break;
        case 5:
            strcpy(result, "��");
            break;
        case 6:
            strcpy(result, "��");
            break;
        case 7:
            strcpy(result, "��");
            break;
        case 8:
            strcpy(result, "��");
            break;
        case 9:
            strcpy(result, "��");
            break;
        //���̹�ʮ�У�ֻ���ܴӽ�һ������
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
* @brief �������߷�ת��������
* 
* �������ָ�� char *result �С�
* 
* ����ֵ��ת���ɹ�����1��ʧ�ܷ���0��
*/
char ChessMoveToManual(struct ChessBoard *cp, struct ChessPos sourPos, struct ChessPos destPos, char *result)
{
    char type; //������������
    char name[8]; //��������
    char sourName[8]; //��ʼλ������
    char destName[8]; //���ߵ���λ������
    char actionName[8]; //���ӷ�ʽ���ƣ������ˡ�ƽ
    char player; //�������
    char success = 0;
    int rowChessSum = 0;
    int aboveChessSum = 0;
    int belowChessSum = 0;
    
    type = GetChessType(cp, sourPos);
    GetChessManualName(type, name); //������
    player = GetChessPlayer(type);
    rowChessSum = RowChessCount(cp, type, sourPos.row);
    aboveChessSum = AboveChessCount(cp, type, sourPos, player);
    belowChessSum = BelowChessCount(cp, type, sourPos, player);

    //�������Ӳ�����
    if (type == CHESS_NULL)
    {
        printErr("ChessMoveToManual(): �����쳣�����߶������Ӷ�ʧ�����ȵ��øú������ƶ�����λ�ã�\n");
        success = 0;
    }
    //�޷�ȡ��������
    else if (strlen(name) == 0)
    {
        success = 0;
    }
    //ͳ�������쳣
    else if (rowChessSum < 1)
    {
        printErr("ChessMoveToManual(): �����쳣�����߶������Ӷ�ʧ�����ȵ��øú������ƶ�����λ�ã�\n");
        success = 0;
    }
    //ͳ����������
    else
    {
        success = 1;
        
        /***********�����ƶ���ʽ***********/
        //ƽ��
        if (sourPos.line == destPos.line)
        {
            strcpy(actionName, "ƽ"); //��������ƽ
        }
        //ǰ��
        else if ((player==PLY_RED && destPos.line-sourPos.line<0) || (player==PLY_BLACK && destPos.line-sourPos.line>0))
        {
            strcpy(actionName, "��"); //����������
        }
        //����
        else
        {
            strcpy(actionName, "��"); //����������
        }
        
        /***********�ƶ�����λ��***********/
        //�б仯��destNameΪ���˵�������
        if (destPos.row != sourPos.row)
        {
            GetRowName(destPos.row, player, destName); //������������
        }
        //�в��䣬destNameΪ��������
        else
        {
            GetStepName(abs(destPos.line-sourPos.line), player, destName); //���������˶��������г������У�
        }
        
        /***********���ӳ�ʼλ�ñ���**********/
        //�����ӣ���ͨ�Ƿ�
        if (rowChessSum == 1)
        {
            GetRowName(sourPos.row, player, sourName); //��������
        }
        //���ӵ��Ǳ��䣬����ǰ����һ
        else if (type != CHESS_R_BING && type != CHESS_K_ZU)
        {
            //�������ڵڶ�λ���ǵ�һλ
            strcpy(sourName, name);
            
            if (aboveChessSum == 0)
            {
                strcpy(name, "ǰ");
            }
            else
            {
                strcpy(name, "��");
            }
        }
        //�������ӣ�����ǰ���һ
        else
        {
            if (aboveChessSum == 0)
            {
                strcpy(name, "ǰ");
            }
            else if (belowChessSum == 0)
            {
                strcpy(name, "��");
            }
            else if(aboveChessSum == belowChessSum)
            {
                strcpy(name, "��");
            }
            else if(aboveChessSum < belowChessSum)
            {
                strcpy(name, "��ǰ");
            }
            else if(aboveChessSum > belowChessSum)
            {
                strcpy(name, "�к�");
            }

            GetRowName(sourPos.row, player, sourName);
        }
    }

    if (success)
    {
        sprintf(result, "%s%s%s%s", name, sourName, actionName, destName);
    }

    return success;
}

/**
* @brief ��ʼ����Ϸ�浵Ŀ¼
* 
* Ŀ¼·���� GAME_SAVE_DIR ����ָ��
*/
int InitGameSaveDir()
{
    int success = 0;
    FILE *fp;

    CreateDirectory(GAME_SAVE_DIR, NULL);
    CreateDirectory(GAME_SAVE_DIR"/log", NULL);
    CreateDirectory(GAME_SAVE_DIR"/save", NULL);
    CreateDirectory(GAME_SAVE_DIR"/maunal", NULL);

    fp = fopen(GAME_SAVE_DIR"/canSave.test", "w");

    if (fp == NULL)
    {
        success = 0;
    }
    else
    {
        success = 1;
        fclose(fp);
    }

    return success;
}

/**
* @brief ȡ��Ĭ�ϴ浵��
* 
* ��������β�name�У���������չ����
*/
void GetDefaultSaveName(char *name)
{
    SYSTEMTIME time;

    GetLocalTime(&time);
    sprintf(name, "%04d-%02d-%02d_%02d_%02d_%02d", time.wYear, time.wMonth, time.wDay, time.wHour, time.wMinute, time.wSecond);
}

/**
* @brief д��Ϸ��־
* 
* �β�fileName������·����
* 
* �ɹ�����1��ʧ�ܷ���0��
* �ļ���Ϊ��ʱ������־��¼��������1��
*/
int WriteGameLog(char *fileName, char *content)
{
    int success = 0;
    char path[255];
    FILE *fp;
    
    //�ļ���Ϊ�գ��ɹ�������־��¼
    if (strlen(fileName) == 0)
    {
        success = 1;
    }
    else
    {
        sprintf(path, "%s/%s", GAME_SAVE_DIR"/log", fileName);

        fp = fopen(path, "a");
        
        if (fp == NULL)
        {
            fp = fopen(path, "w");
        }
        
        if (fp == NULL)
        {
            success = 0;
        }
        else
        {
            success = 1;
            
            fprintf(fp, "%s", content);
            fclose(fp);
        }
    }

    return success;
}

/**
* @brief ������Ϸ
* 
* �β�fileName������·����
* 
* �ɹ�����1��ʧ�ܷ���0��
*/
int SaveGame(struct ChessBoard *cp, char *fileName)
{
    int success = 0;
    char path[255];
    FILE *fp;
    
    sprintf(path, "%s/%s", GAME_SAVE_DIR"/save", fileName);

    fp = fopen(path, "wb");
    
    if (fp == NULL)
    {
        success = 0;
    }
    else
    {
        success = 1;
        
        fwrite(cp, sizeof(struct ChessBoard), 1, fp);
        fclose(fp);
    }

    return success;
}

/**
* @brief ������Ϸ
* 
* �β�fileName������·����
* 
* �ɹ�����1��ʧ�ܷ���0��
*/
int LoadGame(struct ChessBoard *cp, char *fileName)
{
    int success = 0;
    char path[255];
    char tmpPath[255];
    FILE *fp;
    
    sprintf(path, "%s/%s", GAME_SAVE_DIR"/save", fileName);

    fp = fopen(path, "rb");
    
    if (fp == NULL)
    {
        success = 0;
    }
    else
    {
        success = 1;
        
        fread(cp, sizeof(struct ChessBoard), 1, fp);
        fclose(fp);

        //��Ϸ״̬��ͣ
        cp->gameState = GSTAT_PAUSE;

        //�����µ���Ϸ��־�ļ�
        sprintf(path, "%s/%s", GAME_SAVE_DIR"/log", cp->logFileName);
        GetDefaultSaveName(cp->logFileName);
        strcat(cp->logFileName, ".log");
        sprintf(tmpPath, "%s/%s", GAME_SAVE_DIR"/log", cp->logFileName);
        CopyFile(path, tmpPath, TRUE);
    }

    return success;
}

/**
* @brief �ı�ƥ������
*/
char TextMatchChess(char *text, char player)
{
    char chess = CHESS_NULL;

    //�췽
    if (player == PLY_RED)
    {
        if (memcmp(text, "˧", 2))
        {
            chess = CHESS_R_SHUAI;
        }
        else if (memcmp(text, "��", 2))
        {
            chess = CHESS_R_JU;
        }
        else if (memcmp(text, "��", 2))
        {
            chess = CHESS_R_MA;
        }
        else if (memcmp(text, "��", 2))
        {
            chess = CHESS_R_PAO;
        }
        else if (memcmp(text, "��", 2))
        {
            chess = CHESS_R_XIANG;
        }
        else if (memcmp(text, "��", 2))
        {
            chess = CHESS_R_SHI;
        }
        else if (memcmp(text, "ʿ", 2))
        {
            chess = CHESS_R_SHI;
        }
        else if (memcmp(text, "��", 2))
        {
            chess = CHESS_R_BING;
        }
    }
    else
    {
        //�ڷ�
        if (memcmp(text, "��", 2))
        {
            chess = CHESS_K_JIANG;
        }
        else if (memcmp(text, "��", 2))
        {
            chess = CHESS_K_JU;
        }
        else if (memcmp(text, "��", 2))
        {
            chess = CHESS_K_MA;
        }
        else if (memcmp(text, "��", 2))
        {
            chess = CHESS_K_PAO;
        }
        else if (memcmp(text, "��", 2))
        {
            chess = CHESS_K_XIANG;
        }
        else if (memcmp(text, "��", 2))
        {
            chess = CHESS_K_SHI;
        }
        else if (memcmp(text, "ʿ", 2))
        {
            chess = CHESS_K_SHI;
        }
        else if (memcmp(text, "��", 2))
        {
            chess = CHESS_K_ZU;
        }
    }
    
    return chess;
}

/**
* @brief ��������
*/
int ParseNumber(char *text, char player, int *len)
{
    int num = -1;

    if (player == PLY_RED)
    {
        *len = 2;

        if (memcmp(text, "һ", 2))
        {
            num = 1;
        }
        else if (memcmp(text, "��", 2))
        {
            num = 2;
        }
        if (memcmp(text, "��", 2))
        {
            num = 3;
        }
        if (memcmp(text, "��", 2))
        {
            num = 4;
        }
        if (memcmp(text, "��", 2))
        {
            num = 5;
        }
        if (memcmp(text, "��", 2))
        {
            num = 6;
        }
        if (memcmp(text, "��", 2))
        {
            num = 7;
        }
        if (memcmp(text, "��", 2))
        {
            num = 8;
        }
        if (memcmp(text, "��", 2))
        {
            num = 9;
        }
    }
    else
    {
        if (memcmp(text, "��", 2))
        {
            num = 1;
            *len = 2;
        }
        else if (memcmp(text, "��", 2))
        {
            num = 2;
            *len = 2;
        }
        if (memcmp(text, "��", 2))
        {
            num = 3;
            *len = 2;
        }
        if (memcmp(text, "��", 2))
        {
            num = 4;
            *len = 2;
        }
        if (memcmp(text, "��", 2))
        {
            num = 5;
            *len = 2;
        }
        if (memcmp(text, "��", 2))
        {
            num = 6;
            *len = 2;
        }
        if (memcmp(text, "��", 2))
        {
            num = 7;
            *len = 2;
        }
        if (memcmp(text, "��", 2))
        {
            num = 8;
            *len = 2;
        }
        if (memcmp(text, "��", 2))
        {
            num = 9;
            *len = 2;
        }
        else if (memcmp(text, "1", 1))
        {
            num = 1;
            *len = 1;
        }
        else if (memcmp(text, "2", 1))
        {
            num = 2;
            *len = 1;
        }
        if (memcmp(text, "3", 1))
        {
            num = 3;
            *len = 1;
        }
        if (memcmp(text, "4", 1))
        {
            num = 4;
            *len = 1;
        }
        if (memcmp(text, "5", 1))
        {
            num = 5;
            *len = 1;
        }
        if (memcmp(text, "6", 1))
        {
            num = 6;
            *len = 1;
        }
        if (memcmp(text, "7", 1))
        {
            num = 7;
            *len = 1;
        }
        if (memcmp(text, "8", 1))
        {
            num = 8;
            *len = 1;
        }
        if (memcmp(text, "9", 1))
        {
            num = 9;
            *len = 1;
        }
    }

    return num;
}

/**
* @brief ��������
*/
char ParseMaunal(struct ChessBoard *cp, FILE *fp)
{
    char action = ACT_UNKNOWN;
    char step[11];
    char chessType;
    char sourRow;
    char destRow;
    int direction;
    int len;
    char *text;
    int failed = 0;
    struct ChessPos destPos;
    struct ChessPos sourPos;
    int stepLen;

    if (0 == fscanf(fp, "%10s", step))
    {
        action = ACT_STOP_GAME;
    }
    else if (strcmp("��ʤ", step) || strcmp("�췽ʤ", step))
    {
        PlayerWin(cp, PLY_RED);
        action = ACT_STOP_GAME;
    }
    else if (strcmp("��ʤ", step) || strcmp("�ڷ�ʤ", step))
    {
        PlayerWin(cp, PLY_BLACK);
        action = ACT_STOP_GAME;
    }
    //���ӼǷ����磺ǰ���һ ǰ5��1
    else if (memcmp(step, "ǰ", 2) || memcmp(step, "��", 2) || memcmp(step, "��", 2))
    {
    
    }
    //�����Ƿ����磺��˽���
    else
    {
        text = step;
        chessType = TextMatchChess(text, cp->activePlayer);
        text += 2;
        sourRow = ParseNumber(text, cp->activePlayer, &len);
        text += len;

        if (memcmp(text, "��", 2))
        {
            direction = 1;
        }
        else if (memcmp(text, "��", 2))
        {
            direction = -1;
        }
        else if (memcmp(text, "ƽ", 2))
        {
            direction = 0;
        }
        else
        {
            failed = 1;
        }

        text += 2;
        destRow = ParseNumber(text, cp->activePlayer, &len);

        if (1 == failed || CHESS_NULL == chessType || -1 == sourRow || -1 == destRow)
        {
            failed = 1;
        }
        else
        {
            sourPos.row = sourRow;
            
            for (sourPos.line=0,failed=1; sourPos.line<CHESSBOARD_LINE || failed==0; sourPos.line++)
            {
                if (GetChessType(cp, sourPos) == chessType)
                {
                    failed = 0;
                }
            }
            //��ȥforѭ������ǰ��ӵ�line
            sourPos.line--;

            if (0 == failed)
            {
                //ƽ��
                if (0 == direction)
                {
                    destPos.line = sourPos.line;
                    
                    if (cp->activePlayer == PLY_RED)
                    {
                        destPos.row = CHESSBOARD_ROW - destRow;
                    }
                    else
                    {
                        destPos.row = destRow - 1;
                    }
                }
                //����
                else
                {
                    switch (chessType)
                    {
                    
                    case CHESS_R_SHI:
                        destPos.row = destRow;
                        //��
                        if (direction > 0)
                        {
                            destPos.line = sourPos.line - 1;
                        }
                        //��
                        else
                        {
                            destPos.line = sourPos.line + 1;
                        }
                        break;

                    case CHESS_K_SHI:
                        destPos.row = destRow;
                        //��
                        if (direction > 0)
                        {
                            destPos.line = sourPos.line + 1;
                        }
                        //��
                        else
                        {
                            destPos.line = sourPos.line - 1;
                        }
                        break;

                    case CHESS_R_XIANG:
                        destPos.row = destRow;
                        //��
                        if (direction > 0)
                        {
                            destPos.line = sourPos.line - 2;
                        }
                        //��
                        else
                        {
                            destPos.line = sourPos.line + 2;
                        }
                        break;

                    case CHESS_K_XIANG:
                        destPos.row = destRow;
                        //��
                        if (direction > 0)
                        {
                            destPos.line = sourPos.line + 2;
                        }
                        //��
                        else
                        {
                            destPos.line = sourPos.line - 2;
                        }
                        break;

                    case CHESS_R_MA:
                        destPos.row = destRow;
                        
                        if (abs(destPos.row - sourPos.row) == 1)
                        {
                            stepLen = 2;
                        }
                        else
                        {
                            stepLen = 1;
                        }

                        //��
                        if (direction > 0)
                        {
                            destPos.line = sourPos.line - stepLen;
                        }
                        //��
                        else
                        {
                            destPos.line = sourPos.line + stepLen;
                        }

                    case CHESS_K_MA:
                        destPos.row = destRow;
                        
                        if (abs(destPos.row - sourPos.row) == 1)
                        {
                            stepLen = 2;
                        }
                        else
                        {
                            stepLen = 1;
                        }

                        //��
                        if (direction > 0)
                        {
                            destPos.line = sourPos.line + stepLen;
                        }
                        //��
                        else
                        {
                            destPos.line = sourPos.line - stepLen;
                        }
                        break;

                    default:
                        destPos.row = sourPos.row;
                        
                        if (GetChessPlayer(chessType) == PLY_RED)
                        {
                            destPos.line = sourPos.line - direction * destRow;
                        }
                        else
                        {
                            destPos.line = sourPos.line + direction * destRow;
                        }
                        break;
                    }
                }
            }
        }
    }

    return action;
}