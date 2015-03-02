#ifndef _MINI_DEBUG_H_
#define _MINI_DEBUG_H_

#undef MINI_DEBUG

#ifdef MINI_DEBUG
	#define dlog(x, y) printf(x, y)
#else
#define dlog(x, y) ;
#endif

#endif