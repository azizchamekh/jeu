
#ifndef perso_h
#define perso_h

#include <stdio.h>
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include <stdio.h>
#include <SDL/SDL_mixer.h>
#include <SDL/SDL_ttf.h>
#include "bg.h"

typedef struct
{int id;
    SDL_Rect position;
    SDL_Surface *sprite;
    vie v;
    int score;
    int vitesse;
    int acceleration;
}personnage;
void initialiser_personnage(personnage *p);
void afficher_perso1(SDL_Surface *ecran);
void anim_perso(int *i, SDL_Event *event,personnage *p);
void Deplacement_personnage(SDL_Event *event,personnage *p,int *continuer,stage *s);


#endif /* perso_h */
