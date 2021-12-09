#include "GameLevelScene.h"
#include <algorithm>
#include <chrono>
#include <functional>
#include <random>
#include <string>

#include "../Entities/Sprite.h"
#include "../GameManager.h"
#include "../Scenes/GameOverScene.h"
#include "../Scenes/LevelScene.h"
#include "../Scenes/StageScene.h"
#include "../Util/Pathfinding.h"

GameLevelScene::GameLevelScene(GameManager* _gameManager, const unsigned int _stage, const unsigned int prevScore)
    : Scene(_gameManager), score(prevScore), stage(_stage)
{

    // common field parameters
    fieldPositionX = 0;
    fieldPositionY = gameManager->getWindowHeight() / 15;
    const float scale = (gameManager->getWindowHeight() - fieldPositionY) / static_cast<float>(tileArrayHeight * tileSize);
    scaledTileSize = static_cast<int>(round(scale * tileSize));
    // menu music
    menuMusic = std::make_shared<Music>(gameManager->getAssetManager()->getMusic(MusicEnum::Level));
    menuMusic->play();
    // sounds
    gameoverSound = std::make_shared<Sound>(gameManager->getAssetManager()->getSound(SoundEnum::Lose));
    winSound = std::make_shared<Sound>(gameManager->getAssetManager()->getSound(SoundEnum::Win));
    explosionSound = std::make_shared<Sound>(gameManager->getAssetManager()->getSound(SoundEnum::Explosion));
    // render text
    // spawnTextObjects();
    // generate tile map
    // generateTileMap();
    // 
    // crearObjetosJuego("resources/level1.txt");
    // prepare player
    // spawnPlayer(fieldPositionX + playerStartX * scaledTileSize, fieldPositionY + playerStartY * scaledTileSize);
    // generate enemies
    // generateEnemies();
    // set timer
    // updateLevelTimer();
}
void GameLevelScene::onEvent(const SDL_Event& event)
{
    //Scene::onEvent(event);
    //// we need to update movement if movement keys pressed or released
    //if ((event.type == SDL_KEYDOWN || event.type == SDL_KEYUP) && event.key.repeat == 0)
    //{
    //    updateMovement(event.type == SDL_KEYDOWN ? true : false, event.key.keysym.scancode);
    //}

    //if (event.type == SDL_KEYDOWN)
    //{
    //    // we should go to main menu by Escape key
    //    if (event.key.keysym.scancode == SDL_SCANCODE_ESCAPE)
    //    {
    //        gameOver();
    //        isWin = false;
    //        gameOverTimer = winTimerStart;
    //    }
    //    // we can spawn a bomb by space press
    //    else if (event.key.keysym.scancode == SDL_SCANCODE_SPACE)
    //    {
    //        if (!isGameOver)
    //        {
    //            spawnBomb(player.get());
    //        }
    //    }
    //    // we can pause a gameManager by pressing enter key
    //    else if (event.key.keysym.scancode == SDL_SCANCODE_RETURN)
    //    {
    //        isPaused = !isPaused;
    //        if (isPaused)
    //        {
    //            menuMusic->pause();
    //        }
    //        else
    //        {
    //            menuMusic->resume();
    //        }
    //    }
    //    // stage complete cheat
    //    else if (event.key.keysym.scancode == SDL_SCANCODE_BACKSPACE)
    //    {
    //        gameOver();
    //        isWin = true;
    //        score += scoreRewardForStage * 100;
    //        gameOverTimer = winTimerStart;
    //    }
    //}
}

void GameLevelScene::update(const unsigned int delta)
{
    // pause
    if (isPaused)
    {
        return;
    }
    Scene::update(delta);
    //// update collision of player
    //updatePlayerCollision();
    //// update collision of enemies
    //updateEnemiesCollision();
    //// update collision of bricks
    //updateBangsCollision();
    //// update camera
    //updateCamera();
    //// update timers
    //updateTimers(delta);
}

//void LevelScene::updateTimers(const unsigned int delta)
//{
//    // update level timer
//    levelTimer -= delta;
//    levelTimerDelta += delta;
//    if (levelTimerDelta >= levelTimerUpdateText)
//    {
//        updateLevelTimer();
//    }
//    // update bomb timer
//    if (bomb != nullptr)
//    {
//        updateBombTimer(delta);
//    }
//    // update bang timer
//    if (bangs.size() > 0)
//    {
//        updateBangTimer(delta);
//    }
//    // update gameManager over timer
//    if (isGameOver)
//    {
//        updateGameOverTimer(delta);
//    }
//
//    // finish level if level timer is 0
//    if (levelTimer <= 0 && !isGameOver)
//    {
//        gameOver();
//        isWin = false;
//        gameOverTimer = winTimerStart;
//    }
//}

//void GameLevelScene::updateLevelTimer()
//{
//    if (levelTimer < 0)
//    {
//        return;
//    }
//    levelTimerDelta = 0;
//    const int timeInSec = static_cast<int>(levelTimer / 1000.0f);
//    std::string timeString = std::to_string(timeInSec);
//    while (timeString.size() < 3)
//    {
//        timeString = "0" + timeString;
//    }
//    timerNumber->setText(timeString);
//}
