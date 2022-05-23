#ifndef FACEENGINEGUI_COMPONENTS_SCROLLBAR_H
#define FACEENGINEGUI_COMPONENTS_SCROLLBAR_H

#include "FaceEngineGUI/UIComponent.h"
#include "FaceEngine/Texture2D.h"
#include "FaceEngine/Math/Rectangle.h"
#include "FaceEngineGUI/Util/UIButtonState.h"

namespace FaceEngineGUI
{
    class Scrollbar : public FaceEngineGUI::UIComponent
    {
    private:
        FaceEngine::Texture2D* _backgroundTextureAtlas;
        FaceEngine::Texture2D* _scrollerTextureAtlas;
        FaceEngine::Rectanglef _sourceRectangle;

        float scrollPercentage;

        void UpdateButtonState(FaceEngine::GameUpdate* gameUpdate);

    public:
        Scrollbar(int x, int y, int width, int height, FaceEngine::Texture2D* backgroundTextureAtlas, FaceEngine::Texture2D* scrollerTextureAtlas, FaceEngineGUI::UIComponent* parent = nullptr);
        ~Scrollbar();

        void Update(FaceEngine::GameUpdate* gameUpdate) override;
        void Draw(FaceEngine::SpriteBatcher* renderer) override;
    };
}

#endif