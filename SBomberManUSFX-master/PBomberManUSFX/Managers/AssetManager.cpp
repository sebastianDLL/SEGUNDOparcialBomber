#include <SDL_image.h>
#include <iostream>

#include "../Managers/AssetManager.h"

void AssetManager::load(SDL_Renderer* renderer)
{
        // load font
    loadFont();
    // load textures
    loadTexture(renderer, GameTexture::MenuBack, "assets/menu_title.png");
    loadTexture(renderer, GameTexture::Metal, "resources/muro_metal.jpg");
    loadTexture(renderer, GameTexture::Stone, "resources/muro_piedra_01.png");
  //  loadTexture(renderer, GameTexture::Grass, "resources/suelo_cesped_01.png");
    loadTexture(renderer, GameTexture::Grass, "assets/NuevaCeramica.png");
    /*NuevaCeramica.png*/
    loadTexture(renderer, GameTexture::Brick, "resources/muro_piedra_01.png");
    loadTexture(renderer, GameTexture::WallPacman, "resources/muro_metal.jpg");
   // loadTexture(renderer, GameTexture::WallPacman, "resources/wall_sprite.bmp");
    loadTexture(renderer, GameTexture::Player, "assets/player.png");
    loadTexture(renderer, GameTexture::Enemy1, "assets/enemy_1.png");
    loadTexture(renderer, GameTexture::Enemy2, "assets/enemy_2.png");
    loadTexture(renderer, GameTexture::Enemy3, "assets/enemy_3.png");
    loadTexture(renderer, GameTexture::Bomb, "assets/bomb.png");
    loadTexture(renderer, GameTexture::Explosion, "assets/explosion.png");
    loadTexture(renderer, GameTexture::Door, "assets/door.png");
 //    load music
    loadMusic(MusicEnum::MainMenu, "assets/main_theme.ogg");
    loadMusic(MusicEnum::Level, "assets/level.ogg");
//     load sounds
    loadSound(SoundEnum::Win, "assets/win.wav");
    loadSound(SoundEnum::Lose, "assets/lose.wav");
    loadSound(SoundEnum::Explosion, "assets/explosion.wav");
    if (auto explosionSound = getSound(SoundEnum::Explosion))
    {
        Mix_VolumeChunk(explosionSound.get(), 35);
    }
}

std::shared_ptr<TTF_Font> AssetManager::getFont() const
{
    return font;
}

std::shared_ptr<SDL_Texture> AssetManager::getTexture(GameTexture texture)
{
    return textures[texture];
}

std::shared_ptr<Mix_Music> AssetManager::getMusic(MusicEnum music)
{
    return musics[music];
}

std::shared_ptr<Mix_Chunk> AssetManager::getSound(SoundEnum sound)
{
    return sounds[sound];
}

void AssetManager::loadFont()
{
    // load font
    font = std::shared_ptr<TTF_Font>(TTF_OpenFont("assets/font.ttf", 32), TTF_CloseFont);
    if(!font)
    {
        std::cout << "TTF_OpenFont Error: " << TTF_GetError() << std::endl;
    }
}

void AssetManager::loadTexture(SDL_Renderer* renderer, GameTexture texture, const std::string& filePath)
{
    textures[texture] =
        std::shared_ptr<SDL_Texture>(IMG_LoadTexture(renderer, filePath.c_str()), SDL_DestroyTexture);
    if(!textures[texture])
    {
        std::cout << "IMG_LoadTexture Error: " << IMG_GetError() << std::endl;
    }
}

void AssetManager::loadMusic(MusicEnum music, const std::string& filePath)
{
    musics[music] = std::shared_ptr<Mix_Music>(Mix_LoadMUS(filePath.c_str()), Mix_FreeMusic);
    if(!musics[music])
    {
        std::cout << "loadMusic Error: " << Mix_GetError() << std::endl;
    }
}

void AssetManager::loadSound(SoundEnum sound, const std::string& filePath)
{
    sounds[sound] = std::shared_ptr<Mix_Chunk>(Mix_LoadWAV(filePath.c_str()), Mix_FreeChunk);
    if(!sounds[sound])
    {
        std::cout << "loadSound Error: " << Mix_GetError() << std::endl;
    }
}
