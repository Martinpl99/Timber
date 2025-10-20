#pragma once
#include <vector>
#include <memory>
namespace sf
{
	class RenderWindow;
	class Texture;
}

class IMoveObjectRenderer;

using namespace sf;

class RenderItemsProvider
{
public:
	RenderItemsProvider(RenderWindow& A_objDestinationWindow);
	std::shared_ptr<std::vector<std::shared_ptr<IMoveObjectRenderer>>> ProvideMoveBees(const Texture& A_beeTexture,
		size_t A_horizontalStartPos,
		size_t A_amountOfBees);

	std::shared_ptr<IMoveObjectRenderer> ProvideMoveCloud(const Texture& A_beeTexture,
		size_t A_horizontalStartPos,
		size_t A_verticalStartPos);
private:
	RenderWindow& m_objRenderWindow;
};
