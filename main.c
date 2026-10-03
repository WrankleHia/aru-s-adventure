#include <gb/gb.h>
#include <stdio.h>
#include "mainsprites.c"
#include "titlescreen_data.c"
#include "titlescreen_map.c"

UINT8 currentstate = 0;
UINT8 currentspriteframe = 1;
UINT8 ArrowX = 45;
UINT8 ArrowDirection = 1;

void TitleScreen2(){
        set_sprite_tile(0, 13);
        move_sprite(0, 45, 120);
        SHOW_SPRITES;
        printf("\n ------------------\n   Aru's Adventure\n ------------------\n\n\n\n\n\n\n\n\n\n      PUSH START\n\n\n (c)2024 WrankleHia");
        while(1){
        move_sprite(0, ArrowX, 120);
        if(ArrowX <= 46){
            ArrowX++;
        }else{
            ArrowX--;
        }
        if(joypad()){
                NR10_REG = 0x16;
                NR11_REG = 0x40;
                NR12_REG = 0x73;
                NR14_REG = 0xC3;
        }
        delay(100);
    }
}
void TitleScreen(){
    set_sprite_data(0, 14, mainsprites);
    set_sprite_tile(0, currentspriteframe);
    move_sprite(0, 30, 135);
    SHOW_SPRITES;
    while(1){ 
        set_sprite_tile(0, currentspriteframe);
        currentspriteframe++;
        if(currentspriteframe == 13){
            currentspriteframe = 1;
        }
        if(joypad()){
            if(currentstate == 0){
            currentstate++;
            set_sprite_tile(0, 0);
            TitleScreen2();
        }
        }
        delay(80);
    }
}

void main(){
    NR52_REG = 0x80;
    NR50_REG = 0x77;
    NR51_REG = 0xFF;
    set_bkg_data(0, 249, titlescreen_data);
    set_bkg_tiles(0, 0, 20, 18, titlescreen_map);
    SHOW_BKG;
    DISPLAY_ON;
    TitleScreen();
}