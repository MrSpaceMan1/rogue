#include "game.hpp"
#include "player.hpp"
#include "world.hpp"

World::World(){
    this->player = Player();
    this->lastFrameTime = 0;
    this->timeElapsed = 0 ;
    this->updateSpan = 100;
};

void World::update(u_int32_t timeFromEpoch){
    u_int32_t timeElapsedLastTick = timeFromEpoch - this->lastFrameTime;
    this->lastFrameTime = timeFromEpoch;
    this->timeElapsed += timeElapsedLastTick;

    if (this->timeElapsed < this->updateSpan){
        return;
    } else {
        this->timeElapsed -= this->updateSpan;
    }

    this->player.update(timeFromEpoch);
};

void World::render(u_int32_t timeFromEpoch, blit::Surface* screen){
    this->player.render(timeFromEpoch, screen);
};