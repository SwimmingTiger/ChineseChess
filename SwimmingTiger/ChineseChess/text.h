#ifndef _TEXT_H_
/**
* @brief �й������ı�����������
* 
* - ������Ϣ
*     - ���ߣ����ݺ�
*     - �༶�����131��
*     - ѧԺ���������ѧ�빤��ѧԺ
*     - ѧУ����������ѧԺ
*/
#define _TEXT_H_

/**********************************��������**********************************/

/*ȡ�����ӵļ�������*/
void GetChessManualName(char chessType, char *ipName);

/*��ȡ��������*/
void GetRowName(char row, char player, char *result);

/*�������߷�ת��������*/
char ChessMoveToManual(struct ChessBoard *cp, struct ChessPos sourPos, struct ChessPos destPos, char *result);

/*********************************Ԥ�������*********************************/
#endif