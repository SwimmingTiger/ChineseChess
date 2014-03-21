#ifndef _MENU_H_
/**
* @brief 中国象棋游戏菜单函数声明
* 
* - 作者信息
*     - 作者：彭逸豪
*     - 班级：软件131班
*     - 学院：计算机科学与工程学院
*     - 学校：大连民族学院
*/
#define _MENU_H_

/**********************************常量声明**********************************/

/**********************菜单样式*********************/

/** @brief 菜单边框类型 */
#define MENU_BORDER_STYLE 0

/** @brief 菜单边框宽度 */
#define MENU_BORDER_WIDTH 1

/** @brief 菜单字体高度 */
#define MENU_FONT_HEIGHT 30

/** @brief 菜单字体宽度 */
#define MENU_FONT_WIDTH 15

/** @brief 菜单字体粗细 */
#define MENU_FONT_WEIGHT 700

/** @brief 菜单标题字体高度 */
#define MENU_TITLE_FONT_HEIGHT 40

/** @brief 菜单标题字体宽度 */
#define MENU_TITLE_FONT_WIDTH 20

/** @brief 菜单注解字体高度 */
#define MENU_TIP_FONT_HEIGHT 20

/** @brief 菜单注解字体宽度 */
#define MENU_TIP_FONT_WIDTH 10

/** @brief 菜单字体粗细 */
#define MENU_FONT_WEIGHT 700

/**
* @brief 菜单字体族
* 
* 可取下列值之一：
* FF_DECORATIVE：新奇的字体
* FF_DONTCARE：不关心或不知道
* FF_MODERN：等宽字体
* FF_ROMAN：衬线非等宽字体
* FF_SCRIPT：手写体
* FF_SWISS：无衬线非等宽字体
*/
#define MENU_FONT_FAMILY FF_SCRIPT

/** @brief 菜单字体名 */
#define MENU_FONT_NAME "黑体"

/** @brief 菜单边框颜色 */
#define MENU_BORDER_COLOR 0x0000ff

/** @brief 菜单文字颜色 */
#define MENU_TEXT_COLOR 0x000000

/** @brief 菜单背景颜色 */
#define MENU_BACKGROUND_COLOR 0xc0c0c0

/**********************************函数声明**********************************/

/*返回菜单矩形范围，使菜单自适应高宽居中*/
void DecideMenuRect(int width, int height, RECT *rc);

/*绘制主菜单并返回用户选择的事件*/
char MainMenuSelect();

/*绘制游戏菜单并返回用户选择的事件*/
char GameMenuSelect();

/*绘制玩家获胜游戏菜单*/
char PlayerWinSelect(char player);

/*绘制无法存档提示框*/
void ShowCannotSaveNotice();

/*绘制无法载入存档提示框*/
void ShowCannotLoadNotice();

/*绘制关于提示框*/
void ShowAbout();

/*查看下棋过程*/
void ShowStep(struct ChessBoard *cp);

/*********************************预处理结束*********************************/
#endif