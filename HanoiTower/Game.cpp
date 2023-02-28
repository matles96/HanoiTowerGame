#include "Game.h"

void Game::Run()
{

	HANDLE Handle = GetStdHandle(STD_INPUT_HANDLE);
	DWORD InputNumber = 0;
	DWORD InputRead = 0;
	INPUT_RECORD InputRecord;
	bool Running = true;
	int stackNumber = 0;
	hanoiTowersController.CreateNewHanoiTowers(Tools::ChooseHanoiTowerHigh());
	hanoiTowersController.Draw();
	while (Running) {
		hanoiTowersController.IsFinished();
		GetNumberOfConsoleInputEvents(Handle, &InputNumber);
		if (InputNumber != 0) {
			ReadConsoleInput(Handle, &InputRecord, 1, &InputRead);
			if (!InputRecord.Event.KeyEvent.bKeyDown) {
				switch (InputRecord.Event.KeyEvent.wVirtualKeyCode) {
				case VK_LEFT:
					system("cls");
					hanoiTowersController.MovePointerLeft();
					hanoiTowersController.Draw();
					break;
				case VK_RIGHT:
					system("cls");
					hanoiTowersController.MovePointerRight();
					hanoiTowersController.Draw();
					break;
				case VK_DOWN:
					system("cls");
					hanoiTowersController.PutDisc();
					hanoiTowersController.Draw();
					break;
				case VK_UP:
					system("cls");
					hanoiTowersController.GetDisc();
					hanoiTowersController.Draw();
					break;
				case VK_ESCAPE:
					Running = false;
					system("cls");
					break;
				case 0x48:
					Tools::HelpScreen();
					hanoiTowersController.Draw();
					break;
				case 0x4E:
					hanoiTowersController.CreateNewHanoiTowers(Tools::ChooseHanoiTowerHigh());
					hanoiTowersController.Draw();
					break;
				default:
					break;
				}
			}
			InputNumber = 0;
		}
	}

}

Game::Game()
{
}


Game::~Game()
{
}
