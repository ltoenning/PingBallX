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

#ifndef PINGBALLX_PLAYER_H
#define PINGBALLX_PLAYER_H
#include "olcPixelGameEngine.h"

#define BAR_WIDTH 6

namespace PingBallX {
    class Player {
    public:
        Player() = default;
        Player(uint8_t  _x_pos, uint8_t _y_pos, uint8_t _length);

        /// Draws the player
        /// \param pge PixelGameEngine used for drawing
        void Draw(olc::PixelGameEngine* pge);

        /// Updates player position matching key presses
        /// \param pge PixelGameEngine used for drawing
        /// \param up_key Key needed for up move
        /// \param down_key Key needed for down move
        void Update(olc::PixelGameEngine* pge, olc::Key up_key, olc::Key down_key);

        ///
        /// \param x x coordinate
        /// \param y y coordinate
        void SetPosition(int32_t x, int32_t y);

        ///
        /// \return x coordinate of player
        [[nodiscard]] int getX() const;

        ///
        /// \return y coordinate of player
        [[nodiscard]] int getY() const;

        ///
        /// \return length of player bar
        [[nodiscard]] int getLength() const;

        /// Sets height used for border checking
        /// \param _window_height in pixel
        void setWindowHeight(int _window_height);


    private:
        int x_pos = 0, y_pos = 0;
        uint8_t length = 10;
        int window_height = 0;

        void up();

        void down();
    };
}



#endif//PINGBALLX_PLAYER_H
