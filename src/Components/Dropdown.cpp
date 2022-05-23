#include "FaceEngineGUI/Components/Dropdown.h"
#include "FaceEngineGUI/Transforms/Translations/PixelTranslation.h"
#include "FaceEngineGUI/Transforms/Scales/RelativeScale.h"
#include "FaceEngineGUI/Transforms/Translations/PixelTranslation.h"
#include <iostream>

namespace FaceEngineGUI
{
    Dropdown::Dropdown(int x, int y, int width, int height, FaceEngine::Texture2D* buttonTextureAtlas, FaceEngine::Texture2D* extensionBackgroundTexture, FaceEngineGUI::UIComponent* parent) : FaceEngineGUI::UIComponent(x, y, width, height, parent)
    {
        _buttonTextureAtlas = buttonTextureAtlas;
        _extensionBackgroundTexture = extensionBackgroundTexture;
        _elements = std::vector<UIComponent*>();
        _extended = false;
        _extensionBounds = FaceEngine::Rectanglef(x, y + height, width, 0);

        _buttonSourceRectangle = FaceEngine::Rectanglef(0, 0, _buttonTextureAtlas->GetWidth(), _buttonTextureAtlas->GetHeight() / 3);
    }

    Dropdown::~Dropdown()
    {
        for (int i = 0; i < _elements.size(); ++i)
        {
            delete _elements[i];
        }

        _elements.clear();
    }

    void Dropdown::AddElement(UIComponent* element) // TODO: update extension bounds.
    {
        AddChild(element);

        element->SetWidth(new FaceEngineGUI::Scales::RelativeScale(1.0f));
        element->SetX(new FaceEngineGUI::Translations::PixelTranslation(0));

        if (_elements.size() == 0)
        {
            element->SetY(new FaceEngineGUI::Translations::PixelTranslation(Bounds.Height));
        }
        else
        {
            element->SetY(new FaceEngineGUI::Translations::PixelTranslation(_elements.back()->GetRelativeY() + _elements.back()->GetHeight()));
        }

        _elements.push_back(element);
        _extensionBounds.Height += element->GetHeight();
    }

    void Dropdown::Update(FaceEngine::GameUpdate* gameUpdate)
    {
        if (!enabled)
        {
            return;
        }
        
        // Update Elements

        if (_extended || _closedLastCycle)
        {
            for (int i = 0; i < _elements.size(); ++i)
            {
                _elements[i]->Update(gameUpdate);
            }

            if (_closedLastCycle)
            {
                _closedLastCycle = false;
            }
        }

        // Update Button and State

        UpdateExtensionState(gameUpdate);
        UpdateButtonState(gameUpdate);
    }

    void Dropdown::Draw(FaceEngine::SpriteBatcher* renderer)
    {
        if (!enabled)
        {
            return;
        }
        
        // Draw Button

        renderer->Draw(_buttonTextureAtlas, Bounds, _buttonSourceRectangle);

        // Draw Extension and Elements

        if (!_extended)
        {
            return;
        }

        renderer->Draw(_extensionBackgroundTexture, _extensionBounds);
        
        for (int i = 0; i < _elements.size(); ++i)
        {
            _elements[i]->Draw(renderer);
        }
    }

    void Dropdown::UpdateButtonState(FaceEngine::GameUpdate* gameUpdate)
    {
        if (!Bounds.Contains(gameUpdate->GetCursorPos()))
        {
            buttonState = FaceEngineGUI::Util::UIButtonState::NEUTRAL;
            _buttonSourceRectangle.Y = 0;
        }
        else if (gameUpdate->IsMouseReleased(0))
        {
            buttonState = FaceEngineGUI::Util::UIButtonState::CLICKED;
            _extended = !_extended;
        }
        else if (gameUpdate->IsMouseDown(0))
        {
            buttonState = FaceEngineGUI::Util::UIButtonState::PRESSED;
            _buttonSourceRectangle.Y = 2 * (_buttonTextureAtlas->GetHeight() / 3);
        }
        else
        {
            buttonState = FaceEngineGUI::Util::UIButtonState::HOVERED;
            _buttonSourceRectangle.Y = _buttonTextureAtlas->GetHeight() / 3;
        }
    }

    void Dropdown::UpdateExtensionState(FaceEngine::GameUpdate* gameUpdate)
    {
        if (_extended && gameUpdate->IsMouseReleased(0))
        {
            _extended = false;
            _closedLastCycle = true;
        }
    }
}