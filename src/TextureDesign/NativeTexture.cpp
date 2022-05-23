#include "FaceEngineGUI/TextureDesign/NativeTexture.h"
#include <memory>

namespace FaceEngineGUI
{
    NativeTexture::NativeTexture()
    {
        Width = 0;
        Height = 0;

        Fill = nullptr;
        Border = nullptr;
        CornerEffect = nullptr;
        VisualEffect = nullptr;
    }

    NativeTexture::~NativeTexture() 
    {
        delete Fill;
        delete Border;
        delete CornerEffect;
        delete VisualEffect;
    }

    FaceEngine::Texture2D* NativeTexture::Rasterise() //Fill -> Border + CornerEffect-> VisualEffect
    {
        char* imageData = new char[Width * Height * 4];

        // Populating pixel data from Fill.

        for (int y = 0; y < Height; ++y)
        {
            for (int x = 0; x < Width; ++x)
            {
                int dataIndex = (x + (y * Width) * 4);
                FaceEngine::Colour fillData = Fill->GetPixelData(x, y, Width, Height);

                imageData[dataIndex] = fillData.GetRAsInt();
                imageData[dataIndex + 1] = fillData.GetGAsInt();
                imageData[dataIndex + 2] = fillData.GetBAsInt();
                imageData[dataIndex + 3] = fillData.GetAAsInt();
            }
        }

        return FaceEngine::Texture2D::CreateTexture2D(Width, Height, imageData);
    }
}
