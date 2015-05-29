LOCAL_PATH := $(call my-dir)

include $(CLEAR_VARS)

LOCAL_MODULE := cocos2dcpp_shared

LOCAL_MODULE_FILENAME := libcocos2dcpp

LOCAL_SRC_FILES := hellocpp/main.cpp \
                   ../../Classes/AppDelegate.cpp \
                   ../../Classes/gameScene.cpp \
                   ../../Classes/MyBodyParser.cpp \
                   ../../Classes/Watermelon.cpp \
                   ../../Classes/ACutSprite.cpp \
                   ../../Classes/BookItem.cpp \
                   ../../Classes/Bag.cpp \
                   ../../Classes/Candy.cpp \
                   ../../Classes/Cat.cpp \
                   ../../Classes/Gummy.cpp \
                   ../../Classes/Pen.cpp \
                   ../../Classes/Potatoes.cpp \
                   ../../Classes/StudentBoy.cpp \
                   ../../Classes/StudentGirl.cpp \
                   ../../Classes/Teacher.cpp
				   
LOCAL_C_INCLUDES := $(LOCAL_PATH)/../../Classes

LOCAL_WHOLE_STATIC_LIBRARIES := cocos2dx_static
LOCAL_WHOLE_STATIC_LIBRARIES += cocosdenshion_static
LOCAL_WHOLE_STATIC_LIBRARIES += box2d_static


include $(BUILD_SHARED_LIBRARY)

$(call import-module,2d)
$(call import-module,audio/android)
$(call import-module,Box2D)
