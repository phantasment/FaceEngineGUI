#ifndef FACEENGINEGUI_COMPONENTS_DIALOGBOX_H
#define FACEENGINEGUI_COMPONENTS_DIALOGBOX_H

#include "FaceEngineGUI/UIComponent.h"
#include "FaceEngineGUI/Components/Sprite.h"
#include "FaceEngineGUI/Components/Label.h"
#include "FaceEngineGUI/Components/Button.h"
#include <string>

#define TITLE_BAR_HEIGHT 25

namespace FaceEngineGUI
{
    class DialogBox : public FaceEngineGUI::UIComponent
    {
    private:
        // GUI Sections
        FaceEngineGUI::Sprite* _titleBar;
        FaceEngineGUI::Sprite* _body;

        // GUI Components
        FaceEngineGUI::Label* _title;
        FaceEngineGUI::Button* _minimiseButton;
        FaceEngineGUI::Button* _maximiseButton;
        FaceEngineGUI::Button* _closeButton;

    public:
        DialogBox(int x, int y, int width, int height, FaceEngineGUI::UIComponent* parent = nullptr);
        ~DialogBox();

        void Update(FaceEngine::GameUpdate* gameUpdate) override;
        void Draw(FaceEngine::SpriteBatcher* renderer) override;

        void SetTitleBarTexture(FaceEngine::Texture2D* texture);
        void SetBodyTexture(FaceEngine::Texture2D* texture);
        void SetCloseButtonTexture(FaceEngine::Texture2D* texture);
        
        void SetTitleFont(FaceEngine::TextureFont* textureFont);
        void SetTitle(std::string title);

        inline FaceEngineGUI::Sprite* GetBody()
        {
            return _body;
        }

        // Adjustment Methods
    };
}

#endif