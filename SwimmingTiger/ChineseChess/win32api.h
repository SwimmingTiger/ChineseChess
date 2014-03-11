#ifndef _WIN32API_H_
/**
* @brief Windows API 函数声明
* 
* 本头文件声明本程序需要使用的部分Windows API，
* 这些API存在于Windows系统中，但在windows.h头文件中未声明。
*/
#define _WIN32API_H_

/** @brief 控制台字体信息结构 */
typedef struct _CONSOLE_FONT
{
    DWORD index;
    COORD dim;
} CONSOLE_FONT;

/** @brief 获取控制台窗口句柄 */
extern "C" HWND WINAPI GetConsoleWindow();
/** @brief 改变控制台字体（不知为何不能正常使用） */
extern "C" BOOL WINAPI SetConsoleFont(HANDLE hOutput, DWORD fontIndex);
/** @brief 获取控制台字体信息 */
extern "C" BOOL WINAPI GetConsoleFontInfo(HANDLE hOutput, BOOL bMaximize, DWORD numFonts, CONSOLE_FONT* info);
/** @brief 获取控制台字体大小 */
extern "C" DWORD WINAPI GetNumberOfConsoleFonts();
/** @brief 设置控制台窗口图标 */
extern "C" BOOL WINAPI SetConsoleIcon(HICON hIcon);
/** @brief 设置控制台显示模式 */
extern "C" BOOL WINAPI SetConsoleDisplayMode(HANDLE hOut, DWORD dwNewMode, LPDWORD lpdwOldMode);
/** @brief 设置绘图时的画刷颜色 */
extern "C" COLORREF WINAPI SetDCBrushColor(HDC hdc, COLORREF crColor);

/*预处理结束*/
#endif