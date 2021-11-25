#include "FaceEngineGUI/Transforms/Translations/CentreTranslation.h"
#include <iostream>

namespace FaceEngineGUI::Transforms::Translations
{
    CentreTranslation::CentreTranslation()
    {
        MeasureFrom = MeasurementPoint::CENTRE;
    }

    CentreTranslation::CentreTranslation(const MeasurementPoint& referencePoint)
    {
        MeasureFrom = referencePoint;
    }

    int CentreTranslation::TranslateX(const FaceEngine::Math::Rectangle& compBounds, const FaceEngine::Math::Rectangle& parentBounds) const
    {
        switch (MeasureFrom)
        {
            case MeasurementPoint::CENTRE:
                return parentBounds.X + (parentBounds.Width / 2) - (compBounds.Width / 2);
            case MeasurementPoint::MIN:
                return parentBounds.X + (parentBounds.Width / 2);
            default:
                return parentBounds.X + (parentBounds.Width / 2) - compBounds.Width;
        }
    }

    int CentreTranslation::TranslateY(const FaceEngine::Math::Rectangle& compBounds, const FaceEngine::Math::Rectangle& parentBounds) const
    {
        switch (MeasureFrom)
        {
            case MeasurementPoint::CENTRE:
                return parentBounds.Y + (parentBounds.Height / 2) - (compBounds.Height / 2);
            case MeasurementPoint::MIN:
                return parentBounds.Y + (parentBounds.Height / 2);
            default:
                return parentBounds.Y + (parentBounds.Height / 2) - compBounds.Height;
        }
    }

    void CentreTranslation::Print() const
    {
        std::cout << "CentreTranslation:[MeasureFrom: " << MeasureFrom << "]" << std::endl;
    }
}
