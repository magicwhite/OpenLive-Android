TOP_LOCAL_PATH := $(call my-dir)

LOCAL_PATH := $(TOP_LOCAL_PATH)/src
include $(CLEAR_VARS)

# This is the target being built.
LOCAL_MODULE := FaceBeautify

# All of the source files that we will compile.
LOCAL_SRC_FILES := \
	FaceBeautifyWrapper.cc

# The JNI headers
LOCAL_C_INCLUDES += \
	$(TOP_LOCAL_PATH)/include \

LOCAL_CFLAGS += -fvisibility=hidden
LOCAL_CPPFLAGS += -fvisibility=hidden

LOCAL_MODULE_TAGS := optional

LOCAL_LDFLAGS := -L$(LOCAL_PATH)/../../../../libs/$(TARGET_ARCH_ABI)/

LOCAL_LDLIBS += -lvideoprp

include $(BUILD_SHARED_LIBRARY)
