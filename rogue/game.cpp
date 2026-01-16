#include "game.hpp"

using namespace blit;

///////////////////////////////////////////////////////////////////////////
//
// init()
//
// setup your game here
//


class Player {
    u_int8_t size = 4;
    u_int32_t x, y = 0;
    u_int32_t lastFrameTime = 0; // in ms
    u_int32_t timeElapsed = 0; // in ms
    u_int32_t updateSpan = 100; // in ms

    public:
        void render(uint32_t time, Surface* scr);
        void update(uint32_t time);
};

void Player::render(uint32_t time, Surface* scr){
    Surface screen = *scr;
    screen.pen = Pen(0, 0, 0);
    screen.clear();

    screen.pen = Pen(255, 255, 255);
    screen.rectangle(Rect(Point(this->x, this->y), Point(this->x+this->size, this->y+this->size)));
    return;
};

void Player::update(u_int32_t time){
    u_int32_t timeElapsedLastTick = time - this->lastFrameTime;
    this->lastFrameTime = time;
    this->timeElapsed += timeElapsedLastTick;

    if (this->timeElapsed < this->updateSpan){
        return;
    } else {
        this->timeElapsed -= this->updateSpan;
    }

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

Player globalPlayer = Player();
void init() {
    set_screen_mode(ScreenMode::hires);
}

///////////////////////////////////////////////////////////////////////////
//
// render(time)
//
// This function is called to perform rendering of the game. time is the 
// amount if milliseconds elapsed since the start of your game
//
void render(uint32_t time) {

    // clear the screen -- screen is a reference to the frame buffer and can be used to draw all things with the 32blit
    // screen.clear();

    // draw some text at the top of the screen
    // screen.alpha = 255;
    // screen.mask = nullptr;
    // screen.pen = Pen(255, 255, 255);
    // screen.rectangle(Rect(0, 0, 320, 14));
    // screen.pen = Pen(0, 0, 0);
    // screen.text("Hello 32blit!", minimal_font, Point(5, 4));

    globalPlayer.render(time, &screen);

}

///////////////////////////////////////////////////////////////////////////
//
// update(time)
//
// This is called to update your game state. time is the 
// amount if milliseconds elapsed since the start of your game
//
void update(uint32_t time) {
    globalPlayer.update(time);
}