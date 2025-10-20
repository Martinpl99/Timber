#include "../../headers/rendering/MoceCloudRendererBuilder.h"
#include "../../headers/rendering/MoveCloudRenderer.h"

MoveCloudRendererBuilder::MoveCloudRendererBuilder(std::shared_ptr<Sprite> A_objSpritePtr, RenderWindow& A_renderWindow)
	: MoveObjectRendererBuilder(A_objSpritePtr, A_renderWindow)
{
	m_elementToCreate = std::make_shared<MoveCloudRenderer>(A_objSpritePtr, A_renderWindow);
}

 std::shared_ptr<IMoveObjectRenderer> MoveCloudRendererBuilder::GetRenderer()
{
	 return m_elementToCreate;
}