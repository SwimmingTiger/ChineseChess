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


/** @brief ǰ��������ɫ�������� */
#define CHESSBOARD_COLOR "color 3D"

/** @brief ���ڿ�ȣ��ַ��� */
#define CHESSBOARD_WINDOW_WIDTH 40

/** @brief ���ڸ߶ȣ��ַ��� */
#define CHESSBOARD_WINDOW_HEIGHT 20

/** @brief �����п����أ� */
#define CHESSBOARD_ROW_WIDTH 40

/** @brief �����иߣ����أ� */
#define CHESSBOARD_LINE_HEIGHT 50

/** @brief ������ߺ����꣨���أ� */
#define CHESSBOARD_RECT_LEFT 10

/** @brief ���̶��������꣨���أ� */
#define CHESSBOARD_RECT_TOP 10

/** @brief ���̿�ȣ����أ� */
#define CHESSBOARD_WIDTH (CHESSBOARD_ROW_WIDTH*8)

/** @brief ���̸߶ȣ����أ� */
#define CHESSBOARD_HEIGHT (CHESSBOARD_LINE_HEIGHT*9)

/** @brief �����ұߺ����꣨���أ� */
#define CHESSBOARD_RECT_RIGHT (CHESSBOARD_WIDTH+CHESSBOARD_RECT_LEFT)

/** @brief ���̵ױ������꣨���أ� */
#define CHESSBOARD_RECT_BOTTOM (CHESSBOARD_HEIGHT+CHESSBOARD_RECT_TOP)


#endif