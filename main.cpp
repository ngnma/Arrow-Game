#include "SBDL.h"
#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;
void playgame();void showmenu();void showresumemenu();void makerand();void settingmenu();
void loadingTextureGame();void loadingSoundGame();void switching();void endmenu();void charectormenu();


Texture bar,barr,score,gem,green,ground5,ground2,ground4,ground1,yellow,barrier,target,player2,player1,player3,player4,
player5,player6,eating2,eating1,blueback,restart,pausebar,menurestart,menuexit,exitt,pointmenuu,ground3,pausemenu1,
pausemenu2,pausemenu3,greengemscore,endmenu1,endmenu2,endmenu4,settingmenu2,settingmenu4,eating3,eating4,eating5,
eating6,hide5,hide6,playerbar,musicmenu,ground6;

Font *font;
Sound *crashgem,*crash,*click,*normal,*apple,*duk,*bear,*dog,*pinguin,*snake;
Music*s;
SDL_Rect bar1Rect,bluebackRect,yellowRect,ground5Rect,ground4Rect,
ground4rRect,ground1Rect,ground1rRect,ground5rRect,pausebarRect,blueback2Rect,blueback3Rect,menurestartRect,
menuexitRect,ground3Rect,ground3rRect,ground2rRect,ground2Rect,bar2Rect,bar3Rect,
pausemenu2Rect,pausemenu3Rect,endmenu1Rect,endmenu2Rect,endmenu3Rect,endmenu4Rect,settingmenu1Rect,
settingmenu2Rect,settingmenu3Rect,settingmenu4Rect,pausemenu1Rect,ground6Rect,ground6rRect,
charmenu1Rect,charmenu2Rect,charmenu3Rect,charmenu4Rect,charmenu5Rect,charmenu6Rect;

SDL_Rect Rect_target[100],Rect_gem[100],Rect_l[101],Rect_r[101],Rect_green[100];


int frame=1,hh,point=0,pointmenu=0,greengem=0,speed=0,playernumber=1,highscore=0;
int targetrand[100],gemrand[10],greenrand[100];
bool again=true,sound=true,music=false;
int switchgame=1;

void loadingSoundGame(){
    click=SBDL::loadSound("assets/click.wav");
    s = SBDL::loadMusic("assets/chilled_v1.wav");
    crash = SBDL::loadSound("assets/crash2.wav");
    crashgem = SBDL::loadSound("assets/gem_old.wav");
    normal = SBDL::loadSound("assets/normal.wav");
    apple = SBDL::loadSound("assets/apple.wav");
    duk= SBDL::loadSound("assets/duk.wav");
    dog=SBDL::loadSound("assets/dog.wav");
    pinguin=SBDL::loadSound("assets/penguin.wav");
    snake=SBDL::loadSound("assets/snake.wav");
    bear=SBDL::loadSound("assets/bear.wav");
}
void loadingTextureGame() {
    settingmenu2=SBDL::loadTexture("assets/menu2.png");
    settingmenu4=SBDL::loadTexture("assets/menu4.png");
    menuexit=SBDL::loadTexture("assets/menu3.png");
    bar = SBDL::loadTexture("assets/bar.png");
    barr = SBDL::loadTexture("assets/barr.png");
    gem = SBDL::loadTexture("assets/gem.png");
    green=SBDL::loadTexture("assets/green.png");
    ground1 = SBDL::loadTexture("assets/ground1.png");
    ground2 = SBDL::loadTexture("assets/ground2.png");
    ground3 = SBDL::loadTexture("assets/ground3.png");
    ground4 = SBDL::loadTexture("assets/ground2.png");
    ground5 = SBDL::loadTexture("assets/ground5.png");
    ground6 = SBDL::loadTexture("assets/ground6.png");
    player1 = SBDL::loadTexture("assets/yellow.png");
    player2 = SBDL::loadTexture("assets/player2.png");
    player3 = SBDL::loadTexture("assets/player3.png");
    player4 = SBDL::loadTexture("assets/player4.png");
    player5 = SBDL::loadTexture("assets/player5.png");
    player6 = SBDL::loadTexture("assets/player6.png");
    barrier = SBDL::loadTexture("assets/wall_1.png");
    eating1 = SBDL::loadTexture("assets/target.png");
    eating2 = SBDL::loadTexture("assets/eating2.png");
    eating3 = SBDL::loadTexture("assets/eating3.png");
    eating4 = SBDL::loadTexture("assets/eating4.png");
    eating5 = SBDL::loadTexture("assets/eating5.png");
    eating6 = SBDL::loadTexture("assets/eating6.png");
    musicmenu = SBDL::loadTexture("assets/menu5.png");
    playerbar= SBDL::loadTexture("assets/playerbar.png");
    hide5 = SBDL::loadTexture("assets/hide5.png");
    hide6 = SBDL::loadTexture("assets/hide6.png");
    menurestart = SBDL::loadTexture("assets/menu11.png");
    blueback = SBDL::loadTexture("assets/BackMenuBlue.png");
    font = SBDL::loadFont("assets/CenturyGothic.ttf", 100);
    restart = SBDL::createFontTexture(font,"Restart",255,255,255);
    exitt = SBDL::createFontTexture(font,"Exit",255,255,255);
    pausemenu1= SBDL::createFontTexture(font,"Resume",255,255,255);
    pausemenu2= SBDL::createFontTexture(font,"Restart",255,255,255);
    pausemenu3= SBDL::createFontTexture(font,"Main Menu",255,255,255);
    pausebar = SBDL::createFontTexture(font,"Pause",255,255,255);
    endmenu1= SBDL::createFontTexture(font,"Restart",255,255,255);
    endmenu2= SBDL::createFontTexture(font,"Main Menu",255,255,255);
    endmenu4= SBDL::createFontTexture(font,"Exit",255,255,255);
    yellow=player1;
    target=eating1;
     endmenu1Rect={100,100,250,100};
     endmenu2Rect={450,100,250,100};
     endmenu3Rect={100,300,250,100};
     endmenu4Rect={450,300,250,100};
     charmenu1Rect={150,100,100,100};
     charmenu2Rect={350,100,100,100};
     charmenu3Rect={550,100,100,100};
     charmenu4Rect={150,300,100,100};
     charmenu5Rect={350,300,100,100};
     charmenu6Rect={550,300,100,100};
     settingmenu1Rect={100,75,250,150};
     settingmenu2Rect={450,75,250,150};
     settingmenu3Rect={100,275,250,150};
     settingmenu4Rect={450,275,250,150};
     bar1Rect = {300, 50, 200, 100};
     bar2Rect = {300, 200, 200, 100};
     bar3Rect = {300, 350, 200, 100};
     bluebackRect = {100, 100, 600, 100};
     blueback2Rect = {100, 300, 200, 100};
     blueback3Rect = {500, 300, 200, 100};
     yellowRect = {250, 300, 25, 25};
     ground1Rect = {0, 0, 500, 500};
     ground2Rect = {0, 0, 500, 500};
     ground3Rect = {0, 0, 500, 500};
     ground4Rect = {0, 0, 500, 500};
     ground5Rect = {0, 0, 500, 500};
     ground6Rect = {0, 0, 500, 500};
     ground1rRect = {500, 0, 500, 500};
     ground2rRect = {500, 0, 500, 500};
     ground3rRect = {500, 0, 500, 500};
     ground4rRect = {500, 0, 500, 500};
     ground5rRect = {500, 0, 500, 500};
     ground6rRect = {500, 0, 500, 500};
     menurestartRect ={500,120,50,50};
     menuexitRect={150,310,100,80};
     pausemenu1Rect ={300, 50, 200, 100};
     pausemenu2Rect ={300, 200, 200, 100};
     pausemenu3Rect ={300, 350, 200, 100};
     pausebarRect={50,400,100,50};
}
void makerand(){
    for(int i=0;i<100;i++){
        targetrand[i]=rand()%2;
        gemrand[i]=rand()%4;
    greenrand[i]=rand()%2;}

    int H=rand()%100+100;
    int W=rand()%300+200;
    Rect_l[0]={0 ,400-H,W,H};
    Rect_r[0]={W+100 ,400 -H,800,H};
    H=400-H;
    for(int i=1;i<100;i++)
    {hh=rand()%100+100;
        W=rand()%200+W-100;
        Rect_l[i]={0,H-hh,W,hh};
        Rect_r[i]={W+200 ,H-hh,800,hh};
        Rect_target[i]={W+70,(H-hh)+hh/2,20,20};
        Rect_gem[i]={W+120,(H-hh)+hh/2+20,20,20};
        Rect_green[i]={W+80,(H-hh)+hh/2-20,20,20};
        H=H-hh;}
    Rect_r[100]={800,0,1,500};
    Rect_l[100]={-1,0,1,500};

}
void showresumemenu(){
    SBDL::showTexture(ground3, ground3Rect);
    SBDL::showTexture(ground3, ground3rRect);
    SBDL::showTexture(bar,bar1Rect );
    SBDL::showTexture(bar,bar2Rect );
    SBDL::showTexture(bar,bar3Rect );
    SBDL::showTexture(pausemenu1,pausemenu1Rect);
    SBDL::showTexture(pausemenu2,pausemenu2Rect);
    SBDL::showTexture(pausemenu3,pausemenu3Rect);
    if (SBDL::mouseInRect(bar1Rect) && SBDL::Mouse.clicked()){if(sound==true){SBDL::playSound(click, 1);} switchgame=0;}
    else if (SBDL::mouseInRect(bar2Rect) && SBDL::Mouse.clicked()){if(sound==true){SBDL::playSound(click, 1);} yellowRect = {250, 300, 25, 25};point=0;makerand();speed=0;switchgame=0;}
    else if (SBDL::mouseInRect(bar3Rect) && SBDL::Mouse.clicked()){if(sound==true){SBDL::playSound(click, 1);} yellowRect = {250, 300, 25, 25};point=0;makerand();speed=0;switchgame=1;}
}
void playgame(){
    SBDL::showTexture(ground1, ground1Rect);
    SBDL::showTexture(ground1, ground1rRect);
    for(int i=2;i<100;i++){
        SBDL::showTexture(barrier, Rect_l[i]);
        SBDL::showTexture(barrier, Rect_r[i]);
        if(targetrand[i]==1)
            SBDL::showTexture(target, Rect_target[i]);
        if(gemrand[i]==1)
            SBDL::showTexture(gem, Rect_gem[i]);
        if(greenrand[i]==1)
            SBDL::showTexture(green, Rect_green[i]);}
    score = SBDL::createFontTexture(font,""+to_string(point),0,0,0);
    pointmenuu = SBDL::createFontTexture(font,"HighScore:"+to_string(highscore),0,0,0);
    greengemscore = SBDL::createFontTexture(font,"GreenGem:"+to_string(greengem),0,0,0);
    SBDL::showTexture(score, {390, 50, 35, 30});
    SBDL::showTexture(yellow, yellowRect);
    if (SBDL::keyHeld(SDL_SCANCODE_SPACE)) {
        yellowRect.x += 3+speed;
    } else {
        yellowRect.x -= 3+speed;
    }
    if(SBDL::mouseInRect(pausebarRect) && SBDL::Mouse.clicked()){if(sound==true){SBDL::playSound(click, 1);} switchgame=2;}

    for(int i=2;i<101;i++)
        if (SBDL::hasIntersectionRect(Rect_l[i], yellowRect) or SBDL::hasIntersectionRect(Rect_r[i], yellowRect)) {
            {if(sound==true){SBDL::playSound(crash, 1);}
                switchgame = 3;
                //speed=0;
                //yellowRect = {250, 300, 25, 25};
                //point = 0;
                //makerand();
            }
            }

    for(int i=0;i<100;i++){
        if (SBDL::hasIntersectionRect(Rect_target[i], yellowRect) and targetrand[i]==1) {
            if(sound==true){
                switch (playernumber)
                {
                    case 1:SBDL::playSound(normal, 1);break;
                    case 2:SBDL::playSound(duk, 1);break;
                    case 3:SBDL::playSound(snake, 1);break;
                    case 4:SBDL::playSound(pinguin, 1);break;
                    case 5:SBDL::playSound(bear, 1);break;
                    case 6:SBDL::playSound(dog, 1);break;
                }}

            Rect_target[i].w = 0;
            Rect_target[i].h = 0;
            point++;}
        if (SBDL::hasIntersectionRect(Rect_gem[i], yellowRect) and gemrand[i]==1) {
            if (sound==true){SBDL::playSound(crashgem, 1);}
            Rect_gem[i].w = 0;
            Rect_gem[i].h = 0;
            point+=10;}
        if (SBDL::hasIntersectionRect(Rect_green[i], yellowRect) and greenrand[i]==1) {
            if (sound==true){SBDL::playSound(apple, 1);}
        Rect_green[i].w = 0;
        Rect_green[i].h = 0;
        greengem++;
    }}
    for(int i=2;i<100;i++){
        Rect_l[i].y=Rect_l[i].y+1+speed;
        Rect_target[i].y=Rect_target[i].y+1+speed;
        Rect_gem[i].y=Rect_gem[i].y+1+speed;
        Rect_green[i].y=Rect_green[i].y+1+speed;
        Rect_r[i].y=Rect_r[i].y+1+speed;}
    frame++;
    if(frame%50==0)
        speed+=0.5;
    if(point>highscore)
        highscore=point;
    SBDL::showTexture(bar,pausebarRect );
    SBDL::showTexture(pausebar,pausebarRect );
}
void showmenu(){
    SBDL::showTexture(ground5, ground5Rect);
    SBDL::showTexture(ground5, ground5rRect);
    SBDL::showTexture(blueback,bluebackRect );
    SBDL::showTexture(blueback,blueback2Rect );
    SBDL::showTexture(blueback,blueback3Rect );
    SBDL::showTexture(menurestart,menurestartRect);
    SBDL::showTexture(menuexit,menuexitRect);
    SBDL::showTexture(pointmenuu, {100, 220,200, 50});
    SBDL::showTexture(greengemscore, {500, 220,200, 50});
    SBDL::showTexture(restart, {300, 120,200, 50});
    SBDL::showTexture(exitt, {565, 325,70, 50});
    if (SBDL::mouseInRect(bluebackRect) && SBDL::Mouse.clicked()) { if(sound==true){SBDL::playSound(click, 1);}speed=0;yellowRect = {250, 300, 25, 25};point = 0;
    makerand();switchgame = 0; }
    else if (SBDL::mouseInRect(blueback3Rect) && SBDL::Mouse.clicked()) { if(sound==true){SBDL::playSound(click, 1);} again=false ;}
    else if (SBDL::mouseInRect(blueback2Rect) && SBDL::Mouse.clicked()) { if(sound==true){SBDL::playSound(click, 1);} switchgame=4;}
}
void switching(){
    if(switchgame==0){playgame();}
    else if(switchgame==1){showmenu();}
    else if(switchgame==2){ showresumemenu();}
    else if(switchgame==3){ endmenu();}
    else if(switchgame==4){ settingmenu();}
    else if(switchgame==5){ charectormenu();}
}
void endmenu(){
    SBDL::showTexture(ground2, ground2Rect);
    SBDL::showTexture(ground2, ground2rRect);
    SBDL::showTexture(bar,endmenu1Rect );
    SBDL::showTexture(bar,endmenu2Rect );
    SBDL::showTexture(bar,endmenu3Rect );
    SBDL::showTexture(bar,endmenu4Rect );
    SBDL::showTexture(endmenu1,endmenu1Rect );
    SBDL::showTexture(endmenu2,endmenu2Rect );
    SBDL::showTexture(endmenu4,endmenu4Rect );
    SBDL::showTexture(green,{100,320,50,50});
    SBDL::showTexture(green,{150,320,50,50});
    SBDL::showTexture(green,{200,320,50,50});
    SBDL::showTexture(green,{250,320,50,50});
    SBDL::showTexture(green,{300,320,50,50});
    if (SBDL::mouseInRect(endmenu1Rect) && SBDL::Mouse.clicked())
    {if(sound==true)
    {SBDL::playSound(click, 1);}
    speed=0;yellowRect = {250, 300, 25, 25};point = 0;makerand();switchgame = 0; }
    else if(SBDL::mouseInRect(endmenu2Rect)&& SBDL::Mouse.clicked())
    {if(sound==true){SBDL::playSound(click, 1);}
    speed=0;yellowRect = {250, 300, 25, 25};point=0;makerand();switchgame = 1;}
    else if(SBDL::mouseInRect(endmenu3Rect) && SBDL::Mouse.clicked())
    {if(sound==true){SBDL::playSound(click, 1);}if(greengem>=5)greengem-=5;switchgame=0;}
    else if(SBDL::mouseInRect(endmenu4Rect) && SBDL::Mouse.clicked())
    {if(sound==true){SBDL::playSound(click, 1);}
    again=false;}
}
void settingmenu(){
    SBDL::showTexture(ground4, ground4Rect);
    SBDL::showTexture(ground4, ground4rRect);
    SBDL::showTexture(barr,settingmenu1Rect );
    SBDL::showTexture(barr,settingmenu2Rect );
    SBDL::showTexture(barr,settingmenu3Rect );
    SBDL::showTexture(barr,settingmenu4Rect );
    SBDL::showTexture(playerbar,{190,115,80,70});
    SBDL::showTexture(musicmenu,{200,315,70,70});
    SBDL::showTexture(settingmenu2,{540,125,70,50});
    SBDL::showTexture(settingmenu4,{540,325,70,50});
    if (SBDL::mouseInRect(settingmenu1Rect) && SBDL::Mouse.clicked()) { if(sound==true){SBDL::playSound(click, 1);} switchgame = 5; }//change charector!be yellow
    else if(SBDL::mouseInRect(settingmenu2Rect) && SBDL::Mouse.clicked()){if(sound==true){SBDL::playSound(click, 1);} sound=true;music=false;switchgame = 1;}
    else if(SBDL::mouseInRect(settingmenu3Rect) && SBDL::Mouse.clicked()){if(sound==true){SBDL::playSound(click, 1);} switchgame = 4;music=true;sound=false;SBDL::playMusic(s,-1);}
    else if(SBDL::mouseInRect(settingmenu4Rect) && SBDL::Mouse.clicked()){if(sound==true){SBDL::playSound(click, 1);} sound=false;music=false;switchgame = 1;}
}
void charectormenu(){
    SBDL::showTexture(ground6, ground6Rect);
    SBDL::showTexture(ground6, ground6rRect);
    SBDL::showTexture(barr,charmenu1Rect );
    SBDL::showTexture(barr,charmenu2Rect );
    SBDL::showTexture(barr,charmenu3Rect );
    SBDL::showTexture(barr,charmenu4Rect );
    SBDL::showTexture(barr,charmenu5Rect );
    SBDL::showTexture(barr,charmenu6Rect );
    SBDL::showTexture(player1,{175,125,50,50});
    SBDL::showTexture(player2,{375,125,50,50});
    SBDL::showTexture(player3,{575,125,50,50});
    SBDL::showTexture(player4,{175,325,50,50});
    SBDL::showTexture(player5,{375,325,50,50});
    SBDL::showTexture(player6,{575,325,50,50});
    if (SBDL::mouseInRect(charmenu1Rect) && SBDL::Mouse.clicked()) { if(sound==true){SBDL::playSound(click, 1);}yellow=player1;target=eating1;playernumber=1;switchgame=0;}
    else if (SBDL::mouseInRect(charmenu2Rect) && SBDL::Mouse.clicked()) { if(sound==true){SBDL::playSound(click, 1);}yellow=player2;target=eating2;playernumber=2;switchgame=0;}
    else if (SBDL::mouseInRect(charmenu3Rect) && SBDL::Mouse.clicked()) { if(sound==true){SBDL::playSound(click, 1);}yellow=player3;target=eating3;playernumber=3;switchgame=0;}
    else if (SBDL::mouseInRect(charmenu4Rect) && SBDL::Mouse.clicked()) { if(sound==true){SBDL::playSound(click, 1);}yellow=player4;target=eating4;playernumber=4;switchgame=0;}
    else if (SBDL::mouseInRect(charmenu5Rect) && SBDL::Mouse.clicked()) { if(sound==true){SBDL::playSound(click, 1);}yellow=player5;target=eating5;playernumber=5;switchgame=0;}
    else if (SBDL::mouseInRect(charmenu6Rect) && SBDL::Mouse.clicked()) { if(sound==true){SBDL::playSound(click, 1);}yellow=player6;target=eating6;playernumber=6;switchgame=0;}
}

int main(int argc, char *argv[]) {
    srand(time(NULL));
    const int window_width = 800;
    const int window_height = 500;
    SBDL::InitEngine("Arrow", window_width, window_height);

    const int FPS = 30; //frame per second
    const int delay = 1000 / FPS; //delay we need at each frame

    loadingTextureGame();
    loadingSoundGame();
    makerand();

    while (SBDL::isRunning()) {
        int startTime = SBDL::getTime();
        SBDL::updateEvents();
        SBDL::clearRenderScreen();
        if(again==true)
        switching();
        if(music==false)
        SBDL::stopMusic();
            SBDL::updateRenderScreen();
            int elapsedTime = SBDL::getTime() - startTime;
            if (elapsedTime < delay)
                SBDL::delay(delay - elapsedTime);
        }
    }
/*
 * switchgame;
 * 0=>play game
 * 1=>show main menu
 * 2=>show resume menu
 * 3=>show end menu
 * 4=>show setting menu
 * 5=>show charectore menu
 */