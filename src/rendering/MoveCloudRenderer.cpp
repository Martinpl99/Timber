#include "../../headers/rendering/MoveCloudRenderer.h"
#include <SFML/Graphics.hpp>

MoveCloudRenderer::MoveCloudRenderer(std::shared_ptr<Sprite> A_objSpritePtr, RenderWindow& A_renderWindow)
	: MoveObjectRenderer(A_objSpritePtr, A_renderWindow)
{

}

void MoveCloudRenderer::render(const Time& A_time_dt)
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
            auto newVerticalStartPos = static_cast<float>(m_fVerticalMoveRange + rand() % 101);
            auto newHorizonstalStartPos = static_cast<float>(m_fHorizontalMoveRange + rand() % 101);

            if (m_isInitialized && m_bIsMoveHorizontally)
                m_objSpritePtr->setPosition(newHorizonstalStartPos, m_fVerticalStartPos);

            if (m_isInitialized && m_bIsMoveVertically)
                m_objSpritePtr->setPosition(m_fHorizontalMoveRange, newVerticalStartPos);

            if (m_isInitialized && m_bIsMoveVertically && m_bIsMoveHorizontally)
                m_objSpritePtr->setPosition(newHorizonstalStartPos, newVerticalStartPos);
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
                m_objSpritePtr->getPosition().y +
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
