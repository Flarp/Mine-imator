#include "filedialog.h"

wstring filedialogOpen(wstring title, wstring location, wstring filters) {
	wchar_t selectedFile[MAX_MULTIPLE * MAX_FILENAME];

#ifdef _WIN32
	OPENFILENAMEW ofn;
	ofn.lStructSize = sizeof(OPENFILENAME);
	ofn.hwndOwner = 0;
	ofn.hInstance = 0;
	ofn.lpstrFilter = &filters[0];
	ofn.lpstrCustomFilter = NULL;
	ofn.nMaxCustFilter = 0;
	ofn.nFilterIndex = 0;
	ofn.lpstrFile = selectedFile;
	ofn.lpstrFile[0] = '\0';
	ofn.nMaxFile = sizeof(selectedFile);
	ofn.lpstrFileTitle = NULL;
	ofn.nMaxFileTitle = _MAX_FNAME + _MAX_EXT;
	ofn.lpstrInitialDir = &location[0];
	ofn.lpstrTitle = &title[0];
	ofn.Flags = OFN_EXPLORER;
	ofn.nFileOffset = 0;
	ofn.nFileExtension = 0;
	ofn.lpstrDefExt = NULL;
	ofn.lCustData = 0L;
	ofn.lpfnHook = NULL;
	ofn.lpTemplateName = NULL;
	GetOpenFileNameW(&ofn);
#else
#endif

	return wstring(selectedFile);
}