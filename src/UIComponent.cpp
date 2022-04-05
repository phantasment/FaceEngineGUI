#include "FaceEngineGUI/UIComponent.h"
#include "FaceEngineGUI/Canvas.h"
#include "FaceEngineGUI/Transforms/Translations/PixelTranslation.h"
#include "FaceEngineGUI/Transforms/Scales/PixelScale.h"
#include <iostream>
#include <algorithm>

namespace FaceEngineGUI
{
    UIComponent::UIComponent(UIComponent* parent)
    {
        Parent = nullptr;

        TManager.XTranslation = new Transforms::Translations::PixelTranslation(0);
        TManager.YTranslation = new Transforms::Translations::PixelTranslation(0);
        TManager.WidthScale = new Transforms::Scales::PixelScale(0);
        TManager.HeightScale = new Transforms::Scales::PixelScale(0);

        if (parent != nullptr)
        {
            parent->AddChild(this);
        }

        RefreshComponent();
    }

    UIComponent::UIComponent(const int width, const int height, UIComponent* parent)
    {
        Parent = nullptr;

        TManager.XTranslation = new Transforms::Translations::PixelTranslation(0);
        TManager.YTranslation = new Transforms::Translations::PixelTranslation(0);
        TManager.WidthScale = new Transforms::Scales::PixelScale(width);
        TManager.HeightScale = new Transforms::Scales::PixelScale(height);

        if (parent != nullptr)
        {
            parent->AddChild(this);
        }

        RefreshComponent();
    }

    UIComponent::UIComponent(const int x, const int y, const int width, const int height, UIComponent* parent)
    {
        Parent = nullptr;

        TManager.XTranslation = new Transforms::Translations::PixelTranslation(x);
        TManager.YTranslation = new Transforms::Translations::PixelTranslation(y);
        TManager.WidthScale = new Transforms::Scales::PixelScale(width);
        TManager.HeightScale = new Transforms::Scales::PixelScale(height);

        if (parent != nullptr)
        {
            parent->AddChild(this);
        }

        RefreshComponent();
    }

    UIComponent::~UIComponent()
    {
        for (long long unsigned int i = 0; i < Children.size(); ++i)
        {
            delete Children[i];
        }
    }

    void UIComponent::RefreshComponent()
    {
        if (!AManager.IsPlaying())
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
        }
        
        for (int i = 0; i < Children.size(); ++i)
        {
            Children[i]->RefreshComponent();
        }
    }

    void UIComponent::Update(FaceEngine::GameUpdate* gameUpdate)
    {
        if (!enabled)
        {
            return;
        }

        UpdateAnimations(gameUpdate);

        //TODO: update children.
    }

    void UIComponent::Draw(FaceEngine::Graphics::SpriteRenderer* renderer)
    {
        if (!enabled)
        {
            return;
        }
        
        //TODO: draw children.
    }

    void UIComponent::AddChild(UIComponent* childComp)
    {
        for (int i = 0; i < Children.size(); ++i)
        {
            if (Children[i] == childComp)
            {
                return;
            }
        }

        Children.push_back(childComp);

        if (childComp->Parent != nullptr)
        {
            childComp->Parent->RemoveChild(childComp);
        }

        childComp->Parent = this;
    }

    void UIComponent::RemoveChild(UIComponent* childComp)
    {
        std::cout << Children.size() << std::endl;

        for (int i = 0; i < Children.size(); ++i)
        {
            if (Children[i] == childComp)
            {
                childComp->Parent = nullptr;
                childComp->RefreshComponent();

                Children.erase(Children.begin() + i - 1);

                break;
            }
        }

        std::cout << Children.size() << std::endl;
    }

    void UIComponent::Enable()
    {
        enabled = true;

        for (int i = 0; i < Children.size(); ++i)
        {
            Children[i]->Enable();
        }
    }

    void UIComponent::Disable()
    {
        enabled = false;

        for (int i = 0; i < Children.size(); ++i)
        {
            Children[i]->Disable();
        }
    }

    bool UIComponent::IsEnabled() const
    {
        return enabled;
    }
    
    void UIComponent::InitialiseAnimations()
    {
        AManager.PlayIntro();
    }

    void UIComponent::UpdateAnimations(FaceEngine::GameUpdate* gameUpdate)
    {
        AManager.Update(gameUpdate);

        if (!AManager.IsPlaying())
        {
            return;
        }

        //std::cout << "Updating animations" << std::endl;

        if (Parent == nullptr)
        {
            Bounds.Width = TManager.GetWidth(Bounds, Canvas::Bounds) + AManager.GetWidthOffset();
            Bounds.Height = TManager.GetHeight(Bounds, Canvas::Bounds) + AManager.GetHeightOffset();
            Bounds.X = TManager.GetX(Bounds, Canvas::Bounds) + AManager.GetXOffset();
            Bounds.Y = TManager.GetY(Bounds, Canvas::Bounds) + AManager.GetYOffset();
        }
        else
        {
            Bounds.Width = TManager.GetWidth(Bounds, Parent->Bounds) + AManager.GetWidthOffset();
            Bounds.Height = TManager.GetHeight(Bounds, Parent->Bounds) + AManager.GetHeightOffset();
            Bounds.X = TManager.GetX(Bounds, Parent->Bounds) + AManager.GetXOffset();
            Bounds.Y = TManager.GetY(Bounds, Parent->Bounds) + AManager.GetYOffset();
        }
    }

    void UIComponent::SetIntroTransition(Animations::Transition* introTransition)
    {
        AManager.IntroTransition = introTransition;
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
        if (TManager.XTranslation != nullptr) // TODO: move this into TManager
        {
            delete TManager.XTranslation;
        }

        TManager.XTranslation = xTranslation;
        RefreshComponent();
    }

    void UIComponent::SetMinX(Transforms::UITranslation* xTranslation)
    {
        if (TManager.MinXTranslation != nullptr)
        {
            delete TManager.MinXTranslation;
        }

        TManager.MinXTranslation = xTranslation;
        RefreshComponent();
    }

    void UIComponent::SetMaxX(Transforms::UITranslation* xTranslation)
    {
        if (TManager.MaxXTranslation != nullptr)
        {
            delete TManager.MaxXTranslation;
        }

        TManager.MaxXTranslation = xTranslation;
        RefreshComponent();
    }

    void UIComponent::SetY(Transforms::UITranslation* yTranslation)
    {
        if (TManager.YTranslation != nullptr)
        {
            delete TManager.YTranslation;
        }

        TManager.YTranslation = yTranslation;
        RefreshComponent();
    }

    void UIComponent::SetMinY(Transforms::UITranslation* yTranslation)
    {
        if (TManager.MinYTranslation != nullptr)
        {
            delete TManager.MinYTranslation;
        }

        TManager.MinYTranslation = yTranslation;
        RefreshComponent();
    }

    void UIComponent::SetMaxY(Transforms::UITranslation* yTranslation)
    {
        if (TManager.MaxYTranslation != nullptr)
        {
            delete TManager.MaxYTranslation;
        }

        TManager.MaxYTranslation = yTranslation;
        RefreshComponent();
    }

    void UIComponent::SetWidth(Transforms::UIScale* widthScale)
    {
        if (TManager.WidthScale != nullptr)
        {
            delete TManager.WidthScale;
        }
        
        TManager.WidthScale = widthScale;
        RefreshComponent();
    }

    void UIComponent::SetMinWidth(Transforms::UIScale* widthScale)
    {
        if (TManager.MinWidthScale != nullptr)
        {
            delete TManager.MinWidthScale;
        }

        TManager.MinWidthScale = widthScale;
        RefreshComponent();
    }

    void UIComponent::SetMaxWidth(Transforms::UIScale* widthScale)
    {
        if (TManager.MaxWidthScale != nullptr)
        {
            delete TManager.MaxWidthScale;
        }

        TManager.MaxWidthScale = widthScale;
        RefreshComponent();
    }

    void UIComponent::SetHeight(Transforms::UIScale* heightScale)
    {
        if (TManager.HeightScale != nullptr)
        {
            delete TManager.HeightScale;
        }

        TManager.HeightScale = heightScale;
        RefreshComponent();
    }

    void UIComponent::SetMinHeight(Transforms::UIScale* heightScale)
    {
        if (TManager.MinHeightScale != nullptr)
        {
            delete TManager.MinHeightScale;
        }

        TManager.MinHeightScale = heightScale;
        RefreshComponent();
    }

    void UIComponent::SetMaxHeight(Transforms::UIScale* heightScale)
    {
        if (TManager.MaxHeightScale != nullptr)
        {
            delete TManager.MaxHeightScale;
        }

        TManager.MaxHeightScale = heightScale;
        RefreshComponent();
    }
}
