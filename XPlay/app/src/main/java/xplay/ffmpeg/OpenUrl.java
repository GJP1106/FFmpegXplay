package xplay.ffmpeg;

import android.Manifest;
import android.content.pm.ActivityInfo;
import android.content.pm.PackageManager;
import android.os.Build;
import android.os.Bundle;
import android.util.Log;
import android.view.View;
import android.view.Window;
import android.view.WindowManager;
import android.widget.Button;
import android.widget.EditText;

import androidx.appcompat.app.AppCompatActivity;
import androidx.core.app.ActivityCompat;


public class OpenUrl extends AppCompatActivity {
    private Button btfile;
    private Button btrtmp;
    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.openurl);
        btfile = findViewById(R.id.playvideo);
        btfile.setOnClickListener(
                new View.OnClickListener() {
                    @Override
                    public void onClick(View view) {
                        EditText t = findViewById( R.id.fileurl );
                        //用户输入的URL，打开视频
                        Log.e("XPlay","Open URL");
                        Open(t.getText().toString());

                        //关闭当前窗口
                        finish();
                    }
                }
        );

        btrtmp = findViewById( R.id.playrtmp );
        btrtmp.setOnClickListener(
                new View.OnClickListener() {
                    @Override
                    public void onClick(View view) {
                        EditText t = findViewById( R.id.rtmpurl );
                        //用户输入的URL，打开视频
                        Open(t.getText().toString());

                        //关闭当前窗口
                        finish();
                    }
                }
        );

    }

    public native void Open(String url);
}
