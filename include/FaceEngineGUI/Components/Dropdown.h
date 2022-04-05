#ifndef FACEENGINEGUI_COMPONENTS_DROPDOWN_H
#define FACEENGINEGUI_COMPONENTS_DROPDOWN_H

#include "FaceEngineGUI/UIComponent.h"
#include "FaceEngine/Math/Rectangle.h"
#include "FaceEngine/Graphics/Texture2D.h"
#include "FaceEngineGUI/Util/UIButtonState.h"
#include "FaceEngine/Math/Vector2.h"
#include <list>

namespace FaceEngineGUI::Components
{
    class Dropdown : public UIComponent
    {
    private:
        // Unimplemented
        FaceEngine::Math::Vector2 _padding;

        int elementWidth = 0;
        bool _extended = false;
        bool _closedLastCycle = false;

        FaceEngine::Math::Rectangle _extensionBounds;
        FaceEngine::Math::Rectangle _buttonSourceRectangle;
        FaceEngineGUI::Util::UIButtonState buttonState;

        FaceEngine::Graphics::Texture2D* _buttonTextureAtlas;
        FaceEngine::Graphics::Texture2D* _extensionBackgroundTexture;
        std::vector<UIComponent*> _elements;

        void UpdateButtonState(FaceEngine::GameUpdate* gameUpdate);
        void UpdateExtensionState(FaceEngine::GameUpdate* gameUpdate);

    public:
        Dropdown(int x, int y, int width, int height, FaceEngine::Graphics::Texture2D* buttonTextureAtlas, FaceEngine::Graphics::Texture2D* extensionBackgroundTexture, FaceEngineGUI::UIComponent* parent = nullptr);
        ~Dropdown();

        void AddElement(UIComponent* element);

        void Update(FaceEngine::GameUpdate* gameUpdate) override;
        void Draw(FaceEngine::Graphics::SpriteRenderer* renderer) override;
    };
}

#endif