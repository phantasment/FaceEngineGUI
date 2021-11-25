#ifndef FACEENGINEGUI_TEXTUREDESIGN_FILLS_LINEARGRADIENTFILL_H
#define FACEENGINEGUI_TEXTUREDESIGN_FILLS_LINEARGRADIENTFILL_H

#include "FaceEngine/Graphics/Colour.h"
#include "FaceEngineGUI/TextureDesign/Fill.h"

namespace FaceEngineGUI::TextureDesign::Fills
{
    class LinearGradientFill : public FaceEngineGUI::TextureDesign::Fill
    {
    private:
        FaceEngine::Graphics::Colour _firstColour;
        FaceEngine::Graphics::Colour _secondColour;
    
    public:
        LinearGradientFill();
        LinearGradientFill(const FaceEngine::Graphics::Colour& firstColour, const FaceEngine::Graphics::Colour& secondColour);
        ~LinearGradientFill() override = default;

        FaceEngine::Graphics::Colour GetPixelData(int x, int y, int width, int height) const override;
    };
}

#endif