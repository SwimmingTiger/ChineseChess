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
#include <iostream>

using namespace std;

/**
* @brief �жϰ�����ֵ�Ƿ��ڵ�ǰ��ֵ������
* 
* ����ֵ���ڷ���1�����ڷ���0
*/
char MatchKey(signed char key, struct KeyCode *keycode, int keycodeSize, struct KeyState *keyStat)
{
    char found = 0;
	int i;

	for (i=0; found==0 && i<keycodeSize; i++)
	{
	    if (keycode->first == key)
		{
			//����ֵΪ���ֽڣ���ڶ��ֽ�Ϊ-1��������ϼ����ֵΪ˫�ֽڣ�keyStat�е�lastKeyӦ��ڶ��ֽ���ͬ��
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
* @brief ����������ֵΪ��������
* 
* ����ֵ����������ö��
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