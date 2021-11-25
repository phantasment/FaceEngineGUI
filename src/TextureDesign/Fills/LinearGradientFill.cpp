#include "FaceEngineGUI/TextureDesign/Fills/LinearGradientFill.h"

namespace FaceEngineGUI::TextureDesign::Fills
{
    LinearGradientFill::LinearGradientFill()
    {
        _firstColour = FaceEngine::Graphics::Colour::White;
        _secondColour = FaceEngine::Graphics::Colour::Black;
    }

    LinearGradientFill::LinearGradientFill(const FaceEngine::Graphics::Colour& firstColour, const FaceEngine::Graphics::Colour& secondColour)
    {
        _firstColour = firstColour;
        _secondColour = secondColour;
    }

    FaceEngine::Graphics::Colour LinearGradientFill::GetPixelData(int x, int y, int width, int height) const
    {
        return FaceEngine::Graphics::Colour::Lerp(_firstColour, _secondColour, (float)y / (float)height);
    }
}
