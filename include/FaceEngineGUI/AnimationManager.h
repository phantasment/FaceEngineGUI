#ifndef FACEENGINEGUI_ANIMATIONMANAGER_H
#define FACEENGINEGUI_ANIMATIONMANAGER_H

#include "FaceEngineGUI/Animations/Transition.h"

namespace FaceEngineGUI
{
    class AnimationManager
    {
    private:
        Animations::Transition* _activeTransition;

    public:
        Animations::Transition* IntroTransition;
        Animations::Transition* OutroTransition;
        // Animation PassiveAnimation;
        // Animation[] Animations;

        AnimationManager();
        ~AnimationManager();

        void Update(std::shared_ptr<FaceEngine::GameUpdate> gameUpdate);
        void PlayIntro();
        void PlayOutro();
        // void PlayAnimation(int index);

        bool IsPlaying() const;
        
        int GetXOffset() const;
        int GetYOffset() const;
        int GetWidthOffset() const;
        int GetHeightOffset() const;
        float GetAlphaOffset() const;
    };
}

#endif