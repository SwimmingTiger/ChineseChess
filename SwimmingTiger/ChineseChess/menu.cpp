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
#include "text.h"

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
        ACT_SHOW_ABOUT,
        ACT_STOP_GAME,
        ACT_STOP_GAME
    };
    //按键数量
    int keyNum = 5;
    //键值
    struct KeyCode keyMap[] =
    {
        /***********增加按键勿忘修改按键数量***********/
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
    DrawMenuText("2. 载入存档", MENU_FONT_HEIGHT, MENU_FONT_WIDTH, rc, 30, 100);
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
    RECT rc = {300, 230};
    signed char key = -1;
    struct KeyState keyStat={-1, -1, -1, -1};
    //事件
    char actionMap[] =
    {
        ACT_BACK_GAME,
        ACT_SAVE_GAME,
        ACT_SHOW_STEP,
        ACT_STOP_GAME,
        ACT_BACK_GAME //Esc键打开、关闭游戏菜单
    };
    //按键数量
    int keyNum = 5;
    //键值
    struct KeyCode keyMap[] =
    {
        /***********增加按键勿忘修改按键数量***********/
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
    DrawMenuText("请选择操作", MENU_TITLE_FONT_HEIGHT, MENU_TITLE_FONT_WIDTH, rc, 50, 10);
    DrawMenuText("1. 返回游戏", MENU_FONT_HEIGHT, MENU_FONT_WIDTH, rc, 30, 60);
    DrawMenuText("2. 存档并退出", MENU_FONT_HEIGHT, MENU_FONT_WIDTH, rc, 30, 100);
    DrawMenuText("3. 查看下棋过程", MENU_FONT_HEIGHT, MENU_FONT_WIDTH, rc, 30, 140);
    DrawMenuText("4. 退出游戏", MENU_FONT_HEIGHT, MENU_FONT_WIDTH, rc, 30, 180);

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
        /***********增加按键勿忘修改按键数量***********/
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
    DrawMenuText("3. 返回主菜单", MENU_FONT_HEIGHT, MENU_FONT_WIDTH, rc, 30, 140);

    while (action == ACT_UNKNOWN)
    {
        key = getch();
        action = ParseKey(key, &keyStat, actionMap, (struct KeyCode*)keyMap, keyNum, 1);
    }

    return action;
}

/**
* @brief 绘制无法存档提示框
*/
void ShowCannotSaveNotice()
{
    RECT rc = {360, 230};

    DecideMenuRect(rc.left, rc.top, &rc);

    DrawRect(rc.left-5, rc.top-5, rc.right+5, rc.bottom+5,
             0, 0,
             MENU_BACKGROUND_COLOR, MENU_BACKGROUND_COLOR);
    DrawRect(rc.left, rc.top, rc.right, rc.bottom,
             MENU_BORDER_WIDTH, MENU_BORDER_STYLE,
             MENU_BORDER_COLOR, MENU_BACKGROUND_COLOR);
    DrawMenuText("游戏无法存档", MENU_TITLE_FONT_HEIGHT, MENU_TITLE_FONT_WIDTH, rc, 55, 10);
    DrawMenuText("游戏数据目录不可写，", MENU_FONT_HEIGHT, MENU_FONT_WIDTH, rc, 30, 60);
    DrawMenuText("您可能无法存档或查", MENU_FONT_HEIGHT, MENU_FONT_WIDTH, rc, 30, 100);
    DrawMenuText("看下棋过程。", MENU_FONT_HEIGHT, MENU_FONT_WIDTH, rc, 30, 140);
    DrawMenuText("按任意键继续...", MENU_TIP_FONT_HEIGHT, MENU_TIP_FONT_WIDTH, rc, 30, 190);

    getch();
}

/**
* @brief 绘制存档失败提示框
*/
void ShowSaveFailedNotice()
{
    RECT rc = {400, 250};

    DecideMenuRect(rc.left, rc.top, &rc);

    DrawRect(rc.left-5, rc.top-5, rc.right+5, rc.bottom+5,
             0, 0,
             MENU_BACKGROUND_COLOR, MENU_BACKGROUND_COLOR);
    DrawRect(rc.left, rc.top, rc.right, rc.bottom,
             MENU_BORDER_WIDTH, MENU_BORDER_STYLE,
             MENU_BORDER_COLOR, MENU_BACKGROUND_COLOR);
    DrawMenuText("存档失败", MENU_TITLE_FONT_HEIGHT, MENU_TITLE_FONT_WIDTH, rc, 100, 10);
    DrawMenuText("写入存档文件失败！", MENU_FONT_HEIGHT, MENU_FONT_WIDTH, rc, 30, 60);
    DrawMenuText("可能是游戏目录不可写，", MENU_FONT_HEIGHT, MENU_FONT_WIDTH, rc, 30, 100);
    DrawMenuText("请尝试用管理员身份运行", MENU_FONT_HEIGHT, MENU_FONT_WIDTH, rc, 30, 140);
    DrawMenuText("游戏。", MENU_FONT_HEIGHT, MENU_FONT_WIDTH, rc, 30, 180);
    DrawMenuText("按任意键返回游戏...", MENU_TIP_FONT_HEIGHT, MENU_TIP_FONT_WIDTH, rc, 30, 220);

    getch();
}

/**
* @brief 绘制载入存档选择框
*/
char LoadSaveSelect(char *title)
{
    RECT rc = {400, 150};
    char action = ACT_UNKNOWN;
    signed char key = -1;
    struct KeyState keyStat={-1, -1, -1, -1};
    //事件
    char actionMap[] =
    {
        10,
        11,
        12,
        13,
        14,
        15,
        16,
        17,
        18,
        19,
        -1,
        -1,
        -1
    };
    //按键数量
    int keyNum = 13;
    //键值
    struct KeyCode keyMap[] =
    {
        /***********增加按键勿忘修改按键数量***********/
        {'0', -1},
        {'1', -1},
        {'2', -1},
        {'3', -1},
        {'4', -1},
        {'5', -1},
        {'6', -1},
        {'7', -1},
        {'8', -1},
        {'9', -1},
        {27, -1}, //Esc键
        {46, -1}, //小键盘小数点键
        {'.', -1} //主键盘小数点键
    };

    DecideMenuRect(rc.left, rc.top, &rc);

    DrawRect(rc.left-5, rc.top-5, rc.right+5, rc.bottom+5,
             0, 0,
             MENU_BACKGROUND_COLOR, MENU_BACKGROUND_COLOR);
    DrawRect(rc.left, rc.top, rc.right, rc.bottom,
             MENU_BORDER_WIDTH, MENU_BORDER_STYLE,
             MENU_BORDER_COLOR, MENU_BACKGROUND_COLOR);
    DrawMenuText(title, MENU_TITLE_FONT_HEIGHT, MENU_TITLE_FONT_WIDTH, rc, 110, 10);
    DrawMenuText("请输入存档序号（0到9）", MENU_FONT_HEIGHT, MENU_FONT_WIDTH, rc, 30, 60);
    DrawMenuText("按Esc或小数点键退出...", MENU_TIP_FONT_HEIGHT, MENU_TIP_FONT_WIDTH, rc, 30, 110);

    while (action == ACT_UNKNOWN)
    {
        key = getch();
        action = ParseKey(key, &keyStat, actionMap, (struct KeyCode*)keyMap, keyNum, 1);
    }

    if (action > 0)
    {
        action -= 10;
    }

    return action;
}

/**
* @brief 绘制无法载入存档提示框
*/
void ShowCannotLoadNotice()
{
    RECT rc = {400, 150};

    DecideMenuRect(rc.left, rc.top, &rc);

    DrawRect(rc.left-5, rc.top-5, rc.right+5, rc.bottom+5,
             0, 0,
             MENU_BACKGROUND_COLOR, MENU_BACKGROUND_COLOR);
    DrawRect(rc.left, rc.top, rc.right, rc.bottom,
             MENU_BORDER_WIDTH, MENU_BORDER_STYLE,
             MENU_BORDER_COLOR, MENU_BACKGROUND_COLOR);
    DrawMenuText("无法载入存档", MENU_TITLE_FONT_HEIGHT, MENU_TITLE_FONT_WIDTH, rc, 70, 10);
    DrawMenuText("存档文件不存在或已损坏", MENU_FONT_HEIGHT, MENU_FONT_WIDTH, rc, 30, 60);
    DrawMenuText("按任意键继续...", MENU_TIP_FONT_HEIGHT, MENU_TIP_FONT_WIDTH, rc, 30, 110);

    getch();
}

/**
* @brief 绘制关于提示框
*/
void ShowAbout()
{
    RECT rc = {460, 375};

    DecideMenuRect(rc.left, rc.top, &rc);

    DrawRect(rc.left-5, rc.top-5, rc.right+5, rc.bottom+5,
             0, 0,
             MENU_BACKGROUND_COLOR, MENU_BACKGROUND_COLOR);
    DrawRect(rc.left, rc.top, rc.right, rc.bottom,
             MENU_BORDER_WIDTH, MENU_BORDER_STYLE,
             MENU_BORDER_COLOR, MENU_BACKGROUND_COLOR);
    DrawMenuText("按键说明", MENU_TITLE_FONT_HEIGHT, MENU_TITLE_FONT_WIDTH, rc, 130, 10);
    DrawMenuText("移动光标：W、A、S、D键或", MENU_FONT_HEIGHT, MENU_FONT_WIDTH, rc, 25, 60);
    DrawMenuText("上下左右方向键。", MENU_FONT_HEIGHT, MENU_FONT_WIDTH, rc, 25, 100);
    DrawMenuText("选择棋子：回车键或空格键。", MENU_FONT_HEIGHT, MENU_FONT_WIDTH, rc, 25, 145);
    DrawMenuText("选择棋子后再次按回车键或", MENU_TIP_FONT_HEIGHT, MENU_TIP_FONT_WIDTH, rc, 65, 185);
    DrawMenuText("空格键将棋子移动到新位置。", MENU_TIP_FONT_HEIGHT, MENU_TIP_FONT_WIDTH, rc, 65, 205);
    DrawMenuText("弹出游戏菜单：Esc键或F8键。", MENU_FONT_HEIGHT, MENU_FONT_WIDTH, rc, 25, 240);
    DrawMenuText("画面残缺或消失，按F5刷新。", MENU_FONT_HEIGHT, MENU_FONT_WIDTH, rc, 25, 285);
    DrawMenuText("按任意键继续...", MENU_TIP_FONT_HEIGHT, MENU_TIP_FONT_WIDTH, rc, 25, 330);

    getch();
}

/**
* @brief 查看下棋过程
*/
void ShowStep(struct ChessBoard *cp)
{
    char path[255];
    char buff[1024];
    FILE *fp;

    sprintf(path, "%s/%s", GAME_SAVE_DIR"/log", cp->logFileName);

    //清空屏幕
    system("cls");
    DrawRect(0, 0, CONSOLE_WINDOW_WIDTH, CONSOLE_WINDOW_HEIGHT, 0, 0, CHESSBOARD_BACKGROUND_COLOR, CHESSBOARD_BACKGROUND_COLOR);

    fp = fopen(path, "r");

    if (fp == NULL)
    {
        printf("\n\t\t*****************************************\n");
        printf("\n\t\t    下棋过程记录文件无法读取，\n\t\t    可能文件已损坏或您尚未开始走棋。\n\t\t    请先走至少一步再来查看下棋过程。\n");
    }
    else
    {
        printf("\n\t\t****************下棋过程*****************\n\n");
        
        while (!feof(fp))
        {
            if (NULL != fgets(buff, 1024, fp))
            {
                printf("\t\t\t    %s", buff);
            }
        }

        fclose(fp);
    }

    printf("\n\t\t*****************************************\n\t\t按任意键继续...");

    getch();
    system("cls");
}