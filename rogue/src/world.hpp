#ifndef WORLD_HPP
#define WORLD_HPP
#include "player.hpp"

class World{
    private:
        Player player;

        u_int32_t lastFrameTime = 0; // in ms
        u_int32_t timeElapsed = 0; // in ms
        u_int32_t updateSpan = 100; // in ms

    public:
        World();
        void update(u_int32_t timeFromEpoch);
        void render(u_int32_t timeFromEpoch, blit::Surface* screen);
};

#endif