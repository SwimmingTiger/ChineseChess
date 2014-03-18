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
* ��ڷ�������ͬ���췽
*/


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
    char success = 0;
    char rowChessSum = 0;

    type = GetChessType(cp, sourPos);

    //�������Ӳ�����
    if (type == CHESS_NULL)
    {
        printErr("ChessMoveToManual(): �����쳣�����߶������Ӷ�ʧ�����ȵ��øú������ƶ�����λ�ã�\n");
        success = 0;
    }
    else
    {
         GetChessManualName(type, name);

         //�޷�ȡ��������
         if (strlen(name) == 0)
         {
             success = 0;
         }
         else
         {
             rowChessSum = RowChessCount(cp, type, sourPos.row);

             //ͳ�������쳣
             if (rowChessSum < 1)
             {
                 printErr("ChessMoveToManual(): �����쳣�����߶������Ӷ�ʧ�����ȵ��øú������ƶ�����λ�ã�\n");
                 success = 0;
             }
             //���������ӣ�����ͨ�Ƿ�
             else if (rowChessSum == 1)
             {
                 //ƽ��
                 if (sourPos.line == destPos.line)
                 {
                     //strcpy();
                 }
             }
         }
    }
    
    return success;
}