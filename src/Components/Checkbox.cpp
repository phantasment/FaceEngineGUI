#include "FaceEngineGUI/Components/Checkbox.h"

namespace FaceEngineGUI::Components
{
    Checkbox::Checkbox(std::shared_ptr<FaceEngine::Graphics::Texture2D> texture, FaceEngineGUI::UIComponent* parent) : FaceEngineGUI::UIComponent(parent)
    {
        Texture = texture;
        state = FaceEngineGUI::Util::NEUTRAL;
        checked = false;
        sourceRectangle = FaceEngine::Math::Rectangle(0, 0, texture->GetWidth(), texture->GetHeight() / 6);
    }

    Checkbox::Checkbox(int x, int y, int width, int height, std::shared_ptr<FaceEngine::Graphics::Texture2D> texture, FaceEngineGUI::UIComponent* parent) : FaceEngineGUI::UIComponent(x, y, width, height, parent)
    {
        Texture = texture;
        state = FaceEngineGUI::Util::NEUTRAL;
        checked = false;
        sourceRectangle = FaceEngine::Math::Rectangle(0, 0, texture->GetWidth(), texture->GetHeight() / 6);
    }

    void Checkbox::UpdateState(std::shared_ptr<FaceEngine::GameUpdate> gameUpdate)
    {
        if (!Bounds.Contains(gameUpdate->GetCursorPos()))
        {
            state = FaceEngineGUI::Util::NEUTRAL;

            if (checked == true)
            {
                sourceRectangle.Y = 3 * (Texture->GetHeight() / 6);
            } 
            else
            {
                sourceRectangle.Y = 0;
            }
        }
        else if (gameUpdate->IsMouseReleased(0))
        {
            state = FaceEngineGUI::Util::CLICKED;
            checked = !checked;
        }
        else if (gameUpdate->IsMouseDown(0))
        {
            state = FaceEngineGUI::Util::PRESSED;
            
            if (checked == true)
            {
                sourceRectangle.Y = 5 * (Texture->GetHeight() / 6);
            }
            else
            {
                sourceRectangle.Y = 2 * (Texture->GetHeight() / 6);
            }
        } 
        else
        {
            state = FaceEngineGUI::Util::HOVERED;

            if (checked == true)
            {
                sourceRectangle.Y = 4 * (Texture->GetHeight() / 6);
            }
            else
            {
                sourceRectangle.Y = Texture->GetHeight() / 6;
            }
        }
    }

    void Checkbox::Update(std::shared_ptr<FaceEngine::GameUpdate> gameUpdate)
    {
        UpdateState(gameUpdate);
        FaceEngineGUI::UIComponent::Update(gameUpdate);
    }

    void Checkbox::Draw(std::shared_ptr<FaceEngine::Graphics::SpriteRenderer> renderer)
    {
        renderer->Draw(Texture, Bounds, sourceRectangle);
    }
}