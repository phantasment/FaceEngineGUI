#ifndef FACEENGINEGUI_COMPONENTS_TEXTBOX_H
#define FACEENGINEGUI_COMPONENTS_TEXTBOX_H

#include "FaceEngineGUI/UIComponent.h"
#include "FaceEngine/TextureFont.h"
#include "FaceEngine/TypingSession.h"
#include "FaceEngineGUI/Util/UIButtonState.h"

// TODO: padding

namespace FaceEngineGUI::Components
{
    class Textbox : public FaceEngineGUI::UIComponent
    {
    private:
        // Textbox Variables
        FaceEngine::TypingSession _typingSession;
        FaceEngineGUI::Util::UIButtonState _state;
        bool _focussed;
        bool _allowOverflow;

        // Texture Variables
        FaceEngine::Texture2D* _caretTexture;
        FaceEngine::Texture2D* _backgroundTexture;

        // Boundary Variables
        FaceEngine::Rectanglef _sourceBounds;
        FaceEngine::Rectanglef _textBounds;
        FaceEngine::Rectanglef _caretBounds;

        // Caret Variables
        float _caretBlinkDuration;
        float _timeSinceCaretBlink;
        bool _caretVisible;

        // Text Variables
        FaceEngine::TextureFont* _font;
        FaceEngine::Colour _fontColour;
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

        void DrawBackground(FaceEngine::SpriteBatcher* renderer);
        void DrawText(FaceEngine::SpriteBatcher* renderer);
        void DrawCaret(FaceEngine::SpriteBatcher* renderer);

    public:
        Textbox(const int x, const int y, const int width, const int height, FaceEngine::Texture2D* texture, FaceEngine::Texture2D* typingBarTexture, FaceEngine::TextureFont* font, FaceEngine::Colour fontColour, FaceEngineGUI::UIComponent* parent = nullptr);
        ~Textbox();

        void Update(FaceEngine::GameUpdate* gameUpdate) override;
        void Draw(FaceEngine::SpriteBatcher* renderer) override;

        void SetX(FaceEngineGUI::UITranslation* xTranslation) override;
        void SetY(FaceEngineGUI::UITranslation* xTranslation) override;
        void SetPadding(int paddingX, int paddingY);

        bool IsFocussed() const;
    };
}

#endif