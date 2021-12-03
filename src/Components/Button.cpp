#include "FaceEngineGUI/Components/Button.h"
#include <iostream>

namespace FaceEngineGUI::Components
{
    Button::Button(std::shared_ptr<FaceEngine::Graphics::Texture2D> texture, UIComponent* parent) : FaceEngineGUI::UIComponent(0, 0, 0, 0, parent)
    {
        Initialise(texture);
    }

    Button::Button(int x, int y, int width, int height, std::shared_ptr<FaceEngine::Graphics::Texture2D> texture, FaceEngineGUI::UIComponent* parent) : FaceEngineGUI::UIComponent(x, y, width, height, parent)
    {
        Initialise(texture);
    }

    void Button::Initialise(std::shared_ptr<FaceEngine::Graphics::Texture2D> texture)
    {
        Texture = texture;
        buttonState = FaceEngineGUI::Util::UIButtonState::NEUTRAL;
        sourceRectangle = FaceEngine::Math::Rectangle(0, 0, texture->GetWidth(), texture->GetHeight() / 3);
    }

    void Button::UpdateButtonState(std::shared_ptr<FaceEngine::GameUpdate> gameUpdate)
    {
        if (!Bounds.Contains(gameUpdate->GetCursorPos()))
        {
            buttonState = FaceEngineGUI::Util::UIButtonState::NEUTRAL;
            sourceRectangle.Y = 0;
        }
        else if (gameUpdate->IsMouseReleased(0))
        {
            buttonState = FaceEngineGUI::Util::UIButtonState::CLICKED;
        }
        else if (gameUpdate->IsMouseDown(0))
        {
            buttonState = FaceEngineGUI::Util::UIButtonState::PRESSED;
            sourceRectangle.Y = 2 * (Texture->GetHeight() / 3);
        }
        else
        {
            buttonState = FaceEngineGUI::Util::UIButtonState::HOVERED;
            sourceRectangle.Y = Texture->GetHeight() / 3;
        }
    }

    FaceEngineGUI::Util::UIButtonState Button::GetState() const
    {
        return buttonState;
    }

    void Button::Update(std::shared_ptr<FaceEngine::GameUpdate> gameUpdate)
    {
        UpdateButtonState(gameUpdate);
        FaceEngineGUI::UIComponent::Update(gameUpdate);
    }

    void Button::Draw(std::shared_ptr<FaceEngine::Graphics::SpriteRenderer> renderer)
    {
        renderer->Draw(Texture, Bounds, sourceRectangle);
    }
}
