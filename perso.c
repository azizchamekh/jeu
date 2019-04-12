
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include <stdio.h>
#include <SDL/SDL_mixer.h>
#include <SDL/SDL_ttf.h>
#include "perso.h"
#include "bg.h"

void initialiser_personnage(personnage *p)
{
    p->position.x=20;
    p->position.y=220;
    p->position.w=75;
    p->position.h=80;
    p->v.val=100;
    p->acceleration=0;
    p->vitesse=20;
    p->score=0;
    p->id=1;
    p->v.o=init(p->v.o,25,25,100,100);
    
}



void anim_perso(int *i, SDL_Event *event,personnage *p){
    char lien[20];
    SDL_PollEvent(event);
    switch(event->type)
    {case SDL_KEYDOWN:
            switch(event->key.keysym.sym)
        {case SDLK_RIGHT:
                (*i)++;
                if(*i>5)*i=1;
                sprintf(lien,"r%d.png",*i);
                SDL_Delay(150);
                p->sprite = IMG_Load(lien);
                break;
            case SDLK_LEFT: (*i)++;
                if(*i>5)*i=1;
                sprintf(lien,"l%d.png",*i);
                SDL_Delay(150);
                p->sprite = IMG_Load(lien);
                break;
                
        }
        break; }
}


void Deplacement_personnage(SDL_Event *event,personnage *p,int *continuer,stage *s)
{
    int old_y;
    SDL_PollEvent(event);
    switch(event->type)
    {
        case SDL_QUIT:
            (*continuer)=0;
            break;
        case SDL_MOUSEBUTTONDOWN :
            if(event->button.button==SDL_BUTTON_LEFT)
            {
                if(event->button.x-s->pos.x>p->position.x-s->pos.x)
                {
                    p->position.x+=p->vitesse+p->acceleration*0.2;}
                
                if(event->button.x-s->pos.x<p->position.x-s->pos.x)
                {
                    p->position.x-=p->vitesse+p->acceleration*0.2;}
                
                
            }
            break;
        case SDL_KEYDOWN:
            switch(event->key.keysym.sym)
        {
            case SDLK_UP:
                p->position.y-=p->vitesse/6;
                break;
            case SDLK_DOWN:
                p->position.y+=p->vitesse/6;
                
                break;
            case SDLK_RIGHT:
                p->position.x+=p->vitesse+p->acceleration*0.2;
                break;
            case SDLK_LEFT:
                p->position.x-=p->vitesse+p->acceleration*0.2;
                break;
        }
            break;
    }
    
}
int main(int argc, char *argv[])
{
    SDL_Event event;
    int continuer = 1;
    personnage p;
    stage s;
    SDL_Init(SDL_INIT_VIDEO);
    // s.ecran = SDL_SetVideoMode(1000, 480, 32, SDL_HWSURFACE|SDL_DOUBLEBUF);
    s.ecran = SDL_SetVideoMode(558,417, 32, SDL_HWSURFACE);
    SDL_WM_SetCaption("Test", NULL);
    p.sprite = IMG_Load("r1.png");
    s.background=IMG_Load("small.png");
    SDL_SetColorKey(p.sprite, SDL_SRCCOLORKEY, SDL_MapRGB(p.sprite->format, 0, 0, 255));
    initialiser_personange(&p);
    s.background=initialiser_stage(&s,"small.png");
    while (continuer)
    {
        Deplacement_personnage(&event,&p,&continuer,&s);
        anim_perso (&i,&event,&p)
        scrolling(&p,&s);
        afficher_background(s.background,&s.pos,s.ecran);
        SDL_BlitSurface(p.sprite, NULL,s.ecran,&p.position);
        SDL_Flip(s.ecran);
    }
    
    SDL_FreeSurface(p.sprite);
    SDL_Quit();
    
    return EXIT_SUCCESS;
}
