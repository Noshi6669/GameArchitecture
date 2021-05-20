#include <iostream>
#include <DxLib.h>
#include <sstream>
#include <iomanip>

int WINAPI WinMain(_In_ HINSTANCE hInstance, _In_opt_ HINSTANCE hPrevInstance, _In_ LPSTR lpCmdLine, _In_ int nCmdShow)
{

	SetWindowText(L"2016212_•S‡–μιD‘Ύ");

	ChangeWindowMode(true);
	DxLib_Init();
	SetDrawScreen(DX_SCREEN_BACK);

	int graphH[6] = {};
	//“Η‚έ‚έ‚Μ“_‚ΕƒGƒ‰[o‚Δ‚ι
	for (int i = 0; i < 6; i++)
	{
		//wchar_t path[80];
		std::wostringstream oss;
		oss << L"./Asset/Adventurer-1.5/Individual Sprites/adventurer-run-%02d";
		oss << std::setw(2);
		oss << std::setfill(L'0');
		oss << i << ".png";

		
		//wsprintf(path, L"../../Asset/Adventurer-1.5/ndividual Sprites/adventurer-run-%02d.png",80);
		graphH[i] = LoadGraph(oss.str().c_str());
	}
	

	unsigned int frameNo = 0;
	while (ProcessMessage() != -1)
	{
		ClearDrawScreen();

		int num = 0;
		DrawBox(200, 200, 400, 400, 0x00ff00, true);
		DrawRotaGraph(200, 200, 4.0f, 0.0f, graphH[frameNo / 10], true);

		ScreenFlip();
		frameNo = (frameNo + 1) % 60;
	}

	DxLib_End();
	return 0;
}