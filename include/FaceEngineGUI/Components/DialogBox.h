#ifndef FACEENGINEGUI_COMPONENTS_DIALOGBOX_H
#define FACEENGINEGUI_COMPONENTS_DIALOGBOX_H

#include "FaceEngineGUI/UIComponent.h"
#include "FaceEngineGUI/Components/Sprite.h"
#include "FaceEngineGUI/Components/Label.h"
#include "FaceEngineGUI/Components/Button.h"
#include <string>

#define TITLE_BAR_HEIGHT 30

namespace FaceEngineGUI::Components
{
    class DialogBox : public FaceEngineGUI::UIComponent
    {
    private:
        // GUI Sections
        FaceEngineGUI::Components::Sprite* _titleBar;
        FaceEngineGUI::Components::Sprite* _body;

        // GUI Components
        FaceEngineGUI::Components::Label* _title;
        FaceEngineGUI::Components::Button* _minimiseButton;
        FaceEngineGUI::Components::Button* _maximiseButton;
        FaceEngineGUI::Components::Button* _closeButton;

    public:
        DialogBox(int x, int y, int width, int height, FaceEngineGUI::UIComponent* parent = nullptr);
        ~DialogBox();

        void Update(FaceEngine::GameUpdate* gameUpdate) override;
        void Draw(FaceEngine::Graphics::SpriteRenderer* renderer) override;

        void SetTitleBarTexture(FaceEngine::Graphics::Texture2D* texture);
        void SetBodyTexture(FaceEngine::Graphics::Texture2D* texture);
        void SetCloseButtonTexture(FaceEngine::Graphics::Texture2D* texture);
        
        void SetTitleFont(FaceEngine::Graphics::TextureFont* textureFont);
        void SetTitle(std::string title);

        inline FaceEngineGUI::Components::Sprite* GetBody()
        {
            return _body;
        }

        // Adjustment Methods
    };
}

#endif