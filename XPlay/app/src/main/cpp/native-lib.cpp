#include <jni.h>
#include <string>
#include "FFDemux.h"

extern "C" JNIEXPORT jstring JNICALL
Java_xplay_ffmpeg_MainActivity_stringFromJNI(
        JNIEnv* env,
        jobject /* this */) {
    std::string hello = "Hello from C++";
    ////////////////////////////////
    //测试用代码
    IDemux *de = new FFDemux();
    de->Open("/sdcard/test.mp4");
    for(;;) {
        XData d = de->Read();
    }
    return env->NewStringUTF(hello.c_str());
}
