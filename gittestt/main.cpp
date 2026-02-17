#include <iostream>
#include "Textures.h"
#include "Shapes.h"
#include "Essentials.h"
#include "DragFunc.h"
#include "Motion.h"
#include "LookMenu.h"
#include "SoundMenu.h"

int main( int argc, char * argv[] )
{
    Uint32 SDL_flags = SDL_INIT_VIDEO | SDL_INIT_TIMER | SDL_INIT_AUDIO ;
    Uint32 WND_flags = SDL_WINDOW_SHOWN;
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

    Uint32 currentTime = SDL_GetTicks();

    Mix_OpenAudio( 44100, MIX_DEFAULT_FORMAT, 2, 2048 );
    Mix_Chunk* MeowSound1 = Mix_LoadWAV("sounds/Meow.wav");


    // Initialize TTF
    if (TTF_Init() == -1) {
        cout << "TTF could not initialize! Error: " << TTF_GetError() << endl;
    }
    // Loading from your "fonts" folder
    TTF_Font* menu_font_normal = TTF_OpenFont("fonts/menu_font.ttf", 20);
    TTF_Font* menu_font_clicked = TTF_OpenFont("fonts/menu_font.ttf", 22);

    //for under code menu ribbon buttons
    TTF_Font* under_code_font = TTF_OpenFont("fonts/simple.ttf", 9);
    TTF_Font* under_code_font2 = TTF_OpenFont("fonts/simple.ttf", 12);

    //font for code blocks.
    TTF_Font* code_block = TTF_OpenFont("fonts/simple.ttf", 13);

    //main say and think font
    TTF_Font* mainsaythinkfont = TTF_OpenFont("fonts/simple.ttf", 13);



    if (!menu_font_clicked or !menu_font_normal) {
        cout << "Failed to load fonts! Error: " << TTF_GetError() << endl;
    }



    block1 second_block = {100, 150, 200, 40, blue};
    second_block.opCode = "move";
    second_block.font = code_block;
//    second_block.input1 = "100";
    second_block.input2 = "100";

    block1 third_block = {100, 300, 200, 40, blue};
    third_block.opCode = "turn";
    third_block.font = code_block;
    //    third_block.input1 = "100";
    third_block.input2 = "100";

    block1 fourth_block = {100, 450, 200, 40, blue};
    fourth_block.opCode = "turn";
    fourth_block.font = code_block;
    //    fourth_block.input1 = "100";
    fourth_block.input2 = "100";







    double k = 1.05;
    CurveyRect code_menu_button = {2, 50, 20, 100, 50};
    CurveyRect costumes_menu_button = {98, 50, 20, 100, 50};
    CurveyRect sounds_menu_button = {200, 50, 20, 100, 50};
    CurveyRect code_menu_button2 = {code_menu_button.x, int(code_menu_button.y - (k-1) * code_menu_button.h), int(code_menu_button.r * k), int(code_menu_button.w * k), int(code_menu_button.h*k)};
    CurveyRect costumes_menu_button2 = {costumes_menu_button.x, int(costumes_menu_button.y - (k-1) * costumes_menu_button.h), int(costumes_menu_button.r * k), int(costumes_menu_button.w * k), int(costumes_menu_button.h*k)};
    CurveyRect sounds_menu_button2 = {sounds_menu_button.x, int(sounds_menu_button.y - (k-1) * sounds_menu_button.h), int(sounds_menu_button.r * k), int(sounds_menu_button.w * k), int(sounds_menu_button.h*k)};

    double co=1.25;
    //for code menu buttons.
    int dButton = 60; int r = 27, initial_y = code_menu_button.y+code_menu_button.h + 40;
    //motion
    RibbonButton motion = {(code_menu_button.w-20)/2, initial_y , r};
    motion.vertices();
    RibbonButton motion2 = {(code_menu_button.w-20)/2, initial_y , int(r*co)};
    motion2.vertices();

    //looks
    RibbonButton looks = {(code_menu_button.w-20)/2, initial_y + dButton , r};
    looks.vertices();
    RibbonButton looks2 = {(code_menu_button.w-20)/2, initial_y + dButton , int(r*co)};
    looks2.vertices();

    //sound
    RibbonButton sound = {(code_menu_button.w-20)/2, initial_y+ 2  * dButton , r};
    sound.vertices();
    RibbonButton sound2 = {(code_menu_button.w-20)/2, initial_y+ 2  * dButton , int(r*co)};
    sound2.vertices();
    //events
    RibbonButton events = {(code_menu_button.w-20)/2, initial_y + 3  * dButton , r};
    events.vertices();
    RibbonButton events2 = {(code_menu_button.w-20)/2, initial_y + 3  * dButton , int(r*co)};
    events2.vertices();
    //control
    RibbonButton control = {(code_menu_button.w-20)/2, initial_y + 4  * dButton , r};
    control.vertices();
    RibbonButton control2 = {(code_menu_button.w-20)/2, initial_y + 4  * dButton , int(r*co)};
    control2.vertices();
    //sensing
    RibbonButton sensing = {(code_menu_button.w-20)/2, initial_y + 5  * dButton , r};
    sensing.vertices();
    RibbonButton sensing2 = {(code_menu_button.w-20)/2, initial_y + 5  * dButton , int(r*co)};
    sensing2.vertices();
    //operators
    RibbonButton operators = {(code_menu_button.w-20)/2, initial_y + 6  * dButton , r};
    operators.vertices();
    RibbonButton operators2 = {(code_menu_button.w-20)/2, initial_y + 6  * dButton , int(r*co)};
    operators2.vertices();
    //variables
    RibbonButton variables = {(code_menu_button.w-20)/2, initial_y + 7  * dButton , r};
    variables.vertices();
    RibbonButton variables2 = {(code_menu_button.w-20)/2, initial_y + 7  * dButton , int(r*co)};
    variables2.vertices();
    //my blocks
    RibbonButton my_blocks = {(code_menu_button.w-20)/2, initial_y + 8  * dButton , r};
    my_blocks.vertices();
    RibbonButton my_blocks2 = {(code_menu_button.w-20)/2, initial_y + 8  * dButton ,int(r*co)};
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







    SDL_FreeSurface(code_menu_surf);


    //left ribbon to be drawn.
    int n=5;
    vector<SDL_Rect> left_ribbon(n);
    for(int i=0; i<n; i++){
        left_ribbon[i] = {code_menu_button.x+i, code_menu_button.y+i-3 + code_menu_button.h + 3, code_menu_button.w-20-2 * i, DM.h - left_ribbon[i].h};
    }
    //blocks scrolling menu
    vector<SDL_Rect> blocks_scrolling_menu(n);
    for(int i=0; i<n; i++){
        blocks_scrolling_menu[i] = {code_menu_button.w-20 + code_menu_button.x+i, code_menu_button.y+i-3 + code_menu_button.h + 3 , 2  * code_menu_button.w + 20 - 2 * i, DM.h - blocks_scrolling_menu[i].h};
    }


    //mouse points to...
    SDL_Point curser;


    //temp integer
    int dragmouseX;
    int dragmouseY;
    bool mousebl2=false;
    bool mousebl3=false;
    bool mousebl4=false;



    //sprites


    // mainsprite player1;
    // player1.texture = loadtexture("images/player.png", m_renderer);
    // player1.x = 1000;
    // player1.y = 200;
    // player1.w = 50;
    // player1.h = 50;

    mainsprite player2;
    player2.texture = loadtexture("images/player.png", m_renderer);
    player2.x = 1000;
    player2.y = 300;
    player2.w = 100;
    player2.h = 100;
    player2.setcenter();




    //this is where the real stuff is happening.
    bool Running = true;
    bool clicked_code_menu = true, clicked_costumes_menu = false, clicked_sounds_menu = false;
    bool clicked_motion=true, clicked_looks=false, clicked_sound=false, clicked_events=false, clicked_control=false, clicked_sensing=false, clicked_operators=false, clicked_variables=false, clicked_my_blocks = false;
    while(Running){
        while(SDL_PollEvent(&e)) {
            if (e.type == SDL_QUIT)Running = false;
            if (e.type == SDL_KEYDOWN) {
                if (e.key.keysym.sym == SDLK_ESCAPE)Running = false;
            }

            //for checking click on different icons.
            if(e.type == SDL_MOUSEBUTTONDOWN){

                if(e.button.button == SDL_BUTTON_LEFT){
                    if(PointInCurveyRect(&curser, &code_menu_button)){
                        clicked_code_menu = true;
                        clicked_costumes_menu = false;
                        clicked_sounds_menu = false;
                    }
                    if(PointInCurveyRect(&curser, &costumes_menu_button)){
                        clicked_code_menu = false;
                        clicked_costumes_menu = true;
                        clicked_sounds_menu = false;
                    }
                    if(PointInCurveyRect(&curser, &sounds_menu_button)){
                        clicked_code_menu = false;
                        clicked_costumes_menu = false;
                        clicked_sounds_menu = true;
                    }

                    if(pointInRibbonButton(&curser, &motion)){
                        clicked_motion = true, clicked_looks= false, clicked_sound=false, clicked_events=false, clicked_control=false, clicked_sensing=false, clicked_operators=false, clicked_variables=false, clicked_my_blocks = false;
                    }
                    if(pointInRibbonButton(&curser, &looks)){
                        clicked_motion = false, clicked_looks= true, clicked_sound=false, clicked_events=false, clicked_control=false, clicked_sensing=false, clicked_operators=false, clicked_variables=false, clicked_my_blocks = false;
                    }
                    if(pointInRibbonButton(&curser, &sound)){
                        clicked_motion = false, clicked_looks= false, clicked_sound=true, clicked_events=false, clicked_control=false, clicked_sensing=false, clicked_operators=false, clicked_variables=false, clicked_my_blocks = false;
                    }
                    if(pointInRibbonButton(&curser, &events)){
                        clicked_motion = false, clicked_looks= false, clicked_sound=false, clicked_events= true, clicked_control=false, clicked_sensing=false, clicked_operators=false, clicked_variables=false, clicked_my_blocks = false;
                    }
                    if(pointInRibbonButton(&curser, &control)){
                        clicked_motion = false, clicked_looks= false, clicked_sound=false, clicked_events=false, clicked_control= true, clicked_sensing=false, clicked_operators=false, clicked_variables=false, clicked_my_blocks = false;
                    }
                    if(pointInRibbonButton(&curser, &sensing)){
                        clicked_motion = false, clicked_looks= false, clicked_sound=false, clicked_events=false, clicked_control=false, clicked_sensing= true, clicked_operators=false, clicked_variables=false, clicked_my_blocks = false;
                    }
                    if(pointInRibbonButton(&curser, &operators)){
                        clicked_motion = false, clicked_looks= false, clicked_sound=false, clicked_events=false, clicked_control=false, clicked_sensing=false, clicked_operators= true, clicked_variables=false, clicked_my_blocks = false;
                    }
                    if(pointInRibbonButton(&curser, &variables)){
                        clicked_motion = false, clicked_looks= false, clicked_sound=false, clicked_events=false, clicked_control=false, clicked_sensing=false, clicked_operators= false, clicked_variables= true, clicked_my_blocks = false;
                    }
                    if(pointInRibbonButton(&curser, &my_blocks)){
                        clicked_motion = false, clicked_looks= false, clicked_sound=false, clicked_events=false, clicked_control=false, clicked_sensing=false, clicked_operators= false, clicked_variables=false, clicked_my_blocks = true;
                    }

                    dragmouseX = e.button.x;
                    dragmouseY = e.button.y;

                    if (mouseIsInside(second_block, dragmouseX, dragmouseY)) {
                        dragging = true;
                        drag_x = dragmouseX-second_block.x;
                        drag_y = dragmouseY-second_block.y;
                        mousebl2 = true;

                    }
                    if (mouseIsInside(third_block, dragmouseX, dragmouseY)) {
                        dragging = true;
                        drag_x = dragmouseX-third_block.x;
                        drag_y = dragmouseY-third_block.y;

                        mousebl3 = true;
                    }
                    if (mouseIsInside(fourth_block, dragmouseX, dragmouseY)) {
                        dragging = true;
                        drag_x = dragmouseX-fourth_block.x;
                        drag_y = dragmouseY-fourth_block.y;

                        mousebl4 = true;
                    }







                }
            }
            if (e.type == SDL_MOUSEBUTTONUP) {
                if (e.button.button == SDL_BUTTON_LEFT) {
                    dragging = false;
                    mousebl2 = false;
                    mousebl3 = false;
                    mousebl4 = false;

                }

                //sprite control

                if (mouseIsInside(second_block, dragmouseX, dragmouseY)) {
                    move_n_step(true,10,player2);
                }
                if (mouseIsInside(third_block, dragmouseX, dragmouseY)) {
                    turn_right_n_degree(10,player2);
                }
                if (mouseIsInside(fourth_block, dragmouseX, dragmouseY)) {
                    turn_right_n_degree(-10,player2);
                }

                //test sound menu
                if (mouseIsInside(fourth_block, dragmouseX, dragmouseY)) {
                    playsound(MeowSound1);
                }
            }
            if (e.type == SDL_MOUSEMOTION) {
                if (dragging&&mousebl2) {
                    second_block.x = e.motion.x-drag_x;
                    second_block.y = e.motion.y-drag_y;
                }
                if (dragging&&mousebl3) {
                    third_block.x = e.motion.x-drag_x;
                    third_block.y = e.motion.y-drag_y;
                }
                if (dragging&&mousebl4) {
                    fourth_block.x = e.motion.x-drag_x;
                    fourth_block.y = e.motion.y-drag_y;
                }
            }

        }

        //magnet
        magnetup(second_block, third_block);
        magnetup(third_block, fourth_block);
        magnetup(second_block, fourth_block);
        magnetdown(second_block, third_block);
        magnetdown(third_block, fourth_block);
        magnetdown(second_block, fourth_block);



        SDL_SetRenderDrawColor(m_renderer, 50, 50, 50, 255);
        SDL_RenderClear(m_renderer);





        SDL_GetMouseState(&curser.x, &curser.y);

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
            }
            for(int i=0; i<n; i++){
                SDL_SetRenderDrawColor(m_renderer, 0, 87+5*i, 87+5*i, 255);
                SDL_RenderFillRect(m_renderer, &blocks_scrolling_menu[i]);
            }
            //final layer of white and near white (for scrolling menu) on the menus.
            SDL_SetRenderDrawColor(m_renderer, 255, 255, 255, 255);
            SDL_RenderFillRect(m_renderer, &left_ribbon[n-1]);
            SDL_SetRenderDrawColor(m_renderer, 220, 220, 220, 255);
            SDL_RenderFillRect(m_renderer, &blocks_scrolling_menu[n-1]);



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
            }

            else if(clicked_looks){
                ribbonButtonPolygon(m_renderer, looks2.X, looks2.Y, purple.r, purple.g, purple.b, purple.a);
                SDL_RenderCopy(m_renderer, looks2_tex, nullptr, &looks2_text_rect);
            }

            else if(clicked_sound){
                ribbonButtonPolygon(m_renderer, sound2.X, sound2.Y, deep_purple.r, deep_purple.g, deep_purple.b, deep_purple.a);
                SDL_RenderCopy(m_renderer, sound2_tex, nullptr, &sound2_text_rect);
            }

            else if(clicked_events){
                ribbonButtonPolygon(m_renderer, events2.X, events2.Y, yellow.r, yellow.g, yellow.b, yellow.a);
                SDL_RenderCopy(m_renderer, events2_tex, nullptr, &events2_text_rect);
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


//        aaInscribedPolygon(m_renderer, 200, 200, 50, 8, 255, 0, 0, 255);
        drawBlock1(m_renderer, second_block);
        drawBlock1(m_renderer, third_block);
        drawBlock1(m_renderer, fourth_block);









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
