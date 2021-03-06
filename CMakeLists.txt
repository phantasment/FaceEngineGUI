cmake_minimum_required(VERSION 3.22)
project(FaceEngineGUI VERSION 1.0.0 LANGUAGES CXX)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

find_package(ZLIB 1.2.12 EXACT REQUIRED)
find_package(glfw3 3.3 REQUIRED)

if (NOT DEFINED FACEENGINE_INCLUDE_DIRS OR NOT DEFINED FACEENGINE_LIBRARIES)
    find_package(FaceEngine 1.0.0 REQUIRED)
endif()

set(FACE_ENGINE_GUI_SRC_FILES
    src/AnimationManager.cpp
    src/Canvas.cpp
    src/TransformManager.cpp
    src/UIComponent.cpp

    src/Animations/Animation.cpp
    src/Animations/Transition.cpp

    src/Components/Button.cpp
    src/Components/Checkbox.cpp
    src/Components/Dropdown.cpp
    src/Components/DialogBox.cpp
    src/Components/Label.cpp
    src/Components/Textbox.cpp
    src/Components/Slider.cpp
    src/Components/Sprite.cpp
    src/Components/Stepper.cpp

    src/TextureDesign/ColourScheme.cpp
    src/TextureDesign/NativeTexture.cpp
    src/TextureDesign/TextureFactory.cpp

    src/TextureDesign/Fills/LinearGradientFill.cpp
    src/TextureDesign/Fills/SolidFill.cpp

    src/Transforms/Scales/PixelScale.cpp
    src/Transforms/Scales/RelativeScale.cpp

    src/Transforms/Translations/CentreTranslation.cpp
    src/Transforms/Translations/PixelTranslation.cpp
    src/Transforms/Translations/RelativeTranslation.cpp
)

add_library(FaceEngineGUI SHARED ${FACE_ENGINE_GUI_SRC_FILES})
target_compile_options(FaceEngineGUI PRIVATE -O3)
add_library(FaceEngineGUIStatic STATIC ${FACE_ENGINE_GUI_SRC_FILES})
target_compile_options(FaceEngineGUIStatic PRIVATE -O3)

target_include_directories(FaceEngineGUI PRIVATE include "${GLFW_INCLUDE_DIRS}" "${ZLIB_INCLUDE_DIRS}" "${FACEENGINE_INCLUDE_DIRS}")
target_include_directories(FaceEngineGUIStatic PRIVATE include "${GLFW_INCLUDE_DIRS}" "${ZLIB_INCLUDE_DIRS}" "${FACEENGINE_INCLUDE_DIRS}")
target_link_libraries(FaceEngineGUI PRIVATE "${FACEENGINE_LIBRARIES}" "${ZLIB_LIBRARIES}" glfw)
target_link_libraries(FaceEngineGUIStatic PRIVATE "${FACEENGINE_LIBRARIES}" "${ZLIB_LIBRARIES}" glfw)

set_target_properties(FaceEngineGUI PROPERTIES OUTPUT_NAME FaceEngineGUI)
set_target_properties(FaceEngineGUIStatic PROPERTIES OUTPUT_NAME FaceEngineGUIStatic)