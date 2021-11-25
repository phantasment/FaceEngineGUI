#ifndef FACEENGINEGUI_TRANSFORMS_TRANSLATIONS_CENTRETRANSLATION_H
#define FACEENGINEGUI_TRANSFORMS_TRANSLATIONS_CENTRETRANSLATION_H

#include "FaceEngineGUI/Transforms/UITranslation.h"

namespace FaceEngineGUI::Transforms::Translations
{
    class CentreTranslation : public FaceEngineGUI::Transforms::UITranslation
    {
    public:
        CentreTranslation();
        CentreTranslation(const MeasurementPoint& referencePoint);
        ~CentreTranslation() override { }

        int TranslateX(const FaceEngine::Math::Rectangle& compBounds, const FaceEngine::Math::Rectangle& parentBounds) const override;
        int TranslateY(const FaceEngine::Math::Rectangle& compBounds, const FaceEngine::Math::Rectangle& parentBounds) const override;

        void Print() const override;
    };
}

#endif