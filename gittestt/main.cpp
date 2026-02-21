#include <iostream>
#include "Textures.h"
#include "Shapes.h"
#include "Essentials.h"
#include "DragFunc.h"
#include "blockArrangement.h"
#include "Motion.h"
#include "LookMenu.h"
#include "SoundMenu.h"

int main( int argc, char * argv[] ) {
    Uint32 SDL_flags = SDL_INIT_VIDEO | SDL_INIT_TIMER ;
    Uint32 WND_flags = SDL_WINDOW_SHOWN; //| SDL_WINDOW_FULLSCREEN_DESKTOP;
    SDL_Window * m_window;
    SDL_Renderer * m_renderer;

    IMG_Init(IMG_INIT_PNG);

    SDL_Init( SDL_flags );
    SDL_CreateWindowAndRenderer( 1280, 720, WND_flags, &m_window, &m_renderer );
    //Pass the focus to the drawing window
    SDL_RaiseWindow(m_window);
    //Get screen resolution
    SDL_DisplayMode DM;
    SDL_GetCurrentDisplayMode(0, &DM);
    int W = DM.w;
    int H = DM.h;
    SDL_Event e;
    e.type = 0;


    SDL_SetWindowFullscreen(m_window, SDL_WINDOW_FULLSCREEN_DESKTOP);

    Uint32 currentTime = SDL_GetTicks();

    Mix_OpenAudio( 44100, MIX_DEFAULT_FORMAT, 2, 2048 );
    Mix_Chunk* MeowSound1 = Mix_LoadWAV("sounds/Meow.wav");


    // Initialize TTF
    if (TTF_Init() == -1) {
        cout << "TTF could not initialize! Error: " << TTF_GetError() << endl;
    }
    // Loading from your "fonts" folder
    TTF_Font* menu_font_normal = TTF_OpenFont("fonts/menu_font.ttf", 23);
    TTF_Font* menu_font_clicked = TTF_OpenFont("fonts/menu_font.ttf", 25);

    //saving ribbon font
    TTF_Font* saving_ribbon = TTF_OpenFont("fonts/main_icon.ttf", 37);


    //for under code menu ribbon buttons
    TTF_Font* under_code_font = TTF_OpenFont("fonts/simple.ttf", 12);
    TTF_Font* under_code_font2 = TTF_OpenFont("fonts/simple.ttf", 15);

    //font for code blocks.
    TTF_Font* code_block = TTF_OpenFont("fonts/simple.ttf", 17);

    //main say and think font
    TTF_Font* mainsaythinkfont = TTF_OpenFont("fonts/simple.ttf", 13);



    if (!menu_font_clicked or !menu_font_normal or !under_code_font or !under_code_font2 or !code_block) {
        cout << "Failed to load fonts! Error: " << TTF_GetError() << endl;
    }


    double k = 1.05;
    double enl = 1.25;
    CurveyRect code_menu_button = {int(2 * enl), int(50 * enl), int(20 * enl), int(100 * enl), int(50 * enl)};
    CurveyRect costumes_menu_button = {int(98 * enl), int(50 * enl), int(20 * enl), int(100 * enl), int(50 * enl)};
    CurveyRect sounds_menu_button = {int(200 * enl), int(50 * enl), int(20 * enl), int(100 * enl), int(50 * enl)};
    CurveyRect code_menu_button2 = {code_menu_button.x, int(code_menu_button.y - (k-1) * code_menu_button.h), int(code_menu_button.r * k), int(code_menu_button.w * k), int(code_menu_button.h*k)};
    CurveyRect costumes_menu_button2 = {costumes_menu_button.x, int(costumes_menu_button.y - (k-1) * costumes_menu_button.h), int(costumes_menu_button.r * k), int(costumes_menu_button.w * k), int(costumes_menu_button.h*k)};
    CurveyRect sounds_menu_button2 = {sounds_menu_button.x, int(sounds_menu_button.y - (k-1) * sounds_menu_button.h), int(sounds_menu_button.r * k), int(sounds_menu_button.w * k), int(sounds_menu_button.h*k)};

    double co=1.25;
    //for code menu buttons.
    int dButton = 60; int r = 28, initial_y = code_menu_button.y+code_menu_button.h + 20;
    //motion
    RibbonButton motion = {(code_menu_button.w-20)/2, int((initial_y) * enl) , int(r*enl)};
    motion.vertices();
    RibbonButton motion2 = {(code_menu_button.w-20)/2, int(initial_y * enl) , int(r*co * enl)};
    motion2.vertices();

    //looks
    RibbonButton looks = {(code_menu_button.w-20)/2, int((initial_y + dButton) * enl) , int(r*enl)};
    looks.vertices();
    RibbonButton looks2 = {(code_menu_button.w-20)/2, int((initial_y + dButton) * enl) , int(r*co * enl)};
    looks2.vertices();

    //sound
    RibbonButton sound = {(code_menu_button.w-20)/2, int((initial_y + 2  * dButton) * enl) , int(r*enl)};
    sound.vertices();
    RibbonButton sound2 = {(code_menu_button.w-20)/2, int((initial_y + 2  * dButton) * enl) , int(r*co * enl)};
    sound2.vertices();
    //events
    RibbonButton events = {(code_menu_button.w-20)/2, int((initial_y + 3  * dButton) * enl) , int(r*enl)};
    events.vertices();
    RibbonButton events2 = {(code_menu_button.w-20)/2, int((initial_y + 3  * dButton) * enl) , int(r*co * enl)};
    events2.vertices();
    //control
    RibbonButton control = {(code_menu_button.w-20)/2, int((initial_y + 4  * dButton) * enl) , int(r*enl)};
    control.vertices();
    RibbonButton control2 = {(code_menu_button.w-20)/2, int((initial_y + 4  * dButton) * enl) , int(r*co * enl)};
    control2.vertices();
    //sensing
    RibbonButton sensing = {(code_menu_button.w-20)/2, int((initial_y + 5  * dButton) * enl) , int(r*enl)};
    sensing.vertices();
    RibbonButton sensing2 = {(code_menu_button.w-20)/2, int((initial_y + 5  * dButton) * enl) , int(r*co * enl)};
    sensing2.vertices();
    //operators
    RibbonButton operators = {(code_menu_button.w-20)/2, int((initial_y + 6  * dButton) * enl) , int(r*enl)};
    operators.vertices();
    RibbonButton operators2 = {(code_menu_button.w-20)/2, int((initial_y + 6  * dButton) * enl) , int(r*co * enl)};
    operators2.vertices();
    //variables
    RibbonButton variables = {(code_menu_button.w-20)/2, int((initial_y + 7  * dButton) * enl) , int(r*enl)};
    variables.vertices();
    RibbonButton variables2 = {(code_menu_button.w-20)/2, int((initial_y + 7  * dButton) * enl) , int(r*co * enl)};
    variables2.vertices();
    //my blocks
    RibbonButton my_blocks = {(code_menu_button.w-20)/2, int((initial_y + 8  * dButton) * enl) , int(r*enl)};
    my_blocks.vertices();
    RibbonButton my_blocks2 = {(code_menu_button.w-20)/2, int((initial_y + 8  * dButton) * enl) ,int(r*co * enl)};
    my_blocks2.vertices();






    //fonts and texts
    //code menu normal
    SDL_Surface* code_menu_surf = TTF_RenderText_Blended(menu_font_normal, "Code", menu_text_yellow);
    SDL_Texture* code_menu_tex = SDL_CreateTextureFromSurface(m_renderer, code_menu_surf);
    SDL_Rect code_menu_text_rect = { code_menu_button.x + (code_menu_button.w - code_menu_surf->w)/2, code_menu_button.y + (code_menu_button.y - code_menu_surf->h)/2, code_menu_surf->w, code_menu_surf->h };
    //code menu when clicked
    SDL_Surface* code_menu_surf2 = TTF_RenderText_Blended(menu_font_clicked, "Code", menu_text_yellow2);
    SDL_Texture* code_menu_tex2 = SDL_CreateTextureFromSurface(m_renderer, code_menu_surf2);
    SDL_Rect code_menu_text_rect2 = { code_menu_button2.x + (code_menu_button2.w - code_menu_surf2->w)/2, code_menu_button2.y + (code_menu_button2.y - code_menu_surf2->h)/2, code_menu_surf2->w, code_menu_surf2->h };
    //costumes menu normal
    SDL_Surface* costumes_menu_surf = TTF_RenderText_Blended(menu_font_normal, "Costumes", menu_text_yellow);
    SDL_Texture* costumes_menu_tex = SDL_CreateTextureFromSurface(m_renderer, costumes_menu_surf);
    SDL_Rect costumes_menu_text_rect = { costumes_menu_button.x + (costumes_menu_button.w - costumes_menu_surf->w)/2, costumes_menu_button.y + (costumes_menu_button.y - costumes_menu_surf->h)/2, costumes_menu_surf->w, costumes_menu_surf->h };
    //costumes menu when clicked
    SDL_Surface* costumes_menu_surf2 = TTF_RenderText_Blended(menu_font_clicked, "Costumes", menu_text_yellow2);
    SDL_Texture* costumes_menu_tex2 = SDL_CreateTextureFromSurface(m_renderer, costumes_menu_surf2);
    SDL_Rect costumes_menu_text_rect2 = { costumes_menu_button2.x + (costumes_menu_button2.w - costumes_menu_surf2->w)/2, costumes_menu_button2.y + (costumes_menu_button2.y - costumes_menu_surf2->h)/2, costumes_menu_surf2->w, costumes_menu_surf2->h };
    //sounds menu normal
    SDL_Surface* sounds_menu_surf = TTF_RenderText_Blended(menu_font_normal, "Sounds", menu_text_yellow);
    SDL_Texture* sounds_menu_tex = SDL_CreateTextureFromSurface(m_renderer, sounds_menu_surf);
    SDL_Rect sounds_menu_text_rect = { sounds_menu_button.x + (sounds_menu_button.w - sounds_menu_surf->w)/2, sounds_menu_button.y + (sounds_menu_button.y - sounds_menu_surf->h)/2, sounds_menu_surf->w, sounds_menu_surf->h };
    //sounds menu when clicked
    SDL_Surface* sounds_menu_surf2 = TTF_RenderText_Blended(menu_font_clicked, "Sounds", menu_text_yellow2);
    SDL_Texture* sounds_menu_tex2 = SDL_CreateTextureFromSurface(m_renderer, sounds_menu_surf2);
    SDL_Rect sounds_menu_text_rect2 = { sounds_menu_button2.x + (sounds_menu_button2.w - sounds_menu_surf2->w)/2, sounds_menu_button2.y + (sounds_menu_button2.y - sounds_menu_surf2->h)/2, sounds_menu_surf2->w, sounds_menu_surf2->h };

    //under code menu ribbon buttons.
    //motion normal
    SDL_Surface* motion_surf = TTF_RenderText_Blended(under_code_font, "Motion", black);
    SDL_Texture* motion_tex = SDL_CreateTextureFromSurface(m_renderer, motion_surf);
    SDL_Rect motion_text_rect = {motion.x - motion_surf->w / 2, motion.y-motion_surf->h/2, motion_surf->w, motion_surf->h};
    //clicked
    SDL_Surface* motion2_surf = TTF_RenderText_Blended(under_code_font2, "Motion", gray);
    SDL_Texture* motion2_tex = SDL_CreateTextureFromSurface(m_renderer, motion2_surf);
    SDL_Rect motion2_text_rect = {motion2.x-motion2_surf->w/2, motion2.y-motion2_surf->h/2, motion2_surf->w, motion2_surf->h};
    //looks
    SDL_Surface* looks_surf = TTF_RenderText_Blended(under_code_font, "Looks", black);
    SDL_Texture* looks_tex = SDL_CreateTextureFromSurface(m_renderer, looks_surf);
    SDL_Rect looks_text_rect = {looks.x-looks_surf->w/2, looks.y-looks_surf->h/2, looks_surf->w, looks_surf->h};
    //clicked
    SDL_Surface* looks2_surf = TTF_RenderText_Blended(under_code_font2, "Looks", gray);
    SDL_Texture* looks2_tex = SDL_CreateTextureFromSurface(m_renderer, looks2_surf);
    SDL_Rect looks2_text_rect = {looks2.x-looks2_surf->w/2, looks2.y-looks2_surf->h/2, looks2_surf->w, looks2_surf->h};
    //sound
    SDL_Surface* sound_surf = TTF_RenderText_Blended(under_code_font, "Sound", black);
    SDL_Texture* sound_tex = SDL_CreateTextureFromSurface(m_renderer, sound_surf);
    SDL_Rect sound_text_rect = {sound.x-sound_surf->w/2, sound.y-sound_surf->h/2, sound_surf->w, sound_surf->h};
    //clicked
    SDL_Surface* sound2_surf = TTF_RenderText_Blended(under_code_font2, "Sound", gray);
    SDL_Texture* sound2_tex = SDL_CreateTextureFromSurface(m_renderer, sound2_surf);
    SDL_Rect sound2_text_rect = {sound2.x-sound2_surf->w/2, sound2.y-sound2_surf->h/2, sound2_surf->w, sound2_surf->h};
    //events
    SDL_Surface* events_surf = TTF_RenderText_Blended(under_code_font, "Events", black);
    SDL_Texture* events_tex = SDL_CreateTextureFromSurface(m_renderer, events_surf);
    SDL_Rect events_text_rect = {events.x-events_surf->w/2, events.y-events_surf->h/2, events_surf->w, events_surf->h};
    //clicked
    SDL_Surface* events2_surf = TTF_RenderText_Blended(under_code_font2, "Events", gray);
    SDL_Texture* events2_tex = SDL_CreateTextureFromSurface(m_renderer, events2_surf);
    SDL_Rect events2_text_rect = {events2.x-events2_surf->w/2, events2.y-events2_surf->h/2, events2_surf->w, events2_surf->h};
    //control
    SDL_Surface* control_surf = TTF_RenderText_Blended(under_code_font, "Control", black);
    SDL_Texture* control_tex = SDL_CreateTextureFromSurface(m_renderer, control_surf);
    SDL_Rect control_text_rect = {control.x-control_surf->w/2, control.y-control_surf->h/2, control_surf->w, control_surf->h};
    //clicked
    SDL_Surface* control2_surf = TTF_RenderText_Blended(under_code_font2, "Control", gray);
    SDL_Texture* control2_tex = SDL_CreateTextureFromSurface(m_renderer, control2_surf);
    SDL_Rect control2_text_rect = {control2.x-control2_surf->w/2, control2.y-control2_surf->h/2, control2_surf->w, control2_surf->h};
    //sensing
    SDL_Surface* sensing_surf = TTF_RenderText_Blended(under_code_font, "Sensing", black);
    SDL_Texture* sensing_tex = SDL_CreateTextureFromSurface(m_renderer, sensing_surf);
    SDL_Rect sensing_text_rect = {sensing.x-sensing_surf->w/2, sensing.y-sensing_surf->h/2, sensing_surf->w, sensing_surf->h};
    //clicked
    SDL_Surface* sensing2_surf = TTF_RenderText_Blended(under_code_font2, "Sensing", gray);
    SDL_Texture* sensing2_tex = SDL_CreateTextureFromSurface(m_renderer, sensing2_surf);
    SDL_Rect sensing2_text_rect = {sensing2.x-sensing2_surf->w/2, sensing2.y-sensing2_surf->h/2, sensing2_surf->w, sensing2_surf->h};
    //operators
    SDL_Surface* operators_surf = TTF_RenderText_Blended(under_code_font, "Operators", black);
    SDL_Texture* operators_tex = SDL_CreateTextureFromSurface(m_renderer, operators_surf);
    SDL_Rect operators_text_rect = {operators.x-operators_surf->w/2, operators.y-operators_surf->h/2, operators_surf->w, operators_surf->h};
    //clicked
    SDL_Surface* operators2_surf = TTF_RenderText_Blended(under_code_font2, "Operators", gray);
    SDL_Texture* operators2_tex = SDL_CreateTextureFromSurface(m_renderer, operators2_surf);
    SDL_Rect operators2_text_rect = {operators2.x-operators2_surf->w/2, operators2.y-operators2_surf->h/2, operators2_surf->w, operators2_surf->h};
    //variables
    SDL_Surface* variables_surf = TTF_RenderText_Blended(under_code_font, "Variables", black);
    SDL_Texture* variables_tex = SDL_CreateTextureFromSurface(m_renderer, variables_surf);
    SDL_Rect variables_text_rect = {variables.x-variables_surf->w/2, variables.y-variables_surf->h/2, variables_surf->w, variables_surf->h};
    //clicked
    SDL_Surface* variables2_surf = TTF_RenderText_Blended(under_code_font2, "Variables", gray);
    SDL_Texture* variables2_tex = SDL_CreateTextureFromSurface(m_renderer, variables2_surf);
    SDL_Rect variables2_text_rect = {variables2.x-variables2_surf->w/2, variables2.y-variables2_surf->h/2, variables2_surf->w, variables2_surf->h};
    //My blocks
    SDL_Surface* my_blocks_surf = TTF_RenderText_Blended(under_code_font, "My blocks", black);
    SDL_Texture* my_blocks_tex = SDL_CreateTextureFromSurface(m_renderer, my_blocks_surf);
    SDL_Rect my_blocks_text_rect = {my_blocks.x-my_blocks_surf->w/2, my_blocks.y-my_blocks_surf->h/2, my_blocks_surf->w, my_blocks_surf->h};
    //clicked
    SDL_Surface* my_blocks2_surf = TTF_RenderText_Blended(under_code_font2, "My blocks", gray);
    SDL_Texture* my_blocks2_tex = SDL_CreateTextureFromSurface(m_renderer, my_blocks2_surf);
    SDL_Rect my_blocks2_text_rect = {my_blocks2.x-my_blocks2_surf->w/2, my_blocks2.y-my_blocks2_surf->h/2, my_blocks2_surf->w, my_blocks2_surf->h};

    //saving ribbon and the rest
    SDL_Surface* my_scratch_sur = TTF_RenderText_Blended(saving_ribbon, "Hexacratch", light_blue);
    SDL_Texture* my_scratch_tex = SDL_CreateTextureFromSurface(m_renderer, my_scratch_sur);
    SDL_Rect my_scratch_rect = {25, 10, my_scratch_sur->w, my_scratch_sur->h};














    SDL_FreeSurface(code_menu_surf);



    int n=5;
    //saving menu rects
    vector<SDL_Rect> save_ribbon(n);
    for(int i=0; i<n; i++){
        save_ribbon[i] = {i, i, DM.w - 2 * i, 20 + my_scratch_sur->h - 2 * i};
    }
    //left ribbon to be drawn.
    vector<SDL_Rect> left_ribbon(n);
    for(int i=0; i<n; i++){
        left_ribbon[i] = {code_menu_button.x+i, code_menu_button.y+i-3 + code_menu_button.h + 3, code_menu_button.w-20-2 * i, DM.h - left_ribbon[i].h};
    }
    //behind main buttons rects
    vector<SDL_Rect> behind_buttons(n);
    for(int i=0; i<n; i++){
        behind_buttons[i] = {save_ribbon[i].x, save_ribbon[0].h,  DM.w - 2 * i, abs(left_ribbon[0].y - save_ribbon[0].h)};
    }
    //blocks scrolling menu
    vector<SDL_Rect> blocks_scrolling_menu(n);
    for(int i=0; i<n; i++){
        blocks_scrolling_menu[i] = {code_menu_button.w-20 + code_menu_button.x+i, code_menu_button.y+i-3 + code_menu_button.h + 3 , 2  * code_menu_button.w + 20 - 2 * i, DM.h - blocks_scrolling_menu[i].h};
    }
    //for code menu blocking system
    vector<SDL_Rect> blocking_system(n);
    for(int i=0; i<n; i++){
        blocking_system[i] = {blocks_scrolling_menu[0].w + blocks_scrolling_menu[0].x+i, code_menu_button.y+i-3 + code_menu_button.h + 3 , int(DM.w/2.9) - 2 * i, DM.h - blocking_system[i].h};
    }
    vector<SDL_Rect> sprite_property(n);
    for(int i=0; i<n; i++){
        sprite_property[i] = {blocking_system[0].w + blocking_system[0].x+i + DM.w / 150, code_menu_button.y+i + code_menu_button.h , DM.w - (sprite_property[i].x) - i, blocking_system[i].h / 2 - 2 * i};
    }
    vector<SDL_Rect> under_sprite(n);
    for(int i=0; i<n; i++){
        under_sprite[i] = {sprite_property[0].x + i, sprite_property[0].y + sprite_property[0].h + i, DM.w - under_sprite[i].x - 2 * i, DM.w - under_sprite[i].y - 2 * i};
    }



    //rest of the fonts also here

    //under sprite territory fonts and stuff

    //choosing sprite
    //text
    SDL_Surface* sprite_choose_sur = TTF_RenderText_Blended(code_block, "Sprite", black);
    SDL_Texture* sprite_choose_tex = SDL_CreateTextureFromSurface(m_renderer, sprite_choose_sur);
    SDL_Rect sprite_choose_rect = {under_sprite[0].x + 50, under_sprite[0].y + 50, sprite_choose_sur->w, sprite_choose_sur->h};
    //input box
    SDL_Rect sprite_name_input = {sprite_choose_rect.x + 50, sprite_choose_rect.y, 300, sprite_choose_rect.h};
    string sprite_name;

    SDL_Surface* sprite_name_sur = TTF_RenderText_Blended(code_block, "Sprite1", black);
    SDL_Texture* sprite_name_tex = SDL_CreateTextureFromSurface(m_renderer, sprite_name_sur);
    SDL_Rect sprite_name_rect = {sprite_name_input.x, sprite_name_input.y, sprite_name_sur->w, sprite_name_sur->h};






    //saving ribbon buttons
    //green go
    double execution_rect_coef = 3.5;
    SDL_Rect execution_rect1 = {sprite_property[0].x, behind_buttons[0].y + behind_buttons[0].h / 3, int(10 * execution_rect_coef), int(5 * execution_rect_coef)};
    SDL_Rect execution_rect2 = {sprite_property[0].x, behind_buttons[0].y + behind_buttons[0].h / 3, int(2 * execution_rect_coef), int(10 * execution_rect_coef)};
    //red stop
    Circle terminate_circle = {execution_rect1.x + 60, execution_rect2.y + execution_rect2.h/2 + 1, execution_rect2.h/2};




    //defining blocks

    //distancing from the top----------------------------
    int dist1 = DM.h / 20;
    int dist2 = DM.h / 10;
    int dist3 = (DM.h / 20) + 50;
    int blockH = 35;

    //---------------------------------------------------

    //motion blocks
    menu_block_motion[0].y = code_menu_button.y + code_menu_button .h + 10;
    arrange(dist1, menu_block_motion);
    for(auto &i:menu_block_motion){
        i.h = blockH;
        i.x = blocks_scrolling_menu[0].x + 20;
        i.color = blue;
        i.font = code_block;
        i.opCode = "move";
    }
    menu_block_motion[0].opCode = "move"; menu_block_motion[0].input1 = "10"; menu_block_motion[0].input2 = " ";
    menu_block_motion[1].opCode = "turn right"; menu_block_motion[1].input1 = "15"; menu_block_motion[1].input2 = " ";
    menu_block_motion[2].opCode = "turn left"; menu_block_motion[2].input1 = "15"; menu_block_motion[2].input2 = " ";
    menu_block_motion[3].opCode = "go to"; menu_block_motion[3].input1 = "random pos"; menu_block_motion[3].input2 = " ";
    menu_block_motion[4].opCode = "go to:"; menu_block_motion[4].input1 = "0"; menu_block_motion[4].input2 = "0";
    menu_block_motion[5].opCode = "glide"; menu_block_motion[5].input1 = "0"; menu_block_motion[5].input2 = "random pos";
//    menu_block_motion[6].opCode = "glide:"; menu_block_motion[6].input1 = "0"; menu_block_motion[6].input2 = "0";
    menu_block_motion[7].opCode = "point in direction"; menu_block_motion[7].input1 = "90"; menu_block_motion[7].input2 = " ";
    menu_block_motion[8].opCode = "point towards"; menu_block_motion[8].input1 = "mouse"; menu_block_motion[8].input2 = " ";
    menu_block_motion[9].opCode = "change x by"; menu_block_motion[9].input1 = "10"; menu_block_motion[9].input2 = " ";
    menu_block_motion[10].opCode = "set x to"; menu_block_motion[10].input1 = "0"; menu_block_motion[10].input2 = " ";
    menu_block_motion[11].opCode = "change y by"; menu_block_motion[11].input1 = "10"; menu_block_motion[11].input2 = " ";
    menu_block_motion[12].opCode = "set y to"; menu_block_motion[12].input1 = "0"; menu_block_motion[12].input2 = " ";
    menu_block_motion[13].opCode = "if on edge"; menu_block_motion[13].input1 = "bounce"; menu_block_motion[13].input2 = " ";
    menu_block_motion[14].opCode = "rotation style"; menu_block_motion[14].input1 = "left-right"; menu_block_motion[14].input2 = " ";

    //looks blocks
    menu_block_looks[0].y = code_menu_button.y + code_menu_button.h + 10;
    arrange(dist1, menu_block_looks);
    for(auto &i:menu_block_looks){
        i.h = blockH;
        i.x = blocks_scrolling_menu[0].x + 20;
        i.color = purple;
        i.font = code_block;
        i.opCode = "say";
    }
    menu_block_looks[0].opCode = "say"; menu_block_looks[0].input1 = "Hello!"; menu_block_looks[0].input2 = "2";
    menu_block_looks[1].opCode = "say"; menu_block_looks[1].input1 = "Hello!"; menu_block_looks[1].input2 = " ";
    menu_block_looks[2].opCode = "think"; menu_block_looks[2].input1 = "hmm..."; menu_block_looks[2].input2 = "2";
    menu_block_looks[3].opCode = "think"; menu_block_looks[3].input1 = "hmm..."; menu_block_looks[3].input2 = " ";
    menu_block_looks[4].opCode = "switch custom to"; menu_block_looks[4].input1 = "cs1"; menu_block_looks[4].input2 = " ";
    menu_block_looks[5].opCode = "next costume"; menu_block_looks[5].input1 = " "; menu_block_looks[5].input2 = " ";
    menu_block_looks[6].opCode = "switch bkgr to"; menu_block_looks[6].input1 = "bkgr1"; menu_block_looks[6].input2 = " ";
    menu_block_looks[7].opCode = "next background"; menu_block_looks[7].input1 = " "; menu_block_looks[7].input2 = " ";
    menu_block_looks[8].opCode = "change size by"; menu_block_looks[8].input1 = "10"; menu_block_looks[8].input2 = " ";
    menu_block_looks[9].opCode = "set size to"; menu_block_looks[9].input1 = "100"; menu_block_looks[9].input2 = " ";
    menu_block_looks[10].opCode = "change"; menu_block_looks[10].input1 = "color by"; menu_block_looks[10].input2 = "25";
    menu_block_looks[11].opCode = "set"; menu_block_looks[11].input1 = "color to"; menu_block_looks[11].input2 = "0";
    menu_block_looks[12].opCode = "clear graphic effect"; menu_block_looks[12].input1 = " "; menu_block_looks[12].input2 = " ";
    menu_block_looks[13].opCode = "show"; menu_block_looks[13].input1 = " "; menu_block_looks[13].input2 = " ";
    menu_block_looks[14].opCode = "hide"; menu_block_looks[14].input1 = " "; menu_block_looks[14].input2 = " ";
    menu_block_looks[15].opCode = "go to"; menu_block_looks[15].input1 = "font"; menu_block_looks[15].input2 = "layer";
    menu_block_looks[16].opCode = "go in layers"; menu_block_looks[16].input1 = "forward"; menu_block_looks[16].input2 = "1";

    //sound blocks
    menu_block_sound[0].y = code_menu_button.y + code_menu_button.h + 10;
    arrange(dist3, menu_block_sound);
    for(auto &i:menu_block_sound){
        i.h = blockH;
        i.x = blocks_scrolling_menu[0].x + 20;
        i.color = dark_purple;
        i.font = code_block;
        i.opCode = "set";
    }
    menu_block_sound[0].opCode = "play sound"; menu_block_sound[0].input1 = "Meow"; menu_block_sound[0].input2 = " ";
    menu_block_sound[1].opCode = "start sound"; menu_block_sound[1].input1 = "Meow"; menu_block_sound[1].input2 = " ";
    menu_block_sound[2].opCode = "stop all sounds"; menu_block_sound[2].input1 = " "; menu_block_sound[2].input2 = " ";
    menu_block_sound[3].opCode = "change effect"; menu_block_sound[3].input1 = "pitch"; menu_block_sound[3].input2 = "10";
    menu_block_sound[4].opCode = "set effect"; menu_block_sound[4].input1 = "pitch"; menu_block_sound[4].input2 = "100";
    menu_block_sound[5].opCode = "clear sound effects"; menu_block_sound[5].input1 = " "; menu_block_sound[5].input2 = " ";
    menu_block_sound[6].opCode = "change volume by"; menu_block_sound[6].input1 = "-10"; menu_block_sound[6].input2 = " ";
    menu_block_sound[7].opCode = "set volume to"; menu_block_sound[7].input1 = "100"; menu_block_sound[7].input2 = " ";

    //events blocks
    menu_block_events[0].y = code_menu_button.y + code_menu_button.h + 30;
    arrange(dist2, menu_block_events);
    for(auto &i:menu_block_events){
        i.h = blockH;
        i.x = blocks_scrolling_menu[0].x + 16;
        i.color = yellow;
        i.font = code_block;
        i.opCode = "set";
    }
    menu_block_events[0].opCode = "when flag clicked"; menu_block_events[0].input1 = " "; menu_block_events[0].input2 = " ";
    menu_block_events[1].opCode = "when key pressed"; menu_block_events[1].input1 = "space"; menu_block_events[1].input2 = " ";
    menu_block_events[2].opCode = "when this sprite clicked"; menu_block_events[2].input1 = " "; menu_block_events[2].input2 = " ";
    menu_block_events[3].opCode = "when bkgr goes to"; menu_block_events[3].input1 = "bkgr1"; menu_block_events[3].input2 = " ";
    menu_block_events[4].opCode = "when greater"; menu_block_events[4].input1 = "loudness"; menu_block_events[4].input2 = "10";
    menu_block_events[5].opCode = "when I receive"; menu_block_events[5].input1 = "msg1"; menu_block_events[5].input2 = " ";
    menu_block_events[6].opCode = "broadcast"; menu_block_events[6].input1 = "msg1"; menu_block_events[6].input2 = " ";
    menu_block_events[7].opCode = "broadcast & wait"; menu_block_events[7].input1 = "msg1"; menu_block_events[7].input2 = " ";

    //control blocks


















































    //mouse points to...
    SDL_Point curser;


    //temp integer
    int dragmouseX;
    int dragmouseY;
    bool mousebl2=false;
    bool mousebl3=false;

    //sprites


    // mainsprite player1;
    // player1.texture = loadtexture("images/player.png", m_renderer);
    // player1.x = 1000;
    // player1.y = 200;
    // player1.w = 50;
    // player1.h = 50;

    mainsprite player2;
    player2.texture = loadtexture("images/player.png", m_renderer);
    player2.x = 1300;
    player2.y = 300;
    player2.w = 100;
    player2.h = 100;
    player2.setcenter();

    //this is where the real stuff is happening.
    //dragging variables
    //------------------------------------------
    block1 tempDraggingBlock;
    bool isDragging = false;
    int dragOffsetX = 0;
    int dragOffsetY = 0;
    int draggingindex=-1;
    //------------------------------------------
    vector<block1> program; //every block dragged in is in here
    bool Running = true;
    bool clicked_code_menu = true, clicked_costumes_menu = false, clicked_sounds_menu = false;
    bool clicked_motion=true, clicked_looks=false, clicked_sound=false, clicked_events=false, clicked_control=false, clicked_sensing=false, clicked_operators=false, clicked_variables=false, clicked_my_blocks = false;
    int activeBlockIndex = -1, activeBoxSide = 0;
    bool clicked_sprite_name_box = false;

    //flag clicking
    bool clicked_flag = false, clicked_redCircle = false;
    //--------------------------------------------------------------------------------
    //the main loop
    //--------------------------------------------------------------------------------
    while(Running){

        for (int i=0; i<program.size(); i++)
        {
            program[i].topSnap = {program[i].x + program[i].w/2, program[i].y};
            program[i].bottomSnap = {program[i].x + program[i].w/2,program[i].y + program[i].h};
        }

        SDL_GetMouseState(&curser.x, &curser.y);
        while(SDL_PollEvent(&e)) {
            if (e.type == SDL_QUIT)Running = false;
                //following condition for text.
            else if (e.type == SDL_KEYDOWN) {
                if (e.key.keysym.sym == SDLK_ESCAPE)Running = false;

            }




            //for checking click on different icons.
            if (e.type == SDL_MOUSEBUTTONDOWN) {
                if (e.button.button == SDL_BUTTON_LEFT)
                {
                    if (PointInCurveyRect(&curser, &code_menu_button)) {
                        clicked_code_menu = true;
                        clicked_costumes_menu = false;
                        clicked_sounds_menu = false;
                    }
                    if (PointInCurveyRect(&curser, &costumes_menu_button)) {
                        clicked_code_menu = false;
                        clicked_costumes_menu = true;
                        clicked_sounds_menu = false;
                    }
                    if (PointInCurveyRect(&curser, &sounds_menu_button)) {
                        clicked_code_menu = false;
                        clicked_costumes_menu = false;
                        clicked_sounds_menu = true;
                    }

                    if (pointInRibbonButton(&curser, &motion)) {
                        clicked_motion = true, clicked_looks = false, clicked_sound = false, clicked_events = false, clicked_control = false, clicked_sensing = false, clicked_operators = false, clicked_variables = false, clicked_my_blocks = false;
                    }
                    if (pointInRibbonButton(&curser, &looks)) {
                        clicked_motion = false, clicked_looks = true, clicked_sound = false, clicked_events = false, clicked_control = false, clicked_sensing = false, clicked_operators = false, clicked_variables = false, clicked_my_blocks = false;
                    }
                    if (pointInRibbonButton(&curser, &sound)) {
                        clicked_motion = false, clicked_looks = false, clicked_sound = true, clicked_events = false, clicked_control = false, clicked_sensing = false, clicked_operators = false, clicked_variables = false, clicked_my_blocks = false;
                    }
                    if (pointInRibbonButton(&curser, &events)) {
                        clicked_motion = false, clicked_looks = false, clicked_sound = false, clicked_events = true, clicked_control = false, clicked_sensing = false, clicked_operators = false, clicked_variables = false, clicked_my_blocks = false;
                    }
                    if (pointInRibbonButton(&curser, &control)) {
                        clicked_motion = false, clicked_looks = false, clicked_sound = false, clicked_events = false, clicked_control = true, clicked_sensing = false, clicked_operators = false, clicked_variables = false, clicked_my_blocks = false;
                    }
                    if (pointInRibbonButton(&curser, &sensing)) {
                        clicked_motion = false, clicked_looks = false, clicked_sound = false, clicked_events = false, clicked_control = false, clicked_sensing = true, clicked_operators = false, clicked_variables = false, clicked_my_blocks = false;
                    }
                    if (pointInRibbonButton(&curser, &operators)) {
                        clicked_motion = false, clicked_looks = false, clicked_sound = false, clicked_events = false, clicked_control = false, clicked_sensing = false, clicked_operators = true, clicked_variables = false, clicked_my_blocks = false;
                    }
                    if (pointInRibbonButton(&curser, &variables)) {
                        clicked_motion = false, clicked_looks = false, clicked_sound = false, clicked_events = false, clicked_control = false, clicked_sensing = false, clicked_operators = false, clicked_variables = true, clicked_my_blocks = false;
                    }
                    if (pointInRibbonButton(&curser, &my_blocks)) {
                        clicked_motion = false, clicked_looks = false, clicked_sound = false, clicked_events = false, clicked_control = false, clicked_sensing = false, clicked_operators = false, clicked_variables = false, clicked_my_blocks = true;
                    }

                    dragmouseX = e.button.x;
                    dragmouseY = e.button.y;

                    for(int i=0; i < program.size(); i++) {
                        if (mouseIsInside2(program, dragmouseX, dragmouseY,i)) {
                            dragging = true;
                            drag_x = dragmouseX-program[i].x;
                            drag_y = dragmouseY-program[i].y;
                            mousebl2 = true;
                            program[i].isdrag = true;
                            draggingindex= i;

                        }
                    }

                    //writing in the boxes-----------------------------------------

                    bool clickedAnything = false;
                    //for motion boxes
                    // ----------------------------------------------------------------------------
                    if(clicked_motion){
                        for(int i=0; i<menu_block_motion.size(); i++){
                            auto &b = menu_block_motion[i];
                            if(SDL_PointInRect(&curser, &b.text_box1)){
                                activeBlockIndex = i; activeBoxSide = 1; clickedAnything = true;
                            }
                            if(SDL_PointInRect(&curser, &b.text_box2)){
                                activeBlockIndex = i; activeBoxSide = 2; clickedAnything = true;
                            }
                        }
                    }
                    if(!clickedAnything){
                        activeBlockIndex = -1; activeBoxSide = 0;
                    }
                    for(int j=0; j<menu_block_motion.size(); j++){
                        menu_block_motion[j].isFocused1 = (activeBlockIndex == j and activeBoxSide == 1);
                        menu_block_motion[j].isFocused2 = (activeBlockIndex == j and activeBoxSide == 2);
                    }
                    // ----------------------------------------------------------------------------
                    //for looks boxes
                    // ----------------------------------------------------------------------------
                    if(clicked_looks){
                        for(int i=0; i<menu_block_looks.size(); i++){
                            auto &b = menu_block_looks[i];
                            if(SDL_PointInRect(&curser, &b.text_box1)){
                                activeBlockIndex = i; activeBoxSide = 1; clickedAnything = true;
                            }
                            if(SDL_PointInRect(&curser, &b.text_box2)){
                                activeBlockIndex = i; activeBoxSide = 2; clickedAnything = true;
                            }
                        }
                    }
                    if(!clickedAnything){
                        activeBlockIndex = -1; activeBoxSide = 0;
                    }
                    for(int j=0; j<menu_block_looks.size(); j++){
                        menu_block_looks[j].isFocused1 = (activeBlockIndex == j and activeBoxSide == 1);
                        menu_block_looks[j].isFocused2 = (activeBlockIndex == j and activeBoxSide == 2);
                    }
                    // ----------------------------------------------------------------------------
                    if(clicked_sound){
                        for(int i=0; i<menu_block_sound.size(); i++){
                            auto &b = menu_block_sound[i];
                            if(SDL_PointInRect(&curser, &b.text_box1)){
                                activeBlockIndex = i; activeBoxSide = 1; clickedAnything = true;
                            }
                            if(SDL_PointInRect(&curser, &b.text_box2)){
                                activeBlockIndex = i; activeBoxSide = 2; clickedAnything = true;
                            }
                        }
                    }
                    if(!clickedAnything){
                        activeBlockIndex = -1; activeBoxSide = 0;
                    }
                    for(int j=0; j<menu_block_sound.size(); j++){
                        menu_block_sound[j].isFocused1 = (activeBlockIndex == j and activeBoxSide == 1);
                        menu_block_sound[j].isFocused2 = (activeBlockIndex == j and activeBoxSide == 2);
                    }
                    // ----------------------------------------------------------------------------
                    //for events boxes
                    // ----------------------------------------------------------------------------
                    if(clicked_events){
                        for(int i=0; i<menu_block_events.size(); i++){
                            auto &b = menu_block_events[i];
                            if(SDL_PointInRect(&curser, &b.text_box1)){
                                activeBlockIndex = i; activeBoxSide = 1; clickedAnything = true;
                            }
                            if(SDL_PointInRect(&curser, &b.text_box2)){
                                activeBlockIndex = i; activeBoxSide = 2; clickedAnything = true;
                            }
                        }
                    }
                    if(!clickedAnything){
                        activeBlockIndex = -1; activeBoxSide = 0;
                    }
                    for(int j=0; j<menu_block_events.size(); j++){
                        menu_block_events[j].isFocused1 = (activeBlockIndex == j and activeBoxSide == 1);
                        menu_block_events[j].isFocused2 = (activeBlockIndex == j and activeBoxSide == 2);
                    }
                    // ----------------------------------------------------------------------------
                    vector<block1> *activeMenu = nullptr;
                    if(clicked_motion) activeMenu = &menu_block_motion;
                    else if(clicked_looks) activeMenu = &menu_block_looks;
                    else if(clicked_sound) activeMenu = &menu_block_sound;
                    else if(clicked_events) activeMenu = &menu_block_events;
                    if(activeMenu){
                        for(auto& b : *activeMenu){
                            if(pointInBlock1(&curser, &b)){
                                isDragging = true;
                                tempDraggingBlock = b;
                                dragOffsetX = curser.x - b.x;
                                dragOffsetY = curser.y - b.y;
                                break;
                            }
                        }
                    }
                    if(SDL_PointInRect(&curser, &execution_rect1) or SDL_PointInRect(&curser, &execution_rect2)){
                        clicked_flag = !clicked_flag;
                    }
                    if(PointInCircle(&curser, &terminate_circle)){
                        clicked_redCircle = !clicked_redCircle;
                    }

                    //for entering sprites name
                    if(SDL_PointInRect(&curser, &sprite_name_rect)){
                        clicked_sprite_name_box = true;
                        SDL_StartTextInput();
                    }
                    else{
                        clicked_sprite_name_box = false;
                        SDL_StopTextInput();
                    }
                }
            }



            if(e.type == SDL_MOUSEMOTION and isDragging){
                tempDraggingBlock.x = curser.x - dragOffsetX;
                tempDraggingBlock.y = curser.y - dragOffsetY;
                //sth the man thinks I GOT????
            }
            if(e.type == SDL_MOUSEBUTTONUP and e.button.button == SDL_BUTTON_LEFT){
                if(isDragging){
                    SDL_Point dropPoint = {tempDraggingBlock.x, tempDraggingBlock.y};
                    if(SDL_PointInRect(&dropPoint, &blocking_system[0])){
                        bool snap = false;
                        if (program.empty())
                        {
                            program.push_back(tempDraggingBlock);
                        }
                        else
                        {
                            for (int i=0; i<program.size(); i++)
                            {
                                block1 &b = program[i];

                                int distY1 = abs(tempDraggingBlock.y - b.y-b.h);

                                if (distY1 < 15)
                                {
                                    program.insert(program.begin()+i+1, tempDraggingBlock);
                                    snap = true;
                                    break;
                                }
                            }
                            if (!snap)
                            {
                                program.push_back(tempDraggingBlock);
                            }
                        }
                        // arrangeprogram(program);
                    }
                    isDragging = false;
                }
            }

            //writing in blocks
            //for motion boxes
            // ----------------------------------------------------------------------------
            if(clicked_motion){
                if (activeBlockIndex != -1) {
                    auto &currentBlock = menu_block_motion[activeBlockIndex];
                    string *target = (activeBoxSide == 1) ? &currentBlock.input1 :
                                     (activeBoxSide == 2) ? &currentBlock.input2 : nullptr;
                    if (target) {
                        if (e.type == SDL_TEXTINPUT) {
                            *target += e.text.text;
                        } else if (e.type == SDL_KEYDOWN) {
                            if (e.key.keysym.sym == SDLK_BACKSPACE and !target->empty()) {
                                target->pop_back();
                            }
                            if (e.key.keysym.sym == SDLK_RETURN) {
                                activeBlockIndex = -1;
                            }
                        }
                    }
                }
            }
            // ----------------------------------------------------------------------------
            //for looks boxes
            // ----------------------------------------------------------------------------
            if(clicked_looks){
                if (activeBlockIndex != -1) {
                    auto &currentBlock = menu_block_looks[activeBlockIndex];
                    string *target = (activeBoxSide == 1) ? &currentBlock.input1 :
                                     (activeBoxSide == 2) ? &currentBlock.input2 : nullptr;
                    if (target) {
                        if (e.type == SDL_TEXTINPUT) {
                            *target += e.text.text;
                        } else if (e.type == SDL_KEYDOWN) {
                            if (e.key.keysym.sym == SDLK_BACKSPACE and !target->empty()) {
                                target->pop_back();
                            }
                            if (e.key.keysym.sym == SDLK_RETURN) {
                                activeBlockIndex = -1;
                            }
                        }
                    }
                }
            }
            // ----------------------------------------------------------------------------
            //for sound boxes
            // ----------------------------------------------------------------------------
            if(clicked_sound){
                if (activeBlockIndex != -1) {
                    auto &currentBlock = menu_block_sound[activeBlockIndex];
                    string *target = (activeBoxSide == 1) ? &currentBlock.input1 :
                                     (activeBoxSide == 2) ? &currentBlock.input2 : nullptr;
                    if (target) {
                        if (e.type == SDL_TEXTINPUT) {
                            *target += e.text.text;
                        } else if (e.type == SDL_KEYDOWN) {
                            if (e.key.keysym.sym == SDLK_BACKSPACE and !target->empty()) {
                                target->pop_back();
                            }
                            if (e.key.keysym.sym == SDLK_RETURN) {
                                activeBlockIndex = -1;
                            }
                        }
                    }
                }
            }
            // ----------------------------------------------------------------------------
            //for events boxes
            // ----------------------------------------------------------------------------
            if(clicked_events){
                if (activeBlockIndex != -1) {
                    auto &currentBlock = menu_block_events[activeBlockIndex];
                    string *target = (activeBoxSide == 1) ? &currentBlock.input1 :
                                     (activeBoxSide == 2) ? &currentBlock.input2 : nullptr;
                    if (target) {
                        if (e.type == SDL_TEXTINPUT) {
                            *target += e.text.text;
                        } else if (e.type == SDL_KEYDOWN) {
                            if (e.key.keysym.sym == SDLK_BACKSPACE and !target->empty()) {
                                target->pop_back();
                            }
                            if (e.key.keysym.sym == SDLK_RETURN) {
                                activeBlockIndex = -1;
                            }
                        }
                    }
                }
            }
            // ----------------------------------------------------------------------------

            //for taking sprites name
            if(clicked_sprite_name_box){
                if(e.type == SDL_KEYDOWN){
                    if(e.key.keysym.sym == SDLK_BACKSPACE and !sprite_name.empty()){
                        sprite_name.pop_back();
                    }
                }
                if(e.type == SDL_TEXTINPUT){

                    if(sprite_name.length() < 15){
                        sprite_name += e.text.text;
                    }




                }


            }



        }

        if(clicked_sprite_name_box){
            SDL_FreeSurface(sprite_name_sur);
            SDL_DestroyTexture(sprite_name_tex);
            const char * display_text = sprite_name.empty() ? " " : sprite_name.c_str();

            sprite_name_sur = TTF_RenderText_Blended(code_block, display_text, black);
            sprite_name_tex = SDL_CreateTextureFromSurface(m_renderer, sprite_name_sur);
            sprite_name_rect.w = sprite_name_sur->w;
            sprite_name_rect.h = sprite_name_sur->h;
        }
        SDL_RenderCopy(m_renderer, sprite_name_tex, nullptr, &sprite_name_rect);

        //first rendering the total bkgr
        SDL_SetRenderDrawColor(m_renderer, 50, 50, 50, 255);
        SDL_RenderClear(m_renderer);










        //rendering save ribbon first
        //drawing save ribbon
        for(int i=0; i<n; i++){
            SDL_SetRenderDrawColor(m_renderer, 0, 87+5*i, 87+5*i, 255);
            SDL_RenderFillRect(m_renderer, &save_ribbon[i]);
        }
        //final touch for saving menu
        SDL_SetRenderDrawColor(m_renderer, 150, 150, 150, 150);
        SDL_RenderFillRect(m_renderer, &save_ribbon[4]);
        SDL_RenderCopy(m_renderer, my_scratch_tex, nullptr, &my_scratch_rect);

        //drawing behind button ribbon
        for(int i=0; i<n; i++){
            SDL_SetRenderDrawColor(m_renderer, 0, 87+5*i, 87+5*i, 255);
            SDL_RenderFillRect(m_renderer, &behind_buttons[i]);

        SDL_SetRenderDrawColor(m_renderer, light_gray.r, light_gray.g, light_gray.b, light_gray.a);
        SDL_RenderFillRect(m_renderer, &behind_buttons[4]);
        //green flag.
        if(clicked_flag) SDL_SetRenderDrawColor(m_renderer, deep_orange.r, deep_orange.g, deep_orange.b, deep_orange.a);
        else SDL_SetRenderDrawColor(m_renderer, dark_green.r, dark_green.g, dark_green.b, dark_green.a);
        SDL_RenderFillRect(m_renderer, &execution_rect1); SDL_RenderFillRect(m_renderer, &execution_rect2);
        //red stop circle
        if(clicked_redCircle){
            aaFilledCircleRGBA(m_renderer, terminate_circle.x, terminate_circle.y, terminate_circle.r, purple.r, purple.g, purple.b, purple.a);
        }
        else {
            aaFilledCircleRGBA(m_renderer, terminate_circle.x, terminate_circle.y, terminate_circle.r, 255, 0, 0, 255);

        }

        SDL_RenderCopy(m_renderer, sprite_choose_tex, nullptr, &sprite_choose_rect);


        //sprite property and under it
        for(int i=0; i<n; i++){
            SDL_SetRenderDrawColor(m_renderer, 0, 87+5*i, 87+5*i, 255);
            SDL_RenderFillRect(m_renderer, &sprite_property[i]);
            SDL_RenderFillRect(m_renderer, &under_sprite[i]);
        }
        SDL_SetRenderDrawColor(m_renderer, 240, 240, 240, 255);
        SDL_RenderFillRect(m_renderer, &sprite_property[n-1]);
        SDL_SetRenderDrawColor(m_renderer, 220, 220, 220, 255);
        SDL_RenderFillRect(m_renderer, &under_sprite[n-1]);










            if (e.type == SDL_MOUSEBUTTONUP) {
                if (e.button.button == SDL_BUTTON_LEFT) {
                    dragging = false;
                    mousebl2 = false;
                    mousebl3 = false;
                    isDragging = false;


                    for (int i=0;i<program.size();i++)
                    {
                        if (program[i].isdrag)
                        {
                            program[i].isdrag=false;
                        }
                    }
                    draggingindex=-1;
                }
            }
            if (e.type == SDL_MOUSEMOTION) {
                if (dragging&&mousebl2) {
                    for (int i=0; i<program.size(); i++)
                    {
                        if (program[i].isdrag)
                        {
                            program[i].x = e.motion.x-drag_x;
                            program[i].y = e.motion.y-drag_y;
                        }

                    }

                }

            }

            for (int i=0; i<program.size(); i++)
            {
                if (program[i].x < blocking_system[0].x)
                {
                    program.erase(program.begin()+i);
                }
                if (program[i].y < blocking_system[0].y)
                {
                    program.erase(program.begin()+i);

                }
                if (program[i].x+program[i].w > blocking_system[1].x+blocking_system[0].w)
                {
                    program.erase(program.begin()+i);

                }
                if (program[i].y > blocking_system[1].y+blocking_system[0].h)
                {
                    program.erase(program.begin()+i);

                }
            }

        }





        //magnet
//        magnet1(second_block, third_block);

        for (int i=0; i<program.size(); i++)
        {
            for (int j=0;j<program.size();j++)
            {
                magnetdown(program[j],program[i]);
                magnetup(program[j],program[i]);
            }
        }












        //hovering over menus
        if (!PointInCurveyRect(&curser, &code_menu_button)) {
            curvey_rect_3D(m_renderer, code_menu_button.x, code_menu_button.y, code_menu_button.w, code_menu_button.h, code_menu_button.r, cyan.r, cyan.g, cyan.b, cyan.a);
        }
        else if (PointInCurveyRect(&curser, &code_menu_button)) {
            curvey_rect_3D(m_renderer, code_menu_button.x, code_menu_button.y, code_menu_button.w, code_menu_button.h, code_menu_button.r, dark_cyan.r, dark_cyan.g,dark_cyan.b, dark_cyan.a);
        }

        if (!PointInCurveyRect(&curser, &costumes_menu_button)) {
            curvey_rect_3D(m_renderer, costumes_menu_button.x, costumes_menu_button.y, costumes_menu_button.w, costumes_menu_button.h, costumes_menu_button.r, cyan.r, cyan.g, cyan.b, cyan.a);
        }
        else if (PointInCurveyRect(&curser, &costumes_menu_button)) {
            curvey_rect_3D(m_renderer, costumes_menu_button.x, costumes_menu_button.y, costumes_menu_button.w, costumes_menu_button.h, costumes_menu_button.r, dark_cyan.r, dark_cyan.g,dark_cyan.b, dark_cyan.a);
        }

        if (!PointInCurveyRect(&curser, &sounds_menu_button)) {
            curvey_rect_3D(m_renderer, sounds_menu_button.x, sounds_menu_button.y, sounds_menu_button.w, sounds_menu_button.h, sounds_menu_button.r, cyan.r, cyan.g, cyan.b, cyan.a);
        }
        else if (PointInCurveyRect(&curser, &sounds_menu_button)) {
            curvey_rect_3D(m_renderer, sounds_menu_button.x, sounds_menu_button.y, sounds_menu_button.w, sounds_menu_button.h, sounds_menu_button.r, dark_cyan.r, dark_cyan.g,dark_cyan.b, dark_cyan.a);
        }
        SDL_RenderCopy(m_renderer, code_menu_tex, nullptr, &code_menu_text_rect);
        SDL_RenderCopy(m_renderer, costumes_menu_tex, nullptr, &costumes_menu_text_rect);
        SDL_RenderCopy(m_renderer, sounds_menu_tex, nullptr, &sounds_menu_text_rect);


        //code menu
        if(clicked_code_menu){
            curvey_rect_3D(m_renderer, code_menu_button2.x, code_menu_button2.y, code_menu_button2.w, code_menu_button2.h, code_menu_button2.r, cyan.r, cyan.g, cyan.b, cyan.a);
            SDL_RenderCopy(m_renderer, code_menu_tex2, nullptr, &code_menu_text_rect2);
            //ribbon drawing under code. fancy drawing
            for(int i=0; i<n; i++){
                SDL_SetRenderDrawColor(m_renderer, 0, 87+5*i, 87+5*i, 255);
                SDL_RenderFillRect(m_renderer, &left_ribbon[i]);
                SDL_RenderFillRect(m_renderer, &blocks_scrolling_menu[i]);
                SDL_RenderFillRect(m_renderer, &blocking_system[i]);

            }
            //final layer of white and near white (for scrolling menu) on the menus.
            SDL_SetRenderDrawColor(m_renderer, 255, 255, 255, 255);
            SDL_RenderFillRect(m_renderer, &left_ribbon[n-1]);
            SDL_SetRenderDrawColor(m_renderer, 220, 220, 220, 255);
            SDL_RenderFillRect(m_renderer, &blocks_scrolling_menu[n-1]);
            SDL_SetRenderDrawColor(m_renderer, 255, 255, 255, 255);
            SDL_RenderFillRect(m_renderer, &blocking_system[n-1]);













            //ribbon buttons under code menu
            if(!pointInRibbonButton(&curser, &motion)){
                ribbonButtonPolygon(m_renderer, motion.X, motion.Y, blue.r, blue.g, blue.b, blue.a);
            }
            else if(pointInRibbonButton(&curser, &motion)){
                ribbonButtonPolygon(m_renderer, motion.X, motion.Y, dark_blue.r, dark_blue.g, dark_blue.b, dark_blue.a);
            }

            if(!pointInRibbonButton(&curser, &looks)){
                ribbonButtonPolygon(m_renderer, looks.X, looks.Y, purple.r, purple.g, purple.b, purple.a);
            }
            else if(pointInRibbonButton(&curser, &looks)){
                ribbonButtonPolygon(m_renderer, looks.X, looks.Y, dark_purple.r, dark_purple.g, dark_purple.b, dark_purple.a);
            }

            if(!pointInRibbonButton(&curser, &sound)){
                ribbonButtonPolygon(m_renderer, sound.X, sound.Y, deep_purple.r, deep_purple.g, deep_purple.b, deep_purple.a);
            }
            else if(pointInRibbonButton(&curser, &sound)){
                ribbonButtonPolygon(m_renderer, sound.X, sound.Y, dark_deep_purple.r, dark_deep_purple.g, dark_deep_purple.b, dark_deep_purple.a);
            }

            if(!pointInRibbonButton(&curser, &events)){
                ribbonButtonPolygon(m_renderer, events.X, events.Y, yellow.r, yellow.g, yellow.b, yellow.a);
            }
            else if(pointInRibbonButton(&curser, &events)){
                ribbonButtonPolygon(m_renderer, events.X, events.Y, dark_yellow.r, dark_yellow.g, dark_yellow.b, dark_yellow.a);
            }

            if(!pointInRibbonButton(&curser, &control)){
                ribbonButtonPolygon(m_renderer, control.X, control.Y, orange.r, orange.g, orange.b, orange.a);
            }
            else if(pointInRibbonButton(&curser, &control)){
                ribbonButtonPolygon(m_renderer, control.X, control.Y, dark_orange.r, dark_orange.g, dark_orange.b, dark_orange.a);
            }

            if(!pointInRibbonButton(&curser, &sensing)){
                ribbonButtonPolygon(m_renderer, sensing.X, sensing.Y, light_blue.r, light_blue.g, light_blue.b, light_blue.a);
            }
            else if(pointInRibbonButton(&curser, &sensing)){
                ribbonButtonPolygon(m_renderer, sensing.X, sensing.Y, dark_light_blue.r, dark_light_blue.g, dark_light_blue.b, dark_light_blue.a);
            }

            if(!pointInRibbonButton(&curser, &operators)){
                ribbonButtonPolygon(m_renderer, operators.X, operators.Y, green.r, green.g, green.b, green.a);
            }
            else if(pointInRibbonButton(&curser, &operators)){
                ribbonButtonPolygon(m_renderer, operators.X, operators.Y, dark_green.r, dark_green.g, dark_green.b, dark_green.a);
            }

            if(!pointInRibbonButton(&curser, &variables)){
                ribbonButtonPolygon(m_renderer, variables.X, variables.Y, deep_orange.r, deep_orange.g, deep_orange.b, deep_orange.a);
            }
            else if(pointInRibbonButton(&curser, &variables)){
                ribbonButtonPolygon(m_renderer, variables.X, variables.Y, dark_deep_orange.r, dark_deep_orange.g, dark_deep_orange.b, dark_deep_orange.a);
            }

            if(!pointInRibbonButton(&curser, &my_blocks)){
                ribbonButtonPolygon(m_renderer, my_blocks.X, my_blocks.Y, pink.r, pink.g, pink.b, pink.a);
            }
            else if(pointInRibbonButton(&curser, &my_blocks)){
                ribbonButtonPolygon(m_renderer, my_blocks.X, my_blocks.Y, dark_pink.r, dark_pink.g, dark_pink.b, dark_pink.a);
            }
            SDL_RenderCopy(m_renderer, motion_tex, nullptr, &motion_text_rect);
            SDL_RenderCopy(m_renderer, looks_tex, nullptr, &looks_text_rect);
            SDL_RenderCopy(m_renderer, sound_tex, nullptr, &sound_text_rect);
            SDL_RenderCopy(m_renderer, events_tex, nullptr, &events_text_rect);
            SDL_RenderCopy(m_renderer, control_tex, nullptr, &control_text_rect);
            SDL_RenderCopy(m_renderer, sensing_tex, nullptr, &sensing_text_rect);
            SDL_RenderCopy(m_renderer, operators_tex, nullptr, &operators_text_rect);
            SDL_RenderCopy(m_renderer, variables_tex, nullptr, &variables_text_rect);
            SDL_RenderCopy(m_renderer, my_blocks_tex, nullptr, &my_blocks_text_rect);

            if(clicked_motion){
                ribbonButtonPolygon(m_renderer, motion2.X, motion2.Y, blue.r, blue.g, blue.b, blue.a);
                SDL_RenderCopy(m_renderer, motion2_tex, nullptr, &motion2_text_rect);

                //drawing motion blocks
                for(auto &i:menu_block_motion){
                    drawBlock1(m_renderer, i);
                }


            }

            else if(clicked_looks){
                ribbonButtonPolygon(m_renderer, looks2.X, looks2.Y, purple.r, purple.g, purple.b, purple.a);
                SDL_RenderCopy(m_renderer, looks2_tex, nullptr, &looks2_text_rect);

                //drawing looks blocks
                for(auto &i:menu_block_looks){
                    drawBlock1(m_renderer, i);
                }


            }

            else if(clicked_sound){
                ribbonButtonPolygon(m_renderer, sound2.X, sound2.Y, deep_purple.r, deep_purple.g, deep_purple.b, deep_purple.a);
                SDL_RenderCopy(m_renderer, sound2_tex, nullptr, &sound2_text_rect);
                //drawing sound blocks
                for(auto &i:menu_block_sound){
                    drawBlock1(m_renderer, i);
                }
            }

            else if(clicked_events){
                ribbonButtonPolygon(m_renderer, events2.X, events2.Y, yellow.r, yellow.g, yellow.b, yellow.a);
                SDL_RenderCopy(m_renderer, events2_tex, nullptr, &events2_text_rect);
                //drawing events blocks
                for(auto &i:menu_block_events){
                    drawBlock2(m_renderer, i);
                }
            }

            else if(clicked_control){
                ribbonButtonPolygon(m_renderer, control2.X, control2.Y, orange.r, orange.g, orange.b, orange.a);
                SDL_RenderCopy(m_renderer, control2_tex, nullptr, &control2_text_rect);
            }

            else if(clicked_sensing){
                ribbonButtonPolygon(m_renderer, sensing2.X, sensing2.Y, light_blue.r, light_blue.g, light_blue.b, light_blue.a);
                SDL_RenderCopy(m_renderer, sensing2_tex, nullptr, &sensing2_text_rect);
            }
            else if(clicked_operators){
                ribbonButtonPolygon(m_renderer, operators2.X, operators2.Y, green.r, green.g, green.b, green.a);
                SDL_RenderCopy(m_renderer, operators2_tex, nullptr, &operators2_text_rect);
            }
            else if(clicked_variables){
                ribbonButtonPolygon(m_renderer, variables2.X, variables2.Y, deep_orange.r, deep_orange.g, deep_orange.b, deep_orange.a);
                SDL_RenderCopy(m_renderer, variables2_tex, nullptr, &variables2_text_rect);
            }
            else if(clicked_my_blocks){
                ribbonButtonPolygon(m_renderer, my_blocks2.X, my_blocks2.Y, pink.r, pink.g, pink.b, pink.a);
                SDL_RenderCopy(m_renderer, my_blocks2_tex, nullptr, &my_blocks2_text_rect);
            }





        }


            //costumes menu
        else if(clicked_costumes_menu){
            curvey_rect_3D(m_renderer, costumes_menu_button2.x, costumes_menu_button2.y, costumes_menu_button2.w, costumes_menu_button2.h, costumes_menu_button2.r, cyan.r, cyan.g, cyan.b, cyan.a);
            SDL_RenderCopy(m_renderer, costumes_menu_tex2, nullptr, &costumes_menu_text_rect2);
        }
            //sounds menu
        else if(clicked_sounds_menu){
            curvey_rect_3D(m_renderer, sounds_menu_button2.x, sounds_menu_button2.y, sounds_menu_button2.w, sounds_menu_button2.h, sounds_menu_button2.r, cyan.r, cyan.g, cyan.b, cyan.a);
            SDL_RenderCopy(m_renderer, sounds_menu_tex2, nullptr, &sounds_menu_text_rect2);
        }


        //rendering program (the main vector)





        //temp drawing for the blocks getting dragged.
        if(isDragging){
            drawBlock1(m_renderer ,tempDraggingBlock);
        }



        //sprites show box (stage)


        // SDL_Rect playerrect1 = {player1.x, player1.y, player1.w, player1.h};
        // SDL_RenderCopy(m_renderer,player1.texture, nullptr, &playerrect1);


        SDL_Rect playerrect2 = {player2.x, player2.y, player2.w, player2.h};
        SDL_RenderCopyEx(m_renderer,player2.texture, nullptr, &playerrect2,player2.angle , &player2.center , player2.flip);





        //look menu functions


        if (player2.isSayingfor) {
            say_s_for_n_sec_draw(m_renderer,player2 , mainsaythinkfont);

        }

        if (player2.isSaying) {
            say_s_draw(m_renderer, player2, mainsaythinkfont);
        }

        if (player2.isThinkingfor) {
            think_s_for_n_sec_draw(m_renderer,player2 , mainsaythinkfont);

        }

        if (player2.isThinking) {
            think_s_draw(m_renderer, player2, mainsaythinkfont);

        }



        currentTime = SDL_GetTicks();

        if (player2.isSayingfor) {
            if (currentTime - player2.sayforStartTime >= player2.sayDuration) {

                player2.isSayingfor = false;
            }
        }
        if (player2.isThinkingfor) {
            if (currentTime - player2.thinkforStartTime >= player2.thinkDuration) {
                player2.isThinkingfor = false;

            }
        }


        //sound menu function















        SDL_RenderPresent(m_renderer);
        SDL_Delay(16);
    }


    SDL_FreeSurface(code_menu_surf2);
    SDL_FreeSurface(costumes_menu_surf2);
    SDL_FreeSurface(costumes_menu_surf);
    SDL_FreeSurface(sounds_menu_surf2);
    SDL_FreeSurface(sounds_menu_surf);
    SDL_FreeSurface(motion2_surf);
    SDL_FreeSurface(motion_surf);
    SDL_FreeSurface(looks2_surf);
    SDL_FreeSurface(looks_surf);
    SDL_FreeSurface(sound_surf);
    SDL_FreeSurface(sound2_surf);
    SDL_FreeSurface(events2_surf);
    SDL_FreeSurface(events_surf);
    SDL_FreeSurface(control2_surf);
    SDL_FreeSurface(control_surf);
    SDL_FreeSurface(sensing2_surf);
    SDL_FreeSurface(sensing_surf);
    SDL_FreeSurface(operators2_surf);
    SDL_FreeSurface(operators_surf);
    SDL_FreeSurface(variables2_surf);
    SDL_FreeSurface(variables_surf);
    SDL_FreeSurface(my_blocks2_surf);
    SDL_FreeSurface(my_blocks_surf);
    SDL_FreeSurface(my_scratch_sur);
    SDL_FreeSurface(sprite_choose_sur);



    SDL_DestroyTexture(code_menu_tex);
    SDL_DestroyTexture(code_menu_tex2);
    SDL_DestroyTexture(costumes_menu_tex);
    SDL_DestroyTexture(costumes_menu_tex2);
    SDL_DestroyTexture(sounds_menu_tex);
    SDL_DestroyTexture(sounds_menu_tex2);
    SDL_DestroyTexture(motion2_tex);
    SDL_DestroyTexture(motion_tex);
    SDL_DestroyTexture(looks2_tex);
    SDL_DestroyTexture(looks_tex);
    SDL_DestroyTexture(sound_tex);
    SDL_DestroyTexture(sound2_tex);
    SDL_DestroyTexture(events_tex);
    SDL_DestroyTexture(events2_tex);
    SDL_DestroyTexture(control_tex);
    SDL_DestroyTexture(control2_tex);
    SDL_DestroyTexture(sensing_tex);
    SDL_DestroyTexture(sensing2_tex);
    SDL_DestroyTexture(operators_tex);
    SDL_DestroyTexture(operators2_tex);
    SDL_DestroyTexture(variables_tex);
    SDL_DestroyTexture(variables2_tex);
    SDL_DestroyTexture(my_blocks_tex);
    SDL_DestroyTexture(my_blocks2_tex);
    SDL_DestroyTexture(my_scratch_tex);
    SDL_DestroyTexture(sprite_choose_tex);

    TTF_CloseFont(menu_font_clicked);
    TTF_CloseFont(menu_font_normal);
    TTF_CloseFont(under_code_font);
    TTF_CloseFont(under_code_font2);
    TTF_CloseFont(code_block);
    TTF_CloseFont(mainsaythinkfont);


    Mix_FreeChunk(MeowSound1);



    SDL_DestroyTexture(player2.texture);
    //Finalize and free resources
    SDL_DestroyWindow( m_window );
    SDL_DestroyRenderer( m_renderer );
    Mix_CloseAudio();


    TTF_Quit();
    IMG_Quit();
    SDL_Quit();
    return 0;
}