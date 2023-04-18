#include "potential_init.h"

void InitPotenMem(_potential_mem *PotenMemPE_0,
                  ap_uint<CLST_ID_WIDTH> ClstID)
{
    int idxPotenMem;


    /********************* snn layer 1 *************************/

    if (ClstID==0)
    {
        for (idxPotenMem=0; idxPotenMem<100; idxPotenMem++)
        {
                PotenMemPE_0[idxPotenMem](63,48) = idxPotenMem;     //initialize neuron ID
                PotenMemPE_0[idxPotenMem](47,0) = 0;     //initialize potential as zero
        }
    }

    if (ClstID==1)
    {
        for (idxPotenMem=0; idxPotenMem<100; idxPotenMem++)
        {
                PotenMemPE_0[idxPotenMem](63,48) = idxPotenMem+100;     //initialize neuron ID
                PotenMemPE_0[idxPotenMem](47,0) = 0;     //initialize potential as zero
        }
    }
    if (ClstID==2)
    {
        for (idxPotenMem=0; idxPotenMem<100; idxPotenMem++)
        {
            PotenMemPE_0[idxPotenMem](63,48) = idxPotenMem+200;     //initialize neuron ID
            PotenMemPE_0[idxPotenMem](47,0) = 0;     //initialize potential as zero
        }
    }
    if (ClstID==3)
    {
        for (idxPotenMem=0; idxPotenMem<100; idxPotenMem++)
        {
            PotenMemPE_0[idxPotenMem](63,48) = idxPotenMem+300;     //initialize neuron ID
            PotenMemPE_0[idxPotenMem](47,0) = 0;     //initialize potential as zero
        }
    }

    /********************* snn layer 2 *************************/
    if (ClstID==4)
    {
        for (idxPotenMem=0; idxPotenMem<10; idxPotenMem++)
        {
            PotenMemPE_0[idxPotenMem](63,48) = idxPotenMem;     //initialize neuron ID
            PotenMemPE_0[idxPotenMem](47,0) = 0;     //initialize potential as zero
        }
    }
}
