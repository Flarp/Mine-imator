#include "strings.h"

string stringToWstring(wstring wstr) {
	string result;
	result.resize(wstr.length());
	wcstombs(&result[0], &wstr[0], result.length());
	return result;
}

wstring wstringToString(string str) {
	wstring result;
	result.resize(str.length());
	mbstowcs(&result[0], &str[0], result.length());
	return result;
}

string_list stringSplit(string str, char split) {
	stringstream ss(str);
	string_list result;
	string item;
	while (getline(ss, item, split))
		result.push_back(item);
	return result;
}

wstring_list wstringSplit(wstring wstr, wchar_t split) {
	wstringstream ss(wstr);
	wstring_list result;
	wstring item;
	while (getline(ss, item, split))
		result.push_back(item);
	return result;
}

string stringReplace(string str, string from, string to) {
	if (from.empty())
		return str;
	size_t start_pos = 0;
	while((start_pos = str.find(from, start_pos)) != string::npos) {
		str.replace(start_pos, from.length(), to);
		start_pos += to.length();
	}
    return str;
}

wstring wstringReplace(wstring wstr, wstring from, wstring to) {
	if (from.empty())
		return wstr;
	size_t start_pos = 0;
	while((start_pos = wstr.find(from, start_pos)) != wstring::npos) {
		wstr.replace(start_pos, from.length(), to);
		start_pos += to.length();
	}
    return wstr;
}