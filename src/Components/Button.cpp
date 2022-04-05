#include "FaceEngineGUI/Components/Button.h"
#include <iostream>

namespace FaceEngineGUI::Components
{
    Button::Button(FaceEngine::Graphics::Texture2D* texture, UIComponent* parent) : FaceEngineGUI::UIComponent(0, 0, 0, 0, parent)
    {
        Initialise(texture);
    }

    Button::Button(int x, int y, int width, int height, FaceEngine::Graphics::Texture2D* texture, FaceEngineGUI::UIComponent* parent) : FaceEngineGUI::UIComponent(x, y, width, height, parent)
    {
        Initialise(texture);
    }

    void Button::Initialise(FaceEngine::Graphics::Texture2D* texture)
    {
        Texture = texture;
        buttonState = FaceEngineGUI::Util::UIButtonState::NEUTRAL;
        sourceRectangle = FaceEngine::Math::Rectangle(0, 0, texture->GetWidth(), texture->GetHeight() / 3);
    }

    void Button::UpdateButtonState(FaceEngine::GameUpdate* gameUpdate)
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

    bool Button::IsClicked() const
    {
        return buttonState == FaceEngineGUI::Util::UIButtonState::CLICKED;
    }

    void Button::Update(FaceEngine::GameUpdate* gameUpdate)
    {
        if (!enabled)
        {
            return;
        }

        UpdateButtonState(gameUpdate);
        FaceEngineGUI::UIComponent::Update(gameUpdate);
    }

    void Button::Draw(FaceEngine::Graphics::SpriteRenderer* renderer)
    {
        if (!enabled)
        {
            return;
        }
        
        renderer->Draw(Texture, Bounds, sourceRectangle);
    }
}
