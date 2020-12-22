
#include "./_dev_pragmatics_/warnings.msvc.10+.h"

#include <incl.stlsoft.h>

#ifdef _DEBUG
# ifdef STLSOFT_PPF_pragma_message_SUPPORT
#  undef STLSOFT_PPF_pragma_message_SUPPORT
# endif
#endif

#ifdef UNIX

# include <incl.unixstl.h>
#else

# include <incl.winstl.h>
#endif

#include <recls/recls.h>


