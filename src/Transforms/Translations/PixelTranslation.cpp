#include "FaceEngineGUI/Transforms/Translations/PixelTranslation.h"

namespace FaceEngineGUI::Translations
{
    PixelTranslation::PixelTranslation()
    {
        TranslationFactor = 0;
        MeasureFrom = MeasurementPoint::MIN;
    }

    PixelTranslation::PixelTranslation(const int& translationFactor)
    {
        TranslationFactor = translationFactor;
        MeasureFrom = MeasurementPoint::MIN;
    }

    PixelTranslation::PixelTranslation(const int& translationFactor, const MeasurementPoint& referencePoint)
    {
        TranslationFactor = translationFactor;
        MeasureFrom = referencePoint;
    }

    int PixelTranslation::TranslateX(const FaceEngine::Rectanglef& compBounds, const FaceEngine::Rectanglef& parentBounds) const
    {
        switch (MeasureFrom)
        {
            case MeasurementPoint::MIN:
                return parentBounds.X + TranslationFactor;
            case MeasurementPoint::CENTRE:
                return parentBounds.X - (compBounds.Width / 2) + TranslationFactor;
            default:
                return parentBounds.X + compBounds.Width + TranslationFactor;
        }
    }

    int PixelTranslation::TranslateY(const FaceEngine::Rectanglef& compBounds, const FaceEngine::Rectanglef& parentBounds) const
    {
        switch (MeasureFrom)
        {
            case MeasurementPoint::MIN:
                return parentBounds.Y + TranslationFactor;
            case MeasurementPoint::CENTRE:
                return parentBounds.Y - (compBounds.Height / 2) + TranslationFactor;
            default:
                return parentBounds.Y - compBounds.Height + TranslationFactor;
        }
    }

    void PixelTranslation::Print() const
    {
        std::cout << "PixelTranslation:[MeasureFrom: " << MeasureFrom << "]" << std::endl;
    }
}
