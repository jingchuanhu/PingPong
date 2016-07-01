#include <jni.h>
#include <Common/Intersect.h>
#include "Main/Main.h"
#include "Common/Methods.h"

Main * game;


extern "C" {

    JNIEXPORT void JNICALL Java_ru_simpleapps_game_GameLib_init(JNIEnv* env, jobject obj, jint width, jint height, jobject pngManager, jobject assetManager){
        GLfloat * line1 = new GLfloat[4];
        line1[0] = 0.0f;
        line1[1] = 0.0f;
        line1[2] = 0.5f;
        line1[3] = 0.5f;

        GLfloat * line2 = new GLfloat[4];
        line2[0] = 0.0f;
        line2[1] = 0.5f;
        line2[2] = 0.5f;
        line2[3] = 0.0f;

        GLfloat * point = new GLfloat[2];

        bool isIntersect = Line::intersect(line1, line2, point);
//        game = new Main(env, width, height, pngManager, assetManager);
    }

    JNIEXPORT void JNICALL Java_ru_simpleapps_game_GameLib_step(JNIEnv* env, jobject obj){
//        game->step();
    }

    JNIEXPORT void JNICALL Java_ru_simpleapps_game_GameLib_action(JNIEnv* env, jobject obj, jfloat x, jfloat y, jboolean press){
//        game->getLeft()->action(Methods::convertCoordinatesToOpenGL(false, game->getWidth(), x),
//                                Methods::convertCoordinatesToOpenGL(true, game->getHeight(), y));
//
//        game->getRight()->action(Methods::convertCoordinatesToOpenGL(false, game->getWidth(), x),
//                                 Methods::convertCoordinatesToOpenGL(true, game->getHeight(), y));
//
//        if(press)
//            game->getPlayPause()->action(Methods::convertCoordinatesToOpenGL(false, game->getWidth(), x),
//                                         Methods::convertCoordinatesToOpenGL(true, game->getHeight(), y));
    }

    JNIEXPORT void JNICALL Java_ru_simpleapps_game_GameLib_pause(JNIEnv* env, jobject obj){

    }

    JNIEXPORT void JNICALL Java_ru_simpleapps_game_GameLib_stop(JNIEnv* env, jobject obj){

    }
}
