#ifndef FACEENGINEGUI_COMPONENTS_TEXTBOX_H
#define FACEENGINEGUI_COMPONENTS_TEXTBOX_H

#include "FaceEngineGUI/UIComponent.h"
#include "FaceEngine/Graphics/TextureFont.h"
#include "FaceEngineGUI/Util/TypingSession.h"
#include "FaceEngineGUI/Util/UIButtonState.h"

// TODO: padding

namespace FaceEngineGUI::Components
{
    class Textbox : public FaceEngineGUI::UIComponent
    {
    private:
        // Textbox Variables
        FaceEngineGUI::Util::TypingSession _typingSession;
        FaceEngineGUI::Util::UIButtonState _state;
        bool _focussed;

        // Texture Variables
        FaceEngine::Graphics::Texture2D* _caretTexture;
        FaceEngine::Graphics::Texture2D* _backgroundTexture;

        // Boundary Variables
        FaceEngine::Math::Rectangle _sourceBounds;
        FaceEngine::Math::Rectangle _textBounds;
        FaceEngine::Math::Rectangle _caretBounds;

        // Caret Variables
        float _caretBlinkDuration;
        float _timeSinceCaretBlink;
        bool _caretVisible;

        // Text Variables
        FaceEngine::Graphics::TextureFont* _font;
        FaceEngine::Graphics::Colour _fontColour;
        float _textScale;

        // Methods
        void Activate();
        void Deactivate();

        void UpdateText(FaceEngine::GameUpdate* gameUpdate);
        void UpdateTextPosition(FaceEngine::GameUpdate* gameUpdate);
        void UpdateCaretBlink(FaceEngine::GameUpdate* gameUpdate);
        void UpdateCursor(FaceEngine::GameUpdate* gameUpdate);
        void UpdateStatus(FaceEngine::GameUpdate* gameUpdate);

        void SetCaretPosition(const int insertPosition);
        void InsertAtMouse(FaceEngine::GameUpdate* gameUpdate);

        void DrawBackground(FaceEngine::Graphics::SpriteRenderer* renderer);
        void DrawText(FaceEngine::Graphics::SpriteRenderer* renderer);
        void DrawCaret(FaceEngine::Graphics::SpriteRenderer* renderer);

    public:
        Textbox(const int x, const int y, const int width, const int height, FaceEngine::Graphics::Texture2D* texture, FaceEngine::Graphics::Texture2D* typingBarTexture, FaceEngine::Graphics::TextureFont* font, FaceEngine::Graphics::Colour fontColour, FaceEngineGUI::UIComponent* parent = nullptr);
        ~Textbox();

        void Update(FaceEngine::GameUpdate* gameUpdate) override;
        void Draw(FaceEngine::Graphics::SpriteRenderer* renderer) override;
    };
}

#endif