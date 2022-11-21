
#include <iostream>
#include <fstream>
#include <regex>
#include <cstring>
#include <conio.h>
#include <windows.h>

using namespace std;

#ifndef _FUN_H
#define _FUN_H

// 使用正则表达式进行匹配，判断全局输入
bool IsRegexInput(string str) 
{
	bool flag;
	flag = true;
	regex r("\\d{1,8}");
	while (!(flag = regex_match(str, r)))
	{
		return flag;
	}
	return flag;

}

//显示或隐藏光标
void ShowCursor(bool visible) { 

    CONSOLE_CURSOR_INFO cursor_info = {20, visible};
    //CONSOLE_CURSOR_INFO结构体包含控制台光标信息，成员分别表示光标百分比厚度和是否可见
    SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &cursor_info);
 	//SetConsoleCursorInfo设定控制台窗口的光标大小和是否可见
}

template <typename T>

inline T const& Max (T const& a, T const& b) 
{ 
    return a < b ? b:a; 
}

void SetTextRed()
{
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),FOREGROUND_RED | FOREGROUND_INTENSITY);
}
void SetTextGreen()
{
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),FOREGROUND_GREEN | FOREGROUND_INTENSITY);
}

void SetTextWhite()
{
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
}
void SetBgWhite()
{
	
}
#endif



