#ifndef FACEENGINEGUI_COMPONENTS_STEPPER_H
#define FACEENGINEGUI_COMPONENTS_STEPPER_H

#include "FaceEngineGUI/UIComponent.h"
#include "FaceEngineGUI/Util/UIButtonState.h"
#include "FaceEngine/Graphics/Texture2D.h"
#include "FaceEngineGUI/Components/Button.h"
#include "FaceEngine/GameUpdate.h"
#include <memory>

namespace FaceEngineGUI::Components
{
    class Stepper : public FaceEngineGUI::UIComponent
    {
    private:
        FaceEngine::Math::Rectangle stepperButtonBounds;
        FaceEngine::Math::Rectangle stepperButtonSourceRect;
        FaceEngineGUI::Util::UIButtonState state;
        bool focused;
        int stepLength;

        void UpdateState(FaceEngine::GameUpdate* gameUpdate);

    public:
        FaceEngine::Graphics::Texture2D* StepperRailTexture;
        FaceEngine::Graphics::Texture2D* StepperButtonTexture;

        Stepper(int x, int y, int railLength, int railHeight, int buttonWidth, int buttonHeight, int steps,
               FaceEngine::Graphics::Texture2D* stepperRailTexture, 
               FaceEngine::Graphics::Texture2D* stepperButtonTexture, 
               FaceEngineGUI::UIComponent* parent = nullptr);
        ~Stepper();

        float GetValue() const;

        void Update(FaceEngine::GameUpdate* gameUpdate) override;
        void Draw(FaceEngine::Graphics::SpriteRenderer* renderer) override;
    };
}

#endif