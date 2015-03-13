#pragma once

#include <iostream>
#include <sstream>
#include <vector>
#include <string.h>
#include <wchar.h>

using namespace std;
typedef vector<string> string_list;
typedef vector<wstring> wstring_list;

// Converts a wide string to a UTF-8 encoded string.
string wstringToString(wstring str);
// Converts an UTF-8 encoded string into a wide string.
wstring stringToWstring(string wstr);

// Creates a list of all the substrings in str separated by the given character.
string_list stringSplit(string str, char split);
// Creates a list of all the substrings in wstr separated by the given character.
wstring_list wstringSplit(wstring wstr, wchar_t split);

// Replaces all occurances of the given substring and returns the modified string.
string stringReplace(string str, string from, string to);
// Replaces all occurances of the given substring and returns the modified wide string.
wstring wstringReplace(wstring wstr, wstring from, wstring to);