#pragma once

#include <SDL.h>
#include <memory>

#include "../Entities/Music.h"
#include "../Entities/Text.h"
#include "../Scenes/Scene.h"
#include "../GameVersions.h"
/**
    * @brief Menu id
    *
    */
enum class MenuItem
{
    None,
    StartCartoon,
    StartClasic,
    StartCustom,
    StartRealistic,
    Exit,
    Last
};
/**
    * @brief Menu Scene
    *
    */
class MenuScene : public Scene
{
    public:
    /**
        * @brief Construct a new Menu Scene
        *
        * @param game
        */
    MenuScene(GameManager* game);
    /**
        * @brief Called when scene was activated
        *
        */
    virtual void onEnter() override;
    /**
        * @brief Called when scene was deactivated
        *
        */
    virtual void onExit() override;
    /**
        * @brief Trigger on SDL2 event if scene is active
        *
        * @param event - SDL2 event
        */
    virtual void onEvent(const SDL_Event& event) override;

    private:
    /**
        * @brief called when menu item was selected
        *
        */
    void onMenuItemSelect();
    /**
        * @brief called when menu item was pressed
        *
        */
    void onMenuItemPress();

    //std::shared_ptr<Text> startText = nullptr;      // menu start
    //Text* startText = nullptr; Es lo mismo que la linea anterior
    
    std::shared_ptr<Text> startCartoonText = nullptr;      // menu start cartoon
    std::shared_ptr<Text> startClasicText = nullptr;      // menu start clasic
    std::shared_ptr<Text> startCustomText = nullptr;      // menu start custom
    std::shared_ptr<Text> startRealisticText = nullptr;      // menu start realistic
    std::shared_ptr<Text> exitText = nullptr;       // menu exit
    std::shared_ptr<Music> menuMusic = nullptr;     // menu music
    MenuItem currentSelectedMenu = MenuItem::StartCartoon; // current selected menu

    // const colors for menu selection
    const SDL_Color colorStandard = {255, 255, 255, 255};
    const SDL_Color colorPressed = {66, 134, 244, 255};
};

