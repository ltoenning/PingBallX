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

#ifndef PINGBALLX_BALL_H
#define PINGBALLX_BALL_H

#include "olcPixelGameEngine.h"
#include "Player.h"

namespace PingBallX
{
    class Ball {
    public:
        Ball() = default;

        /// Draws the ball using the parameter
        /// \param pge PixelGameEngine used for drawing
        void Draw(olc::PixelGameEngine* pge);

        /// Calculates the next ball position according to possible hits with player or window border
        /// \param left_player used to get position of player
        /// \param right_player used to get position of player
        /// \return 1 for player left lost, 2 for player right lost
        int Update(const Player& left_player, const Player& right_player);

        ///
        /// \param x x coordinate
        /// \param y y coordinate
        void SetPosition(int32_t x, int32_t y);

        /// Random velocity between -10 and 10 for x and y velocirty
        void SetRandomVelocity();

        /// Sets height used for border checking
        /// \param _window_height in pixel
        void setWindowHeight(int _window_height);

    private:
        int x_pos = 0, y_pos = 0;
        int x_vel = 0, y_vel = 0;
        int window_height = 0;

    };
}



#endif//PINGBALLX_BALL_H
