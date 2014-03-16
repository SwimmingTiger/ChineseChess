#ifndef _CONTROL_H_
/**
* @brief 中国象棋游戏按键及控制函数声明
* 
* - 作者信息
*     - 作者：彭逸豪
*     - 班级：软件131班
*     - 学院：计算机科学与工程学院
*     - 学校：大连民族学院
*/
#define _CONTROL_H_

/**********************************常量声明**********************************/

/**
* @brief 每个操作最多绑定的按键数量
* 
* 如果增加了按键数量则需要修改该常量
*/
#define KEYCODE_MAX_NUM 2

/**
* @brief 向上移动光标的键值表
* 
* 一个二维数组（char [KEYCODE_MAX_NUM][2]），
* char [x][0]和char [x][1]构成一个按键。
* 双字节键值倒过来写（比如光标上键键值为224 72，这里写成{72,224}），
* 单字节键值则让第二个成员为-1，如w键键值为119，写成{119,-1}。
* 
* 如果增加了按键数量，则需要增加常量KEYCODE_MAX_NUM的值。
*/
#define KEYCODE_UP {/*光标上键*/{(char)72,(char)224}, /*w键*/{(char)119,(char)-1}}
/**
* 向下移动光标的键值，写法同 KEYCODE_UP
*/
#define KEYCODE_DOWN {/*光标下键*/{(char)80,(char)224}, /*s键*/{(char)115,(char)-1}}
/**
* 向左移动光标的键值，写法同 KEYCODE_UP
*/
#define KEYCODE_LEFT {/*光标左键*/{(char)75,(char)224}, /*a键*/{(char)97,(char)-1}}
/**
* 向右移动光标的键值，写法同 KEYCODE_UP
*/
#define KEYCODE_RIGHT {/*光标右键*/{(char)77,(char)224}, /*d键*/{(char)100,(char)-1}}
/**
* 锁定/解锁棋子的键值，写法同 KEYCODE_UP
*/
#define KEYCODE_LOCK {/*空格键*/{(char)32,(char)-1}, /*回车键*/{(char)13,(char)-1}}
/**
* 结束游戏的键值，写法同 KEYCODE_UP
*/
#define KEYCODE_STOP_GAME {/*Esc键*/{(char)27,(char)-1}, /*F12键*/{(char)134,(char)224}}
/**
* 刷新屏幕显示，写法同 KEYCODE_UP
*/
#define KEYCODE_REFRESH_SCREEN {/*F5键*/{(char)63,(char)0}, /*退格键*/{(char)8,(char)-1}}
/**
* 用于游戏操作的按键数量
* 
* 上面定义了几种按键类型，这里就是几
*/
#define GAME_CONTROL_KEY_NUM 7

/********************************数据类型声明********************************/

/**
* @brief 按键状态结构
*/
struct KeyState
{
    char ctrlState; ///< ctrl键状态，0未按下，1按下
    char altState; ///< alt键状态，0未按下，1按下
    char shiftState; ///< shift键状态，0未按下，1按下
    signed char lastKey; ///< 存储上一个键。如果按键的键值是双字节则存储按键的首字节。
};

/**
* @brief 按键键值结构
*/
struct KeyCode
{
    signed char first;
    signed char second;
};

/**
* @brief 动作类型枚举
*/
enum ActionType
{
    ACT_UNKNOWN, ///< 未知动作
    ACT_KEY_UP, ///< 向上移动光标
    ACT_KEY_DOWN, ///< 向下移动光标
    ACT_KEY_LEFT, ///< 向左移动光标
    ACT_KEY_RIGHT, ///< 向右移动光标
    ACT_KEY_LOCK, ///< 锁定/解锁棋子（锁定棋子再移动光标时棋子也相应移动，再解锁棋子将其放到新位置）
    ACT_STOP_GAME, ///< 结束游戏
    ACT_PAUSE_GAME, ///< 暂停游戏
    ACT_RESTART_GAME, ///< 重新开始游戏
    ACT_REFRESH_SCREEN, ///< 刷新屏幕显示
};

/**********************************函数声明**********************************/

/*判断按键键值是否在当前键值数组内*/
char MatchKey(signed char key, struct KeyCode *keycode, int keycodeSize, struct KeyState *keyStat);

/*解析按键键值为动作类型*/
char ParseKey(signed char key, struct KeyState *keyStat, char *actionMap, struct KeyCode *keyMap, int actionSize, int keycodeSize);

/*********************************预处理结束*********************************/
#endif