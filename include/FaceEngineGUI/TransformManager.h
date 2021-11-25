#ifndef FACEENGINEGUI_TRANSFORMMANAGER_H
#define FACEENGINEGUI_TRANSFORMMANAGER_H

#include "FaceEngineGUI/Transforms/UIScale.h"
#include "FaceEngineGUI/Transforms/UITranslation.h"
#include "FaceEngine/Math/Rectangle.h"
#include <memory>

namespace FaceEngineGUI
{
    class TransformManager
    {
    public:
        FaceEngineGUI::Transforms::UITranslation* XTranslation;
        FaceEngineGUI::Transforms::UITranslation* MinXTranslation;
        FaceEngineGUI::Transforms::UITranslation* MaxXTranslation;

        FaceEngineGUI::Transforms::UITranslation* YTranslation;
        FaceEngineGUI::Transforms::UITranslation* MinYTranslation;
        FaceEngineGUI::Transforms::UITranslation* MaxYTranslation;

        FaceEngineGUI::Transforms::UIScale* WidthScale;
        FaceEngineGUI::Transforms::UIScale* MinWidthScale;
        FaceEngineGUI::Transforms::UIScale* MaxWidthScale;

        FaceEngineGUI::Transforms::UIScale* HeightScale;
        FaceEngineGUI::Transforms::UIScale* MinHeightScale;
        FaceEngineGUI::Transforms::UIScale* MaxHeightScale;

        TransformManager() : TransformManager(nullptr, nullptr, nullptr, nullptr) { }
        TransformManager(FaceEngineGUI::Transforms::UITranslation* xTranslation, FaceEngineGUI::Transforms::UITranslation* yTranslation, FaceEngineGUI::Transforms::UIScale* widthScale, FaceEngineGUI::Transforms::UIScale* heightScale);
        ~TransformManager();

        int GetX(const FaceEngine::Math::Rectangle& compBounds, const FaceEngine::Math::Rectangle& parentBounds) const;
        int GetY(const FaceEngine::Math::Rectangle& compBounds, const FaceEngine::Math::Rectangle& parentBounds) const;
        int GetWidth(const FaceEngine::Math::Rectangle& compBounds, const FaceEngine::Math::Rectangle& parentBounds) const;
        int GetHeight(const FaceEngine::Math::Rectangle& compBounds, const FaceEngine::Math::Rectangle& parentBounds) const;
    };
}

#endif