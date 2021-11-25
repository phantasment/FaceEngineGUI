#include "FaceEngineGUI/Transforms/Scales/PixelScale.h"
#include <iostream>

namespace FaceEngineGUI::Transforms::Scales
{
    PixelScale::PixelScale()
    {
        ScaleFactor = 0;
    }

    PixelScale::PixelScale(const int scaleFactor)
    {
        ScaleFactor = scaleFactor;
    }

    PixelScale::~PixelScale()
    {
        
    }

    int PixelScale::ScaleWidth(const FaceEngine::Math::Rectangle& compBounds, const FaceEngine::Math::Rectangle& parentBounds) const
    {
        return ScaleFactor;
    }

    int PixelScale::ScaleHeight(const FaceEngine::Math::Rectangle& compBounds, const FaceEngine::Math::Rectangle& parentBounds) const
    {
        return ScaleFactor;
    }

    void PixelScale::Print() const
    {
        std::cout << "PixelScale:[Factor: " << ScaleFactor << "]" << std::endl;
    }
}
