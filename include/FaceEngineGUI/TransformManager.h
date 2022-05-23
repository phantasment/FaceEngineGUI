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
        FaceEngineGUI::UITranslation* XTranslation;
        FaceEngineGUI::UITranslation* MinXTranslation;
        FaceEngineGUI::UITranslation* MaxXTranslation;

        FaceEngineGUI::UITranslation* YTranslation;
        FaceEngineGUI::UITranslation* MinYTranslation;
        FaceEngineGUI::UITranslation* MaxYTranslation;

        FaceEngineGUI::UIScale* WidthScale;
        FaceEngineGUI::UIScale* MinWidthScale;
        FaceEngineGUI::UIScale* MaxWidthScale;

        FaceEngineGUI::UIScale* HeightScale;
        FaceEngineGUI::UIScale* MinHeightScale;
        FaceEngineGUI::UIScale* MaxHeightScale;

        TransformManager() : TransformManager(nullptr, nullptr, nullptr, nullptr) { }
        TransformManager(FaceEngineGUI::UITranslation* xTranslation, FaceEngineGUI::UITranslation* yTranslation, FaceEngineGUI::UIScale* widthScale, FaceEngineGUI::UIScale* heightScale);
        ~TransformManager();

        int GetX(const FaceEngine::Rectanglef& compBounds, const FaceEngine::Rectanglef& parentBounds) const;
        int GetY(const FaceEngine::Rectanglef& compBounds, const FaceEngine::Rectanglef& parentBounds) const;
        int GetWidth(const FaceEngine::Rectanglef& compBounds, const FaceEngine::Rectanglef& parentBounds) const;
        int GetHeight(const FaceEngine::Rectanglef& compBounds, const FaceEngine::Rectanglef& parentBounds) const;
    };
}

#endif