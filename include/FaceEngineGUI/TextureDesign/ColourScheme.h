#ifndef FACEENGINEGUI_TEXTUREDESIGN_COLOURSCHEME_H
#define FACEENGINEGUI_TEXTUREDESIGN_COLOURSCHEME_H

#include "FaceEngine/Graphics/Colour.h"

namespace FaceEngineGUI::TextureDesign
{
    class ColourScheme
    {
        private:
            // ----- Basic Scheme -----

            FaceEngine::Graphics::Colour _backgroundColour;
            FaceEngine::Graphics::Colour _borderColour;
        
            // ----- Interactive Scheme -----

            FaceEngine::Graphics::Colour _hoveredBackgroundColour;
            FaceEngine::Graphics::Colour _pressedBackgroundColour;
            FaceEngine::Graphics::Colour _hoveredBorderColour;
            FaceEngine::Graphics::Colour _pressedBorderColour;

            // ----- Advanced Interactive Scheme -----

            FaceEngine::Graphics::Colour _scrollbarColour;
            FaceEngine::Graphics::Colour _hoveredScrollbarColour;
            FaceEngine::Graphics::Colour _pressedScrollbarColour;
            FaceEngine::Graphics::Colour _scrollerColour;
            FaceEngine::Graphics::Colour _hoveredScrollerColour;
            FaceEngine::Graphics::Colour _pressedScrollerColour;

            // ----- Text Scheme ----- TODO: rename some of these

            FaceEngine::Graphics::Colour _textColour;
            FaceEngine::Graphics::Colour _inaccessibleTextColour;
            FaceEngine::Graphics::Colour _selectedTextColour;
            FaceEngine::Graphics::Colour _textSelectionBackgroundColour;

            // ----- Inheritance Scheme -----

            ColourScheme* _childColourScheme;

        public:
            ColourScheme();
            ColourScheme(FaceEngine::Graphics::Colour& backgroundColour, FaceEngine::Graphics::Colour& borderColour);
            ~ColourScheme();

            FaceEngine::Graphics::Colour GetBackgroundColour() const;
            FaceEngine::Graphics::Colour GetBorderColour() const;
    };
}

#endif