#include "FaceEngineGUI/Components/Stepper.h"
#include <cmath>
#include <iostream>

namespace FaceEngineGUI::Components
{
    Stepper::Stepper(int x, int y, int railLength, int railHeight, int sliderWidth, int sliderHeight, int steps, // TODO: error if steps = 0 or greater than rail length
                   std::shared_ptr<FaceEngine::Graphics::Texture2D> sliderailTexture, 
                   std::shared_ptr<FaceEngine::Graphics::Texture2D> sliderTexture, 
                   FaceEngineGUI::UIComponent* parent) : FaceEngineGUI::UIComponent(x, y, railLength, railHeight, parent),
    stepperButtonBounds(x - (sliderWidth / 2), y + (railHeight / 2) - (sliderHeight / 2), sliderWidth, sliderHeight),
    stepperButtonSourceRect(0, 0, sliderTexture->GetWidth(), sliderTexture->GetHeight() / 3),
    stepLength(railLength / (steps - 1))
    {
        std::cout << stepLength << std::endl;
        StepperRailTexture = sliderailTexture;
        StepperButtonTexture = sliderTexture;
    }

    Stepper::~Stepper()
    {

    }

    void Stepper::UpdateState(std::shared_ptr<FaceEngine::GameUpdate> gameUpdate)
    {
        if (!focused)
        {
            if (stepperButtonBounds.Contains(gameUpdate->GetCursorPos()))
            {
                if (gameUpdate->IsMousePressed(0))
                {
                    focused = true;
                    state = FaceEngineGUI::Util::UIButtonState::PRESSED;
                    stepperButtonSourceRect.Y = 2 * (StepperButtonTexture->GetHeight() / 3);
                }
                else
                {
                    state = FaceEngineGUI::Util::UIButtonState::HOVERED;
                    stepperButtonSourceRect.Y = StepperButtonTexture->GetHeight() / 3;
                }
            }
            else if (state != FaceEngineGUI::Util::NEUTRAL)
            {
                state = FaceEngineGUI::Util::UIButtonState::NEUTRAL;
                stepperButtonSourceRect.Y = 0;
            }
        }
        else
        {
            if (gameUpdate->IsMouseReleased(0))
            {
                focused = false;
                state = FaceEngineGUI::Util::UIButtonState::NEUTRAL;
                stepperButtonSourceRect.Y = 0;
            }
        }
    }

    float Stepper::GetValue() const
    {
        return ((stepperButtonBounds.X + (stepperButtonBounds.Width / 2)) - Bounds.X) / Bounds.Width;
    }

    void Stepper::Update(std::shared_ptr<FaceEngine::GameUpdate> gameUpdate)
    {
        UpdateState(gameUpdate);

        if (focused)
        {
            if (gameUpdate->GetCursorPos().X >= Bounds.GetRight())
            {
                stepperButtonBounds.X = Bounds.GetRight() - (stepperButtonBounds.Width / 2);
            }
            else if (gameUpdate->GetCursorPos().X <= Bounds.X)
            {
                stepperButtonBounds.X = Bounds.X - (stepperButtonBounds.Width / 2);
            }
            else
            {
                std::cout << "cursor: " << gameUpdate->GetCursorPos().X << ", stepLength: " << stepLength << ", result: " << (std::round(gameUpdate->GetCursorPos().X / stepLength) * stepLength) << std::endl;
                stepperButtonBounds.X = (std::round(gameUpdate->GetCursorPos().X / stepLength) * stepLength) - (stepperButtonBounds.Width / 2);
            }
        }
    }

    void Stepper::Draw(std::shared_ptr<FaceEngine::Graphics::SpriteRenderer> renderer)
    {
        renderer->Draw(StepperRailTexture, Bounds);
        renderer->Draw(StepperButtonTexture, stepperButtonBounds, stepperButtonSourceRect);
    }
}