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

/** @brief 各方棋子数 */
#define CHESS_NUM_ARR \
{\
    {CHESS_R_SHUAI, 1},\
    {CHESS_R_JU, 2},\
    {CHESS_R_MA, 2},\
    {CHESS_R_PAO, 2},\
    {CHESS_R_XIANG, 2},\
    {CHESS_R_SHI, 2},\
    {CHESS_R_BING, 5},\
    \
    {CHESS_K_JIANG, 1},\
    {CHESS_K_JU, 2},\
    {CHESS_K_MA, 2},\
    {CHESS_K_PAO, 2},\
    {CHESS_K_XIANG, 2},\
    {CHESS_K_SHI, 2},\
    {CHESS_K_ZU, 5}\
}
/** @brief 一方棋子总数 */
#define CHESS_NUM_SUM 16

/********************************数据类型声明********************************/

/**
* @brief 游戏状态枚举
*/
enum GameState
{
    GSTAT_ACTIVE, ///< 游戏正在进行
    GSTAT_PAUSE, ///< 游戏暂停
    GSTAT_STOP, ///< 游戏结束
    GSTAT_DRAW, ///< 和棋
    GSTAT_RED_WIN, ///< 红方玩家获胜
    GSTAT_BLACK_WIN, ///< 黑方玩家获胜
};

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

    char redChessNum; ///< 红方棋子数
    char blackChessNum; ///< 黑方棋子数

    char redShuaiExists; ///< 红方帅是否存在，是1否0
    char blackJiangExists; ///< 黑方将是否存在，是1否0

	char gameState; ///< 游戏状态
    char logFileName[100]; ///< 游戏日志文件名称（不包括路径）
};

/**********************************函数声明**********************************/

/*初始化棋盘*/
void InitChessBoard(ChessBoard *cp, enum Player player);

/*取得棋子名*/
void GetChessDisplayName(char chessType, char *ipName);

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

/*返回当前活动玩家*/
char ActivePlayer(struct ChessBoard *cp);

/*返回当前非活动玩家*/
char InactivePlayer(struct ChessBoard *cp);

/*取当前活动玩家光标指针*/
struct ChessPos * ActiveCursor(struct ChessBoard *cp);

/*取当前非活动玩家光标指针*/
struct ChessPos * InactiveCursor(struct ChessBoard *cp);

/*取当前活动玩家棋子数指针*/
char * ActiveChessNum(struct ChessBoard *cp);

/*取当前非活动玩家棋子数指针*/
char * InactiveChessNum(struct ChessBoard *cp);

/*指定玩家获胜*/
void PlayerWin(struct ChessBoard *cp, char player);

/*当前活动玩家获胜*/
void ActivePlayerWin(struct ChessBoard *cp);

/*当前非活动玩家获胜*/
void InactivePlayerWin(struct ChessBoard *cp);

/*摆放棋子到指定位置*/
void PutChess(struct ChessBoard *cp, char line, char row, char chessType);

/*统计起点到终点沿途的棋子个数（不包括起点和终点）*/
int ChessCount(struct ChessBoard *cp, struct ChessPos destPos, struct ChessPos sourPos);

/*统计一列上某棋子的个数*/
int RowChessCount(struct ChessBoard *cp, char chessType, char row);

/*统计当前棋子往上（相对于特定玩家）还有几个同样的棋子*/
int AboveChessCount(struct ChessBoard *cp, char chessType, struct ChessPos sourPos, char player);

/*统计当前棋子往下（相对于特定玩家）还有几个同样的棋子*/
int BelowChessCount(struct ChessBoard *cp, char chessType, struct ChessPos sourPos, char player);

/*移动棋子*/
char MoveChess(struct ChessBoard *cp, struct ChessPos destPos, struct ChessPos sourPos);

/*********************************宏函数声明*********************************/

/** @brief 求两数的最大值（宏）*/
#define MAX2(a,b) ((a)>(b)?(a):(b))

/** @brief 求两数的最小值（宏）*/
#define MIN2(a,b) ((a)<(b)?(a):(b))

/*********************************预处理结束*********************************/
#endif