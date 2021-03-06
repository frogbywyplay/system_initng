/*
 * Initng, a next generation sysvinit replacement.
 * Copyright (C) 2006 Jimmy Wennlund <jimmy.wennlund@gmail.com>
 *
 *  This program is free software; you can redistribute it and/or modify
 *  it under the terms of the GNU General Public License as published by
 *  the Free Software Foundation; either version 2 of the License, or
 *  (at your option) any later version.
 *
 *  This program is distributed in the hope that it will be useful,
 *  but WITHOUT ANY WARRANTY; without even the implied warranty of
 *  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *  GNU General Public License for more details.
 *
 *  You should have received a copy of the GNU General Public License
 *  along with this program; if not, write to the Free Software
 *  Foundation, Inc., 51 Franklin St, Fifth Floor, Boston, MA  02110-1301  USA
 */

#include "initng.h"

#include <time.h>							/* time() */
#include <fcntl.h>							/* fcntl() */
#include <sys/un.h>							/* memmove() strcmp() */
#include <sys/wait.h>						/* waitpid() sa */
#include <linux/kd.h>						/* KDSIGACCEPT */
#include <sys/ioctl.h>						/* ioctl() */
#include <stdio.h>							/* printf() */
#include <stdlib.h>							/* free() exit() */
#include <sys/reboot.h>						/* reboot() RB_DISABLE_CAD */
#include <assert.h>
#include <errno.h>

#include "initng_global.h"

#include "initng_static_service_types.h"

#include "initng_active_db.h"
#include "initng_toolbox.h"
#include "initng_main.h"
#include "initng_execute.h"
#include "initng_common.h"
#include "initng_depend.h"
#include "initng_load_module.h"
#include "initng_handler.h"
#include "initng_kill_handler.h"
#include "initng_static_data_id.h"
#include "initng_static_states.h"


stype_h TYPE_CONTAINER = { "container", "This is an empty set that can be used as a container, and you can relate other services data to this one.",
	TRUE, NULL, NULL, NULL
};

void initng_service_register_static_stypes(void)
{
	initng_service_type_register(&TYPE_CONTAINER);
}
