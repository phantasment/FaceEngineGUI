#ifndef FACEENGINEGUI_TEXTUREDESIGN_COLOURSCHEME_H
#define FACEENGINEGUI_TEXTUREDESIGN_COLOURSCHEME_H

#include "FaceEngine/Colour.h"

namespace FaceEngineGUI
{
    class ColourScheme
    {
        private:
            // ----- Basic Scheme -----

            FaceEngine::Colour _backgroundColour;
            FaceEngine::Colour _borderColour;
        
            // ----- Interactive Scheme -----

            FaceEngine::Colour _hoveredBackgroundColour;
            FaceEngine::Colour _pressedBackgroundColour;
            FaceEngine::Colour _hoveredBorderColour;
            FaceEngine::Colour _pressedBorderColour;

            // ----- Advanced Interactive Scheme -----

            FaceEngine::Colour _scrollbarColour;
            FaceEngine::Colour _hoveredScrollbarColour;
            FaceEngine::Colour _pressedScrollbarColour;
            FaceEngine::Colour _scrollerColour;
            FaceEngine::Colour _hoveredScrollerColour;
            FaceEngine::Colour _pressedScrollerColour;

            // ----- Text Scheme ----- TODO: rename some of these

            FaceEngine::Colour _textColour;
            FaceEngine::Colour _inaccessibleTextColour;
            FaceEngine::Colour _selectedTextColour;
            FaceEngine::Colour _textSelectionBackgroundColour;

            // ----- Inheritance Scheme -----

            ColourScheme* _childColourScheme;

        public:
            ColourScheme();
            ColourScheme(FaceEngine::Colour& backgroundColour, FaceEngine::Colour& borderColour);
            ~ColourScheme();

            FaceEngine::Colour GetBackgroundColour() const;
            FaceEngine::Colour GetBorderColour() const;
    };
}

#endif