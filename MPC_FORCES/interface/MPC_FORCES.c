/*
 This is an interface for MPC_FORCES that can be used to call the solver generated by FORCES PRO
*/ 

#include "../include/MPC_FORCES.h"
#include "../include/internal_MPC_FORCES_1.h"
#include <stdio.h>

/* For Visual Studio 2015 Compatibility */
#if (_MSC_VER >= 1900)
FILE _iob[3];
FILE * __cdecl __iob_func(void)
{
    _iob[0] = *stdin;
    _iob[1] = *stdout;
    _iob[2] = *stderr;
    return _iob;
}
#endif

extern solver_int32_default MPC_FORCES_solve(MPC_FORCES_params *params, MPC_FORCES_output *output, MPC_FORCES_info *info, FILE *fs) 
{
	/* Some memory */
	static internal_MPC_FORCES_1_params params_1;
	static internal_MPC_FORCES_1_output output_1;
	static internal_MPC_FORCES_1_info info_1;

	solver_int32_default exitflag;
	/* define variables */
	solver_int32_default i;
	/* SOLVER 1 --------------------------------------------------------*/
	/*Assigning parameter values of solver #1*/
	/*Assigning parameter values of solver #1*/
	params_1.p_1[0] = (0.000557591106497401 * params->t_init[2]);
	params_1.p_1[0] += (0.000327207658357976 * params->t_init[1]);
	params_1.p_1[0] += (0.994840556522850306 * params->t_init[0]);
	params_1.p_1[1] = (0.010208283552879564 * params->t_init[2]);
	params_1.p_1[1] += (0.986260434519327100 * params->t_init[1]);
	params_1.p_1[1] += (0.003523774782316664 * params->t_init[0]);
	params_1.p_1[2] = (0.951321748581923754 * params->t_init[2]);
	params_1.p_1[2] += (0.030624850658638680 * params->t_init[1]);
	params_1.p_1[2] += (0.018014481902223718 * params->t_init[0]);

	/* call solver #1 */
	exitflag = internal_MPC_FORCES_1_solve(&params_1, &output_1, &info_1, fs );

	/* iterations */
	info->it = info_1.it;

	/* iterations to optimality (branch and bound) */
	info->it2opt = info_1.it2opt;

	/* res_eq */
	info->res_eq = info_1.res_eq;

	/* res_ineq */
	info->res_ineq = info_1.res_ineq;

	/* pobj */
	info->pobj = info_1.pobj;

	/* dobj */
	info->dobj = info_1.dobj;

	/* dgap */
	info->dgap = info_1.dgap;

	/* rdgap */
	info->rdgap = info_1.rdgap;

	/* mu */
	info->mu = info_1.mu;

	/* mu_aff */
	info->mu_aff = info_1.mu_aff;

	/* sigma */
	info->sigma = info_1.sigma;

	/* lsit_aff */

	info->lsit_aff = info_1.lsit_aff;

	/* lsit_cc */
	info->lsit_cc = info_1.lsit_cc;

	/* step_aff */
	info->step_aff = info_1.step_aff;

	/* step_cc */
	info->step_cc = info_1.step_cc;

	/* solver time */
	info->solvetime = info_1.solvetime;


	/* OUTPUTS -----------------------------------------------------------*/
	/*Build outputs*/
	output->p0[0] = (1.000000000000000000 * output_1.o_1[0]);

	output->p0[1] = (1.000000000000000000 * output_1.o_2[0]);

	output->p0[2] = (1.000000000000000000 * output_1.o_3[0]);

	return exitflag;
}