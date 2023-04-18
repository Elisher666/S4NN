#include "PE.h"

void SchedulePE(volatile ap_int<32> *ddr_0,
                struct sPEInputPkg *PEInputPkg,
                struct sOutputMemPkg *OutputMemPkg,
                struct sMsgPkg *InputMsgPkg,
                struct sRegFileWidePkg *RegFilePkg,
                _reg_64b *RegFileWidePkg_0,

                _weight_mem *WeightMemPE_0,

                _potential_mem *PotenMemPE_0,

                int weight_base_addr
)
{
    struct sMsgPkg MsgPkg = *InputMsgPkg;

    _mask_pe MaskPE;
    MaskPE = MsgPkg.immb;

    if(MaskPE[0]==1)
    {
        PE<0>(ddr_0, PEInputPkg+0, OutputMemPkg, InputMsgPkg, RegFilePkg, RegFileWidePkg_0, WeightMemPE_0, PotenMemPE_0,weight_base_addr);
    }


}
