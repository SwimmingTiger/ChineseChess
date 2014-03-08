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


/** @brief 前景背景颜色设置命令 */
#define CHESSBOARD_COLOR "color 3D"

/** @brief 窗口宽度（字符） */
#define CHESSBOARD_WINDOW_WIDTH 40

/** @brief 窗口高度（字符） */
#define CHESSBOARD_WINDOW_HEIGHT 20

/** @brief 棋盘列宽（像素） */
#define CHESSBOARD_ROW_WIDTH 40

/** @brief 棋盘行高（像素） */
#define CHESSBOARD_LINE_HEIGHT 50

/** @brief 棋盘左边横坐标（像素） */
#define CHESSBOARD_RECT_LEFT 10

/** @brief 棋盘顶边纵坐标（像素） */
#define CHESSBOARD_RECT_TOP 10

/** @brief 棋盘宽度（像素） */
#define CHESSBOARD_WIDTH (CHESSBOARD_ROW_WIDTH*8)

/** @brief 棋盘高度（像素） */
#define CHESSBOARD_HEIGHT (CHESSBOARD_LINE_HEIGHT*9)

/** @brief 棋盘右边横坐标（像素） */
#define CHESSBOARD_RECT_RIGHT (CHESSBOARD_WIDTH+CHESSBOARD_RECT_LEFT)

/** @brief 棋盘底边纵坐标（像素） */
#define CHESSBOARD_RECT_BOTTOM (CHESSBOARD_HEIGHT+CHESSBOARD_RECT_TOP)


#endif