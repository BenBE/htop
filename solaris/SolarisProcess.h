#ifndef HEADER_SolarisProcess
#define HEADER_SolarisProcess
/*
htop - SolarisProcess.h
(C) 2015 Hisham H. Muhammad
(C) 2017,2018 Guy M. Broome
Released under the GNU GPLv2, see the COPYING file
in the source distribution for its full text.
*/

#include "config.h" // IWYU pragma: keep

#include <zone.h>
#include <sys/proc.h>
#include <libproc.h>

#include "Settings.h"


typedef struct SolarisProcess_ {
   Process    super;
   zoneid_t   zoneid;
   char*      zname;
   taskid_t   taskid;
   projid_t   projid;
   poolid_t   poolid;
   ctid_t     contid;
   pid_t      realpid;
   pid_t      realppid;
   pid_t      lwpid;
} SolarisProcess;

extern const ProcessClass SolarisProcess_class;

extern const ProcessFieldData Process_fields[LAST_PROCESSFIELD];

Process* SolarisProcess_new(const Settings* settings);

void Process_delete(Object* cast);

#endif
