#include <jni.h>
#include <string>
#include "XLog.h"
#include <android/native_window_jni.h>
#include "IPlayerPorxy.h"

extern "C"
JNIEXPORT
jint JNI_OnLoad(JavaVM *vm, void *res)
{
    IPlayerPorxy::Get()->Init(vm);
    IPlayerPorxy::Get()->Open("/sdcard/test.mp4");
    IPlayerPorxy::Get()->Start();
    return JNI_VERSION_1_6;
}
extern "C" JNIEXPORT jstring JNICALL
Java_xplay_ffmpeg_MainActivity_stringFromJNI(
        JNIEnv* env,
        jobject /* this */) {
    std::string hello = "Hello from C++";
    //IPlayerPorxy::Get()->Open("/sdcard/test.mp4");
    //IPlayerPorxy::Get()->Start();
    return env->NewStringUTF(hello.c_str());
}
extern "C"
JNIEXPORT void JNICALL
Java_xplay_ffmpeg_XPlay_InitView(JNIEnv *env, jobject thiz, jobject surface) {
    // TODO: implement InitView()
    ANativeWindow *win = ANativeWindow_fromSurface(env, surface);
    IPlayerPorxy::Get()->InitView(win);
}