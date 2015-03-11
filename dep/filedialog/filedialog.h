// filedialog, a Windows, OS X and Linux library for files, dialogs and filedialogs.

#pragma once
#define MAX_FILENAME       1024
#define MAX_COMMAND        256
#define MAX_MULTIPLE       32

#ifdef _WIN32
#include <Windows.h>
#else

#endif

#include <iostream>
#include <string.h>
#include <wchar.h>
#include <stdio.h>

// Shows a file dialog for opening a file, starting at the given location ("" for last visited).
// Use filters to select specific formats only.
std::wstring dialogOpenFile(std::wstring title, std::wstring location, std::wstring filters, bool multiSelect);

// Shows a file dialog for saving a file, starting at the given location ("" for last visited).
// Use filters to select specific formats only.
std::wstring dialogSaveFile(std::wstring title, std::wstring location, std::wstring filters);