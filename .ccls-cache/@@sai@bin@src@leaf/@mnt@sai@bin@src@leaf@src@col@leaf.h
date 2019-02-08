/* Terminal colors (16 first used in escape sequence) */
static const char *colorname[] = {

    "#101716",
    "#FEB453",
    "#4D7D68",
    "#87B08C",
    "#713326",
    "#4D7D68",
    "#B8422E",
    "#FE6355",

    "#82795B",
    "#305F48",
    "#F1F0D2",
    "#34251F",
    "#B7BE9A",
    "#124136",
    "#F1F0D2",
    "#FEFEFE",

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
