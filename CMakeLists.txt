cmake_minimum_required(VERSION 3.22)
project(FaceEngineGUI VERSION 1.0.0 LANGUAGES CXX)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

find_library(zlib 1.2.11 EXACT)
add_subdirectory(${FACEENGINE_DIR} FaceEngine)

add_library(FaceEngineGUI SHARED src/AnimationManager.cpp src/Canvas.cpp src/TransformManager.cpp src/UIComponent.cpp src/Animations/Animation.cpp src/Animations/Transition.cpp src/Components/Button.cpp src/Components/Checkbox.cpp src/Components/Slider.cpp src/Components/Sprite.cpp src/Components/Stepper.cpp src/Components/Dropdown.cpp src/TextureDesign/ColourScheme.cpp src/TextureDesign/NativeTexture.cpp src/TextureDesign/TextureFactory.cpp src/TextureDesign/Fills/LinearGradientFill.cpp src/TextureDesign/Fills/SolidFill.cpp src/Transforms/Scales/PixelScale.cpp src/Transforms/Scales/RelativeScale.cpp src/Transforms/Translations/CentreTranslation.cpp src/Transforms/Translations/PixelTranslation.cpp src/Transforms/Translations/RelativeTranslation.cpp)
add_library(FaceEngineGUIStatic STATIC src/AnimationManager.cpp src/Canvas.cpp src/TransformManager.cpp src/UIComponent.cpp src/Animations/Animation.cpp src/Animations/Transition.cpp src/Components/Button.cpp src/Components/Checkbox.cpp src/Components/Slider.cpp src/Components/Sprite.cpp src/Components/Stepper.cpp src/Components/Dropdown.cpp src/TextureDesign/ColourScheme.cpp src/TextureDesign/NativeTexture.cpp src/TextureDesign/TextureFactory.cpp src/TextureDesign/Fills/LinearGradientFill.cpp src/TextureDesign/Fills/SolidFill.cpp src/Transforms/Scales/PixelScale.cpp src/Transforms/Scales/RelativeScale.cpp src/Transforms/Translations/CentreTranslation.cpp src/Transforms/Translations/PixelTranslation.cpp src/Transforms/Translations/RelativeTranslation.cpp)

target_include_directories(FaceEngineGUI PRIVATE include ${FACEENGINE_DIR}/include ${GLFW_INCLUDE_DIRS} ${ZLIB_INCLUDE_DIRS})
target_include_directories(FaceEngineGUIStatic PRIVATE include ${FACEENGINE_DIR}/include ${GLFW_INCLUDE_DIRS} ${ZLIB_INCLUDE_DIRS})
target_link_libraries(FaceEngineGUI PRIVATE ${ZLIB_LIBRARIES} ${GLFW_LIBRARIES} FaceEngine)
target_link_libraries(FaceEngineGUIStatic PRIVATE ${ZLIB_LIBRARIES} ${GLFW_LIBRARIES} FaceEngine)

set_target_properties(FaceEngineGUI PROPERTIES OUTPUT_NAME FaceEngineGUI)
set_target_properties(FaceEngineGUIStatic PROPERTIES OUTPUT_NAME FaceEngineGUIStatic)