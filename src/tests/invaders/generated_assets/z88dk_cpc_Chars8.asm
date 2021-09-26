; ******************************************************
; **       Libreria de rutinas para Amstrad CPC       **
; **	   Raul Simarro, 	  Artaburu 2009       **
; ******************************************************

GLOBAL cpc_Chars8
GLOBAL first_char8

.first_char8 defb 32	;first defined char number (ASCII)

.cpc_Chars8   ;each bit of each byte is a pixel, same way as SYMBOL function of Locomotive BASIC.

;; KEY SET BY ANJUEL AND NA_TH_AN FROM NANAKO CPC GAME.
   DEFB     0,  0,  0,  0,  0,  0,  0,  0 ; (32)
   DEFB    1,3,3,31,63,63,63,63
   DEFB    0,128,128,240,248,248,248,248
   DEFB    0,0,0,7,15,15,15,15
   DEFB    64,224,224,252,254,254,254,254
   DEFB   64,224,224,252,254,254,254,254
   DEFB     2,9,11,14,15,7,2,4
   DEFB     128,0,128,192,224,160,160,0
   DEFB    0,7,15,14,15,3,6,3
   DEFB     37,37,37,37,37,37,50,0
   DEFB     255,255,255,192,129,255,255,255
   DEFB     32,17,63,110,255,191,160,27
   DEFB    1,3,7,13,15,2,5,10
   DEFB    8,18,250,238,254,252,8,4
   DEFB    66,66,90,126,60,60,60,24
   DEFB    15,127,255,230,255,25,54,192 ; TILE 12 (47)
   DEFB     0,224,240,112,240,128,192,48 ; TILE 13 (48)
   DEFB     $18,$3e,$60,$3c,$06,$7c,$18,$00 ; TILE 25 (49)
   ;DEFB    16, 62, 32, 60,  4,124,  8,  0 ; (49)
   DEFB   0,0,0,0,224,240,0,0 ; TILE 17 (50)
   DEFB   24,60,126,219,255,90,129,66 ; TILE 18 (51)
   DEFB   128,192,224,176,240,64,160,80; (52)
   DEFB    62, 32, 32, 62,  2, 34, 62,  0
   DEFB    62, 32, 32, 62, 34, 34, 62,  0
   DEFB    62, 36,  4,  4,  4,  4, 14,  0
   DEFB    62, 34, 34, 62, 34, 34, 62,  0
   DEFB    62, 34, 34, 62,  2, 34, 62,  0
   DEFB     0, 24, 24,  0,  0, 24, 24,  0
   DEFB     0, 24, 24,  0,  0, 24, 24, 32
   DEFB     4,  8, 16, 32, 16,  8,  4,  0
   DEFB     0,  0,126,  0,  0,126,  0,  0
   DEFB    32, 16,  8,  4,  8, 16, 32,  0
   DEFB    64,124, 68,  4, 28, 16,  0, 16
   DEFB     0, 56, 84, 92, 64, 60,  0,  0
   DEFB   126, 36, 36, 36, 60, 36,102,  0
   DEFB   124, 36, 36, 62, 34, 34,126,  0
   DEFB     2,126, 66, 64, 66,126,  2,  0
   DEFB   126, 34, 34, 34, 34, 34,126,  0
   DEFB     2,126, 66,120, 66,126,  2,  0
   DEFB     2,126, 34, 48, 32, 32,112,  0
   DEFB     2,126, 34, 32, 46, 36,124,  0
   DEFB   102, 36, 36, 60, 36, 36,102,  0
   DEFB    56, 16, 16, 16, 16, 16, 56,  0
   DEFB    28,  8,  8,  8,  8, 40, 56,  0
   DEFB   108, 40, 40,124, 36, 36,102,  0
   DEFB   112, 32, 32, 32, 34,126,  2,  0
   DEFB   127, 42, 42, 42, 42,107,  8,  0
   DEFB   126, 36, 36, 36, 36, 36,102,  0
   DEFB   126, 66, 66, 66, 66, 66,126,  0
   DEFB   126, 34, 34,126, 32, 32,112,  0
   DEFB   126, 66, 66, 74,126,  8, 28,  0
   DEFB   126, 34, 34,126, 36, 36,114,  0
   DEFB   126, 66, 64,126,  2, 66,126,  0
   DEFB    34, 62, 42,  8,  8,  8, 28,  0
   DEFB   102, 36, 36, 36, 36, 36,126,  0
   DEFB   102, 36, 36, 36, 36, 24,  0,  0
   DEFB   107, 42, 42, 42, 42, 42, 62,  0
   DEFB   102, 36, 36, 24, 36, 36,102,  0
   DEFB   102, 36, 36, 60,  8,  8, 28,  0
   DEFB   126, 66,  4,  8, 16, 34,126,  0
   DEFB     4, 60, 36, 32, 36, 60,  4,  0
   DEFB     0, 64, 32, 16,  8,  4,  0,  0
   DEFB    32, 60, 36,  4, 36, 60, 32,  0
   DEFB     0, 16, 40, 68,  0,  0,  0,  0
   DEFB     0,  0,  0,  0,  0,  0,  0,  0
   DEFB     0,100,104, 16, 44, 76,  0,  0
   DEFB   126, 36, 36, 36, 60, 36,102,  0
   DEFB   124, 36, 36, 62, 34, 34,126,  0
   DEFB     2,126, 66, 64, 66,126,  2,  0
   DEFB   126, 34, 34, 34, 34, 34,126,  0
   DEFB     2,126, 66,120, 66,126,  2,  0
   DEFB     2,126, 34, 48, 32, 32,112,  0
   DEFB     2,126, 34, 32, 46, 36,124,  0
   DEFB   102, 36, 36, 60, 36, 36,102,  0
   DEFB    56, 16, 16, 16, 16, 16, 56,  0
   DEFB    28,  8,  8,  8,  8, 40, 56,  0
   DEFB   108, 40, 40,124, 36, 36,102,  0
   DEFB   112, 32, 32, 32, 34,126,  2,  0
   DEFB   127, 42, 42, 42, 42,107,  8,  0
   DEFB   126, 36, 36, 36, 36, 36,102,  0
   DEFB   126, 66, 66, 66, 66, 66,126,  0
   DEFB   126, 34, 34,126, 32, 32,112,  0
   DEFB   126, 66, 66, 74,126,  8, 28,  0
   DEFB   126, 34, 34,126, 36, 36,114,  0
   DEFB   126, 66, 64,126,  2, 66,126,  0
   DEFB    34, 62, 42,  8,  8,  8, 28,  0
   DEFB   102, 36, 36, 36, 36, 36,126,  0
   DEFB   102, 36, 36, 36, 36, 24,  0,  0
   DEFB   107, 42, 42, 42, 42, 42, 62,  0
   DEFB   102, 36, 36, 24, 36, 36,102,  0
   DEFB   102, 36, 36, 60,  8,  8, 28,  0
   DEFB 0,0,0,1,3,3,3,3
   DEFB 16,56,56,255,255,255,255,255
   DEFB 0,0,0,0,128,128,128,128
   DEFB 4,14,14,127,255,255,255,255
   DEFB 0,0,0,192,224,224,224,224
   DEFB 240,254,255,103,255,156,102,12
