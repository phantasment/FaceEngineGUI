#ifndef FACEENGINEGUI_TRANSFORMS_SCALES_RELATIVESCALE_H
#define FACEENGINEGUI_TRANSFORMS_SCALES_RELATIVESCALE_H

#include "FaceEngineGUI/Transforms/UIScale.h"
#include "FaceEngine/Math/Rectangle.h"

namespace FaceEngineGUI::Scales
{
    class RelativeScale : public FaceEngineGUI::UIScale
    {
        public:
            float ScaleFactor;

            RelativeScale();
            RelativeScale(const float translationFactor);
            ~RelativeScale() override;

            int ScaleWidth(const FaceEngine::Rectanglef& compBounds, const FaceEngine::Rectanglef& parentBounds) const override;
            int ScaleHeight(const FaceEngine::Rectanglef& compBounds, const FaceEngine::Rectanglef& parentBounds) const override;
            
            void Print() const override;
    };
}

#endif