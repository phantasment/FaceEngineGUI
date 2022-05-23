#ifndef FACEENGINEGUI_COMPONENTS_LABEL_H
#define FACEENGINEGUI_COMPONENTS_LABEL_H

#include "FaceEngineGUI/UIComponent.h"
#include "FaceEngine/TextureFont.h"
#include "FaceEngine/Colour.h"
#include <string>

namespace FaceEngineGUI
{
    class Label : public FaceEngineGUI::UIComponent
    {
    private:
        std::string _text;
        FaceEngine::TextureFont* _font;
        FaceEngine::Colour _fontColour;
        float _textScale;

    public:
        Label(int width, int height, std::string text, FaceEngine::TextureFont* font, FaceEngine::Colour fontColour, FaceEngineGUI::UIComponent* parent = nullptr);
        Label(int x, int y, int width, int height, std::string text, FaceEngine::TextureFont* font, FaceEngine::Colour fontColour, FaceEngineGUI::UIComponent* parent = nullptr);
        ~Label();

        void SetFont(FaceEngine::TextureFont* font);
        void SetText(std::string text);

        void Draw(FaceEngine::SpriteBatcher* renderer) override;
    };
}

#endif