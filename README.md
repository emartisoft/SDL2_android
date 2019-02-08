SDL2_android Base application for start develop C++ OpenGL app

Test it on real phone.

For emulator change ABI: abiFilters 'armeabi-v7a', 'arm64-v8a', 'x86', 'x86_64' in SDL2_android/app/build.gradle 
and APP_ABI := armeabi-v7a arm64-v8a x86 x86_64 in SDL2_android/app/jni/Application.mk

Clean and rebuild project.