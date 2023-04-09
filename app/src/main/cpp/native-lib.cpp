#include <jni.h>
#include <string>

#include <android/log.h>

#define LOG_TAG    "MyDemo"
#define LOGI(...)  __android_log_print(ANDROID_LOG_INFO, LOG_TAG, __VA_ARGS__)
#define LOGE(...)  __android_log_print(ANDROID_LOG_ERROR, LOG_TAG, __VA_ARGS__)
#define LOGD(...)  __android_log_print(ANDROID_LOG_INFO, LOG_TAG, __VA_ARGS__)

extern
"C"
JNIEXPORT
jstring
JNICALL
//方法名字：Java+包名+类名+方法名
Java_com_yalemang_jnistudy_basic_JniBasicActivity_stringFromJNI(
        JNIEnv* env,
        jobject /* this */) {
    std::string hello = "Hello from C++";
    return env->NewStringUTF(hello.c_str());
}

extern
"C"
JNIEXPORT
void
JNICALL
//方法名字：Java+包名+类名+方法名
Java_com_yalemang_jnistudy_basic_JniBasicActivity_changeAge(
        JNIEnv* env,
        jobject /* this */jniBasicActivityObj) {
    jclass jniBasicActivityClass = env->GetObjectClass(jniBasicActivityObj);
    jfieldID ageField = env->GetFieldID(jniBasicActivityClass,"age","I");
    env->SetIntField(jniBasicActivityObj,ageField,5);
}

extern
"C"
JNIEXPORT
void
JNICALL
//方法名字：Java+包名+类名+方法名
Java_com_yalemang_jnistudy_basic_JniBasicActivity_callFromNative(
        JNIEnv* env,
        jobject /* this */jniBasicActivityObj, jstring method_name) {
    jclass jniBasicActivityClass = env->GetObjectClass(jniBasicActivityObj);
    char* methodName = (char*)env->GetStringUTFChars(method_name,0);
    jmethodID callByNative = env->GetMethodID(jniBasicActivityClass,methodName,"()I");
    int  result = env->CallIntMethod(jniBasicActivityObj,callByNative);
    LOGD("Ellen2020->Native调用Java方法返回值:%d",result);
}