package xplay.ffmpeg;

import androidx.appcompat.app.AppCompatActivity;
import androidx.core.app.ActivityCompat;

import android.Manifest;
import android.content.Intent;
import android.content.pm.ActivityInfo;
import android.content.pm.PackageManager;
import android.os.Build;
import android.os.Bundle;
import android.view.View;
import android.view.Window;
import android.view.WindowManager;
import android.util.Log;
import android.widget.Button;
import android.widget.SeekBar;
import android.widget.TextView;

public class MainActivity extends AppCompatActivity implements Runnable,SeekBar.OnSeekBarChangeListener{

    // Used to load the 'native-lib' library on application startup.
    static {
        System.loadLibrary("native-lib");
    }
    private Button bt;
    private SeekBar seek;
    private Thread th;
    //add Android9.0 读写权限问题
    private static String[] PERMISSIONS_STORAGE = {
            Manifest.permission.READ_EXTERNAL_STORAGE,
            Manifest.permission.WRITE_EXTERNAL_STORAGE
    };
    private static int REQUEST_PERMISSION_CODE = 1;

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);

        //去掉标题栏
        supportRequestWindowFeature( Window.FEATURE_NO_TITLE);
        //全屏，隐藏状态
        getWindow().setFlags( WindowManager.LayoutParams.FLAG_FULLSCREEN ,
                WindowManager.LayoutParams.FLAG_FULLSCREEN
        );
        //屏幕为横屏
        setRequestedOrientation( ActivityInfo.SCREEN_ORIENTATION_LANDSCAPE );


        setContentView(R.layout.activity_main);

        bt = findViewById(R.id.open_button);
        seek = findViewById(R.id.aplayseek);
        seek.setMax(1000);;
        seek.setOnSeekBarChangeListener(this);
        bt.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View v) {
                Log.e("XPlay ","open button click!");
                //打开路径选择窗口
                Intent intent = new Intent();
                Log.e("XPlay ","open button click1!");
                intent.setClass(MainActivity.this, OpenUrl.class);
                Log.e("XPlay ","open button click2!");
                startActivity(intent);
                Log.e("XPlay ","open button click3!");
            }
        });
        //启动播放进度线程
        th = new Thread(this);
        th.start();
        //add Android9.0 读写权限问题
        if(Build.VERSION.SDK_INT > Build.VERSION_CODES.LOLLIPOP) {
            if(ActivityCompat.checkSelfPermission(this, Manifest.permission.WRITE_EXTERNAL_STORAGE) != PackageManager.PERMISSION_GRANTED) {
                ActivityCompat.requestPermissions(this,PERMISSIONS_STORAGE, REQUEST_PERMISSION_CODE);
            }
        }
    }

    //播放进度显示
    @Override
    public void run() {
        for(;;)
        {
            seek.setProgress((int)(PlayPos()*1000));
            try {
                Thread.sleep( 40 );
            } catch (InterruptedException e) {
                e.printStackTrace();
            }
        }
    }
    public native double PlayPos();
    public native void Seek(double pos);

    @Override
    public void onProgressChanged(SeekBar seekBar, int i, boolean b) {

    }

    @Override
    public void onStartTrackingTouch(SeekBar seekBar) {

    }

    @Override
    public void onStopTrackingTouch(SeekBar seekBar) {
        Seek( (double)seekBar.getProgress()/(double)seekBar.getMax() );
    }
    //add Android9.0 读写权限问题
    @Override
    public void onRequestPermissionsResult(int requestCode, String[] permissions, int[] grantResults) {
        super.onRequestPermissionsResult(requestCode, permissions, grantResults);
        if(requestCode == REQUEST_PERMISSION_CODE) {
            for(int i = 0; i < permissions.length; i++) {
                Log.i("MainActivity", "申请的权限为:" + permissions[i] + "申请结果:" +grantResults[i]);
            }
        }
    }

}
