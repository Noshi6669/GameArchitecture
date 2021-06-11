#include <iostream>
#include <DxLib.h>
#include <sstream>
#include <iomanip>
#include "Geometry.h"

Position2 GetMousePosition2()
{
	int mx, my;
	GetMousePoint(&mx, &my);
	return { (float)mx,(float)my };
}

int WINAPI WinMain(_In_ HINSTANCE hInstance, _In_opt_ HINSTANCE hPrevInstance, _In_ LPSTR lpCmdLine, _In_ int nCmdShow)
{

	SetWindowText(L"2016212_百合野颯太");

	ChangeWindowMode(true);
	DxLib_Init();
	SetDrawScreen(DX_SCREEN_BACK);

	int groundH = LoadGraph(L"./Asset/ground.png");
	int graphH[6] = {};
	//読み込みの時点でエラー出てる
	for (int i = 0; i < 6; i++)
	{
		//wchar_t path[80];
		std::wostringstream oss;
		oss << L"./Asset/Adventurer-1.5/Individual Sprites/";
		oss << std::setw(1);
		//oss << std::setfill(L'0');
		oss << i << ".png";

		//wsprintf(path, L"../../Asset/Adventurer-1.5/ndividual Sprites/adventurer-run-%02d.png",80);
		graphH[i] = LoadGraph(oss.str().c_str());
	}

	Vector2 playerPos = { 100,200 };

	unsigned int frameNo = 0;
	bool isReverse = false;
	int lastMouseInput = 0;
	while (ProcessMessage() != -1)
	{
		ClearDrawScreen();

		auto currentMouseInput = GetMouseInput();
		if ((currentMouseInput & MOUSE_INPUT_LEFT) &&
			!(lastMouseInput & MOUSE_INPUT_LEFT))
		{
			isReverse = !isReverse;
		}
		lastMouseInput = currentMouseInput;

		constexpr size_t block_size = 32;
		auto count = 720 / block_size;
		int x = 0;	//現在点
		int y = 240;
		for (int i = 0;i < count;++i)
		{
			int nextX = i * block_size;
			int nextY = 240 + 100.0f * sin((float)(0.5 * nextX) / 180.0f * DX_PI);
			DrawLineAA(x, y, nextX, nextY, 0xffffff, 5.0f);
			DrawModiGraph(x, y,	//左上
				nextX, nextY,	//右上
				nextX, nextY + 32,	//右下(右上から真下に)
				x, y + 32,			//左下(左上から真下に)
				groundH, true);
			x = nextX;
			y = nextY;
		}



		auto mpos = GetMousePosition2();
		Vector2 dir = mpos - playerPos;
		float angle = atan2(dir.y, dir.x);

		auto imgIdx = frameNo / 10;
		int num = 0;
		DrawBox(200, 200, 400, 400, 0x00ff00, true);

		int centerX = 16;
		if (isReverse)
		{
			int w, h;
			GetGraphSize(graphH[imgIdx], &w, &h);
			centerX = w - centerX;
		}
		//回転位置を指定できる描画方法
		DrawRotaGraph2(playerPos.x, playerPos.y, centerX, 35, 4.0f, angle, graphH[imgIdx],true, isReverse);
		//通常描画
		//DrawRotaGraph(playerPos.x, playerPos.y, 4.0f, angle, graphH[frameNo / 10], true);
		ScreenFlip();
		frameNo = (frameNo + 1) % 60;
	}

	DxLib_End();
	return 0;
}