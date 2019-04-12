#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include <stdio.h>
#include <SDL/SDL_mixer.h>
#include <SDL/SDL_ttf.h>
#include "menu.h"
#include "credits.h"

void apply_surface( int x, int y, SDL_Surface* source, SDL_Surface* destination );
void menu(SDL_Surface *bg,SDL_Surface *screen);

void credits(SDL_Surface *screen, SDL_Surface *bg)
{
	SDL_Event event;
	int Run=1;
	//bg = IMG_Load( "bg.bmp" );
	apply_surface( 0, 0, bg, screen );
	SDL_Surface *credits=IMG_Load("cred.png");
	SDL_Surface *back=IMG_Load("cred.png");
	apply_surface( 0, 0, credits, screen );
	apply_surface( 0, 0, back, screen );

	SDL_Flip(screen);
	while(Run)
	{
		SDL_WaitEvent(&event);
		switch (event.type)
		{
			case SDL_MOUSEMOTION :
			{
		 if  ((event.motion.x >450) && (event.motion.x <495) && (event.motion.y >350) && (event.motion.y <380) )
							{
									apply_surface( 387, 500, back, screen );
									SDL_Flip(screen);
							}
					else 
							{
									apply_surface( 387, 500, back, screen );
									SDL_Flip(screen);
							}
			}
			break;
			case SDL_MOUSEBUTTONUP : 
                {
                        if(event.button.button == SDL_BUTTON_LEFT)
                            {
                
                                if(event.button.x >450 && event.button.x <495 && event.button.y >350 && event.button.y <380 ) 
                                {
                                	//SDL_FreeSurface(credits);
									apply_surface( 0, 0, bg, screen );
									SDL_Flip(screen);
									menu(bg,screen);
                                }
                            }
                }
		}
        SDL_Flip(screen);
        apply_surface(0,0,bg,screen);
        apply_surface( 0, 0, credits, screen );
        apply_surface( 0, 0, back, screen );
	}

	
}

