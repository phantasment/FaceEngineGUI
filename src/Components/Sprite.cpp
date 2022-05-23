#include "FaceEngineGUI/Components/Sprite.h"
#include <iostream>

namespace FaceEngineGUI
{
    Sprite::Sprite(FaceEngine::Texture2D* texture) : UIComponent(0, 0, texture->GetWidth(), texture->GetHeight())
    {
        Texture = texture;
    }

    Sprite::Sprite(int width, int height, FaceEngine::Texture2D* texture, FaceEngineGUI::UIComponent* parent) : UIComponent(0, 0, width, height, parent)
    {
        Texture = texture;
    }

    Sprite::Sprite(int x, int y, int width, int height, FaceEngine::Texture2D* texture, FaceEngineGUI::UIComponent* parent) : UIComponent(x, y, width, height, parent)
    {
        Texture = texture;
    }

    void Sprite::Draw(FaceEngine::SpriteBatcher* renderer)
    {
        if (!enabled)
        {
            return;
        }
        
        renderer->Draw(Texture, Bounds);
    }
}