@ECHO OFF
g++ -Wall -std=c++17 -O2 -c src/*.cpp src/Components/*.cpp src/Transforms/Scales/*.cpp src/Transforms/Translations/*.cpp src/TextureDesign/*.cpp src/TextureDesign/Fills/*.cpp -I"include" -I"C:\lib\glfw-3.3.5\include" -I"C:\lib\zlib-1.2.11" -I"C:\lib\zlib-1.2.11\cmake-build-release" -I"C:\Users\Ryan\Desktop\Files\Projects\Programming\FaceEngine\include"
mv *.o build-win64/
ar rvs build-win64/libFaceEngineGUI.a build-win64/*.o