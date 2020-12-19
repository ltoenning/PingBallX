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

#ifndef PINGBALLX_GAME_H
#define PINGBALLX_GAME_H

#define LENGTH 100

enum State
{
    INTRO, RUNNING
};

#include "olcPixelGameEngine.h"

#include "Player.h"
#include "Ball.h"
#include "UserInterface.h"
namespace PingBallX {
    class Game : public olc::PixelGameEngine {
    public:
        Game();
        bool OnUserCreate() override;
        bool OnUserUpdate(float fElapsedTime) override;

    private:
        PingBallX::Player left_player = PingBallX::Player(0,0,LENGTH); // Setting x,y position after start
        PingBallX::Player right_player = PingBallX::Player(0,0,LENGTH); // Setting x,y position after start
        PingBallX::Ball ball;
        UserInterface ui;
        void UpdateDraw();

        /// Update game state, player, ball according to key presses
        /// \return true if game should continue, otherwise false
        bool UpdateInput();

        void DrawHelp();
        bool should_restart = false;
        State state = INTRO;
    };
}

#endif//PINGBALLX_GAME_H
