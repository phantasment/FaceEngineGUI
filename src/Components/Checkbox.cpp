#include "FaceEngineGUI/Components/Checkbox.h"

namespace FaceEngineGUI
{
    Checkbox::Checkbox(FaceEngine::Texture2D* texture, FaceEngineGUI::UIComponent* parent) : FaceEngineGUI::UIComponent(parent)
    {
        Texture = texture;
        state = FaceEngineGUI::Util::NEUTRAL;
        _checked = false;
        sourceRectangle = FaceEngine::Rectanglef(0, 0, texture->GetWidth(), texture->GetHeight() / 6);
    }

    Checkbox::Checkbox(int x, int y, int width, int height, FaceEngine::Texture2D* texture, FaceEngineGUI::UIComponent* parent) : FaceEngineGUI::UIComponent(x, y, width, height, parent)
    {
        Texture = texture;
        state = FaceEngineGUI::Util::NEUTRAL;
        _checked = false;
        sourceRectangle = FaceEngine::Rectanglef(0, 0, texture->GetWidth(), texture->GetHeight() / 6);
    }

    void Checkbox::UpdateState(FaceEngine::GameUpdate* gameUpdate)
    {
        if (!Bounds.Contains(gameUpdate->GetCursorPos()))
        {
            state = FaceEngineGUI::Util::NEUTRAL;

            if (_checked == true)
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
            _checked = !_checked;
        }
        else if (gameUpdate->IsMouseDown(0))
        {
            state = FaceEngineGUI::Util::PRESSED;
            
            if (_checked == true)
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

            if (_checked == true)
            {
                sourceRectangle.Y = 4 * (Texture->GetHeight() / 6);
            }
            else
            {
                sourceRectangle.Y = Texture->GetHeight() / 6;
            }
        }
    }

    void Checkbox::SetChecked(bool checked)
    {
        _checked = checked;
    }

    bool Checkbox::IsChecked()
    {
        return _checked;
    }

    bool Checkbox::IsClicked()
    {
        return state == FaceEngineGUI::Util::CLICKED;
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

    void Checkbox::Draw(FaceEngine::SpriteBatcher* renderer)
    {
        if (!enabled)
        {
            return;
        }
        
        renderer->Draw(Texture, Bounds, sourceRectangle);
    }
}