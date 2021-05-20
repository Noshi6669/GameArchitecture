#include <iostream>
#include <DxLib.h>

int WINAPI WinMain(_In_ HINSTANCE hInstance, _In_opt_ HINSTANCE hPrevInstance, _In_ LPSTR lpCmdLine, _In_ int nCmdShow)
{
	SetWindowText(L"2016212_ïSçáñÏÈDëæ");
	ChangeWindowMode(true);
	DxLib_Init();
	SetDrawScreen(DX_SCREEN_BACK);
	while (ProcessMessage() != -1)
	{
		ClearDrawScreen();

		int num = 200;
		DrawBox(num, num, 400, 400, 0x00ff00, true);

		ScreenFlip();
	}

	DxLib_End();
	return 0;
}