#ifndef FACEENGINEGUI_ANIMATIONS_TRANSITION_H
#define FACEENGINEGUI_ANIMATIONS_TRANSITION_H

#include "FaceEngineGUI/Animations/Animation.h"
#include "FaceEngine/GameUpdate.h"
#include <memory>

namespace FaceEngineGUI::Animations
{
    class Transition
    {
    private:
        bool _playing;

    public:
        Animation* XDriver;
        Animation* YDriver;
        Animation* WidthDriver;
        Animation* HeightDriver;
        Animation* AlphaDriver;

        Transition();
        ~Transition();

        int GetXOffset() const;
        int GetYOffset() const;
        int GetWidthOffset() const;
        int GetHeightOffset() const;
        float GetAlphaOffset() const;

        void Update(std::shared_ptr<FaceEngine::GameUpdate> gameUpdate);

        void Play();
        //void Pause();
        void Stop();

        bool IsPlaying() const;
    };
}

#endif