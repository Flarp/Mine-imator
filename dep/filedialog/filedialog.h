// filedialog, a Windows, OS X and Linux library for files and dialogs.

#pragma once

#define MAX_FILENAME        1024
#define MAX_COMMAND         256
#define MAX_MULTIPLE        32

#define ENV_KDIALOG         0
#define ENV_APPLE           1

#ifdef _WIN32
#include <Windows.h>
#endif

#include <stdio.h>
#include <stdlib.h>
#include "strings.h"

// Shows a file dialog for opening a file, starting at the given location ("" for last visited).
// Returns a list of the files selected. Use filters to select specific formats only.
wstring_list dialogOpenFile(wstring title, wstring location, wstring_list filters, bool multiSelect);

// Shows a file dialog for saving a file, starting at the given location ("" for last visited).
// Use filters to select specific formats only.
wstring_list dialogSaveFile(wstring title, wstring location, wstring_list filters);