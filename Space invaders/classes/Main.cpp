#include "graphics.h"
#include "Game.h"

// The custom callback function that the library calls 
// to check for and set the current application state.
void update(float ms)
{
    // Fernw apo to SGG to Game kai tou kanw cast giati den einai void *
    Game* game = (Game*)graphics::getUserData();


    game->update();
}

// The window content drawing function.
void draw()
{
    // Fernw apo to SGG to Game kai tou kanw cast giati den einai void *
    Game* game = (Game*)graphics::getUserData();
    


    game->draw();
}

int main()
{
    // Dimiourgia tou antikeimenou Game
    Game* game = new Game();



    // Dimourgia neou parathyrou
    graphics::createWindow(game->platosP, game->ypsosP, game->titlos);

    // Thetoume poies synartiseis tha kanoyn draw kai update
    graphics::setDrawFunction(draw);
    graphics::setUpdateFunction(update);


    // Dimiuourgia kamva
    graphics::setCanvasSize(game->platosK, game->ypsosK);
    graphics::setCanvasScaleMode(graphics::CANVAS_SCALE_FIT);


    // Pernaw ta xrwmata gia to background
    graphics::Brush br(game->backBr);
    

    //                H'
    br.texture = "assets\\back.png";
    br.fill_color[0] = game->backR;
    br.fill_color[1] = game->backG;
    br.fill_color[2] = game->backB;
    br.outline_opacity = 0.0f;
    float offset = YPSOS_KAMVA / 4 * sinf(graphics::getGlobalTime()/1000.0f);

    // Xrwma sto background
    graphics::setWindowBackground(br);
    



    // Fortwnoume tin grammatoseira
     graphics::setFont("assets\\gram.ttf");


    // Pernaw to paixninei mesa sto SGG // Mporw na to kanw se ola ta simeia prin to MessageLoop
    graphics::setUserData(game);

    // Gia na paizei mousiki sto paraskinio
    graphics::playMusic("assets\\backroundmusic.mp3", 0.2f, true, 0);


    // Kalei synexeia tis update/draw
    graphics::startMessageLoop();


    // Katastrofi tou antikeimenou game
    delete game;

    return 0;
}