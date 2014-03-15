#ifndef _CHESS_H_
/**
* @brief 中国象棋游戏棋子棋盘与走棋函数声明
* 
* - 作者信息
*     - 作者：彭逸豪
*     - 班级：软件131班
*     - 学院：计算机科学与工程学院
*     - 学校：大连民族学院
*/
#define _CHESS_H_

/**********************************常量声明**********************************/

/** @brief 棋盘行数 */
#define CHESSBOARD_LINE 10
/** @brief 棋盘列数 */
#define CHESSBOARD_ROW 9

/********************************数据类型声明********************************/

/**
* @brief 玩家枚举
* 
* 用来标识玩家是红方还是黑方。
* 象棋规则中红方先手，黑方后手。
*/
enum Player
{
    PLY_BOTH, ///< 红方玩家和黑方玩家在同一台电脑上，两者交替操作
    PLY_RED, ///< 当前为红方玩家
    PLY_BLACK, ///< 当前为黑方玩家
};

/**
* @brief 棋子类型枚举
* 
* 枚举了红黑方的所有棋子类型，包括无棋子。
* 其中，红方名称中间带_R_，黑方带_K_
* （因R和B过于相似，故不用B而用K代表黑方Black）
*/
enum ChessType
{
    CHESS_NULL, ///< 无棋子
    
    CHESS_R_SHUAI, ///< 红方帅
    CHESS_R_JU, ///< 红方车
    CHESS_R_MA, ///< 红方马
    CHESS_R_PAO, ///< 红方炮
    CHESS_R_XIANG, ///< 红方相
    CHESS_R_SHI, ///< 红方仕
    CHESS_R_BING, ///< 红方兵
    
    CHESS_K_JIANG, ///< 黑方将
    CHESS_K_JU, ///< 黑方车
    CHESS_K_MA, ///< 黑方马
    CHESS_K_PAO, ///< 黑方炮
    CHESS_K_XIANG, ///< 黑方象
    CHESS_K_SHI, ///< 黑方士
    CHESS_K_ZU, ///< 黑方卒
};

/**
* @brief 棋子坐标结构
*/
struct ChessPos
{
    unsigned char line; //行号
    unsigned char row; //列号
};

/**
* @brief 棋盘结构
* 
* 包括棋盘格子数据、红黑方的位置
*/
struct ChessBoard
{
    char map[10][9]; ///< 棋盘格子数据，
                     ///< 一个十行九列的二维数组，前五行为黑方棋盘，后五行为红方棋盘。
                     ///< （当前玩家是黑方时，虽将黑方绘制在下，但黑方棋盘数据仍在前五行。）
                     ///< 每个数组元素代表棋盘上的一个交叉点，其值为棋子类型枚举值。

    char player; ///< 本机玩家，其值为玩家枚举类型，用于联网对战标识玩家，目前无意义。
    char activePlayer; ///< 当前活动玩家，其值为玩家枚举类型。该玩家可移动棋子。

    char chessLocked; ///< 棋子是否锁定，锁定为1，未锁定为0
    struct ChessPos lockedCursor; ///< 锁定棋子的光标位置

    struct ChessPos cursorRed; ///< 红方玩家光标
    struct ChessPos cursorBlack; ///< 黑方玩家光标
    struct ChessPos *activeCursor; ///< 指向当前活动玩家光标的指针
};

/**********************************函数声明**********************************/

/*初始化棋盘*/
void InitChessBoard(ChessBoard *cp, enum Player player);

/*取得棋子名*/
void GetChessName(char chessType, char *ipName);

/*游戏流程控制函数*/
void StartGame(struct ChessBoard *cp);

/*创建棋子坐标结构*/
struct ChessPos CreatePos(char line, char row);

/*比较棋子坐标与给定坐标是否相等*/
char MatchPos(struct ChessPos pos, char line, char row);

/*取得棋子类型*/
char GetChessType(struct ChessBoard *cp, struct ChessPos pos);

/*设置棋子类型*/
void SetChessType(struct ChessBoard *cp, struct ChessPos pos, char chessType);

/*取得棋子所属的玩家*/
char GetChessPlayer(char chessType);

/*切换当前活动玩家*/
void SwitchActivePlayer(struct ChessBoard *cp);

/*摆放棋子到指定位置*/
void PutChess(struct ChessBoard *cp, char line, char row, char chessType);

/*统计起点到终点沿途的棋子个数（不包括起点和终点）*/

/*移动棋子*/
char MoveChess(struct ChessBoard *cp, struct ChessPos destPos, struct ChessPos sourPos, char player);

/*********************************预处理结束*********************************/
#endif