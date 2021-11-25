#ifndef FACEENGINEGUI_TEXTUREDESIGN_NATIVETEXTURE_H
#define FACEENGINEGUI_TEXTUREDESIGN_NATIVETEXTURE_H

#include "FaceEngineGUI/TextureDesign/Fill.h"
#include "FaceEngineGUI/TextureDesign/Border.h"
#include "FaceEngineGUI/TextureDesign/CornerEffect.h"
#include "FaceEngineGUI/TextureDesign/VisualEffect.h"
#include "FaceEngine/Graphics/Texture2D.h"
#include <memory>

namespace FaceEngineGUI::TextureDesign
{
    class NativeTexture
    {
    public:
        int Width;
        int Height;

        FaceEngineGUI::TextureDesign::Fill* Fill;
        FaceEngineGUI::TextureDesign::Border* Border;
        FaceEngineGUI::TextureDesign::CornerEffect* CornerEffect;
        FaceEngineGUI::TextureDesign::VisualEffect* VisualEffect; // TODO: allow for more than one visual effect, maybe corner effects too.

        NativeTexture();
        ~NativeTexture();

        std::shared_ptr<FaceEngine::Graphics::Texture2D> Rasterise();
    };
}

#endif