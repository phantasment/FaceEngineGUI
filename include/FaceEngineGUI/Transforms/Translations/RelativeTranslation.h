#ifndef FACEENGINEGUI_TRANSFORMS_TRANSLATIONS_RELATIVETRANSLATION_H
#define FACEENGINEGUI_TRANSFORMS_TRANSLATIONS_RELATIVETRANSLATION_H

#include "FaceEngineGUI/Transforms/UITranslation.h"

namespace FaceEngineGUI::Transforms::Translations
{
    class RelativeTranslation : public FaceEngineGUI::Transforms::UITranslation
    {
    public:
        float TranslationFactor;

        RelativeTranslation(float translationFactor);
        RelativeTranslation(float translationFactory, const MeasurementPoint& referencePoint);
        ~RelativeTranslation() override { }

        int TranslateX(const FaceEngine::Math::Rectangle& compBounds, const FaceEngine::Math::Rectangle& parentBounds) const override;
        int TranslateY(const FaceEngine::Math::Rectangle& compBounds, const FaceEngine::Math::Rectangle& parentBounds) const override;

        void Print() const override;
    };
}

#endif