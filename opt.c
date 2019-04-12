

#include <stdio.h>
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include <SDL/SDL_mixer.h>
#include <SDL/SDL_ttf.h>
#include "menu.h"
#include "opt.h"

void option(SDL_Surface* bg,SDL_Surface* screen)
{
	FILE* f=fopen("actualoptions.txt","r");
	int soundstate,fsstate;
	fscanf(f,"%d %d",&soundstate,&fsstate);

	SDL_Surface* optionsscreen=IMG_Load("option.png");
	SDL_Surface* tick=IMG_Load("tick_yes.png");
	SDL_Surface* backmo=IMG_Load("backmo.png");
	SDL_Surface* savemo=IMG_Load("savemo.png");
	SDL_Surface* native=IMG_Load("native.png");

	apply_surface(0,0,bg,screen);
	apply_surface(0,0,optionsscreen,screen);
	apply_surface(239,360,native,screen);
	if(soundstate==1) 
	{
		apply_surface(378,125,tick,screen);
	}
	if(fsstate==1)
	{
		apply_surface(378,275,tick,screen);
	}

	SDL_Flip(screen);

	int continuer=1;
	SDL_Event event;
	while(continuer)
	{
		SDL_WaitEvent(&event);
		switch(event.type)
		{
			case SDL_MOUSEMOTION : 
			{
				if(event.motion.x>240 && event.motion.x<460 && event.motion.y>460 && event.motion.y<530)
				{
					apply_surface(0,0,bg,screen);
					apply_surface(0,0,optionsscreen,screen);
					if(soundstate==1 && fsstate==1) 
					{
						apply_surface(378,125,tick,screen);
						apply_surface(378,275,tick,screen);
					}
					else if(fsstate==1 && soundstate==0)
					{
						apply_surface(0,0,optionsscreen,screen);
						apply_surface(378,275,tick,screen);
					}
					else if(soundstate==1 && fsstate==0)
					{
						apply_surface(0,0,optionsscreen,screen);
						apply_surface(378,125,tick,screen);
					}
					else 
					{
						apply_surface(0,0,optionsscreen,screen);
					}
					apply_surface(239,460,backmo,screen);
					SDL_Flip(screen);
				}
				else if(event.motion.x>530 && event.motion.x<752 && event.motion.y>460 && event.motion.y<530)
				{
					apply_surface(0,0,bg,screen);
					apply_surface(0,0,optionsscreen,screen);
					if(soundstate==1 && fsstate==1) 
					{
						apply_surface(378,125,tick,screen);
						apply_surface(378,275,tick,screen);
					}
					else if(fsstate==1 && soundstate==0)
					{
						apply_surface(0,0,optionsscreen,screen);
						apply_surface(378,275,tick,screen);
					}
					else if(soundstate==1 && fsstate==0)
					{
						apply_surface(0,0,optionsscreen,screen);
						apply_surface(378,125,tick,screen);
					}
					else 
					{
						apply_surface(0,0,optionsscreen,screen);
					}
					apply_surface(239,460,savemo,screen);
					SDL_Flip(screen);
				}
				else 
				{
					apply_surface(0,0,bg,screen);
					apply_surface(0,0,optionsscreen,screen);
					if(soundstate==1 && fsstate==1) 
					{
						apply_surface(378,125,tick,screen);
						apply_surface(378,275,tick,screen);
					}
					else if(fsstate==1 && soundstate==0)
					{
						apply_surface(0,0,optionsscreen,screen);
						apply_surface(378,275,tick,screen);
					}
					else if(soundstate==1 && fsstate==0)
					{
						apply_surface(0,0,optionsscreen,screen);
						apply_surface(378,125,tick,screen);
					}
					else 
					{
						apply_surface(0,0,optionsscreen,screen);
					}
					apply_surface(239,460,native,screen);
					SDL_Flip(screen);
				}
				break;
			}
			case SDL_MOUSEBUTTONDOWN : 
			{
				if(event.button.button==SDL_BUTTON_LEFT)
				{
					if(event.button.x>560 && event.button.x<605 && event.button.y>197 && event.button.y<239)
					{
						if(soundstate==1)
						{
							soundstate=0;
							apply_surface(0,0,bg,screen);
							apply_surface(0,0,optionsscreen,screen);
							if(fsstate==1)
							{
								apply_surface(562,275,tick,screen);
							}
							apply_surface(239,460,native,screen);
							SDL_Flip(screen);
						}
						else if(soundstate==0)
						{
							soundstate=1;
							apply_surface(0,0,bg,screen);
							apply_surface(0,0,optionsscreen,screen);
							apply_surface(378,125,tick,screen);
							if(fsstate==1)
							{
								apply_surface(562,275,tick,screen);
							}
							apply_surface(239,460,native,screen);
							SDL_Flip(screen);
						}
					}
					else if(event.button.x>560 && event.button.x<605 && event.button.y>280 && event.button.y<325)
					{
						if(fsstate==1)
						{
							fsstate=0;
							apply_surface(0,0,bg,screen);
							apply_surface(0,0,optionsscreen,screen);
							if(soundstate==1)
							{
								apply_surface(378,125,tick,screen);
							}
							apply_surface(239,460,native,screen);
							SDL_Flip(screen);
						}
						else if(fsstate==0)
						{
							fsstate=1;
							apply_surface(0,0,bg,screen);
							apply_surface(0,0,optionsscreen,screen);
							apply_surface(378,275,tick,screen);
							if(soundstate==1)
							{
								apply_surface(378,125,tick,screen);
							}
							apply_surface(239,460,native,screen);
							SDL_Flip(screen);
						}
					}
					else if(event.button.x>240 && event.button.x<460 && event.button.y>460 && event.button.y<530)
					{
						continuer=0;
					}
					else if(event.button.x>530 && event.button.x<752 && event.button.y>460 && event.button.y<530)
					{
						fclose(f);
						f=fopen("actualoptions.txt","w");
						fprintf(f,"%d %d",soundstate,fsstate);
						fclose(f);
						if(soundstate==1)
						{
							Mix_VolumeMusic(128);
						}
						else 
						{
							Mix_VolumeMusic(0);
						}
						if(fsstate==1)
						{
							screen=SDL_SetVideoMode( 1024, 600, 32, SDL_SWSURFACE | SDL_FULLSCREEN );
							SDL_Flip(screen);
						}
						else 
						{
							screen=SDL_SetVideoMode( 1024, 600, 32, SDL_SWSURFACE);
							SDL_Flip(screen);
						}
						continuer=0;
					}
				}
				break;
			}
			case SDL_QUIT : 
			{
				SDL_Quit();
			}
		}
	}
}


