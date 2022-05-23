/* See LICENSE file for copyright and license details. */

/* appearance */
static const unsigned int borderpx       = 0;        /* border pixel of windows */
static const unsigned int gappx          = 12;        /* gaps between windows */
static const unsigned int snap           = 32;       /* snap pixel */
static const unsigned int colorfultitle  = 0;
static const unsigned int colorfultag    = 1;
static const int scalepreview            = 4;        /* tag preview scaling */
static const int showbar                 = 1;        /* 0 means no bar */
static const int topbar                  = 1;        /* 0 means bottom bar */
static const int vertpad                 = 13; /* vertical padding of bar */
static const int sidepad                 = 13; /* horizontal padding of bar */
static const int user_bh                 = 33;
static const int horizpadbar             = 10;
static const int vertpadbar              = 9;
static const char *fonts[]               = { "Iosevka Nerd Font:size=10" };
static const char dmenufont[]            = "Iosevka Nerd Font:size=10";
static const char col_gray1[]            = "#101419";
static const char col_gray2[]            = "#15191e";
static const char col_gray3[]            = "#485263";
static const char col_gray4[]            = "#15191e";
static const char col_yellow[]           = "#f1cf8a";
static const char col_green[]            = "#76b97f";
static const char col_teal[]             = "#70a5eb";
static const char col_magenta[]          = "#c68aee";
static const char col_red[]              = "#e05f65";
static const char col_blue[]             = "#70a5eb";
static const char col_cyan[]             = "#74bee9";
static const char col_borderbar[]        = "#101419";
static const char *colors[][3]           = {
	/*               fg         bg         border   */
	[SchemeNorm] = { col_gray3, col_gray1, col_gray2 },
	[SchemeSel]  = { col_gray4, col_cyan,  col_cyan  },
  [SchemeTag]        = { col_gray3,       col_gray1,    col_gray1 },
  [SchemeTag1]       = { col_yellow,          col_gray1,  col_gray1 },
	[SchemeTag2]       = { col_green,         col_gray1,  col_gray1 },
  [SchemeTag3]       = { col_cyan,   col_gray1,  col_gray1 },
  [SchemeTag4]       = { col_magenta,     col_gray1,  col_gray1 },
  [SchemeTag5]       = { col_red,  col_gray1,  col_gray1 },
	[SchemeTag6]       = { col_blue,     col_gray1,  col_gray1 },
	[SchemeLayout]     = { col_green,       col_gray1,    col_gray1 },
  [SchemeLaunchers]  = { col_blue, col_gray1, col_gray1 },
};

static const int tagschemes[] = { SchemeTag1, SchemeTag2, SchemeTag3,
                                  SchemeTag4, SchemeTag5, SchemeTag6,
                                  SchemeTag7, SchemeTag8, SchemeTag9 };

/* tagging */
static const char *tags[] = { "", "亂", "", "", "", "ﭮ" };

static const unsigned int ulinepad	= 4;	/* horizontal padding between the underline and tag */
static const unsigned int ulinestroke	= 2;	/* thickness / height of the underline */
static const unsigned int ulinevoffset	= 0;	/* how far above the bottom of the bar the line should appear */
static const int ulineall 		= 0;	/* 1 to show underline on all tags, 0 for just the active ones */

/* launcher commands (They must be NULL terminated) */
static const char* apps[] = { "rofi", "-show", "drun", NULL };
static const char* dashboard[] = { "eww", "open", "--toggle", "system-tray", NULL };

static const Launcher launchers[] = {
  /* command       name to display */
  { dashboard, "舘" },
  { apps, "異" },
};

static const Rule rules[] = {
	/* xprop(1):
	 *	WM_CLASS(STRING) = instance, class
	 *	WM_NAME(STRING) = title
	 */
	/* class      instance    title       tags mask     isfloating   monitor */
	{ "Gimp",     NULL,       NULL,       0,            1,           -1 },
};

/* layout(s) */
static const float mfact     = 0.52; /* factor of master area size [0.05..0.95] */
static const int nmaster     = 1;    /* number of clients in master area */
static const int resizehints = 0;    /* 1 means respect size hints in tiled resizals */
static const int lockfullscreen = 1; /* 1 will force focus on the fullscreen window */

static const Layout layouts[] = {
	/* symbol     arrange function */
	{ "[]=",      tile },
  { "><>",      NULL },
};

/* key definitions */
#define MODKEY Mod4Mask
#define TAGKEYS(KEY,TAG) \
	{ MODKEY,                       KEY,      view,           {.ui = 1 << TAG} }, \
	{ MODKEY|ControlMask,           KEY,      toggleview,     {.ui = 1 << TAG} }, \
	{ MODKEY|ShiftMask,             KEY,      tag,            {.ui = 1 << TAG} }, \
	{ MODKEY|ControlMask|ShiftMask, KEY,      toggletag,      {.ui = 1 << TAG} },

/* helper for spawning shell commands in the pre dwm-5.0 fashion */
#define SHCMD(cmd) { .v = (const char*[]){ "/bin/sh", "-c", cmd, NULL } }

/* commands */
static char dmenumon[2] = "0"; /* component of dmenucmd, manipulated in spawn() */
static const char *dmenucmd[] = { "dmenu_run", "-m", dmenumon, "-fn", dmenufont, "-nb", col_gray1, "-nf", col_gray3, "-sb", col_cyan, "-sf", col_gray4, NULL };
static const char *roficmd[] = { "rofi", "-show", "drun", NULL };
static const char *termcmd[]  = { "st", NULL };
static const char *browsercmd[] = { "firefox", NULL };
static const char *dashboardcmd[] = { "eww", "open", "--toggle", "system-tray", NULL };
static const char *xcolorpick[] = { "/home/gabriel/.local/bin/xcolor-pick", NULL };

static Key keys[] = {
	/* modifier                     key        function        argument */
	{ MODKEY|ShiftMask,             XK_Return, spawn,          {.v = roficmd } },
	{ MODKEY|ControlMask|ShiftMask, XK_Return, spawn,          {.v = dashboardcmd } },
	{ MODKEY,                   		XK_Return, spawn,          {.v = termcmd } },
	{ MODKEY,                       XK_b,      spawn, 	       {.v = browsercmd } },
  { MODKEY,                       XK_x,      spawn,          {.v = xcolorpick } },

	{ MODKEY,                       XK_j,      focusstack,     {.i = +1 } },
	{ MODKEY,                       XK_k,      focusstack,     {.i = -1 } },
  { MODKEY,                       XK_i,      incnmaster,     {.i = +1 } },
  { MODKEY|ShiftMask,             XK_i,      incnmaster,     {.i = -1 } },
  { MODKEY|ShiftMask,             XK_h,      setmfact,       {.f = -0.05} },
  { MODKEY|ShiftMask,             XK_l,      setmfact,       {.f = +0.05} },
  { MODKEY|ShiftMask,             XK_j,      rotatestack,    {.i = +1 } },
  { MODKEY|ShiftMask,             XK_k,      rotatestack,    {.i = -1 } },

	{ MODKEY,                       XK_Return, zoom,           {0} },
	{ MODKEY,                       XK_Tab,    setlayout,      {0} },
	{ MODKEY,	                      XK_w,      killclient,     {0} },
	{ MODKEY,                       XK_m,      setlayout,      {.v = &layouts[0]} },
	{ MODKEY,                       XK_t,      setlayout,      {.v = &layouts[1]} },
	{ MODKEY,                       XK_space,  togglefloating, {0} },
	{ MODKEY,                       XK_0,      view,           {.ui = ~0 } },
	{ MODKEY|ShiftMask,             XK_0,      tag,            {.ui = ~0 } },
	{ MODKEY,                       XK_comma,  focusmon,       {.i = -1 } },
	{ MODKEY,                       XK_period, focusmon,       {.i = +1 } },
	{ MODKEY|ShiftMask,             XK_comma,  tagmon,         {.i = -1 } },
	{ MODKEY|ShiftMask,             XK_period, tagmon,         {.i = +1 } },
	{ MODKEY,                       XK_minus,  setgaps,        {.i = -1 } },
	{ MODKEY,                       XK_equal,  setgaps,        {.i = +1 } },
	{ MODKEY|ShiftMask,             XK_equal,  setgaps,        {.i = 0  } },
	TAGKEYS(                        XK_1,                      0)
	TAGKEYS(                        XK_2,                      1)
	TAGKEYS(                        XK_3,                      2)
	TAGKEYS(                        XK_4,                      3)
	TAGKEYS(                        XK_5,                      4)
	TAGKEYS(                        XK_6,                      5)
	{ MODKEY|ShiftMask,             XK_q,      quit,           {0} },
	{ MODKEY|ShiftMask, 		XK_r,      quit,           {1} }, 
};

/* button definitions */
/* click can be ClkTagBar, ClkLtSymbol, ClkStatusText, ClkWinTitle, ClkClientWin, or ClkRootWin */
static Button buttons[] = {
	/* click                event mask      button          function        argument */
	{ ClkLtSymbol,          0,              Button1,        setlayout,      {0} },
	{ ClkLtSymbol,          0,              Button3,        setlayout,      {.v = &layouts[2]} },
	{ ClkStatusText,        0,              Button2,        spawn,          {.v = termcmd } },
	{ ClkClientWin,         MODKEY,         Button1,        movemouse,      {0} },
	{ ClkClientWin,         MODKEY,         Button2,        togglefloating, {0} },
	{ ClkClientWin,         MODKEY,         Button3,        resizemouse,    {0} },
	{ ClkTagBar,            0,              Button1,        view,           {0} },
	{ ClkTagBar,            0,              Button3,        toggleview,     {0} },
	{ ClkTagBar,            MODKEY,         Button1,        tag,            {0} },
	{ ClkTagBar,            MODKEY,         Button3,        toggletag,      {0} },
};

