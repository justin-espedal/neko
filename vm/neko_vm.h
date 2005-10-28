/* ************************************************************************ */
/*																			*/
/*  Neko Virtual Machine													*/
/*  Copyright (c)2005 Nicolas Cannasse										*/
/*																			*/
/*  This program is free software; you can redistribute it and/or modify	*/
/*  it under the terms of the GNU General Public License as published by	*/
/*  the Free Software Foundation; either version 2 of the License, or		*/
/*  (at your option) any later version.										*/
/*																			*/
/*  This program is distributed in the hope that it will be useful,			*/
/*  but WITHOUT ANY WARRANTY; without even the implied warranty of			*/
/*  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the			*/
/*  GNU General Public License for more details.							*/
/*																			*/
/*  You should have received a copy of the GNU General Public License		*/
/*  along with this program; if not, write to the Free Software				*/
/*  Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA 02111-1307 USA */
/*																			*/
/* ************************************************************************ */
#ifndef _NEKO_VM_H
#define _NEKO_VM_H
#include "neko.h"

typedef void (*neko_printer)( const char *data, int size );

typedef struct {
	neko_printer printer;
	void *custom;
	const char **args;
	int nargs;
} neko_params;

typedef struct _neko_vm neko_vm;

C_FUNCTION_BEGIN

EXTERN void neko_global_init();
EXTERN void neko_global_free();
EXTERN void neko_gc_major();
EXTERN void neko_gc_loop();

EXTERN neko_vm *neko_vm_alloc( neko_params *p );
EXTERN neko_vm *neko_vm_current();
EXTERN value neko_exc_stack( neko_vm *vm );
EXTERN value neko_call_stack( neko_vm *vm );
EXTERN void *neko_vm_custom( neko_vm *vm );
EXTERN void neko_vm_execute( neko_vm *vm, void *module );
EXTERN void neko_vm_select( neko_vm *vm );
EXTERN void neko_clean_thread();
EXTERN value neko_default_loader();

C_FUNCTION_END

#endif
/* ************************************************************************ */