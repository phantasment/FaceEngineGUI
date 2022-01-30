#ifndef FACEENGINEGUI_COMPONENTS_SLIDER_H
#define FACEENGINEGUI_COMPONENTS_SLIDER_H

#include "FaceEngineGUI/UIComponent.h"
#include "FaceEngineGUI/Util/UIButtonState.h"
#include "FaceEngine/Graphics/Texture2D.h"
#include "FaceEngineGUI/Components/Button.h"
#include "FaceEngine/GameUpdate.h"

namespace FaceEngineGUI::Components
{
    class Slider : public FaceEngineGUI::UIComponent
    {
    private:
        FaceEngine::Math::Rectangle sliderButtonBounds;
        FaceEngine::Math::Rectangle sliderSourceRectangle;
        FaceEngineGUI::Util::UIButtonState state;
        bool focused;

        void UpdateState(FaceEngine::GameUpdate* gameUpdate);

    public:
        FaceEngine::Graphics::Texture2D* SliderailTexture;
        FaceEngine::Graphics::Texture2D* SliderTexture;

        Slider(int x, int y, int railLength, int railHeight, int sliderWidth, int sliderHeight, 
               FaceEngine::Graphics::Texture2D* sliderailTexture, 
               FaceEngine::Graphics::Texture2D* sliderTexture, 
               FaceEngineGUI::UIComponent* parent = nullptr);
        ~Slider();

        float GetValue() const;

        void Update(FaceEngine::GameUpdate* gameUpdate) override;
        void Draw(FaceEngine::Graphics::SpriteRenderer* renderer) override;
    };
}

#endif