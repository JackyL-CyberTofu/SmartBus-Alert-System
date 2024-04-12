#include "main.h"
#include <flite/flite.h>
#include <alsa/asoundlib.h>
#include <stdio.h>
#include "hal/useNFC.h"

#include <stdio.h>
#include <stdbool.h>
#include "displaylogic.h"
#include "alphabet.h"

// Assume pins already configured for SPI
// E.g. for SPI1, CS0:
// (bbg)$ config-pin P9_28 spi_cs
// (bbg)$ config-pin P9_31 spi_sclk
// (bbg)$ config-pin P9_29 spi
// (bbg)$ config-pin P9_30 spi
// P9_48 == D/C
// P9_60 == RST
#define SPI_DEV_BUS0_CS0 "/dev/spidev0.0"
#define SPI_DEV_BUS1_CS0 "/dev/spidev1.0"
#define SPI_DEV_BUS1_CS1 "/dev/spidev1.1"
#define SPI_MODE_DEFAULT 0
#define SPEED_HZ_DEFAULT 10000000 // Arbitrary, but 500000 is reasonable

#define MAX_BYTE_VALUE 255

#define Y_DISPLAY_MAX_LOW 0x00
#define Y_DISPLAY_MAX_HIGH 0xEF

#define X_DISPLAY_MAX_HIGH 0x01
#define X_DISPLAY_MAX_LOW 0x3F

#define Y_DISPLAY_DIMENSION 360
#define X_DISPLAY_DIMENSION 480

#define MAX_VAL_16_BITS 65535

#define FONT_SIZE_3_START_Y 3
#define FONT_SIZE_3_START_X 3
#define FONT_SIZE_3_INCREMENTOR 18

#define FONT_SIZE_2 2
#define FONT_SIZE_2_START_Y 25
#define FONT_SIZE_2_START_X 2
#define FONT_SIZE_2_Y_INCREMENTOR 20

#define SECOND_LINE_Y (FONT_SIZE_2_START_Y + (FONT_SIZE_2_Y_INCREMENTOR* 1))
#define THIRD_LINE_Y (FONT_SIZE_2_START_Y + (FONT_SIZE_2_Y_INCREMENTOR * 2))
#define FOURTH_LINE_Y (FONT_SIZE_2_START_Y + (FONT_SIZE_2_Y_INCREMENTOR * 3))
#define FIFTH_LINE_Y (FONT_SIZE_2_START_Y + (FONT_SIZE_2_Y_INCREMENTOR * 4))
#define SIXTH_LINE_Y (FONT_SIZE_2_START_Y + (FONT_SIZE_2_Y_INCREMENTOR * 5))
#define SEVENTH_LINE_Y (FONT_SIZE_2_START_Y + (FONT_SIZE_2_Y_INCREMENTOR * 6))
#define EIGHTH_LINE_Y (FONT_SIZE_2_START_Y + (FONT_SIZE_2_Y_INCREMENTOR * 7))


int main(int argc, char *argv[])
{
    srand(time(NULL));

    if (argc != 2){
        printf("No Argument Provided\n");
        return 1;
    }
//	int size;
//	char *calling = "https://api.translink.ca/rttiapi/v1/stops/55713/estimates?apikey=JoKWW8MHpsoc04lKVKnA&count=2";
//	transStruct_t *a = (transStruct_t *) ReadFromTransAPI(&size, calling);
//	freeTransStruct(size, a);


    // // ---------------------------- TTS ----------------------------

    // initialize_flite();
    // cst_voice *voice = setup_voice();

    // const char *text = "Bus fifty nine departing soon at stop one";
    // synthesize_text_to_file(text, voice, "play");

    // // ---------------------------- NFC ----------------------------

    init_nfc();
//    char inputString[] = "Santa";
    inititalize_JoyStick();
    startThreads(argv[1]);

    // For random
//    srand(time(NULL));
    printf("Before display init\n");
    displaylogic_init();
    printf("After display init\n");

    joinThreads();
    // Cleanup
    displaylogic_cleanup();
    printf("---------------------------------------------------\n");
    // shutdown_all_pins();
}

