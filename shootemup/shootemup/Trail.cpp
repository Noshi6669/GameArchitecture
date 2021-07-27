#include "Trail.h"
#include "HomingShot.h"
#include <DxLib.h>

constexpr size_t history_limit = 10;

Trail::Trail(HomingShot& owner):owner_(owner)
{
}

void Trail::Update()
{
	history_.push_front(owner_.pos);
	if (history_.size() > history_limit)
	{
		history_.pop_back();
	}
}

void Trail::Draw()
{
	auto lastpos = owner_.pos;
	float thickness = 20.0f;
	for (const auto& pos : history_)
	{
		DrawLineAA(lastpos.x, lastpos.y,
			pos.x, pos.y,
			0xffffff, thickness);
		thickness *= 0.9f;
		lastpos = pos;
	}
}
