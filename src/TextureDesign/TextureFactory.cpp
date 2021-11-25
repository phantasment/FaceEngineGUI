#include "FaceEngineGUI/TextureDesign/TextureFactory.h"
#include "FaceEngineGUI/TextureDesign/Fills/SolidFill.h"
#include "FaceEngineGUI/TextureDesign/Fills/LinearGradientFill.h"

namespace FaceEngineGUI::TextureDesign
{
    NativeTexture TextureFactory::CreateSolidFill(const int width, const int height, const ColourScheme& colourScheme)
    {
        NativeTexture nativeTexture = NativeTexture();

        nativeTexture.Width = width;
        nativeTexture.Height = height;

        FaceEngine::Graphics::Colour fill = colourScheme.GetBackgroundColour();

        nativeTexture.Fill = new Fills::SolidFill(fill);

        return nativeTexture;
    }

    NativeTexture TextureFactory::CreateSolidFill(const int width, const int height, const FaceEngine::Graphics::Colour& fillColour)
    {
        NativeTexture nativeTexture = NativeTexture();

        nativeTexture.Width = width;
        nativeTexture.Height = height;
        nativeTexture.Fill = new Fills::SolidFill(fillColour);

        return nativeTexture;
    }

    NativeTexture TextureFactory::CreateLinearGradientFill(const int width, const int height, const FaceEngine::Graphics::Colour& startColour, const FaceEngine::Graphics::Colour& endColour)
    {
        NativeTexture nativeTexture = NativeTexture();

        nativeTexture.Width = width;
        nativeTexture.Height = height;
        nativeTexture.Fill = new Fills::LinearGradientFill(startColour, endColour);

        return nativeTexture;
    }
}
