#include "FaceEngineGUI/Canvas.h"

namespace FaceEngineGUI
{
    FaceEngine::Math::Rectangle Canvas::Bounds;

    void Canvas::Initialise(const int& width, const int& height)
    {
        Canvas::Bounds = FaceEngine::Math::Rectangle(0, 0, width, height);
    }
}
