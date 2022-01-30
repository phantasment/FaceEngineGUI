#ifndef FACEENGINEGUI_COMPONENTS_CHECKBOX_H
#define FACEENGINEGUI_COMPONENTS_CHECKBOX_H

#include "FaceEngineGUI/UIComponent.h"
#include "FaceEngine/Math/Rectangle.h"
#include "FaceEngineGUI/Util/UIButtonState.h"

namespace FaceEngineGUI::Components
{
    class Checkbox : public FaceEngineGUI::UIComponent
    {
    private:
        FaceEngine::Math::Rectangle sourceRectangle;
        FaceEngineGUI::Util::UIButtonState state;
        bool checked;

        void UpdateState(FaceEngine::GameUpdate* gameUpdate);
        
    public:
        FaceEngine::Graphics::Texture2D* Texture;

        Checkbox(FaceEngine::Graphics::Texture2D* texture, FaceEngineGUI::UIComponent* parent = nullptr);
        Checkbox(int x, int y, int width, int height, FaceEngine::Graphics::Texture2D* texture, FaceEngineGUI::UIComponent* parent = nullptr);
    
        ~Checkbox() { }

        void Update(FaceEngine::GameUpdate* gameUpdate) override;
        void Draw(FaceEngine::Graphics::SpriteRenderer* renderer) override;
    };
}

#endif