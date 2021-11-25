#include "FaceEngineGUI/Transforms/Scales/RelativeScale.h"

namespace FaceEngineGUI::Transforms::Scales
{
    RelativeScale::RelativeScale()
    {
        ScaleFactor = 0;
    }

    RelativeScale::RelativeScale(const float scaleFactor)
    {
        ScaleFactor = scaleFactor;
    }

    RelativeScale::~RelativeScale()
    {

    }

    int RelativeScale::ScaleWidth(const FaceEngine::Math::Rectangle& compBounds, const FaceEngine::Math::Rectangle& parentBounds) const
    {
        return parentBounds.Width * ScaleFactor;
    }

    int RelativeScale::ScaleHeight(const FaceEngine::Math::Rectangle& compBounds, const FaceEngine::Math::Rectangle& parentBounds) const
    {
        return parentBounds.Height * ScaleFactor;
    }

    void RelativeScale::Print() const
    {
        std::cout << "RelativeScale:[Factor: " << ScaleFactor << "]" << std::endl;
    }
}