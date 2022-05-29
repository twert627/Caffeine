/* Easy file handling utilities. */

#define _XOPEN_SOURCE 500 
#include "fs.h"

#ifdef __linux__
#define _XOPEN_SOURCE_EXTENDED 1
#include <ftw.h>
#else
/* TODO: Windows */
#endif



