/**
* @brief 中国象棋菜单函数实现
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
#include "win32api.h"
#include "chess.h"
#include "graphics.h"
#include "style.h"
#include "control.h"
#include "menu.h"

/**
* @brief 返回菜单矩形范围，使菜单自适应高宽居中
*/
void DecideMenuRect(int width, int height, RECT *rc)
{
    RECT windowRc;

    GetClientRect(GetConsoleWindow(),&windowRc);

    rc->top = windowRc.top + (windowRc.bottom - windowRc.top - height)/2;
    rc->left = windowRc.left + (windowRc.right - windowRc.left - width)/2;
    rc->bottom = rc->top + height;
    rc->right = rc->left + width;
}

/**
* @brief 绘制菜单文字
*/
void DrawMenuText(char *text, int fontHeight, int fontWidth, RECT rc, int x, int y)
{
    DrawString(text, MENU_TEXT_COLOR, MENU_BACKGROUND_COLOR,
		       0xffffff, 0, 0,
			   fontHeight, fontWidth, MENU_FONT_WEIGHT, MENU_FONT_FAMILY, MENU_FONT_NAME,
			   rc.left+x, rc.top+y);
}

/**
* @brief 绘制主菜单并返回用户选择的事件
*/
char MainMenuSelect()
{
    char action = ACT_UNKNOWN;
    RECT rc = {300, 230};
    signed char key = -1;
    struct KeyState keyStat={-1, -1, -1, -1};
    //事件
    char actionMap[] =
    {
        ACT_START_GAME,
        ACT_LOAD_GAME,
        ACT_STOP_GAME,
        ACT_STOP_GAME
    };
    //按键数量
    int keyNum = 4;
    //键值
    struct KeyCode keyMap[] =
    {
        {'1', -1},
        {'2', -1},
        {'3', -1},
        {'4', -1}, 
        {27, -1} //Esc键
    };

    DecideMenuRect(rc.left, rc.top, &rc);

    DrawRect(rc.left-5, rc.top-5, rc.right+5, rc.bottom+5,
             0, 0,
             MENU_BACKGROUND_COLOR, MENU_BACKGROUND_COLOR);
    DrawRect(rc.left, rc.top, rc.right, rc.bottom,
             MENU_BORDER_WIDTH, MENU_BORDER_STYLE,
             MENU_BORDER_COLOR, MENU_BACKGROUND_COLOR);
    DrawMenuText("中国象棋", MENU_TITLE_FONT_HEIGHT, MENU_TITLE_FONT_WIDTH, rc, 65, 10);
    DrawMenuText("1. 新游戏", MENU_FONT_HEIGHT, MENU_FONT_WIDTH, rc, 30, 60);
    DrawMenuText("2. 读取存档", MENU_FONT_HEIGHT, MENU_FONT_WIDTH, rc, 30, 100);
    DrawMenuText("3. 按键说明", MENU_FONT_HEIGHT, MENU_FONT_WIDTH, rc, 30, 140);
    DrawMenuText("4. 退出游戏", MENU_FONT_HEIGHT, MENU_FONT_WIDTH, rc, 30, 180);

    while (action == ACT_UNKNOWN)
    {
        key = getch();
        action = ParseKey(key, &keyStat, actionMap, (struct KeyCode*)keyMap, keyNum, 1);
    }

    return action;
}

/**
* @brief 绘制游戏菜单并返回用户选择的事件
*/
char GameMenuSelect()
{
    char action = ACT_UNKNOWN;
    RECT rc = {300, 190};
    signed char key = -1;
    struct KeyState keyStat={-1, -1, -1, -1};
    //事件
    char actionMap[] =
    {
        ACT_BACK_GAME,
        ACT_SAVE_GAME,
        ACT_STOP_GAME,
        ACT_STOP_GAME
    };
    //按键数量
    int keyNum = 4;
    //键值
    struct KeyCode keyMap[] =
    {
        {'1', -1},
        {'2', -1},
        {'3', -1},
        {27, -1} //Esc键
    };

    DecideMenuRect(rc.left, rc.top, &rc);

    DrawRect(rc.left-5, rc.top-5, rc.right+5, rc.bottom+5,
             0, 0,
             MENU_BACKGROUND_COLOR, MENU_BACKGROUND_COLOR);
    DrawRect(rc.left, rc.top, rc.right, rc.bottom,
             MENU_BORDER_WIDTH, MENU_BORDER_STYLE,
             MENU_BORDER_COLOR, MENU_BACKGROUND_COLOR);
    DrawMenuText("请选择操作", MENU_TITLE_FONT_HEIGHT, MENU_TITLE_FONT_WIDTH, rc, 50, 10);
    DrawMenuText("1. 返回游戏", MENU_FONT_HEIGHT, MENU_FONT_WIDTH, rc, 30, 60);
    DrawMenuText("2. 存档并退出", MENU_FONT_HEIGHT, MENU_FONT_WIDTH, rc, 30, 100);
    DrawMenuText("3. 结束游戏", MENU_FONT_HEIGHT, MENU_FONT_WIDTH, rc, 30, 140);

    while (action == ACT_UNKNOWN)
    {
        key = getch();
        action = ParseKey(key, &keyStat, actionMap, (struct KeyCode*)keyMap, keyNum, 1);
    }

    return action;
}

/**
* @brief 绘制玩家获胜游戏菜单
*/
char PlayerWinSelect(char player)
{
    char action = ACT_UNKNOWN;
    RECT rc = {300, 190};
    signed char key = -1;
    struct KeyState keyStat={-1, -1, -1, -1};
    //事件
    char actionMap[] =
    {
        ACT_START_GAME,
        ACT_SHOW_STEP,
        ACT_STOP_GAME,
        ACT_STOP_GAME
    };
    //按键数量
    int keyNum = 4;
    //键值
    struct KeyCode keyMap[] =
    {
        {'1', -1},
        {'2', -1},
        {'3', -1},
        {27, -1} //Esc键
    };

    DecideMenuRect(rc.left, rc.top, &rc);

    DrawRect(rc.left-5, rc.top-5, rc.right+5, rc.bottom+5,
             0, 0,
             MENU_BACKGROUND_COLOR, MENU_BACKGROUND_COLOR);
    DrawRect(rc.left, rc.top, rc.right, rc.bottom,
             MENU_BORDER_WIDTH, MENU_BORDER_STYLE,
             MENU_BORDER_COLOR, MENU_BACKGROUND_COLOR);
    DrawMenuText(player==PLY_RED ? "红方胜" : "黑方胜", MENU_TITLE_FONT_HEIGHT, MENU_TITLE_FONT_WIDTH, rc, 80, 10);
    DrawMenuText("1. 重新开始", MENU_FONT_HEIGHT, MENU_FONT_WIDTH, rc, 30, 60);
    DrawMenuText("2. 查看下棋过程", MENU_FONT_HEIGHT, MENU_FONT_WIDTH, rc, 30, 100);
    DrawMenuText("3. 结束游戏", MENU_FONT_HEIGHT, MENU_FONT_WIDTH, rc, 30, 140);

    while (action == ACT_UNKNOWN)
    {
        key = getch();
        action = ParseKey(key, &keyStat, actionMap, (struct KeyCode*)keyMap, keyNum, 1);
    }

    return action;
}