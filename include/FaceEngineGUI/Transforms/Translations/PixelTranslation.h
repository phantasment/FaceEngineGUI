#ifndef FACEENGINEGUI_TRANSFORMS_TRANSLATIONS_PIXELTRANSLATION_H
#define FACEENGINEGUI_TRANSFORMS_TRANSLATIONS_PIXELTRANSLATION_H

#include "FaceEngineGUI/Transforms/UITranslation.h"
#include "FaceEngine/Math/Rectangle.h"

namespace FaceEngineGUI::Translations
{
    class PixelTranslation : public FaceEngineGUI::UITranslation
    {
        public:
            int TranslationFactor;

            PixelTranslation();
            PixelTranslation(const int& translationFactor);
            PixelTranslation(const int& translationFactor, const MeasurementPoint& referencePoint);

            ~PixelTranslation() override { }

            int TranslateX(const FaceEngine::Rectanglef& compBounds, const FaceEngine::Rectanglef& parentBounds) const override;
            int TranslateY(const FaceEngine::Rectanglef& compBounds, const FaceEngine::Rectanglef& parentBounds) const override;

            void Print() const override;
    };
}

#endif