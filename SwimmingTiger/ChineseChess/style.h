#ifndef _STYLE_H_
/**
* @brief �й�������Ϸ������ʽ����
* 
* - ������Ϣ
*     - ���ߣ����ݺ�
*     - �༶�����131��
*     - ѧԺ���������ѧ�빤��ѧԺ
*     - ѧУ����������ѧԺ
*/
#define _STYLE_H_

/**********************************��������**********************************/

/********************����̨������ʽ*******************/

/** @brief ����̨���ڱ��� */
#define CONSOLE_WINDOW_TITLE "�й�����"

/** @brief ����̨���ּ�������ɫ�������� */
#define CONSOLE_COLOR "color 60"

/** @brief �������ϽǺ����꣨�����Ļ�����أ� */
#define CONSOLE_WINDOW_LEFT 15

/** @brief �������Ͻ������꣨�����Ļ�����أ� */
#define CONSOLE_WINDOW_TOP 10

/** @brief ����̨���ݿ�ȣ��ַ��� */
#define CONSOLE_CONTENT_WIDTH 80

/** @brief ����̨���ݸ߶ȣ��ַ��� */
#define CONSOLE_CONTENT_HEIGHT 42

/** @brief ����̨���ڿ�ȣ����أ� */
#define CONSOLE_WINDOW_WIDTH 1024

/** @brief ����̨���ڸ߶ȣ����أ� */
#define CONSOLE_WINDOW_HEIGHT 768

/**********************������ʽ*********************/

/** @brief �����п����أ� */
#define CHESSBOARD_ROW_WIDTH 70

/** @brief �����иߣ����أ� */
#define CHESSBOARD_LINE_HEIGHT 65

/** @brief ������ߺ����꣨���أ� */
#define CHESSBOARD_RECT_LEFT 35

/** @brief ���̶��������꣨���أ� */
#define CHESSBOARD_RECT_TOP 38

/** @brief ���̿�ȣ����أ� */
#define CHESSBOARD_WIDTH (CHESSBOARD_ROW_WIDTH*8)

/** @brief ���̸߶ȣ����أ� */
#define CHESSBOARD_HEIGHT (CHESSBOARD_LINE_HEIGHT*9)

/** @brief �����ұߺ����꣨���أ� */
#define CHESSBOARD_RECT_RIGHT (CHESSBOARD_WIDTH+CHESSBOARD_RECT_LEFT)

/** @brief ���̵ױ������꣨���أ� */
#define CHESSBOARD_RECT_BOTTOM (CHESSBOARD_HEIGHT+CHESSBOARD_RECT_TOP)

/** @brief ���������� */
#define CHESSBOARD_BORDER_STYLE PS_DASH

/** @brief �����߿�� */
#define CHESSBOARD_BORDER_WIDTH 2

/** @brief ��������ɫ */
#define CHESSBOARD_BORDER_COLOR 0x000000

/** @brief ���̱�����ɫ */
#define CHESSBOARD_BACKGROUND_COLOR 0x008080

/**********************������ʽ*********************/

/** @brief ���ӱ߿����� */
#define CHESS_BORDER_STYLE PS_DASH

/** @brief ���ӱ߿��� */
#define CHESS_BORDER_WIDTH 2

/** @brief ��������߶� */
#define CHESS_FONT_HEIGHT 30

/** @brief ���������� */
#define CHESS_FONT_WIDTH 15

/** @brief ���������ϸ */
#define CHESS_FONT_WEIGHT 700

/** @brief ��������ˮƽƫ�� */
#define CHESS_FONT_OFFSET_X -16

/** @brief ����������ֱƫ�� */
#define CHESS_FONT_OFFSET_Y -15

/**
* @brief ����������
* 
* ��ȡ����ֵ֮һ��
* FF_DECORATIVE�����������
* FF_DONTCARE�������Ļ�֪��
* FF_MODERN���ȿ�����
* FF_ROMAN�����߷ǵȿ�����
* FF_SCRIPT����д��
* FF_SWISS���޳��߷ǵȿ�����
*/
#define CHESS_FONT_FAMILY FF_SCRIPT

/** @brief ���������� */
#define CHESS_FONT_NAME "����"

/** @brief �췽���ӱ߿�������ɫ */
#define CHESS_RED_COLOR 0x0000ff

/** @brief �ڷ����ӱ߿�������ɫ */
#define CHESS_BLACK_COLOR 0x000000

/** @brief �����ڲ���ɫ */
#define CHESS_INSIDE_COLOR 0xc0c0c0

/** @brief ���Ӱ뾶 */
#define CHESS_RADIUS 25

/**********************�����ʽ*********************/

/** @brief ���߿����� */
#define CURSOR_BORDER_STYLE PS_DASH

/** @brief ���߿��� */
#define CURSOR_BORDER_WIDTH 1

/** @brief ���߿���ɫ */
#define CURSOR_BORDER_COLOR 0x00ff00

/** @brief �������߿���ɫ */
#define LOCK_CURSOR_BORDER_COLOR 0x0000ff

/** @brief ����ڲ���ɫ */
#define CURSOR_INSIDE_COLOR 0x008080

/** @brief �����η�Χ��ԭ���ھ������Ͻǣ� */
#define CURSOR_RECT {-30, -30, 30, 30}

/*********************************Ԥ�������*********************************/
#endif