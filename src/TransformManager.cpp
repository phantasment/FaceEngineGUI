#include "FaceEngineGUI/TransformManager.h"

namespace FaceEngineGUI
{
    TransformManager::TransformManager(FaceEngineGUI::UITranslation* xTranslation, FaceEngineGUI::UITranslation* yTranslation, FaceEngineGUI::UIScale* widthScale, FaceEngineGUI::UIScale* heightScale)
    {
        _xTranslation = xTranslation;
        MinXTranslation = nullptr;
        MaxXTranslation = nullptr;

        _yTranslation = yTranslation;
        MinYTranslation = nullptr;
        MaxYTranslation = nullptr;

        _widthScale = widthScale;
        MinWidthScale = nullptr;
        MaxWidthScale = nullptr;

        _heightScale = heightScale;
        MinHeightScale = nullptr;
        MaxHeightScale = nullptr;
    }

    TransformManager::~TransformManager()
    {
        delete _xTranslation;
        delete MinXTranslation;
        delete MaxXTranslation;
        delete _yTranslation;
        delete MinYTranslation;
        delete MaxYTranslation;
        delete _widthScale;
        delete MinWidthScale;
        delete MaxWidthScale;
        delete _heightScale;
        delete MinHeightScale;
        delete MaxHeightScale;
    }

    void TransformManager::SetX(FaceEngineGUI::UITranslation* xTranslation)
    {
        if (_xTranslation != nullptr)
        {
            delete _xTranslation;
        }

        _xTranslation = xTranslation;
    }

    void TransformManager::SetY(FaceEngineGUI::UITranslation* yTranslation)
    {
        if (_yTranslation != nullptr)
        {
            delete _yTranslation;
        }

        _yTranslation = yTranslation;
    }

    void TransformManager::SetWidth(FaceEngineGUI::UIScale* widthScale)
    {
        if (_widthScale != nullptr)
        {
            delete _widthScale;
        }

        _widthScale = widthScale;
    }

    void TransformManager::SetHeight(FaceEngineGUI::UIScale* heightScale)
    {
        if (_heightScale != nullptr)
        {
            delete _heightScale;
        }

        _heightScale = heightScale;
    }

    int TransformManager::GetX(const FaceEngine::Rectanglef& compBounds, const FaceEngine::Rectanglef& parentBounds) const
    {
        int value = _xTranslation->TranslateX(compBounds, parentBounds);

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

    int TransformManager::GetY(const FaceEngine::Rectanglef& compBounds, const FaceEngine::Rectanglef& parentBounds) const
    {
        int value = _yTranslation->TranslateY(compBounds, parentBounds);

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

    int TransformManager::GetWidth(const FaceEngine::Rectanglef& compBounds, const FaceEngine::Rectanglef& parentBounds) const
    {
        int value = _widthScale->ScaleWidth(compBounds, parentBounds);

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

    int TransformManager::GetHeight(const FaceEngine::Rectanglef& compBounds, const FaceEngine::Rectanglef& parentBounds) const
    {
        int value = _heightScale->ScaleHeight(compBounds, parentBounds);

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
