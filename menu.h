#ifndef menu_h
#define menu_h
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include <stdio.h>
#include <SDL/SDL_mixer.h>
#include <SDL/SDL_ttf.h>
#include "menu.h"

void apply_surface( int x, int y, SDL_Surface* source, SDL_Surface* destination ) ;
void menu(SDL_Surface *bg,SDL_Surface *screen);
#endif /* menu_h */
