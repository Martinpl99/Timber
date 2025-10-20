#pragma once
#include<memory>

class MoveObjectRenderer;
class IMoveObjectRenderer;

namespace sf
{
	class Sprite;
	class RenderWindow;
}

using namespace sf;

class MoveObjectRendererBuilder
{
public:
	MoveObjectRendererBuilder(std::shared_ptr<Sprite> A_objSpritePtr, RenderWindow& A_renderWindow);
	MoveObjectRendererBuilder& SetHorizontalStartPosition(float A_fHorizontalStartPos);
	MoveObjectRendererBuilder& SetVerticalStartPosition(float A_fVerticalStartPos);
	MoveObjectRendererBuilder& SetSpeedOfElement(float A_fSpeedOfElement);
	MoveObjectRendererBuilder& SetIsMoveHorizontally(bool A_bIsMoveHorizontally);
	MoveObjectRendererBuilder& SetIsMoveVertically(float A_bIsMoveVertically);
	MoveObjectRendererBuilder& SetHorizontalBorder(float A_fHorizontalBorder);
	MoveObjectRendererBuilder& SetVerticalBorder(float A_fVerticalBorder);
	MoveObjectRendererBuilder& SetHorizontalMoveRange(float A_fHorizontalMoveRange);
	MoveObjectRendererBuilder& SetVerticalMoveRange(float A_fVerticalMoveRange);

	virtual std::shared_ptr<IMoveObjectRenderer> GetRenderer();
protected:
	std::shared_ptr<MoveObjectRenderer> m_elementToCreate;
};
