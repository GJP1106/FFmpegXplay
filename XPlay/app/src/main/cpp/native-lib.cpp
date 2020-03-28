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
    /*IPlayerPorxy::Get()->Open("/sdcard/test.mp4");
    IPlayerPorxy::Get()->Start();*/

    return JNI_VERSION_1_6;
}
extern "C"
JNIEXPORT void JNICALL
Java_xplay_ffmpeg_XPlay_InitView(JNIEnv *env, jobject thiz, jobject surface) {
    // TODO: implement InitView()
    ANativeWindow *win = ANativeWindow_fromSurface(env, surface);
    IPlayerPorxy::Get()->InitView(win);
}extern "C"
JNIEXPORT void JNICALL
Java_xplay_ffmpeg_OpenUrl_Open(JNIEnv *env, jobject thiz, jstring url) {
    // TODO: implement Open()
    const char *openUrl = env->GetStringUTFChars(url, 0);
    IPlayerPorxy::Get()->Open(openUrl);
    IPlayerPorxy::Get()->Start();
    //IPlayerPorxy::Get()->Seek(0.5);
    env->ReleaseStringUTFChars(url,openUrl);
}extern "C"
JNIEXPORT jdouble JNICALL
Java_xplay_ffmpeg_MainActivity_PlayPos(JNIEnv *env, jobject thiz) {
    // TODO: implement PlayPos()
    return IPlayerPorxy::Get()->PlayPos();
}extern "C"
JNIEXPORT void JNICALL
Java_xplay_ffmpeg_MainActivity_Seek(JNIEnv *env, jobject thiz, jdouble pos) {
    // TODO: implement Seek()
    IPlayerPorxy::Get()->Seek(pos);
}