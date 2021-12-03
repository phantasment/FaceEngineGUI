#include "FaceEngineGUI/Transforms/Translations/RelativeTranslation.h"

namespace FaceEngineGUI::Transforms::Translations
{
    RelativeTranslation::RelativeTranslation(float translationFactor)
    {   
        TranslationFactor = translationFactor;
    }

    RelativeTranslation::RelativeTranslation(float translationFactor, const MeasurementPoint& referencePoint)
    {   
        TranslationFactor = translationFactor;
        MeasureFrom = referencePoint;
    }

    int RelativeTranslation::TranslateX(const FaceEngine::Math::Rectangle& compBounds, const FaceEngine::Math::Rectangle& parentBounds) const
    {
        switch (MeasureFrom)
        {
            case MeasurementPoint::MIN:
                return parentBounds.Width * TranslationFactor;
            case MeasurementPoint::CENTRE:
                return (parentBounds.Width * TranslationFactor) - (compBounds.Width / 2);
            default:
                return (parentBounds.Width * TranslationFactor) - compBounds.Width;
        }
    }

    int RelativeTranslation::TranslateY(const FaceEngine::Math::Rectangle& compBounds, const FaceEngine::Math::Rectangle& parentBounds) const
    {
        switch (MeasureFrom)
        {
            case MeasurementPoint::MIN:
                return parentBounds.Height * TranslationFactor;
            case MeasurementPoint::CENTRE:
                return (parentBounds.Height * TranslationFactor) - (compBounds.Height / 2);
            default:
                return (parentBounds.Height * TranslationFactor) - compBounds.Height;
        }
    }

    void RelativeTranslation::Print() const
    {
        std::cout << "RelativeTranslation:[MeasureFrom: " << MeasureFrom << "]" << std::endl;
    }
}