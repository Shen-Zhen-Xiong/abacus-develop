#include "RELAX_cell.h"
#include "local_orbital_ions.h"


RELAX_cell::RELAX_cell(){}

RELAX_cell::~RELAX_cell(){}


void RELAX_cell::opt_cell()
{
	Local_Orbital_Ions ions;
	ions.opt_ions();
	
	return;
}

