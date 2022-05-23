#include "FaceEngineGUI/Components/Label.h"
#include <iostream>

namespace FaceEngineGUI
{
    Label::Label(int x, int y, int width, int height, std::string text, FaceEngine::TextureFont* font, FaceEngine::Colour fontColour, FaceEngineGUI::UIComponent* parent) : FaceEngineGUI::UIComponent(x, y, width, height, parent)
    {
        _text = text;
        _font = font;
        _fontColour = fontColour;

        if (_font != nullptr)
        {
            _textScale = Bounds.Height / _font->MeasureString("M").Y;
        }
    }

    Label::Label(int width, int height, std::string text, FaceEngine::TextureFont* font, FaceEngine::Colour fontColour, FaceEngineGUI::UIComponent* parent) : FaceEngineGUI::UIComponent(0, 0, width, height, parent)
    {
        _text = text;
        _font = font;
        _fontColour = fontColour;

        if (_font != nullptr)
        {
            _textScale = Bounds.Height / _font->MeasureString("M").Y;
        }
    }

    Label::~Label()
    {

    }

    void Label::SetFont(FaceEngine::TextureFont* font)
    {
        _font = font;
        _textScale = Bounds.Height / _font->MeasureString("M").Y;
    }

    void Label::SetText(std::string text)
    {
        _text = text;
    }

    void Label::Draw(FaceEngine::SpriteBatcher* renderer)
    {
        if (!enabled)
        {
            return;
        }
        
        if (_text.empty())
        {
            return;
        }
        
        renderer->DrawString(_font, _text, Bounds.GetPosition(), _fontColour, _textScale);
    }
}