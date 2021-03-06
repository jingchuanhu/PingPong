#ifndef GAME_PINGPONG_INIT_H
#define GAME_PINGPONG_INIT_H

#include <jni.h>
#include <stdlib.h>
#include <string>
#include <stdlib.h>
#include <algorithm>
#include <unistd.h>

#include "Graphic/Objects/Platform/Enemy.h"
#include "Graphic/Objects/Ball/Ball.h"
#include "Graphic/Objects/Platform/Platform.h"
#include "Graphic/Objects/Object.h"
#include "Graphic/Controls/Label.h"
#include "Graphic/Controls/Button.h"
#include "Particles/Particles.h"
#include "Particles/Splash.h"
#include "Particles/Plume.h"
#include "Particles/Shape.h"
#include "Shaders/MakeShaders.h"
#include "Graphic/View.h"
#include "Textures/ManageTexture.h"
#include "Common/Structures.h"
#include "Common/LogGL.h"
#include "Main/State.h"
#include "Sound/OSLSound.h"


class Main {

    public:
        Main(   JNIEnv * _env, jint _width, jint _height, jobject _pngManager, jobject _assetManager) :

                env(_env),
                height(_height),
                width(_width),
                pngManager(_pngManager),
                assetManager(_assetManager),

                SCREEN_COEFFICIENT((float)_width / (float)_height),
                CENTER_ROTATE(3.14f),
                CENTER_SPEED(0.005f),
                CENTER_PERIOD(-3.14f),
                BORDER_UP(0.8f),
                BORDER_DOWN(-0.57f),
                NEGATIVE(-1.0f),
                BUTTON_CONTROL_HEIGHT(0.22f),
                BUTTON_CONTROL_WIDTH(0.7f),
                BUTTON_START_HEIGHT(0.12f),
                BUTTON_START_WIDTH(0.5f),
                PLATFORMS_WIDTH(0.5f),
                PLATFORMS_HEIGHT(0.1f),
                PLATFORMS_SPEED(0.06f),
                BALL_WIDTH(PLATFORMS_WIDTH / 5.0f),
                BALL_HEIGHT(SCREEN_COEFFICIENT * BALL_WIDTH),
                BALL_SPEED(0.02f),
                STOP_MOVE(0.0f),
                LABEL_HEIGHT(0.1f),
                LABEL_WIDTH(0.5f),
                BUTTON_MENU_WIDTH(1.4f),
                BUTTON_MENU_HEIGHT(0.32f),
                BUTTON_MENU_X_POSITION((2.0f - 1.4f) / 2.0f - 1.0f)
        {
            srand(static_cast<unsigned> (time(0)));
            init();
            createObjects();
            gameState = State::MENU;
        }

        ~Main();

        void step();

        GLuint getPolygons(){
            return polygons;
        }

        GLuint getSprites(){
            return sprites;
        }

        Button * getLeft() const {
            return left;
        }

        Button * getRight() const {
            return right;
        }

        Button * getPlayPause() const {
            return playPause;
        }

        Button * getLeftTwo() const {
            return leftTwo;
        }

        Button * getRightTwo() const {
            return rightTwo;
        }

        Button * getPlayPauseTwo() const {
            return playPauseTwo;
        }

        Button * getSingle() const {
            return single;
        }

        Button * getMulti() const {
            return multi;
        }

        Button * getSound() const {
            return sound;
        }

        Button * getExit() const {
            return exit;
        }

        int getWidth() const {
            return width;
        }

        int getHeight() const {
            return height;
        }

        std::vector<Button *> * getAllButtons(){
            return &allButtons;
        }

        void setGameState(const State &gameState) {
            Main::gameState = gameState;
        }

        // For back
        bool backAction();

        GLint getSpritesDelta() const {
            return spritesDelta;
        }

        GLint getSpritesSize() const {
            return spritesSize;
        }

        GLint getSpritesColorStart() const {
            return spritesColorStart;
        }

        GLint getSpritesColorEnd() const {
            return spritesColorEnd;
        }

        GLint getPolygonsTransformationAttr() const {
            return polygonsTransformationAttr;
        }

        GLint getPolygonsTextureAttr() const {
            return polygonsTextureAttr;
        }

        GLint getPolygonsPositionAttr() const {
            return polygonsPositionAttr;
        }

        GLint getSpritesRandomPosition() const {
            return spritesRandomPosition;
        }

        GLint getSpritesRandomSpeed() const {
            return spritesRandomSpeed;
        }

        GLint getSpritesRandomRadius() const {
            return spritesRandomRadius;
        }

        GLint getSpritesTotalDeltaSpeed() const {
            return spritesTotalDeltaSpeed;
        }

    private:
        bool init();
        void setDefault();
        void setMenuButtonsVisibility(bool isVisible);
        void createObjects();
        void renderBackground();

        // For single
        GLfloat * setBordDownPosition(GLfloat * positionCoords, bool isInverse);
        GLfloat * setBordUpPosition(GLfloat * positionCoords);
        void drawFrameForSingle();
        void logicSingle();
        void renderSingleInterface();
        void renderSingleObjects();

        // For multi
        void drawFrameForMulti();
        void logicMulti();
        void renderMultiInterface();
        void renderMultiObjects();

        // For menu
        void drawFrameMenu();
        void logicMenu();
        void lowQuality();
        void highQuality();

        std::vector<Button *> allButtons;
        std::vector<Button *> menuButtons;
        State gameState;

        Matrix * matrix;
        Particles * particles;
        Splash * splashObj;
        Plume * plumeObj;
        Shape * shapeObj;

        // Screen
        int width;
        int height;

        // Java references
        JNIEnv * env;
        jobject pngManager;
        jobject assetManager;

        // Programs
        GLuint polygons;
        GLuint sprites;
        GLuint splash;
        GLuint shape;

        // Polygons
        GLint polygonsPositionAttr;
        GLint polygonsTextureAttr;
        GLint polygonsTransformationAttr;

        // Sprites
        GLint spritesRandomPosition;
        GLint spritesRandomSpeed;
        GLint spritesRandomRadius;
        GLint spritesTotalDeltaSpeed;
        GLint spritesDelta;
        GLint spritesSize;
        GLint spritesColorStart;
        GLint spritesColorEnd;

        // Splash
        GLint splashPosition;
        GLint splashColorStart;
        GLint splashColorEnd;
        GLint splashDelta;
        GLint splashSize;

        // Shape
        GLint shapeAngle;
        GLint shapeColor;
        GLint shapeCenter;
        GLint shapeRadius;
        GLint shapeArguments;
        GLint shapeSize;
        GLint shapeTotalDeltaSpeed;

        // Objects
        // Sound
        OSLSound * soundObj;

        // Common
        View * bordDown;
        View * menuHeader;

        Object * field;
        Ball * ball;
        Button * left;
        Button * playPause;
        Button * right;

        // For single
        Label * singleSpeed;
        Label * singleScoreOne;
        Label * singleScoreTwo;
        View * bordUp;
        Platform * player;
        Platform * playerTwo;
        Enemy * enemy;

        // For multi
        Label * multiScoreOne;
        Label * multiScoreTwo;
        Button * leftTwo;
        Button * playPauseTwo;
        Button * rightTwo;
        View * bordDownTwo;

        // For menu
        Button * single;
        Button * multi;
        Button * sound;
        Button * quality;
        Button * exit;

        ManageTexture * textures;

        const float SCREEN_COEFFICIENT;
        const float CENTER_ROTATE;
        const float CENTER_SPEED;
        const float CENTER_PERIOD;
        const float BORDER_UP;
        const float BORDER_DOWN;
        const float NEGATIVE;
        const float BUTTON_CONTROL_HEIGHT;
        const float BUTTON_CONTROL_WIDTH;
        const float BUTTON_START_HEIGHT;
        const float BUTTON_START_WIDTH;
        const float PLATFORMS_WIDTH;
        const float PLATFORMS_HEIGHT;
        const float PLATFORMS_SPEED;
        const float BALL_WIDTH;
        const float BALL_HEIGHT;
        const float BALL_SPEED;
        const float STOP_MOVE;
        const float LABEL_HEIGHT;
        const float LABEL_WIDTH;
        const float BUTTON_MENU_WIDTH;
        const float BUTTON_MENU_HEIGHT;
        const float BUTTON_MENU_X_POSITION;
};


#endif //GAME_PINGPONG_INIT_H
