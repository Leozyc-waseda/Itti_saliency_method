

/*
 *
 * Headline23
 *
 * created with FontCreator
 * written by F. Maximilian Thiele
 *
 * http://www.apetech.de/fontCreator
 * me@apetech.de
 *
 * File Name           : Headline23.h
 * Date                : 23.05.2009
 * Font size in bytes  : 17582
 * Font width          : 10
 * Font height         : 23
 * Font first char     : 32
 * Font last char      : 128
 * Font used chars     : 96
 *
 * The font data are defined as
 *
 * struct _FONT_ {
 *     uint16_t   font_Size_in_Bytes_over_all_included_Size_it_self;
 *     uint8_t    font_Width_in_Pixel_for_fixed_drawing;
 *     uint8_t    font_Height_in_Pixel_for_all_characters;
 *     unit8_t    font_First_Char;
 *     uint8_t    font_Char_Count;
 *
 *     uint8_t    font_Char_Widths[font_Last_Char - font_First_Char +1];
 *                  // for each character the separate width in pixels,
 *                  // characters < 128 have an implicit virtual right empty row
 *
 *     uint8_t    font_data[];
 *                  // bit field of all characters
 */

#include <inttypes.h>
#include <avr/pgmspace.h>

#ifndef HEADLINE23_H
#define HEADLINE23_H

#define HEADLINE23_WIDTH 10
#define HEADLINE23_HEIGHT 23

static uint8_t Headline23[] PROGMEM = {
    0x44, 0xAE, // size
    0x0A, // width
    0x17, // height
    0x20, // first char
    0x60, // char count

    // char widths
    0x00, 0x04, 0x06, 0x0C, 0x07, 0x0F, 0x0B, 0x03, 0x05, 0x04,
    0x04, 0x0A, 0x03, 0x06, 0x03, 0x08, 0x08, 0x06, 0x08, 0x08,
    0x09, 0x08, 0x08, 0x08, 0x08, 0x08, 0x03, 0x03, 0x08, 0x0A,
    0x08, 0x08, 0x10, 0x0B, 0x09, 0x0A, 0x0A, 0x07, 0x07, 0x09,
    0x0A, 0x04, 0x0A, 0x0A, 0x08, 0x0D, 0x0A, 0x0A, 0x09, 0x0A,
    0x09, 0x08, 0x09, 0x0A, 0x0A, 0x10, 0x09, 0x0A, 0x07, 0x04,
    0x07, 0x04, 0x09, 0x16, 0x04, 0x08, 0x08, 0x08, 0x08, 0x08,
    0x06, 0x08, 0x08, 0x04, 0x05, 0x08, 0x03, 0x0D, 0x08, 0x08,
    0x08, 0x08, 0x06, 0x07, 0x05, 0x08, 0x09, 0x0D, 0x09, 0x09,
    0x07, 0x06, 0x02, 0x06, 0x0F, 0x00,

    // font data
    0xFC, 0xFC, 0xFC, 0xFC, 0xBF, 0xBF, 0xBF, 0x83, 0x06, 0x06, 0x06, 0x06, // 33
    0x7C, 0x3C, 0x0C, 0x00, 0x3C, 0x3C, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, // 34
    0x00, 0x80, 0x80, 0x80, 0xF0, 0xF0, 0x80, 0x80, 0x80, 0xE0, 0xF0, 0x80, 0x21, 0x31, 0xF1, 0xFF, 0x3F, 0x31, 0x31, 0xF1, 0xFF, 0x3F, 0x33, 0x31, 0x00, 0x04, 0x06, 0x02, 0x00, 0x00, 0x00, 0x06, 0x06, 0x00, 0x00, 0x00, // 35
    0xC0, 0xE0, 0xF0, 0x38, 0xF0, 0xE0, 0xC0, 0xF3, 0xF7, 0xE7, 0x8F, 0xFE, 0xFC, 0xF8, 0x00, 0x00, 0x02, 0x06, 0x02, 0x00, 0x00, // 36
    0xF0, 0xF8, 0x08, 0xF8, 0xF8, 0xE0, 0x00, 0x00, 0x80, 0xC0, 0xE0, 0x30, 0x18, 0x08, 0x00, 0x03, 0x07, 0x86, 0xC7, 0x73, 0x39, 0x1C, 0x06, 0x03, 0xF9, 0xFC, 0x0C, 0x9C, 0xFC, 0xF0, 0x04, 0x06, 0x06, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x02, 0x06, 0x06, 0x06, 0x02, 0x00, // 37
    0xC0, 0xF0, 0xF0, 0xF8, 0x38, 0xF8, 0xF0, 0xE0, 0x00, 0x00, 0x00, 0xF0, 0xFB, 0xFF, 0xBF, 0x9F, 0xFF, 0xFF, 0xF1, 0xE0, 0xF0, 0x30, 0x02, 0x06, 0x06, 0x06, 0x06, 0x06, 0x02, 0x06, 0x06, 0x06, 0x06, // 38
    0x7C, 0x3C, 0x0C, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, // 39
    0xC0, 0xF8, 0xFE, 0x3E, 0x02, 0xFF, 0xFF, 0xFF, 0x00, 0x00, 0x00, 0x0E, 0x1E, 0x3E, 0x00, // 40
    0x1E, 0xFE, 0xF8, 0xC0, 0x00, 0xFF, 0xFF, 0xFF, 0x3C, 0x3E, 0x0E, 0x00, // 41
    0x38, 0x3C, 0x3C, 0x38, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, // 42
    0x00, 0x00, 0x00, 0x00, 0xE0, 0xE0, 0x00, 0x00, 0x00, 0x00, 0x06, 0x06, 0x06, 0x06, 0x7F, 0x7F, 0x06, 0x06, 0x06, 0x06, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, // 43
    0x00, 0x00, 0x00, 0x80, 0x80, 0x80, 0x1E, 0x0E, 0x02, // 44
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x0C, 0x0C, 0x0C, 0x0C, 0x0C, 0x0C, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, // 45
    0x00, 0x00, 0x00, 0x80, 0x80, 0x80, 0x06, 0x06, 0x06, // 46
    0x00, 0x00, 0x00, 0xC0, 0xF8, 0xFC, 0x3C, 0x04, 0x00, 0xE0, 0xFC, 0xFF, 0x1F, 0x03, 0x00, 0x00, 0x04, 0x06, 0x06, 0x02, 0x00, 0x00, 0x00, 0x00, // 47
    0xF8, 0xFC, 0xFC, 0x0C, 0x1C, 0xFC, 0xFC, 0xF0, 0xFF, 0xFF, 0xFF, 0x80, 0x80, 0xFF, 0xFF, 0xFF, 0x02, 0x06, 0x06, 0x06, 0x06, 0x06, 0x06, 0x00, // 48
    0x30, 0x70, 0xF8, 0xFC, 0xFC, 0xFC, 0x00, 0x00, 0xFF, 0xFF, 0xFF, 0xFF, 0x00, 0x00, 0x06, 0x06, 0x06, 0x06, // 49
    0x70, 0x7C, 0x7C, 0x0C, 0xDC, 0xFC, 0xFC, 0xF0, 0xC0, 0xE0, 0xF8, 0xFE, 0xBF, 0x8F, 0x87, 0x80, 0x06, 0x06, 0x06, 0x06, 0x06, 0x06, 0x06, 0x06, // 50
    0x38, 0x3C, 0x3C, 0x0C, 0x9C, 0xFC, 0xFC, 0xF8, 0xF0, 0xF0, 0xF3, 0x87, 0x8F, 0xFF, 0xFF, 0xFC, 0x02, 0x06, 0x06, 0x06, 0x06, 0x06, 0x06, 0x02, // 51
    0x00, 0x00, 0xE0, 0xFC, 0xFC, 0xFC, 0xFC, 0xFC, 0x00, 0x70, 0x7E, 0x7F, 0x73, 0x70, 0xFF, 0xFF, 0xFF, 0x70, 0x00, 0x00, 0x00, 0x00, 0x00, 0x06, 0x06, 0x06, 0x00, // 52
    0xFC, 0xFC, 0xFC, 0x8C, 0xCC, 0xCC, 0xCC, 0x80, 0xF3, 0xF3, 0xF3, 0x01, 0xFF, 0xFF, 0xFF, 0xFF, 0x02, 0x06, 0x06, 0x06, 0x06, 0x06, 0x06, 0x00, // 53
    0xF8, 0xFC, 0xFC, 0x0C, 0x9C, 0xBC, 0x3C, 0x38, 0xFF, 0xFF, 0xFF, 0x83, 0x83, 0xFF, 0xFF, 0xFF, 0x02, 0x06, 0x06, 0x06, 0x06, 0x06, 0x06, 0x00, // 54
    0x1C, 0x1C, 0x1C, 0x1C, 0xFC, 0xFC, 0xFC, 0x7C, 0x00, 0x00, 0xE0, 0xFF, 0xFF, 0xFF, 0x07, 0x00, 0x00, 0x00, 0x06, 0x06, 0x06, 0x00, 0x00, 0x00, // 55
    0xF8, 0xFC, 0xFC, 0x0C, 0x9C, 0xFC, 0xFC, 0xF8, 0xFE, 0xFF, 0xFF, 0x87, 0x87, 0xFF, 0xFF, 0xFC, 0x02, 0x06, 0x06, 0x06, 0x06, 0x06, 0x06, 0x00, // 56
    0xF8, 0xFC, 0xFC, 0x0C, 0x1C, 0xFC, 0xFC, 0xF0, 0xCF, 0xCF, 0xDF, 0x0C, 0x8E, 0xFF, 0xFF, 0xFF, 0x02, 0x06, 0x06, 0x06, 0x06, 0x06, 0x02, 0x00, // 57
    0x80, 0x80, 0x00, 0x87, 0x87, 0x87, 0x06, 0x06, 0x06, // 58
    0x80, 0x80, 0x00, 0x87, 0x87, 0x87, 0x1E, 0x0E, 0x02, // 59
    0x00, 0x00, 0xC0, 0xF0, 0xFC, 0x3F, 0x0F, 0x03, 0x04, 0x1F, 0x7F, 0xFF, 0xE1, 0x80, 0x00, 0x00, 0x00, 0x00, 0x00, 0x02, 0x1E, 0x3E, 0x3C, 0x30, // 60
    0x80, 0x80, 0x80, 0x80, 0x80, 0x80, 0x80, 0x80, 0x80, 0x80, 0x19, 0x19, 0x19, 0x19, 0x19, 0x19, 0x19, 0x19, 0x19, 0x19, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, // 61
    0x03, 0x0F, 0x3F, 0xFE, 0xF0, 0xC0, 0x00, 0x00, 0x00, 0x00, 0x80, 0xE1, 0xFF, 0x7F, 0x1F, 0x04, 0x30, 0x3C, 0x3E, 0x1E, 0x06, 0x00, 0x00, 0x00, // 62
    0x78, 0x7C, 0x7C, 0x1C, 0xDC, 0xFC, 0xFC, 0xF0, 0x00, 0x00, 0x98, 0x9F, 0x9F, 0x8F, 0x03, 0x00, 0x00, 0x00, 0x06, 0x06, 0x06, 0x06, 0x00, 0x00, // 63
    0x80, 0xE0, 0x70, 0x18, 0x88, 0xCC, 0x64, 0x24, 0x24, 0xC4, 0xE4, 0xEC, 0x08, 0x18, 0x70, 0xE0, 0x3F, 0x7B, 0xC0, 0x8C, 0x3F, 0x77, 0x40, 0x40, 0x70, 0x7F, 0x7F, 0x61, 0x60, 0x30, 0x98, 0x0F, 0x00, 0x00, 0x00, 0x02, 0x06, 0x04, 0x04, 0x0C, 0x0C, 0x0C, 0x0C, 0x04, 0x06, 0x02, 0x02, 0x00, // 64
    0x00, 0x00, 0xFC, 0xFC, 0xFC, 0xFC, 0xFC, 0xFC, 0xFC, 0x00, 0x00, 0x00, 0xFF, 0xFF, 0xFF, 0xFF, 0x70, 0xFF, 0xFF, 0xFF, 0xFE, 0x00, 0x06, 0x06, 0x06, 0x06, 0x06, 0x00, 0x06, 0x06, 0x06, 0x06, 0x06, // 65
    0xFC, 0xFC, 0xFC, 0xFC, 0x1C, 0xFC, 0xFC, 0xF8, 0xF0, 0xFF, 0xFF, 0xFF, 0xFF, 0x87, 0xFF, 0xFF, 0xFF, 0xFD, 0x06, 0x06, 0x06, 0x06, 0x06, 0x06, 0x06, 0x06, 0x02, // 66
    0xC0, 0xF8, 0xFC, 0xFC, 0xFC, 0x0C, 0xFC, 0xFC, 0xF8, 0xF0, 0x3F, 0xFF, 0xFF, 0xFF, 0xFF, 0x80, 0xF0, 0xF0, 0xF0, 0xF0, 0x00, 0x02, 0x06, 0x06, 0x06, 0x06, 0x06, 0x06, 0x02, 0x00, // 67
    0xFC, 0xFC, 0xFC, 0xFC, 0x1C, 0xFC, 0xFC, 0xF8, 0xF8, 0xE0, 0xFF, 0xFF, 0xFF, 0xFF, 0x80, 0xFF, 0xFF, 0xFF, 0xFF, 0x7F, 0x06, 0x06, 0x06, 0x06, 0x06, 0x06, 0x06, 0x06, 0x02, 0x00, // 68
    0xFC, 0xFC, 0xFC, 0xFC, 0x1C, 0x1C, 0x1C, 0xFF, 0xFF, 0xFF, 0xFF, 0x87, 0x87, 0x87, 0x06, 0x06, 0x06, 0x06, 0x06, 0x06, 0x06, // 69
    0xFC, 0xFC, 0xFC, 0xFC, 0x1C, 0x1C, 0x1C, 0xFF, 0xFF, 0xFF, 0xFF, 0x07, 0x07, 0x07, 0x06, 0x06, 0x06, 0x06, 0x00, 0x00, 0x00, // 70
    0xF0, 0xF8, 0xFC, 0xFC, 0x0C, 0x3C, 0xFC, 0xF8, 0xF8, 0xFF, 0xFF, 0xFF, 0xFF, 0x80, 0x8E, 0xFE, 0xFE, 0xFE, 0x00, 0x02, 0x06, 0x06, 0x06, 0x06, 0x06, 0x06, 0x02, // 71
    0xFC, 0xFC, 0xFC, 0xFC, 0x00, 0xFC, 0xFC, 0xFC, 0xFC, 0xFC, 0xFF, 0xFF, 0xFF, 0xFF, 0x07, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0x06, 0x06, 0x06, 0x06, 0x00, 0x06, 0x06, 0x06, 0x06, 0x06, // 72
    0xFC, 0xFC, 0xFC, 0xFC, 0xFF, 0xFF, 0xFF, 0xFF, 0x06, 0x06, 0x06, 0x06, // 73
    0x00, 0x00, 0x00, 0x00, 0x00, 0xFC, 0xFC, 0xFC, 0xFC, 0xFC, 0x60, 0xE0, 0xE0, 0xE0, 0x80, 0xFF, 0xFF, 0xFF, 0xFF, 0x3F, 0x00, 0x02, 0x06, 0x06, 0x06, 0x06, 0x06, 0x06, 0x02, 0x00, // 74
    0xFC, 0xFC, 0xFC, 0xFC, 0xC0, 0xFC, 0xFC, 0xFC, 0x1C, 0x00, 0xFF, 0xFF, 0xFF, 0xFF, 0x3F, 0xFF, 0xFF, 0xFC, 0xE0, 0x00, 0x06, 0x06, 0x06, 0x06, 0x00, 0x06, 0x06, 0x06, 0x06, 0x04, // 75
    0xFC, 0xFC, 0xFC, 0xFC, 0x00, 0x00, 0x00, 0x00, 0xFF, 0xFF, 0xFF, 0xFF, 0x80, 0x80, 0x80, 0x80, 0x06, 0x06, 0x06, 0x06, 0x06, 0x06, 0x06, 0x06, // 76
    0xFC, 0xFC, 0xFC, 0xFC, 0xFC, 0xFC, 0x00, 0xFC, 0xFC, 0xFC, 0xFC, 0xFC, 0xFC, 0xFF, 0xFF, 0xFF, 0x03, 0x3F, 0xFF, 0xFF, 0xFF, 0x3F, 0x03, 0xFF, 0xFF, 0xFF, 0x06, 0x06, 0x06, 0x00, 0x00, 0x06, 0x06, 0x06, 0x00, 0x00, 0x06, 0x06, 0x06, // 77
    0xFC, 0xFC, 0xFC, 0xFC, 0xE0, 0x80, 0x00, 0xFC, 0xFC, 0xFC, 0xFF, 0xFF, 0xFF, 0x0F, 0x1F, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0x06, 0x06, 0x06, 0x00, 0x00, 0x00, 0x06, 0x06, 0x06, 0x06, // 78
    0xF0, 0xF8, 0xFC, 0xFC, 0x1C, 0xFC, 0xFC, 0xFC, 0xF8, 0xC0, 0xFF, 0xFF, 0xFF, 0xFF, 0x80, 0xFF, 0xFF, 0xFF, 0xFF, 0x3F, 0x00, 0x02, 0x06, 0x06, 0x06, 0x06, 0x06, 0x02, 0x02, 0x00, // 79
    0xFC, 0xFC, 0xFC, 0xFC, 0x1C, 0xFC, 0xFC, 0xF8, 0xF0, 0xFF, 0xFF, 0xFF, 0xFF, 0x0E, 0x07, 0x07, 0x07, 0x03, 0x06, 0x06, 0x06, 0x06, 0x00, 0x00, 0x00, 0x00, 0x00, // 80
    0xF0, 0xF8, 0xFC, 0xFC, 0x1C, 0xFC, 0xFC, 0xFC, 0xF8, 0xE0, 0xFF, 0xFF, 0xFF, 0xFF, 0x80, 0xFF, 0xFF, 0xFF, 0xFF, 0x7F, 0x00, 0x02, 0x06, 0x06, 0x0E, 0x1E, 0x1E, 0x1A, 0x18, 0x18, // 81
    0xFC, 0xFC, 0xFC, 0xFC, 0x1C, 0xFC, 0xFC, 0xFC, 0xF8, 0xFF, 0xFF, 0xFF, 0xFF, 0x07, 0xFF, 0xFF, 0xFF, 0xFD, 0x06, 0x06, 0x06, 0x06, 0x00, 0x06, 0x06, 0x06, 0x06, // 82
    0xF8, 0xFC, 0xFC, 0x9C, 0x3C, 0x3C, 0x3C, 0x38, 0xE1, 0xE3, 0xE7, 0x8F, 0x9F, 0xFF, 0xFE, 0xFC, 0x02, 0x06, 0x06, 0x06, 0x06, 0x06, 0x06, 0x02, // 83
    0x1C, 0x1C, 0x1C, 0xFC, 0xFC, 0xFC, 0xFC, 0x1C, 0x1C, 0x00, 0x00, 0x00, 0xFF, 0xFF, 0xFF, 0xFF, 0x00, 0x00, 0x00, 0x00, 0x00, 0x06, 0x06, 0x06, 0x06, 0x00, 0x00, // 84
    0xFC, 0xFC, 0xFC, 0xFC, 0x00, 0xFC, 0xFC, 0xFC, 0xFC, 0xFC, 0xFF, 0xFF, 0xFF, 0xFF, 0x80, 0xFF, 0xFF, 0xFF, 0xFF, 0x3F, 0x00, 0x02, 0x06, 0x06, 0x06, 0x06, 0x06, 0x06, 0x02, 0x00, // 85
    0x0C, 0xFC, 0xFC, 0xFC, 0xF0, 0xC0, 0xFC, 0xFC, 0xFC, 0x3C, 0x00, 0x0F, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0x7F, 0x00, 0x00, 0x00, 0x06, 0x06, 0x06, 0x06, 0x06, 0x06, 0x00, 0x00, // 86
    0x04, 0xFC, 0xFC, 0xFC, 0xF0, 0x00, 0xFC, 0xFC, 0xFC, 0xFC, 0xF8, 0x00, 0xFC, 0xFC, 0xFC, 0xFC, 0x00, 0x07, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0x0F, 0xFF, 0xFF, 0xFC, 0xFF, 0xFF, 0xFF, 0x01, 0x00, 0x00, 0x06, 0x06, 0x06, 0x06, 0x06, 0x00, 0x00, 0x06, 0x06, 0x06, 0x06, 0x06, 0x06, 0x00, // 87
    0x3C, 0xFC, 0xFC, 0xFC, 0xC0, 0xFC, 0xFC, 0xFC, 0x0C, 0xF0, 0xFF, 0xFF, 0xFF, 0x1F, 0xFF, 0xFF, 0xFF, 0xE0, 0x06, 0x06, 0x06, 0x06, 0x00, 0x02, 0x06, 0x06, 0x06, // 88
    0x04, 0x3C, 0xFC, 0xFC, 0xF0, 0xC0, 0xFC, 0xFC, 0x7C, 0x0C, 0x00, 0x00, 0x03, 0xFF, 0xFF, 0xFF, 0xFF, 0x07, 0x00, 0x00, 0x00, 0x00, 0x00, 0x06, 0x06, 0x06, 0x06, 0x00, 0x00, 0x00, // 89
    0x1C, 0x1C, 0xDC, 0xFC, 0xFC, 0xFC, 0x7C, 0xE0, 0xFE, 0xFF, 0xFF, 0xBF, 0x87, 0x80, 0x06, 0x06, 0x06, 0x06, 0x06, 0x06, 0x06, // 90
    0xFF, 0xFF, 0x03, 0x03, 0xFF, 0xFF, 0x00, 0x00, 0x7E, 0x7E, 0x60, 0x60, // 91
    0x0C, 0xFC, 0xFC, 0xE0, 0x00, 0x00, 0x00, 0x00, 0x00, 0x0F, 0x7F, 0xFE, 0xE0, 0x00, 0x00, 0x00, 0x00, 0x00, 0x0E, 0x3E, 0x3C, // 92
    0x03, 0x03, 0xFF, 0xFF, 0x00, 0x00, 0xFF, 0xFF, 0x60, 0x60, 0x7E, 0x7E, // 93
    0x80, 0xE0, 0xF8, 0x7C, 0x3C, 0xFC, 0xF0, 0x80, 0x00, 0x03, 0x03, 0x01, 0x00, 0x00, 0x00, 0x03, 0x03, 0x02, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, // 94
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xC0, 0xC0, 0xC0, 0xC0, 0xC0, 0xC0, 0xC0, 0xC0, 0xC0, 0xC0, 0xC0, 0xC0, 0xC0, 0xC0, 0xC0, 0xC0, 0xC0, 0xC0, 0xC0, 0xC0, 0xC0, 0x40, // 95
    0x06, 0x3E, 0x3E, 0x30, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, // 96
    0xC0, 0xE0, 0xE0, 0x60, 0xE0, 0xE0, 0xC0, 0x80, 0xF1, 0xF9, 0xF9, 0x0C, 0xFF, 0xFF, 0xFF, 0xFF, 0x06, 0x06, 0x06, 0x06, 0x06, 0x06, 0x06, 0x06, // 97
    0xFC, 0xFC, 0xFC, 0x60, 0xE0, 0xE0, 0xE0, 0xC0, 0xFF, 0xFF, 0xFF, 0x80, 0x80, 0xFF, 0xFF, 0xFF, 0x06, 0x06, 0x06, 0x02, 0x06, 0x06, 0x06, 0x02, // 98
    0x00, 0xC0, 0xE0, 0xE0, 0x60, 0xE0, 0xE0, 0xC0, 0x1E, 0xFF, 0xFF, 0xFF, 0x00, 0xE3, 0xE3, 0xE3, 0x00, 0x02, 0x06, 0x06, 0x06, 0x06, 0x06, 0x02, // 99
    0xE0, 0xE0, 0xE0, 0x60, 0xFC, 0xFC, 0xFC, 0xFC, 0xFF, 0xFF, 0xFF, 0x80, 0xFF, 0xFF, 0xFF, 0xFF, 0x02, 0x06, 0x06, 0x06, 0x06, 0x06, 0x06, 0x06, // 100
    0xC0, 0xE0, 0xE0, 0x60, 0xE0, 0xE0, 0xC0, 0x00, 0xFF, 0xFF, 0xFF, 0x0E, 0xEF, 0xEF, 0xEF, 0x67, 0x02, 0x02, 0x06, 0x06, 0x06, 0x06, 0x02, 0x00, // 101
    0x60, 0xF8, 0xFC, 0xFC, 0xEC, 0x6C, 0x00, 0xFF, 0xFF, 0xFF, 0xFF, 0x00, 0x00, 0x06, 0x06, 0x06, 0x06, 0x00, // 102
    0xE0, 0xE0, 0xE0, 0x60, 0xE0, 0xE0, 0xE0, 0xE0, 0xFF, 0xFF, 0xFF, 0xC0, 0xFF, 0xFF, 0xFF, 0xFF, 0x0C, 0x1C, 0x1C, 0x18, 0x1E, 0x1E, 0x0E, 0x06, // 103
    0xFC, 0xFC, 0xFC, 0x60, 0xE0, 0xE0, 0xE0, 0xC0, 0xFF, 0xFF, 0xFF, 0x00, 0xFF, 0xFF, 0xFF, 0xFF, 0x06, 0x06, 0x06, 0x00, 0x06, 0x06, 0x06, 0x06, // 104
    0xEC, 0xEC, 0xEC, 0xEC, 0xFF, 0xFF, 0xFF, 0xFF, 0x06, 0x06, 0x06, 0x06, // 105
    0x00, 0xEC, 0xEC, 0xEC, 0xEC, 0x00, 0xFF, 0xFF, 0xFF, 0xFF, 0x18, 0x1E, 0x1E, 0x0E, 0x06, // 106
    0xFC, 0xFC, 0xFC, 0x80, 0xC0, 0xE0, 0xE0, 0x20, 0xFF, 0xFF, 0xFF, 0x3F, 0xFF, 0xFF, 0xF1, 0x80, 0x06, 0x06, 0x06, 0x00, 0x02, 0x06, 0x06, 0x06, // 107
    0xFC, 0xFC, 0xFC, 0xFF, 0xFF, 0xFF, 0x06, 0x06, 0x06, // 108
    0xE0, 0xE0, 0xE0, 0x60, 0xE0, 0xE0, 0xE0, 0xC0, 0x60, 0xE0, 0xE0, 0xE0, 0x80, 0xFF, 0xFF, 0xFF, 0x00, 0xFF, 0xFF, 0xFF, 0xFF, 0x00, 0xFF, 0xFF, 0xFF, 0xFF, 0x06, 0x06, 0x06, 0x00, 0x06, 0x06, 0x06, 0x06, 0x00, 0x06, 0x06, 0x06, 0x06, // 109
    0xE0, 0xE0, 0xE0, 0x60, 0xE0, 0xE0, 0xE0, 0xC0, 0xFF, 0xFF, 0xFF, 0x00, 0xFF, 0xFF, 0xFF, 0xFF, 0x06, 0x06, 0x06, 0x00, 0x06, 0x06, 0x06, 0x06, // 110
    0xC0, 0xE0, 0xE0, 0x60, 0xE0, 0xE0, 0xC0, 0x80, 0xFF, 0xFF, 0xFF, 0x00, 0xFF, 0xFF, 0xFF, 0xFF, 0x02, 0x06, 0x06, 0x06, 0x06, 0x06, 0x02, 0x00, // 111
    0xE0, 0xE0, 0xE0, 0xE0, 0xE0, 0xE0, 0xE0, 0xC0, 0xFF, 0xFF, 0xFF, 0x80, 0xFF, 0xFF, 0xFF, 0xFF, 0x1E, 0x1E, 0x1E, 0x02, 0x06, 0x06, 0x06, 0x02, // 112
    0xE0, 0xE0, 0xE0, 0x60, 0xE0, 0xE0, 0xE0, 0xE0, 0xFF, 0xFF, 0xFF, 0x80, 0xFF, 0xFF, 0xFF, 0xFF, 0x02, 0x06, 0x06, 0x06, 0x0E, 0x1E, 0x1E, 0x1E, // 113
    0xE0, 0xE0, 0xE0, 0xE0, 0xE0, 0xE0, 0xFF, 0xFF, 0xFF, 0x0F, 0x01, 0x01, 0x06, 0x06, 0x06, 0x00, 0x00, 0x00, // 114
    0xC0, 0xE0, 0xE0, 0x60, 0xE0, 0xE0, 0xC0, 0xC7, 0xCF, 0xCF, 0x1E, 0xFD, 0xF9, 0xF1, 0x02, 0x06, 0x06, 0x06, 0x06, 0x06, 0x02, // 115
    0xF8, 0xF8, 0xF8, 0xF8, 0x60, 0xFF, 0xFF, 0xFF, 0xFF, 0x00, 0x00, 0x06, 0x06, 0x06, 0x06, // 116
    0xE0, 0xE0, 0xE0, 0x00, 0xE0, 0xE0, 0xE0, 0xE0, 0xFF, 0xFF, 0xFF, 0x00, 0xFF, 0xFF, 0xFF, 0xFF, 0x06, 0x06, 0x06, 0x06, 0x06, 0x06, 0x06, 0x06, // 117
    0x60, 0xE0, 0xE0, 0xE0, 0x00, 0xE0, 0xE0, 0xE0, 0x60, 0x00, 0x3F, 0xFF, 0xFF, 0xF0, 0xFF, 0xFF, 0x3F, 0x00, 0x00, 0x00, 0x06, 0x06, 0x06, 0x06, 0x06, 0x00, 0x00, // 118
    0xE0, 0xE0, 0xE0, 0x00, 0x80, 0xE0, 0xE0, 0xE0, 0x00, 0x80, 0xE0, 0xE0, 0xE0, 0x0F, 0xFF, 0xFF, 0xFE, 0xFF, 0xFF, 0x3F, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0x0F, 0x00, 0x06, 0x06, 0x06, 0x06, 0x06, 0x00, 0x06, 0x06, 0x06, 0x06, 0x06, 0x00, // 119
    0x20, 0xE0, 0xE0, 0xE0, 0x00, 0xE0, 0xE0, 0xE0, 0x00, 0x00, 0xE1, 0xFF, 0xFF, 0x7F, 0xFF, 0xFF, 0xE1, 0x00, 0x04, 0x06, 0x06, 0x06, 0x00, 0x06, 0x06, 0x06, 0x04, // 120
    0x60, 0xE0, 0xE0, 0xE0, 0x00, 0xE0, 0xE0, 0xE0, 0xE0, 0x00, 0x0F, 0xFF, 0xFF, 0xF8, 0xFF, 0xFF, 0xFF, 0x00, 0x00, 0x18, 0x1E, 0x1E, 0x1E, 0x0E, 0x0E, 0x00, 0x00, // 121
    0x60, 0x60, 0xE0, 0xE0, 0xE0, 0xE0, 0xE0, 0xC0, 0xF8, 0xFE, 0xFF, 0x9F, 0x87, 0x00, 0x06, 0x06, 0x06, 0x06, 0x06, 0x06, 0x06, // 122
    0x00, 0x00, 0xF8, 0xFC, 0x1C, 0x0C, 0x1C, 0x3E, 0xFF, 0xF7, 0x00, 0x00, 0x00, 0x00, 0x1E, 0x3E, 0x38, 0x30, // 123
    0xFE, 0xFE, 0xFF, 0xFF, 0xFE, 0xFE, // 124
    0x0C, 0x1C, 0xFC, 0xF8, 0x00, 0x00, 0x00, 0x00, 0xE3, 0xFF, 0x3E, 0x1C, 0x30, 0x38, 0x3E, 0x1E, 0x00, 0x00, // 125
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x06, 0x07, 0x07, 0x03, 0x03, 0x03, 0x07, 0x07, 0x07, 0x06, 0x06, 0x06, 0x06, 0x07, 0x03, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, // 126

};

#endif
