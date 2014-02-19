
#ifndef _GAMEANIMATION_H_
    #define _GAMEANIMATION_H_

#include <SDL.h>

class GameAnimation
{
    private:
        int currentFrame;
        int framesIncremented;
    
    private:
        int frameRate;
        long timeAtLastCycle;
    
    private:
        int maxFrames;
    
    public:
        GameAnimation();
        void Animate();
    
    public:
        void SetFrameRate(int);
        int GetFrameRate();
    
        void SetCurrentFrame(int);
        int GetCurrentFrame();
    
        void SetMaxFramesInAnimation(int);
        int GetMaxFramesInAnimation();
};


#endif
