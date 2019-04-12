

#ifndef bg_h
#define bg_h

#include <stdio.h>
#include <stdlib.h>
#include <stdio.h>
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include "perso.h"

typedef struct
{
    SDL_Surface *background;
    SDL_Surface *ecran;
    SDL_Rect pos;
}stage;
stage s;
SDL_Surface *initialiser_stage(stage *s,char chaine[]);
void afficher_background(SDL_Surface *bg,SDL_Rect *pos,SDL_Surface *screen);
void scrolling(personnage *p,stage *stage1 );



#endif /* bg_h */
