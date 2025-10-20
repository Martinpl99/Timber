#include "../../headers/rendering/MoveObjectrenderer.h"
#include<SFML/Graphics.hpp>
#include "../../headers/Settings.h"

MoveObjectRenderer::MoveObjectRenderer(std::shared_ptr<Sprite> A_objSpritePtr, RenderWindow& A_objRenderWindow)
    : m_objSpritePtr(A_objSpritePtr), m_objRenderWindow(A_objRenderWindow)
{

}


void MoveObjectRenderer::SetHorizontalStartPosition(float A_fHorizontalStartPos)
{
    m_fHorizontalStartPos = A_fHorizontalStartPos;
}

void MoveObjectRenderer::SetVerticalStartPosition(float A_fVerticalStartPos)
{
    m_fVerticalStartPos = A_fVerticalStartPos;
}

void MoveObjectRenderer::SetIsMoveHorizontally(bool A_bIsMoveHorizontally)
{
    m_bIsMoveHorizontally = A_bIsMoveHorizontally;
}

void MoveObjectRenderer::SetIsMoveVertically(float A_bIsMoveVertically)
{
    m_bIsMoveVertically = A_bIsMoveVertically;
}

void MoveObjectRenderer::SetSpeedOfElement(float A_fSpeedOfElement)
{
    m_fSpeedOfElement = A_fSpeedOfElement;
}

void MoveObjectRenderer::SetHorizontalBorder(float A_fHorizontalBorder)
{
    m_fHorizontalBorder = A_fHorizontalBorder;
}

void MoveObjectRenderer::SetVerticalBorder(float A_fVerticalBorder)
{
    m_fVerticalBorder = A_fVerticalBorder;
}

void MoveObjectRenderer::SetHorizontalMoveRange(float A_fHorizontalMoveRange)
{
    m_fHorizontalMoveRange = A_fHorizontalMoveRange;
}

void MoveObjectRenderer::SetVerticalMoveRange(float A_fVerticalMoveRange)
{
    m_fVerticalMoveRange = A_fVerticalMoveRange;
}

void MoveObjectRenderer::render(const Time& A_time_dt)
{
    if (!m_bIsActive)
    {
        if (!m_isInitialized)
        {
            m_objSpritePtr->setPosition(m_fHorizontalStartPos, m_fVerticalStartPos);
            m_isInitialized = true;
        }
        else
        {
            auto newVerticalStartPos = static_cast<float>(rand() % static_cast<int>(m_fVerticalMoveRange));
            auto newHorizonstalStartPos = static_cast<float>(rand() % static_cast<int>(m_fHorizontalMoveRange));

            if (m_isInitialized && m_bIsMoveHorizontally)
                m_objSpritePtr->setPosition(m_fHorizontalStartPos, newVerticalStartPos);

            if (m_isInitialized && m_bIsMoveVertically)
                m_objSpritePtr->setPosition(newHorizonstalStartPos, m_fVerticalStartPos);
        }
        m_bIsActive = true;
        m_objRenderWindow.draw(*m_objSpritePtr);
    }
    else
    {
        if (m_bIsMoveHorizontally)
        {
            m_objSpritePtr->setPosition(m_objSpritePtr->getPosition().x -
                (m_fSpeedOfElement * A_time_dt.asSeconds()),
                m_objSpritePtr->getPosition().y);
        }

        if (m_bIsMoveVertically)
        {
            m_objSpritePtr->setPosition(m_objSpritePtr->getPosition().x,
                m_objSpritePtr->getPosition().y -
                (m_fSpeedOfElement * A_time_dt.asSeconds()));
        }

        if (m_bIsMoveHorizontally)
            if (m_objSpritePtr->getPosition().x < m_fHorizontalBorder)
                m_bIsActive = false;

        if (m_bIsMoveVertically)
            if (m_objSpritePtr->getPosition().y < m_fVerticalBorder)
                m_bIsActive = false;

        m_objRenderWindow.draw(*m_objSpritePtr);
    }
}