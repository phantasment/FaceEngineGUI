#ifndef FACEENGINEGUI_COMPONENTS_SLIDER_H
#define FACEENGINEGUI_COMPONENTS_SLIDER_H

#include "FaceEngineGUI/UIComponent.h"
#include "FaceEngineGUI/Util/UIButtonState.h"
#include "FaceEngine/Graphics/Texture2D.h"
#include "FaceEngineGUI/Components/Button.h"
#include "FaceEngine/GameUpdate.h"
#include <memory>

namespace FaceEngineGUI::Components
{
    class Slider : public FaceEngineGUI::UIComponent
    {
    private:
        FaceEngine::Math::Rectangle sliderButtonBounds;
        FaceEngine::Math::Rectangle sliderSourceRectangle;
        FaceEngineGUI::Util::UIButtonState state;
        bool focused;

        void UpdateState(std::shared_ptr<FaceEngine::GameUpdate> gameUpdate);

    public:
        std::shared_ptr<FaceEngine::Graphics::Texture2D> SliderailTexture;
        std::shared_ptr<FaceEngine::Graphics::Texture2D> SliderTexture;

        Slider(int x, int y, int railLength, int railHeight, int sliderWidth, int sliderHeight, 
               std::shared_ptr<FaceEngine::Graphics::Texture2D> sliderailTexture, 
               std::shared_ptr<FaceEngine::Graphics::Texture2D> sliderTexture, 
               FaceEngineGUI::UIComponent* parent = nullptr);
        ~Slider();

        float GetValue() const;

        void Update(std::shared_ptr<FaceEngine::GameUpdate> gameUpdate) override;
        void Draw(std::shared_ptr<FaceEngine::Graphics::SpriteRenderer> renderer) override;
    };
}

#endif