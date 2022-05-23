#ifndef FACEENGINEGUI_TRANSFORMS_UISCALE_H
#define FACEENGINEGUI_TRANSFORMS_UISCALE_H

#include "FaceEngine/Math/Rectangle.h"
#include "FaceEngineGUI/Transforms/MeasurementPoint.h"

namespace FaceEngineGUI
{
    class UIScale
    {
        public:
            virtual ~UIScale() { }

            virtual int ScaleWidth(const FaceEngine::Rectanglef& compBounds, const FaceEngine::Rectanglef& parentBounds) const = 0;
            virtual int ScaleHeight(const FaceEngine::Rectanglef& compBounds, const FaceEngine::Rectanglef& parentBounds) const = 0;

            virtual void Print() const = 0;
    };
}

#endif