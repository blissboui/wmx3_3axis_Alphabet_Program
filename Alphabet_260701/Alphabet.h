#pragma once
#include "Common.h"
#include <fstream>
#include <sstream>
#include <array>
#include <string>

class Alphabet {
public:
	void SetType(int n);
	void SetCoordNum(int n);
	void SetCoord(const double coord_[3]);
	void SetTargetPos(const int idx, const int rowOf, const int colOf);
	std::array<Motion::PosCommand, 3>& GetPosCommand(int i);
	int GetCoordNum() const;
	static bool SetAlphabetData(vector<Alphabet>& alphabet_AZ, std::string fileName);
	static bool FileOpen(std::vector<std::vector<double>>& data, const std::string fileName);
	void ShowCoord(int i) {
		cout << "[ " << coord[i][0].target << ", " << coord[i][1].target << ", " << coord[i][2].target << " ]" << endl;
	}
private:
	int type;		// ¾ËÆÄºª Á¾·ù
	int coordNum;	// xyz ÁÂÇ¥ °³¼ö
	std::vector<std::array<Motion::PosCommand, 3>> coord;		// ¾ËÆÄºª ÁÂÇ¥ 2Â÷¿ø ¹è¿­ [coordNum][3]
};
