#include "FaceEngineGUI/AnimationManager.h"
#include <iostream>

#define print(x) std::cout << x << std::endl

namespace FaceEngineGUI
{
    AnimationManager::AnimationManager()
    {
        _activeTransition = nullptr;
        IntroTransition = nullptr;
        OutroTransition = nullptr;
    }

    AnimationManager::~AnimationManager()
    {
        delete IntroTransition;
        delete OutroTransition;
    }

    void AnimationManager::Update(FaceEngine::GameUpdate* gameUpdate)
    {   
        if (_activeTransition == nullptr)
        {
            return;
        }

        _activeTransition->Update(gameUpdate);

        if (_activeTransition->IsPlaying())
        {
            _activeTransition = nullptr;
        }
    }

    void AnimationManager::PlayIntro()
    {
        if (IntroTransition == nullptr)
        {
            return;
        }

        _activeTransition = IntroTransition;
        _activeTransition->Play();
    }

    void AnimationManager::PlayOutro()
    {
        if (OutroTransition == nullptr)
        {
            return;
        }

        _activeTransition = OutroTransition;
    }

    bool AnimationManager::IsPlaying() const
    {
        return _activeTransition != nullptr;
    }

    int AnimationManager::GetXOffset() const
    {
        return _activeTransition->GetXOffset();
    }

    int AnimationManager::GetYOffset() const
    {
        return _activeTransition->GetYOffset();
    }

    int AnimationManager::GetWidthOffset() const
    {
        return _activeTransition->GetWidthOffset();
    }

    int AnimationManager::GetHeightOffset() const
    {
        return _activeTransition->GetHeightOffset();
    }

    float AnimationManager::GetAlphaOffset() const
    {
        return _activeTransition->GetAlphaOffset();
    }
}
