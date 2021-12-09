#include "Director.h"

std::shared_ptr<GameLevelScene> Director::getGameLevelScene(GameManager* _gameManager, const unsigned int _stage, const unsigned int _prevScore)
{
	
	auto gameLevelScene = std::make_shared<GameLevelScene>(_gameManager, _stage, _prevScore);
	gameLevelScene->player = builder->getPlayer();
		/*Auto* Coche = new Auto();

		Coche->Carroceria = builder->getCarroceria();
		Coche->Motor = builder->getMotor();
		Coche->Neumaticos[0] = builder->getNeumatico();
		Coche->Neumaticos[1] = builder->getNeumatico();
		Coche->Neumaticos[2] = builder->getNeumatico();
		Coche->Neumaticos[3] = builder->getNeumatico();

		return Coche;*/
		return gameLevelScene;
}