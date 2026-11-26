//
// Copyright(C) 2023 by Ryan Krafnick
//
// This program is free software; you can redistribute it and/or
// modify it under the terms of the GNU General Public License
// as published by the Free Software Foundation; either version 2
// of the License, or (at your option) any later version.
//
// This program is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU General Public License for more details.
//
// DESCRIPTION:
//	DSDA Font
//

#include "lprintf.h"
#include "r_data.h"

#include "font.h"

static patchnum_t hu_font[HU_FONTSIZE];
static patchnum_t hu_font2[HU_FONTSIZE];

dsda_font_t hud_font;
dsda_font_t exhud_font;

void dsda_InitAllFonts(void) {
  char buffer[9];

  int i;
  int j;
  j = HU_FONTSTART;
  for (i = 0; i < HU_FONTSIZE; ++i, ++j) {
    if ('0' <= j && j <= '9') {
      if (raven)
        snprintf(buffer, sizeof(buffer), "FONTA%.2d", j - 32);
      else
        snprintf(buffer, sizeof(buffer), "STCFN%.3d", j);
      R_SetPatchNum(&hu_font[i], buffer);
    }
    else if ('A' <= j && j <= 'Z') {
      if (raven)
        snprintf(buffer, sizeof(buffer), "FONTA%.2d", j - 32);
      else
        snprintf(buffer, sizeof(buffer), "STCFN%.3d", j);
      R_SetPatchNum(&hu_font[i], buffer);
    }
    else if (!raven && j < 97) {
      snprintf(buffer, sizeof(buffer), "STCFN%.3d", j);
      R_SetPatchNum(&hu_font[i], buffer);
      //jff 2/23/98 make all font chars defined, useful or not
    }
    else if (raven && j < 91) {
      snprintf(buffer, sizeof(buffer), "FONTA%.2d", j - 32);
      R_SetPatchNum(&hu_font[i], buffer);
      //jff 2/23/98 make all font chars defined, useful or not
    }
    else {
      hu_font[i] = hu_font2[i]; //jff 2/16/98 account for gap
    }
  }

  hud_font.font = hu_font;
  hud_font.height = hu_font['0' - HU_FONTSTART].height;
  hud_font.line_height = hud_font.height + 1;
  hud_font.space_width = raven ? 5 : 4;
  hud_font.start = HU_FONTSTART;
  hud_font.kerning = raven ? -1 : 0;

  exhud_font = dsda_InitFont("DIG", 3);
}

dsda_font_t dsda_InitFont(const char *lump_match, int suffix_size) {
  dsda_font_t font;
  char buffer[9];
  int i;
  int j;

  char match_string[16];

  if (strlen(lump_match) + suffix_size > 8)
    return font;

  snprintf(match_string, sizeof(match_string), "%s%%.%dd", lump_match, suffix_size);
  lprintf(LO_ERROR, "match_string: %s\n", match_string);

  j = HU_FONTSTART;
  for (i = 0; i < HU_FONTSIZE - 1; i++, j++) {
    if ((!raven && j > 96) || (raven && j > 90))
      break;

    snprintf(buffer, sizeof(buffer), match_string, j);
    R_SetPatchNum(&hu_font2[i], buffer);
  }

  font.font = hu_font2;
  font.height = hu_font2['0' - HU_FONTSTART].height;
  font.line_height = font.height + 1;
  font.space_width = 5;
  font.start = HU_FONTSTART;
  font.kerning = 0;

  return font;
}
