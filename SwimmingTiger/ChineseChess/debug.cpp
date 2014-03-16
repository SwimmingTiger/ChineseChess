/**
* @brief 中国象棋调试与错误处理函数实现
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

/**
* @brief 输出错误提示
*/
void printErr(char *str)
{
    system("cls");
    printf("%s", str);
    getch();
}