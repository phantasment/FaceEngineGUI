#ifndef FACEENGINEGUI_COMPONENTS_SLIDER_H
#define FACEENGINEGUI_COMPONENTS_SLIDER_H

#include "FaceEngineGUI/UIComponent.h"
#include "FaceEngineGUI/Util/UIButtonState.h"
#include "FaceEngine/Texture2D.h"
#include "FaceEngineGUI/Components/Button.h"
#include "FaceEngine/GameUpdate.h"

namespace FaceEngineGUI
{
    class Slider : public FaceEngineGUI::UIComponent
    {
    private:
        FaceEngine::Rectanglef sliderButtonBounds;
        FaceEngine::Rectanglef sliderSourceRectangle;
        FaceEngineGUI::Util::UIButtonState state;
        bool focused;

        void UpdateState(FaceEngine::GameUpdate* gameUpdate);

    public:
        FaceEngine::Texture2D* SliderailTexture;
        FaceEngine::Texture2D* SliderTexture;

        Slider(int x, int y, int railLength, int railHeight, int sliderWidth, int sliderHeight, 
               FaceEngine::Texture2D* sliderailTexture, 
               FaceEngine::Texture2D* sliderTexture, 
               FaceEngineGUI::UIComponent* parent = nullptr);
        ~Slider();

        float GetValue() const;

        void Update(FaceEngine::GameUpdate* gameUpdate) override;
        void Draw(FaceEngine::SpriteBatcher* renderer) override;
    };
}

#endif