#ifndef _EXE_HEADER_
#define _EXE_HEADER_

#include "global_vars.h"
#include "PE.h"
#include "ALU.h"
#include "spike_scheduler.h"
#include "decoder.h"
#include "register_file.h"
#include "output_mem.h"
#include "weight_init.h"
#include "potential_init.h"

_idx_instr_mem executer(
        volatile ap_int<32> *ddr_0,
        _idx_instr_mem *IdxInstr,
        ap_uint<1> *ClusterDone,
        ap_uint<1> *ClusterSync,
        struct sClstInputPkg *ClstInputPkg,
        struct sSpikeMemPkg *SpikeMemPkg,
        struct sPEInputPkg *PEInputPkg,
        struct sOutputMemPkg *OutputMemPkg,
        struct sMsgPkg *MsgPkg,
        struct sRegFileWidePkg *RegFilePkg,
        _reg_64b *RegFileWidePkg_0,

        _weight_mem *WeightMemPE_0,

        _potential_mem *PotenMemPE_0,
        int weight_base_addr
);

#endif
