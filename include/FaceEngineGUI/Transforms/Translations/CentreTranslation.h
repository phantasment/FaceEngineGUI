#ifndef FACEENGINEGUI_TRANSFORMS_TRANSLATIONS_CENTRETRANSLATION_H
#define FACEENGINEGUI_TRANSFORMS_TRANSLATIONS_CENTRETRANSLATION_H

#include "FaceEngineGUI/Transforms/UITranslation.h"

namespace FaceEngineGUI::Translations
{
    class CentreTranslation : public FaceEngineGUI::UITranslation
    {
    public:
        CentreTranslation();
        CentreTranslation(const MeasurementPoint& referencePoint);
        ~CentreTranslation() override { }

        int TranslateX(const FaceEngine::Rectanglef& compBounds, const FaceEngine::Rectanglef& parentBounds) const override;
        int TranslateY(const FaceEngine::Rectanglef& compBounds, const FaceEngine::Rectanglef& parentBounds) const override;

        void Print() const override;
    };
}

#endif