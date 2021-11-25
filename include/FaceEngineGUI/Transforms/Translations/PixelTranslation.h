#ifndef FACEENGINEGUI_TRANSFORMS_TRANSLATIONS_PIXELTRANSLATION_H
#define FACEENGINEGUI_TRANSFORMS_TRANSLATIONS_PIXELTRANSLATION_H

#include "FaceEngineGUI/Transforms/UITranslation.h"
#include "FaceEngine/Math/Rectangle.h"

namespace FaceEngineGUI::Transforms::Translations
{
    class PixelTranslation : public FaceEngineGUI::Transforms::UITranslation
    {
        public:
            int TranslationFactor;

            PixelTranslation();
            PixelTranslation(const int& translationFactor);
            PixelTranslation(const int& translationFactor, const MeasurementPoint& referencePoint);

            ~PixelTranslation() override { }

            int TranslateX(const FaceEngine::Math::Rectangle& compBounds, const FaceEngine::Math::Rectangle& parentBounds) const override;
            int TranslateY(const FaceEngine::Math::Rectangle& compBounds, const FaceEngine::Math::Rectangle& parentBounds) const override;

            void Print() const override;
    };
}

#endif