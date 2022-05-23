#include "FaceEngineGUI/Components/Textbox.h"
#include "FaceEngine/SpriteBatcher.h"

namespace FaceEngineGUI::Components
{
    Textbox::Textbox(const int x, const int y, const int width, const int height, FaceEngine::Texture2D* backgroundTexture, FaceEngine::Texture2D* typingBarTexture, FaceEngine::TextureFont* font, FaceEngine::Colour fontColour, FaceEngineGUI::UIComponent* parent) : UIComponent(x, y, width, height, parent)
    {
        // Textbox Variables
        _typingSession = FaceEngine::TypingSession();
        _focussed = false;
        _state = FaceEngineGUI::Util::NEUTRAL;

        // Texture Variables
        _backgroundTexture = backgroundTexture;
        _caretTexture = typingBarTexture;

        // Boundary Variables
        _sourceBounds = FaceEngine::Rectanglef(0, 0, _backgroundTexture->GetWidth(), _backgroundTexture->GetHeight() / 3);

        if (parent == nullptr)
        {
            _textBounds = FaceEngine::Rectanglef(x, y, width, height); // padding implemented here
            _caretBounds = FaceEngine::Rectanglef(x, y, 3, height);
        }
        else
        {
            _textBounds = FaceEngine::Rectanglef(parent->GetBounds().X + x, parent->GetBounds().Y + y, width, height); // padding implemented here
            _caretBounds = FaceEngine::Rectanglef(parent->GetBounds().X + x, parent->GetBounds().Y + y, 3, height);
        }

        // Caret Variables
        _caretBlinkDuration = 0.5;
        _timeSinceCaretBlink = 0;
        _caretVisible = true;

        // Text Variables
        _font = font;
        _fontColour = fontColour;
        _textScale = _textBounds.Height / _font->MeasureString("M").Y;
    }

    Textbox::~Textbox()
    {
        delete _backgroundTexture;
        delete _caretTexture;
        delete _font;
    }

    void Textbox::Update(FaceEngine::GameUpdate* gameUpdate)
    {
        if (!enabled)
        {
            return;
        }
        
        UpdateStatus(gameUpdate);
        UpdateCursor(gameUpdate);

        if (_focussed)
        {
            UpdateText(gameUpdate);
            UpdateCaretBlink(gameUpdate);

            if (gameUpdate->IsMouseReleased(0) && Bounds.Contains(gameUpdate->GetCursorPos()))
            {
                InsertAtMouse(gameUpdate);
            }
        }
    }

    void Textbox::Draw(FaceEngine::SpriteBatcher* renderer)
    {
        if (!enabled)
        {
            return;
        }
        
        DrawBackground(renderer);
        DrawText(renderer);
        DrawCaret(renderer);
    }

    void Textbox::Activate()
    {
        _focussed = true;
        _caretVisible = true;
        _timeSinceCaretBlink = 0;
    }

    void Textbox::Deactivate()
    {
        _focussed = false;
        _caretVisible = false;
    }

    void Textbox::UpdateText(FaceEngine::GameUpdate* gameUpdate)
    {
        int previousCaretPosition = _typingSession.GetInsertPosition();
        
        _typingSession.Update(gameUpdate);

        if (previousCaretPosition != _typingSession.GetInsertPosition())
        {
            SetCaretPosition(_typingSession.GetInsertPosition());
        }
    }

    void Textbox::UpdateTextPosition(FaceEngine::GameUpdate* gameUpdate)
    {
        
    }

    void Textbox::UpdateCaretBlink(FaceEngine::GameUpdate* gameUpdate)
    {
        _timeSinceCaretBlink += gameUpdate->GetDelta();

        if (_timeSinceCaretBlink >= _caretBlinkDuration)
        {
            _caretVisible = !_caretVisible;
            _timeSinceCaretBlink = 0;
        }
    }

    void Textbox::SetCaretPosition(const int insertPosition)
    {
        if (insertPosition < 0 || insertPosition > _typingSession.GetText().length())
        {
            return;
        }

        _caretBounds.X = _textBounds.X + (_font->MeasureString(_typingSession.GetText().substr(0, insertPosition)).X * _textScale);
    }

    void Textbox::InsertAtMouse(FaceEngine::GameUpdate* gameUpdate)
    {
        int relativeDistance = gameUpdate->GetCursorPos().X - _textBounds.X;

        for (int i = 1; i < _typingSession.GetText().length() + 1; ++i)
        {
            if (relativeDistance < _font->MeasureString(_typingSession.GetText().substr(0, i)).X * _textScale)
            {
                _typingSession.SetInsertPosition(i - 1);
                SetCaretPosition(i - 1);
                return;
            }
        }

        _typingSession.SetInsertPosition(_typingSession.GetText().length());
        SetCaretPosition(_typingSession.GetText().length());
    }

    void Textbox::UpdateCursor(FaceEngine::GameUpdate* gameUpdate)
    {
        if (Bounds.Contains(gameUpdate->GetCursorPos()))
        {
            //gameUpdate->SetCursorType(FaceEngine::IBeam);
        }
        else
        {
            //gameUpdate->SetCursorType(FaceEngine::Normal);
        }
    }

    void Textbox::UpdateStatus(FaceEngine::GameUpdate* gameUpdate)
    {
        if (!Bounds.Contains(gameUpdate->GetCursorPos()))
        {
            if (gameUpdate->IsMouseReleased(0) && _focussed)
            {
                Deactivate();
            }

            _state = FaceEngineGUI::Util::NEUTRAL;
            _sourceBounds.Y = 0;
        }
        else if (gameUpdate->IsMouseReleased(0))
        {
            _state = FaceEngineGUI::Util::CLICKED;
            
            if (!_focussed)
            {
                Activate();
            }
        }
        else if (gameUpdate->IsMouseDown(0))
        {
            _state = FaceEngineGUI::Util::PRESSED;
            _sourceBounds.Y = 2 * (_backgroundTexture->GetHeight() / 3);
        }
        else
        {
            _state = FaceEngineGUI::Util::UIButtonState::HOVERED;
            _sourceBounds.Y = _backgroundTexture->GetHeight() / 3;
        }
    }

    void Textbox::DrawBackground(FaceEngine::SpriteBatcher* renderer)
    {
        renderer->Draw(_backgroundTexture, Bounds, _sourceBounds);
    }

    void Textbox::DrawText(FaceEngine::SpriteBatcher* renderer)
    {
        renderer->DrawString(_font, _typingSession.GetText(), _textBounds.GetPosition(), _fontColour, _textScale);
    }

    void Textbox::DrawCaret(FaceEngine::SpriteBatcher* renderer)
    {
        if (_caretVisible)
        {
            renderer->Draw(_caretTexture, _caretBounds);
        }
    }

    void Textbox::SetX(FaceEngineGUI::UITranslation* xTranslation)
    {
        FaceEngineGUI::UIComponent::SetX(xTranslation);

        _textBounds.X = Bounds.X;
    }

    void Textbox::SetY(FaceEngineGUI::UITranslation* yTranslation)
    {
        FaceEngineGUI::UIComponent::SetY(yTranslation);

        _textBounds.Y = Bounds.Y;
        _caretBounds.Y = Bounds.Y;
    }

    void Textbox::SetPadding(int paddingX, int paddingY)
    {
        _textBounds.X = Bounds.X + paddingX;
        _textBounds.Y = Bounds.Y + paddingY;
        _textBounds.Width = Bounds.Width - (2 * paddingX);
        _textBounds.Height = Bounds.Height - (2 * paddingY);

        _textScale = _textBounds.Height / _font->MeasureString("M").Y;
    }

    bool Textbox::IsFocussed() const
    {
        return _focussed;
    }
}