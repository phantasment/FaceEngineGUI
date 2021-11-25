#ifndef FACEENGINEGUI_COMPONENTS_SPRITE_H
#define FACEENGINEGUI_COMPONENTS_SPRITE_H

#include "FaceEngineGUI/UIComponent.h"

namespace FaceEngineGUI::Components
{
    class Sprite : public FaceEngineGUI::UIComponent
    {
    public:
        std::shared_ptr<FaceEngine::Graphics::Texture2D> Texture;

        Sprite(std::shared_ptr<FaceEngine::Graphics::Texture2D> texture);
        Sprite(int x, int y, int width, int height, std::shared_ptr<FaceEngine::Graphics::Texture2D> texture, FaceEngineGUI::UIComponent* parent);
        virtual ~Sprite() { }

        void Draw(std::shared_ptr<FaceEngine::Graphics::SpriteRenderer> renderer) override;
    };
}

#endif