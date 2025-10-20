#pragma once
#include "../../headers/interfaces/IMoveObjectRenderer.h"
#include <memory>

namespace sf
{
	class Sprite;
	class RenderWindow;
	class Time;
}

class MoveObjectRendererBuilder;

using namespace sf;

class MoveObjectRenderer : public IMoveObjectRenderer
{
	friend class MoveObjectRendererBuilder;
public:
	MoveObjectRenderer(std::shared_ptr<Sprite> A_objSpritePtr, RenderWindow& A_renderWindow);
	virtual void render(const Time& A_time_dt) override;

protected:
	void SetHorizontalStartPosition(float A_fHorizontalStartPos);
	void SetVerticalStartPosition(float A_fVerticalStartPos);
	void SetIsMoveHorizontally(bool A_bIsMoveHorizontally);
	void SetIsMoveVertically(float A_bIsMoveVertically);
	void SetSpeedOfElement(float A_fSpeedOfElement);
	void SetHorizontalBorder(float A_fHorizontalBorder);
	void SetVerticalBorder(float A_fVerticalBorder);
	void SetHorizontalMoveRange(float A_fHorizontalMoveRange);
	void SetVerticalMoveRange(float A_fVerticalMoveRange);

protected:
	RenderWindow& m_objRenderWindow;
	std::shared_ptr<Sprite> m_objSpritePtr;
	bool m_bIsMoveHorizontally = false;
	bool m_bIsMoveVertically = false;
	float m_fHorizontalStartPos = 0.0f;
	float m_fVerticalStartPos = 0.0f;
	float m_fSpeedOfElement = 0.0f;
	float m_fHorizontalBorder = 0.0f;
	float m_fVerticalBorder = 0.0f;
	float m_fHorizontalMoveRange = 1.0f;
	float m_fVerticalMoveRange = 1.0f;
	bool m_bIsActive = false;
	bool m_isInitialized = false;
};
