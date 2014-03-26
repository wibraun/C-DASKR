
#include <stdio.h>
#include <stdlib.h>

#include "ddaskr_types.h"

/* Table of constant values */

#define c_b3 1.
static integer c__1 = 1;
static integer c__0 = 0;
static integer c_false = _FALSE_;
static integer c__2 = 2;
static integer c_true = _TRUE_;

/* DECK D1MACH */
real_number d1mach_(integer *idummy)
{
    /* System generated locals */
    real_number ret_val;

    /* Local variables */
    static real_number u, comp;

/* ***BEGIN PROLOGUE  D1MACH */
/* ***PURPOSE  Compute the unit roundoff of the machine. */
/* ***CATEGORY  R1 */
/* ***TYPE      DOUBLE PRECISION (R1MACH-S, D1MACH-D) */
/* ***KEYWORDS  MACHINE CONSTANTS */
/* ***AUTHOR  Hindmarsh, Alan C., (LLNL) */
/* ***DESCRIPTION */
/* *Usage: */
/*        DOUBLE PRECISION  A, D1MACH */
/*        A = D1MACH(idummy)  [The argument is ignored.] */

/* *Function Return Values: */
/*     A : the unit roundoff of the machine. */

/* *Description: */
/*     The unit roundoff is defined as the smallest positive machine */
/*     number u such that  1.0 + u .ne. 1.0.  This is computed by D1MACH */
/*     in a machine-independent manner. */

/* ***REFERENCES  (NONE) */
/* ***ROUTINES CALLED  DUMSUM */
/* ***REVISION HISTORY  (YYYYMMDD) */
/*   19930216  DATE WRITTEN */
/*   19930818  Added SLATEC-format prologue.  (FNF) */
/*   20030707  Added DUMSUM to force normal storage of COMP.  (ACH) */
/* ***END PROLOGUE  D1MACH */

/* ***FIRST EXECUTABLE STATEMENT  D1MACH */
    u = 1.;
L10:
    u *= .5;
    comp = c_b3 + u;
    if (comp != 1.) {
	goto L10;
    }
    ret_val = u * 2.;
    return ret_val;
/* ----------------------- End of Function D1MACH ------------------------ */
} /* d1mach_ */

/* DECK XERRWD */
/* Subroutine */ int xerrwd_(char *msg, integer *nmes, integer *nerr, integer
	*level, integer *ni, integer *i1, integer *i2, integer *nr,
	real_number *r1, real_number *r2, integer msg_len)
{
    /* Format strings */
    static char fmt_20[] = "      In above message,  I1 = %d\n";
    static char fmt_30[] = "      In above message,  I1 = %d   I2 = %d\n";
    static char fmt_40[] = "      In above message,  R1 = %21.13E\n";
    static char fmt_50[] = "      In above,  R1 = %21.13E   R2 = %21.13E\n";
    /* Local variables */
    extern integer ixsav_(integer *, integer *, integer *);
    static integer lunit, mesflg;

    char* ptr_msg;


/* ***BEGIN PROLOGUE  XERRWD */
/* ***SUBSIDIARY */
/* ***PURPOSE  Write error message with values. */
/* ***LIBRARY   MATHLIB */
/* ***CATEGORY  R3C */
/* ***TYPE      DOUBLE PRECISION (XERRWV-S, XERRWD-D) */
/* ***AUTHOR  Hindmarsh, Alan C., (LLNL) */
/* ***DESCRIPTION */

/*  Subroutines XERRWD, XSETF, XSETUN, and the function routine IXSAV, */
/*  as given here, constitute a simplified version of the SLATEC error */
/*  handling package. */

/*  All arguments are input arguments. */

/*  MSG    = The message (character array). */
/*  NMES   = The length of MSG (number of characters). */
/*  NERR   = The error number (not used). */
/*  LEVEL  = The error level.. */
/*           0 or 1 means recoverable (control returns to caller). */
/*           2 means fatal (run is aborted--see note below). */
/*  NI     = Number of integers (0, 1, or 2) to be printed with message. */
/*  I1,I2  = Integers to be printed, depending on NI. */
/*  NR     = Number of reals (0, 1, or 2) to be printed with message. */
/*  R1,R2  = Reals to be printed, depending on NR. */

/*  Note..  this routine is machine-dependent and specialized for use */
/*  in limited context, in the following ways.. */
/*  1. The argument MSG is assumed to be of type CHARACTER, and */
/*     the message is printed with a format of (1X,A). */
/*  2. The message is assumed to take only one line. */
/*     Multi-line messages are generated by repeated calls. */
/*  3. If LEVEL = 2, control passes to the statement   STOP */
/*     to abort the run.  This statement may be machine-dependent. */
/*  4. R1 and R2 are assumed to be in double precision and are printed */
/*     in D21.13 format. */

/* ***ROUTINES CALLED  IXSAV */
/* ***REVISION HISTORY  (YYMMDD) */
/*   920831  DATE WRITTEN */
/*   921118  Replaced MFLGSV/LUNSAV by IXSAV. (ACH) */
/*   930329  Modified prologue to SLATEC format. (FNF) */
/*   930407  Changed MSG from CHARACTER*1 array to variable. (FNF) */
/*   930922  Minor cosmetic change. (FNF) */
/* ***END PROLOGUE  XERRWD */

/* *Internal Notes: */

/* For a different default logical unit number, IXSAV (or a subsidiary */
/* routine that it calls) will need to be modified. */
/* For a different run-abort command, change the statement following */
/* statement 100 at the end. */
/* ----------------------------------------------------------------------- */
/* Subroutines called by XERRWD.. None */
/* Function routine called by XERRWD.. IXSAV */
/* ----------------------------------------------------------------------- */
/* **End */

/*  Declare arguments. */


/*  Declare local variables. */


/*  Get logical unit number and message print flag. */

/* ***FIRST EXECUTABLE STATEMENT  XERRWD */
    lunit = ixsav_(&c__1, &c__0, &c_false);
    mesflg = ixsav_(&c__2, &c__0, &c_false);
    if (mesflg == 0) {
  goto L100;
    }

/*  Write the message. */

    ptr_msg = (char*) malloc(msg_len*sizeof(char));
    snprintf(ptr_msg, msg_len, "%s", msg);
    puts(ptr_msg);
    free(ptr_msg);

    if (*ni == 1) {
      printf(fmt_20, *i1);
    }
    if (*ni == 2) {
      printf(fmt_30, *i1, *i2);
    }
    if (*nr == 1) {
      printf(fmt_40, *r1);
    }
    if (*nr == 2) {
	  printf(fmt_50, *r1, *r2);
    }

/*  Abort the run if LEVEL = 2. */

L100:
    if (*level != 2) {
      return 0;
    }
    exit(0);

/* ----------------------- End of Subroutine XERRWD ---------------------- */
    return 0;
} /* xerrwd_ */

/* DECK XSETF */
/* Subroutine */ int xsetf_(integer *mflag)
{
    static integer junk;
    extern integer ixsav_(integer *, integer *, integer *);

/* ***BEGIN PROLOGUE  XSETF */
/* ***PURPOSE  Reset the error print control flag. */
/* ***LIBRARY   MATHLIB */
/* ***CATEGORY  R3A */
/* ***TYPE      ALL (XSETF-A) */
/* ***KEYWORDS  ERROR CONTROL */
/* ***AUTHOR  Hindmarsh, Alan C., (LLNL) */
/* ***DESCRIPTION */

/*   XSETF sets the error print control flag to MFLAG: */
/*      MFLAG=1 means print all messages (the default). */
/*      MFLAG=0 means no printing. */

/* ***SEE ALSO  XERMSG, XERRWD, XERRWV */
/* ***REFERENCES  (NONE) */
/* ***ROUTINES CALLED  IXSAV */
/* ***REVISION HISTORY  (YYMMDD) */
/*   921118  DATE WRITTEN */
/*   930329  Added SLATEC format prologue. (FNF) */
/*   930407  Corrected SEE ALSO section. (FNF) */
/*   930922  Made user-callable, and other cosmetic changes. (FNF) */
/* ***END PROLOGUE  XSETF */

/* Subroutines called by XSETF.. None */
/* Function routine called by XSETF.. IXSAV */
/* ----------------------------------------------------------------------- */
/* **End */

/* ***FIRST EXECUTABLE STATEMENT  XSETF */
    if (*mflag == 0 || *mflag == 1) {
	junk = ixsav_(&c__2, mflag, &c_true);
    }
    return 0;
/* ----------------------- End of Subroutine XSETF ----------------------- */
} /* xsetf_ */

/* DECK XSETUN */
/* Subroutine */ int xsetun_(integer *lun)
{
    static integer junk;
    extern integer ixsav_(integer *, integer *, integer *);

/* ***BEGIN PROLOGUE  XSETUN */
/* ***PURPOSE  Reset the logical unit number for error messages. */
/* ***LIBRARY   MATHLIB */
/* ***CATEGORY  R3B */
/* ***TYPE      ALL (XSETUN-A) */
/* ***KEYWORDS  ERROR CONTROL */
/* ***DESCRIPTION */

/*   XSETUN sets the logical unit number for error messages to LUN. */

/* ***AUTHOR  Hindmarsh, Alan C., (LLNL) */
/* ***SEE ALSO  XERMSG, XERRWD, XERRWV */
/* ***REFERENCES  (NONE) */
/* ***ROUTINES CALLED  IXSAV */
/* ***REVISION HISTORY  (YYMMDD) */
/*   921118  DATE WRITTEN */
/*   930329  Added SLATEC format prologue. (FNF) */
/*   930407  Corrected SEE ALSO section. (FNF) */
/*   930922  Made user-callable, and other cosmetic changes. (FNF) */
/* ***END PROLOGUE  XSETUN */

/* Subroutines called by XSETUN.. None */
/* Function routine called by XSETUN.. IXSAV */
/* ----------------------------------------------------------------------- */
/* **End */

/* ***FIRST EXECUTABLE STATEMENT  XSETUN */
    if (*lun > 0) {
	junk = ixsav_(&c__1, lun, &c_true);
    }
    return 0;
/* ----------------------- End of Subroutine XSETUN ---------------------- */
} /* xsetun_ */

/* DECK IXSAV */
integer ixsav_(integer *ipar, integer *ivalue, integer *iset)
{
    /* Initialized data */

    static integer lunit = -1;
    static integer lundef = 6;
    static integer mesflg = 1;

    /* System generated locals */
    integer ret_val;

/* ***BEGIN PROLOGUE  IXSAV */
/* ***SUBSIDIARY */
/* ***PURPOSE  Save and recall error message control parameters. */
/* ***LIBRARY   MATHLIB */
/* ***CATEGORY  R3C */
/* ***TYPE      ALL (IXSAV-A) */
/* ***AUTHOR  Hindmarsh, Alan C., (LLNL) */
/* ***DESCRIPTION */

/*  IXSAV saves and recalls one of two error message parameters: */
/*    LUNIT, the logical unit number to which messages are printed, and */
/*    MESFLG, the message print flag. */
/*  This is a modification of the SLATEC library routine J4SAVE. */

/*  Saved local variables.. */
/*   LUNIT  = Logical unit number for messages. */
/*   LUNDEF = Default logical unit number, data-loaded to 6 below */
/*            (may be machine-dependent). */
/*   MESFLG = Print control flag.. */
/*            1 means print all messages (the default). */
/*            0 means no printing. */

/*  On input.. */
/*    IPAR   = Parameter indicator (1 for LUNIT, 2 for MESFLG). */
/*    IVALUE = The value to be set for the parameter, if ISET = .TRUE. */
/*    ISET   = Logical flag to indicate whether to read or write. */
/*             If ISET = .TRUE., the parameter will be given */
/*             the value IVALUE.  If ISET = .FALSE., the parameter */
/*             will be unchanged, and IVALUE is a dummy argument. */

/*  On return.. */
/*    IXSAV = The (old) value of the parameter. */

/* ***SEE ALSO  XERMSG, XERRWD, XERRWV */
/* ***ROUTINES CALLED  NONE */
/* ***REVISION HISTORY  (YYMMDD) */
/*   921118  DATE WRITTEN */
/*   930329  Modified prologue to SLATEC format. (FNF) */
/*   941025  Minor modification re default unit number. (ACH) */
/* ***END PROLOGUE  IXSAV */

/* **End */
/* ----------------------------------------------------------------------- */
/* ----------------------------------------------------------------------- */
/* The following Fortran-77 declaration is to cause the values of the */
/* listed (local) variables to be saved between calls to this routine. */
/* ----------------------------------------------------------------------- */

/* ***FIRST EXECUTABLE STATEMENT  IXSAV */
    if (*ipar == 1) {
	if (lunit == -1) {
	    lunit = lundef;
	}
	ret_val = lunit;
	if (*iset) {
	    lunit = *ivalue;
	}
    }

    if (*ipar == 2) {
	ret_val = mesflg;
	if (*iset) {
	    mesflg = *ivalue;
	}
    }

    return ret_val;
/* ----------------------- End of Function IXSAV ------------------------- */
} /* ixsav_ */

/* DECK S_COPY */
void str_copy(char *a, char *b, integer la, integer lb)
{
	char *aend, *bend;

	aend = a + la;

	if(la <= lb){
		if (a <= b || a >= b + la){
			while(a < aend){
				*a++ = *b++;
			}
		} else{
			for(b += la; a < aend; ){
				*--aend = *--b;
			}
		}
	} else {
		bend = b + lb;
		if (a <= b || a >= bend){
			while(b < bend){
				*a++ = *b++;
			}
		} else {
			a += lb;
			while(b < bend){
				*--a = *--bend;
			}
			a += lb;
		}
		while(a < aend){
			*a++ = ' ';
		}
	}
/* ----------------------- End of Function s_copy ------------------------- */
} /* s_copy */
