#include <3ds.h>
#include "textstuff.h"
#include "letters.h"

void tsDrawLetter(gfxScreen_t screen, gfx3dSide_t side, char letter, u16 x, u16 y, u8 r, u8 g, u8 b) {
    int i;
    int k;
    unsigned char mask;
    unsigned char* _letter;
    unsigned char l;
    u8* fb = gfxGetFramebuffer(screen, side, NULL, NULL);

    switch(letter) {
        case 'a':
            _letter = letter_A;
		    break;
        case 'b':
            _letter = letter_B;
            break;
        case 'c':
            _letter = letter_C;
            break;
        case 'd':
            _letter = letter_D;
            break;
        case 'e':
            _letter = letter_E;
            break;
        case 'f':
            _letter = letter_F;
            break;
        case 'g':
            _letter = letter_G;
            break;
        case 'h':
            _letter = letter_H;
            break;
        case 'i':
            _letter = letter_I;
            break;
        case 'j':
            _letter = letter_J;
            break;
        case 'k':
            _letter = letter_K;
            break;
        case 'l':
            _letter = letter_L;
            break;
        case 'm':
            _letter = letter_M;
            break;
        case 'n':
            _letter = letter_N;
            break;
        case 'o':
            _letter = letter_O;
            break;
        case 'p':
            _letter = letter_P;
            break;
        case 'q':
            _letter = letter_Q;
            break;
        case 'r':
            _letter = letter_R;
            break;
        case 's':
            _letter = letter_S;
            break;
        case 't':
            _letter = letter_T;
            break;
        case 'u':
            _letter = letter_U;
            break;
        case 'v':
            _letter = letter_V;
            break;
        case 'w':
            _letter = letter_W;
            break;
        case 'x':
            _letter = letter_X;
            break;
        case 'y':
            _letter = letter_Y;
            break;
        case 'z':
            _letter = letter_Z;
            break;
        case ' ':
            return;
            break;
        case '.':
            _letter = letter_period;
            break;
        case ':':
            _letter = letter_colon;
            break;
        case '-':
            _letter = letter_dash;
            break;
        case ',':
            _letter = letter_comma;
            break;
        case '!':
            _letter = letter_exclamation;
            break;
        case '?':
            _letter = letter_question;
            break;
	    case '"':
            _letter = letter_quote;
			break;
        case '1':
            _letter = letter_1;
            break;
		case '2':
	        _letter = letter_2;
            break;
        case '3':
            _letter = letter_3;
            break;
        case '4':
            _letter = letter_4;
            break;
        case '5':
            _letter = letter_5;
            break;
        case '6':
            _letter = letter_6;
            break;
        case '7':
            _letter = letter_7;
            break;
        case '8':
            _letter = letter_8;
            break;
        case '9':
            _letter = letter_9;
            break;
        case '0':
            _letter = letter_0;
            break;
        default:
            return;
            break;
    }

    for (i = 0; i < 8; i++) {
        mask = 0b10000000;
        l = _letter[i];
        for (k = 0; k < 8; k++){
            if ((mask >> k) & l){
                fb[3*(8-i+y+(k+x)*240)] = r;
                fb[3*(8-i+y+(k+x)*240)+1] = g;
                fb[3*(8-i+y+(k+x)*240)+2] = b;
            }     
        }
    }
}

void tsDrawWord(gfxScreen_t screen, gfx3dSide_t side, char* word, u16 x, u16 y, u8 r, u8 g, u8 b){
    int tmp_x = x;
    int i;
    int line = 0;
    u16 width;
    
    if (screen == GFX_TOP)
        width = 400;
    else
        width = 320;

    for (i = 0; i < strlen(word); i++){
     
      if (tmp_x+8 > width) {
        line++;
        tmp_x = x;
      }
      tsDrawLetter(screen,side,word[i],tmp_x,y+(line*8),r,g,b);

      tmp_x = tmp_x+8;
    }

}