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

#include "Player.h"
#include <iostream>

using namespace PingBallX;

Player::Player(uint8_t _x_pos, uint8_t _y_pos, uint8_t _length) {
    x_pos = _x_pos;
    y_pos = _y_pos;
    length = _length;
}

void Player::Draw(olc::PixelGameEngine* pge) {
    pge->FillRect(x_pos,y_pos,BAR_WIDTH,length, olc::WHITE);
}
void Player::up() {
    if(y_pos > 0)
        y_pos = y_pos - 10;
}
void Player::down() {
    if(y_pos < window_height-length)
        y_pos = y_pos + 10;
}
void Player::SetPosition(int32_t x, int32_t y) {
    x_pos = x;
    y_pos = y;
}

void Player::Update(olc::PixelGameEngine* pge, olc::Key up_key, olc::Key down_key)
{
    if(pge->GetKey(up_key).bHeld)
    {
        up();
    }
    if(pge->GetKey(down_key).bHeld)
        down();
}

int Player::getX() const {
    return x_pos;
}
int Player::getY() const {
    return y_pos;
}
int Player::getLength() const {
    return length;
}

void Player::setWindowHeight(int _window_height) {
    window_height = _window_height;
}
