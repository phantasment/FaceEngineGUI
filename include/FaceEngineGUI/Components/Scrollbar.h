#ifndef FACEENGINEGUI_COMPONENTS_SCROLLBAR_H
#define FACEENGINEGUI_COMPONENTS_SCROLLBAR_H

#include "FaceEngineGUI/UIComponent.h"
#include "FaceEngine/Graphics/Texture2D.h"
#include "FaceEngine/Math/Rectangle.h"
#include "FaceEngineGUI/Util/UIButtonState.h"

namespace FaceEngineGUI::Components
{
    class Scrollbar : public FaceEngineGUI::UIComponent
    {
    private:
        FaceEngine::Graphics::Texture2D* _backgroundTextureAtlas;
        FaceEngine::Graphics::Texture2D* _scrollerTextureAtlas;
        FaceEngine::Math::Rectangle _sourceRectangle;

        float scrollPercentage;

        void UpdateButtonState(FaceEngine::GameUpdate* gameUpdate);

    public:
        Scrollbar(int x, int y, int width, int height, FaceEngine::Graphics::Texture2D* backgroundTextureAtlas, FaceEngine::Graphics::Texture2D* scrollerTextureAtlas, FaceEngineGUI::UIComponent* parent = nullptr);
        ~Scrollbar();

        void Update(FaceEngine::GameUpdate* gameUpdate) override;
        void Draw(FaceEngine::Graphics::SpriteRenderer* renderer) override;
    };
}

#endif