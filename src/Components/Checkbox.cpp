#include "FaceEngineGUI/Components/Checkbox.h"

namespace FaceEngineGUI::Components
{
    Checkbox::Checkbox(FaceEngine::Graphics::Texture2D* texture, FaceEngineGUI::UIComponent* parent) : FaceEngineGUI::UIComponent(parent)
    {
        Texture = texture;
        state = FaceEngineGUI::Util::NEUTRAL;
        checked = false;
        sourceRectangle = FaceEngine::Math::Rectangle(0, 0, texture->GetWidth(), texture->GetHeight() / 6);
    }

    Checkbox::Checkbox(int x, int y, int width, int height, FaceEngine::Graphics::Texture2D* texture, FaceEngineGUI::UIComponent* parent) : FaceEngineGUI::UIComponent(x, y, width, height, parent)
    {
        Texture = texture;
        state = FaceEngineGUI::Util::NEUTRAL;
        checked = false;
        sourceRectangle = FaceEngine::Math::Rectangle(0, 0, texture->GetWidth(), texture->GetHeight() / 6);
    }

    void Checkbox::UpdateState(FaceEngine::GameUpdate* gameUpdate)
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

    void Checkbox::Update(FaceEngine::GameUpdate* gameUpdate)
    {
        if (!enabled)
        {
            return;
        }
        
        UpdateState(gameUpdate);
        FaceEngineGUI::UIComponent::Update(gameUpdate);
    }

    void Checkbox::Draw(FaceEngine::Graphics::SpriteRenderer* renderer)
    {
        if (!enabled)
        {
            return;
        }
        
        renderer->Draw(Texture, Bounds, sourceRectangle);
    }
}