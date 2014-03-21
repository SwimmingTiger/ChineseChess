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
#include "text.h"

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
        ACT_SHOW_ABOUT,
        ACT_STOP_GAME,
        ACT_STOP_GAME
    };
    //��������
    int keyNum = 5;
    //��ֵ
    struct KeyCode keyMap[] =
    {
        /***********���Ӱ��������޸İ�������***********/
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
    DrawMenuText("2. ����浵", MENU_FONT_HEIGHT, MENU_FONT_WIDTH, rc, 30, 100);
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
    RECT rc = {300, 230};
    signed char key = -1;
    struct KeyState keyStat={-1, -1, -1, -1};
    //�¼�
    char actionMap[] =
    {
        ACT_BACK_GAME,
        ACT_SAVE_GAME,
        ACT_SHOW_STEP,
        ACT_STOP_GAME,
        ACT_BACK_GAME //Esc���򿪡��ر���Ϸ�˵�
    };
    //��������
    int keyNum = 5;
    //��ֵ
    struct KeyCode keyMap[] =
    {
        /***********���Ӱ��������޸İ�������***********/
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
    DrawMenuText("��ѡ�����", MENU_TITLE_FONT_HEIGHT, MENU_TITLE_FONT_WIDTH, rc, 50, 10);
    DrawMenuText("1. ������Ϸ", MENU_FONT_HEIGHT, MENU_FONT_WIDTH, rc, 30, 60);
    DrawMenuText("2. �浵���˳�", MENU_FONT_HEIGHT, MENU_FONT_WIDTH, rc, 30, 100);
    DrawMenuText("3. �鿴�������", MENU_FONT_HEIGHT, MENU_FONT_WIDTH, rc, 30, 140);
    DrawMenuText("4. �˳���Ϸ", MENU_FONT_HEIGHT, MENU_FONT_WIDTH, rc, 30, 180);

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
        /***********���Ӱ��������޸İ�������***********/
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
    DrawMenuText("3. �������˵�", MENU_FONT_HEIGHT, MENU_FONT_WIDTH, rc, 30, 140);

    while (action == ACT_UNKNOWN)
    {
        key = getch();
        action = ParseKey(key, &keyStat, actionMap, (struct KeyCode*)keyMap, keyNum, 1);
    }

    return action;
}

/**
* @brief �����޷��浵��ʾ��
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
    DrawMenuText("��Ϸ�޷��浵", MENU_TITLE_FONT_HEIGHT, MENU_TITLE_FONT_WIDTH, rc, 55, 10);
    DrawMenuText("��Ϸ����Ŀ¼����д��", MENU_FONT_HEIGHT, MENU_FONT_WIDTH, rc, 30, 60);
    DrawMenuText("�������޷��浵���", MENU_FONT_HEIGHT, MENU_FONT_WIDTH, rc, 30, 100);
    DrawMenuText("��������̡�", MENU_FONT_HEIGHT, MENU_FONT_WIDTH, rc, 30, 140);
    DrawMenuText("�����������...", MENU_TIP_FONT_HEIGHT, MENU_TIP_FONT_WIDTH, rc, 30, 190);

    getch();
}

/**
* @brief ���ƴ浵ʧ����ʾ��
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
    DrawMenuText("�浵ʧ��", MENU_TITLE_FONT_HEIGHT, MENU_TITLE_FONT_WIDTH, rc, 100, 10);
    DrawMenuText("д��浵�ļ�ʧ�ܣ�", MENU_FONT_HEIGHT, MENU_FONT_WIDTH, rc, 30, 60);
    DrawMenuText("��������ϷĿ¼����д��", MENU_FONT_HEIGHT, MENU_FONT_WIDTH, rc, 30, 100);
    DrawMenuText("�볢���ù���Ա�������", MENU_FONT_HEIGHT, MENU_FONT_WIDTH, rc, 30, 140);
    DrawMenuText("��Ϸ��", MENU_FONT_HEIGHT, MENU_FONT_WIDTH, rc, 30, 180);
    DrawMenuText("�������������Ϸ...", MENU_TIP_FONT_HEIGHT, MENU_TIP_FONT_WIDTH, rc, 30, 220);

    getch();
}

/**
* @brief ��������浵ѡ���
*/
char LoadSaveSelect(char *title)
{
    RECT rc = {400, 150};
    char action = ACT_UNKNOWN;
    signed char key = -1;
    struct KeyState keyStat={-1, -1, -1, -1};
    //�¼�
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
    //��������
    int keyNum = 13;
    //��ֵ
    struct KeyCode keyMap[] =
    {
        /***********���Ӱ��������޸İ�������***********/
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
        {27, -1}, //Esc��
        {46, -1}, //С����С�����
        {'.', -1} //������С�����
    };

    DecideMenuRect(rc.left, rc.top, &rc);

    DrawRect(rc.left-5, rc.top-5, rc.right+5, rc.bottom+5,
             0, 0,
             MENU_BACKGROUND_COLOR, MENU_BACKGROUND_COLOR);
    DrawRect(rc.left, rc.top, rc.right, rc.bottom,
             MENU_BORDER_WIDTH, MENU_BORDER_STYLE,
             MENU_BORDER_COLOR, MENU_BACKGROUND_COLOR);
    DrawMenuText(title, MENU_TITLE_FONT_HEIGHT, MENU_TITLE_FONT_WIDTH, rc, 110, 10);
    DrawMenuText("������浵��ţ�0��9��", MENU_FONT_HEIGHT, MENU_FONT_WIDTH, rc, 30, 60);
    DrawMenuText("��Esc��С������˳�...", MENU_TIP_FONT_HEIGHT, MENU_TIP_FONT_WIDTH, rc, 30, 110);

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
* @brief �����޷�����浵��ʾ��
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
    DrawMenuText("�޷�����浵", MENU_TITLE_FONT_HEIGHT, MENU_TITLE_FONT_WIDTH, rc, 70, 10);
    DrawMenuText("�浵�ļ������ڻ�����", MENU_FONT_HEIGHT, MENU_FONT_WIDTH, rc, 30, 60);
    DrawMenuText("�����������...", MENU_TIP_FONT_HEIGHT, MENU_TIP_FONT_WIDTH, rc, 30, 110);

    getch();
}

/**
* @brief ���ƹ�����ʾ��
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
    DrawMenuText("����˵��", MENU_TITLE_FONT_HEIGHT, MENU_TITLE_FONT_WIDTH, rc, 130, 10);
    DrawMenuText("�ƶ���꣺W��A��S��D����", MENU_FONT_HEIGHT, MENU_FONT_WIDTH, rc, 25, 60);
    DrawMenuText("�������ҷ������", MENU_FONT_HEIGHT, MENU_FONT_WIDTH, rc, 25, 100);
    DrawMenuText("ѡ�����ӣ��س�����ո����", MENU_FONT_HEIGHT, MENU_FONT_WIDTH, rc, 25, 145);
    DrawMenuText("ѡ�����Ӻ��ٴΰ��س�����", MENU_TIP_FONT_HEIGHT, MENU_TIP_FONT_WIDTH, rc, 65, 185);
    DrawMenuText("�ո���������ƶ�����λ�á�", MENU_TIP_FONT_HEIGHT, MENU_TIP_FONT_WIDTH, rc, 65, 205);
    DrawMenuText("������Ϸ�˵���Esc����F8����", MENU_FONT_HEIGHT, MENU_FONT_WIDTH, rc, 25, 240);
    DrawMenuText("�����ȱ����ʧ����F5ˢ�¡�", MENU_FONT_HEIGHT, MENU_FONT_WIDTH, rc, 25, 285);
    DrawMenuText("�����������...", MENU_TIP_FONT_HEIGHT, MENU_TIP_FONT_WIDTH, rc, 25, 330);

    getch();
}

/**
* @brief �鿴�������
*/
void ShowStep(struct ChessBoard *cp)
{
    char path[255];
    char buff[1024];
    FILE *fp;

    sprintf(path, "%s/%s", GAME_SAVE_DIR"/log", cp->logFileName);

    //�����Ļ
    system("cls");
    DrawRect(0, 0, CONSOLE_WINDOW_WIDTH, CONSOLE_WINDOW_HEIGHT, 0, 0, CHESSBOARD_BACKGROUND_COLOR, CHESSBOARD_BACKGROUND_COLOR);

    fp = fopen(path, "r");

    if (fp == NULL)
    {
        printf("\n\t\t*****************************************\n");
        printf("\n\t\t    ������̼�¼�ļ��޷���ȡ��\n\t\t    �����ļ����𻵻�����δ��ʼ���塣\n\t\t    ����������һ�������鿴������̡�\n");
    }
    else
    {
        printf("\n\t\t****************�������*****************\n\n");
        
        while (!feof(fp))
        {
            if (NULL != fgets(buff, 1024, fp))
            {
                printf("\t\t\t    %s", buff);
            }
        }

        fclose(fp);
    }

    printf("\n\t\t*****************************************\n\t\t�����������...");

    getch();
    system("cls");
}