#ifndef _GAMEFPS_H_
    #define _GAMEFPS_H_

#include <SDL.h>

class GameFps
{
    public:
        static GameFps FpsControl;
        static const int ONE_SECOND = 1000;
        static const int MOVEMENT_RATE = 32.0f;
    
    private:
        int oldTime;
        int lastTime;
    
        int numberOfFrames;
        int framesThisSecond;
    
    private:
        float speedFactor;
    
    public:
        GameFps();
    
    public:
        void Update();
    
    public:
        int GetFps();
        float GetSpeedFactor();

};

#endif