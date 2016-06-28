#include "FaceBeautify.h"

#include <jni.h>
#include <stdlib.h>

#include "AgoraYuvEnhancer.h"

extern "C" {

static AgoraYuvEnhancer *_enhancer = NULL;

JNIEXPORT jint JNICALL Java_io_agora_external_FaceBeautify_doStartFB(
    JNIEnv *,
    jobject)
{
    if (_enhancer != NULL)
        return -1;

    _enhancer = new AgoraYuvEnhancer;
    AgoraYuvPreProcessor::RegisterToEngine(_enhancer);

    return 0;
}

JNIEXPORT jint JNICALL Java_io_agora_external_FaceBeautify_doStopFB(
    JNIEnv *,
    jobject)
{
    if (_enhancer == NULL)
        return 0;

    AgoraYuvPreProcessor::RegisterToEngine(NULL);
    delete _enhancer;
    _enhancer = NULL;

    return 0;
}

JNIEXPORT jint JNICALL Java_io_agora_external_FaceBeautify_doSetLighteningFactor(
    JNIEnv *env,
    jobject obj,
    jfloat factor)
{
    if (_enhancer == NULL)
        return -1;

    _enhancer->SetLighteningFactor(factor);

    return 0;
}

JNIEXPORT jint JNICALL Java_io_agora_external_FaceBeautify_doSetSmoothnessFactor(
    JNIEnv *env,
    jobject obj,
    jint factor)
{
    if (_enhancer == NULL)
        return -1;

    _enhancer->SetSmoothnessFactor(factor);

    return 0;
}

}
