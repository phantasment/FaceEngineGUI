#include "FaceEngineGUI/TextureDesign/Fills/SolidFill.h"

namespace FaceEngineGUI::Fills
{
    SolidFill::SolidFill()
    {
        
    }

    SolidFill::SolidFill(FaceEngine::Colour fillColour)
    {
        _fillColour = fillColour;
    }

    FaceEngine::Colour SolidFill::GetPixelData(int x, int y, int width, int height) const
    {
        return _fillColour;
    }
}
