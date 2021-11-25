#ifndef FACEENGINEGUI_TEXTUREDESIGN_FILL_H
#define FACEENGINEGUI_TEXTUREDESIGN_FILL_H

#include "FaceEngine/Graphics/Colour.h"

namespace FaceEngineGUI::TextureDesign
{
    class Fill
    {
    public:
        virtual ~Fill() = default;
        virtual FaceEngine::Graphics::Colour GetPixelData(int x, int y, int width, int height) const = 0;
    };
}

#endif