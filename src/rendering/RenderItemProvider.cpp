#include "../../headers/rendering/RenderItemsProvider.h"
#include <SFML/Graphics.hpp>
#include "../../headers/rendering/MoveObjectRendererBuilder.h"
#include <iostream>
#include<vector>
#include<SFML/System/Time.hpp>
#include "../../headers/rendering/MoceCloudRendererBuilder.h"

RenderItemsProvider::RenderItemsProvider(RenderWindow& A_objDestinationWindow)
    : m_objRenderWindow(A_objDestinationWindow)
{

}

std::shared_ptr<std::vector<std::shared_ptr<IMoveObjectRenderer>>> RenderItemsProvider::ProvideMoveBees(const Texture& A_beeTexture, size_t A_horizontalStartPos, size_t A_amountOfBees)
{
    std::vector<std::shared_ptr<Sprite>> spriteBees;

    for (size_t idx = 0; idx < A_amountOfBees; idx++)
    {
        auto spriteBeeLoop = std::make_shared<Sprite>();
        spriteBeeLoop->setTexture(A_beeTexture);
        spriteBees.push_back(spriteBeeLoop);
    }

     auto bees = std::make_shared< std::vector<std::shared_ptr<IMoveObjectRenderer>>>();

    for (auto spriteBeel : spriteBees)
    {
        MoveObjectRendererBuilder moveObjectRenderer(spriteBeel, m_objRenderWindow);

        bees->push_back(moveObjectRenderer.SetSpeedOfElement(static_cast<float>(rand() % 2000))
            .SetHorizontalStartPosition(static_cast<float>(A_horizontalStartPos))
            .SetVerticalStartPosition(static_cast<float>(rand() % 1100))
            .SetVerticalMoveRange(1100)
            .SetIsMoveHorizontally(true)
            .SetHorizontalBorder(static_cast<float>(-100))
            .GetRenderer());
    }

    return bees;
}

std::shared_ptr<IMoveObjectRenderer> RenderItemsProvider::ProvideMoveCloud(const Texture& A_beeTexture,
    size_t A_horizontalStartPos,
    size_t A_verticalStartPos)
{
    auto cloudSprite = std::make_shared<Sprite>();
    cloudSprite->setTexture(A_beeTexture);

    MoveCloudRendererBuilder moveObjectRenderer(cloudSprite, m_objRenderWindow);

    return moveObjectRenderer.SetSpeedOfElement(static_cast<float>(20))
        .SetHorizontalStartPosition(static_cast<float>(A_horizontalStartPos))
        .SetVerticalStartPosition(static_cast<float>(A_verticalStartPos))
        .SetHorizontalBorder(static_cast<float>(-200))
        .SetVerticalBorder(static_cast<float>(-200))
        .SetHorizontalMoveRange(2500)
        .SetVerticalMoveRange(10)
        .SetIsMoveVertically(true)
        .SetIsMoveHorizontally(true)
        .GetRenderer();
}