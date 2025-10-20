#pragma once
#include "MoveObjectRenderer.h"

class MoveCloudRenderer : public MoveObjectRenderer
{
public:
	MoveCloudRenderer(std::shared_ptr<Sprite> A_objSpritePtr, RenderWindow& A_renderWindow);
	void render(const Time& A_time_dt) override;

private:
	int counter = 0;
};