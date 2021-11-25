#include "FaceEngineGUI/TextureDesign/Fills/SolidFill.h"

namespace FaceEngineGUI::TextureDesign::Fills
{
    SolidFill::SolidFill()
    {
        
    }

    SolidFill::SolidFill(FaceEngine::Graphics::Colour fillColour)
    {
        _fillColour = fillColour;
    }

    FaceEngine::Graphics::Colour SolidFill::GetPixelData(int x, int y, int width, int height) const
    {
        return _fillColour;
    }
}
