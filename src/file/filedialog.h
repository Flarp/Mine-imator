#include "../mineimator.h"

#define MAX_FILENAME       1024
#define MAX_MULTIPLE       32

#ifdef _WIN32
#include <Windows.h>
#else

#endif
using namespace std;
wstring filedialogOpen(wstring title, wstring location, wstring filters);
wstring filedialogSave(wstring title, wstring location, wstring filters);