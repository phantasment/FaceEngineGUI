#ifndef FACEENGINEGUI_TEXTUREDESIGN_FILLS_SOLIDFILL_H
#define FACEENGINEGUI_TEXTUREDESIGN_FILLS_SOLIDFILL_H

#include "FaceEngine/Colour.h"
#include "FaceEngineGUI/TextureDesign/Fill.h"

namespace FaceEngineGUI::Fills
{
    class SolidFill : public FaceEngineGUI::Fill
    {
    private:
        FaceEngine::Colour _fillColour;
    
    public:
        SolidFill();
        SolidFill(FaceEngine::Colour fillColour);
        ~SolidFill() override = default;

        FaceEngine::Colour GetPixelData(int x, int y, int width, int height) const override;
    };
}

#endif