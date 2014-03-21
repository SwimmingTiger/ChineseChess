#ifndef _CONTROL_H_
/**
* @brief �й�������Ϸ���������ƺ�������
* 
* - ������Ϣ
*     - ���ߣ����ݺ�
*     - �༶�����131��
*     - ѧԺ���������ѧ�빤��ѧԺ
*     - ѧУ����������ѧԺ
*/
#define _CONTROL_H_

/**********************************��������**********************************/

/**
* @brief ÿ���������󶨵İ�������
* 
* ��������˰�����������Ҫ�޸ĸó���
*/
#define KEYCODE_MAX_NUM 2

/**
* @brief �����ƶ����ļ�ֵ��
* 
* һ����ά���飨char [KEYCODE_MAX_NUM][2]����
* char [x][0]��char [x][1]����һ��������
* ˫�ֽڼ�ֵ������д���������ϼ���ֵΪ224 72������д��{72,224}����
* ���ֽڼ�ֵ���õڶ�����ԱΪ-1����w����ֵΪ119��д��{119,-1}��
* 
* ��������˰�������������Ҫ���ӳ���KEYCODE_MAX_NUM��ֵ��
*/
#define KEYCODE_UP {/*����ϼ�*/{(char)72,(char)224}, /*w��*/{(char)119,(char)-1}}
/**
* �����ƶ����ļ�ֵ��д��ͬ KEYCODE_UP
*/
#define KEYCODE_DOWN {/*����¼�*/{(char)80,(char)224}, /*s��*/{(char)115,(char)-1}}
/**
* �����ƶ����ļ�ֵ��д��ͬ KEYCODE_UP
*/
#define KEYCODE_LEFT {/*������*/{(char)75,(char)224}, /*a��*/{(char)97,(char)-1}}
/**
* �����ƶ����ļ�ֵ��д��ͬ KEYCODE_UP
*/
#define KEYCODE_RIGHT {/*����Ҽ�*/{(char)77,(char)224}, /*d��*/{(char)100,(char)-1}}
/**
* ����/�������ӵļ�ֵ��д��ͬ KEYCODE_UP
*/
#define KEYCODE_LOCK {/*�ո��*/{(char)32,(char)-1}, /*�س���*/{(char)13,(char)-1}}
/**
* ������Ϸ�ļ�ֵ��д��ͬ KEYCODE_UP
*/
#define KEYCODE_SHOW_MENU {/*Esc��*/{(char)27,(char)-1}, /*F8��*/{(char)66,(char)0}}
/**
* ������Ϸ�ļ�ֵ��д��ͬ KEYCODE_UP
*/
#define KEYCODE_SAVE_GAME {/*F6��*/{(char)64,(char)0}, /*F9��*/{(char)67,(char)0}}
/**
* ������Ϸ�ļ�ֵ��д��ͬ KEYCODE_UP
*/
#define KEYCODE_LOAD_GAME {/*F7��*/{(char)65,(char)0}, /*F10��*/{(char)68,(char)0}}

/**
* ˢ����Ļ��ʾ��д��ͬ KEYCODE_UP
*/
#define KEYCODE_REFRESH_SCREEN {/*F5��*/{(char)63,(char)0}, /*�˸��*/{(char)8,(char)-1}}
/**
* ������Ϸ�����İ�������
* 
* ���涨���˼��ְ������ͣ�������Ǽ�
*/
#define GAME_CONTROL_KEY_NUM 9

/********************************������������********************************/

/**
* @brief ����״̬�ṹ
*/
struct KeyState
{
    char ctrlState; ///< ctrl��״̬��0δ���£�1����
    char altState; ///< alt��״̬��0δ���£�1����
    char shiftState; ///< shift��״̬��0δ���£�1����
    signed char lastKey; ///< �洢��һ��������������ļ�ֵ��˫�ֽ���洢���������ֽڡ�
};

/**
* @brief ������ֵ�ṹ
*/
struct KeyCode
{
    signed char first;
    signed char second;
};

/**
* @brief ��������ö��
*/
enum ActionType
{
    ACT_UNKNOWN, ///< δ֪����
    ACT_KEY_UP, ///< �����ƶ����
    ACT_KEY_DOWN, ///< �����ƶ����
    ACT_KEY_LEFT, ///< �����ƶ����
    ACT_KEY_RIGHT, ///< �����ƶ����
    ACT_KEY_LOCK, ///< ����/�������ӣ������������ƶ����ʱ����Ҳ��Ӧ�ƶ����ٽ������ӽ���ŵ���λ�ã�
    ACT_STOP_GAME, ///< ������Ϸ
    ACT_BACK_GAME, ///< ������Ϸ
    ACT_START_GAME, ///< ��ʼ��Ϸ
    ACT_SAVE_GAME, ///<������Ϸ
    ACT_LOAD_GAME, ///< ������Ϸ
    ACT_SHOW_MENU, ///< ��ʾ�˵�
    ACT_SHOW_STEP, ///< �鿴�������
    ACT_REFRESH_SCREEN, ///< ˢ����Ļ��ʾ
    ACT_SHOW_ABOUT, ///< ��ʾ���ڲ˵�
};

/**********************************��������**********************************/

/*�жϰ�����ֵ�Ƿ��ڵ�ǰ��ֵ������*/
char MatchKey(signed char key, struct KeyCode *keycode, int keycodeSize, struct KeyState *keyStat);

/*����������ֵΪ��������*/
char ParseKey(signed char key, struct KeyState *keyStat, char *actionMap, struct KeyCode *keyMap, int actionSize, int keycodeSize);

/*********************************Ԥ�������*********************************/
#endif