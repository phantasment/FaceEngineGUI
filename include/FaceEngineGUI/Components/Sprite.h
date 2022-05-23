#ifndef FACEENGINEGUI_COMPONENTS_SPRITE_H
#define FACEENGINEGUI_COMPONENTS_SPRITE_H

#include "FaceEngineGUI/UIComponent.h"

namespace FaceEngineGUI
{
    class Sprite : public FaceEngineGUI::UIComponent
    {
    public:
        FaceEngine::Texture2D* Texture;

        Sprite(FaceEngine::Texture2D* texture);
        Sprite(int width, int height, FaceEngine::Texture2D* texture, FaceEngineGUI::UIComponent* parent = nullptr);
        Sprite(int x, int y, int width, int height, FaceEngine::Texture2D* texture, FaceEngineGUI::UIComponent* parent = nullptr);
        virtual ~Sprite() { }

        void Draw(FaceEngine::SpriteBatcher* renderer) override;
    };
}

#endif