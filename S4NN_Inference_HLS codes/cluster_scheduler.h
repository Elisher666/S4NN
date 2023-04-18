#ifndef _CLST_SCD_HEADER_
#define _CLST_SCD_HEADER_

#include "global_vars.h"
#include "cluster_0.h"
#include "cluster_1.h"
#include "cluster_2.h"
#include "cluster_3.h"

void InitClstFlag(ap_uint<16> MaskClst, struct sClstInputPkg *ClstInputPkg, _reg_timestep GlobalTimeStep);

#endif