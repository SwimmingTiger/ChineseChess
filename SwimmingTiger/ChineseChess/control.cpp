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
* @brief �жϰ�����ֵ�Ƿ��ڵ�ǰ��ֵ������
* 
* ����ֵ���ڷ���1�����ڷ���0
*/
char MatchKey(signed char key, signed char keycode[][2], int keycodeSize, struct KeyState *keyStat)
{
    char found = 0;
	int i;

	for (i=0; found==0 && i<keycodeSize; i++)
	{
	    if (keycode[i][0] == key)
		{
			//����ֵΪ���ֽڣ���ڶ��ֽ�Ϊ-1��������ϼ����ֵΪ˫�ֽڣ�keyStat�е�lastKeyӦ��ڶ��ֽ���ͬ��
		    if (keycode[i][1] == -1 || keycode[i][1] == keyStat->lastKey)
			{
			    found = 1;
			}
		}
	}

	return found;
}

/**
* @brief ����������ֵΪ��������
* 
* ����ֵ����������ö��
*/
char ParseKey(signed char key, struct KeyState *keyStat)
{
    signed char keycodeUp[KEYCODE_MAX_NUM][2] = KEYCODE_UP;
    signed char keycodeDown[KEYCODE_MAX_NUM][2] = KEYCODE_DOWN;
    signed char keycodeLeft[KEYCODE_MAX_NUM][2] = KEYCODE_LEFT;
    signed char keycodeRight[KEYCODE_MAX_NUM][2] = KEYCODE_RIGHT;
    signed char keycodeLock[KEYCODE_MAX_NUM][2] = KEYCODE_LOCK;
    signed char keycodeStopGame[KEYCODE_MAX_NUM][2] = KEYCODE_STOP_GAME;
	char action = ACT_UNKNOWN;

    if (MatchKey(key, keycodeUp, KEYCODE_MAX_NUM, keyStat))
	{
	    action = ACT_KEY_UP;
	}
	else if (MatchKey(key, keycodeDown, KEYCODE_MAX_NUM, keyStat))
	{
	    action = ACT_KEY_DOWN;
	}
	else if (MatchKey(key, keycodeLeft, KEYCODE_MAX_NUM, keyStat))
	{
	    action = ACT_KEY_LEFT;
	}
	else if (MatchKey(key, keycodeRight, KEYCODE_MAX_NUM, keyStat))
	{
	    action = ACT_KEY_RIGHT;
	}
	else if (MatchKey(key, keycodeLock, KEYCODE_MAX_NUM, keyStat))
	{
	    action = ACT_KEY_LOCK;
	}
    else if (MatchKey(key, keycodeStopGame, KEYCODE_MAX_NUM, keyStat))
	{
	    action = ACT_STOP_GAME;
	}

	keyStat->lastKey = key;

    return action;
}