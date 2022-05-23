#ifndef FACEENGINEGUI_TEXTUREDESIGN_FILLS_LINEARGRADIENTFILL_H
#define FACEENGINEGUI_TEXTUREDESIGN_FILLS_LINEARGRADIENTFILL_H

#include "FaceEngine/Colour.h"
#include "FaceEngineGUI/TextureDesign/Fill.h"

namespace FaceEngineGUI::Fills
{
    class LinearGradientFill : public FaceEngineGUI::Fill
    {
    private:
        FaceEngine::Colour _firstColour;
        FaceEngine::Colour _secondColour;
    
    public:
        LinearGradientFill();
        LinearGradientFill(const FaceEngine::Colour& firstColour, const FaceEngine::Colour& secondColour);
        ~LinearGradientFill() override = default;

        FaceEngine::Colour GetPixelData(int x, int y, int width, int height) const override;
    };
}

#endif