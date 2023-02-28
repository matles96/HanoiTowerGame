#include "HanoiTowersController.h"


void HanoiTowersController::EraseHanoiTowers()
{
	pointedTower = 0;
	takenDisc = 0;
	hanoiTowerMaxHigh = 0;
	for (int i = 0; i < 3; i++) {
		while (!hanoiTowers[i]->empty()) {
			hanoiTowers[i]->pop();
		}
	}
}

void HanoiTowersController::DrawTower(int XCoordinate, int YCoordinate, int towerNumber)
{

	std::stack<int> temporaryStack;
	YCoordinate += (hanoiTowerMaxHigh - hanoiTowers[towerNumber]->size());
	while (!hanoiTowers[towerNumber]->empty()) {
		Tools::SetConsoleCursorPosition(XCoordinate, YCoordinate);
		temporaryStack.push(hanoiTowers[towerNumber]->top());
		hanoiTowers[towerNumber]->pop();
		for (int i = 0; i < hanoiTowerMaxHigh - temporaryStack.top(); i++)
			std::cout << " ";
		for (int i = 0; i < (temporaryStack.top() * 2) - 1; i++)
			std::cout << "X";
		YCoordinate++;
	}
	while (!temporaryStack.empty()) {
		hanoiTowers[towerNumber]->push(temporaryStack.top());
		temporaryStack.pop();
	}
}

void HanoiTowersController::DrawPointerInfo(int XCoordinate, int YCoordinate, int towerNumber)
{
	Tools::SetConsoleCursorPosition(XCoordinate, YCoordinate);
	char character = (towerNumber == pointedTower) ? '=' : '-';
	for (int i = 0; i < (hanoiTowerMaxHigh * 2) - 1; i++)
		std::cout << character;
}

void HanoiTowersController::WriteControllerInfo()
{
	std::string text;
	if (takenDisc == 0)
		text = "";
	else {
		text = std::to_string(takenDisc) + "; ";
		for (int i = 0; i < (takenDisc * 2) - 1; i++) {
			text += "X";
		}
	}
	std::cout << text << std::endl;
}

void HanoiTowersController::IsFinished()
{
	if (hanoiTowers[2]->size() == hanoiTowerMaxHigh) {
		Tools::WinScreen();
		CreateNewHanoiTowers(Tools::ChooseHanoiTowerHigh());
		Draw();
	}
}

void HanoiTowersController::MovePointerLeft()
{
	pointedTower--;
	if (pointedTower < 0)
		pointedTower = 2;
}

void HanoiTowersController::MovePointerRight()
{
	pointedTower++;
	if (pointedTower > 2)
		pointedTower = 0;
}

void HanoiTowersController::PutDisc()
{
	if (takenDisc != 0) {
		if (hanoiTowers[pointedTower]->empty() || hanoiTowers[pointedTower]->top() > takenDisc) {
			hanoiTowers[pointedTower]->push(takenDisc);
			takenDisc = 0;
		}
	}
}

void HanoiTowersController::GetDisc()
{
	if (takenDisc == 0 && !hanoiTowers[pointedTower]->empty()) {
		takenDisc = hanoiTowers[pointedTower]->top();
		hanoiTowers[pointedTower]->pop();
	}
}

void HanoiTowersController::Draw()
{
	WriteControllerInfo();
	CONSOLE_SCREEN_BUFFER_INFO info;
	GetConsoleScreenBufferInfo(GetStdHandle(STD_OUTPUT_HANDLE), &info);
	COORD cursorPosition = info.dwCursorPosition;
	cursorPosition.Y++;
	DrawTower(cursorPosition.X, cursorPosition.Y, 0);
	DrawTower(cursorPosition.X + (hanoiTowerMaxHigh * 2), cursorPosition.Y, 1);
	DrawTower(cursorPosition.X + (hanoiTowerMaxHigh * 4), cursorPosition.Y, 2);
	DrawPointerInfo(cursorPosition.X, cursorPosition.Y + hanoiTowerMaxHigh, 0);
	DrawPointerInfo(cursorPosition.X + (hanoiTowerMaxHigh * 2), cursorPosition.Y + hanoiTowerMaxHigh, 1);
	DrawPointerInfo(cursorPosition.X + (hanoiTowerMaxHigh * 4), cursorPosition.Y + hanoiTowerMaxHigh, 2);
}

void HanoiTowersController::CreateNewHanoiTowers(int towerHigh)
{
	EraseHanoiTowers();
	hanoiTowerMaxHigh = towerHigh;
	for (int i = towerHigh; i > 0; i--) {
		hanoiTowers[0]->push(i);
	}
}

HanoiTowersController::HanoiTowersController()
{
	takenDisc = 0;
	pointedTower = 0;
	hanoiTowerMaxHigh = 0;
	hanoiTowers[0] = std::make_unique<std::stack<int>>();
	hanoiTowers[1] = std::make_unique<std::stack<int>>();
	hanoiTowers[2] = std::make_unique<std::stack<int>>();
}


HanoiTowersController::~HanoiTowersController()
{
}
