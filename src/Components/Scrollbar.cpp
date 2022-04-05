#include "FaceEngineGUI/Components/Scrollbar.h"

namespace FaceEngineGUI::Components
{
    Scrollbar::Scrollbar(int x, int y, int width, int height, FaceEngine::Graphics::Texture2D* backgroundTextureAtlas, FaceEngine::Graphics::Texture2D* scrollerTextureAtlas, FaceEngineGUI::UIComponent* parent = nullptr) : UIComponent(x, y, width, height, parent)
    {
        _backgroundTextureAtlas = backgroundTextureAtlas;
        _scrollerTextureAtlas = scrollerTextureAtlas;
    }
}