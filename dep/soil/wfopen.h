#pragma once
#include <wchar.h>
#include <stdio.h>
#include <stdlib.h>

// Cross platform file opening.
FILE* wfopen(const wchar_t* filename, char* param);