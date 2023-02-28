#pragma once
#include<stack>
#include<memory>
#include<array>
#include"Tools.h"
#include<iostream>
#include<string>
class HanoiTowersController
{
private:
	using stackPointer = std::unique_ptr<std::stack<int>>;

	std::array<stackPointer, 3> hanoiTowers;
	int hanoiTowerMaxHigh;
	int pointedTower;
	int takenDisc;

	void EraseHanoiTowers();
	void DrawTower(int XCoordinate, int YCoordinate, int towerNumber);
	void DrawPointerInfo(int XCoordinate, int YCoordinate, int towerNumber);
	void WriteControllerInfo();
public:
	void CreateNewHanoiTowers(int towerHigh);
	void MovePointerLeft();
	void MovePointerRight();
	void PutDisc();
	void GetDisc();
	void Draw();
	void IsFinished();

	HanoiTowersController();
	~HanoiTowersController();
};