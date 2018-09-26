/* Terminal colors (16 first used in escape sequence) */
static const char *colorname[] = {

    "#0A211B",
    "#B14355",
    "#E16026",
    "#878F56",
    "#79A165",
    "#FD943A",
    "#FCB030",
    "#EFE297",

    "#0C3139",
    "#1B5128",
    "#493C24",
    "#264C3D",
    "#5E3735",
    "#167B66",
    "#954628",
    "#4F7B5C",

    [255] = 0,
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
