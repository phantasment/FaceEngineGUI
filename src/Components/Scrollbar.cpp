#include "FaceEngineGUI/Components/Scrollbar.h"

namespace FaceEngineGUI
{
    Scrollbar::Scrollbar(int x, int y, int width, int height, FaceEngine::Texture2D* backgroundTextureAtlas, FaceEngine::Texture2D* scrollerTextureAtlas, FaceEngineGUI::UIComponent* parent = nullptr) : UIComponent(x, y, width, height, parent)
    {
        _backgroundTextureAtlas = backgroundTextureAtlas;
        _scrollerTextureAtlas = scrollerTextureAtlas;
    }
}