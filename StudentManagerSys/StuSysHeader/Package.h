
#include <iostream>
#include <iomanip>
#include <fstream>
#include <regex>
#include <cstring>
#include <conio.h>
#include <windows.h>


using namespace std;

#ifndef _FUN_H

#define _FUN_H
/* 
//取消最大化，最小化
void SizeGoAway() {
	SetWindowLongPtrA(
		GetConsoleWindow(),
		GWL_STYLE,
		GetWindowLongPtrA(GetConsoleWindow(), GWL_STYLE) & ~WS_SIZEBOX & ~WS_MAXIMIZEBOX);
}

//取消关闭  谨慎使用，坑人专用
void DeleteGoAway(){
	DeleteMenu(GetSystemMenu(GetConsoleWindow(), FALSE),
		SC_CLOSE, MF_DISABLED);
	DrawMenuBar(GetConsoleWindow());
} */

#endif

