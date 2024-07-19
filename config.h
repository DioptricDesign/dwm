/* See LICENSE file for copyright and license details. */

/* appearance */
static const unsigned int borderpx  = 2;        /* border pixel of windows */
static const unsigned int gappx     = 5;        /* gaps between windows */
static const unsigned int snap      = 32;       /* snap pixel */
static const unsigned int systraypinning = 0;   /* 0: sloppy systray follows selected monitor, >0: pin systray to monitor X */
static const unsigned int systrayonleft = 0;   	/* 0: systray in the right corner, >0: systray on left of status text */
static const unsigned int systrayspacing = 2;   /* systray spacing */
static const int systraypinningfailfirst = 1;   /* 1: if pinning fails, display systray on the first monitor, False: display systray on the last monitor*/
static const int showsystray        = 1;     /* 0 means no systray */
static const int showbar            = 1;     /* 0 means no bar */
static const int topbar             = 1;     /* 0 means bottom bar */
static const int user_bh            = 22;        /* 0 means that dwm will call*/
static const char *fonts[]          = { "Jetbrains mono:size=10:style=Bold" };
static const char dmenufont[]       = "Jetbrains mono:size=10:style=Bold";
static const char col_black[]       = "#272537";
static const char col_gray[]       = "#7e6d87";
static const char col_mauve[]       = "#d7d3ee";
static const char col_white[]       = "#e6e6e9";
static const char col_purple[]        = "#8650d3";
static const char col_brblack[]        = "#484867";
static const char *colors[][3]      = {
  /*               fg         bg         border   */
  [SchemeNorm] = { col_mauve, col_black, col_gray },
  [SchemeSel]  = { col_white, col_brblack,  col_purple  },
};

/* tagging */
static const char *tags[] = { "I", "II", "III", "IV", "V" };

static const Rule rules[] = {
  /* xprop(1):
   *	WM_CLASS(STRING) = instance, class
   *	WM_NAME(STRING) = title
   */
  /* class      instance    title       tags mask     isfloating   monitor */
  { "vlc",     NULL,       NULL,       1 << 1,            0,           -1 },
  { "firefox",     NULL,       NULL,       1 << 0,            0,           -1 },
  { "Gpodder",     NULL,       NULL,       1 << 1,            0,           -1 },
  { "steam",     NULL,       NULL,       1 << 2,            0,           -1 },
  { "dosbox",     NULL,       NULL,       1 << 2,            0,           -1 },
  { "Minetest",     NULL,       NULL,       1 << 2,            0,           -1 },
  { "Lutris",     NULL,       NULL,       1 << 2,            0,           -1 },
  { "VirtualBox Manager",     NULL,       NULL,       1 << 3,            0,           -1 },
  { "Inkskape",     NULL,       NULL,       1 << 4,            0,           -1 },
  { "Gimp",     NULL,       NULL,       1 << 4,            0,           -1 },
  { "Blender",     NULL,       NULL,       1 << 4,            0,           -1 },
  { "Darktable",     NULL,       NULL,       1 << 4,            0,           -1 },
  { "scribus",     NULL,       NULL,       1 << 4,            0,           -1 },
  { "Qalculate-gtk",     NULL,       NULL,       0,            1,           -1 },
  { "Gcolor3",     NULL,       NULL,       0,            1,           -1 },
};

/* layout(s) */
static const float mfact     = 0.55; /* factor of master area size [0.05..0.95] */
static const int nmaster     = 1;    /* number of clients in master area */
static const int resizehints = 1;    /* 1 means respect size hints in tiled resizals */
static const int lockfullscreen = 1; /* 1 will force focus on the fullscreen window */

static const Layout layouts[] = {
  /* symbol     arrange function */
  { "[]=",      tile },    /* first entry is default */
  { "><>",      NULL },    /* no layout function means floating behavior */
  { "[M]",      monocle },
};

/* key definitions */
#define MODKEY Mod4Mask
#define TAGKEYS(KEY,TAG)                                                \
  { MODKEY,                       KEY,      view,           {.ui = 1 << TAG} }, \
{ MODKEY|ControlMask,           KEY,      toggleview,     {.ui = 1 << TAG} }, \
{ MODKEY|ShiftMask,             KEY,      tag,            {.ui = 1 << TAG} }, \
{ MODKEY|ControlMask|ShiftMask, KEY,      toggletag,      {.ui = 1 << TAG} },

/* helper for spawning shell commands in the pre dwm-5.0 fashion */
#define SHCMD(cmd) { .v = (const char*[]){ "/bin/sh", "-c", cmd, NULL } }

/* commands */
static const char *dmenucmd[] = { "dmenu_run", "-fn", dmenufont, "-nb", col_black, "-nf", col_mauve, "-sb", col_purple, "-sf", col_white, "-h", "22", NULL };
static const char *termcmd[]  = { "alacritty", NULL };
static const char *browser[]  = { "firefox", NULL };
static const char *filebrowser[]  = { "pcmanfm", NULL };
static const char *email[]  = { "thunderbird", NULL };
static const char *editor[]  = { "emacsclient","-c", NULL };
static const char *xkill[]  = { "xkill", NULL };
static const char *sysmon[]  = { "alacritty", "-e", "htop", NULL };
static const char *clipboard[]  = { "clipmenu", NULL };
/*programs*/
static const char *vlc[]  = { "vlc", NULL };
static const char *gpodder[]  = { "gpodder", NULL };
static const char *calculator[]  = { "qalculate-gtk", NULL };
static const char *colorpckr[]  = { "gcolor3", NULL };
static const char *passwords[]  = { "keepassxc", NULL };
static const char *vms[]  = { "virtualbox", NULL };
/*scripts*/
static const char *power[]  = { "powermenu", NULL };
static const char *output[]  = { "outputmenu", NULL };
static const char *lock[]  = { "xautolockmenu", NULL };
static const char *sensor[]  = { "sensornote", NULL };
static const char *games[]  = { "gamesmenu", NULL };
static const char *graphics[]  = { "graphicsmenu", NULL };
static const char *library[]  = { "libmenu", NULL };
static const char *calendar[]  = { "calendarmenu", NULL };
static const char *chat[]  = { "chatmenu", NULL };
static const char *timer[]  = { "timermenu", NULL };
static const char *search[]  = { "dmsearch", NULL };
/* media commands*/
static const char *upvol[]   = { "/usr/bin/pactl", "set-sink-volume", "0", "+2%",     NULL };
static const char *downvol[] = { "/usr/bin/pactl", "set-sink-volume", "0", "-2%",     NULL };
static const char *mutevol[] = { "/usr/bin/pactl", "set-sink-mute",   "0", "toggle",  NULL };
static const char *next[] = { "/usr/bin/playerctl", "next", NULL };
static const char *play[] = { "/usr/bin/playerctl", "play-pause", NULL };
static const char *previous[] = { "/usr/bin/playerctl", "previous", NULL };

#include "movestack.c"
#include <X11/XF86keysym.h>
static const Key keys[] = {
  /* modifier                     key        function        argument */
  { MODKEY,                       XK_p,      spawn,          {.v = dmenucmd } },
  { MODKEY,                       XK_t,      spawn,          {.v = termcmd } },
  { MODKEY,                       XK_w,      spawn,          {.v = browser} },
  { MODKEY,                       XK_f,      spawn,          {.v = filebrowser} },
  { MODKEY,                       XK_m,      spawn,          {.v = email} },
  { MODKEY,                       XK_e,      spawn,          {.v = editor} },
  { MODKEY,                       XK_v,      spawn,          {.v = vlc} },
  { MODKEY|ShiftMask,             XK_v,      spawn,          {.v = vms} },
  { MODKEY|ShiftMask,             XK_p,      spawn,          {.v = passwords} },
  { MODKEY,                       XK_g,      spawn,          {.v = gpodder} },
  { MODKEY,                       XK_c,      spawn,          {.v = calculator} },
  { MODKEY|ShiftMask,             XK_c,      spawn,          {.v = colorpckr} },
  { MODKEY|ShiftMask,             XK_b,      spawn,          {.v = clipboard} },
  { MODKEY,                       XK_minus,  spawn,          {.v = downvol} },
  { MODKEY,                       XK_equal,  spawn,          {.v = upvol} },
  { MODKEY,                       XK_0,      spawn,          {.v = mutevol} },
  { MODKEY,                       XK_slash,  spawn,          {.v = play} },
  { MODKEY,                       XK_period, spawn,          {.v = next} },
  { MODKEY,                       XK_comma,  spawn,          {.v = previous} },
  { 0,     XF86XK_AudioPrev,		             spawn,	         {.v = previous} },
  { 0,     XF86XK_AudioPlay,		             spawn,	         {.v = play} },
  { 0,     XF86XK_AudioNext,		             spawn,	         {.v = next} },
  { 0,     XF86XK_AudioMute,		             spawn,          {.v = mutevol} },
  { 0,     XF86XK_AudioLowerVolume,		       spawn,          {.v = downvol} },
  { 0,     XF86XK_AudioRaiseVolume,		       spawn,          {.v = upvol} },
  { 0,     XF86XK_MonBrightnessUp,	         spawn,		       {.v = (const char*[]){ "xbacklight", "-inc", "15", NULL } } },
  { 0,     XF86XK_MonBrightnessDown,	       spawn,		       {.v = (const char*[]){ "xbacklight", "-dec", "15", NULL } } },
  { MODKEY,                       XK_b,      togglebar,      {0} },
  { MODKEY|ShiftMask,             XK_j,      movestack,      {.i = +1 } },
  { MODKEY|ShiftMask,             XK_k,      movestack,      {.i = -1 } },
  { MODKEY,                       XK_j,      focusstack,     {.i = +1 } },
  { MODKEY,                       XK_k,      focusstack,     {.i = -1 } },
  { MODKEY,                       XK_i,      incnmaster,     {.i = +1 } },
  { MODKEY,                       XK_d,      incnmaster,     {.i = -1 } },
  { MODKEY,                       XK_h,      setmfact,       {.f = -0.05} },
  { MODKEY,                       XK_l,      setmfact,       {.f = +0.05} },
  { MODKEY,                       XK_Return, zoom,           {0} },
  { MODKEY,                       XK_Tab,    view,           {0} },
  { MODKEY,                       XK_x,      killclient,     {0} },
  { MODKEY|ShiftMask,             XK_x,       spawn,          {.v =xkill} },
  { MODKEY,                       XK_F1,      setlayout,      {.v = &layouts[0]} },
  { MODKEY,                       XK_F2,      setlayout,      {.v = &layouts[1]} },
  { MODKEY,                       XK_F3,      setlayout,      {.v = &layouts[2]} },
  { MODKEY,                       XK_space,  setlayout,      {0} },
  { MODKEY|ShiftMask,             XK_space,  togglefloating, {0} },
  { MODKEY|ShiftMask,             XK_F11,      fullscreen,     {0} },
  { MODKEY,                       XK_BackSpace,      view,           {.ui = ~0 } },
  { MODKEY|ShiftMask,             XK_BackSpace,      tag,            {.ui = ~0 } },
  { MODKEY,                       XK_Left,  focusmon,       {.i = -1 } },
  { MODKEY,                       XK_Right, focusmon,       {.i = +1 } },
  { MODKEY|ShiftMask,             XK_Left,  tagmon,         {.i = -1 } },
  { MODKEY|ShiftMask,             XK_Right, tagmon,         {.i = +1 } },
  { MODKEY,                       XK_bracketleft,  setgaps,        {.i = -1 } },
  { MODKEY,                       XK_bracketright,  setgaps,        {.i = +1 } },
  { MODKEY|ShiftMask,             XK_bracketright,  setgaps,        {.i = 0  } },
  TAGKEYS(                        XK_1,                      0)
  TAGKEYS(                        XK_2,                      1)
  TAGKEYS(                        XK_3,                      2)
  TAGKEYS(                        XK_4,                      3)
  TAGKEYS(                        XK_5,                      4)
  { MODKEY|ShiftMask,             XK_q,      quit,           {0} },
  { MODKEY|ShiftMask,             XK_r,      quit,           {1} },
  { MODKEY,                       XK_grave, scratchpad_show, {0} },
  { MODKEY|ShiftMask,             XK_grave, scratchpad_hide, {0} },
  { MODKEY,                       XK_s,scratchpad_remove,{0} },
  { MODKEY,                       XK_apostrophe, spawn, {.v = search} },
  {ControlMask|Mod1Mask,          XK_Delete,  spawn, {.v = sysmon} },
  {ControlMask|Mod1Mask,          XK_p,       spawn, {.v = power} },
  {ControlMask|Mod1Mask,          XK_o,       spawn, {.v = output} },
  {ControlMask|Mod1Mask,          XK_l,       spawn, {.v = lock} },
  {ControlMask|Mod1Mask,          XK_s,       spawn, {.v = sensor} },
  {ControlMask|Mod1Mask,          XK_g,       spawn, {.v = games} },
  {ControlMask|Mod1Mask,          XK_x,       spawn, {.v = graphics} },
  {ControlMask|Mod1Mask,          XK_b,       spawn, {.v = library} },
  {ControlMask|Mod1Mask,          XK_c,       spawn, {.v = calendar} },
  {ControlMask|Mod1Mask,          XK_m,       spawn, {.v = chat} },
  {ControlMask|Mod1Mask,          XK_t,       spawn, {.v = timer} },
};

/* button definitions */
/* click can be ClkTagBar, ClkLtSymbol, ClkStatusText, ClkWinTitle, ClkClientWin, or ClkRootWin */
static const Button buttons[] = {
  /* click                event mask      button          function        argument */
  { ClkLtSymbol,          0,              Button1,        setlayout,      {0} },
  { ClkLtSymbol,          0,              Button3,        setlayout,      {.v = &layouts[2]} },
  { ClkWinTitle,          0,              Button2,        zoom,           {0} },
  { ClkStatusText,        0,              Button2,        spawn,          {.v = termcmd } },
  { ClkClientWin,         MODKEY,         Button1,        movemouse,      {0} },
  { ClkClientWin,         MODKEY,         Button2,        togglefloating, {0} },
  { ClkClientWin,         MODKEY,         Button3,        resizemouse,    {0} },
  { ClkTagBar,            0,              Button1,        view,           {0} },
  { ClkTagBar,            0,              Button3,        toggleview,     {0} },
  { ClkTagBar,            MODKEY,         Button1,        tag,            {0} },
  { ClkTagBar,            MODKEY,         Button3,        toggletag,      {0} },
};

