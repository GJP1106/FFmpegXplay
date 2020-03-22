#include <jni.h>
#include <string>
#include "FFDemux.h"
#include "XLog.h"
#include "FFDecode.h"

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
    de->AddObs(tobs);
    de->Open("/sdcard/test.mp4");

    IDecode *vdecode = new FFDecode();
    vdecode->Open(de->GetVPara());
    de->Start();
    XSleep(3000);
    de->Stop();
    /*for(;;) {
        XData d = de->Read();
        XLOGI("Read data size is %d", d.size);
    }*/
    return env->NewStringUTF(hello.c_str());
}
