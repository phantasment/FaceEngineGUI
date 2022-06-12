#ifndef FACEENGINEGUI_UICOMPONENT_H
#define FACEENGINEGUI_UICOMPONENT_H

#include "FaceEngineGUI/TransformManager.h"
#include "FaceEngineGUI/AnimationManager.h"
#include "FaceEngine/Math/Rectangle.h"
#include "FaceEngineGUI/Transforms/UITranslation.h"
#include "FaceEngineGUI/Transforms/UIScale.h"
#include "FaceEngine/GameUpdate.h"
#include "FaceEngine/SpriteBatcher.h"

namespace FaceEngineGUI
{
    class UIComponent
    {
        protected:
            TransformManager TManager;
            AnimationManager AManager;
            FaceEngine::Rectanglef Bounds;
            std::vector<UIComponent*> Children;
            UIComponent* Parent;

            bool IsVisible;
            bool enabled = true;

            UIComponent(UIComponent* parent = nullptr);
            UIComponent(const int width, const int height, UIComponent* parent = nullptr);
            UIComponent(const int x, const int y, const int width, const int height, UIComponent* parent = nullptr);

            virtual void RefreshComponent();

            void UpdateAnimations(FaceEngine::GameUpdate* gameUpdate);

        public:
            virtual ~UIComponent();
            virtual void Update(FaceEngine::GameUpdate* gameUpdate);
            virtual void Draw(FaceEngine::SpriteBatcher* renderer); // change all variable names away from renderer

            void InitialiseAnimations();
            void SetIntroTransition(FaceEngineGUI::Animations::Transition* introTransition);

            void AddChild(UIComponent* childComp);
            void RemoveChild(UIComponent* childComp);

            void Enable();
            void Disable();
            bool IsEnabled() const;

            UIComponent* GetParent() const;
            FaceEngine::Rectanglef GetBounds() const;
            int GetX() const;
            int GetY() const;
            int GetRelativeX() const;
            int GetRelativeY() const;
            int GetLeft() const;
            int GetRight() const;
            int GetTop() const;
            int GetBottom() const;
            int GetWidth() const;
            int GetHeight() const;

            void SetX(int pixels);
            void SetX(int pixels, FaceEngineGUI::MeasurementPoint measureFrom);
            void SetXRelative(float percentage);
            void SetXRelative(float percentage, FaceEngineGUI::MeasurementPoint measureFrom);
            void CentreX();
            void CentreX(FaceEngineGUI::MeasurementPoint measureFrom);

            void SetY(int pixels);
            void SetY(int pixels, FaceEngineGUI::MeasurementPoint measureFrom);
            void SetYRelative(float percentage);
            void SetYRelative(float percentage, FaceEngineGUI::MeasurementPoint measureFrom);
            void CentreY();
            void CentreY(FaceEngineGUI::MeasurementPoint measureFrom);

            void SetWidth(int pixels);
            void SetWidthRelative(float percentage);
            
            void SetHeight(int pixels);
            void SetHeightRelative(float percentage);

            virtual void SetX(FaceEngineGUI::UITranslation* xTranslation);
            void SetMinX(FaceEngineGUI::UITranslation* xTranslation);
            void SetMaxX(FaceEngineGUI::UITranslation* xTranslation);
            virtual void SetY(FaceEngineGUI::UITranslation* yTranslation);
            void SetMinY(FaceEngineGUI::UITranslation* yTranslation);
            void SetMaxY(FaceEngineGUI::UITranslation* yTranslation);

            void SetWidth(FaceEngineGUI::UIScale* widthScale);
            void SetMinWidth(FaceEngineGUI::UIScale* widthScale);
            void SetMaxWidth(FaceEngineGUI::UIScale* widthScale);
            void SetHeight(FaceEngineGUI::UIScale* heightScale);
            void SetMinHeight(FaceEngineGUI::UIScale* heightScale);
            void SetMaxHeight(FaceEngineGUI::UIScale* heightScale);
    };
}

#endif