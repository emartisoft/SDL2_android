LOCAL_PATH := $(call my-dir)

include $(CLEAR_VARS)

LOCAL_MODULE := main

#path to /include files written in each Android.mk file in each subdirs
#LOCAL_C_INCLUDES := $(LOCAL_PATH)/$(SDL_PATH)/include ....... ....... .......

LOCAL_C_INCLUDES := $(LOCAL_PATH)/../glm/
LOCAL_C_INCLUDES += $(LOCAL_PATH)/../freetype/include/

#Application source files here:
LOCAL_SRC_FILES :=      \
            main.cpp    \
            Game.cpp    \
            EventHandler.cpp    \
            PlayState.cpp   \
            GameStateMachine.cpp    \
            GameControlObject.cpp   \
            TextureManager.cpp  \
            ForShaders.cpp  \
            CubeExample.cpp \
            TerritoryExample.cpp

LOCAL_SHARED_LIBRARIES := SDL2 SDL2_image SDL2_mixer freetype

LOCAL_LDLIBS := -lGLESv2 -llog


include $(BUILD_SHARED_LIBRARY)

