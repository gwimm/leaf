#include <stdint.h>
#include <sys/types.h>

#define HISTSIZE      2000

/* macros */
#define MIN(a, b)           ((a) < (b) ? (a) : (b))
#define MAX(a, b)           ((a) < (b) ? (b) : (a))
#define LEN(a)              (sizeof(a) / sizeof(a)[0])
#define BETWEEN(x, a, b)    ((a) <= (x) && (x) <= (b))
#define DIVCEIL(n, d)       (((n) + ((d) - 1)) / (d))
#define DEFAULT(a, b)       (a) = (a) ? (a) : (b)
#define LIMIT(x, a, b)      (x) = (x) < (a) ? (a) : (x) > (b) ? (b) : (x)
#define ATTRCMP(a, b)       ((a).mode != (b).mode || (a).fg != (b).fg \
                                                        || (a).bg != (b).bg)

#define TIMEDIFF(t1, t2)    ((t1.tv_sec-t2.tv_sec)*1000 + \
                            (t1.tv_nsec-t2.tv_nsec)/1E6)
#define MODBIT(x, set, bit) ((set) ? ((x) |= (bit)) : ((x) &= ~(bit)))

#define TRUECOLOR(r,g,b)    (1 << 24 | (r) << 16 | (g) << 8 | (b))
#define IS_TRUECOL(x)       (1 << 24 & (x))
#define TLINE(y)       ((y) < term.scr ? term.hist[((y) + term.histi - term.scr \
               + HISTSIZE + 1) % HISTSIZE] : term.line[(y) - term.scr])

enum glyph_attribute {
    ATTR_NULL       = 0,
    ATTR_BOLD       = 1 << 0,
    ATTR_FAINT      = 1 << 1,
    ATTR_ITALIC     = 1 << 2,
    ATTR_UNDERLINE  = 1 << 3,
    ATTR_BLINK      = 1 << 4,
    ATTR_REVERSE    = 1 << 5,
    ATTR_INVISIBLE  = 1 << 6,
    ATTR_STRUCK     = 1 << 7,
    ATTR_WRAP       = 1 << 8,
    ATTR_WIDE       = 1 << 9,
    ATTR_WDUMMY     = 1 << 10,
    ATTR_BOLD_FAINT = ATTR_BOLD | ATTR_FAINT,
};

enum selection_mode {
    SEL_IDLE = 0,
    SEL_EMPTY = 1,
    SEL_READY = 2
};

enum selection_type {
    SEL_REGULAR = 1,
    SEL_RECTANGULAR = 2
};

enum selection_snap {
    SNAP_WORD = 1,
    SNAP_LINE = 2
};

typedef unsigned char uchar;
typedef unsigned int uint;
typedef unsigned long ulong;
typedef unsigned short ushort;

typedef uint_least32_t Rune;

#define Glyph Glyph_

typedef struct {
    Rune u;           /* character code */
    ushort mode;      /* attribute flags */
    uint32_t fg;      /* foreground  */
    uint32_t bg;      /* background  */
} Glyph;

typedef Glyph *Line;

typedef union {
    int i;
    uint ui;
    float f;
    const void *v;
} Arg;

enum win_mode {
    MODE_VISIBLE     = 1 << 0,
    MODE_FOCUSED     = 1 << 1,
    MODE_APPKEYPAD   = 1 << 2,
    MODE_MOUSEBTN    = 1 << 3,
    MODE_MOUSEMOTION = 1 << 4,
    MODE_REVERSE     = 1 << 5,
    MODE_KBDLOCK     = 1 << 6,
    MODE_HIDE        = 1 << 7,
    MODE_APPCURSOR   = 1 << 8,
    MODE_MOUSESGR    = 1 << 9,
    MODE_8BIT        = 1 << 10,
    MODE_BLINK       = 1 << 11,
    MODE_FBLINK      = 1 << 12,
    MODE_FOCUS       = 1 << 13,
    MODE_MOUSEX10    = 1 << 14,
    MODE_MOUSEMANY   = 1 << 15,
    MODE_BRCKTPASTE  = 1 << 16,
    MODE_NUMLOCK     = 1 << 17,
    MODE_MOUSE       = MODE_MOUSEBTN|MODE_MOUSEMOTION|MODE_MOUSEX10\
                       |MODE_MOUSEMANY,
};

void die(const char *, ...);
void redraw(void);
void draw(void);

void iso14755(const Arg *);
void printscreen(const Arg *);
void printsel(const Arg *);
void sendbreak(const Arg *);
void toggleprinter(const Arg *);

int tattrset(int);
void tnew(int, int);
void tresize(int, int);
void tsetdirtattr(int);
void ttyhangup(void);
int ttynew(char *, char *, char *, char **);
size_t ttyread(void);
void ttyresize(int, int);
void ttywrite(const char *, size_t, int);

void resettitle(void);

void selclear(void);
void selinit(void);
void selstart(int, int, int);
void selextend(int, int, int, int);
int selected(int, int);
char *getsel(void);

size_t utf8encode(Rune, char *);

void *xmalloc(size_t);
void *xrealloc(void *, size_t);
char *xstrdup(char *);

void kscrolldown(const Arg *);
void kscrollup(const Arg *);

void xbell(void);
void xclipcopy(void);
void xdrawcursor(int, int, Glyph, int, int, Glyph);
void xdrawline(Line, int, int, int);
void xfinishdraw(void);
void xloadcols(void);
int xsetcolorname(int, const char *);
void xsettitle(char *);
int xsetcursor(int);
void xsetmode(int, unsigned int);
void xsetpointermotion(int);
void xsetsel(char *);
int xstartdraw(void);

/* config.h globals */
extern char *utmp;
extern char *stty_args;
extern char *vtiden;
extern char *worddelimiters;
extern int allowaltscreen;
extern char *termname;
extern unsigned int tabspaces;
extern unsigned int defaultfg;
extern unsigned int defaultbg;
