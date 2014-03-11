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
* @brief 解析按键键值为操作类型
* 
* 返回值：操作类型枚举
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