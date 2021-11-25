#ifndef FACEENGINEGUI_COMPONENTS_BUTTON_H
#define FACEENGINEGUI_COMPONENTS_BUTTON_H

#include "FaceEngine/Math/Rectangle.h"
#include "FaceEngineGUI/UIComponent.h"
#include "FaceEngineGUI/Util/UIButtonState.h"
#include <memory>

namespace FaceEngineGUI::Components
{
    class Button : public FaceEngineGUI::UIComponent
    {
    private:
        FaceEngine::Math::Rectangle sourceRectangle;
        FaceEngineGUI::Util::UIButtonState buttonState;

        // ----- Initialisers -----

        void Initialise(std::shared_ptr<FaceEngine::Graphics::Texture2D> texture);

        // ----- Helper Methods -----

        void UpdateButtonState(std::shared_ptr<FaceEngine::GameUpdate> gameUpdate);

    public:
        std::shared_ptr<FaceEngine::Graphics::Texture2D> Texture;

        // ----- Constructors and Destructors -----

        Button(std::shared_ptr<FaceEngine::Graphics::Texture2D> texture);
        Button(std::shared_ptr<FaceEngine::Graphics::Texture2D> texture, FaceEngineGUI::UIComponent* parent);
        Button(int x, int y, int width, int height, std::shared_ptr<FaceEngine::Graphics::Texture2D> texture);
        Button(int x, int y, int width, int height, std::shared_ptr<FaceEngine::Graphics::Texture2D> texture, FaceEngineGUI::UIComponent* parent);

        ~Button() { }

        // ----- Methods -----

        void Update(std::shared_ptr<FaceEngine::GameUpdate> gameUpdate) override;
        void Draw(std::shared_ptr<FaceEngine::Graphics::SpriteRenderer> renderer) override;
    };
}

#endif