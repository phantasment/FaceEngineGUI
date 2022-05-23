#ifndef FACEENGINEGUI_TEXTUREDESIGN_FILL_H
#define FACEENGINEGUI_TEXTUREDESIGN_FILL_H

#include "FaceEngine/Colour.h"

namespace FaceEngineGUI
{
    class Fill
    {
    public:
        virtual ~Fill() = default;
        virtual FaceEngine::Colour GetPixelData(int x, int y, int width, int height) const = 0;
    };
}

#endif