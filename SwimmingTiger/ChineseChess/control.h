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
#define KEYCODE_UP {/*光标上键*/{72,224}, /*w键*/{119,-1}}
/**
* 向下移动光标的键值，写法同 KEYCODE_UP
*/
#define KEYCODE_DOWN {/*光标下键*/{80,224}, /*s键*/{115,-1}}
/**
* 向左移动光标的键值，写法同 KEYCODE_UP
*/
#define KEYCODE_LEFT {/*光标左键*/{75,224}, /*a键*/{97,-1}}
/**
* 向右移动光标的键值，写法同 KEYCODE_UP
*/
#define KEYCODE_RIGHT {/*光标右键*/{77,224}, /*d键*/{100,-1}}
/**
* 锁定/解锁棋子的键值，写法同 KEYCODE_UP
*/
#define KEYCODE_LOCK {/*空格键*/{32,-1}, /*回车键*/{13,-1}}

/********************************数据类型声明********************************/

/**
* @brief 按键状态结构
*/
struct KeyState
{
    char ctrlState; ///< ctrl键状态，0未按下，1按下
    char altState; ///< alt键状态，0未按下，1按下
    char shiftState; ///< shift键状态，0未按下，1按下
    char lastKey; ///< 存储上一个键。如果按键的键值是双字节则存储按键的首字节。
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
};

/**********************************函数声明**********************************/

/*判断按键键值是否在当前键值数组内*/
char MatchKey(signed char key, signed char keycode[][2], int keycodeSize, struct KeyState *keyStat);

/*解析按键键值为动作类型*/
char ParseKey(signed char key, struct KeyState *keyStat);

/*********************************预处理结束*********************************/
#endif