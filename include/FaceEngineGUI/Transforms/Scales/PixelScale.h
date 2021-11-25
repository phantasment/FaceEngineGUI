#ifndef FACEENGINEGUI_TRANSFORMS_SCALES_PIXELSCALE_H
#define FACEENGINEGUI_TRANSFORMS_SCALES_PIXELSCALE_H

#include "FaceEngineGUI/Transforms/UIScale.h"
#include "FaceEngine/Math/Rectangle.h"

namespace FaceEngineGUI::Transforms::Scales
{
    class PixelScale : public FaceEngineGUI::Transforms::UIScale
    {
        public:
            int ScaleFactor;

            PixelScale();
            PixelScale(const int scaleFactor);
            ~PixelScale() override;

            int ScaleWidth(const FaceEngine::Math::Rectangle& compBounds, const FaceEngine::Math::Rectangle& parentBounds) const override;
            int ScaleHeight(const FaceEngine::Math::Rectangle& compBounds, const FaceEngine::Math::Rectangle& parentBounds) const override;

            void Print() const override;
    };
}

#endif