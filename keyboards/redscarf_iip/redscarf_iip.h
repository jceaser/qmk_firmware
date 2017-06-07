/* Copyright 2017 REPLACE_WITH_YOUR_NAME
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */
#ifndef REDSCARFF_IIP_H
#define REDSCARFF_IIP_H

#include "quantum.h"

// This a shortcut to help you visually see your layout.
// The following is an example using the Planck MIT layout
// The first section contains all of the arguments
// The second converts the arguments into a two-dimensional array
#define _KEYMAP( \
    k00, k01, k02, \
      k10,  k11   \
) \
{ \
    { k00, k01,   k02 }, \
    { k10, KC_NO, k11 }, \
}

#define XXX KC_NO

/* RedScarfII keymap definition macro
 * K3B and K2M are extra keys for ISO

#define MATRIX_ROW_PINS { B2, B1, B0}
#define MATRIX_COL_PINS { F4,F1,F0,B3,D0,D1,D4,D5,D6,D7,F7,F6,D2,D3,B6,B5,B4,F5 

*/
    /*
           f4  f1 f0 B3 D0 D1 D4 D5 D6 D7 F7 F6 D2 D3 B6 B5 B4 F5
    f1 f2  esc 1  2  3  4  5  6  7  8  9  0  -  +  bs hm x  x  x
    f3 f4  t   q  w  e  r  t  y  u  i  o  p  [  ]  \  pu 8  9  x
    f5 f6  cl  a  s  d  f  g  h  j  k  l  ;  '  i1 rt pd 5  6  x
    f7 f8  s   i2 z  x  c  v  b  n  m  .  ,  /  rs up ed 2  3  x
    f9 f10 c1  c2 c3                sp c4 c5 c6 lt dn rt x  x  x
               f1 f2 f3 f4 f5 f6 f7 f8 f9 f10
    */
    //          f4   f1   f0   B3   D0   D1   D4   D5   D6   D7   F7   F6   D2   D3   B6   B5   B4   F5
#define KEYMAP( \
    K5B, K5C,   K0A, K0B, K0C, K0D, K0E, K0F, K0G, K0H, K0I, K0J, K0K, K0L, K0M, K0N, K0P, K0Q, K0R, K0S, \
    K5D, K5E,   K1A, K1B, K1C, K1D, K1E, K1F, K1G, K1H, K1I, K1J, K1K, K1L, K1M, K1N, K1P, K1Q, K1R, K1S, \
    K5F, K5G,   K2A, K2B, K2C, K2D, K2E, K2F, K2G, K2H, K2I, K2J, K2K, K2L, K2M, K2N, K2P, K2Q, K2R, K2S, \
    K5H, K5I,   K3A, K3B, K3C, K3D, K3E, K3F, K3G, K3H, K3I, K3J, K3K, K3L, K3M, K3N, K3P, K3Q, K3R, K3S, \
    K5J, K5K,   K4A, K4B, K4C,           K4J,                K4K, K4L, K4H, K4M, K4N, K4P, K4Q, K4R, K4S  \
) { \
    {K5B, K5C,   K0A, K0B, K0C, K0D, K0E, K0F, K0G, K0H, K0I, K0J, K0K, K0L, K0M, K0N, K0P, NO, NO,  NO}, \
    {K5D, K5E,   K1A, K1B, K1C, K1D, K1E, K1F, K1G, K1H, K1I, K1J, K1K, K1L, K1M, K1N, K1P, NO, NO,  NO}, \
    {K5F, K5G,   K2A, K2B, K2C, K2D, K2E, K2F, K2G, K2H, K2I, K2J, K2K, K2L, K2M, K2N, K2P, NO, NO,  NO}, \
    {K5H, K5I,   K3A, K3B, K3C, K3D, K3E, K3F, K3G, K3H, K3I, K3J, K3K, K3L, K3M, K3N, K3P, NO, NO,  NO}, \
    {K5J, K5K,   K4A, K4B, K4C,           K4J,                K4K, K4L, K4H, K4M, K4N, K4P, NO, NO,  NO}  \
}

#endif
