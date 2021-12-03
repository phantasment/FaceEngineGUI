#ifndef FACEENGINEGUI_COMPONENTS_CHECKBOX_H
#define FACEENGINEGUI_COMPONENTS_CHECKBOX_H

#include "FaceEngineGUI/UIComponent.h"
#include "FaceEngine/Math/Rectangle.h"
#include "FaceEngineGUI/Util/UIButtonState.h"
#include <memory>

namespace FaceEngineGUI::Components
{
    class Checkbox : public FaceEngineGUI::UIComponent
    {
    private:
        FaceEngine::Math::Rectangle sourceRectangle;
        FaceEngineGUI::Util::UIButtonState state;
        bool checked;

        void UpdateState(std::shared_ptr<FaceEngine::GameUpdate> gameUpdate);
        
    public:
        std::shared_ptr<FaceEngine::Graphics::Texture2D> Texture;

        Checkbox(std::shared_ptr<FaceEngine::Graphics::Texture2D> texture, FaceEngineGUI::UIComponent* parent = nullptr);
        Checkbox(int x, int y, int width, int height, std::shared_ptr<FaceEngine::Graphics::Texture2D> texture, FaceEngineGUI::UIComponent* parent = nullptr);
    
        ~Checkbox() { }

        void Update(std::shared_ptr<FaceEngine::GameUpdate> gameUpdate) override;
        void Draw(std::shared_ptr<FaceEngine::Graphics::SpriteRenderer> renderer) override;
    };
}

#endif