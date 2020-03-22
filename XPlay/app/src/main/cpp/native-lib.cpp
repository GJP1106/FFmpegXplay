#include <jni.h>
#include <string>
#include "FFDemux.h"
#include "XLog.h"
#include "FFDecode.h"
#include "XEGL.h"
#include "XShader.h"
#include <android/native_window_jni.h>


class TestObs:public IObserver
{
public:
    void Update(XData d) {
        //XLOGI("TestObs Update data size is %d",d.size);
    }
};

extern "C" JNIEXPORT jstring JNICALL
Java_xplay_ffmpeg_MainActivity_stringFromJNI(
        JNIEnv* env,
        jobject /* this */) {
    std::string hello = "Hello from C++";
    ////////////////////////////////
    //测试用代码
    TestObs *tobs = new TestObs();
    IDemux *de = new FFDemux();
    //de->AddObs(tobs);
    de->Open("/sdcard/test.mp4");

    IDecode *vdecode = new FFDecode();
    vdecode->Open(de->GetVPara());

    IDecode *adecode = new FFDecode();
    adecode->Open(de->GetApara());
    de->AddObs(vdecode);
    de->AddObs(adecode);
    de->Start();
    vdecode->Start();
    adecode->Start();

    //XSleep(3000);
    //de->Stop();
    /*for(;;) {
        XData d = de->Read();
        XLOGI("Read data size is %d", d.size);
    }*/
    return env->NewStringUTF(hello.c_str());
}
extern "C"
JNIEXPORT void JNICALL
Java_xplay_ffmpeg_XPlay_InitView(JNIEnv *env, jobject thiz, jobject surface) {
    // TODO: implement InitView()
    ANativeWindow *win = ANativeWindow_fromSurface(env, surface);
    XEGL::Get()->Init(win);
    XShader shader;
    shader.Init();
}