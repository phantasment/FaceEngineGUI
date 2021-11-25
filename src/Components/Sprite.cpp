#include "FaceEngineGUI/Components/Sprite.h"
#include <iostream>

namespace FaceEngineGUI::Components
{
    Sprite::Sprite(std::shared_ptr<FaceEngine::Graphics::Texture2D> texture) : UIComponent(0, 0, texture->GetWidth(), texture->GetHeight())
    {
        Texture = texture;
    }

    Sprite::Sprite(int x, int y, int width, int height, std::shared_ptr<FaceEngine::Graphics::Texture2D> texture, FaceEngineGUI::UIComponent* parent = nullptr) : UIComponent(x, y, width, height, parent)
    {
        Texture = texture;
    }

    void Sprite::Draw(std::shared_ptr<FaceEngine::Graphics::SpriteRenderer> renderer)
    {
        renderer->Draw(Texture, Bounds);
    }
}