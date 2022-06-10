#include "FaceEngineGUI/UIComponent.h"
#include "FaceEngineGUI/Canvas.h"
#include "FaceEngineGUI/Transforms/Translations/PixelTranslation.h"
#include "FaceEngineGUI/Transforms/Translations/CentreTranslation.h"
#include "FaceEngineGUI/Transforms/Translations/RelativeTranslation.h"
#include "FaceEngineGUI/Transforms/Scales/PixelScale.h"
#include "FaceEngineGUI/Transforms/Scales/RelativeScale.h"
#include <iostream>
#include <algorithm>

namespace FaceEngineGUI
{
    UIComponent::UIComponent(UIComponent* parent)
    {
        Parent = parent;

        TManager.SetX(new FaceEngineGUI::Translations::PixelTranslation(0));;
        TManager.SetY(new FaceEngineGUI::Translations::PixelTranslation(0));
        TManager.SetWidth(new FaceEngineGUI::Scales::PixelScale(0));
        TManager.SetHeight(new FaceEngineGUI::Scales::PixelScale(0));

        if (parent != nullptr)
        {
            parent->AddChild(this);
        }

        RefreshComponent();
    }

    UIComponent::UIComponent(const int width, const int height, UIComponent* parent)
    {
        Parent = parent;

        TManager.SetX(new FaceEngineGUI::Translations::PixelTranslation(0));
        TManager.SetY(new FaceEngineGUI::Translations::PixelTranslation(0));
        TManager.SetWidth(new FaceEngineGUI::Scales::PixelScale(width));
        TManager.SetHeight(new FaceEngineGUI::Scales::PixelScale(height));

        if (parent != nullptr)
        {
            parent->AddChild(this);
        }

        RefreshComponent();
    }

    UIComponent::UIComponent(const int x, const int y, const int width, const int height, UIComponent* parent)
    {
        Parent = parent;

        TManager.SetX(new FaceEngineGUI::Translations::PixelTranslation(x));
        TManager.SetY(new FaceEngineGUI::Translations::PixelTranslation(y));
        TManager.SetWidth(new FaceEngineGUI::Scales::PixelScale(width));
        TManager.SetHeight(new FaceEngineGUI::Scales::PixelScale(height));

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

    void UIComponent::SetX(int pixels)
    {
        SetX(new FaceEngineGUI::Translations::PixelTranslation(pixels));
    }

    void UIComponent::SetXRelative(float percentage)
    {
        SetX(new FaceEngineGUI::Translations::RelativeTranslation(percentage));
    }

    void UIComponent::CentreX()
    {
        SetX(new FaceEngineGUI::Translations::CentreTranslation());
    }

    void UIComponent::SetY(int pixels)
    {
        SetY(new FaceEngineGUI::Translations::PixelTranslation(pixels));
    }

    void UIComponent::SetYRelative(float percentage)
    {
        SetY(new FaceEngineGUI::Translations::RelativeTranslation(percentage));
    }

    void UIComponent::CentreY()
    {
        SetY(new FaceEngineGUI::Translations::CentreTranslation());
    }

    void UIComponent::SetWidth(int pixels)
    {
        SetWidth(new FaceEngineGUI::Scales::PixelScale(pixels));
    }

    void UIComponent::SetWidthRelative(float percentage)
    {
        SetWidth(new FaceEngineGUI::Scales::RelativeScale(percentage));
    }

    void UIComponent::SetHeight(int pixels)
    {
        SetHeight(new FaceEngineGUI::Scales::PixelScale(pixels));
    }

    void UIComponent::SetHeightRelative(float percentage)
    {
        SetHeight(new FaceEngineGUI::Scales::RelativeScale(percentage));
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

    void UIComponent::Draw(FaceEngine::SpriteBatcher* renderer)
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

    FaceEngine::Rectanglef UIComponent::GetBounds() const
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

    void UIComponent::SetX(FaceEngineGUI::UITranslation* xTranslation)
    {
        TManager.SetX(xTranslation);
        RefreshComponent();
    }

    void UIComponent::SetMinX(FaceEngineGUI::UITranslation* xTranslation)
    {
        if (TManager.MinXTranslation != nullptr)
        {
            delete TManager.MinXTranslation;
        }

        TManager.MinXTranslation = xTranslation;
        RefreshComponent();
    }

    void UIComponent::SetMaxX(FaceEngineGUI::UITranslation* xTranslation)
    {
        if (TManager.MaxXTranslation != nullptr)
        {
            delete TManager.MaxXTranslation;
        }

        TManager.MaxXTranslation = xTranslation;
        RefreshComponent();
    }

    void UIComponent::SetY(FaceEngineGUI::UITranslation* yTranslation)
    {
        TManager.SetY(yTranslation);
        RefreshComponent();
    }

    void UIComponent::SetMinY(FaceEngineGUI::UITranslation* yTranslation)
    {
        if (TManager.MinYTranslation != nullptr)
        {
            delete TManager.MinYTranslation;
        }

        TManager.MinYTranslation = yTranslation;
        RefreshComponent();
    }

    void UIComponent::SetMaxY(FaceEngineGUI::UITranslation* yTranslation)
    {
        if (TManager.MaxYTranslation != nullptr)
        {
            delete TManager.MaxYTranslation;
        }

        TManager.MaxYTranslation = yTranslation;
        RefreshComponent();
    }

    void UIComponent::SetWidth(FaceEngineGUI::UIScale* widthScale)
    {
        TManager.SetWidth(widthScale);
        RefreshComponent();
    }

    void UIComponent::SetMinWidth(FaceEngineGUI::UIScale* widthScale)
    {
        if (TManager.MinWidthScale != nullptr)
        {
            delete TManager.MinWidthScale;
        }

        TManager.MinWidthScale = widthScale;
        RefreshComponent();
    }

    void UIComponent::SetMaxWidth(FaceEngineGUI::UIScale* widthScale)
    {
        if (TManager.MaxWidthScale != nullptr)
        {
            delete TManager.MaxWidthScale;
        }

        TManager.MaxWidthScale = widthScale;
        RefreshComponent();
    }

    void UIComponent::SetHeight(FaceEngineGUI::UIScale* heightScale)
    {
        TManager.SetHeight(heightScale);
        RefreshComponent();
    }

    void UIComponent::SetMinHeight(FaceEngineGUI::UIScale* heightScale)
    {
        if (TManager.MinHeightScale != nullptr)
        {
            delete TManager.MinHeightScale;
        }

        TManager.MinHeightScale = heightScale;
        RefreshComponent();
    }

    void UIComponent::SetMaxHeight(FaceEngineGUI::UIScale* heightScale)
    {
        if (TManager.MaxHeightScale != nullptr)
        {
            delete TManager.MaxHeightScale;
        }

        TManager.MaxHeightScale = heightScale;
        RefreshComponent();
    }
}
