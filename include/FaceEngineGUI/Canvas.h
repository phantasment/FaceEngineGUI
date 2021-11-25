#ifndef FACEENGINEGUI_CANVAS_H
#define FACEENGINEGUI_CANVAS_H

#include "FaceEngine/Math/Rectangle.h"

namespace FaceEngineGUI
{
    class Canvas
    {
    private:
        Canvas();
        
    public:
        static FaceEngine::Math::Rectangle Bounds;
        static void Initialise(const int& width, const int& height);
    };
}

#endif