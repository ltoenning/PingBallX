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


#include "UserInterface.h"

using namespace PingBallX;

void UserInterface::IncreaseScorePlayer1() {
     scorePlayer1++;
}
void UserInterface::IncreaseScorePlayer2() {
    scorePlayer2++;
}
void UserInterface::Draw(olc::PixelGameEngine *pge) {
    // FIXME Remove fixed coordinates
    // Player 1 score
    pge->DrawString(800,1000, std::to_string(scorePlayer1), olc::WHITE,8);

    // FIXME Remove fixed coordinates
    // Player 2 score
    pge->DrawString(1070,1000, std::to_string(scorePlayer2), olc::WHITE,8);
}
