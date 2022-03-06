#ifndef FACEENGINEGUI_UTIL_TYPINGSESSION_H
#define FACEENGINEGUI_UTIL_TYPINGSESSION_H

#include <map>
#include <string>
#include "FaceEngine/GameUpdate.h"

namespace FaceEngineGUI::Util
{
    class TypingSession
    {   
    private:
        std::string _text;
        int _insertPosition;

        char GetChar(FaceEngine::TypedKey typedKey);
        void AddChar(char character);

        void Backspace(const bool ctrl);
        void Delete(const bool ctrl);
        void ShiftLeft(const bool ctrl);
        void ShiftRight(const bool ctrl);
    
    public:
        TypingSession();
        ~TypingSession();

        void Update(FaceEngine::GameUpdate* gameUpdate);

        std::string GetText() const;
        int GetInsertPosition() const;

        void SetInsertPosition(int insertPosition);
    };
}

#endif