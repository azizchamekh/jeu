#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include <stdio.h>
#include <SDL/SDL_mixer.h>
#include <SDL/SDL_ttf.h>


void apply_surface( int x, int y, SDL_Surface* source, SDL_Surface* destination ) 
{

    SDL_Rect offset;

    offset.x = x;
    offset.y = y;

    //on blit la surface
    SDL_BlitSurface( source, NULL, destination, &offset );
}
void menu(SDL_Surface *bg,SDL_Surface *screen)
{
    SDL_Surface *bouttons = NULL;
    SDL_Surface *newgame = NULL;
    SDL_Surface *options = NULL;
    SDL_Surface *credit = NULL;
    SDL_Surface *quit = NULL;

    FILE* f=fopen("actualoptions.txt","r");
    int soundstate,fsstate;
    fscanf(f,"%d %d",&soundstate,&fsstate);
    fclose(f);

if(Mix_OpenAudio(44100,MIX_DEFAULT_FORMAT,MIX_DEFAULT_CHANNELS,1024)==-1)
     {
     printf("%s",Mix_GetError());
     }
Mix_Music *musique;
     musique=Mix_LoadMUS("music.ogg");
     Mix_PlayMusic(musique, -1);
     

    Mix_Music *song=NULL;
    Mix_Chunk *effect=NULL;
    song=Mix_LoadMUS("wow.mp3");
    effect=Mix_LoadWAV("click_one.wav");

    if(soundstate==0)
    {
        Mix_VolumeMusic(0);
    }
    else 
    {
        Mix_VolumeMusic(MIX_MAX_VOLUME);
    }



    int Run=1,T[4];
    SDL_Event event;
    T[0]=0;
    T[1]=0;
    T[2]=0;
    T[3]=0;
    int i=-1;

    bouttons = IMG_Load("1.png");
    newgame = IMG_Load("11.png");
    options = IMG_Load("12.png");
    quit = IMG_Load("13.png");
 credit = IMG_Load("14.png");


	

	bg = IMG_Load( "back.png" );
	apply_surface( 0, 0, bg, screen );
    apply_surface( 0, 0, bouttons, screen );

    SDL_Rect offset;
    offset.x=0;
    offset.y=0;

    

    SDL_Flip( screen );
    



        while(Run)
        {
           
            SDL_WaitEvent(&event);
            switch(event.type)
            {
                case SDL_KEYDOWN :
                {
                        if(event.key.keysym.sym==SDLK_RIGHT && T[0]==0 && T[1]==0 && T[2]==0 && T[3]==0 )
                        {
                                    apply_surface( 0, 0, newgame, screen );
                                    Mix_PlayChannel( -1, effect, 0 );
                                    T[0]=1;T[1]=0;T[2]=0;T[3]=0;
                        }
                    
                        else if(event.key.keysym.sym==SDLK_RIGHT && T[0]==1)
                        {
                                    apply_surface( 0, 0, options, screen );
                                    Mix_PlayChannel( -1, effect, 0 );
                                    T[0]=0;T[1]=1;T[2]=0;T[3]=0;
                        }
                        else if(event.key.keysym.sym==SDLK_RIGHT && T[1]==1)
                        {
                                    apply_surface( 0, 0, quit, screen );
                                    Mix_PlayChannel( -1, effect, 0 );
                                    T[0]=0;T[1]=0;T[2]=1;T[3]=0;
                        }
                        else if(event.key.keysym.sym==SDLK_RIGHT && T[2]==1)
                        {
                                    apply_surface( 0, 0, credit, screen );
                                    Mix_PlayChannel( -1, effect, 0 );
                                    T[0]=0;T[1]=0;T[2]=0;T[3]=1;
                        }
                        else if(event.key.keysym.sym==SDLK_RIGHT && T[3]==1)
                        {
                            
                                    apply_surface( 0, 0, newgame, screen );
                                    Mix_PlayChannel( -1, effect, 0 );
                                    T[0]=0;T[1]=0;T[2]=0;T[3]=0;
                        }
                        if(event.key.keysym.sym==SDLK_LEFT && T[0]==0 && T[1]==0 && T[2]==0 && T[2]==0 && T[3]==0)
                        {
                                    apply_surface( 0, 0, credit, screen );
                                    Mix_PlayChannel( -1, effect, 0 );
                                    T[0]=0;T[1]=0;T[2]=0;T[3]=0;
                        }
                        else if(event.key.keysym.sym==SDLK_LEFT && T[0]==1)
                        {
                                    apply_surface( 0, 0, credit, screen );
                                    Mix_PlayChannel( -1, effect, 0 );
                                    T[0]=0;T[1]=0;T[2]=0;T[3]=1;
                        }
                        else if(event.key.keysym.sym==SDLK_LEFT && T[3]==1)
                        {
                                    apply_surface( 0, 0, quit, screen );
                                    Mix_PlayChannel( -1, effect, 0 );
                                    T[0]=0;T[1]=0;T[2]=1;T[3]=0;
                        }
                    
                        else if(event.key.keysym.sym==SDLK_LEFT && T[2]==1)
                        {
                                    apply_surface( 0, 0, options, screen );
                                    Mix_PlayChannel( -1, effect, 0 );
                                    T[0]=0;T[1]=1;T[2]=0;T[3]=0;
                        }
                        else if(event.key.keysym.sym==SDLK_LEFT && T[1]==1)
                        {
                                    apply_surface( 0, 0, newgame, screen );
                                    Mix_PlayChannel( -1, effect, 0 );
                                    T[0]=1;T[1]=0;T[2]=0;T[3]=0;
                        
                        }
                    break;
                }    

                 break;  
                case SDL_MOUSEMOTION :
                {
                            if((event.motion.x >70) && (event.motion.x <170) && (event.motion.y >150) && (event.motion.y <280) )
                                    {
                                        apply_surface( 0, 0, newgame, screen );
                                        T[0]=1;T[1]=0;T[2]=0;T[3]=0;
                                        
                                    }
                    
                            else if((event.motion.x >200) && (event.motion.x <300) && (event.motion.y >150) && (event.motion.y <280) )
                                    {
                                        apply_surface( 0, 0, options, screen );
                                        T[0]=0;T[1]=1;T[2]=0;T[3]=0;
                                    }
                            else if ((event.motion.x >330) && (event.motion.x <430) && (event.motion.y >150) && (event.motion.y <280) )
                                    {
                                        apply_surface( 0, 0, quit, screen );
                                        T[0]=0;T[1]=0;T[2]=1;T[3]=0;
                                    }
                            else if((event.motion.x >450) && (event.motion.x <495) && (event.motion.y >350) && (event.motion.y <380) )
                                    {
                                        apply_surface( 0, 0, credit, screen );
                                        T[0]=0;T[1]=0;T[2]=0;T[3]=1;
                                    }
                            else 
                            		{
                            			apply_surface( 0, 0, bouttons, screen );
                            		}
                                    break;
                }
                case SDL_QUIT :
                {
                        Run=0;
                }
                case SDL_MOUSEBUTTONUP : 
                {
                        if(event.button.button == SDL_BUTTON_LEFT)
                            {
                
                                if(event.button.x >30 && event.button.x <80 && event.button.y >150 && event.button.y <200 ) Run=0;
                                else if (event.button.x >396.5 && event.button.x <627.5 && event.button.y >350 && event.button.y <480) 
                                {

                                }
                                else if (event.button.x >396.5 && event.button.x <627.5 && event.button.y >50 && event.button.y <180)
                                {
                                    Mix_PauseMusic();
                                    //printf("music is%s paused\n", Mix_PausedMusic()?"":" not");
                                    //Mix_CloseAudio();

                                    apply_surface( 0, 0, bg, screen );
                                    apply_surface( 0, 0, bouttons, screen );
                                }
                                else if(event.button.x>396.5 && event.button.x<627.5 && event.button.y>250 && event.button.y<323)
                                {

                                    apply_surface( 0, 0, bg, screen );
                                    apply_surface( 0, 0, bouttons, screen );
                                }
				else if(event.button.x>330 && event.button.x<430 && event.button.y>150 && event.button.y<280)
                                    {
                                        Run=0;
					break;
                                    }

                            }
                }
            }
            SDL_Flip(screen);
        }
        

	SDL_Flip( screen );

    //Liberation des surface
    SDL_FreeSurface( bouttons );
    SDL_FreeSurface( newgame );
    SDL_FreeSurface( options );
    SDL_FreeSurface( credit );
    SDL_FreeSurface( quit );
    SDL_FreeSurface( bg );

    //On quitte sdl
    SDL_Quit();
}
int main(int argc, const char* argv[]) {
int x,y;
SDL_Surface* source; SDL_Surface* destination;
SDL_Surface *bg=IMG_Load( "back.png" );
SDL_Surface *screen;
 screen = SDL_SetVideoMode(500,400, 32, SDL_HWSURFACE);
    SDL_WM_SetCaption("zembra", NULL);
apply_surface(x,y,source,destination )
menu(bg,screen);
}
