#include <iostream>
#include "ap_int.h"
#include "global_vars.h"

//int SnnAcc(volatile ap_int<32> *ddr_0, int idx_ret, int idx_spkm, int test, int in_mem_offset_0, int in_mem_length_0, int *clsf_result_0);
int SnnAcc(volatile ap_int<32> *ddr_0, int image_base_addr, int weight_base_addr, int idx_img);

int main() {

    #ifdef TEST_LOG_PRINT
    std::cout << "Hello, World!" << std::endl;
    #endif

    int rev;
    printf("Test begin\n");

//    ap_int<32> *ddr_0;
//    int idx_ret;
//    int idx_spkm;
//    int test;
//    int in_mem_offset_0;
//    int in_mem_length_0;
//    int *clsf_result_0;
    ap_int<32> *ddr_0;
    int image_base_addr;
    int weight_base_addr;
    int idx_img;

    for(idx_img=0;idx_img<2;idx_img++) {
        rev = SnnAcc(ddr_0, 0, 0, idx_img);
        printf("rev: %d\r\n", rev);
    }
    return 0;
}
