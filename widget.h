/*
 * widget.h - widget managing header
 *
 * Copyright (C) 2010 Mason Larobina <mason.larobina@gmail.com>
 * Copyright (C) 2007-2009 Julien Danjou <julien@danjou.info>
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 *
 */

#ifndef LUAKIT_WIDGET_H
#define LUAKIT_WIDGET_H

typedef struct widget_t widget_t;

#include <gtk/gtk.h>
#include "luakit.h"
#include "common/util.h"
#include "common/luaclass.h"
#include "common/luaobject.h"
#include "luah.h"

typedef widget_t *(widget_constructor_t)(widget_t *);
typedef void (widget_destructor_t)(widget_t *);

widget_constructor_t widget_entry;
widget_constructor_t widget_eventbox;
widget_constructor_t widget_hbox;
widget_constructor_t widget_label;
widget_constructor_t widget_notebook;
widget_constructor_t widget_textbutton;
widget_constructor_t widget_vbox;
widget_constructor_t widget_webview;
widget_constructor_t widget_window;

typedef const struct {
    luakit_token_t tok;
    const gchar *name;
    widget_constructor_t *wc;
} widget_info_t;

/* Widget */
struct widget_t
{
    LUA_OBJECT_HEADER
    /* Widget type information */
    widget_info_t *info;
    /* Widget destructor */
    widget_destructor_t *destructor;
    /* Index function */
    gint (*index)(lua_State *, luakit_token_t);
    /* Newindex function */
    gint (*newindex)(lua_State *, luakit_token_t);
    /* Lua object ref */
    gpointer ref;
    /* Main gtk widget */
    GtkWidget *widget;
    /* Misc private data */
    gpointer data;
};

lua_class_t widget_class;
void widget_class_setup(lua_State *);

#endif

// vim: ft=c:et:sw=4:ts=8:sts=4:enc=utf-8:tw=80
