#ifndef FACEENGINEGUI_COMPONENTS_LABEL_H
#define FACEENGINEGUI_COMPONENTS_LABEL_H

#include "FaceEngineGUI/UIComponent.h"
#include "FaceEngine/Graphics/TextureFont.h"
#include "FaceEngine/Graphics/Colour.h"
#include <string>

namespace FaceEngineGUI::Components
{
    class Label : public FaceEngineGUI::UIComponent
    {
    private:
        std::string _text;
        FaceEngine::Graphics::TextureFont* _font;
        FaceEngine::Graphics::Colour _fontColour;
        float _textScale;

    public:
        Label(int width, int height, std::string text, FaceEngine::Graphics::TextureFont* font, FaceEngine::Graphics::Colour fontColour, FaceEngineGUI::UIComponent* parent = nullptr);
        Label(int x, int y, int width, int height, std::string text, FaceEngine::Graphics::TextureFont* font, FaceEngine::Graphics::Colour fontColour, FaceEngineGUI::UIComponent* parent = nullptr);
        ~Label();

        void SetFont(FaceEngine::Graphics::TextureFont* font);
        void SetText(std::string text);

        void Draw(FaceEngine::Graphics::SpriteRenderer* renderer) override;
    };
}

#endif