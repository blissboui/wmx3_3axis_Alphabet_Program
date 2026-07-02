#include "Alphabet.h"
#include "InputString.h"
#include "Engine.h"
#include "Motion.h"
#include "IO.h"

void SetOffset(vector<Alphabet>& alphAZ, vector<Alphabet>& strAlph, const InputString& str_);
void StartMotion(vector<Alphabet>& strAlph, AlphabetMotion& motion_, int strLen);

int main() {
	vector<Alphabet> alphabet_AZ(26);
	InputString str;
	WMX3Api wmx;
	Engine engineCtrl(&wmx);
	AlphabetMotion motionCtrl(&wmx);
	IO ioCtrl(&wmx);

	// 디바이스 생성
	engineCtrl.CreateDevice();
	// 통신 시작
	engineCtrl.StartCommunication();
	// 서보 on
	motionCtrl.ServoOn();
	// 엑셀 csv 파일로부터 A~Z 알파벳 좌표 데이터 읽은 후 전달한 변수에 저장
	Alphabet::SetAlphabetData(alphabet_AZ, (std::string)"C:\\Users\\boboy\\source\\repos\\Data\\AlphabetData.csv");
	
	while (1)
	{
		str.SetString();
		vector<Alphabet> strAlphabet;	// 입력한 문자열 알파벳 배열
		SetOffset(alphabet_AZ, strAlphabet, str);	// 행, 열 좌표 옵셋 적용

		str.PrintString();
		if (1) {
			StartMotion(strAlphabet, motionCtrl, str.GetStrLen());	// 모션 시작
		}

		else if (ioCtrl.GetBit(2)) {
			break;
		}
	}
	str.PrintString();

}
void StartMotion(vector<Alphabet>& strAlph, AlphabetMotion& motion_, int strLen) {
	for (int idx = 0; idx < strLen; idx++)
	{
		for (int i = 0; i < strAlph[idx].GetCoordNum(); i++)
		{
			motion_.MovePos(strAlph[idx].GetPosCommand(i).data());
		}
	}
}
void SetOffset(vector<Alphabet>& alphAZ, vector<Alphabet>& strAlph, const InputString& str_) {
	
	int row = 0, col = 0;
	for (int idx = 0; idx < str_.GetStrLen(); idx++)
	{
		strAlph.push_back(alphAZ[str_.GetStrType(idx)]);	// 알파벳 타입에 맞게 깊은 복사

		for (int i = 0; i < strAlph[idx].GetCoordNum(); i++)
		{
			strAlph[idx].SetTargetPos(i, ROW_OFFSET_LEN * row, COL_OFFSET_LEN * col);	// 좌표에 옵셋 적용
			strAlph[idx].ShowCoord(i);
		}
		cout << endl;
		col++;
		if (col >= MAX_COL) {
			col = 0;
			row++;
		}
		if (row >= MAX_ROW) {
			cout << "작성 가능한 글자수를 초과했습니다." << endl;
			return;
		}
	}
	
}