#include "weight_init.h"

void InitWeightMem(volatile ap_int<32> *ddr_0,
                   _weight_mem *WeightMemPE_0,
                   ap_uint<CLST_ID_WIDTH> ClstID,
                   int weight_base_addr
                   )
{
#ifndef TEST_WEIGHT_LOAD_PSEUDO
    _reg_64b burst_length;	//32-bit
	_reg_64b src_offset_0;	//32-bit
	_reg_64b src_offset_1;	//32-bit
	_reg_64b src_offset_2;	//32-bit
	_reg_64b src_offset_3;	//32-bit


	/******************************* 1st hidden layer **********************************/

    if(ClstID==0)
    {
        /*need calculate before use*/
    	burst_length = 75;
    	src_offset_0 = 0;
    	src_offset_1 = 225;
    	src_offset_2 = 450;
    	src_offset_3 = 675;

        memcpy(WeightMemPE_0, (const ap_int<32> *)(ddr_0 + weight_base_addr / 4 + src_offset_0), burst_length * sizeof(ap_int<32>));

    }


	/******************************* output layer **********************************/
    if(ClstID==1)
    {
    	burst_length = 1024;
    	src_offset_0 = 77700;
    	src_offset_1 = 78724;
    	src_offset_2 = 79748;
    	src_offset_3 = 80772;

        memcpy(WeightMemPE_0, (const ap_int<32> *)(ddr_0 + weight_base_addr / 4 + src_offset_0), burst_length * sizeof(ap_int<32>));

    }



#endif

#ifdef TEST_WEIGHT_LOAD_PSEUDO

#endif

}
