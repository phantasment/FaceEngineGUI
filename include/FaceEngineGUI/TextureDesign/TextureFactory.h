#ifndef FACEENGINEGUI_TEXTUREDESIGN_TEXTUREFACTORY_H
#define FACEENGINEGUI_TEXTUREDESIGN_TEXTUREFACTORY_H

#include "FaceEngineGUI/TextureDesign/NativeTexture.h"
#include "FaceEngineGUI/TextureDesign/ColourScheme.h"
#include "FaceEngine/Colour.h"

namespace FaceEngineGUI
{
    class TextureFactory
    {
    private:
        TextureFactory();
    
    public:
        static FaceEngineGUI::NativeTexture CreateSolidFill(const int width, const int height, const FaceEngineGUI::ColourScheme& colourScheme);
        static FaceEngineGUI::NativeTexture CreateSolidFill(const int width, const int height, const FaceEngine::Colour& fillColour);
        static FaceEngineGUI::NativeTexture CreateLinearGradientFill(const int width, const int height, const FaceEngine::Colour& startColour, const FaceEngine::Colour& endColour);
    };
}

#endif