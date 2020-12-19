// MIT License
//
// Copyright (c) 2020 Lars Toenning
//
// Permission is hereby granted, free of charge, to any person obtaining a copy
//        of this software and associated documentation files (the "Software"), to deal
// in the Software without restriction, including without limitation the rights
//        to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
//        copies of the Software, and to permit persons to whom the Software is
// furnished to do so, subject to the following conditions:
//
// The above copyright notice and this permission notice shall be included in all
//        copies or substantial portions of the Software.
//
// THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
// IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
// FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
//        AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
// LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
// OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
// SOFTWARE.

#include "Ball.h"
#include <iostream>
#include <algorithm>

using namespace PingBallX;

void Ball::Draw(olc::PixelGameEngine *pge) {
    pge->FillRect(x_pos,y_pos,10,10, olc::WHITE);
}

void Ball::SetPosition(int32_t x, int32_t y) {
    x_pos = x;
    y_pos = y;
}


int Ball::Update(const Player& left_player, const Player& right_player) {
    // Left side
    if(x_pos + BAR_WIDTH + x_vel <= left_player.getX())
    {
        // Check y accordingly
        if(y_pos < left_player.getY() || y_pos > left_player.getY()+ left_player.getLength())
        {
            return 1;
        }
        x_pos = left_player.getX() + BAR_WIDTH;
        x_vel *= -1;
    }

    // Right side
    if(x_pos + x_vel >= right_player.getX())
    {
        // Check y accordingly
        if(y_pos < right_player.getY() || y_pos > right_player.getY()+ right_player.getLength())
        {
            return 2;
        }
        x_pos = right_player.getX();
        x_vel *= -1;
    }

    // Top
    if(y_pos + y_vel < 0)
    {
        y_pos = 0;
        y_vel *= -1;
    }

    if(y_pos - y_vel > window_height)
    {
        y_pos = window_height;
        y_vel *= -1;
    }

    // If no contact
    x_pos += x_vel;
    y_pos += y_vel;

    return 0;
}
void Ball::SetRandomVelocity() {
    srand(time(nullptr));
    rand() % 2 ? x_vel = -10 : x_vel = 10;
    rand() % 2 ? y_vel = -10 : y_vel = 10;
}

void Ball::setWindowHeight(int _window_height) {
    this->window_height = _window_height;
}
