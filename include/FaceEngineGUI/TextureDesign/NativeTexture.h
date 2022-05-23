#ifndef FACEENGINEGUI_TEXTUREDESIGN_NATIVETEXTURE_H
#define FACEENGINEGUI_TEXTUREDESIGN_NATIVETEXTURE_H

#include "FaceEngineGUI/TextureDesign/Fill.h"
#include "FaceEngineGUI/TextureDesign/Border.h"
#include "FaceEngineGUI/TextureDesign/CornerEffect.h"
#include "FaceEngineGUI/TextureDesign/VisualEffect.h"
#include "FaceEngine/Texture2D.h"

namespace FaceEngineGUI
{
    class NativeTexture
    {
    public:
        int Width;
        int Height;

        FaceEngineGUI::Fill* Fill;
        FaceEngineGUI::Border* Border;
        FaceEngineGUI::CornerEffect* CornerEffect;
        FaceEngineGUI::VisualEffect* VisualEffect; // TODO: allow for more than one visual effect, maybe corner effects too.

        NativeTexture();
        ~NativeTexture();

        FaceEngine::Texture2D* Rasterise();
    };
}

#endif