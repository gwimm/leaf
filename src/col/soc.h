/* Terminal colors (16 first used in escape sequence) */
static const char *colorname[] = {

    "#010204",
    "#E14445",
    "#BD3C51",
    "#5F2E39",
    "#10171F",
    "#A56C4E",
    "#C4ECEB",
    "#FA6B28",

    "#62CB64",
    "#C46479",
    "#838BAD",
    "#FCA41D",
    "#CC9E77",
    "#CDC467",
    "#81C0BE",
    "#F8AEB9",
    "#E14445",
    "#FEFEFE",

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
