#include "FaceEngineGUI/Transforms/Translations/RelativeTranslation.h"

namespace FaceEngineGUI::Translations
{
    RelativeTranslation::RelativeTranslation(float translationFactor)
    {   
        TranslationFactor = translationFactor;
        MeasureFrom = MeasurementPoint::MIN;
    }

    RelativeTranslation::RelativeTranslation(float translationFactor, const MeasurementPoint& referencePoint)
    {   
        TranslationFactor = translationFactor;
        MeasureFrom = referencePoint;
    }

    int RelativeTranslation::TranslateX(const FaceEngine::Rectanglef& compBounds, const FaceEngine::Rectanglef& parentBounds) const
    {
        switch (MeasureFrom)
        {
            case MeasurementPoint::MIN:
                return parentBounds.X + (parentBounds.Width * TranslationFactor);
            case MeasurementPoint::CENTRE:
                return parentBounds.X + (parentBounds.Width * TranslationFactor) - (compBounds.Width / 2);
            default:
                return parentBounds.X + (parentBounds.Width * TranslationFactor) - compBounds.Width;
        }
    }

    int RelativeTranslation::TranslateY(const FaceEngine::Rectanglef& compBounds, const FaceEngine::Rectanglef& parentBounds) const
    {
        switch (MeasureFrom)
        {
            case MeasurementPoint::MIN:
                return parentBounds.Y + (parentBounds.Height * TranslationFactor);
            case MeasurementPoint::CENTRE:
                return parentBounds.Y + (parentBounds.Height * TranslationFactor) - (compBounds.Height / 2);
            default:
                return parentBounds.Y + (parentBounds.Height * TranslationFactor) - compBounds.Height;
        }
    }

    void RelativeTranslation::Print() const
    {
        std::cout << "RelativeTranslation:[MeasureFrom: " << MeasureFrom << "]" << std::endl;
    }
}