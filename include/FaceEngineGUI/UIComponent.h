#ifndef FACEENGINEGUI_UICOMPONENT_H
#define FACEENGINEGUI_UICOMPONENT_H

#include "FaceEngineGUI/TransformManager.h"
#include "FaceEngineGUI/AnimationManager.h"
#include "FaceEngine/Math/Rectangle.h"
#include "FaceEngineGUI/Transforms/UITranslation.h"
#include "FaceEngineGUI/Transforms/UIScale.h"
#include "FaceEngine/GameUpdate.h"
#include "FaceEngine/Graphics/SpriteRenderer.h"

namespace FaceEngineGUI
{
    class UIComponent
    {
        protected:
            TransformManager TManager;
            AnimationManager AManager;
            FaceEngine::Math::Rectangle Bounds;
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
            virtual void Draw(FaceEngine::Graphics::SpriteRenderer* renderer);

            void InitialiseAnimations();
            void SetIntroTransition(FaceEngineGUI::Animations::Transition* introTransition);

            void AddChild(UIComponent* childComp);
            void RemoveChild(UIComponent* childComp);

            void Enable();
            void Disable();
            bool IsEnabled() const;

            UIComponent* GetParent() const;
            FaceEngine::Math::Rectangle GetBounds() const;
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

            virtual void SetX(FaceEngineGUI::Transforms::UITranslation* xTranslation);
            void SetMinX(FaceEngineGUI::Transforms::UITranslation* xTranslation);
            void SetMaxX(FaceEngineGUI::Transforms::UITranslation* xTranslation);
            virtual void SetY(FaceEngineGUI::Transforms::UITranslation* yTranslation);
            void SetMinY(FaceEngineGUI::Transforms::UITranslation* yTranslation);
            void SetMaxY(FaceEngineGUI::Transforms::UITranslation* yTranslation);

            void SetWidth(FaceEngineGUI::Transforms::UIScale* widthScale);
            void SetMinWidth(FaceEngineGUI::Transforms::UIScale* widthScale);
            void SetMaxWidth(FaceEngineGUI::Transforms::UIScale* widthScale);
            void SetHeight(FaceEngineGUI::Transforms::UIScale* heightScale);
            void SetMinHeight(FaceEngineGUI::Transforms::UIScale* heightScale);
            void SetMaxHeight(FaceEngineGUI::Transforms::UIScale* heightScale);
    };
}

#endif