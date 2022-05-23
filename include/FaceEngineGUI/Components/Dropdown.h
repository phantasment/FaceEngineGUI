#ifndef FACEENGINEGUI_COMPONENTS_DROPDOWN_H
#define FACEENGINEGUI_COMPONENTS_DROPDOWN_H

#include "FaceEngineGUI/UIComponent.h"
#include "FaceEngine/Math/Rectangle.h"
#include "FaceEngine/Texture2D.h"
#include "FaceEngineGUI/Util/UIButtonState.h"
#include "FaceEngine/Math/Vector2.h"
#include <list>

namespace FaceEngineGUI
{
    class Dropdown : public UIComponent
    {
    private:
        // Unimplemented
        FaceEngine::Vector2f _padding;

        int elementWidth = 0;
        bool _extended = false;
        bool _closedLastCycle = false;

        FaceEngine::Rectanglef _extensionBounds;
        FaceEngine::Rectanglef _buttonSourceRectangle;
        FaceEngineGUI::Util::UIButtonState buttonState;

        FaceEngine::Texture2D* _buttonTextureAtlas;
        FaceEngine::Texture2D* _extensionBackgroundTexture;
        std::vector<UIComponent*> _elements;

        void UpdateButtonState(FaceEngine::GameUpdate* gameUpdate);
        void UpdateExtensionState(FaceEngine::GameUpdate* gameUpdate);

    public:
        Dropdown(int x, int y, int width, int height, FaceEngine::Texture2D* buttonTextureAtlas, FaceEngine::Texture2D* extensionBackgroundTexture, FaceEngineGUI::UIComponent* parent = nullptr);
        ~Dropdown();

        void AddElement(UIComponent* element);

        void Update(FaceEngine::GameUpdate* gameUpdate) override;
        void Draw(FaceEngine::SpriteBatcher* renderer) override;
    };
}

#endif