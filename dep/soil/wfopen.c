#include "wfopen.h"

FILE* wfopen(const wchar_t *filename, char *param) {
#ifdef _WIN32
	wchar_t wparam[3];
	mbstowcs(wparam, param, 3);
	return _wfopen(filename, wparam);
#else
	FILE *f;
	int len;
	char *fn;
	
	len = (int)wcsrtombs(NULL, &filename, 0, NULL);
	if (len < 0)
		return NULL;
		
	fn = (char*)malloc(len + 1); 
	wcsrtombs(fn, &filename, len, NULL); 
	fn[len] = '\0'; 
	f = fopen(fn, param);
	free(fn);
	
	return f;
#endif
}