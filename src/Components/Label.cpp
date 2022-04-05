#include "FaceEngineGUI/Components/Label.h"
#include <iostream>

namespace FaceEngineGUI::Components
{
    Label::Label(int x, int y, int width, int height, std::string text, FaceEngine::Graphics::TextureFont* font, FaceEngine::Graphics::Colour fontColour, FaceEngineGUI::UIComponent* parent) : FaceEngineGUI::UIComponent(x, y, width, height, parent)
    {
        _text = text;
        _font = font;
        _fontColour = fontColour;

        if (_font != nullptr)
        {
            _textScale = Bounds.Height / ((_font->GetAscender() + abs(_font->GetDescender())) / 64.0);
        }
    }

    Label::Label(int width, int height, std::string text, FaceEngine::Graphics::TextureFont* font, FaceEngine::Graphics::Colour fontColour, FaceEngineGUI::UIComponent* parent) : FaceEngineGUI::UIComponent(0, 0, width, height, parent)
    {
        _text = text;
        _font = font;
        _fontColour = fontColour;

        if (_font != nullptr)
        {
            _textScale = Bounds.Height / ((_font->GetAscender() + abs(_font->GetDescender())) / 64.0);
        }
    }

    Label::~Label()
    {

    }

    void Label::SetFont(FaceEngine::Graphics::TextureFont* font)
    {
        _font = font;
        _textScale = Bounds.Height / ((_font->GetAscender() + abs(_font->GetDescender())) / 64.0);
    }

    void Label::SetText(std::string text)
    {
        _text = text;
    }

    void Label::Draw(FaceEngine::Graphics::SpriteRenderer* renderer)
    {
        if (!enabled)
        {
            return;
        }
        
        if (_text.empty())
        {
            return;
        }
        
        renderer->Draw(_font, _text, Bounds.GetPosition(), _fontColour, _textScale);
    }
}