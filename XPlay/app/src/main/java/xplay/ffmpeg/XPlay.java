package xplay.ffmpeg;

import android.content.Context;
import android.opengl.GLSurfaceView;
import android.util.AttributeSet;
import android.view.SurfaceHolder;
import android.view.View;

import javax.microedition.khronos.egl.EGLConfig;
import javax.microedition.khronos.opengles.GL10;

public class XPlay extends GLSurfaceView implements SurfaceHolder.Callback, GLSurfaceView.Renderer, View.OnClickListener{
    public XPlay(Context context, AttributeSet attrs) {
        super(context, attrs);
        //android8.0以上需要设置
        setRenderer(this);
        setOnClickListener(this);
    }

    @Override
    public void surfaceCreated(SurfaceHolder holder) {
        //初始化opengl egl显示
        InitView(holder.getSurface());

    }

    @Override
    public void surfaceChanged(SurfaceHolder holder, int format, int width,
                               int height){}
    @Override
    public void surfaceDestroyed(SurfaceHolder holder){}

    public native void InitView(Object surface);

    @Override
    public void onSurfaceCreated(GL10 gl, EGLConfig config) {

    }

    @Override
    public void onSurfaceChanged(GL10 gl, int width, int height) {

    }

    @Override
    public void onDrawFrame(GL10 gl) {

    }
    @Override
    public void onClick(View v) {
        PlayOrPause();
    }
    public native void PlayOrPause();
}
