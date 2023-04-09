package com.yalemang.jnistudy.basic

import android.os.Bundle
import android.util.Log
import androidx.appcompat.app.AppCompatActivity
import com.yalemang.jnistudy.databinding.ActivityJniBasicBinding

class JniBasicActivity : AppCompatActivity(){

    private lateinit var jniBasicBinding:ActivityJniBasicBinding
    var age:Int = 29

    override fun onCreate(savedInstanceState: Bundle?) {
        super.onCreate(savedInstanceState)
        jniBasicBinding = ActivityJniBasicBinding.inflate(layoutInflater)
        setContentView(jniBasicBinding.root)
        val jniString = stringFromJNI()
        Log.d("Ellen2020","JNI 字符串是:${jniString}")
        jniBasicBinding.sampleText.text = jniString

        Log.d("Ellen2020","JNI修改age前的值age=${age}")
        changeAge()
        Log.d("Ellen2020","JNI修改age后的值age=${age}")

        //让Native调用上层方法
        callFromNative("callByNative3")
    }

    fun callByNative():Int{
        Log.d("Ellen2020","callByNaive方法被Native调用了")
        return 3
    }

    fun callByNative2():Int{
        Log.d("Ellen2020","callByNaive2方法被Native调用了")
        return 5
    }

    fun callByNative3(intValue:Int):Int{
        Log.d("Ellen2020","callByNaive2方法被Native调用了")
        return intValue
    }

    //从Native获取一个字符串
    external fun stringFromJNI(): String

    //Native修改age
    external fun changeAge()

    external fun callFromNative(methodName:String)

    companion object {
        // Used to load the 'jnistudy' library on application startup.
        init {
            System.loadLibrary("jnistudy")
        }
    }
}