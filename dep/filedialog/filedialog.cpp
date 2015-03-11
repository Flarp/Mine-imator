#include "filedialog.h"

#ifndef _WIN32
bool detectEnvironment(std::string env) {
	char buf[MAX_COMMAND];
	std::string cmd = "which " + env;
	bool found;
	FILE *f;

	f = popen(&cmd[0], "r");
	found = (fgets(buf, sizeof(buf), f) != NULL && !strchr(buf, ':'));
	pclose(f);
	return found;
}

std::string getEnvironment() {
	if (detectEnvironment("kdialog"))
		return "kdialog";
	return "";
}
#endif

std::wstring dialogOpenFile(std::wstring title, std::wstring location, std::wstring filters, bool multiSelect) {
	wchar_t selectedFile[MAX_MULTIPLE * MAX_FILENAME];

#ifdef _WIN32 // Windows
	OPENFILENAMEW ofn;
	ofn.lStructSize = sizeof(OPENFILENAME);
	ofn.hwndOwner = 0;

	ofn.lpstrFile = selectedFile;
	ofn.lpstrFile[0] = '\0';
	ofn.nMaxFile = sizeof(selectedFile);

	// lpstrFilter wants \0 as separators.
	wchar_t* p = &filters[0];
	while ((p = wcschr(p, '|')) != NULL) {
		*p = '\0';
		p++;
	}
	ofn.lpstrFilter = &filters[0];
	ofn.nFilterIndex = 1;
	ofn.lpstrInitialDir = &location[0];
	ofn.lpstrTitle = &title[0];

	ofn.Flags = OFN_EXPLORER | OFN_FILEMUSTEXIST | OFN_HIDEREADONLY;
	if (multiSelect)
		ofn.Flags |= OFN_ALLOWMULTISELECT;

	ofn.lpstrFileTitle = NULL;
	ofn.nMaxFileTitle = _MAX_FNAME + _MAX_EXT;
	ofn.lpstrCustomFilter = NULL;
	ofn.lpstrDefExt = NULL;

	if (!GetOpenFileNameW(&ofn))
		return std::wstring(L""); // Cancel
#else // Mac, Linux
	std::cout << "Environment: " << getEnvironment() << std::endl;
#endif

	return std::wstring(selectedFile);
}