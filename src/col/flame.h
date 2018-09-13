/* Terminal colors (16 first used in escape sequence) */
static const char *colorname[] = {

    "#040405",
    "#5D1516",
    "#DB462C",
    "#DE5E31",
    "#F66835",
    "#FA943F",
    "#FEBE4B",
    "#FBC64D",

    "#B13124",
    "#86211C",
    "#380D11",
    "#040405",
    "#2E0B10",
    "#220011",
    "#771111",
    "#cc3322",

	[255] = 0,

	/* more colors can be added after 255 to use with DefaultXX */
};


/*
 * Default colors (colorname index)
 * foreground, background, cursor, reverse cursor
 */
unsigned int defaultfg = 15;
unsigned int defaultbg = 0;
static unsigned int defaultcs = 15;
static unsigned int defaultrcs = 0;

/*
 * Default shape of cursor
 * 2: Block ("█")
 * 4: Underline ("_")
 * 6: Bar ("|")
 * 7: Snowman ("☃")
 */
static unsigned int cursorshape = 2;

/*
 * Default columns and rows numbers
 */

static unsigned int cols = 80;
static unsigned int rows = 24;

/*
 * Default colour and shape of the mouse cursor
 */
static unsigned int mouseshape = XC_xterm;
static unsigned int mousefg = 7;
static unsigned int mousebg = 0;

/*
 * Color used to display font attributes when fontconfig selected a font which
 * doesn't match the ones requested.
 */
static unsigned int defaultattr = 11;
