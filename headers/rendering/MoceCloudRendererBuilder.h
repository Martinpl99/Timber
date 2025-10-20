#pragma once
#include "MoveObjectRendererBuilder.h"

class MoveCloudRendererBuilder : public MoveObjectRendererBuilder
{
public:
	MoveCloudRendererBuilder(std::shared_ptr<Sprite> A_objSpritePtr, RenderWindow& A_renderWindow);
	virtual std::shared_ptr<IMoveObjectRenderer> GetRenderer() override;
};
