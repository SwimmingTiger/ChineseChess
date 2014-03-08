#ifndef _WIN32API_H_
/** @brief Windows API 函数声明*/
#define _WIN32API_H_

typedef struct _CONSOLE_FONT {
    DWORD index;
    COORD dim;
} CONSOLE_FONT;

extern "C" HWND WINAPI GetConsoleWindow();
//extern "C" BOOL WINAPI SetConsoleFont(HANDLE hOutput, DWORD fontIndex);
extern "C" BOOL WINAPI GetConsoleFontInfo(HANDLE hOutput, BOOL bMaximize, DWORD numFonts, CONSOLE_FONT* info);
extern "C" DWORD WINAPI GetNumberOfConsoleFonts();
extern "C" BOOL WINAPI SetConsoleIcon(HICON hIcon);

/*预处理结束*/
#endif