#pragma once
#include "Geometry.h"
#include "Trail.h"
#include "Bullet.h"


struct HomingShot : public Bullet
{
	Trail trail;
	HomingShot();
};

