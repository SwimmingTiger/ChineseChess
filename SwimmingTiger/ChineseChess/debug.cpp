/**
* @brief �й�����������������ʵ��
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

/**
* @brief ���������ʾ
*/
void printErr(char *str)
{
    system("cls");
    printf("%s", str);
    getch();
}