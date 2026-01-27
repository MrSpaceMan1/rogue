#ifndef PLAYER_HPP
#define PLAYER_HPP
#include <stdlib.h>
#include "game.hpp"
#include "32blit.hpp"

class Player {
    private:
        u_int8_t size;
        u_int32_t x, y;

    public:
        Player();
        void render(uint32_t time, blit::Surface* scr);
        void update(uint32_t time);
};

#endif