/* original parser id follows */
/* yysccsid[] = "@(#)yaccpar	1.9 (Berkeley) 02/21/93" */
/* (use YYMAJOR/YYMINOR for ifdefs dependent on parser version) */

#define YYBYACC 1
#define YYMAJOR 1
#define YYMINOR 9
#define YYPATCH 20170430

#define YYEMPTY        (-1)
#define yyclearin      (yychar = YYEMPTY)
#define yyerrok        (yyerrflag = 0)
#define YYRECOVERING() (yyerrflag != 0)
#define YYENOMEM       (-2)
#define YYEOF          0
#define YYPREFIX "yy"

#define YYPURE 0

#line 17 "eqn.y"
#include "e.h"

int	yylex(void);
#line 25 "y.tab.c"

#if ! defined(YYSTYPE) && ! defined(YYSTYPE_IS_DECLARED)
/* Default: YYSTYPE is the semantic value type. */
typedef int YYSTYPE;
# define YYSTYPE_IS_DECLARED 1
#endif

/* compatibility with bison */
#ifdef YYPARSE_PARAM
/* compatibility with FreeBSD */
# ifdef YYPARSE_PARAM_TYPE
#  define YYPARSE_DECL() yyparse(YYPARSE_PARAM_TYPE YYPARSE_PARAM)
# else
#  define YYPARSE_DECL() yyparse(void *YYPARSE_PARAM)
# endif
#else
# define YYPARSE_DECL() yyparse(void)
#endif

/* Parameters sent to lex. */
#ifdef YYLEX_PARAM
# define YYLEX_DECL() yylex(void *YYLEX_PARAM)
# define YYLEX yylex(YYLEX_PARAM)
#else
# define YYLEX_DECL() yylex(void)
# define YYLEX yylex()
#endif

/* Parameters sent to yyerror. */
#ifndef YYERROR_DECL
#define YYERROR_DECL() yyerror(const char *s)
#endif
#ifndef YYERROR_CALL
#define YYERROR_CALL(msg) yyerror(msg)
#endif

extern int YYPARSE_DECL();

#define CONTIG 257
#define QTEXT 258
#define SPACE 259
#define THIN 260
#define TAB 261
#define MATRIX 262
#define LCOL 263
#define CCOL 264
#define RCOL 265
#define COL 266
#define ABOVE 267
#define MARK 268
#define LINEUP 269
#define SUM 270
#define INT 271
#define PROD 272
#define UNION 273
#define INTER 274
#define DEFINE 275
#define TDEFINE 276
#define NDEFINE 277
#define DELIM 278
#define GSIZE 279
#define GFONT 280
#define INCLUDE 281
#define IFDEF 282
#define DOTEQ 283
#define DOTEN 284
#define FROM 285
#define TO 286
#define OVER 287
#define SQRT 288
#define SUP 289
#define SUB 290
#define SIZE 291
#define FONT 292
#define ROMAN 293
#define ITALIC 294
#define BOLD 295
#define FAT 296
#define UP 297
#define DOWN 298
#define BACK 299
#define FWD 300
#define LEFT 301
#define RIGHT 302
#define DOT 303
#define DOTDOT 304
#define HAT 305
#define TILDE 306
#define BAR 307
#define LOWBAR 308
#define HIGHBAR 309
#define UNDER 310
#define VEC 311
#define DYAD 312
#define UTILDE 313
#define YYERRCODE 256
typedef int YYINT;
static const YYINT yylhs[] = {                           -1,
    0,    0,    0,    1,    1,    1,    1,    3,    4,    4,
    5,    5,    2,    2,    2,    2,    2,    2,    2,    2,
    2,    2,    2,    2,    2,    2,    2,    2,    8,    2,
    9,    2,   11,    2,   12,    2,    2,   13,    2,   14,
    2,    2,    2,    2,    2,    2,    2,    2,    2,   23,
    2,   10,   18,   19,   20,   21,   17,   17,   17,   17,
   17,   17,   17,   17,   17,   17,   17,   15,   15,   16,
   16,   24,   24,   22,   28,   22,   26,   26,   26,   26,
   27,   27,    6,    7,    7,    7,    7,   25,   25,
};
static const YYINT yylen[] = {                            2,
    1,    1,    0,    1,    2,    2,    1,    2,    2,    0,
    2,    0,    3,    1,    1,    1,    1,    1,    1,    1,
    1,    1,    3,    2,    2,    2,    2,    2,    0,    5,
    0,    4,    0,    5,    0,    4,    1,    0,    5,    0,
    4,    3,    2,    2,    2,    2,    2,    2,    1,    0,
    5,    1,    2,    2,    2,    2,    1,    1,    1,    1,
    1,    1,    1,    1,    1,    1,    1,    2,    2,    2,
    2,    1,    2,    4,    0,    6,    1,    1,    1,    1,
    1,    3,    2,    1,    1,    1,    2,    1,    1,
};
static const YYINT yydefred[] = {                         0,
    2,   15,   14,   16,   17,   18,   50,   77,   78,   79,
   80,    0,    7,   19,   52,   20,   21,   22,    0,    0,
    0,   84,   85,   86,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,   49,    0,    0,    0,    0,   88,   89,   83,
   87,    0,   54,   56,   55,   53,   69,   68,    0,    0,
    0,    6,   38,   40,    0,   31,   29,   64,   67,   57,
   65,   60,   61,   62,   63,   58,   59,   66,   44,    0,
    0,   35,   33,    0,    0,    0,    0,    0,    0,   75,
    0,   13,    0,    0,    0,    0,    0,    0,    0,    0,
    0,   42,    0,    0,    0,   72,    0,    0,    0,    0,
    0,    0,    0,   71,   70,    0,   74,    0,   51,   73,
    0,   39,    0,   30,   34,    0,    0,    0,    0,   76,
};
static const YYINT yydgoto[] = {                         32,
  103,   34,   62,  124,  122,   35,   36,   98,   97,   37,
  100,   99,   94,   95,   38,  102,   79,   39,   40,   41,
   42,   43,   45,  107,   50,   44,  104,  105,
};
static const YYINT yysindex[] = {                       -56,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0, 1423,    0,    0,    0,    0,    0,    0, 1423, -240,
 -240,    0,    0,    0, 1423, -240, -240, -240, -240, -121,
 1321,    0, 1367, -254, 1423, 1423, -265, 1321, 1423, 1423,
 1423, 1423,    0, -119, -116, -254, -229,    0,    0,    0,
    0,  -57,    0,    0,    0,    0,    0,    0, 1169, 1423,
 -254,    0,    0,    0, 1423,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,  -57,
  -57,    0,    0, -114,  -57,  -57,  -57,  -57, 1321,    0,
 -193,    0, -254, 1423, 1423, -229, 1423, 1423, 1423, 1423,
 -117,    0, 1367, -125, -108,    0,  -99, -195, -254, -229,
   36, -229,   36,    0,    0, 1321,    0, 1321,    0,    0,
 1423,    0, 1423,    0,    0, 1367, -106, -254, -229,    0,
};
static const YYINT yyrindex[] = {                        27,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,   30,  911,    0,    0,    1,    0,    0,    0,
    0,    0,    0,    0,    0,  967,  533,    0,    0,    0,
    0,  105,    0,    0,    0,    0,    0,    0,    0,    0,
 1017,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,  153,
  199,    0,    0,   48,  257,  381,  437,  483,    0,    0,
    0,    0, 1063,    0,    0,  589,    0,    0,    0,    0,
    0,    0, -105,    0,    0,    0,    0, 1119, 1215,  635,
  685,  787,  685,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0, -104,    0, 1271,  837,    0,
};
static const YYINT yygindex[] = {                         0,
    3,    4,    0,  -75,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,  -85,    0,    0,  -16,    0,  -76,    0,
};
#define YYTABLESIZE 1724
static const YYINT yytable[] = {                        117,
   37,   57,   33,   89,   51,  106,   91,  114,   31,   53,
   54,   55,   56,   58,  118,   46,   48,   49,  130,   81,
   82,  120,   47,   82,   83,  119,    3,   90,   52,    1,
   63,   64,   65,   59,   66,   67,   61,  125,   80,   81,
   84,  127,   85,   86,   87,   88,    0,   43,   68,   69,
   70,   71,   72,   73,   74,   75,   76,   77,   78,   66,
   67,    0,   61,   93,    0,    0,   31,    0,   96,    8,
    9,   10,   11,   68,   69,   70,   71,   72,   73,   74,
   75,   76,   77,   78,  115,    0,    0,   61,    0,   63,
  121,   65,    0,   66,   67,    0,    0,  108,  109,    0,
  110,  111,  112,  113,   27,    0,   61,   68,   69,   70,
   71,   72,   73,   74,   75,   76,   77,   78,  126,    0,
    0,    0,    0,   37,  128,   37,  129,    0,    0,   61,
    0,    0,    0,    0,    0,   48,   49,   48,   49,   48,
   49,  116,    2,    3,    4,    5,    6,    7,    8,    9,
   10,   11,   25,   12,   60,   14,   15,   16,   17,   18,
  116,   81,   82,    8,    9,   10,   11,    0,    0,    0,
    0,    0,   43,   19,    0,    0,   20,   21,   22,   23,
   24,   25,   26,   27,   28,   29,   30,  101,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,   26,    1,
    2,    3,    4,    5,    6,    7,    8,    9,   10,   11,
    0,   12,   13,   14,   15,   16,   17,   18,    0,    0,
    0,    0,    0,    0,    0,    0,    0,   27,    0,   27,
    0,   19,    0,    0,   20,   21,   22,   23,   24,   25,
   26,   27,   28,   29,   30,   68,   69,   70,   71,   72,
   73,   74,   75,   76,   77,   78,   45,   37,   37,   37,
   37,   37,   37,   37,   37,   37,   37,   37,   37,   37,
   37,   37,   37,   37,   37,   25,    0,   25,    0,    0,
    0,    0,    0,    0,    0,   37,   37,   37,   37,    0,
    0,   37,   37,   37,   37,   37,   37,   37,   37,   37,
   37,   37,   37,   37,   37,   37,   37,   37,   37,   37,
   37,   37,   37,   37,   43,    0,    0,    0,    0,    0,
    0,   26,    0,   26,  123,   67,    0,    0,    0,    0,
    0,    0,   43,   43,   43,    0,   43,   43,   68,   69,
   70,   71,   72,   73,   74,   75,   76,   77,   78,    0,
   43,   43,   43,   43,   43,   43,   43,   43,   43,   43,
   43,   27,   27,   27,   27,   27,   27,   27,   27,   27,
   27,   27,   27,   27,   27,   27,   27,   27,   27,   45,
   46,   45,    0,    0,    0,    0,    0,    0,    0,   27,
   27,   27,   27,   27,   27,   27,   27,   27,   27,   27,
   27,   27,   27,   27,   27,   27,   27,    0,    0,   25,
   25,   25,   25,   25,   25,   25,   25,   25,   25,   25,
   25,   25,   25,   25,   25,   25,   25,    0,    0,    0,
    0,    0,    0,    0,    0,    0,   47,   25,   25,   25,
   25,   25,   25,   25,   25,   25,   25,   25,   25,   25,
   25,   25,   25,   25,   25,   26,   26,   26,   26,   26,
   26,   26,   26,   26,   26,   26,   26,   26,   26,   26,
   26,   26,   26,    0,    0,    0,    0,    0,    0,    0,
    0,    0,   48,   26,   26,   26,   26,   26,   26,   26,
   26,   26,   26,   26,   26,   26,   26,   26,   26,   26,
   26,    0,    0,   46,    0,   46,    0,    0,    0,    0,
    0,    0,    0,   45,   45,   45,   45,   45,   45,   45,
   45,   45,   45,   45,   45,   45,   45,   45,   45,   45,
   45,    0,   28,    0,    0,    0,    0,    0,    0,    0,
    0,   45,   45,   45,   45,   45,   45,   45,   45,   45,
   45,   45,   45,   45,   45,   45,   45,   45,   45,   47,
    0,   47,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,   23,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,   48,    0,   48,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,   32,    0,    0,   46,   46,   46,
   46,   46,   46,   46,   46,   46,   46,   46,   46,   46,
   46,   46,   46,   46,   46,   28,    0,   28,    0,    0,
    0,    0,    0,    0,    0,   46,   46,   46,   46,   46,
   46,   46,   46,   46,   46,   46,   46,   46,   46,   46,
   46,   46,   46,    0,   10,    0,    0,    0,    0,    0,
    0,    0,    0,   47,   47,   47,   47,   47,   47,   47,
   47,   47,   47,   47,   47,   47,   47,   47,   47,   47,
   47,   23,    0,   23,    0,    0,    0,    0,    0,    0,
    0,   47,   47,   47,   47,   47,   47,   47,   47,   47,
   47,   47,   47,   47,   47,   47,   47,   47,   47,   48,
   48,   48,   48,   48,   48,   48,   48,   48,   48,   48,
   48,   48,   48,   48,   48,   48,   48,   32,    0,   32,
    0,    0,    0,    0,    0,    0,    0,   48,   48,   48,
   48,   48,   48,   48,   48,   48,   48,   48,   48,   48,
   48,   48,   48,   48,   48,    0,   36,    0,    0,   28,
   28,   28,   28,   28,   28,   28,   28,   28,   28,   28,
   28,   28,   28,   28,   28,   28,   28,   10,    0,   10,
    0,    0,    0,    0,    0,    0,    0,   28,   28,   28,
   28,    0,    0,   28,   28,   28,   28,   28,   28,   28,
   28,   28,   28,   28,   28,    0,    9,    0,    0,    0,
    0,    0,    0,    0,    0,   23,   23,   23,   23,   23,
   23,   23,   23,   23,   23,   23,   23,   23,   23,   23,
   23,   23,   23,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,   23,   23,   23,   23,    0,    0,   23,
   23,   23,   23,   23,   23,   23,   23,   23,   23,   23,
   23,   32,   32,   32,   32,   32,   32,   32,   32,   32,
   32,   32,   32,   32,   32,   32,   32,   32,   32,   36,
    4,   36,    0,    0,    0,    0,    0,    0,    0,   32,
   32,   32,   32,    0,    0,   32,   32,   32,   32,   32,
   32,   32,   32,   32,   32,   32,   32,    0,    0,    0,
    0,   10,   10,   10,   10,   10,   10,   10,   10,   10,
   10,   10,   10,   10,   10,   10,   10,   10,   10,    9,
    0,    9,    0,    0,    0,    0,   24,    0,    0,   10,
   10,   10,   10,    0,    0,   10,   10,   10,   10,   10,
   10,   10,   10,   10,   10,   10,   10,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    5,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    4,    0,    4,    0,    0,    0,    0,
    0,    0,    0,   36,   36,   36,   36,   36,   36,   36,
   36,   36,   36,   36,   36,   36,   36,   36,   36,   36,
   36,    0,    8,    0,    0,    0,    0,    0,    0,    0,
    0,   36,   36,   36,   36,    0,    0,   36,   36,   36,
   36,   36,   36,   36,   36,   36,   36,   36,   36,   24,
    0,   24,    0,    9,    9,    9,    9,    9,    9,    9,
    9,    9,    9,    9,    9,    9,    9,    9,    9,    9,
    9,    0,    0,    0,    0,    0,    0,    0,   12,    0,
    0,    9,    9,    9,    9,    0,    0,    9,    9,    9,
    9,    9,    9,    9,    9,    9,    9,    9,    9,    5,
    0,    5,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    4,    4,    4,
    4,    4,    4,    4,    4,    4,    4,    4,    4,    4,
    4,    4,    4,    4,    4,    8,    0,    8,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    4,    0,
    0,    4,    4,    4,    4,    4,    4,    4,    4,    4,
    4,    4,    4,    0,   41,    0,    0,    0,    0,    0,
    0,    0,    0,   24,   24,   24,   24,   24,   24,   24,
   24,   24,   24,   24,   24,   24,   24,   24,   24,   24,
   24,   12,    0,   12,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,   24,    0,    0,   24,   24,   24,
   24,   24,   24,   24,   24,   24,   24,   24,   24,    0,
   11,    0,    0,    5,    5,    5,    5,    5,    5,    5,
    5,    5,    5,    5,    5,    5,    5,    5,    5,    5,
    5,   31,    0,   92,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    5,    0,    0,    5,    5,    5,
    5,    5,    5,    5,    5,    5,    5,    5,    5,    8,
    8,    8,    8,    8,    8,    8,    8,    8,    8,    8,
    8,    8,    8,    8,    8,    8,    8,   41,    0,   41,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    8,    0,    0,    8,    8,    8,    8,    8,    8,    8,
    8,    8,    8,    8,    8,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,   12,   12,   12,   12,   12,
   12,   12,   12,   12,   12,   12,   12,   12,   12,   12,
   12,   12,   12,   11,    0,   11,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,   12,    0,    0,   12,
   12,   12,   12,   12,   12,   12,   12,   12,   12,   12,
   12,    0,    0,    0,    0,    2,    3,    4,    5,    6,
    7,    8,    9,   10,   11,    0,   12,   60,   14,   15,
   16,   17,   18,   31,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,   19,    0,    0,   20,
   21,   22,   23,   24,   25,   26,   27,   28,   29,   30,
    0,   41,   41,   41,   41,   41,   41,   41,   41,   41,
   41,   41,   41,   41,   41,   41,   41,   41,   41,   31,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,   41,    0,    0,   41,   41,   41,   41,   41,
   41,   41,   41,   41,   41,   41,   41,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,   11,   11,   11,
   11,   11,   11,   11,   11,   11,   11,   11,   11,   11,
   11,   11,   11,   11,   11,   31,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,   11,    0,
    0,   11,   11,   11,   11,   11,   11,   11,   11,   11,
   11,   11,   11,    0,    0,    0,    0,    2,    3,    4,
    5,    6,    7,    8,    9,   10,   11,    0,   12,   13,
   14,   15,   16,   17,   18,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,   19,    0,
    0,   20,   21,   22,   23,   24,   25,   26,   27,   28,
   29,   30,    0,    2,    3,    4,    5,    6,    7,    8,
    9,   10,   11,    0,   12,   60,   14,   15,   16,   17,
   18,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,   19,    0,    0,   20,   21,   22,
   23,   24,   25,   26,   27,   28,   29,   30,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    2,
    3,    4,    5,    6,    7,    8,    9,   10,   11,    0,
   12,    0,   14,   15,   16,   17,   18,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
   19,    0,    0,   20,   21,   22,   23,   24,   25,   26,
   27,   28,   29,   30,
};
static const YYINT yycheck[] = {                        125,
    0,  123,    0,  123,   21,   91,  123,  125,  123,   26,
   27,   28,   29,   30,  123,   12,  257,  258,  125,  125,
  125,  107,   19,  289,  290,  125,    0,   44,   25,    0,
  285,  286,  287,   31,  289,  290,   33,  113,   35,   36,
   38,  118,   39,   40,   41,   42,   -1,    0,  303,  304,
  305,  306,  307,  308,  309,  310,  311,  312,  313,  289,
  290,   -1,   59,   60,   -1,   -1,  123,   -1,   65,  263,
  264,  265,  266,  303,  304,  305,  306,  307,  308,  309,
  310,  311,  312,  313,  101,   -1,   -1,   84,   -1,  285,
  286,  287,   -1,  289,  290,   -1,   -1,   94,   95,   -1,
   97,   98,   99,  100,    0,   -1,  103,  303,  304,  305,
  306,  307,  308,  309,  310,  311,  312,  313,  116,   -1,
   -1,   -1,   -1,  123,  121,  125,  123,   -1,   -1,  126,
   -1,   -1,   -1,   -1,   -1,  257,  258,  257,  258,  257,
  258,  267,  257,  258,  259,  260,  261,  262,  263,  264,
  265,  266,    0,  268,  269,  270,  271,  272,  273,  274,
  267,  267,  267,  263,  264,  265,  266,   -1,   -1,   -1,
   -1,   -1,  125,  288,   -1,   -1,  291,  292,  293,  294,
  295,  296,  297,  298,  299,  300,  301,  302,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,    0,  256,
  257,  258,  259,  260,  261,  262,  263,  264,  265,  266,
   -1,  268,  269,  270,  271,  272,  273,  274,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,  123,   -1,  125,
   -1,  288,   -1,   -1,  291,  292,  293,  294,  295,  296,
  297,  298,  299,  300,  301,  303,  304,  305,  306,  307,
  308,  309,  310,  311,  312,  313,    0,  257,  258,  259,
  260,  261,  262,  263,  264,  265,  266,  267,  268,  269,
  270,  271,  272,  273,  274,  123,   -1,  125,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,  285,  286,  287,  288,   -1,
   -1,  291,  292,  293,  294,  295,  296,  297,  298,  299,
  300,  301,  302,  303,  304,  305,  306,  307,  308,  309,
  310,  311,  312,  313,  267,   -1,   -1,   -1,   -1,   -1,
   -1,  123,   -1,  125,  289,  290,   -1,   -1,   -1,   -1,
   -1,   -1,  285,  286,  287,   -1,  289,  290,  303,  304,
  305,  306,  307,  308,  309,  310,  311,  312,  313,   -1,
  303,  304,  305,  306,  307,  308,  309,  310,  311,  312,
  313,  257,  258,  259,  260,  261,  262,  263,  264,  265,
  266,  267,  268,  269,  270,  271,  272,  273,  274,  123,
    0,  125,   -1,   -1,   -1,   -1,   -1,   -1,   -1,  285,
  286,  287,  288,  289,  290,  291,  292,  293,  294,  295,
  296,  297,  298,  299,  300,  301,  302,   -1,   -1,  257,
  258,  259,  260,  261,  262,  263,  264,  265,  266,  267,
  268,  269,  270,  271,  272,  273,  274,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,    0,  285,  286,  287,
  288,  289,  290,  291,  292,  293,  294,  295,  296,  297,
  298,  299,  300,  301,  302,  257,  258,  259,  260,  261,
  262,  263,  264,  265,  266,  267,  268,  269,  270,  271,
  272,  273,  274,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,    0,  285,  286,  287,  288,  289,  290,  291,
  292,  293,  294,  295,  296,  297,  298,  299,  300,  301,
  302,   -1,   -1,  123,   -1,  125,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,  257,  258,  259,  260,  261,  262,  263,
  264,  265,  266,  267,  268,  269,  270,  271,  272,  273,
  274,   -1,    0,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,  285,  286,  287,  288,  289,  290,  291,  292,  293,
  294,  295,  296,  297,  298,  299,  300,  301,  302,  123,
   -1,  125,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,    0,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,  123,   -1,  125,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,    0,   -1,   -1,  257,  258,  259,
  260,  261,  262,  263,  264,  265,  266,  267,  268,  269,
  270,  271,  272,  273,  274,  123,   -1,  125,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,  285,  286,  287,  288,  289,
  290,  291,  292,  293,  294,  295,  296,  297,  298,  299,
  300,  301,  302,   -1,    0,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,  257,  258,  259,  260,  261,  262,  263,
  264,  265,  266,  267,  268,  269,  270,  271,  272,  273,
  274,  123,   -1,  125,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,  285,  286,  287,  288,  289,  290,  291,  292,  293,
  294,  295,  296,  297,  298,  299,  300,  301,  302,  257,
  258,  259,  260,  261,  262,  263,  264,  265,  266,  267,
  268,  269,  270,  271,  272,  273,  274,  123,   -1,  125,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,  285,  286,  287,
  288,  289,  290,  291,  292,  293,  294,  295,  296,  297,
  298,  299,  300,  301,  302,   -1,    0,   -1,   -1,  257,
  258,  259,  260,  261,  262,  263,  264,  265,  266,  267,
  268,  269,  270,  271,  272,  273,  274,  123,   -1,  125,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,  285,  286,  287,
  288,   -1,   -1,  291,  292,  293,  294,  295,  296,  297,
  298,  299,  300,  301,  302,   -1,    0,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,  257,  258,  259,  260,  261,
  262,  263,  264,  265,  266,  267,  268,  269,  270,  271,
  272,  273,  274,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,  285,  286,  287,  288,   -1,   -1,  291,
  292,  293,  294,  295,  296,  297,  298,  299,  300,  301,
  302,  257,  258,  259,  260,  261,  262,  263,  264,  265,
  266,  267,  268,  269,  270,  271,  272,  273,  274,  123,
    0,  125,   -1,   -1,   -1,   -1,   -1,   -1,   -1,  285,
  286,  287,  288,   -1,   -1,  291,  292,  293,  294,  295,
  296,  297,  298,  299,  300,  301,  302,   -1,   -1,   -1,
   -1,  257,  258,  259,  260,  261,  262,  263,  264,  265,
  266,  267,  268,  269,  270,  271,  272,  273,  274,  123,
   -1,  125,   -1,   -1,   -1,   -1,    0,   -1,   -1,  285,
  286,  287,  288,   -1,   -1,  291,  292,  293,  294,  295,
  296,  297,  298,  299,  300,  301,  302,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,    0,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,  123,   -1,  125,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,  257,  258,  259,  260,  261,  262,  263,
  264,  265,  266,  267,  268,  269,  270,  271,  272,  273,
  274,   -1,    0,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,  285,  286,  287,  288,   -1,   -1,  291,  292,  293,
  294,  295,  296,  297,  298,  299,  300,  301,  302,  123,
   -1,  125,   -1,  257,  258,  259,  260,  261,  262,  263,
  264,  265,  266,  267,  268,  269,  270,  271,  272,  273,
  274,   -1,   -1,   -1,   -1,   -1,   -1,   -1,    0,   -1,
   -1,  285,  286,  287,  288,   -1,   -1,  291,  292,  293,
  294,  295,  296,  297,  298,  299,  300,  301,  302,  123,
   -1,  125,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,  257,  258,  259,
  260,  261,  262,  263,  264,  265,  266,  267,  268,  269,
  270,  271,  272,  273,  274,  123,   -1,  125,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,  288,   -1,
   -1,  291,  292,  293,  294,  295,  296,  297,  298,  299,
  300,  301,  302,   -1,    0,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,  257,  258,  259,  260,  261,  262,  263,
  264,  265,  266,  267,  268,  269,  270,  271,  272,  273,
  274,  123,   -1,  125,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,  288,   -1,   -1,  291,  292,  293,
  294,  295,  296,  297,  298,  299,  300,  301,  302,   -1,
    0,   -1,   -1,  257,  258,  259,  260,  261,  262,  263,
  264,  265,  266,  267,  268,  269,  270,  271,  272,  273,
  274,  123,   -1,  125,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,  288,   -1,   -1,  291,  292,  293,
  294,  295,  296,  297,  298,  299,  300,  301,  302,  257,
  258,  259,  260,  261,  262,  263,  264,  265,  266,  267,
  268,  269,  270,  271,  272,  273,  274,  123,   -1,  125,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
  288,   -1,   -1,  291,  292,  293,  294,  295,  296,  297,
  298,  299,  300,  301,  302,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,  257,  258,  259,  260,  261,
  262,  263,  264,  265,  266,  267,  268,  269,  270,  271,
  272,  273,  274,  123,   -1,  125,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,  288,   -1,   -1,  291,
  292,  293,  294,  295,  296,  297,  298,  299,  300,  301,
  302,   -1,   -1,   -1,   -1,  257,  258,  259,  260,  261,
  262,  263,  264,  265,  266,   -1,  268,  269,  270,  271,
  272,  273,  274,  123,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,  288,   -1,   -1,  291,
  292,  293,  294,  295,  296,  297,  298,  299,  300,  301,
   -1,  257,  258,  259,  260,  261,  262,  263,  264,  265,
  266,  267,  268,  269,  270,  271,  272,  273,  274,  123,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,  288,   -1,   -1,  291,  292,  293,  294,  295,
  296,  297,  298,  299,  300,  301,  302,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,  257,  258,  259,
  260,  261,  262,  263,  264,  265,  266,  267,  268,  269,
  270,  271,  272,  273,  274,  123,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,  288,   -1,
   -1,  291,  292,  293,  294,  295,  296,  297,  298,  299,
  300,  301,  302,   -1,   -1,   -1,   -1,  257,  258,  259,
  260,  261,  262,  263,  264,  265,  266,   -1,  268,  269,
  270,  271,  272,  273,  274,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,  288,   -1,
   -1,  291,  292,  293,  294,  295,  296,  297,  298,  299,
  300,  301,   -1,  257,  258,  259,  260,  261,  262,  263,
  264,  265,  266,   -1,  268,  269,  270,  271,  272,  273,
  274,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,  288,   -1,   -1,  291,  292,  293,
  294,  295,  296,  297,  298,  299,  300,  301,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,  257,
  258,  259,  260,  261,  262,  263,  264,  265,  266,   -1,
  268,   -1,  270,  271,  272,  273,  274,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
  288,   -1,   -1,  291,  292,  293,  294,  295,  296,  297,
  298,  299,  300,  301,
};
#define YYFINAL 32
#ifndef YYDEBUG
#define YYDEBUG 0
#endif
#define YYMAXTOKEN 313
#define YYUNDFTOKEN 344
#define YYTRANSLATE(a) ((a) > YYMAXTOKEN ? YYUNDFTOKEN : (a))
#if YYDEBUG
static const char *const yyname[] = {

"end-of-file",0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,"'{'",0,"'}'",0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,"CONTIG","QTEXT","SPACE",
"THIN","TAB","MATRIX","LCOL","CCOL","RCOL","COL","ABOVE","MARK","LINEUP","SUM",
"INT","PROD","UNION","INTER","DEFINE","TDEFINE","NDEFINE","DELIM","GSIZE",
"GFONT","INCLUDE","IFDEF","DOTEQ","DOTEN","FROM","TO","OVER","SQRT","SUP","SUB",
"SIZE","FONT","ROMAN","ITALIC","BOLD","FAT","UP","DOWN","BACK","FWD","LEFT",
"RIGHT","DOT","DOTDOT","HAT","TILDE","BAR","LOWBAR","HIGHBAR","UNDER","VEC",
"DYAD","UTILDE",0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
"illegal-symbol",
};
static const char *const yyrule[] = {
"$accept : stuff",
"stuff : eqn",
"stuff : error",
"stuff :",
"eqn : box",
"eqn : eqn box",
"eqn : eqn lineupbox",
"eqn : LINEUP",
"lineupbox : LINEUP box",
"sbox : SUP box",
"sbox :",
"tbox : TO box",
"tbox :",
"box : '{' eqn '}'",
"box : QTEXT",
"box : CONTIG",
"box : SPACE",
"box : THIN",
"box : TAB",
"box : SUM",
"box : PROD",
"box : UNION",
"box : INTER",
"box : box OVER box",
"box : MARK box",
"box : size box",
"box : font box",
"box : FAT box",
"box : SQRT box",
"$$1 :",
"box : box SUB $$1 box sbox",
"$$2 :",
"box : box SUP $$2 box",
"$$3 :",
"box : int SUB $$3 box sbox",
"$$4 :",
"box : int SUP $$4 box",
"box : int",
"$$5 :",
"box : box FROM $$5 box tbox",
"$$6 :",
"box : box TO $$6 box",
"box : left eqn right",
"box : left eqn",
"box : box diacrit",
"box : fwd box",
"box : up box",
"box : back box",
"box : down box",
"box : column",
"$$7 :",
"box : MATRIX $$7 '{' collist '}'",
"int : INT",
"fwd : FWD text",
"up : UP text",
"back : BACK text",
"down : DOWN text",
"diacrit : HAT",
"diacrit : VEC",
"diacrit : DYAD",
"diacrit : BAR",
"diacrit : LOWBAR",
"diacrit : HIGHBAR",
"diacrit : UNDER",
"diacrit : DOT",
"diacrit : TILDE",
"diacrit : UTILDE",
"diacrit : DOTDOT",
"left : LEFT text",
"left : LEFT '{'",
"right : RIGHT text",
"right : RIGHT '}'",
"collist : column",
"collist : collist column",
"column : col '{' list '}'",
"$$8 :",
"column : col text $$8 '{' list '}'",
"col : LCOL",
"col : CCOL",
"col : RCOL",
"col : COL",
"list : eqn",
"list : list ABOVE eqn",
"size : SIZE text",
"font : ROMAN",
"font : ITALIC",
"font : BOLD",
"font : FONT text",
"text : CONTIG",
"text : QTEXT",

};
#endif

int      yydebug;
int      yynerrs;

int      yyerrflag;
int      yychar;
YYSTYPE  yyval;
YYSTYPE  yylval;

/* define the initial stack-sizes */
#ifdef YYSTACKSIZE
#undef YYMAXDEPTH
#define YYMAXDEPTH  YYSTACKSIZE
#else
#ifdef YYMAXDEPTH
#define YYSTACKSIZE YYMAXDEPTH
#else
#define YYSTACKSIZE 10000
#define YYMAXDEPTH  10000
#endif
#endif

#define YYINITSTACKSIZE 200

typedef struct {
    unsigned stacksize;
    YYINT    *s_base;
    YYINT    *s_mark;
    YYINT    *s_last;
    YYSTYPE  *l_base;
    YYSTYPE  *l_mark;
} YYSTACKDATA;
/* variables for the parser stack */
static YYSTACKDATA yystack;

#if YYDEBUG
#include <stdio.h>	/* needed for printf */
#endif

#include <stdlib.h>	/* needed for malloc, etc */
#include <string.h>	/* needed for memset */

/* allocate initial stack or double stack size, up to YYMAXDEPTH */
static int yygrowstack(YYSTACKDATA *data)
{
    int i;
    unsigned newsize;
    YYINT *newss;
    YYSTYPE *newvs;

    if ((newsize = data->stacksize) == 0)
        newsize = YYINITSTACKSIZE;
    else if (newsize >= YYMAXDEPTH)
        return YYENOMEM;
    else if ((newsize *= 2) > YYMAXDEPTH)
        newsize = YYMAXDEPTH;

    i = (int) (data->s_mark - data->s_base);
    newss = (YYINT *)realloc(data->s_base, newsize * sizeof(*newss));
    if (newss == 0)
        return YYENOMEM;

    data->s_base = newss;
    data->s_mark = newss + i;

    newvs = (YYSTYPE *)realloc(data->l_base, newsize * sizeof(*newvs));
    if (newvs == 0)
        return YYENOMEM;

    data->l_base = newvs;
    data->l_mark = newvs + i;

    data->stacksize = newsize;
    data->s_last = data->s_base + newsize - 1;
    return 0;
}

#if YYPURE || defined(YY_NO_LEAKS)
static void yyfreestack(YYSTACKDATA *data)
{
    free(data->s_base);
    free(data->l_base);
    memset(data, 0, sizeof(*data));
}
#else
#define yyfreestack(data) /* nothing */
#endif

#define YYABORT  goto yyabort
#define YYREJECT goto yyabort
#define YYACCEPT goto yyaccept
#define YYERROR  goto yyerrlab

int
YYPARSE_DECL()
{
    int yym, yyn, yystate;
#if YYDEBUG
    const char *yys;

    if ((yys = getenv("YYDEBUG")) != 0)
    {
        yyn = *yys;
        if (yyn >= '0' && yyn <= '9')
            yydebug = yyn - '0';
    }
#endif

    yym = 0;
    yyn = 0;
    yynerrs = 0;
    yyerrflag = 0;
    yychar = YYEMPTY;
    yystate = 0;

#if YYPURE
    memset(&yystack, 0, sizeof(yystack));
#endif

    if (yystack.s_base == NULL && yygrowstack(&yystack) == YYENOMEM) goto yyoverflow;
    yystack.s_mark = yystack.s_base;
    yystack.l_mark = yystack.l_base;
    yystate = 0;
    *yystack.s_mark = 0;

yyloop:
    if ((yyn = yydefred[yystate]) != 0) goto yyreduce;
    if (yychar < 0)
    {
        yychar = YYLEX;
        if (yychar < 0) yychar = YYEOF;
#if YYDEBUG
        if (yydebug)
        {
            if ((yys = yyname[YYTRANSLATE(yychar)]) == NULL) yys = yyname[YYUNDFTOKEN];
            printf("%sdebug: state %d, reading %d (%s)\n",
                    YYPREFIX, yystate, yychar, yys);
        }
#endif
    }
    if (((yyn = yysindex[yystate]) != 0) && (yyn += yychar) >= 0 &&
            yyn <= YYTABLESIZE && yycheck[yyn] == (YYINT) yychar)
    {
#if YYDEBUG
        if (yydebug)
            printf("%sdebug: state %d, shifting to state %d\n",
                    YYPREFIX, yystate, yytable[yyn]);
#endif
        if (yystack.s_mark >= yystack.s_last && yygrowstack(&yystack) == YYENOMEM) goto yyoverflow;
        yystate = yytable[yyn];
        *++yystack.s_mark = yytable[yyn];
        *++yystack.l_mark = yylval;
        yychar = YYEMPTY;
        if (yyerrflag > 0)  --yyerrflag;
        goto yyloop;
    }
    if (((yyn = yyrindex[yystate]) != 0) && (yyn += yychar) >= 0 &&
            yyn <= YYTABLESIZE && yycheck[yyn] == (YYINT) yychar)
    {
        yyn = yytable[yyn];
        goto yyreduce;
    }
    if (yyerrflag != 0) goto yyinrecovery;

    YYERROR_CALL("syntax error");

    goto yyerrlab; /* redundant goto avoids 'unused label' warning */
yyerrlab:
    ++yynerrs;

yyinrecovery:
    if (yyerrflag < 3)
    {
        yyerrflag = 3;
        for (;;)
        {
            if (((yyn = yysindex[*yystack.s_mark]) != 0) && (yyn += YYERRCODE) >= 0 &&
                    yyn <= YYTABLESIZE && yycheck[yyn] == (YYINT) YYERRCODE)
            {
#if YYDEBUG
                if (yydebug)
                    printf("%sdebug: state %d, error recovery shifting\
 to state %d\n", YYPREFIX, *yystack.s_mark, yytable[yyn]);
#endif
                if (yystack.s_mark >= yystack.s_last && yygrowstack(&yystack) == YYENOMEM) goto yyoverflow;
                yystate = yytable[yyn];
                *++yystack.s_mark = yytable[yyn];
                *++yystack.l_mark = yylval;
                goto yyloop;
            }
            else
            {
#if YYDEBUG
                if (yydebug)
                    printf("%sdebug: error recovery discarding state %d\n",
                            YYPREFIX, *yystack.s_mark);
#endif
                if (yystack.s_mark <= yystack.s_base) goto yyabort;
                --yystack.s_mark;
                --yystack.l_mark;
            }
        }
    }
    else
    {
        if (yychar == YYEOF) goto yyabort;
#if YYDEBUG
        if (yydebug)
        {
            if ((yys = yyname[YYTRANSLATE(yychar)]) == NULL) yys = yyname[YYUNDFTOKEN];
            printf("%sdebug: state %d, error recovery discards token %d (%s)\n",
                    YYPREFIX, yystate, yychar, yys);
        }
#endif
        yychar = YYEMPTY;
        goto yyloop;
    }

yyreduce:
#if YYDEBUG
    if (yydebug)
        printf("%sdebug: state %d, reducing by rule %d (%s)\n",
                YYPREFIX, yystate, yyn, yyrule[yyn]);
#endif
    yym = yylen[yyn];
    if (yym > 0)
        yyval = yystack.l_mark[1-yym];
    else
        memset(&yyval, 0, sizeof yyval);

    switch (yyn)
    {
case 1:
#line 24 "eqn.y"
	{ putout(yystack.l_mark[0]); }
break;
case 2:
#line 25 "eqn.y"
	{ ERROR "syntax error" WARNING; }
break;
case 3:
#line 26 "eqn.y"
	{ eqnreg = 0; }
break;
case 5:
#line 30 "eqn.y"
	{ eqnbox(yystack.l_mark[-1], yystack.l_mark[0], 0); }
break;
case 6:
#line 31 "eqn.y"
	{ eqnbox(yystack.l_mark[-1], yystack.l_mark[0], 1); }
break;
case 7:
#line 32 "eqn.y"
	{ lineup(0); }
break;
case 8:
#line 35 "eqn.y"
	{ yyval = yystack.l_mark[0]; lineup(1); }
break;
case 9:
#line 38 "eqn.y"
	{ yyval = yystack.l_mark[0]; }
break;
case 10:
#line 39 "eqn.y"
	{ yyval = 0; }
break;
case 11:
#line 42 "eqn.y"
	{ yyval = yystack.l_mark[0]; }
break;
case 12:
#line 43 "eqn.y"
	{ yyval = 0; }
break;
case 13:
#line 46 "eqn.y"
	{ yyval = yystack.l_mark[-1]; }
break;
case 14:
#line 47 "eqn.y"
	{ text(QTEXT, (char *) yystack.l_mark[0]); }
break;
case 15:
#line 48 "eqn.y"
	{ text(CONTIG, (char *) yystack.l_mark[0]); }
break;
case 16:
#line 49 "eqn.y"
	{ text(SPACE, (char *) 0); }
break;
case 17:
#line 50 "eqn.y"
	{ text(THIN, (char *) 0); }
break;
case 18:
#line 51 "eqn.y"
	{ text(TAB, (char *) 0); }
break;
case 19:
#line 52 "eqn.y"
	{ funny(SUM); }
break;
case 20:
#line 53 "eqn.y"
	{ funny(PROD); }
break;
case 21:
#line 54 "eqn.y"
	{ funny(UNION); }
break;
case 22:
#line 55 "eqn.y"
	{ funny(INTER); }
break;
case 23:
#line 56 "eqn.y"
	{ boverb(yystack.l_mark[-2], yystack.l_mark[0]); }
break;
case 24:
#line 57 "eqn.y"
	{ mark(yystack.l_mark[0]); }
break;
case 25:
#line 58 "eqn.y"
	{ size(yystack.l_mark[-1], yystack.l_mark[0]); }
break;
case 26:
#line 59 "eqn.y"
	{ font(yystack.l_mark[-1], yystack.l_mark[0]); }
break;
case 27:
#line 60 "eqn.y"
	{ fatbox(yystack.l_mark[0]); }
break;
case 28:
#line 61 "eqn.y"
	{ sqrt(yystack.l_mark[0]); }
break;
case 29:
#line 62 "eqn.y"
	{ps -= deltaps;}
break;
case 30:
#line 62 "eqn.y"
	{ subsup(yystack.l_mark[-4], yystack.l_mark[-1], yystack.l_mark[0]); }
break;
case 31:
#line 63 "eqn.y"
	{ps -= deltaps;}
break;
case 32:
#line 63 "eqn.y"
	{ subsup(yystack.l_mark[-3], 0, yystack.l_mark[0]); }
break;
case 33:
#line 64 "eqn.y"
	{ps -= deltaps;}
break;
case 34:
#line 64 "eqn.y"
	{ integral(yystack.l_mark[-4], yystack.l_mark[-1], yystack.l_mark[0]); }
break;
case 35:
#line 65 "eqn.y"
	{ps -= deltaps;}
break;
case 36:
#line 65 "eqn.y"
	{ integral(yystack.l_mark[-3], 0, yystack.l_mark[0]); }
break;
case 37:
#line 66 "eqn.y"
	{ integral(yystack.l_mark[0], 0, 0); }
break;
case 38:
#line 67 "eqn.y"
	{ps -= deltaps;}
break;
case 39:
#line 67 "eqn.y"
	{ fromto(yystack.l_mark[-4], yystack.l_mark[-1], yystack.l_mark[0]); }
break;
case 40:
#line 68 "eqn.y"
	{ps -= deltaps;}
break;
case 41:
#line 68 "eqn.y"
	{ fromto(yystack.l_mark[-3], 0, yystack.l_mark[0]); }
break;
case 42:
#line 69 "eqn.y"
	{ paren(yystack.l_mark[-2], yystack.l_mark[-1], yystack.l_mark[0]); }
break;
case 43:
#line 70 "eqn.y"
	{ paren(yystack.l_mark[-1], yystack.l_mark[0], 0); }
break;
case 44:
#line 71 "eqn.y"
	{ diacrit(yystack.l_mark[-1], yystack.l_mark[0]); }
break;
case 45:
#line 72 "eqn.y"
	{ move(FWD, yystack.l_mark[-1], yystack.l_mark[0]); }
break;
case 46:
#line 73 "eqn.y"
	{ move(UP, yystack.l_mark[-1], yystack.l_mark[0]); }
break;
case 47:
#line 74 "eqn.y"
	{ move(BACK, yystack.l_mark[-1], yystack.l_mark[0]); }
break;
case 48:
#line 75 "eqn.y"
	{ move(DOWN, yystack.l_mark[-1], yystack.l_mark[0]); }
break;
case 49:
#line 76 "eqn.y"
	{ pile(yystack.l_mark[0]); ct = yystack.l_mark[0]; }
break;
case 50:
#line 77 "eqn.y"
	{yyval=ct;}
break;
case 51:
#line 77 "eqn.y"
	{ matrix(yystack.l_mark[-3]); ct = yystack.l_mark[-3]; }
break;
case 52:
#line 80 "eqn.y"
	{ setintegral(); }
break;
case 53:
#line 83 "eqn.y"
	{ yyval = atoi((char *) yystack.l_mark[-1]); }
break;
case 54:
#line 84 "eqn.y"
	{ yyval = atoi((char *) yystack.l_mark[-1]); }
break;
case 55:
#line 85 "eqn.y"
	{ yyval = atoi((char *) yystack.l_mark[-1]); }
break;
case 56:
#line 86 "eqn.y"
	{ yyval = atoi((char *) yystack.l_mark[-1]); }
break;
case 57:
#line 88 "eqn.y"
	{ yyval = HAT; }
break;
case 58:
#line 89 "eqn.y"
	{ yyval = VEC; }
break;
case 59:
#line 90 "eqn.y"
	{ yyval = DYAD; }
break;
case 60:
#line 91 "eqn.y"
	{ yyval = BAR; }
break;
case 61:
#line 92 "eqn.y"
	{ yyval = LOWBAR; }
break;
case 62:
#line 93 "eqn.y"
	{ yyval = HIGHBAR; }
break;
case 63:
#line 94 "eqn.y"
	{ yyval = UNDER; }
break;
case 64:
#line 95 "eqn.y"
	{ yyval = DOT; }
break;
case 65:
#line 96 "eqn.y"
	{ yyval = TILDE; }
break;
case 66:
#line 97 "eqn.y"
	{ yyval = UTILDE; }
break;
case 67:
#line 98 "eqn.y"
	{ yyval = DOTDOT; }
break;
case 68:
#line 101 "eqn.y"
	{ yyval = ((char *)yystack.l_mark[0])[0]; }
break;
case 69:
#line 102 "eqn.y"
	{ yyval = '{'; }
break;
case 70:
#line 105 "eqn.y"
	{ yyval = ((char *)yystack.l_mark[0])[0]; }
break;
case 71:
#line 106 "eqn.y"
	{ yyval = '}'; }
break;
case 74:
#line 113 "eqn.y"
	{ column(yystack.l_mark[-3], DEFGAP); }
break;
case 75:
#line 114 "eqn.y"
	{yyval=atoi((char*)yystack.l_mark[0]);}
break;
case 76:
#line 114 "eqn.y"
	{ column(yystack.l_mark[-5], yystack.l_mark[-3]); }
break;
case 77:
#line 117 "eqn.y"
	{ yyval = startcol(LCOL); }
break;
case 78:
#line 118 "eqn.y"
	{ yyval = startcol(CCOL); }
break;
case 79:
#line 119 "eqn.y"
	{ yyval = startcol(RCOL); }
break;
case 80:
#line 120 "eqn.y"
	{ yyval = startcol(COL); }
break;
case 81:
#line 123 "eqn.y"
	{ lp[ct++] = yystack.l_mark[0]; }
break;
case 82:
#line 124 "eqn.y"
	{ lp[ct++] = yystack.l_mark[0]; }
break;
case 83:
#line 127 "eqn.y"
	{ yyval = ps; setsize((char *) yystack.l_mark[0]); }
break;
case 84:
#line 130 "eqn.y"
	{ static char R[]="R"; setfont(R); }
break;
case 85:
#line 131 "eqn.y"
	{ static char I[]="I"; setfont(I); }
break;
case 86:
#line 132 "eqn.y"
	{ static char B[]="B"; setfont(B); }
break;
case 87:
#line 133 "eqn.y"
	{ setfont((char *)yystack.l_mark[0]); }
break;
#line 1238 "y.tab.c"
    }
    yystack.s_mark -= yym;
    yystate = *yystack.s_mark;
    yystack.l_mark -= yym;
    yym = yylhs[yyn];
    if (yystate == 0 && yym == 0)
    {
#if YYDEBUG
        if (yydebug)
            printf("%sdebug: after reduction, shifting from state 0 to\
 state %d\n", YYPREFIX, YYFINAL);
#endif
        yystate = YYFINAL;
        *++yystack.s_mark = YYFINAL;
        *++yystack.l_mark = yyval;
        if (yychar < 0)
        {
            yychar = YYLEX;
            if (yychar < 0) yychar = YYEOF;
#if YYDEBUG
            if (yydebug)
            {
                if ((yys = yyname[YYTRANSLATE(yychar)]) == NULL) yys = yyname[YYUNDFTOKEN];
                printf("%sdebug: state %d, reading %d (%s)\n",
                        YYPREFIX, YYFINAL, yychar, yys);
            }
#endif
        }
        if (yychar == YYEOF) goto yyaccept;
        goto yyloop;
    }
    if (((yyn = yygindex[yym]) != 0) && (yyn += yystate) >= 0 &&
            yyn <= YYTABLESIZE && yycheck[yyn] == (YYINT) yystate)
        yystate = yytable[yyn];
    else
        yystate = yydgoto[yym];
#if YYDEBUG
    if (yydebug)
        printf("%sdebug: after reduction, shifting from state %d \
to state %d\n", YYPREFIX, *yystack.s_mark, yystate);
#endif
    if (yystack.s_mark >= yystack.s_last && yygrowstack(&yystack) == YYENOMEM) goto yyoverflow;
    *++yystack.s_mark = (YYINT) yystate;
    *++yystack.l_mark = yyval;
    goto yyloop;

yyoverflow:
    YYERROR_CALL("yacc stack overflow");

yyabort:
    yyfreestack(&yystack);
    return (1);

yyaccept:
    yyfreestack(&yystack);
    return (0);
}
