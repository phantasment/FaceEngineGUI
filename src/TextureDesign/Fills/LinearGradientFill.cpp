#include "FaceEngineGUI/TextureDesign/Fills/LinearGradientFill.h"

namespace FaceEngineGUI::Fills
{
    LinearGradientFill::LinearGradientFill()
    {
        _firstColour = FaceEngine::Colour::White;
        _secondColour = FaceEngine::Colour::Black;
    }

    LinearGradientFill::LinearGradientFill(const FaceEngine::Colour& firstColour, const FaceEngine::Colour& secondColour)
    {
        _firstColour = firstColour;
        _secondColour = secondColour;
    }

    FaceEngine::Colour LinearGradientFill::GetPixelData(int x, int y, int width, int height) const
    {
        return FaceEngine::Colour::Lerp(_firstColour, _secondColour, (float)y / (float)height);
    }
}
