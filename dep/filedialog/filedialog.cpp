#include "filedialog.h"

#ifndef _WIN32

std::string wstrToUTF8(wstring wstr) {
	char result_buffer[MAX_FILENAME];

	iconv_t converter = iconv_open("UTF-8", "wchar_t");

	char* result = result_buffer;
	char* input = (char*)&wstr[0];
	size_t output_available_size = sizeof result_buffer;
	size_t input_available_size = wstr.size();
	size_t result_code = iconv(converter, &input, &input_available_size, &result, &output_available_size);
	if (result_code == -1)
		return "";
	iconv_close(converter);

	return string(result_buffer);
}

bool detectEnvironment(string env) {
	char buf[MAX_COMMAND];
	string command = "which " + env;
	bool found;
	FILE *f;

	f = popen(&command[0], "r");
	found = (fgets(buf, sizeof(buf), f) != NULL && !strchr(buf, ':'));
	pclose(f);
	return found;
}

int getEnvironment() {
	if (detectEnvironment("kdialog"))
		return ENV_KDIALOG;
	return -1;
}

#endif

wstring dialogOpenFile(wstring title, wstring location, wstring filters, bool multiSelect) {
	wchar_t selectedFile[MAX_MULTIPLE * MAX_FILENAME];

#ifdef _WIN32 // Windows
	OPENFILENAMEW ofn;
	wchar_t* p;

	ofn.lStructSize = sizeof(OPENFILENAME);
	ofn.hwndOwner = 0;

	ofn.lpstrFile = selectedFile;
	ofn.lpstrFile[0] = '\0';
	ofn.nMaxFile = sizeof(selectedFile);

	// lpstrFilter wants \0 as separators.
	p = &filters[0];
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
		return wstring(L""); // Cancel
#else // Mac, Linux
	string command;
	FILE *f;

	switch (getEnvironment()) {
		case ENV_KDIALOG:
			// https://techbase.kde.org/Development/Tutorials/Shell_Scripting_with_KDE_Dialogs#Example_28._--getopenfilename_dialog_box
			command = "kdialog --getopenfilename";
			if (location != L"")
				command += " \"" + wstrToUTF8(location) + "\"";
			else
				command += " :";
			if (filters != L"")
				command += " \"*.png|*.jpg\"";
			break;
		default:
			return wstring(L""); // Cancel
	}
	cout << command << endl;
	if (!(f = popen(&command[0], "r")))
		return wstring(L"");

#endif

	return wstring(selectedFile);
}