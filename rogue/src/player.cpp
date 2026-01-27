#include "player.hpp"

using namespace blit;

Player::Player(){
    this->size = 4;
    this->x = 0;
    this->y = 0; 
}

void Player::render(uint32_t time, Surface* scr){
    Surface screen = *scr;
    screen.pen = Pen(0, 0, 0);
    screen.clear();

    screen.pen = Pen(255, 255, 255);
    screen.rectangle(Rect(Point(this->x, this->y), Point(this->x+this->size, this->y+this->size)));
    return;
};

void Player::update(u_int32_t time){
    if(buttons & Button::DPAD_RIGHT){
        this->x += this->size;
    } 
    else if (buttons & Button::DPAD_LEFT){
        this->x -= this->size;
        
    }
    else if (buttons & Button::DPAD_UP){
        this->y -= this->size;
        
    }
    else if (buttons & Button::DPAD_DOWN){
        this->y += this->size;
    }
};
