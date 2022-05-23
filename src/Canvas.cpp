#include "FaceEngineGUI/Canvas.h"

namespace FaceEngineGUI
{
    FaceEngine::Rectanglef Canvas::Bounds;

    void Canvas::Initialise(const int& width, const int& height)
    {
        Canvas::Bounds = FaceEngine::Rectanglef(0, 0, width, height);
    }
}
