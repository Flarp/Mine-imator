// filedialog, a Windows, OS X and Linux library for files and dialogs.

#pragma once

#define MAX_FILENAME       1024
#define MAX_COMMAND        256
#define MAX_MULTIPLE       32

#define ENV_KDIALOG        0

#ifdef _WIN32
#include <Windows.h>
#else
#include <iconv.h>
#endif

#include <iostream>
#include <string.h>
#include <wchar.h>
#include <stdio.h>

using namespace std;

// Shows a file dialog for opening a file, starting at the given location ("" for last visited).
// Use filters to select specific formats only.
wstring dialogOpenFile(wstring title, wstring location, wstring filters, bool multiSelect);

// Shows a file dialog for saving a file, starting at the given location ("" for last visited).
// Use filters to select specific formats only.
wstring dialogSaveFile(wstring title, wstring location, wstring filters);