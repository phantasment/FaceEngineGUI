#ifndef FACEENGINEGUI_TRANSFORMS_UITRANSLATION_H
#define FACEENGINEGUI_TRANSFORMS_UITRANSLATION_H

#include "FaceEngine/Math/Rectangle.h"
#include "FaceEngineGUI/Transforms/MeasurementPoint.h"
#include <iostream>

namespace FaceEngineGUI
{
    class UITranslation
    {
        public:
            MeasurementPoint MeasureFrom;

            virtual ~UITranslation() { }

            virtual int TranslateX(const FaceEngine::Rectanglef& compBounds, const FaceEngine::Rectanglef& parentBounds) const = 0;
            virtual int TranslateY(const FaceEngine::Rectanglef& compBounds, const FaceEngine::Rectanglef& parentBounds) const = 0;

            virtual void Print() const = 0;
    };
}

#endif