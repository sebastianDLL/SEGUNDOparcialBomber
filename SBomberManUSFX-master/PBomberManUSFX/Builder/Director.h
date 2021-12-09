#pragma once
#include <SDL.h>
#include <memory>
#include <utility>
#include <vector>
#include <iostream>
#include <fstream>
#include <string>

#include "../Builder/Builder.h"
#include "../Scenes/GameLevelScene.h"

class Director
{
private:
	Builder* builder;

public:
	void setBuilder(Builder* _newBuilder)
	{
		builder = _newBuilder;
	}

	std::shared_ptr<GameLevelScene> getGameLevelScene(GameManager* _gameManager, const unsigned int _stage, const unsigned int _prevScore);
};

