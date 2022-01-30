#ifndef FACEENGINEGUI_COMPONENTS_CONTAINER_H
#define FACEENGINEGUI_COMPONENTS_CONTAINER_H

#include "FaceEngineGUI/UIComponent.h"

namespace FaceEngineGUI::Components
{
    class Container : public FaceEngineGUI::UIComponent
    {
    public:
        void Update(FaceEngine::GameUpdate* gameUpdate) override;
        void Draw(FaceEngine::Graphics::SpriteRenderer* renderer) override;
    };
}

#endif