#include "FaceEngineGUI/Animations/Transition.h"
#include <iostream>

#define print(x) std::cout << x << std::endl

namespace FaceEngineGUI::Animations
{
    Transition::Transition()
    {
        XDriver = nullptr;
        YDriver = nullptr;
        WidthDriver = nullptr;
        HeightDriver = nullptr;
        AlphaDriver = nullptr;

        _playing = false;
    }

    Transition::~Transition()
    {
        delete XDriver;
        delete YDriver;
        delete WidthDriver;
        delete HeightDriver;
        delete AlphaDriver;
    }

    void Transition::Update(std::shared_ptr<FaceEngine::GameUpdate> gameUpdate)
    {
        if (XDriver != nullptr)
        {
            XDriver->Update(gameUpdate);
        }

        if (YDriver != nullptr)
        {
            YDriver->Update(gameUpdate);
        }

        if (WidthDriver != nullptr)
        {
            WidthDriver->Update(gameUpdate);
        }

        if (HeightDriver != nullptr)
        {
            HeightDriver->Update(gameUpdate);
        }

        if (AlphaDriver != nullptr)
        {
            AlphaDriver->Update(gameUpdate);
        }

        if (((XDriver != nullptr && XDriver->IsPlaying()) || XDriver == nullptr) &&
            ((YDriver != nullptr && YDriver->IsPlaying()) || YDriver == nullptr) &&
            ((WidthDriver != nullptr && WidthDriver->IsPlaying()) || WidthDriver == nullptr) &&
            ((HeightDriver != nullptr && HeightDriver->IsPlaying()) || HeightDriver == nullptr) &&
            ((AlphaDriver != nullptr && AlphaDriver->IsPlaying()) || AlphaDriver == nullptr))
        {
            _playing = false;
        }
    }

    void Transition::Play()
    {
        _playing = true;

        if (XDriver != nullptr)
        {
            XDriver->Play();
        }

        if (YDriver != nullptr)
        {
            YDriver->Play();
        }

        if (WidthDriver != nullptr)
        {
            WidthDriver->Play();
        }

        if (HeightDriver != nullptr)
        {
            HeightDriver->Play();
        }

        if (AlphaDriver != nullptr)
        {
            AlphaDriver->Play();
        }
    }

    void Transition::Stop()
    {
        _playing = false;

        if (XDriver != nullptr)
        {
            XDriver->Stop();
        }

        if (YDriver != nullptr)
        {
            YDriver->Stop();
        }

        if (WidthDriver != nullptr)
        {
            WidthDriver->Stop();
        }

        if (HeightDriver != nullptr)
        {
            HeightDriver->Stop();
        }

        if (AlphaDriver != nullptr)
        {
            AlphaDriver->Stop();
        }
    }

    bool Transition::IsPlaying() const
    {
        return _playing;
    }

    int Transition::GetXOffset() const
    {
        if (XDriver == nullptr)
        {
            return 0;
        }

        return XDriver->GetValue();
    }

    int Transition::GetYOffset() const
    {
        if (YDriver == nullptr)
        {
            return 0;
        }

        return YDriver->GetValue();
    }

    int Transition::GetWidthOffset() const
    {
        if (WidthDriver == nullptr)
        {
            return 0;
        }

        return WidthDriver->GetValue();
    }

    int Transition::GetHeightOffset() const
    {
        if (HeightDriver == nullptr)
        {
            return 0;
        }

        return HeightDriver->GetValue();
    }

    float Transition::GetAlphaOffset() const
    {
        if (AlphaDriver == nullptr)
        {
            return 0;
        }

        return AlphaDriver->GetValue();
    }
}