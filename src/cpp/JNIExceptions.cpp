#include "JNIExceptions.h"

jint throwNoClassDefError( JNIEnv *env, char *message )
{
    jclass exClass;
    char *className = "java/lang/NoClassDefFoundError";

    exClass = env->FindClass( className);
    if (exClass == NULL) {
       //Make JVM crash...
       return throwNoClassDefError( env, className );
    }

    return env->ThrowNew( exClass, message );
}

jint throwAparapiJNIRuntimeException( JNIEnv *env, std::string message ) {
   return throwAparapiJNIRuntimeException(env, (const char *)message.c_str());
}

jint throwAparapiJNIRuntimeException( JNIEnv *env, const char *message )
{
    jclass exClass;
    char *className = "com/aparapi/exception/AparapiJNIException";

    exClass = env->FindClass( className );
    if (exClass == NULL) {
        return throwNoClassDefError( env, className );
    }

    return env->ThrowNew( exClass, message );
}
