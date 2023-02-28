#include "Tools.h"


void Tools::SetConsoleCursorPosition(int x, int y) {
	COORD cursorCoordinate;
	cursorCoordinate.X = x;
	cursorCoordinate.Y = y;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), cursorCoordinate);
}

int Tools::ChooseHanoiTowerHigh() {
	HANDLE Handle = GetStdHandle(STD_INPUT_HANDLE);
	DWORD InputNumber = 0;
	DWORD InputRead = 0;
	INPUT_RECORD InputRecord;
	bool repeat = true;
	int answer = 0;
	system("cls");
	std::cout << "podaj liczbe krazkow od 3 do 9" << std::endl;
	while (repeat) {

		GetNumberOfConsoleInputEvents(Handle, &InputNumber);
		if (InputNumber != 0) {
			ReadConsoleInput(Handle, &InputRecord, 1, &InputRead);
			if (!InputRecord.Event.KeyEvent.bKeyDown) {
				switch (InputRecord.Event.KeyEvent.wVirtualKeyCode) {
				case 0x33:
					answer = 3;
					repeat = false;
					system("cls");
					break;
				case 0x34:
					answer = 4;
					repeat = false;
					system("cls");
					break;
				case 0x35:
					answer = 5;
					repeat = false;
					system("cls");
					break;
				case 0x36:
					answer = 6;
					repeat = false;
					system("cls");
					break;
				case 0x37:
					answer = 7;
					repeat = false;
					system("cls");
					break;
				case 0x38:
					answer = 8;
					repeat = false;
					system("cls");
					break;
				case 0x39:
					answer = 9;
					repeat = false;
					system("cls");
					break;
				default:
					break;
				}
			}
		}
	}
	return answer;
}

void Tools::WinScreen()
{
	system("cls");
	std::cout << "WOW wygrales" << std::endl;
	system("pause");
}

void Tools::HelpScreen()
{
	system("cls");
	std::cout << "help... todo" << std::endl;
	system("pause");
	system("cls");
}
