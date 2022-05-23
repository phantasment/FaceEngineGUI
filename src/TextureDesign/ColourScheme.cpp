#include "FaceEngineGUI/TextureDesign/ColourScheme.h"

namespace FaceEngineGUI
{
    ColourScheme::ColourScheme()
    {
        _backgroundColour = FaceEngine::Colour(0, 0, 0, 0);
        _borderColour = FaceEngine::Colour(0, 0, 0, 0);

        _hoveredBackgroundColour = FaceEngine::Colour(0, 0, 0, 0);
        _pressedBackgroundColour = FaceEngine::Colour(0, 0, 0, 0);
        _hoveredBorderColour = FaceEngine::Colour(0, 0, 0, 0);
        _pressedBorderColour = FaceEngine::Colour(0, 0, 0, 0);

        _scrollbarColour = FaceEngine::Colour(0, 0, 0, 0);
        _hoveredScrollbarColour = FaceEngine::Colour(0, 0, 0, 0);
        _pressedScrollbarColour = FaceEngine::Colour(0, 0, 0, 0);
        _scrollerColour = FaceEngine::Colour(0, 0, 0, 0);
        _hoveredScrollerColour = FaceEngine::Colour(0, 0, 0, 0);
        _pressedScrollerColour = FaceEngine::Colour(0, 0, 0, 0);

        _textColour = FaceEngine::Colour(0, 0, 0, 0);
        _inaccessibleTextColour = FaceEngine::Colour(0, 0, 0, 0);
        _selectedTextColour = FaceEngine::Colour(0, 0, 0, 0);
        _textSelectionBackgroundColour = FaceEngine::Colour(0, 0, 0, 0);

        _childColourScheme = nullptr;
    }

    FaceEngine::Colour ColourScheme::GetBackgroundColour() const
    {
        return _backgroundColour;
    }

    FaceEngine::Colour ColourScheme::GetBorderColour() const
    {
        return _borderColour;
    }
}
