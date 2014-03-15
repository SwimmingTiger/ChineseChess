/**
* @brief 中国象棋控制函数实现
* 
* - 作者信息
*     - 作者：彭逸豪
*     - 班级：软件131班
*     - 学院：计算机科学与工程学院
*     - 学校：大连民族学院
*/
#include <stdio.h>
#include <conio.h>
#include <windows.h>
#include "graphics.h"
#include "chess.h"
#include "control.h"

/**
* @brief 判断按键键值是否在当前键值数组内
* 
* 返回值：在返回1，不在返回0
*/
char MatchKey(signed char key, signed char keycode[][2], int keycodeSize, struct KeyState *keyStat)
{
    char found = 0;
	int i;

	for (i=0; found==0 && i<keycodeSize; i++)
	{
	    if (keycode[i][0] == key)
		{
			//若键值为单字节，则第二字节为-1；若是组合键或键值为双字节，keyStat中的lastKey应与第二字节相同。
		    if (keycode[i][1] == -1 || keycode[i][1] == keyStat->lastKey)
			{
			    found = 1;
			}
		}
	}

	return found;
}

/**
* @brief 解析按键键值为动作类型
* 
* 返回值：操作类型枚举
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