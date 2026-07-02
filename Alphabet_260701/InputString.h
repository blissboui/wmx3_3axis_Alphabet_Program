#pragma once
#include "Common.h"

class InputString {
public:
	void SetString() {
		cout << "알파벳 대문자 문자열 입력 : ";
		cin >> str;
		strLen = str.size();
		strType.clear();
		for (int i = 0; i < strLen; i++) {
			strType.push_back(static_cast<int>(str[i]) - 'A');	//  ASCII 'A' = 65
		}
	}
	void PrintString() const {
		cout << str << endl;
		for (int i = 0; i < strLen; i++) {
			cout << strType[i] << ", ";
		}
		cout << endl;
	}
	int GetStrLen() const {
		return strLen;
	}
	int GetStrType(int idx) const {
		return strType[idx];
	}

private:
	string str;
	int strLen;
	vector<int> strType;
};