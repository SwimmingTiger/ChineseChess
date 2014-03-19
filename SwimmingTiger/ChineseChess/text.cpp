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
#include "chess.h"
#include "debug.h"

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
        //��б�����ӣ�destNameΪ���˵�������
        if (destPos.row != sourPos.row)
        {
            GetRowName(destPos.row, player, destName); //������������
        }
        //��ֱ�����ӣ�destNameΪ��������
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
            strcpy(actionName, name);
            
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