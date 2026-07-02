#pragma once
#include "Common.h"
#include <fstream>
#include <sstream>
#include <array>


class Alphabet {
public:
	void SetType(int n);
	void SetCoordNum(int n);
	void SetCoord(const double coord_[3]);
	void SetTargetPos(const int idx, const int rowOf, const int colOf);
	Motion::LinearIntplCommand& GetLinearIntplCommand(int i);
	int GetCoordNum() const;
	static bool SetAlphabetData(vector<Alphabet>& alphabet_AZ, std::string fileName);
	static bool FileOpen(std::vector<std::vector<double>>& data, const std::string fileName);
	void ShowCoord(int i) {
		cout << "[ " << coord[i].target[0] << ", " << coord[i].target[1] << ", " << coord[i].target[2] << " ]" << endl;
	}
private:
	int type;		// ¾ËÆÄºª Á¾·ù
	int coordNum;	// xyz ÁÂÇ¥ °³¼ö
	std::vector<Motion::LinearIntplCommand> coord;		// ¾ËÆÄºª ÁÂÇ¥ ¹è¿­ (Á÷¼±º¸°£)
};
