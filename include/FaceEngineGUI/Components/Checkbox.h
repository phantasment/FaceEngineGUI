#ifndef FACEENGINEGUI_COMPONENTS_CHECKBOX_H
#define FACEENGINEGUI_COMPONENTS_CHECKBOX_H

#include "FaceEngineGUI/UIComponent.h"
#include "FaceEngine/Math/Rectangle.h"
#include "FaceEngineGUI/Util/UIButtonState.h"

namespace FaceEngineGUI
{
    class Checkbox : public FaceEngineGUI::UIComponent
    {
    private:
        FaceEngine::Rectanglef sourceRectangle;
        FaceEngineGUI::Util::UIButtonState state;
        bool _checked;

        void UpdateState(FaceEngine::GameUpdate* gameUpdate);
        
    public:
        FaceEngine::Texture2D* Texture;

        Checkbox(FaceEngine::Texture2D* texture, FaceEngineGUI::UIComponent* parent = nullptr);
        Checkbox(int x, int y, int width, int height, FaceEngine::Texture2D* texture, FaceEngineGUI::UIComponent* parent = nullptr);
    
        ~Checkbox() { }

        void SetChecked(bool checked);
        bool IsChecked();

        void Update(FaceEngine::GameUpdate* gameUpdate) override;
        void Draw(FaceEngine::SpriteBatcher* renderer) override;
    };
}

#endif