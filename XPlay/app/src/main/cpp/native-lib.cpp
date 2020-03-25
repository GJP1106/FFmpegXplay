#include <jni.h>
#include <string>
#include "XLog.h"
#include <android/native_window_jni.h>
#include "FFPlayerBuilder.h"

static IPlayer *player = NULL;

extern "C"
JNIEXPORT
jint JNI_OnLoad(JavaVM *vm, void *res)
{
    //FFDecode::InitHard(vm);
    FFPlayerBuilder::InitHard(vm);
    ////////////////////////////////

    player = FFPlayerBuilder::Get()->BuilderPlayer();
    player->Open("/sdcard/test.mp4");
    player->Start();

    //de->Start();
    //vdecode->Start();
    //adecode->Start();
    return JNI_VERSION_1_6;
}




extern "C" JNIEXPORT jstring JNICALL
Java_xplay_ffmpeg_MainActivity_stringFromJNI(
        JNIEnv* env,
        jobject /* this */) {
    std::string hello = "Hello from C++";
    /*player = FFPlayerBuilder::Get()->BuilderPlayer();
    player->Open("/sdcard/test.mp4");
    player->Start();*/
#if 0
    //测试用代码

    //TestObs *tobs = new TestObs();
    IDemux *de = new FFDemux();
    //de->AddObs(tobs);
    //de->Open("/sdcard/test.mp4");

    IDecode *vdecode = new FFDecode();
    //vdecode->Open(de->GetVPara(), false);

    IDecode *adecode = new FFDecode();
    //adecode->Open(de->GetApara());
    de->AddObs(vdecode);
    de->AddObs(adecode);

    view = new GLVideoView();
    vdecode->AddObs(view);

    IResample *resample = new FFResample();
    //XParameter outPara = de->GetApara();
    //resample->Open(de->GetApara(),outPara);
    adecode->AddObs(resample);

    IAudioPlay *audioPlay = new SLAudioPlay();
    //audioPlay->StartPlay(outPara);
    resample->AddObs(audioPlay);
    IPlayer::Get()->demux = de;
    IPlayer::Get()->adecode = adecode;
    IPlayer::Get()->vdecode = vdecode;
    IPlayer::Get()->resample = resample;
    IPlayer::Get()->videoView = view;
    IPlayer::Get()->audioPlay = audioPlay;
    IPlayer::Get()->Open("/sdcard/test.mp4");
    IPlayer::Get()->Start();
#endif
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
    if(player) {
        player->InitView(win);
    }
    //IPlayer::Get()->InitView(win);
    //view->SetRender(win);
    //XEGL::Get()->Init(win);
    //XShader shader;
    //shader.Init();
}