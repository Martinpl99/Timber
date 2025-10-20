#include "../../headers/rendering/MoveObjectRendererBuilder.h"
#include "../../headers/rendering/MoveObjectRenderer.h"

MoveObjectRendererBuilder::MoveObjectRendererBuilder(std::shared_ptr<Sprite> A_objSpritePtr, RenderWindow& A_renderWindow)
{
	m_elementToCreate = std::make_shared<MoveObjectRenderer>(A_objSpritePtr, A_renderWindow);
}

MoveObjectRendererBuilder& MoveObjectRendererBuilder::SetHorizontalStartPosition(float A_fHorizontalStartPos)
{
	m_elementToCreate->SetHorizontalStartPosition(A_fHorizontalStartPos);
	return *this;
}

MoveObjectRendererBuilder& MoveObjectRendererBuilder::SetVerticalStartPosition(float A_fVerticalStartPos)
{
	m_elementToCreate->SetVerticalStartPosition(A_fVerticalStartPos);
	return *this;
}

MoveObjectRendererBuilder& MoveObjectRendererBuilder::SetSpeedOfElement(float A_fSpeedOfElement)
{
	m_elementToCreate->SetSpeedOfElement(A_fSpeedOfElement);
	return *this;
}

MoveObjectRendererBuilder& MoveObjectRendererBuilder::SetIsMoveHorizontally(bool A_bIsMoveHorizontally)
{
	m_elementToCreate->SetIsMoveHorizontally(A_bIsMoveHorizontally);
	return *this;
}

MoveObjectRendererBuilder& MoveObjectRendererBuilder::SetIsMoveVertically(float A_bIsMoveVertically)
{
	m_elementToCreate->SetIsMoveVertically(A_bIsMoveVertically);
	return *this;
}

MoveObjectRendererBuilder& MoveObjectRendererBuilder::SetHorizontalBorder(float A_fHorizontalBorder)
{
	m_elementToCreate->SetHorizontalBorder(A_fHorizontalBorder);
	return *this;
}

MoveObjectRendererBuilder& MoveObjectRendererBuilder::SetVerticalBorder(float A_fVerticalBorder)
{
	m_elementToCreate->SetVerticalBorder(A_fVerticalBorder);
	return *this;
}

MoveObjectRendererBuilder& MoveObjectRendererBuilder::SetHorizontalMoveRange(float A_fHorizontalMoveRange)
{
	m_elementToCreate->SetHorizontalMoveRange(A_fHorizontalMoveRange);
	return *this;
}

MoveObjectRendererBuilder& MoveObjectRendererBuilder::SetVerticalMoveRange(float A_fVerticalMoveRange)
{
	m_elementToCreate->SetVerticalMoveRange(A_fVerticalMoveRange);
	return *this;
}

std::shared_ptr<IMoveObjectRenderer> MoveObjectRendererBuilder::GetRenderer()
{
	return std::static_pointer_cast<IMoveObjectRenderer>(m_elementToCreate);
}