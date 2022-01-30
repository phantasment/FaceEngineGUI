#include "FaceEngineGUI/Animations/Animation.h"
#include <cmath>
#include <iostream>

#define print(x) std::cout << x << std::endl


namespace FaceEngineGUI::Animations
{
    Animation::Animation(float initialValue, float duration)
    {
        _initialValue = initialValue;
        _duration = duration;
        _delay = 0;
        _currentDuration = 0;
        _playing = false;
    }

    Animation::~Animation()
    {

    }

    float Animation::GetValue()
    {
        return (_currentDuration / _duration) * std::abs(_initialValue) + _initialValue;
    }

    void Animation::Update(FaceEngine::GameUpdate* gameUpdate)
    {
        if (!_playing)
        {
            return;
        }

        _currentDuration += gameUpdate->GetDelta();

        if (_currentDuration >= _duration)
        {
            Stop();
        }
    }

    bool Animation::IsPlaying()
    {
        return _playing;
    }

    void Animation::Play()
    {
        _currentDuration = 0;
        _playing = true;
    }

    void Animation::Stop()
    {
        _playing = false;
        _currentDuration = _duration;
    }
}