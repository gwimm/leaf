/* Terminal colors (16 first used in escape sequence) */
static const char *colorname[] = {

    "#010204",
    "#1A1C3D",
    "#3D1A1C",
    "#1A2E3D",
    "#10171F",
    "#953238",
    "#8F3295",
    "#BC74D2",

    "#8AD274",
    "#D2748A",
    "#8D74D2",
    "#D28D74",
    "#74D28D",
    "#74B9D2",
    "#D274B9",
    "#748AD2",

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
