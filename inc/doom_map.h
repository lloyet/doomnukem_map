/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   doom_map.h                                       .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: lloyet <lloyet@student.le-101.fr>          +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/04/16 19:44:01 by augberna     #+#   ##    ##    #+#       */
/*   Updated: 2019/05/08 00:08:45 by lloyet      ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#ifndef _DOOM_MAP_H
# define _DOOM_MAP_H

# include "../lib/minilibx_macos/mlx.h"
# include "../lib/libft/inc/libft.h"
# include <stdint.h>
# include <math.h>
# include <stdio.h>
# include <sys/time.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>

# define RGBA(r,g,b,a)				(a << 24) | (r << 16) | (g << 8) | (b)

# define CLR_R						0x00FF0000
# define CLR_G						0x0000FF00
# define CLR_B						0x000000FF
# define CLR_A						0xFF000000

# define CLR_BG						0x00002B36
# define CLR_BG_S					0x00001E26
# define CLR_LAYER					0x00CB4B16
# define CLR_SHADOW					0x006C71C4
# define CLR_VAR					0x00D33682
# define CLR_STR					0x002AA198
# define CLR_VERTEX					0x00A0E502

# define WIDTH						1920
# define WIDTH_2					WIDTH*0.5
# define HEIGH						1080
# define HEIGH_2					HEIGH*0.5

# define G_SCALE					10

# define M_DEG						180.0/M_PI
# define M_RAD						M_PI/180.0

# define KEYBOARD_S					285
# define REG_KMASK_MAX				32

# define KEY_ESCAPE					53
# define KEY_F1						122
# define KEY_F2						120
# define KEY_F3						99
# define KEY_F4						118
# define KEY_F5						96
# define KEY_F6						97
# define KEY_F7						98
# define KEY_F8						100
# define KEY_F9						101
# define KEY_F10					109
# define KEY_F11					103
# define KEY_F12					111
# define KEY_F13					105
# define KEY_F14					107
# define KEY_F15					113
# define KEY_F16					106
# define KEY_F17					64
# define KEY_F18					79
# define KEY_F19					80
# define KEY_TILDE					50
# define KEY_1						18
# define KEY_2						19
# define KEY_3						20
# define KEY_4						21
# define KEY_5						23
# define KEY_6						22
# define KEY_7						26
# define KEY_8						28
# define KEY_9						25
# define KEY_0						29
# define KEY_MINUS					27
# define KEY_EQUAL					24
# define KEY_BACKSPACE				51
# define KEY_TAB					48
# define KEY_Q						12
# define KEY_W						13
# define KEY_E						14
# define KEY_R						15
# define KEY_T						17
# define KEY_Y						16
# define KEY_U						32
# define KEY_I						34
# define KEY_O						31
# define KEY_P						35
# define KEY_OPEN_BRACKET			33
# define KEY_OPEN_BRACE				33
# define KEY_CLOSE_BRACKET			30
# define KEY_CLOSE_BRACE			30
# define KEY_BACKSLASH				42
# define KEY_PIPE					42
# define KEY_CAPSLOCK				272
# define KEY_A						0
# define KEY_S						1
# define KEY_D						2
# define KEY_F						3
# define KEY_G						5
# define KEY_H						4
# define KEY_J						38
# define KEY_K						40
# define KEY_L						37
# define KEY_COLON					41
# define KEY_SEMI_COLON				41
# define KEY_SIMPLE_QUOTE			39
# define KEY_DOUBLE_QUOTES			39
# define KEY_ENTER					36
# define KEY_SHIFT_LEFT				257
# define KEY_Z						6
# define KEY_X						7
# define KEY_C						8
# define KEY_V						9
# define KEY_B						11
# define KEY_N						45
# define KEY_M						46
# define KEY_LESS_THAN				43
# define KEY_COMMA					43
# define KEY_GREATER_THAN			47
# define KEY_DOT					47
# define KEY_SLASH					44
# define KEY_QUESTION_MARK			44
# define KEY_SHIFT_RIGHT			258
# define KEY_CTRL_LEFT				256
# define KEY_COMMAND_LEFT			259
# define KEY_OPTION_LEFT			261
# define KEY_ALT					261
# define KEY_SPACE					49
# define KEY_COMMAND_RIGHT			260
# define KEY_ALT_GR					262
# define KEY_FN						279
# define KEY_CTRL_RIGHT				269
# define KEY_LEFT					123
# define KEY_DOWN					125
# define KEY_RIGHT					124
# define KEY_UP						126
# define KEY_DEL					117
# define KEY_HOME					115
# define KEY_END					119
# define KEY_PAGE_UP				116
# define KEY_PAGE_DOWN				121
# define KEY_CLEAR					71
# define KEY_PAD_1					83
# define KEY_PAD_2					84
# define KEY_PAD_3					85
# define KEY_PAD_4					86
# define KEY_PAD_5					87
# define KEY_PAD_6					88
# define KEY_PAD_7					89
# define KEY_PAD_8					91
# define KEY_PAD_9					92
# define KEY_PAD_0					82
# define KEY_PAD_EQUAL				81
# define KEY_PAD_DIVIDE				75
# define KEY_PAD_MULTIPLY			67
# define KEY_PAD_SUB				78
# define KEY_PAD_ADD				69
# define KEY_PAD_ENTER				76
# define KEY_PAD_DOT				65
# define MOUSE_LEFT					280
# define MOUSE_RIGHT				281
# define MOUSE_MID					282
# define MOUSE_SCROLL_UP			283
# define MOUSE_SCROLL_DOWN			284

# define KEYPRESS					2
# define KEYRELEASE					3
# define BUTTONPRESS				4
# define BUTTONRELEASE				5
# define MOTIONNOTIFY				6
# define ENTERNOTIFY				7
# define LEAVENOTIFY				8
# define FOCUSIN					9
# define FOCUSOUT					10
# define KEYMAPNOTIFY				11
# define EXPOSE						12
# define GRAPHICSEXPOSE				13
# define NOEXPOSE					14
# define VISIBILITYNOTIFY			15
# define CREATENOTIFY				16
# define DESTROYNOTIFY				17
# define UNMAPNOTIFY				18
# define MAPNOTIFY					19
# define MAPREQUEST					20
# define REPARENTNOTIFY				21
# define CONFIGURENOTIFY			22
# define CONFIGUREREQUEST			23
# define GRAVITYNOTIFY				24
# define RESIZEREQUEST				25
# define CIRCULATENOTIFY			26
# define CIRCULATEREQUEST			27
# define PROPERTYNOTIFY				28
# define SELECTIONCLEAR				29
# define SELECTIONREQUEST			30
# define SELECTIONNOTIFY			31
# define COLORMAPNOTIFY				32
# define CLIENTMESSAGE				33
# define MAPPINGNOTIFY				34
# define LASTEVENTS					35

# define NOEVENTMASK				0L
# define KEYPRESSMASK				(1L<<0)
# define KEYRELEASEMASK				(1L<<1)
# define BUTTONPRESSMASK			(1L<<2)
# define BUTTONRELEASEMASK			(1L<<3)
# define ENTERWINDOWMASK			(1L<<4)
# define LEAVEWINDOWMASK			(1L<<5)
# define POINTERMOTIONMASK			(1L<<6)
# define POINTERMOTIONHINTMASK		(1L<<7)
# define BUTTON1MOTIONMASK			(1L<<8)
# define BUTTON2MOTIONMASK			(1L<<9)
# define BUTTON3MOTIONMASK			(1L<<10)
# define BUTTON4MOTIONMASK			(1L<<11)
# define BUTTON5MOTIONMASK			(1L<<12)
# define BUTTONMOTIONMASK			(1L<<13)
# define KRYMAPSTATEMASK			(1L<<14)
# define EXPOSUREMASK				(1L<<15)
# define VISIBILITYCHANGEMASK		(1L<<16)
# define STRUCTURENOTIFYMASK		(1L<<17)
# define RESIZEREDIRECTMASK			(1L<<18)
# define SUBSTRUCTURENOTIFYMASK		(1L<<19)
# define SUBSTRUCTUREREDIRECTMASK	(1L<<20)
# define FOCUSCHANGEMASK			(1L<<21)
# define PROPERTYCHANGEMASK			(1L<<22)
# define COLORMAPCHANGEMASK			(1L<<23)
# define OWNERGRABBUTTONMASK		(1L<<24)

typedef struct		s_keyboard
{
	uint64_t		reg_key;
	uint64_t		reg_fall;
	uint64_t		reg_rise;
	int				reg_size;
	uint8_t			*reg_id;
}					t_keyboard;

typedef struct		s_vertex
{
	int				x;
	int				y;
}					t_vertex;

typedef struct		s_mouse
{
	int				x;
	int				y;
	t_keyboard		*keyboard;
}					t_mouse;

typedef struct		s_node
{
	void			*content;
	struct s_node	*parent;
	struct s_node	*child;
}					t_node;

typedef struct		s_payload
{
	int				n;
	int				index;
	t_node			*begin;
	void 			(*destroy)(void *elem);
}					t_payload;

typedef struct		s_gui
{
	t_node			*iterator;
	t_payload		*layer;
}					t_gui;

typedef struct		s_shape
{
	int				floor;
	int				ceil;
	t_node			*iterator;
	t_payload		*vertex;
}					t_shape;

typedef struct		s_image
{
	void			*id;
	void			*win_id;
	void			*mlx_id;
	char			*data;
	int				bpp;
	int				size_l;
	int				endian;
	int				width;
	int				heigh;
}					t_image;

typedef struct 		s_layer
{
	t_image			*img;
	t_shape			*s_tmp;
	t_vertex		*v_tmp;
	t_node			*iterator;
	t_payload		*shape;
	int				mode;
	int				is_draw;
	int				pipet;
	int				scale;
	double			cursor_coef;
}					t_layer;

typedef struct		s_window
{
	void			*id;
	int				width;
	int				heigh;
	char			*title;
	uint8_t			menu;
}					t_window;

typedef struct		s_framework
{
	void			*id;
	t_window		*win;
	double			frame;
}					t_framework;

typedef struct		s_engine
{
	t_framework		*mlx;
	t_gui			*gui;
	t_keyboard		*keyboard;
	t_mouse			*mouse;
	struct timeval	old;
	struct timeval	cur;
}					t_engine;

int					mouse_motion_hook(int x, int y, t_mouse *mouse);
int					mouse_press_hook(int key, int x, int y, t_mouse *mouse);
int					mouse_release_hook(int key, int x, int y, t_mouse *mouse);

void				register_new_key(t_keyboard *keyboard, int key);
int					key_is_pressed(t_keyboard *keyboard, int key);
int					key_is_rising(t_keyboard *k, int key);
int					key_is_falling(t_keyboard *k, int key);

int					key_press_hook(int key, t_keyboard *keyboard);
int					key_release_hook(int key, t_keyboard *keyboard);
int					destroy_window_hook(t_engine *engine);

void				mouse_destroy(t_mouse *mouse);
t_mouse				*new_mouse(t_keyboard *keyboard);
void				keyboard_destroy(t_keyboard *keyboard);
t_keyboard			*new_keyboard(int size);

void				debug_display(t_engine *e);

void				event_refresh(t_engine *e);
void				event_draw_tmp(t_layer *l, int x, int y);
void				event_delete_tmp(t_layer *l);

t_payload			*new_payload(void *content, void (*destroy)(void *elem));
void				payload_destroy(t_payload *p);
void				payload_add(t_payload *p, t_node *iterator, void *content);
void				payload_remove(t_payload *p, t_node **iterator);
int					payload_size(t_payload *p);

t_node				*new_iterator(t_payload *p);
void				payload_next(t_payload *p, t_node **iterator);
void				payload_prev(t_payload *p, t_node **iterator);
void				payload_iter(t_payload *p, void (*f)(void *content));

void				tree_destroy(t_node *tree, void (*del)(void *));
int					cycle_detector(t_node *begin);

t_node				*new_node(void *content);
void				node_destroy(t_node *node, void (*del)(void *));
void				node_insert(t_node *iterator, t_node *new);
void				node_remove(t_node *iterator, void (*del)(void *));
void				node_iter(t_node *iterator, void (*f)(void *content));

void				layer_destroy(t_layer *layer);
t_layer				*new_layer(t_image *img, int is_draw);
void				layer_init(t_layer *l, t_vertex *v);

void				layer_draw(t_layer *layer);
t_vertex			*layer_has_vertex(t_layer *layer, t_vertex *v);
void				layer_add(t_layer *l, t_shape *s);

void				gui_destroy(t_gui *gui);
t_gui				*new_gui(t_layer *background);
void				gui_add_layer(t_gui *gui, t_layer *layer);
void				gui_remove_layer(t_gui *gui);

void				gui_display(t_gui *gui);
void				gui_prev(t_gui *gui);
void				gui_next(t_gui *gui);

t_shape				*new_shape(t_vertex *vertex);
void				shape_destroy(t_shape *shape);

t_vertex			*shape_has_vertex(t_shape *s, t_vertex *v);
void				shape_add(t_shape *s, t_vertex *v);
void				shape_remove(t_shape *s);
void				shape_draw(t_shape *shape, t_image *img, int pipet);

t_vertex			*new_vertex(int x, int y);
void				vertex_destroy(t_vertex *v);
void				vertex_update(t_vertex *v, int x, int y);
void				vertex_draw(t_image *img, t_vertex *v, int pipet);

t_engine			*new_engine(void);
void				engine_destroy(t_engine *e);

void				window_destroy(t_window *win);
t_window			*new_window(void *mlx_id, int width, int heigh,
						char *title);
void				framework_destroy(t_framework *framework);
t_framework			*new_framework(void);

void				image_destroy(t_image *img);
t_image				*new_image(void *mlx_id, void *win_id, int width, int heigh);
void				image_attach(t_image *img, t_window *win);

void				image_clear(t_image *img);
void				image_pixel_put(t_image *img, int x, int y, int color);
void				image_fill(t_image *img, int color);
void				image_square(t_image *img, t_vertex *v, int color);

void				image_line(t_image *img, t_vertex *v1, t_vertex *v2, int c);
#endif
