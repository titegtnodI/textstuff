#ifndef MEMORY_H
#define MEMORY_H

#define TOP_HEIGHT 240
#define TOP_WIDTH 400

void paint_pixel(u8* fb, u16 x, u16 y, u8 r, u8 g, u8 b);
void paint_letter(u8* fb, char letter, u16 x, u16 y, u8 r, u8 g, u8 b);
void paint_word(u8* fb, char* word, u16 x, u16 y, u8 r, u8 g, u8 b);
#endif

