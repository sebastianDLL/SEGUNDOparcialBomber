#pragma once
#include "Scene.h"
#include <SDL.h>
#include <memory>
#include <utility>
#include <vector>
#include <iostream>
#include <fstream>
#include <string>

#include "../Const.h"
#include "../Entities/Enemy.h"
#include "../Entities/Music.h"
#include "../Entities/Player.h"
#include "../Entities/Sound.h"
#include "../Entities/Text.h"
#include "../Scenes/Scene.h"
#include "../Entities/ClasicoPlayer.h"
#include "../GameVersions.h"

class GameLevelScene :
    public Scene
{
public:
    GameLevelScene(GameManager* _gameManager, const unsigned int _stage, const unsigned int _prevScore);
    //GameLevelScene(GameManager* game, GameVersion _gameVersion, const unsigned int _stage, const unsigned int _prevScore);
    virtual void onEvent(const SDL_Event& event) override;
    /**
        * @brief Update level scene
        *
        * @param delta - delta time since previous update in milliseconds
        */
    virtual void update(const unsigned int delta) override;

    // timers in ms const
    const int levelTimerStart = 200500;
    const int levelTimerUpdateText = 1000;
    const int bombTimerStart = 1500;
    const int bangTimerStart = 800;
    const int gameOverTimerStart = 1000;
    const int winTimerStart = 200;
    // const for score
    const unsigned int scoreRewardForKill = 200;
    const unsigned int scoreRewardForStage = 1000;

    std::shared_ptr<Music> menuMusic = nullptr;                       // menu music
    std::shared_ptr<Sound> gameoverSound = nullptr;                   // game over sound
    std::shared_ptr<Sound> winSound = nullptr;                        // win sound
    std::shared_ptr<Sound> explosionSound = nullptr;                  // explosion sound
    std::shared_ptr<Text> timerNumber = nullptr;                      // timer
    std::shared_ptr<Text> scoreNumber = nullptr;                      // score
    std::shared_ptr<Player> player = nullptr;                         // player
    std::shared_ptr<Sprite> bomb = nullptr;                           // player's bomb
    std::shared_ptr<Sprite> door = nullptr;                           // door for level finish
    std::vector<std::shared_ptr<Enemy>> enemies;                      // enemies
    std::vector<std::pair<GameTile, std::shared_ptr<GameGraphicObject>>> collisions; // collisions
    std::vector<std::shared_ptr<GameGraphicObject>> bangs;                       // bomb's bang
    GameTile tiles[tileArrayHeight][tileArrayWidth];                      // tilemap


    int playerDirectionX = 0; // direction used for control
    int playerDirectionY = 0; // direction used for control
    // timer variables
    int levelTimer = levelTimerStart;
    int levelTimerDelta = 0;
    int bombTimer = 0;
    int bangTimer = 0;
    int gameOverTimer = 0;
    // bool flags
    bool isGameOver = false;
    bool isPaused = false;
    bool isWin = false;
    // variables
    unsigned int gameVersion = GAMEVERSION_CLASIC;
    unsigned int score = 0;
    unsigned int stage = 0;

    // level positioning
    int fieldPositionX = 0;
    int fieldPositionY = 0;
    // size of tiles
    int scaledTileSize = 0;
    // last object that used as background (grass)
    int backgroundObjectLastNumber = 0;
};

