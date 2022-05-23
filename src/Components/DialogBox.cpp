#include "FaceEngineGUI/Components/DialogBox.h"

namespace FaceEngineGUI
{
    DialogBox::DialogBox(int x, int y, int width, int height, FaceEngineGUI::UIComponent* parent) : UIComponent(x, y, width, height, parent)
    {
        _titleBar = new Sprite(0, 0, width, TITLE_BAR_HEIGHT, nullptr, this);
        _body = new Sprite(0, TITLE_BAR_HEIGHT, width, height - TITLE_BAR_HEIGHT, nullptr, this);
        _title = new Label(10, 7, 100, 9, "", nullptr, FaceEngine::Colour::White, this);
        _minimiseButton = nullptr;
        _maximiseButton = nullptr;
        _closeButton = nullptr;
    }

    DialogBox::~DialogBox()
    {
        delete _titleBar;
        delete _body;
        delete _title;
        delete _minimiseButton;
        delete _maximiseButton;
        delete _closeButton;
    }

    void DialogBox::Update(FaceEngine::GameUpdate* gameUpdate)
    {
        if (!enabled)
        {
            return;
        }
        
        //_closeButton->Update(gameUpdate);
    }

    void DialogBox::Draw(FaceEngine::SpriteBatcher* renderer)
    {
        if (!enabled)
        {
            return;
        }
        
        _titleBar->Draw(renderer);
        _body->Draw(renderer);
        _title->Draw(renderer);
        //_closeButton->Draw(renderer);
    }

    void DialogBox::SetTitleBarTexture(FaceEngine::Texture2D* texture)
    {
        _titleBar->Texture = texture;
    }

    void DialogBox::SetBodyTexture(FaceEngine::Texture2D* texture)
    {
        _body->Texture = texture;
    }

    void DialogBox::SetCloseButtonTexture(FaceEngine::Texture2D* texture)
    {
        _closeButton->Texture = texture;
    }

    void DialogBox::SetTitleFont(FaceEngine::TextureFont* font)
    {
        _title->SetFont(font);
    }

    void DialogBox::SetTitle(std::string title)
    {
        _title->SetText(title);
    }
}