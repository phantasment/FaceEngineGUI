#include "FaceEngineGUI/TransformManager.h"

namespace FaceEngineGUI
{
    TransformManager::TransformManager(FaceEngineGUI::Transforms::UITranslation* xTranslation, FaceEngineGUI::Transforms::UITranslation* yTranslation, FaceEngineGUI::Transforms::UIScale* widthScale, FaceEngineGUI::Transforms::UIScale* heightScale)
    {
        XTranslation = xTranslation;
        MinXTranslation = nullptr;
        MaxXTranslation = nullptr;

        YTranslation = yTranslation;
        MinYTranslation = nullptr;
        MaxYTranslation = nullptr;

        WidthScale = widthScale;
        MinWidthScale = nullptr;
        MaxWidthScale = nullptr;

        HeightScale = heightScale;
        MinHeightScale = nullptr;
        MaxHeightScale = nullptr;
    }

    TransformManager::~TransformManager()
    {
        delete XTranslation;
        delete MinXTranslation;
        delete MaxXTranslation;
        delete YTranslation;
        delete MinYTranslation;
        delete MaxYTranslation;
        delete WidthScale;
        delete MinWidthScale;
        delete MaxWidthScale;
        delete HeightScale;
        delete MinHeightScale;
        delete MaxHeightScale;
    }

    int TransformManager::GetX(const FaceEngine::Math::Rectangle& compBounds, const FaceEngine::Math::Rectangle& parentBounds) const
    {
        int value = XTranslation->TranslateX(compBounds, parentBounds);

        if (MinXTranslation != nullptr)
        {
            int min = MinXTranslation->TranslateX(compBounds, parentBounds);

            if (value <= min)
            {
                return min;
            }
        }

        if (MaxXTranslation != nullptr)
        {
            int max = MaxXTranslation->TranslateX(compBounds, parentBounds);

            if (value >= max)
            {
                return max;
            }
        }

        return value;
    }

    int TransformManager::GetY(const FaceEngine::Math::Rectangle& compBounds, const FaceEngine::Math::Rectangle& parentBounds) const
    {
        int value = YTranslation->TranslateY(compBounds, parentBounds);

        if (MinYTranslation != nullptr)
        {
            int min = MinYTranslation->TranslateY(compBounds, parentBounds);

            if (value < min)
            {
                return min;
            }
        }

        if (MaxYTranslation != nullptr)
        {
            int max = MaxYTranslation->TranslateY(compBounds, parentBounds);

            if (value > max)
            {
                return max;
            }
        }

        return value;
    }

    int TransformManager::GetWidth(const FaceEngine::Math::Rectangle& compBounds, const FaceEngine::Math::Rectangle& parentBounds) const
    {
        int value = WidthScale->ScaleWidth(compBounds, parentBounds);

        if (MinWidthScale != nullptr)
        {
            int min = MinWidthScale->ScaleWidth(compBounds, parentBounds);

            if (value < min)
            {
                return min;
            }
        }

        if (MaxWidthScale != nullptr)
        {
            int max = MaxWidthScale->ScaleWidth(compBounds, parentBounds);

            if (value > max)
            {
                return max;
            }
        }

        return value;
    }

    int TransformManager::GetHeight(const FaceEngine::Math::Rectangle& compBounds, const FaceEngine::Math::Rectangle& parentBounds) const
    {
        int value = HeightScale->ScaleHeight(compBounds, parentBounds);

        if (MinHeightScale != nullptr)
        {
            int min = MinHeightScale->ScaleHeight(compBounds, parentBounds);

            if (value < min)
            {
                return min;
            }
        }

        if (MaxHeightScale != nullptr)
        {
            int max = MaxHeightScale->ScaleHeight(compBounds, parentBounds);

            if (value > max)
            {
                return max;
            }
        }

        return value;
    }
}
