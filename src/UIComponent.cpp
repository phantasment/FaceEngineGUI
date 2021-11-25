#include "FaceEngineGUI/UIComponent.h"
#include "FaceEngineGUI/Canvas.h"
#include "FaceEngineGUI/Transforms/Translations/PixelTranslation.h"
#include "FaceEngineGUI/Transforms/Scales/PixelScale.h"
#include <iostream>

namespace FaceEngineGUI
{
    UIComponent::UIComponent(UIComponent* parent)
    {
        Initialise(0, 0, 0, 0, parent);
    }

    UIComponent::UIComponent(const int width, const int height, UIComponent* parent)
    {
        Initialise(0, 0, width, height, parent);
    }

    UIComponent::UIComponent(const int x, const int y, const int width, const int height, UIComponent* parent)
    {
        Initialise(x, y, width, height, parent);
    }

    UIComponent::~UIComponent()
    {
        for (long long unsigned int i = 0; i < Children.size(); ++i)
        {
            delete Children[i];
        }
    }

    void UIComponent::Initialise(const int x, const int y, const int width, const int height, UIComponent* parent)
    {
        Parent = parent;

        TManager.XTranslation = new Transforms::Translations::PixelTranslation(x);
        TManager.YTranslation = new Transforms::Translations::PixelTranslation(y);
        TManager.WidthScale = new Transforms::Scales::PixelScale(width);
        TManager.HeightScale = new Transforms::Scales::PixelScale(height);

        if (Parent != nullptr)
        {
            Parent->AddChild(this);
        }

        RefreshComponent();
    }

    void UIComponent::RefreshComponent()
    {
        if (Parent == nullptr)
        {
            Bounds.Width = TManager.GetWidth(Bounds, Canvas::Bounds);
            Bounds.Height = TManager.GetHeight(Bounds, Canvas::Bounds);
            Bounds.X = TManager.GetX(Bounds, Canvas::Bounds);
            Bounds.Y = TManager.GetY(Bounds, Canvas::Bounds);
        }
        else
        {
            Bounds.Width = TManager.GetWidth(Bounds, Parent->Bounds);
            Bounds.Height = TManager.GetHeight(Bounds, Parent->Bounds);
            Bounds.X = TManager.GetX(Bounds, Parent->Bounds);
            Bounds.Y = TManager.GetY(Bounds, Parent->Bounds);
        }
        
        //TODO: refresh children.
    }

    void UIComponent::Update(std::shared_ptr<FaceEngine::GameUpdate> gameUpdate)
    {
        //TODO: update children.
    }

    void UIComponent::Draw(std::shared_ptr<FaceEngine::Graphics::SpriteRenderer> renderer)
    {
        //TODO: draw children.
    }

    void UIComponent::AddChild(UIComponent* childComp)
    {
        Children.push_back(childComp);

        if (childComp->Parent != nullptr)
        {
            childComp->Parent->RemoveChild(this);
        }

        childComp->Parent = this;
    }

    void UIComponent::RemoveChild(UIComponent* childComp)
    {
        //Children.erase(std::remove(Children.begin(), Children.end(), childComp), Children.end());
        //childComp->Parent = nullptr;
    }

    UIComponent* UIComponent::GetParent() const
    {
        return Parent;
    }

    FaceEngine::Math::Rectangle UIComponent::GetBounds() const
    {
        return Bounds;
    }

    int UIComponent::GetX() const
    {
        return Bounds.X;
    }

    int UIComponent::GetY() const
    {
        return Bounds.Y;
    }

    int UIComponent::GetRelativeX() const
    {
        return Bounds.X - Parent->Bounds.X;
    }

    int UIComponent::GetRelativeY() const
    {
        return Bounds.Y - Parent->Bounds.Y;
    }

    int UIComponent::GetLeft() const
    {
        return Bounds.GetLeft();
    }

    int UIComponent::GetRight() const
    {
        return Bounds.GetRight();
    }

    int UIComponent::GetTop() const
    {
        return Bounds.GetTop();
    }

    int UIComponent::GetBottom() const
    {
        return Bounds.GetBottom();
    }

    int UIComponent::GetWidth() const
    {
        return Bounds.Width;
    }

    int UIComponent::GetHeight() const
    {
        return Bounds.Height;
    }

    void UIComponent::SetX(Transforms::UITranslation* xTranslation)
    {
        TManager.XTranslation = xTranslation;
        RefreshComponent();
    }

    void UIComponent::SetMinX(Transforms::UITranslation* xTranslation)
    {
        TManager.MinXTranslation = xTranslation;
        RefreshComponent();
    }

    void UIComponent::SetMaxX(Transforms::UITranslation* xTranslation)
    {
        TManager.MaxXTranslation = xTranslation;
        RefreshComponent();
    }

    void UIComponent::SetY(Transforms::UITranslation* yTranslation)
    {
        TManager.YTranslation = yTranslation;
        RefreshComponent();
    }

    void UIComponent::SetMinY(Transforms::UITranslation* yTranslation)
    {
        TManager.MinYTranslation = yTranslation;
        RefreshComponent();
    }

    void UIComponent::SetMaxY(Transforms::UITranslation* yTranslation)
    {
        TManager.MaxYTranslation = yTranslation;
        RefreshComponent();
    }

    void UIComponent::SetWidth(Transforms::UIScale* widthScale)
    {
        TManager.WidthScale = widthScale;
        RefreshComponent();
    }

    void UIComponent::SetMinWidth(Transforms::UIScale* widthScale)
    {
        TManager.MinWidthScale = widthScale;
        RefreshComponent();
    }

    void UIComponent::SetMaxWidth(Transforms::UIScale* widthScale)
    {
        TManager.MaxWidthScale = widthScale;
        RefreshComponent();
    }

    void UIComponent::SetHeight(Transforms::UIScale* heightScale)
    {
        TManager.HeightScale = heightScale;
        RefreshComponent();
    }

    void UIComponent::SetMinHeight(Transforms::UIScale* heightScale)
    {
        TManager.MinHeightScale = heightScale;
        RefreshComponent();
    }

    void UIComponent::SetMaxHeight(Transforms::UIScale* heightScale)
    {
        TManager.MaxHeightScale = heightScale;
        RefreshComponent();
    }
}
