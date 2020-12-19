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

#include "Game.h"

using namespace PingBallX;

Game::Game() {

    sAppName = "PingBallX";
}

bool Game::OnUserCreate() {
    // Setting screen height to ball and players
    ball.setWindowHeight(ScreenHeight());
    left_player.setWindowHeight(ScreenHeight());
    right_player.setWindowHeight(ScreenHeight());

    left_player.SetPosition(10,ScreenHeight()/2-LENGTH/2);
    right_player.SetPosition(ScreenWidth()-10, ScreenHeight()/2-LENGTH/2);
    ball.SetPosition(ScreenWidth()/2, ScreenHeight()/2);
    ball.SetRandomVelocity();
    return true;
}

bool Game::OnUserUpdate(float fElapsedTime) {
    UpdateDraw();
    if(!UpdateInput())
        return false;
    if(should_restart)
    {
        OnUserCreate();
        should_restart = false;
    }
    return true;
}

void Game::UpdateDraw() {
    Clear(olc::BLACK);
    left_player.Draw(this);
    right_player.Draw(this);
    ball.Draw(this);
    ui.Draw(this);
    DrawLine(ScreenWidth()/2, 0, ScreenWidth()/2, ScreenHeight(), olc::WHITE, 0xFF00FF); // Split line
    if(state == INTRO)
        DrawHelp();
}

bool Game::UpdateInput() {
    if(!IsFocused())
        return true; //Assume we continue

    if(GetKey(olc::ESCAPE).bHeld)
        return false;

    if(state == RUNNING)
    {

        left_player.Update(this, olc::W, olc::S);
        right_player.Update(this, olc::UP, olc::DOWN);
        int result = ball.Update(left_player, right_player);
        if(result)
        {
            if(result == 1)
                ui.IncreaseScorePlayer2();
            if(result == 2)
                ui.IncreaseScorePlayer1();
            should_restart = true;
        }
    } else
    {
        if(GetKey(olc::ENTER).bHeld)
        {
            state = RUNNING;
        }
    }
    return true;

}

void Game::DrawHelp() {
    FillRect(ScreenWidth()/3,ScreenHeight()/3,ScreenWidth()/3,ScreenHeight()/3, olc::DARK_GREY);
    // FIXME Remove fixed coordinates
    DrawString(ScreenWidth()/3+20, ScreenHeight()/3+30, "Welcome to PingBallX!", olc::WHITE, 2);
    DrawString(ScreenWidth()/3+20, ScreenHeight()/3+120, "Left player: W (up), S (down)", olc::WHITE, 2);
    DrawString(ScreenWidth()/3+20, ScreenHeight()/3+160, "Right player: Arrow keys (up, down)", olc::WHITE, 2);
    DrawString(ScreenWidth()/3+20, ScreenHeight()/3+290, "More information at:", olc::WHITE, 2);
    DrawString(ScreenWidth()/3+20, ScreenHeight()/3+330, "github.com/ltoenning/PingBallX", olc::WHITE, 2);

    DrawString(ScreenWidth()/4+170, ScreenHeight()-300, "Press ENTER to start", olc::RED, 4);
}
