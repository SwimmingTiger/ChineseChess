#ifndef _WIN32API_H_
/**
* @brief Windows API ��������
* 
* ��ͷ�ļ�������������Ҫʹ�õĲ���Windows API��
* ��ЩAPI������Windowsϵͳ�У�����windows.hͷ�ļ���δ������
*/
#define _WIN32API_H_

/** @brief ����̨������Ϣ�ṹ */
typedef struct _CONSOLE_FONT
{
    DWORD index;
    COORD dim;
} CONSOLE_FONT;

/** @brief ��ȡ����̨���ھ�� */
extern "C" HWND WINAPI GetConsoleWindow();
/** @brief �ı����̨���壨��֪Ϊ�β�������ʹ�ã� */
extern "C" BOOL WINAPI SetConsoleFont(HANDLE hOutput, DWORD fontIndex);
/** @brief ��ȡ����̨������Ϣ */
extern "C" BOOL WINAPI GetConsoleFontInfo(HANDLE hOutput, BOOL bMaximize, DWORD numFonts, CONSOLE_FONT* info);
/** @brief ��ȡ����̨�����С */
extern "C" DWORD WINAPI GetNumberOfConsoleFonts();
/** @brief ���ÿ���̨����ͼ�� */
extern "C" BOOL WINAPI SetConsoleIcon(HICON hIcon);
/** @brief ���ÿ���̨��ʾģʽ */
extern "C" BOOL WINAPI SetConsoleDisplayMode(HANDLE hOut, DWORD dwNewMode, LPDWORD lpdwOldMode);
/** @brief ���û�ͼʱ�Ļ�ˢ��ɫ */
extern "C" COLORREF WINAPI SetDCBrushColor(HDC hdc, COLORREF crColor);

/*Ԥ�������*/
#endif