/**
* @brief �й�������ƺ���ʵ��
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
#include "graphics.h"
#include "chess.h"
#include "control.h"

/**
* @brief ����������ֵΪ��������
* 
* ����ֵ����������ö��
*/
char ParseKey(char key, struct KeyStatus *keyStat)
{
    char keycodeUp[KEYCODE_MAX_NUM][2] = KEYCODE_UP;
    char keycodeDown[KEYCODE_MAX_NUM][2] = KEYCODE_DOWN;
    char keycodeLeft[KEYCODE_MAX_NUM][2] = KEYCODE_LEFT;
    char keycodeRight[KEYCODE_MAX_NUM][2] = KEYCODE_RIGHT;
    char keycodeLock[KEYCODE_MAX_NUM][2] = KEYCODE_LOCK;

    return 0;
}