#pragma once
#ifndef __UTIL_H__
#define __UTIL_H__


#include<windows.h>
class Util
{
public:
	Util() {}
	virtual ~Util() {}

	static void GotoXY(int X, int Y);
};
#endif // !__Util_H__

