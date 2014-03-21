#ifndef _MENU_H_
/**
* @brief �й�������Ϸ�˵���������
* 
* - ������Ϣ
*     - ���ߣ����ݺ�
*     - �༶�����131��
*     - ѧԺ���������ѧ�빤��ѧԺ
*     - ѧУ����������ѧԺ
*/
#define _MENU_H_

/**********************************��������**********************************/

/**********************�˵���ʽ*********************/

/** @brief �˵��߿����� */
#define MENU_BORDER_STYLE 0

/** @brief �˵��߿��� */
#define MENU_BORDER_WIDTH 1

/** @brief �˵�����߶� */
#define MENU_FONT_HEIGHT 30

/** @brief �˵������� */
#define MENU_FONT_WIDTH 15

/** @brief �˵������ϸ */
#define MENU_FONT_WEIGHT 700

/** @brief �˵���������߶� */
#define MENU_TITLE_FONT_HEIGHT 40

/** @brief �˵����������� */
#define MENU_TITLE_FONT_WIDTH 20

/** @brief �˵�ע������߶� */
#define MENU_TIP_FONT_HEIGHT 20

/** @brief �˵�ע�������� */
#define MENU_TIP_FONT_WIDTH 10

/** @brief �˵������ϸ */
#define MENU_FONT_WEIGHT 700

/**
* @brief �˵�������
* 
* ��ȡ����ֵ֮һ��
* FF_DECORATIVE�����������
* FF_DONTCARE�������Ļ�֪��
* FF_MODERN���ȿ�����
* FF_ROMAN�����߷ǵȿ�����
* FF_SCRIPT����д��
* FF_SWISS���޳��߷ǵȿ�����
*/
#define MENU_FONT_FAMILY FF_SCRIPT

/** @brief �˵������� */
#define MENU_FONT_NAME "����"

/** @brief �˵��߿���ɫ */
#define MENU_BORDER_COLOR 0x0000ff

/** @brief �˵�������ɫ */
#define MENU_TEXT_COLOR 0x000000

/** @brief �˵�������ɫ */
#define MENU_BACKGROUND_COLOR 0xc0c0c0

/**********************************��������**********************************/

/*���ز˵����η�Χ��ʹ�˵�����Ӧ�߿����*/
void DecideMenuRect(int width, int height, RECT *rc);

/*�������˵��������û�ѡ����¼�*/
char MainMenuSelect();

/*������Ϸ�˵��������û�ѡ����¼�*/
char GameMenuSelect();

/*������һ�ʤ��Ϸ�˵�*/
char PlayerWinSelect(char player);

/*�����޷��浵��ʾ��*/
void ShowCannotSaveNotice();

/*�����޷�����浵��ʾ��*/
void ShowCannotLoadNotice();

/*���ƹ�����ʾ��*/
void ShowAbout();

/*�鿴�������*/
void ShowStep(struct ChessBoard *cp);

/*********************************Ԥ�������*********************************/
#endif