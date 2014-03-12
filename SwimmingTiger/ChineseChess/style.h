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

/** @brief ǰ��������ɫ�������� */
#define CONSOLE_COLOR "color 60"

/** @brief �������ϽǺ����꣨�����Ļ�����أ� */
#define CONSOLE_WINDOW_LEFT 15

/** @brief �������Ͻ������꣨�����Ļ�����أ� */
#define CONSOLE_WINDOW_TOP 10

/** @brief ����̨���ݿ�ȣ��ַ��� */
#define CONSOLE_CONTENT_WIDTH 80

/** @brief ����̨���ݸ߶ȣ��ַ��� */
#define CONSOLE_CONTENT_HEIGHT 48

/** @brief ����̨���ڿ�ȣ����أ� */
#define CONSOLE_WINDOW_WIDTH 1024

/** @brief ����̨���ڸ߶ȣ����أ� */
#define CONSOLE_WINDOW_HEIGHT 768

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

/** @brief ���ӱ߿����� */
#define CHESS_BORDER_STYLE PS_DASH

/** @brief ���ӱ߿��� */
#define CHESS_BORDER_WIDTH 2

/** @brief ���ӱ߿���ɫ */
#define CHESS_BORDER_COLOR 0xb0b0b0

/** @brief �����ڲ���ɫ */
#define CHESS_INSIDE_COLOR 0xc0c0c0

/** @brief ���Ӱ뾶 */
#define CHESS_RADIUS 25

/*********************************Ԥ�������*********************************/
#endif