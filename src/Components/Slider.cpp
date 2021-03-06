#include "FaceEngineGUI/Components/Slider.h"
#include "FaceEngineGUI/Transforms/Translations/PixelTranslation.h"
#include "FaceEngineGUI/Transforms/Translations/CentreTranslation.h"
#include <iostream>

namespace FaceEngineGUI
{
    Slider::Slider(int x, int y, int railLength, int railHeight, int sliderWidth, int sliderHeight, 
                   FaceEngine::Texture2D* sliderailTexture, 
                   FaceEngine::Texture2D* sliderTexture, 
                   FaceEngineGUI::UIComponent* parent) : FaceEngineGUI::UIComponent(x, y, railLength, railHeight, parent),
    sliderButtonBounds(x - (sliderWidth / 2), y + (railHeight / 2) - (sliderHeight / 2), sliderWidth, sliderHeight),
    sliderSourceRectangle(0, 0, sliderTexture->GetWidth(), sliderTexture->GetHeight() / 3)
    {
        SliderailTexture = sliderailTexture;
        SliderTexture = sliderTexture;
    }

    Slider::~Slider()
    {

    }

    void Slider::UpdateState(FaceEngine::GameUpdate* gameUpdate)
    {
        if (!focused)
        {
            if (sliderButtonBounds.Contains(gameUpdate->GetCursorPos()))
            {
                if (gameUpdate->IsMousePressed(0))
                {
                    focused = true;
                    state = FaceEngineGUI::Util::UIButtonState::PRESSED;
                    sliderSourceRectangle.Y = 2 * (SliderTexture->GetHeight() / 3);
                }
                else
                {
                    state = FaceEngineGUI::Util::UIButtonState::HOVERED;
                    sliderSourceRectangle.Y = SliderTexture->GetHeight() / 3;
                }
            }
            else if (state != FaceEngineGUI::Util::NEUTRAL)
            {
                state = FaceEngineGUI::Util::UIButtonState::NEUTRAL;
                sliderSourceRectangle.Y = 0;
            }
        }
        else
        {
            if (gameUpdate->IsMouseReleased(0))
            {
                focused = false;
                state = FaceEngineGUI::Util::UIButtonState::NEUTRAL;
                sliderSourceRectangle.Y = 0;
            }
        }
    }

    float Slider::GetValue() const
    {
        return ((sliderButtonBounds.X + (sliderButtonBounds.Width / 2)) - Bounds.X) / Bounds.Width;
    }

    void Slider::Update(FaceEngine::GameUpdate* gameUpdate)
    {
        if (!enabled)
        {
            return;
        }
        
        UpdateState(gameUpdate);

        if (focused)
        {
            if (gameUpdate->GetCursorPos().X >= Bounds.GetRight())
            {
                sliderButtonBounds.X = Bounds.GetRight() - (sliderButtonBounds.Width / 2);
            }
            else if (gameUpdate->GetCursorPos().X <= Bounds.X)
            {
                sliderButtonBounds.X = Bounds.X - (sliderButtonBounds.Width / 2);
            }
            else
            {
                sliderButtonBounds.X = gameUpdate->GetCursorPos().X - (sliderButtonBounds.Width / 2);
            }
        }
    }

    void Slider::Draw(FaceEngine::SpriteBatcher* renderer)
    {
        if (!enabled)
        {
            return;
        }
        
        renderer->Draw(SliderailTexture, Bounds);
        renderer->Draw(SliderTexture, sliderButtonBounds, sliderSourceRectangle);
    }
}