/**
* @brief �й�����˵�����ʵ��
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
#include "win32api.h"
#include "chess.h"
#include "graphics.h"
#include "style.h"
#include "control.h"
#include "menu.h"

/**
* @brief ���ز˵����η�Χ��ʹ�˵�����Ӧ�߿����
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
* @brief ���Ʋ˵�����
*/
void DrawMenuText(char *text, int fontHeight, int fontWidth, RECT rc, int x, int y)
{
    DrawString(text, MENU_TEXT_COLOR, MENU_BACKGROUND_COLOR,
		       0xffffff, 0, 0,
			   fontHeight, fontWidth, MENU_FONT_WEIGHT, MENU_FONT_FAMILY, MENU_FONT_NAME,
			   rc.left+x, rc.top+y);
}

/**
* @brief �������˵��������û�ѡ����¼�
*/
char MainMenuSelect()
{
    char action = ACT_UNKNOWN;
    RECT rc = {300, 230};
    signed char key = -1;
    struct KeyState keyStat={-1, -1, -1, -1};
    //�¼�
    char actionMap[] =
    {
        ACT_START_GAME,
        ACT_LOAD_GAME,
        ACT_STOP_GAME,
        ACT_STOP_GAME
    };
    //��������
    int keyNum = 4;
    //��ֵ
    struct KeyCode keyMap[] =
    {
        {'1', -1},
        {'2', -1},
        {'3', -1},
        {'4', -1}, 
        {27, -1} //Esc��
    };

    DecideMenuRect(rc.left, rc.top, &rc);

    DrawRect(rc.left-5, rc.top-5, rc.right+5, rc.bottom+5,
             0, 0,
             MENU_BACKGROUND_COLOR, MENU_BACKGROUND_COLOR);
    DrawRect(rc.left, rc.top, rc.right, rc.bottom,
             MENU_BORDER_WIDTH, MENU_BORDER_STYLE,
             MENU_BORDER_COLOR, MENU_BACKGROUND_COLOR);
    DrawMenuText("�й�����", MENU_TITLE_FONT_HEIGHT, MENU_TITLE_FONT_WIDTH, rc, 65, 10);
    DrawMenuText("1. ����Ϸ", MENU_FONT_HEIGHT, MENU_FONT_WIDTH, rc, 30, 60);
    DrawMenuText("2. ��ȡ�浵", MENU_FONT_HEIGHT, MENU_FONT_WIDTH, rc, 30, 100);
    DrawMenuText("3. ����˵��", MENU_FONT_HEIGHT, MENU_FONT_WIDTH, rc, 30, 140);
    DrawMenuText("4. �˳���Ϸ", MENU_FONT_HEIGHT, MENU_FONT_WIDTH, rc, 30, 180);

    while (action == ACT_UNKNOWN)
    {
        key = getch();
        action = ParseKey(key, &keyStat, actionMap, (struct KeyCode*)keyMap, keyNum, 1);
    }

    return action;
}

/**
* @brief ������Ϸ�˵��������û�ѡ����¼�
*/
char GameMenuSelect()
{
    char action = ACT_UNKNOWN;
    RECT rc = {300, 190};
    signed char key = -1;
    struct KeyState keyStat={-1, -1, -1, -1};
    //�¼�
    char actionMap[] =
    {
        ACT_BACK_GAME,
        ACT_SAVE_GAME,
        ACT_STOP_GAME,
        ACT_STOP_GAME
    };
    //��������
    int keyNum = 4;
    //��ֵ
    struct KeyCode keyMap[] =
    {
        {'1', -1},
        {'2', -1},
        {'3', -1},
        {27, -1} //Esc��
    };

    DecideMenuRect(rc.left, rc.top, &rc);

    DrawRect(rc.left-5, rc.top-5, rc.right+5, rc.bottom+5,
             0, 0,
             MENU_BACKGROUND_COLOR, MENU_BACKGROUND_COLOR);
    DrawRect(rc.left, rc.top, rc.right, rc.bottom,
             MENU_BORDER_WIDTH, MENU_BORDER_STYLE,
             MENU_BORDER_COLOR, MENU_BACKGROUND_COLOR);
    DrawMenuText("��ѡ�����", MENU_TITLE_FONT_HEIGHT, MENU_TITLE_FONT_WIDTH, rc, 50, 10);
    DrawMenuText("1. ������Ϸ", MENU_FONT_HEIGHT, MENU_FONT_WIDTH, rc, 30, 60);
    DrawMenuText("2. �浵���˳�", MENU_FONT_HEIGHT, MENU_FONT_WIDTH, rc, 30, 100);
    DrawMenuText("3. ������Ϸ", MENU_FONT_HEIGHT, MENU_FONT_WIDTH, rc, 30, 140);

    while (action == ACT_UNKNOWN)
    {
        key = getch();
        action = ParseKey(key, &keyStat, actionMap, (struct KeyCode*)keyMap, keyNum, 1);
    }

    return action;
}

/**
* @brief ������һ�ʤ��Ϸ�˵�
*/
char PlayerWinSelect(char player)
{
    char action = ACT_UNKNOWN;
    RECT rc = {300, 190};
    signed char key = -1;
    struct KeyState keyStat={-1, -1, -1, -1};
    //�¼�
    char actionMap[] =
    {
        ACT_START_GAME,
        ACT_SHOW_STEP,
        ACT_STOP_GAME,
        ACT_STOP_GAME
    };
    //��������
    int keyNum = 4;
    //��ֵ
    struct KeyCode keyMap[] =
    {
        {'1', -1},
        {'2', -1},
        {'3', -1},
        {27, -1} //Esc��
    };

    DecideMenuRect(rc.left, rc.top, &rc);

    DrawRect(rc.left-5, rc.top-5, rc.right+5, rc.bottom+5,
             0, 0,
             MENU_BACKGROUND_COLOR, MENU_BACKGROUND_COLOR);
    DrawRect(rc.left, rc.top, rc.right, rc.bottom,
             MENU_BORDER_WIDTH, MENU_BORDER_STYLE,
             MENU_BORDER_COLOR, MENU_BACKGROUND_COLOR);
    DrawMenuText(player==PLY_RED ? "�췽ʤ" : "�ڷ�ʤ", MENU_TITLE_FONT_HEIGHT, MENU_TITLE_FONT_WIDTH, rc, 80, 10);
    DrawMenuText("1. ���¿�ʼ", MENU_FONT_HEIGHT, MENU_FONT_WIDTH, rc, 30, 60);
    DrawMenuText("2. �鿴�������", MENU_FONT_HEIGHT, MENU_FONT_WIDTH, rc, 30, 100);
    DrawMenuText("3. ������Ϸ", MENU_FONT_HEIGHT, MENU_FONT_WIDTH, rc, 30, 140);

    while (action == ACT_UNKNOWN)
    {
        key = getch();
        action = ParseKey(key, &keyStat, actionMap, (struct KeyCode*)keyMap, keyNum, 1);
    }

    return action;
}