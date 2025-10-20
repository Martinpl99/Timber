#include "../headers/Game.h"
#include <iostream>
#include <SFML/Graphics.hpp>
#include "../headers/Settings.h"
#include "../headers/rendering/RenderItemsProvider.h"
#include "../headers/interfaces/IMoveObjectRenderer.h"

using namespace sf;
bool Game::runGame()
{
    VideoMode vm(1920, 1080);
    RenderWindow window(vm, "Timber!!!", Style::Fullscreen);

    //Background
    /*************************************************************/
    Texture backgroundTexture;
    backgroundTexture.loadFromFile("graphics/background.png");

    Sprite spriteBackground;
    spriteBackground.setTexture(backgroundTexture);
    spriteBackground.setPosition(0, 0);
    /**************************************************************/

    Texture beeTexture;
    beeTexture.loadFromFile("graphics/bee.png");

    //Tree texture
    /**************************************************************/
    Texture treeTexture;
    treeTexture.loadFromFile("graphics/tree.png");

    Sprite spriteTree;
    spriteTree.setTexture(treeTexture);
    spriteTree.setPosition(TREE_HORIZONTAL_POSITION, TREE_VERTICAL_POSITION);
    /*************************************************************************/

    //Clouds
    /****************************************************************/
    Texture cloudTexture;
    cloudTexture.loadFromFile("graphics/cloud.png");

    Clock clock;

    RenderItemsProvider renderItemProvider(window);

    auto bees = *renderItemProvider.ProvideMoveBees(beeTexture, 2000, 15);
    auto cloud1 = renderItemProvider.ProvideMoveCloud(cloudTexture, 2000, 0);
    auto cloud2 = renderItemProvider.ProvideMoveCloud(cloudTexture, 1500, 0);
    auto cloud3 = renderItemProvider.ProvideMoveCloud(cloudTexture, 1250, 0);
    auto cloud4 = renderItemProvider.ProvideMoveCloud(cloudTexture, 1000, 0);
    auto cloud5 = renderItemProvider.ProvideMoveCloud(cloudTexture, 750, 0);
    auto cloud6 = renderItemProvider.ProvideMoveCloud(cloudTexture, 500, 0);


    //main game loop
    while (window.isOpen())
    {
        if (Keyboard::isKeyPressed(Keyboard::Escape))
        {
            window.close();
            return false;
        }
        Time time_dt = clock.restart();

        window.draw(spriteBackground);
        cloud1->render(time_dt);
        cloud2->render(time_dt);
        cloud3->render(time_dt);
        cloud4->render(time_dt);
        cloud5->render(time_dt);
        cloud6->render(time_dt);
        window.draw(spriteTree);


        for (auto beeToRender : bees)
            beeToRender->render(time_dt);

        window.display();
    }

    return true;
}