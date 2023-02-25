// config.h configuration of MUD

#ifndef _CONFIG_H_
#define _CONFIG_H_

#define	INSTALL_CRASH_SAVE	1
#define INSTALL_EXAMINE	 1
#define LOG_WIZARD	      1

// How many item does the user can carried, this value will
// affect commands:get steal put give, but there is may be
// some other event cause some object move to user, so in
// fact, the user may carry out.
#define MAX_ITEM_CARRIED	50

// How many item does the room can got
#define MAX_ITEM_IN_ROOM	10

#endif
