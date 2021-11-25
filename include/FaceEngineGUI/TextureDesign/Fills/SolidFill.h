#ifndef FACEENGINEGUI_TEXTUREDESIGN_FILLS_SOLIDFILL_H
#define FACEENGINEGUI_TEXTUREDESIGN_FILLS_SOLIDFILL_H

#include "FaceEngine/Graphics/Colour.h"
#include "FaceEngineGUI/TextureDesign/Fill.h"

namespace FaceEngineGUI::TextureDesign::Fills
{
    class SolidFill : public FaceEngineGUI::TextureDesign::Fill
    {
    private:
        FaceEngine::Graphics::Colour _fillColour;
    
    public:
        SolidFill();
        SolidFill(FaceEngine::Graphics::Colour fillColour);
        ~SolidFill() override = default;

        FaceEngine::Graphics::Colour GetPixelData(int x, int y, int width, int height) const override;
    };
}

#endif