#include <stdlib.h>
#include <stdio.h>
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include "bg.h"
#include "perso.h"


SDL_Surface *initialiser_stage(stage *s,char chaine[])
{
    s->pos.x=0;
    s->pos.y=0;
    s->pos.w=s->background->w=4730;
    s->pos.h=s->background->h=430;
    
    SDL_Surface *tmp=NULL,*image=NULL;
    tmp=IMG_Load(chaine);
    SDL_SetColorKey(tmp,SDL_SRCCOLORKEY,SDL_MapRGB(tmp->format,255,255,255));
    image=SDL_DisplayFormat(tmp);
    SDL_FreeSurface(tmp);
    tmp=NULL;
    return image;
    
}

void afficher_background(SDL_Surface *bg,SDL_Rect *pos,SDL_Surface *screen)
{
    SDL_BlitSurface(bg,pos,screen,NULL);
}

void scrolling(personnage *p,stage *stage1 )
{
    
    if((p->position.x>=450)&&(stage1->pos.x<=(4730-558)))
    {
        stage1->pos.x+=20;
        p->position.x=430;
        
        p->v.o.positionObjet.x+=0.1;
    }
    if((p->position.x<=50)&&(stage1->pos.x>=0))
    {
        stage1->pos.x-=20;
        p->position.x=70;
        p->v.o.positionObjet.x-=0.1;
    }
    
}
