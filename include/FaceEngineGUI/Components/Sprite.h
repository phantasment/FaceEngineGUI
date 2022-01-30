#ifndef FACEENGINEGUI_COMPONENTS_SPRITE_H
#define FACEENGINEGUI_COMPONENTS_SPRITE_H

#include "FaceEngineGUI/UIComponent.h"

namespace FaceEngineGUI::Components
{
    class Sprite : public FaceEngineGUI::UIComponent
    {
    public:
        FaceEngine::Graphics::Texture2D* Texture;

        Sprite(FaceEngine::Graphics::Texture2D* texture);
        Sprite(int x, int y, int width, int height, FaceEngine::Graphics::Texture2D* texture, FaceEngineGUI::UIComponent* parent = nullptr);
        virtual ~Sprite() { }

        void Draw(FaceEngine::Graphics::SpriteRenderer* renderer) override;
    };
}

#endif