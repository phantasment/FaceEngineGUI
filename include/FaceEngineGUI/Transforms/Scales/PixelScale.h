#ifndef FACEENGINEGUI_TRANSFORMS_SCALES_PIXELSCALE_H
#define FACEENGINEGUI_TRANSFORMS_SCALES_PIXELSCALE_H

#include "FaceEngineGUI/Transforms/UIScale.h"
#include "FaceEngine/Math/Rectangle.h"

namespace FaceEngineGUI::Scales
{
    class PixelScale : public FaceEngineGUI::UIScale
    {
        public:
            int ScaleFactor;

            PixelScale();
            PixelScale(const int scaleFactor);
            ~PixelScale() override;

            int ScaleWidth(const FaceEngine::Rectanglef& compBounds, const FaceEngine::Rectanglef& parentBounds) const override;
            int ScaleHeight(const FaceEngine::Rectanglef& compBounds, const FaceEngine::Rectanglef& parentBounds) const override;

            void Print() const override;
    };
}

#endif