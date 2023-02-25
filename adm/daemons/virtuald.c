// virtuald.c
//
// This object is the virtual object server of ES2 mudlib.
//
// By Annihilator (07/06/95)
// Adapted for XKX (12/15/95)

void create()
{
	seteuid(getuid());
}

// This function is called by master object to return the "virtual" object
// of <file> when dirver failed to find such a file.
object compile_object(string file)
{
	return 0;
}

/*
BY：NAME
QQ：21315491
DATE：2 0 2 2 . 0 2 . 0 3
*/
