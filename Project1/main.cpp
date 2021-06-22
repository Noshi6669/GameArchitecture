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
	int bgAssetH = LoadGraph(L"./Asset/Assets.png");
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
	unsigned int frameForAngle = 0;
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
		Vector2 currentPos = { 0,240 };
		Vector2 lastDelta90Vectors[2] = { { 0.0f,0.0f },{ 0.0f,0.0f } };
		constexpr float sin_amp = 100.0f;
		for (int i = 0;i < count;++i)
		{
			int nextX = i * block_size;
			int nextY = 240 + sin_amp * sin((float)(0.5 * nextX + frameForAngle) / 180.0f * DX_PI);
			
			auto deltaVec = Vector2(block_size, nextY).Normalized() * block_size;
			auto nextPos = currentPos + deltaVec;

			auto middleVec0 = deltaVec;
			auto middleVecR = deltaVec.Rotated90();
			if (!(lastDelta90Vectors[0] == Vector2::Zero()))
			{
				middleVecR = (middleVecR + lastDelta90Vectors[0]).Normalized() * block_size;
			}
			auto middleVecL = lastDelta90Vectors[0];
			if (!(lastDelta90Vectors[1] == Vector2::Zero()))
			{
				middleVecL = (middleVecL + lastDelta90Vectors[1]).Normalized() * block_size;
			}
			lastDelta90Vectors[1] = lastDelta90Vectors[0];
			lastDelta90Vectors[0] = deltaVec.Rotated90();

			nextPos += Vector2(block_size,
				50.0f * sinf(0.5f * (float)(frameForAngle + block_size * i) * DX_PI_F / 180.0f)
			).Normalized() * block_size;

			DrawLineAA(currentPos.x,currentPos.y, //始点
				nextPos.x, nextPos.y, //終点
				0xffffff, 10.0f);

			currentPos = nextPos;

			auto middlePosL = currentPos + middleVecL;
			auto middlePosR = nextPos + middleVecR;

			DrawRectModiGraph(
				currentPos.x,currentPos.y,
				nextPos.x, nextPos.y,
				middlePosR.x, middlePosR.y,
				middlePosL.x, middlePosL.y,
				48, 0, 16, 16,
				bgAssetH, true
			);
			/*x = nextX;
			y = nextY;*/
		}



		auto mpos = GetMousePosition2();
		Vector2 dir = mpos - playerPos;
		float angle = atan2(dir.y, dir.x);

		auto imgIdx = frameNo / 10;
		int num = 0;
		//DrawBox(200, 200, 400, 400, 0x00ff00, true);

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
		frameForAngle = (frameForAngle + 1) % 720;
	}

	DxLib_End();
	return 0;
}