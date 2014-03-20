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

/** @brief ��Ϸ�浵Ŀ¼ */
#define GAME_SAVE_DIR "./ChineseChess"

/**********************************��������**********************************/

/*ȡ�����ӵļ�������*/
void GetChessManualName(char chessType, char *ipName);

/*��ȡ��������*/
void GetRowName(char row, char player, char *result);

/*�������߷�ת��������*/
char ChessMoveToManual(struct ChessBoard *cp, struct ChessPos sourPos, struct ChessPos destPos, char *result);

/*��ʼ����Ϸ�浵Ŀ¼*/
int InitGameSaveDir();

/*ȡ��Ĭ�ϴ浵��*/
void GetDefaultSaveName(char *name);

/*д��Ϸ��־*/
int WriteGameLog(char *fileName, char *content);

/*������Ϸ*/
int SaveGame(struct ChessBoard *cp, char *fileName);

/*������Ϸ*/
int LoadGame(struct ChessBoard *cp, char *fileName);

/*********************************Ԥ�������*********************************/
#endif