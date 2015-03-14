#pragma once

#ifdef _WIN32
#define SLASH "\\"
#else
#define SLASH "/"
#endif

#include "stringfunc.h"

// Returns whether the given file exists.
bool fileExists(wstring filename);

// Returns the name of the file, without the path.
wstring fileGetName(wstring filename);

// Returns the path to the given file, including the final slash.
wstring fileGetPath(wstring filename);

// Returns the directory of the given file, not including the final slash.
wstring fileGetDirectory(wstring filename);

// Returns the extension of the file, including the leading dot.
wstring fileGetExtension(wstring filename);

// Returns the filename with the new extension (extension must include the leading dot).
wstring fileSetExtension(wstring filename, string ext);

// Returns the filename without an extension.
wstring fileRemoveExtension(wstring filename);

// Returns whether the given directory exists.
bool directoryExists(wstring directory);