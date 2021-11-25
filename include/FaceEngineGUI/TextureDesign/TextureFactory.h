#ifndef FACEENGINEGUI_TEXTUREDESIGN_TEXTUREFACTORY_H
#define FACEENGINEGUI_TEXTUREDESIGN_TEXTUREFACTORY_H

#include "FaceEngineGUI/TextureDesign/NativeTexture.h"
#include "FaceEngineGUI/TextureDesign/ColourScheme.h"
#include "FaceEngine/Graphics/Colour.h"

namespace FaceEngineGUI::TextureDesign
{
    class TextureFactory
    {
    private:
        TextureFactory();
    
    public:
        static FaceEngineGUI::TextureDesign::NativeTexture CreateSolidFill(const int width, const int height, const FaceEngineGUI::TextureDesign::ColourScheme& colourScheme);
        static FaceEngineGUI::TextureDesign::NativeTexture CreateSolidFill(const int width, const int height, const FaceEngine::Graphics::Colour& fillColour);
        static FaceEngineGUI::TextureDesign::NativeTexture CreateLinearGradientFill(const int width, const int height, const FaceEngine::Graphics::Colour& startColour, const FaceEngine::Graphics::Colour& endColour);
    };
}

#endif