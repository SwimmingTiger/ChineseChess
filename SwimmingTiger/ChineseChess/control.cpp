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
#include <iostream>

using namespace std;

/**
* @brief 判断按键键值是否在当前键值数组内
* 
* 返回值：在返回1，不在返回0
*/
char MatchKey(signed char key, struct KeyCode *keycode, int keycodeSize, struct KeyState *keyStat)
{
    char found = 0;
	int i;

	for (i=0; found==0 && i<keycodeSize; i++)
	{
	    if (keycode->first == key)
		{
			//若键值为单字节，则第二字节为-1；若是组合键或键值为双字节，keyStat中的lastKey应与第二字节相同。
		    if (keycode->second == -1 || keycode->second == keyStat->lastKey)
			{
			    found = 1;
			}
		}

        keycode++;
	}

	return found;
}

/**
* @brief 解析按键键值为动作类型
* 
* 返回值：操作类型枚举
*/
char ParseKey(signed char key, struct KeyState *keyStat, char *actionMap, struct KeyCode *keyMap, int actionSize, int keycodeSize)
{
	char action = ACT_UNKNOWN;
    int i;

    for (i=0; i<actionSize && action==ACT_UNKNOWN; i++)
    {
        if (MatchKey(key, keyMap, keycodeSize, keyStat))
        {
            action = *actionMap;
        }

        keyMap += keycodeSize;
        actionMap++;
    }

	keyStat->lastKey = key;

    return action;
}