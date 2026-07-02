#include "Alphabet.h"

const int gAxis[3] = { X_AXIS, Y_AXIS, Z_AXIS };

void Alphabet::SetType(int n) {
	type = n;
}
void Alphabet::SetCoordNum(int n) {
	coordNum = n;
}
void Alphabet::SetCoord(const double coord_[3]) {
	Motion::PosCommand p[3];
	for (int i = 0; i < 3; i++) {
		p[i].axis = gAxis[i];
		p[i].profile.velocity = VELOCITY;
		p[i].profile.acc = ACC;
		p[i].profile.dec = DEC;
		p[i].target = coord_[i];
	}

	coord.push_back({ p[0], p[1], p[2] });
}
int Alphabet::GetCoordNum() const {
	return coordNum; 
}
bool Alphabet::SetAlphabetData(vector<Alphabet>& alphabet_AZ, std::string fileName) {
	std::vector<std::vector<double>> alphabetData;
	if (!FileOpen(alphabetData, fileName)) {
		cout << "파일 열기 실패" << endl;
		return false;
	}
	int count = 0;
	for (int i = 0; i < alphabet_AZ.size(); i++) {
		alphabet_AZ[i].SetType(i);
		alphabet_AZ[i].SetCoordNum(static_cast<int>(alphabetData[i][6]));
		for (int k = 0; k < alphabet_AZ[i].GetCoordNum(); k++) {
			double coord_[3] = {
				alphabetData[count][0],
				alphabetData[count][1],
				alphabetData[count][2]
			};
			alphabet_AZ[i].SetCoord(coord_);
			count++;
		}
	}

	return true;
}
bool Alphabet::FileOpen(std::vector<std::vector<double>>& data, const std::string fileName) {
	std::ifstream file(fileName);

	if (!file.is_open()) {
		return false;
	}
	std::string line;

	while (std::getline(file, line)) {
		std::stringstream ss(line);
		std::string cell;
		std::vector<double> row;

		while (std::getline(ss, cell, ',')) {
			if (cell.empty()) row.push_back(0.0);

			else row.push_back(std::stod(cell));
		}

		data.push_back(row);
	}

	return true;
}
void Alphabet::SetTargetPos(const int idx, const int rowOf, const int colOf) {
	coord[idx][0].target += colOf;
	coord[idx][1].target += rowOf;

}
std::array<Motion::PosCommand, 3>& Alphabet::GetPosCommand(int i)
{
	return coord[i];
}