
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

/* Local headers */
#include "ablibs.h"
#include "abimport.h"
#include "abwidgets.h"
#include "abdefine.h"
#include "abevents.h"
#include "ablinks.h"
#include "abvars.h"
#include "pid.h"

using namespace pid;

int
main ( int argc, char *argv[] )
{
	pid_info p;
	p.FindIfNotFinf(argv[0]);

	_Ap_.Ap_winstate = 0;

	/* AppBuilder Initialization */
	ApInitialize( argc, argv, &AbContext );

	/* Display main window */
	ApLinkWindow( NULL, &AbApplLinks[0], NULL );

	/* Loop until user quits application */
	PtMainLoop( );
	PtExit( 0 );

	return 0;
	}

static const ApClassTab_t ClassTable[] = {
	{ "PtWindow", &PtWindow },
	{ "PtText", &PtText },
	{ "PtTimer", &PtTimer },
	{ "PtButton", &PtButton },
	{ NULL, NULL }
	};

ApContext_t AbContext = { ClassTable, 1, AbWidgets };


