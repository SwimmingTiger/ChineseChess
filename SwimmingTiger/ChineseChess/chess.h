#ifndef _CHESS_H_
/**
* @brief �й�������Ϸ�������������庯������
* 
* - ������Ϣ
*     - ���ߣ����ݺ�
*     - �༶�����131��
*     - ѧԺ���������ѧ�빤��ѧԺ
*     - ѧУ����������ѧԺ
*/
#define _CHESS_H_

/**********************************��������**********************************/

/** @brief �������� */
#define CHESSBOARD_LINE 10
/** @brief �������� */
#define CHESSBOARD_ROW 9

/** @brief ���������� */
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
/** @brief һ���������� */
#define CHESS_NUM_SUM 16

/********************************������������********************************/

/**
* @brief ��Ϸ״̬ö��
*/
enum GameState
{
    GSTAT_ACTIVE, ///< ��Ϸ���ڽ���
    GSTAT_PAUSE, ///< ��Ϸ��ͣ
    GSTAT_STOP, ///< ��Ϸ����
    GSTAT_DRAW, ///< ����
    GSTAT_RED_WIN, ///< �췽��һ�ʤ
    GSTAT_BLACK_WIN, ///< �ڷ���һ�ʤ
};

/**
* @brief ���ö��
* 
* ������ʶ����Ǻ췽���Ǻڷ���
* ��������к췽���֣��ڷ����֡�
*/
enum Player
{
    PLY_BOTH, ///< �췽��Һͺڷ������ͬһ̨�����ϣ����߽������
    PLY_RED, ///< ��ǰΪ�췽���
    PLY_BLACK, ///< ��ǰΪ�ڷ����
};

/**
* @brief ��������ö��
* 
* ö���˺�ڷ��������������ͣ����������ӡ�
* ���У��췽�����м��_R_���ڷ���_K_
* ����R��B�������ƣ��ʲ���B����K����ڷ�Black��
*/
enum ChessType
{
    CHESS_NULL, ///< ������
    
    CHESS_R_SHUAI, ///< �췽˧
    CHESS_R_JU, ///< �췽��
    CHESS_R_MA, ///< �췽��
    CHESS_R_PAO, ///< �췽��
    CHESS_R_XIANG, ///< �췽��
    CHESS_R_SHI, ///< �췽��
    CHESS_R_BING, ///< �췽��
    
    CHESS_K_JIANG, ///< �ڷ���
    CHESS_K_JU, ///< �ڷ���
    CHESS_K_MA, ///< �ڷ���
    CHESS_K_PAO, ///< �ڷ���
    CHESS_K_XIANG, ///< �ڷ���
    CHESS_K_SHI, ///< �ڷ�ʿ
    CHESS_K_ZU, ///< �ڷ���
};

/**
* @brief ��������ṹ
*/
struct ChessPos
{
    unsigned char line; //�к�
    unsigned char row; //�к�
};

/**
* @brief ���̽ṹ
* 
* �������̸������ݡ���ڷ���λ��
*/
struct ChessBoard
{
    char map[10][9]; ///< ���̸������ݣ�
                     ///< һ��ʮ�о��еĶ�ά���飬ǰ����Ϊ�ڷ����̣�������Ϊ�췽���̡�
                     ///< ����ǰ����Ǻڷ�ʱ���佫�ڷ��������£����ڷ�������������ǰ���С���
                     ///< ÿ������Ԫ�ش��������ϵ�һ������㣬��ֵΪ��������ö��ֵ��

    char player; ///< ������ң���ֵΪ���ö�����ͣ�����������ս��ʶ��ң�Ŀǰ�����塣
    char activePlayer; ///< ��ǰ���ң���ֵΪ���ö�����͡�����ҿ��ƶ����ӡ�

    char chessLocked; ///< �����Ƿ�����������Ϊ1��δ����Ϊ0
    struct ChessPos lockedCursor; ///< �������ӵĹ��λ��

    struct ChessPos cursorRed; ///< �췽��ҹ��
    struct ChessPos cursorBlack; ///< �ڷ���ҹ��

    char redChessNum; ///< �췽������
    char blackChessNum; ///< �ڷ�������

    char redShuaiExists; ///< �췽˧�Ƿ���ڣ���1��0
    char blackJiangExists; ///< �ڷ����Ƿ���ڣ���1��0

	char gameState; ///< ��Ϸ״̬
    char logFileName[100]; ///< ��Ϸ��־�ļ����ƣ�������·����
};

/**********************************��������**********************************/

/*��ʼ������*/
void InitChessBoard(ChessBoard *cp, enum Player player);

/*ȡ��������*/
void GetChessDisplayName(char chessType, char *ipName);

/*��Ϸ���̿��ƺ���*/
void StartGame(struct ChessBoard *cp);

/*������������ṹ*/
struct ChessPos CreatePos(char line, char row);

/*�Ƚ�������������������Ƿ����*/
char MatchPos(struct ChessPos pos, char line, char row);

/*ȡ����������*/
char GetChessType(struct ChessBoard *cp, struct ChessPos pos);

/*������������*/
void SetChessType(struct ChessBoard *cp, struct ChessPos pos, char chessType);

/*ȡ���������������*/
char GetChessPlayer(char chessType);

/*�л���ǰ����*/
void SwitchActivePlayer(struct ChessBoard *cp);

/*���ص�ǰ����*/
char ActivePlayer(struct ChessBoard *cp);

/*���ص�ǰ�ǻ���*/
char InactivePlayer(struct ChessBoard *cp);

/*ȡ��ǰ���ҹ��ָ��*/
struct ChessPos * ActiveCursor(struct ChessBoard *cp);

/*ȡ��ǰ�ǻ��ҹ��ָ��*/
struct ChessPos * InactiveCursor(struct ChessBoard *cp);

/*ȡ��ǰ����������ָ��*/
char * ActiveChessNum(struct ChessBoard *cp);

/*ȡ��ǰ�ǻ���������ָ��*/
char * InactiveChessNum(struct ChessBoard *cp);

/*ָ����һ�ʤ*/
void PlayerWin(struct ChessBoard *cp, char player);

/*��ǰ���һ�ʤ*/
void ActivePlayerWin(struct ChessBoard *cp);

/*��ǰ�ǻ��һ�ʤ*/
void InactivePlayerWin(struct ChessBoard *cp);

/*�ڷ����ӵ�ָ��λ��*/
void PutChess(struct ChessBoard *cp, char line, char row, char chessType);

/*ͳ����㵽�յ���;�����Ӹ����������������յ㣩*/
int ChessCount(struct ChessBoard *cp, struct ChessPos destPos, struct ChessPos sourPos);

/*ͳ��һ����ĳ���ӵĸ���*/
int RowChessCount(struct ChessBoard *cp, char chessType, char row);

/*ͳ�Ƶ�ǰ�������ϣ�������ض���ң����м���ͬ��������*/
int AboveChessCount(struct ChessBoard *cp, char chessType, struct ChessPos sourPos, char player);

/*ͳ�Ƶ�ǰ�������£�������ض���ң����м���ͬ��������*/
int BelowChessCount(struct ChessBoard *cp, char chessType, struct ChessPos sourPos, char player);

/*�ƶ�����*/
char MoveChess(struct ChessBoard *cp, struct ChessPos destPos, struct ChessPos sourPos);

/*********************************�꺯������*********************************/

/** @brief �����������ֵ���꣩*/
#define MAX2(a,b) ((a)>(b)?(a):(b))

/** @brief ����������Сֵ���꣩*/
#define MIN2(a,b) ((a)<(b)?(a):(b))

/*********************************Ԥ�������*********************************/
#endif