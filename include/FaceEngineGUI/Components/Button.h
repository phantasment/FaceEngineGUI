#ifndef FACEENGINEGUI_COMPONENTS_BUTTON_H
#define FACEENGINEGUI_COMPONENTS_BUTTON_H

#include "FaceEngine/Math/Rectangle.h"
#include "FaceEngineGUI/UIComponent.h"
#include "FaceEngineGUI/Util/UIButtonState.h"
#include "FaceEngine/Texture2D.h"

namespace FaceEngineGUI
{
    class Button : public FaceEngineGUI::UIComponent
    {
    private:
        FaceEngine::Rectanglef sourceRectangle;
        FaceEngineGUI::Util::UIButtonState buttonState;

        // ----- Initialisers -----

        void Initialise(FaceEngine::Texture2D* texture);

        // ----- Helper Methods -----

        void UpdateButtonState(FaceEngine::GameUpdate* gameUpdate);

    public:
        FaceEngine::Texture2D* Texture;

        // ----- Constructors and Destructors -----

        Button(FaceEngine::Texture2D* texture, FaceEngineGUI::UIComponent* parent = nullptr);
        Button(int x, int y, int width, int height, FaceEngine::Texture2D* texture, FaceEngineGUI::UIComponent* parent = nullptr);

        ~Button() { }

        // ----- Methods -----

        FaceEngineGUI::Util::UIButtonState GetState() const;
        bool IsClicked() const;
        void Update(FaceEngine::GameUpdate* gameUpdate) override;
        void Draw(FaceEngine::SpriteBatcher* renderer) override;
    };
}

#endif