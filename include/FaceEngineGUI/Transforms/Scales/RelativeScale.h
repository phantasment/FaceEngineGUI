#ifndef FACEENGINEGUI_TRANSFORMS_SCALES_RELATIVESCALE_H
#define FACEENGINEGUI_TRANSFORMS_SCALES_RELATIVESCALE_H

#include "FaceEngineGUI/Transforms/UIScale.h"
#include "FaceEngine/Math/Rectangle.h"

namespace FaceEngineGUI::Transforms::Scales
{
    class RelativeScale : public FaceEngineGUI::Transforms::UIScale
    {
        public:
            float ScaleFactor;

            RelativeScale();
            RelativeScale(const float translationFactor);
            ~RelativeScale() override;

            int ScaleWidth(const FaceEngine::Math::Rectangle& compBounds, const FaceEngine::Math::Rectangle& parentBounds) const override;
            int ScaleHeight(const FaceEngine::Math::Rectangle& compBounds, const FaceEngine::Math::Rectangle& parentBounds) const override;
            
            void Print() const override;
    };
}

#endif