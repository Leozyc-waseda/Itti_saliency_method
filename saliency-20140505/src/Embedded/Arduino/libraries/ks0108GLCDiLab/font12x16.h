/*********************************************
 *                                           *
 * Created with FontCreator                  *
 * Written by F. Maximilian Thiele           *
 * http://www.apeTech.de.vu                  *
 * affe.t@gmx.de                             *
 *                                           *
 * File Name: Font12x16.h                    *
 * Date:      13.02.2004                     *
 *                                           *
 *********************************************/

#include
#include

#ifndef FONT12X16_H
#define FONT12X16_H

#define FONT12X16_WIDTH 12
#define FONT12X16_HEIGHT 16

static uint8_t __attribute__ ((progmem)) Font12x16[] = {
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, // "(space)"
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x7C, 0x00, 0xFF, 0x33, 0xFF, 0x33, 0x7C, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, // "!"
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x1C, 0x00, 0x1C, 0x00, 0x00, 0x00, 0x00, 0x00, 0x1C, 0x00, 0x1C, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, // """
        0x00, 0x00, 0x00, 0x02, 0x10, 0x1E, 0x90, 0x1F, 0xF0, 0x03, 0x7E, 0x02, 0x1E, 0x1E, 0x90, 0x1F, 0xF0, 0x03, 0x7E, 0x02, 0x1E, 0x00, 0x10, 0x00, // "#"
        0x00, 0x00, 0x00, 0x00, 0x78, 0x04, 0xFC, 0x0C, 0xCC, 0x0C, 0xFF, 0x3F, 0xFF, 0x3F, 0xCC, 0x0C, 0xCC, 0x0F, 0x88, 0x07, 0x00, 0x00, 0x00, 0x00, // "$"
        0x00, 0x00, 0x00, 0x30, 0x38, 0x38, 0x38, 0x1C, 0x38, 0x0E, 0x00, 0x07, 0x80, 0x03, 0xC0, 0x01, 0xE0, 0x38, 0x70, 0x38, 0x38, 0x38, 0x1C, 0x00, // "%"
        0x00, 0x00, 0x00, 0x00, 0x00, 0x1F, 0xB8, 0x3F, 0xFC, 0x31, 0xC6, 0x21, 0xE2, 0x37, 0x3E, 0x1E, 0x1C, 0x1C, 0x00, 0x36, 0x00, 0x22, 0x00, 0x00, // "&"
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x27, 0x00, 0x3F, 0x00, 0x1F, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, // "'"
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xF0, 0x03, 0xFC, 0x0F, 0xFE, 0x1F, 0x07, 0x38, 0x01, 0x20, 0x01, 0x20, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, // "("
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0x20, 0x01, 0x20, 0x07, 0x38, 0xFE, 0x1F, 0xFC, 0x0F, 0xF0, 0x03, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, // ")"
        0x00, 0x00, 0x00, 0x00, 0x98, 0x0C, 0xB8, 0x0E, 0xE0, 0x03, 0xF8, 0x0F, 0xF8, 0x0F, 0xE0, 0x03, 0xB8, 0x0E, 0x98, 0x0C, 0x00, 0x00, 0x00, 0x00, // "*"
        0x00, 0x00, 0x00, 0x00, 0x80, 0x01, 0x80, 0x01, 0x80, 0x01, 0xF0, 0x0F, 0xF0, 0x0F, 0x80, 0x01, 0x80, 0x01, 0x80, 0x01, 0x00, 0x00, 0x00, 0x00, // "+"
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xB8, 0x00, 0xF8, 0x00, 0x78, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, // ","
        0x00, 0x00, 0x00, 0x00, 0x80, 0x01, 0x80, 0x01, 0x80, 0x01, 0x80, 0x01, 0x80, 0x01, 0x80, 0x01, 0x80, 0x01, 0x80, 0x01, 0x00, 0x00, 0x00, 0x00, // "-"
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x38, 0x00, 0x38, 0x00, 0x38, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, // "."
        0x00, 0x00, 0x00, 0x18, 0x00, 0x1C, 0x00, 0x0E, 0x00, 0x07, 0x80, 0x03, 0xC0, 0x01, 0xE0, 0x00, 0x70, 0x00, 0x38, 0x00, 0x1C, 0x00, 0x0E, 0x00, // "/"
        0x00, 0x00, 0xF8, 0x07, 0xFE, 0x1F, 0x06, 0x1E, 0x03, 0x33, 0x83, 0x31, 0xC3, 0x30, 0x63, 0x30, 0x33, 0x30, 0x1E, 0x18, 0xFE, 0x1F, 0xF8, 0x07, // "0"
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x0C, 0x30, 0x0C, 0x30, 0x0E, 0x30, 0xFF, 0x3F, 0xFF, 0x3F, 0x00, 0x30, 0x00, 0x30, 0x00, 0x30, 0x00, 0x00, // "1"
        0x00, 0x00, 0x1C, 0x30, 0x1E, 0x38, 0x07, 0x3C, 0x03, 0x3E, 0x03, 0x37, 0x83, 0x33, 0xC3, 0x31, 0xE3, 0x30, 0x77, 0x30, 0x3E, 0x30, 0x1C, 0x30, // "2"
        0x00, 0x00, 0x0C, 0x0C, 0x0E, 0x1C, 0x07, 0x38, 0xC3, 0x30, 0xC3, 0x30, 0xC3, 0x30, 0xC3, 0x30, 0xC3, 0x30, 0xE7, 0x39, 0x7E, 0x1F, 0x3C, 0x0E, // "3"
        0x00, 0x00, 0xC0, 0x03, 0xE0, 0x03, 0x70, 0x03, 0x38, 0x03, 0x1C, 0x03, 0x0E, 0x03, 0x07, 0x03, 0xFF, 0x3F, 0xFF, 0x3F, 0x00, 0x03, 0x00, 0x03, // "4"
        0x00, 0x00, 0x3F, 0x0C, 0x7F, 0x1C, 0x63, 0x38, 0x63, 0x30, 0x63, 0x30, 0x63, 0x30, 0x63, 0x30, 0x63, 0x30, 0xE3, 0x38, 0xC3, 0x1F, 0x83, 0x0F, // "5"
        0x00, 0x00, 0xC0, 0x0F, 0xF0, 0x1F, 0xF8, 0x39, 0xDC, 0x30, 0xCE, 0x30, 0xC7, 0x30, 0xC3, 0x30, 0xC3, 0x30, 0xC3, 0x39, 0x80, 0x1F, 0x00, 0x0F, // "6"
        0x00, 0x00, 0x03, 0x00, 0x03, 0x00, 0x03, 0x00, 0x03, 0x30, 0x03, 0x3C, 0x03, 0x0F, 0xC3, 0x03, 0xF3, 0x00, 0x3F, 0x00, 0x0F, 0x00, 0x03, 0x00, // "7"
        0x00, 0x00, 0x00, 0x0F, 0xBC, 0x1F, 0xFE, 0x39, 0xE7, 0x30, 0xC3, 0x30, 0xC3, 0x30, 0xC3, 0x30, 0xE7, 0x30, 0xFE, 0x39, 0xBC, 0x1F, 0x00, 0x0F, // "8"
        0x00, 0x00, 0x3C, 0x00, 0x7E, 0x00, 0xE7, 0x30, 0xC3, 0x30, 0xC3, 0x30, 0xC3, 0x38, 0xC3, 0x1C, 0xC3, 0x0E, 0xE7, 0x07, 0xFE, 0x03, 0xFC, 0x00, // "9"
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x70, 0x1C, 0x70, 0x1C, 0x70, 0x1C, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, // ":"
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x70, 0x9C, 0x70, 0xFC, 0x70, 0x7C, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, // ";"
        0x00, 0x00, 0x00, 0x00, 0xC0, 0x00, 0xE0, 0x01, 0xF0, 0x03, 0x38, 0x07, 0x1C, 0x0E, 0x0E, 0x1C, 0x07, 0x38, 0x03, 0x30, 0x00, 0x00, 0x00, 0x00, // "<"
        0x00, 0x00, 0x00, 0x00, 0x60, 0x06, 0x60, 0x06, 0x60, 0x06, 0x60, 0x06, 0x60, 0x06, 0x60, 0x06, 0x60, 0x06, 0x60, 0x06, 0x60, 0x06, 0x00, 0x00, // "="
        0x00, 0x00, 0x00, 0x00, 0x03, 0x30, 0x07, 0x38, 0x0E, 0x1C, 0x1C, 0x0E, 0x38, 0x07, 0xF0, 0x03, 0xE0, 0x01, 0xC0, 0x00, 0x00, 0x00, 0x00, 0x00, // ">"
        0x00, 0x00, 0x1C, 0x00, 0x1E, 0x00, 0x07, 0x00, 0x03, 0x00, 0x83, 0x37, 0xC3, 0x37, 0xE3, 0x00, 0x77, 0x00, 0x3E, 0x00, 0x1C, 0x00, 0x00, 0x00, // "?"
        0x00, 0x00, 0xF8, 0x07, 0xFE, 0x1F, 0x07, 0x18, 0xF3, 0x33, 0xFB, 0x37, 0x1B, 0x36, 0xFB, 0x37, 0xFB, 0x37, 0x07, 0x36, 0xFE, 0x03, 0xF8, 0x01, // "@"
        0x00, 0x00, 0x00, 0x38, 0x00, 0x3F, 0xE0, 0x07, 0xFC, 0x06, 0x1F, 0x06, 0x1F, 0x06, 0xFC, 0x06, 0xE0, 0x07, 0x00, 0x3F, 0x00, 0x38, 0x00, 0x00, // "A"
        0x00, 0x00, 0xFF, 0x3F, 0xFF, 0x3F, 0xC3, 0x30, 0xC3, 0x30, 0xC3, 0x30, 0xC3, 0x30, 0xE7, 0x30, 0xFE, 0x39, 0xBC, 0x1F, 0x00, 0x0F, 0x00, 0x00, // "B"
        0x00, 0x00, 0xF0, 0x03, 0xFC, 0x0F, 0x0E, 0x1C, 0x07, 0x38, 0x03, 0x30, 0x03, 0x30, 0x03, 0x30, 0x07, 0x38, 0x0E, 0x1C, 0x0C, 0x0C, 0x00, 0x00, // "C"
        0x00, 0x00, 0xFF, 0x3F, 0xFF, 0x3F, 0x03, 0x30, 0x03, 0x30, 0x03, 0x30, 0x03, 0x30, 0x07, 0x38, 0x0E, 0x1C, 0xFC, 0x0F, 0xF0, 0x03, 0x00, 0x00, // "D"
        0x00, 0x00, 0xFF, 0x3F, 0xFF, 0x3F, 0xC3, 0x30, 0xC3, 0x30, 0xC3, 0x30, 0xC3, 0x30, 0xC3, 0x30, 0xC3, 0x30, 0x03, 0x30, 0x03, 0x30, 0x00, 0x00, // "E"
        0x00, 0x00, 0xFF, 0x3F, 0xFF, 0x3F, 0xC3, 0x00, 0xC3, 0x00, 0xC3, 0x00, 0xC3, 0x00, 0xC3, 0x00, 0xC3, 0x00, 0x03, 0x00, 0x03, 0x00, 0x00, 0x00, // "F"
        0x00, 0x00, 0xF0, 0x03, 0xFC, 0x0F, 0x0E, 0x1C, 0x07, 0x38, 0x03, 0x30, 0xC3, 0x30, 0xC3, 0x30, 0xC3, 0x30, 0xC7, 0x3F, 0xC6, 0x3F, 0x00, 0x00, // "G"
        0x00, 0x00, 0xFF, 0x3F, 0xFF, 0x3F, 0xC0, 0x00, 0xC0, 0x00, 0xC0, 0x00, 0xC0, 0x00, 0xC0, 0x00, 0xC0, 0x00, 0xFF, 0x3F, 0xFF, 0x3F, 0x00, 0x00, // "H"
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x03, 0x30, 0x03, 0x30, 0xFF, 0x3F, 0xFF, 0x3F, 0x03, 0x30, 0x03, 0x30, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, // "I"
        0x00, 0x00, 0x00, 0x0E, 0x00, 0x1E, 0x00, 0x38, 0x00, 0x30, 0x00, 0x30, 0x00, 0x30, 0x00, 0x30, 0x00, 0x38, 0xFF, 0x1F, 0xFF, 0x07, 0x00, 0x00, // "J"
        0x00, 0x00, 0xFF, 0x3F, 0xFF, 0x3F, 0xC0, 0x00, 0xE0, 0x01, 0xF0, 0x03, 0x38, 0x07, 0x1C, 0x0E, 0x0E, 0x1C, 0x07, 0x38, 0x03, 0x30, 0x00, 0x00, // "K"
        0x00, 0x00, 0xFF, 0x3F, 0xFF, 0x3F, 0x00, 0x30, 0x00, 0x30, 0x00, 0x30, 0x00, 0x30, 0x00, 0x30, 0x00, 0x30, 0x00, 0x30, 0x00, 0x30, 0x00, 0x00, // "L"
        0x00, 0x00, 0xFF, 0x3F, 0xFF, 0x3F, 0x1E, 0x00, 0x78, 0x00, 0xE0, 0x01, 0xE0, 0x01, 0x78, 0x00, 0x1E, 0x00, 0xFF, 0x3F, 0xFF, 0x3F, 0x00, 0x00, // "M"
        0x00, 0x00, 0xFF, 0x3F, 0xFF, 0x3F, 0x0E, 0x00, 0x38, 0x00, 0xF0, 0x00, 0xC0, 0x03, 0x00, 0x07, 0x00, 0x1C, 0xFF, 0x3F, 0xFF, 0x3F, 0x00, 0x00, // "N"
        0x00, 0x00, 0xF0, 0x03, 0xFC, 0x0F, 0x0E, 0x1C, 0x07, 0x38, 0x03, 0x30, 0x03, 0x30, 0x07, 0x38, 0x0E, 0x1C, 0xFC, 0x0F, 0xF0, 0x03, 0x00, 0x00, // "O"
        0x00, 0x00, 0xFF, 0x3F, 0xFF, 0x3F, 0x83, 0x01, 0x83, 0x01, 0x83, 0x01, 0x83, 0x01, 0x83, 0x01, 0xC7, 0x01, 0xFE, 0x00, 0x7C, 0x00, 0x00, 0x00, // "P"
        0x00, 0x00, 0xF0, 0x03, 0xFC, 0x0F, 0x0E, 0x1C, 0x07, 0x38, 0x03, 0x30, 0x03, 0x36, 0x07, 0x3E, 0x0E, 0x1C, 0xFC, 0x3F, 0xF0, 0x33, 0x00, 0x00, // "Q"
        0x00, 0x00, 0xFF, 0x3F, 0xFF, 0x3F, 0x83, 0x01, 0x83, 0x01, 0x83, 0x03, 0x83, 0x07, 0x83, 0x0F, 0xC7, 0x1D, 0xFE, 0x38, 0x7C, 0x30, 0x00, 0x00, // "R"
        0x00, 0x00, 0x3C, 0x0C, 0x7E, 0x1C, 0xE7, 0x38, 0xC3, 0x30, 0xC3, 0x30, 0xC3, 0x30, 0xC3, 0x30, 0xC7, 0x39, 0x8E, 0x1F, 0x0C, 0x0F, 0x00, 0x00, // "S"
        0x00, 0x00, 0x00, 0x00, 0x03, 0x00, 0x03, 0x00, 0x03, 0x00, 0xFF, 0x3F, 0xFF, 0x3F, 0x03, 0x00, 0x03, 0x00, 0x03, 0x00, 0x00, 0x00, 0x00, 0x00, // "T"
        0x00, 0x00, 0xFF, 0x07, 0xFF, 0x1F, 0x00, 0x38, 0x00, 0x30, 0x00, 0x30, 0x00, 0x30, 0x00, 0x30, 0x00, 0x38, 0xFF, 0x1F, 0xFF, 0x07, 0x00, 0x00, // "U"
        0x00, 0x00, 0x07, 0x00, 0x3F, 0x00, 0xF8, 0x01, 0xC0, 0x0F, 0x00, 0x3E, 0x00, 0x3E, 0xC0, 0x0F, 0xF8, 0x01, 0x3F, 0x00, 0x07, 0x00, 0x00, 0x00, // "V"
        0x00, 0x00, 0xFF, 0x3F, 0xFF, 0x3F, 0x00, 0x1C, 0x00, 0x06, 0x80, 0x03, 0x80, 0x03, 0x00, 0x06, 0x00, 0x1C, 0xFF, 0x3F, 0xFF, 0x3F, 0x00, 0x00, // "W"
        0x00, 0x00, 0x03, 0x30, 0x0F, 0x3C, 0x1C, 0x0E, 0x30, 0x03, 0xE0, 0x01, 0xE0, 0x01, 0x30, 0x03, 0x1C, 0x0E, 0x0F, 0x3C, 0x03, 0x30, 0x00, 0x00, // "X"
        0x00, 0x00, 0x03, 0x00, 0x0F, 0x00, 0x3C, 0x00, 0xF0, 0x00, 0xC0, 0x3F, 0xC0, 0x3F, 0xF0, 0x00, 0x3C, 0x00, 0x0F, 0x00, 0x03, 0x00, 0x00, 0x00, // "Y"
        0x00, 0x00, 0x03, 0x30, 0x03, 0x3C, 0x03, 0x3E, 0x03, 0x33, 0xC3, 0x31, 0xE3, 0x30, 0x33, 0x30, 0x1F, 0x30, 0x0F, 0x30, 0x03, 0x30, 0x00, 0x00, // "Z"
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xFF, 0x3F, 0xFF, 0x3F, 0x03, 0x30, 0x03, 0x30, 0x03, 0x30, 0x03, 0x30, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, // "["
        0x00, 0x00, 0x0E, 0x00, 0x1C, 0x00, 0x38, 0x00, 0x70, 0x00, 0xE0, 0x00, 0xC0, 0x01, 0x80, 0x03, 0x00, 0x07, 0x00, 0x0E, 0x00, 0x1C, 0x00, 0x18, // "\"
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x03, 0x30, 0x03, 0x30, 0x03, 0x30, 0x03, 0x30, 0xFF, 0x3F, 0xFF, 0x3F, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, // "]"
        0x00, 0x00, 0x60, 0x00, 0x70, 0x00, 0x38, 0x00, 0x1C, 0x00, 0x0E, 0x00, 0x07, 0x00, 0x0E, 0x00, 0x1C, 0x00, 0x38, 0x00, 0x70, 0x00, 0x60, 0x00, // "^"
        0x00, 0x00, 0x00, 0xC0, 0x00, 0xC0, 0x00, 0xC0, 0x00, 0xC0, 0x00, 0xC0, 0x00, 0xC0, 0x00, 0xC0, 0x00, 0xC0, 0x00, 0xC0, 0x00, 0xC0, 0x00, 0xC0, // "_"
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x3E, 0x00, 0x7E, 0x00, 0x4E, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, // "`"
        0x00, 0x00, 0x00, 0x1C, 0x40, 0x3E, 0x60, 0x33, 0x60, 0x33, 0x60, 0x33, 0x60, 0x33, 0x60, 0x33, 0x60, 0x33, 0xE0, 0x3F, 0xC0, 0x3F, 0x00, 0x00, // "a"
        0x00, 0x00, 0xFF, 0x7F, 0xFF, 0x7F, 0x80, 0x61, 0xC0, 0x60, 0xC0, 0x60, 0xC0, 0x60, 0xC0, 0x60, 0xC0, 0x71, 0x80, 0x3F, 0x00, 0x1F, 0x00, 0x00, // "b"
        0x00, 0x00, 0x80, 0x0F, 0xC0, 0x1F, 0xE0, 0x38, 0x60, 0x30, 0x60, 0x30, 0x60, 0x30, 0x60, 0x30, 0x60, 0x30, 0xC0, 0x18, 0x80, 0x08, 0x00, 0x00, // "c"
        0x00, 0x00, 0x80, 0x0F, 0xC0, 0x1F, 0xE0, 0x38, 0x60, 0x30, 0x60, 0x30, 0x60, 0x30, 0xE0, 0x30, 0xC0, 0x30, 0xFF, 0x3F, 0xFF, 0x3F, 0x00, 0x00, // "d"
        0x00, 0x00, 0x80, 0x0F, 0xC0, 0x1F, 0xE0, 0x3B, 0x60, 0x33, 0x60, 0x33, 0x60, 0x33, 0x60, 0x33, 0x60, 0x33, 0xC0, 0x13, 0x80, 0x01, 0x00, 0x00, // "e"
        0x00, 0x00, 0xC0, 0x00, 0xC0, 0x00, 0xFC, 0x3F, 0xFE, 0x3F, 0xC7, 0x00, 0xC3, 0x00, 0xC3, 0x00, 0x03, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, // "f"
        0x00, 0x00, 0x80, 0x03, 0xC0, 0xC7, 0xE0, 0xCE, 0x60, 0xCC, 0x60, 0xCC, 0x60, 0xCC, 0x60, 0xCC, 0x60, 0xE6, 0xE0, 0x7F, 0xE0, 0x3F, 0x00, 0x00, // "g"
        0x00, 0x00, 0xFF, 0x3F, 0xFF, 0x3F, 0x80, 0x01, 0xC0, 0x00, 0xC0, 0x00, 0xC0, 0x00, 0xC0, 0x01, 0x80, 0x3F, 0x00, 0x3F, 0x00, 0x00, 0x00, 0x00, // "h"
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x30, 0x60, 0x30, 0xEC, 0x3F, 0xEC, 0x3F, 0x00, 0x30, 0x00, 0x30, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, // "i"
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x60, 0x00, 0xE0, 0x00, 0xC0, 0x60, 0xC0, 0xEC, 0xFF, 0xEC, 0x7F, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, // "j"
        0x00, 0x00, 0x00, 0x00, 0xFF, 0x3F, 0xFF, 0x3F, 0x00, 0x03, 0x80, 0x07, 0xC0, 0x0F, 0xE0, 0x1C, 0x70, 0x38, 0x30, 0x30, 0x00, 0x00, 0x00, 0x00, // "k"
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x30, 0x03, 0x30, 0xFF, 0x3F, 0xFF, 0x3F, 0x00, 0x30, 0x00, 0x30, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, // "l"
        0x00, 0x00, 0xE0, 0x3F, 0xC0, 0x3F, 0xE0, 0x00, 0xE0, 0x00, 0xC0, 0x3F, 0xC0, 0x3F, 0xE0, 0x00, 0xE0, 0x00, 0xC0, 0x3F, 0x80, 0x3F, 0x00, 0x00, // "m"
        0x00, 0x00, 0x00, 0x00, 0xE0, 0x3F, 0xE0, 0x3F, 0x60, 0x00, 0x60, 0x00, 0x60, 0x00, 0x60, 0x00, 0xE0, 0x00, 0xC0, 0x3F, 0x80, 0x3F, 0x00, 0x00, // "n"
        0x00, 0x00, 0x80, 0x0F, 0xC0, 0x1F, 0xE0, 0x38, 0x60, 0x30, 0x60, 0x30, 0x60, 0x30, 0x60, 0x30, 0xE0, 0x38, 0xC0, 0x1F, 0x80, 0x0F, 0x00, 0x00, // "o"
        0x00, 0x00, 0xE0, 0xFF, 0xE0, 0xFF, 0x60, 0x0C, 0x60, 0x18, 0x60, 0x18, 0x60, 0x18, 0x60, 0x18, 0xE0, 0x1C, 0xC0, 0x0F, 0x80, 0x07, 0x00, 0x00, // "p"
        0x00, 0x00, 0x80, 0x07, 0xC0, 0x0F, 0xE0, 0x1C, 0x60, 0x18, 0x60, 0x18, 0x60, 0x18, 0x60, 0x18, 0x60, 0x0C, 0xE0, 0xFF, 0xE0, 0xFF, 0x00, 0x00, // "q"
        0x00, 0x00, 0x00, 0x00, 0xE0, 0x3F, 0xE0, 0x3F, 0xC0, 0x00, 0x60, 0x00, 0x60, 0x00, 0x60, 0x00, 0x60, 0x00, 0xE0, 0x00, 0xC0, 0x00, 0x00, 0x00, // "r"
        0x00, 0x00, 0xC0, 0x11, 0xE0, 0x33, 0x60, 0x33, 0x60, 0x33, 0x60, 0x33, 0x60, 0x33, 0x60, 0x3F, 0x40, 0x1E, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, // "s"
        0x00, 0x00, 0x60, 0x00, 0x60, 0x00, 0xFE, 0x1F, 0xFE, 0x3F, 0x60, 0x30, 0x60, 0x30, 0x60, 0x30, 0x00, 0x30, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, // "t"
        0x00, 0x00, 0xE0, 0x0F, 0xE0, 0x1F, 0x00, 0x38, 0x00, 0x30, 0x00, 0x30, 0x00, 0x30, 0x00, 0x30, 0x00, 0x18, 0xE0, 0x3F, 0xE0, 0x3F, 0x00, 0x00, // "u"
        0x00, 0x00, 0x60, 0x00, 0xE0, 0x01, 0x80, 0x07, 0x00, 0x1E, 0x00, 0x38, 0x00, 0x38, 0x00, 0x1E, 0x80, 0x07, 0xE0, 0x01, 0x60, 0x00, 0x00, 0x00, // "v"
        0x00, 0x00, 0xE0, 0x07, 0xE0, 0x1F, 0x00, 0x38, 0x00, 0x1C, 0xE0, 0x0F, 0xE0, 0x0F, 0x00, 0x1C, 0x00, 0x38, 0xE0, 0x1F, 0xE0, 0x07, 0x00, 0x00, // "w"
        0x00, 0x00, 0x60, 0x30, 0xE0, 0x38, 0xC0, 0x1D, 0x80, 0x0F, 0x00, 0x07, 0x80, 0x0F, 0xC0, 0x1D, 0xE0, 0x38, 0x60, 0x30, 0x00, 0x00, 0x00, 0x00, // "x"
        0x00, 0x00, 0x00, 0x00, 0x60, 0x00, 0xE0, 0x81, 0x80, 0xE7, 0x00, 0x7E, 0x00, 0x1E, 0x80, 0x07, 0xE0, 0x01, 0x60, 0x00, 0x00, 0x00, 0x00, 0x00, // "y"
        0x00, 0x00, 0x60, 0x30, 0x60, 0x38, 0x60, 0x3C, 0x60, 0x36, 0x60, 0x33, 0xE0, 0x31, 0xE0, 0x30, 0x60, 0x30, 0x20, 0x30, 0x00, 0x00, 0x00, 0x00, // "z"
        0x00, 0x00, 0x00, 0x00, 0x80, 0x00, 0xC0, 0x01, 0xFC, 0x1F, 0x7E, 0x3F, 0x07, 0x70, 0x03, 0x60, 0x03, 0x60, 0x03, 0x60, 0x00, 0x00, 0x00, 0x00, // "{"
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xFF, 0x3F, 0xFF, 0x3F, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, // "|"
        0x00, 0x00, 0x00, 0x00, 0x03, 0x60, 0x03, 0x60, 0x03, 0x60, 0x07, 0x70, 0x7E, 0x3F, 0xFC, 0x1F, 0xC0, 0x01, 0x80, 0x00, 0x00, 0x00, 0x00, 0x00, // "}"
        0x00, 0x00, 0x10, 0x00, 0x18, 0x00, 0x0C, 0x00, 0x04, 0x00, 0x0C, 0x00, 0x18, 0x00, 0x10, 0x00, 0x18, 0x00, 0x0C, 0x00, 0x04, 0x00, 0x00, 0x00, // "~"
        0x00, 0x00, 0x00, 0x0F, 0x80, 0x0F, 0xC0, 0x0C, 0x60, 0x0C, 0x30, 0x0C, 0x30, 0x0C, 0x60, 0x0C, 0xC0, 0x0C, 0x80, 0x0F, 0x00, 0x0F, 0x00, 0x00  // "ein Haus :)"
};

#endif
