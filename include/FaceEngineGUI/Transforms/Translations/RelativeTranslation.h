#ifndef FACEENGINEGUI_TRANSFORMS_TRANSLATIONS_RELATIVETRANSLATION_H
#define FACEENGINEGUI_TRANSFORMS_TRANSLATIONS_RELATIVETRANSLATION_H

#include "FaceEngineGUI/Transforms/UITranslation.h"

namespace FaceEngineGUI::Translations
{
    class RelativeTranslation : public FaceEngineGUI::UITranslation
    {
    public:
        float TranslationFactor;

        RelativeTranslation(float translationFactor);
        RelativeTranslation(float translationFactory, const MeasurementPoint& referencePoint);
        ~RelativeTranslation() override { }

        int TranslateX(const FaceEngine::Rectanglef& compBounds, const FaceEngine::Rectanglef& parentBounds) const override;
        int TranslateY(const FaceEngine::Rectanglef& compBounds, const FaceEngine::Rectanglef& parentBounds) const override;

        void Print() const override;
    };
}

#endif