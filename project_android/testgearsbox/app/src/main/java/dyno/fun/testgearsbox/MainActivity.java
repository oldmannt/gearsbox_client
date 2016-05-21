package dyno.fun.testgearsbox;

import android.os.Handler;
import android.os.Looper;
import android.os.Message;
import android.support.v7.app.AppCompatActivity;
import android.os.Bundle;
import android.util.Log;
import android.view.KeyEvent;
import android.widget.TextView;

import java.util.Timer;
import java.util.TimerTask;

import dyno.fun.gearsbox.AsyncLoopGen;
import dyno.fun.gearsbox.CallbackHttpGen;
import dyno.fun.gearsbox.HttpRequestGen;
import dyno.fun.gearsbox.LogGen;

public class MainActivity extends AppCompatActivity {

    static {
        System.loadLibrary("gearsbox_jni");
    }

class CallbackHttp extends CallbackHttpGen{

    @Override
    public boolean callback(long id, boolean result, String data) {

        LogGen.instance().log(LogGen.LOG_CONSOLE, LogGen.LOG_INFO, data);
        TextView tv = (TextView)findViewById(R.id.hello);
        tv.setText(data);
        return false;
    }
}
    private CallbackHttp http_callback;
    private Timer m_timer;
    private Handler s_handler = null;
    private Runnable m_net_looper = null;

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);

        LogGen.instance().log(LogGen.LOG_CONSOLE, LogGen.LOG_INFO, String.format("onCreate enter"));

        s_handler = new Handler(){
            private long last = System.currentTimeMillis();
            public void handleMessage( Message msg ) {
                switch (msg.what){
                    case 999:{
                        long current = System.currentTimeMillis();
                        //Log.i("test", String.format("timer run elapse %d", current-last));
                        LogGen.instance().log(LogGen.LOG_CONSOLE, LogGen.LOG_INFO, String.format("timer run elapse %d", current-last));
                        AsyncLoopGen.instance().process(current-last);
                        last = current;
                    }
                    default:
                        break;
                }// end switch
            }
        };


        m_net_looper = new Runnable() {
            private long last = System.currentTimeMillis();
            @Override
            public void run() {
                long current = System.currentTimeMillis();
                //Log.i("test", String.format("timer run elapse %d", current-last));
                LogGen.instance().log(LogGen.LOG_CONSOLE, LogGen.LOG_INFO, String.format("timer run elapse %d", current-last));
                AsyncLoopGen.instance().process(current-last);
                last = current;
            }
        };

        m_timer = new Timer();
        m_timer.schedule(new TimerTask() {

            public void run() {
                //s_handler.sendEmptyMessage(999);

                s_handler.post(m_net_looper);
            }
        }, 0, 1000);

        http_callback = new CallbackHttp();
        HttpRequestGen.create().get("http://www.google.com",
                                    http_callback);

        LogGen.instance().log(LogGen.LOG_CONSOLE, LogGen.LOG_INFO, String.format("onCreate done"));
        Log.i("test", String.format("onCreate done"));
    }


    public boolean onKeyDown (int keyCode, KeyEvent event) {
        switch (keyCode) {
            case KeyEvent.KEYCODE_VOLUME_DOWN:{

            }
            return true;
            case KeyEvent.KEYCODE_VOLUME_UP:{

            }
            return true;
            case KeyEvent.KEYCODE_BACK:{
                System.exit(0);
            }
            return true;
        }

        return super.onKeyDown (keyCode, event);
    }
}
