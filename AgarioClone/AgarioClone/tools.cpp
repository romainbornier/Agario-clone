#define WIN32_LEAN_AND_MEAN

#include <windows.h>
#include <fstream>
#include <time.h>

#include "tools.h"

void Log(const char *pDst, const char *pMsg, ...)
{
	va_list Args;
	char aPrefix[1024 * 4];
	char *pStr;
	int i, Len;

	sprintf_s(aPrefix, sizeof(aPrefix), "[%08x][%s]: ", (int)time(0), pDst);
	Len = strlen(aPrefix);
	pStr = (char *)aPrefix + Len;

	va_start(Args, pMsg);
	_vsnprintf(pStr, sizeof(aPrefix) - Len, pMsg, Args);

	va_end(Args);
	printf(pStr);
}