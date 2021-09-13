#ifndef _7X8_CHARS
#define _7X8_CHARS


    // A - Z
	#define _TILE_A { 0x08, 0x1C, 0x22, 0x22, 0x3E, 0x22, 0x22, 0x00 }
	#define _TILE_B { 0x3C, 0x12, 0x12, 0x1C, 0x12, 0x12, 0x3C, 0x00 }
	#define _TILE_C { 0x1C, 0x22, 0x20, 0x20, 0x20, 0x22, 0x1C, 0x00 }
	#define _TILE_D { 0x38, 0x24, 0x22, 0x22, 0x22, 0x24, 0x38, 0x00 }
	#define _TILE_E { 0x3E, 0x20, 0x20, 0x3C, 0x20, 0x20, 0x3E, 0x00 }
	#define _TILE_F { 0x3E, 0x20, 0x20, 0x3C, 0x20, 0x20, 0x20, 0x00 }
	#define _TILE_G { 0x1C, 0x20, 0x20, 0x2E, 0x22, 0x22, 0x1C, 0x00 }
	#define _TILE_H { 0x22, 0x22, 0x22, 0x3E, 0x22, 0x22, 0x22, 0x00 }
	#define _TILE_I { 0x1C, 0x08, 0x08, 0x08, 0x08, 0x08, 0x1C, 0x00 }
	#define _TILE_J { 0x0E, 0x04, 0x04, 0x04, 0x04, 0x24, 0x18, 0x00 }
	#define _TILE_K { 0x22, 0x24, 0x28, 0x30, 0x28, 0x24, 0x22, 0x00 }
	#define _TILE_L { 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x3E, 0x00 }
	#define _TILE_M { 0x22, 0x36, 0x2A, 0x2A, 0x22, 0x22, 0x22, 0x00 }
	#define _TILE_N { 0x22, 0x22, 0x32, 0x2A, 0x26, 0x22, 0x22, 0x00 }
	#define _TILE_O { 0x1C, 0x22, 0x22, 0x22, 0x22, 0x22, 0x1C, 0x00 }
	#define _TILE_P { 0x3C, 0x22, 0x22, 0x3C, 0x20, 0x20, 0x20, 0x00 }
	#define _TILE_Q { 0x1C, 0x22, 0x22, 0x22, 0x2A, 0x24, 0x1A, 0x00 }
	#define _TILE_R { 0x3C, 0x22, 0x22, 0x3C, 0x28, 0x24, 0x22, 0x00 }
	#define _TILE_S { 0x1C, 0x22, 0x20, 0x1C, 0x02, 0x22, 0x1C, 0x00 }
	#define _TILE_T { 0x3E, 0x08, 0x08, 0x08, 0x08, 0x08, 0x08, 0x00 }
	#define _TILE_U { 0x22, 0x22, 0x22, 0x22, 0x22, 0x22, 0x1C, 0x00 }
	#define _TILE_V { 0x22, 0x22, 0x22, 0x14, 0x14, 0x08, 0x08, 0x00 }
	#define _TILE_W { 0x22, 0x22, 0x22, 0x2A, 0x2A, 0x36, 0x22, 0x00 }
	#define _TILE_X { 0x22, 0x22, 0x14, 0x08, 0x14, 0x22, 0x22, 0x00 }
	#define _TILE_Y { 0x22, 0x22, 0x14, 0x08, 0x08, 0x08, 0x08, 0x00 }
	#define _TILE_Z { 0x3E, 0x02, 0x04, 0x08, 0x10, 0x20, 0x3E, 0x00 }
    
    // 0 - 9
	#define _TILE_DIGIT_0 { 0x1C, 0x22, 0x26, 0x2A, 0x32, 0x22, 0x1C, 0x00 }
	#define _TILE_DIGIT_1 { 0x08, 0x18, 0x08, 0x08, 0x08, 0x08, 0x1C, 0x00 }
	#define _TILE_DIGIT_2 { 0x1C, 0x22, 0x22, 0x0C, 0x10, 0x20, 0x3E, 0x00 }
	#define _TILE_DIGIT_3 { 0x1C, 0x22, 0x02, 0x0C, 0x02, 0x22, 0x1C, 0x00 }
	#define _TILE_DIGIT_4 { 0x04, 0x0C, 0x14, 0x24, 0x3E, 0x04, 0x04, 0x00 }
	#define _TILE_DIGIT_5 { 0x3E, 0x30, 0x3C, 0x02, 0x02, 0x22, 0x1C, 0x00 }
	#define _TILE_DIGIT_6 { 0x0C, 0x10, 0x20, 0x3C, 0x22, 0x22, 0x1C, 0x00 }
	#define _TILE_DIGIT_7 { 0x3E, 0x02, 0x04, 0x08, 0x10, 0x10, 0x10, 0x00 }
	#define _TILE_DIGIT_8 { 0x1C, 0x22, 0x22, 0x1C, 0x22, 0x22, 0x1C, 0x00 }
	#define _TILE_DIGIT_9 { 0x1C, 0x22, 0x22, 0x1E, 0x02, 0x04, 0x08, 0x00 }



	#define _TILE_0_UDG     {12,18,12,51,45,12,18,18}
	#define _TILE_1_UDG     {0,0,12,18,12,51,45,12}
	#define _TILE_2_UDG     {18,18,0,0,0,0,0,0}
	#define _TILE_3_UDG     {0,0,0,0,12,18,12,51}

	#define _TILE_4_UDG     {45,12,18,18,0,0,0,0}
	#define _TILE_7_UDG     {12,18,12,0,45,0,18,18}
	#define _TILE_9_UDG     {2,7,2,15,18,42,39,37}
	#define _TILE_8_UDG     {0,12,18,33,33,18,12,0}
	#define _TILE_11_UDG    {0,0,0,1,2,5,4,4}
	#define _TILE_5_UDG     {0,0,0,0,0,0,12,18}

	#define _TILE_6_UDG     {12,51,45,12,18,18,0,0}
	
	#define _TILE_16_UDG    {0,0,0,60,2,5,57,1}
	#define _TILE_14_UDG    {0,42,42,58,42,42,0,0}
	#define _TILE_15_UDG    {0,37,37,37,37,50,0,0}
	#define _TILE_10_UDG    {0,0,0,32,16,40,8,8}
	#define _TILE_12_UDG    {16,56,16,60,18,21,57,41}
	#define _TILE_13_UDG    {0,0,0,15,16,40,39,32}
	#define _TILE_17_UDG    {2,7,2,2,2,2,2,5}
	#define _TILE_18_UDG    {16,56,16,16,16,16,16,40}

	#define _TILE_19_UDG    {45,18,12,51,45,12,18,18}
	#define _TILE_20_UDG    {0,0,45,18,12,51,45,12}
	#define _TILE_21_UDG    {0,0,0,0,45,18,12,51}
	#define _TILE_22_UDG    {0,0,0,0,0,0,45,18}
	#define _TILE_23_UDG    {0,4,21,14,27,14,21,4}
	#define _TILE_24_UDG    {63,41,63,37,63,41,63,37}
	#define _TILE_25_UDG    {0xff,0x3e,0x60,0x3c,0x06,0x7c,0x18,0xff}
#endif // _7x8_CHARS