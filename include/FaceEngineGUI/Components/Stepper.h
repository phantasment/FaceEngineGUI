#ifndef FACEENGINEGUI_COMPONENTS_STEPPER_H
#define FACEENGINEGUI_COMPONENTS_STEPPER_H

#include "FaceEngineGUI/UIComponent.h"
#include "FaceEngineGUI/Util/UIButtonState.h"
#include "FaceEngine/Texture2D.h"
#include "FaceEngineGUI/Components/Button.h"
#include "FaceEngine/GameUpdate.h"
#include <memory>

namespace FaceEngineGUI
{
    class Stepper : public FaceEngineGUI::UIComponent
    {
    private:
        FaceEngine::Rectanglef stepperButtonBounds;
        FaceEngine::Rectanglef stepperButtonSourceRect;
        FaceEngineGUI::Util::UIButtonState state;
        bool focused;
        int stepLength;

        void UpdateState(FaceEngine::GameUpdate* gameUpdate);

    public:
        FaceEngine::Texture2D* StepperRailTexture;
        FaceEngine::Texture2D* StepperButtonTexture;

        Stepper(int x, int y, int railLength, int railHeight, int buttonWidth, int buttonHeight, int steps,
               FaceEngine::Texture2D* stepperRailTexture, 
               FaceEngine::Texture2D* stepperButtonTexture, 
               FaceEngineGUI::UIComponent* parent = nullptr);
        ~Stepper();

        float GetValue() const;

        void Update(FaceEngine::GameUpdate* gameUpdate) override;
        void Draw(FaceEngine::SpriteBatcher* renderer) override;
    };
}

#endif