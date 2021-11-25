#include "FaceEngineGUI/TextureDesign/ColourScheme.h"

namespace FaceEngineGUI::TextureDesign
{
    ColourScheme::ColourScheme()
    {
        _backgroundColour = FaceEngine::Graphics::Colour(0, 0, 0, 0);
        _borderColour = FaceEngine::Graphics::Colour(0, 0, 0, 0);

        _hoveredBackgroundColour = FaceEngine::Graphics::Colour(0, 0, 0, 0);
        _pressedBackgroundColour = FaceEngine::Graphics::Colour(0, 0, 0, 0);
        _hoveredBorderColour = FaceEngine::Graphics::Colour(0, 0, 0, 0);
        _pressedBorderColour = FaceEngine::Graphics::Colour(0, 0, 0, 0);

        _scrollbarColour = FaceEngine::Graphics::Colour(0, 0, 0, 0);
        _hoveredScrollbarColour = FaceEngine::Graphics::Colour(0, 0, 0, 0);
        _pressedScrollbarColour = FaceEngine::Graphics::Colour(0, 0, 0, 0);
        _scrollerColour = FaceEngine::Graphics::Colour(0, 0, 0, 0);
        _hoveredScrollerColour = FaceEngine::Graphics::Colour(0, 0, 0, 0);
        _pressedScrollerColour = FaceEngine::Graphics::Colour(0, 0, 0, 0);

        _textColour = FaceEngine::Graphics::Colour(0, 0, 0, 0);
        _inaccessibleTextColour = FaceEngine::Graphics::Colour(0, 0, 0, 0);
        _selectedTextColour = FaceEngine::Graphics::Colour(0, 0, 0, 0);
        _textSelectionBackgroundColour = FaceEngine::Graphics::Colour(0, 0, 0, 0);

        _childColourScheme = nullptr;
    }

    FaceEngine::Graphics::Colour ColourScheme::GetBackgroundColour() const
    {
        return _backgroundColour;
    }

    FaceEngine::Graphics::Colour ColourScheme::GetBorderColour() const
    {
        return _borderColour;
    }
}
