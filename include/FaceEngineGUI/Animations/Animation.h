#ifndef FACEENGINEGUI_ANIMATIONS_ANIMATION_H
#define FACEENGINEGUI_ANIMATIONS_ANIMATION_H

#include "FaceEngine/GameUpdate.h"
#include <memory>

namespace FaceEngineGUI::Animations
{
    class Animation
    {
    private:
        float _initialValue;
        float _delay;
        float _duration;
        bool _playing;

        double _currentDuration;
        
    public:
        Animation(float initialValue, float duration);
        ~Animation();

        float GetValue();
        void Update(FaceEngine::GameUpdate* gameUpdate);
        void Stop();
        void Play();

        bool IsPlaying();
    };
}

#endif