#ifndef _STYLE_H_
/**
* @brief 中国象棋游戏界面样式声明
* 
* - 作者信息
*     - 作者：彭逸豪
*     - 班级：软件131班
*     - 学院：计算机科学与工程学院
*     - 学校：大连民族学院
*/
#define _STYLE_H_

/**********************************常量声明**********************************/

/** @brief 前景背景颜色设置命令 */
#define CONSOLE_COLOR "color 60"

/** @brief 窗口左上角横坐标（相对屏幕，像素） */
#define CONSOLE_WINDOW_LEFT 15

/** @brief 窗口左上角纵坐标（相对屏幕，像素） */
#define CONSOLE_WINDOW_TOP 10

/** @brief 控制台内容宽度（字符） */
#define CONSOLE_CONTENT_WIDTH 80

/** @brief 控制台内容高度（字符） */
#define CONSOLE_CONTENT_HEIGHT 48

/** @brief 控制台窗口宽度（像素） */
#define CONSOLE_WINDOW_WIDTH 1024

/** @brief 控制台窗口高度（像素） */
#define CONSOLE_WINDOW_HEIGHT 768

/** @brief 棋盘列宽（像素） */
#define CHESSBOARD_ROW_WIDTH 70

/** @brief 棋盘行高（像素） */
#define CHESSBOARD_LINE_HEIGHT 65

/** @brief 棋盘左边横坐标（像素） */
#define CHESSBOARD_RECT_LEFT 35

/** @brief 棋盘顶边纵坐标（像素） */
#define CHESSBOARD_RECT_TOP 38

/** @brief 棋盘宽度（像素） */
#define CHESSBOARD_WIDTH (CHESSBOARD_ROW_WIDTH*8)

/** @brief 棋盘高度（像素） */
#define CHESSBOARD_HEIGHT (CHESSBOARD_LINE_HEIGHT*9)

/** @brief 棋盘右边横坐标（像素） */
#define CHESSBOARD_RECT_RIGHT (CHESSBOARD_WIDTH+CHESSBOARD_RECT_LEFT)

/** @brief 棋盘底边纵坐标（像素） */
#define CHESSBOARD_RECT_BOTTOM (CHESSBOARD_HEIGHT+CHESSBOARD_RECT_TOP)

/** @brief 棋盘线类型 */
#define CHESSBOARD_BORDER_STYLE PS_DASH

/** @brief 棋盘线宽度 */
#define CHESSBOARD_BORDER_WIDTH 2

/** @brief 棋盘线颜色 */
#define CHESSBOARD_BORDER_COLOR 0x000000

/** @brief 棋子边框类型 */
#define CHESS_BORDER_STYLE PS_DASH

/** @brief 棋子边框宽度 */
#define CHESS_BORDER_WIDTH 2

/** @brief 棋子边框颜色 */
#define CHESS_BORDER_COLOR 0xb0b0b0

/** @brief 棋子内部颜色 */
#define CHESS_INSIDE_COLOR 0xc0c0c0

/** @brief 棋子半径 */
#define CHESS_RADIUS 25

/*********************************预处理结束*********************************/
#endif