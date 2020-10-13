#ifndef __4864_H__
#define __4864_H__

#define PICTURE_INDEX_YES							0
#define PICTURE_INDEX_NO							1
#define PICTURE_INDEX_MAYBE							2
#define PICTURE_INDEX_SMILE							3
#define PICTURE_INDEX_NO_IDEA						4
#define PICTURE_INDEX_ASK_AGAIN						5
#define PICTURE_INDEX_ANSWER_YES					6
#define PICTURE_INDEX_8BALL_ICON					7
#define PICTURE_INDEX_3AXIS_DOWN					8
#define PICTURE_INDEX_3AXIS_UP						9
#define PICTURE_INDEX_3AXIS_RIGHT					10
#define PICTURE_INDEX_3AXIS_LEFT					11
#define PICTURE_INDEX_3AXIS_HORIZ					12
#define PICTURE_INDEX_FE_LOGO						13
#define PICTURE_INDEX_MC_LOGO						14
#define PICTURE_INDEX_EVK_LOGO						15
#define PICTURE_INDEX_TEMP_ICON						16
#define PICTURE_INDEX_TEMPERATURE					17

void initial_4864(void);
void show_temperature(uint8_t negative, uint8_t ten_digits, uint8_t digits, uint8_t decimal);
void show_picutre(uint8_t pic_index );
void refresh_picture_CF(uint8_t c_or_f );



#endif
