#ifndef FACEENGINEGUI_UICOMPONENT_H
#define FACEENGINEGUI_UICOMPONENT_H

#include "FaceEngineGUI/TransformManager.h"
#include "FaceEngineGUI/AnimationManager.h"
#include "FaceEngine/Math/Rectangle.h"
#include "FaceEngineGUI/Transforms/UITranslation.h"
#include "FaceEngineGUI/Transforms/UIScale.h"
#include "FaceEngine/GameUpdate.h"
#include "FaceEngine/Graphics/SpriteRenderer.h"
#include <memory>

namespace FaceEngineGUI
{
    class UIComponent
    {
        private:
            void Initialise(const int x, const int y, const int width, const int height, UIComponent* parent);

        protected:
            TransformManager TManager;
            AnimationManager AManager;
            FaceEngine::Math::Rectangle Bounds;
            std::vector<UIComponent*> Children;
            UIComponent* Parent;

            bool IsVisible;

            UIComponent(UIComponent* parent = nullptr);
            UIComponent(const int width, const int height, UIComponent* parent = nullptr);
            UIComponent(const int x, const int y, const int width, const int height, UIComponent* parent = nullptr);
            virtual ~UIComponent();            

            virtual void RefreshComponent();
            virtual void Update(std::shared_ptr<FaceEngine::GameUpdate> gameUpdate);
            virtual void Draw(std::shared_ptr<FaceEngine::Graphics::SpriteRenderer> renderer);

        public:
            void AddChild(UIComponent* childComp);
            void RemoveChild(UIComponent* childComp);

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

            void SetX(FaceEngineGUI::Transforms::UITranslation* xTranslation);
            void SetMinX(FaceEngineGUI::Transforms::UITranslation* xTranslation);
            void SetMaxX(FaceEngineGUI::Transforms::UITranslation* xTranslation);
            void SetY(FaceEngineGUI::Transforms::UITranslation* yTranslation);
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