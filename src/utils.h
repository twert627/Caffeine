/* Caffeine utilities */
#ifndef CAFFEINE_UTILS_H
#define CAFFEINE_UTILS_H

/* Note this out for no debug */
#define DEBUG

#ifdef DEBUG
#define debug_printf(x) printf(x)
#else 
#define debug_printf(x) 
#endif

#endif

