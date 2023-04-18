#ifndef _PE_HEADER_
#define _PE_HEADER_

#include "global_vars.h"
#include "ALU.h"
#include "register_file.h"
#include "output_mem.h"

void SchedulePE(volatile ap_int<32> *ddr_0,
                struct sPEInputPkg *PEInputPkg,
                struct sOutputMemPkg *OutputMemPkg,
                struct sMsgPkg *InputMsgPkg,
                struct sRegFileWidePkg *RegFilePkg,
                _reg_64b *RegFileWidePkg_0,

                _weight_mem *WeightMemPE_0,

                _potential_mem *PotenMemPE_0,

                int weight_base_addr
);



template<int n>
void PE(volatile ap_int<32> *ddr_0,
        struct sPEInputPkg *PEInputPkg,
        struct sOutputMemPkg *OutputMemPkg,
        struct sMsgPkg *InputMsgPkg,
        struct sRegFileWidePkg *RegFilePkg,
        _reg_64b *RegFileWidePkg,
        _weight_mem *WeightMemPE,
        _potential_mem *PotenMemPE,
		int weight_base_addr)
{
#ifdef TEST_LDW_PSEUDO
    FILE *fp = NULL;
    int i;
#endif

    struct sMsgPkg MsgPkg = *InputMsgPkg;

    _reg_64b TempReg_1;
    _reg_64b TempReg_2;
    _reg_64b TempReg_3;
    _reg_64b TempReg_4;

    _reg_32b TempReg_1_32b;

    _reg_64b_s TempReg_1s;
    _reg_64b src_offset_0;
    _reg_64b src_offset_1;
    _reg_64b src_offset_2;
    _reg_64b src_offset_3;
    _reg_64b src_offset_4;

    src_offset_0=0;
    src_offset_1=78400;
    src_offset_2=156800;
    src_offset_3=235200;
    src_offset_4=313600;

    switch (InputMsgPkg->opcode)
    {
        case LDW:
            ReadRegFileWide(RegFileWidePkg, MsgPkg.rega, &TempReg_1);  //weight mem offset
            ReadRegFileWide(RegFileWidePkg, MsgPkg.regb, &TempReg_2);  //DDR
            ReadRegFileWide(RegFileWidePkg, MsgPkg.regc, &TempReg_3);  //variety for loop


#ifndef TEST_LDW_PSEUDO
            if((PEInputPkg->ClstID)==0)
                       {
						   memcpy(WeightMemPE + TempReg_1, (const ap_int<32> *)(ddr_0 + weight_base_addr / 4 + TempReg_2+src_offset_0), TempReg_3 * sizeof(ap_int<32>));
                       }

            if((PEInputPkg->ClstID)==1)
                       {
						   memcpy(WeightMemPE + TempReg_1, (const ap_int<32> *)(ddr_0 + weight_base_addr / 4 + TempReg_2+src_offset_1), TempReg_3 * sizeof(ap_int<32>));
                       }

            if((PEInputPkg->ClstID)==2)
                       {
						   memcpy(WeightMemPE + TempReg_1, (const ap_int<32> *)(ddr_0 + weight_base_addr / 4 + TempReg_2+src_offset_2), TempReg_3 * sizeof(ap_int<32>));
                       }

            if((PEInputPkg->ClstID)==3)
                       {
						   memcpy(WeightMemPE + TempReg_1, (const ap_int<32> *)(ddr_0 + weight_base_addr / 4 + TempReg_2+src_offset_3), TempReg_3 * sizeof(ap_int<32>));
                       }

            if((PEInputPkg->ClstID)==4)
                       {
						   memcpy(WeightMemPE + TempReg_1, (const ap_int<32> *)(ddr_0 + weight_base_addr / 4 + TempReg_2+src_offset_4), TempReg_3 * sizeof(ap_int<32>));
                       }

        //    memcpy(WeightMemPE + TempReg_1, (const ap_int<32> *)(ddr_0 + weight_base_addr / 4 + TempReg_2), TempReg_3 * sizeof(ap_int<32>));
#endif

#ifdef TEST_LDW_PSEUDO

//            fp = fopen("D:\\5003ProjSTDP\\Allproj\\S4NN\\S4NN-master python\\S4NN-master\\weightdata\\s4nn_weight_4c_hidden.bin", "rb");
//            fseek( fp, (long int)(TempReg_2*4 + PEInputPkg->DDR_SEG_OFFSET), SEEK_SET );

            if((PEInputPkg->ClstID)==0)
            {
                for(i = 0;i < TempReg_3;i++)
                {
                    //fscanf(fp, "%d", &weight_mem_PE1[reg_ldw_dest_addr+i]);
                    fp = fopen("D:\\5003ProjSTDP\\ClionS4NN\\S4NN_V2\\EE5003\\s4nn_weight_c1.bin", "rb");
                    fseek( fp, (long int)(TempReg_2*4 + i*4 + PEInputPkg->DDR_SEG_OFFSET), SEEK_SET );
                    fread((WeightMemPE + TempReg_1 + i), 1, 4, fp);
                    fclose(fp);
                }
            }

            else if((PEInputPkg->ClstID)==1) {
                for (i = 0; i < TempReg_3; i++) {
                    //fscanf(fp, "%d", &weight_mem_PE1[reg_ldw_dest_addr+i]);
                    fp = fopen("D:\\5003ProjSTDP\\ClionS4NN\\S4NN_V2\\EE5003\\s4nn_weight_c2.bin", "rb");
                    fseek(fp, (long int) ((TempReg_2) * 4 + i * 4 + PEInputPkg->DDR_SEG_OFFSET), SEEK_SET);
                    fread((WeightMemPE + TempReg_1 + i), 1, 4, fp);
                    fclose(fp);
                }
            }
            else if((PEInputPkg->ClstID)==2) {
                for (i = 0; i < TempReg_3; i++) {
                    //fscanf(fp, "%d", &weight_mem_PE1[reg_ldw_dest_addr+i]);
                    fp = fopen("D:\\5003ProjSTDP\\ClionS4NN\\S4NN_V2\\EE5003\\s4nn_weight_c3.bin", "rb");
                    fseek(fp, (long int) ((TempReg_2) * 4 + i * 4 + PEInputPkg->DDR_SEG_OFFSET), SEEK_SET);
                    fread((WeightMemPE + TempReg_1 + i), 1, 4, fp);
                    fclose(fp);
                }
            }
            else if((PEInputPkg->ClstID)==3) {
                for (i = 0; i < TempReg_3; i++) {
                    //fscanf(fp, "%d", &weight_mem_PE1[reg_ldw_dest_addr+i]);
                    fp = fopen("D:\\5003ProjSTDP\\ClionS4NN\\S4NN_V2\\EE5003\\s4nn_weight_c4.bin", "rb");
                    fseek(fp, (long int) ((TempReg_2) * 4 + i * 4 + PEInputPkg->DDR_SEG_OFFSET), SEEK_SET);
                    fread((WeightMemPE + TempReg_1 + i), 1, 4, fp);
                    fclose(fp);
                }
            }
            else if((PEInputPkg->ClstID)==4) {
                for (i = 0; i < TempReg_3; i++) {
                    //fscanf(fp, "%d", &weight_mem_PE1[reg_ldw_dest_addr+i]);
                    fp = fopen("D:\\5003ProjSTDP\\ClionS4NN\\S4NN_V2\\EE5003\\s4nn_weight_out.bin", "rb");
                    fseek(fp, (long int) ((TempReg_2) * 4 + i * 4 + PEInputPkg->DDR_SEG_OFFSET), SEEK_SET);
                    fread((WeightMemPE + TempReg_1 + i), 1, 4, fp);
                    fclose(fp);
                }
            }
//            else if((PEInputPkg->ClstID)==1)
//            {
//                fp = fopen("C:\\Users\\wangy\\Workspace\\NNWeight\\v3\\nn_c1.bin", "rb");
//                fseek( fp, TempReg_2*4 + PEInputPkg->DDR_SEG_OFFSET_1, SEEK_SET );
//            }
//            else if((PEInputPkg->ClstID)==2)
//            {
//                fp = fopen("C:\\Users\\wangy\\Workspace\\NNWeight\\v3\\nn_c2.bin", "rb");
//                fseek( fp, TempReg_2*4 + PEInputPkg->DDR_SEG_OFFSET_2, SEEK_SET );
//            }


//            for(i = 0;i < TempReg_3;i++)
//            {
//                //fscanf(fp, "%d", &weight_mem_PE1[reg_ldw_dest_addr+i]);
//                fread((WeightMemPE + TempReg_1 + i), 1, 4, fp);
//                //printf("%ld\n",WeightMemPE + TempReg_1 + i);
//            }
            fclose(fp);
#endif

            break;

        case WDW:
            ReadRegFileWide(RegFileWidePkg, MsgPkg.rega, &TempReg_1);
            ReadRegFileWide(RegFileWidePkg, MsgPkg.regb, &TempReg_2);
            ReadRegFileWide(RegFileWidePkg, MsgPkg.regc, &TempReg_3);
            memcpy((ap_int<32> *)(ddr_0 + weight_base_addr / 4 + TempReg_1), WeightMemPE+ TempReg_2, TempReg_3 * sizeof(ap_int<32>));

            break;

        case MOV:
            if((MsgPkg.flagp == 0)&&(MsgPkg.flagc == 1))
            {
                ReadRegFileWide(RegFileWidePkg, MsgPkg.regb, &TempReg_1);
                InputMsgPkg->rcpvalue = 0;
                InputMsgPkg->rcpvalue = TempReg_1;
            }
            else if((MsgPkg.flagp == 1)&&(MsgPkg.flagc == 0))
            {
                if(MsgPkg.flagi == 0)
                {
                    TempReg_1 = 0;
                    TempReg_1 = MsgPkg.rcpvalue;

                    WriteRegFileWide(RegFileWidePkg, MsgPkg.rega, &TempReg_1);
                }
                else
                {
                    if((MsgPkg.flags == 1)&&(MsgPkg.imma[15]==1))
                    {TempReg_1 = ALL_HIGH_64B;}
                    else
                    {TempReg_1 = ALL_LOW_64B;}

                    TempReg_1(15,0)=MsgPkg.imma;
                }
                WriteRegFileWide(RegFileWidePkg, MsgPkg.rega, &TempReg_1);
            }
            else if((MsgPkg.flagp == 1)&&(MsgPkg.flagc == 1))
            {
                ReadRegFileWide(RegFileWidePkg, MsgPkg.regb, &TempReg_1);
                WriteRegFileWide(RegFileWidePkg, MsgPkg.rega, &TempReg_1);
            }

#ifdef TEST_LOG_PRINT
        printf("ALU.PE.U--Param1: 0x%x;. \n", (unsigned int)TempReg_1);
#endif
            break;

        case AND:
            ReadRegFileWide(RegFileWidePkg, MsgPkg.regb, &TempReg_1);
            if(MsgPkg.flagi == 0)
            {
                ReadRegFileWide(RegFileWidePkg, MsgPkg.regc, &TempReg_2);
            }
            else
            {
                if((MsgPkg.flagfh==0)&&(MsgPkg.flagfl==0))
                {
                    TempReg_2=ALL_HIGH_64B;
                    TempReg_2(15,0)=MsgPkg.imma(15,0);
                }

                if((MsgPkg.flagfh==0)&&(MsgPkg.flagfl==1))
                {
                    TempReg_2=ALL_HIGH_64B;
                    TempReg_2(31,16)=MsgPkg.imma(15,0);
                }

                if((MsgPkg.flagfh==1)&&(MsgPkg.flagfl==0))
                {
                    TempReg_2=ALL_HIGH_64B;
                    TempReg_2(47,32)=MsgPkg.imma(15,0);
                }

                if((MsgPkg.flagfh==1)&&(MsgPkg.flagfl==1))
                {
                    TempReg_2=ALL_HIGH_64B;
                    TempReg_2(63,48)=MsgPkg.imma(15,0);
                }
            }
            TempReg_3 = ALUPE(TempReg_1, TempReg_2, ALU_AND);
            WriteRegFileWide(RegFileWidePkg, MsgPkg.rega, &TempReg_3);

#ifdef TEST_LOG_PRINT
            printf("ALU.PE.U--Param1: 0x%x; Param2: 0x%x; Result: 0x%x. \n", (unsigned int)TempReg_1, (unsigned int)TempReg_2, (unsigned int)TempReg_3);
#endif
            break;
/*
        case OR:
            ReadRegFileWide(RegFileWidePkg, MsgPkg.regb, &TempReg_1);
            if(MsgPkg.flagi == 0)
            {
                ReadRegFileWide(RegFileWidePkg, MsgPkg.regc, &TempReg_2);
            }
            else
            {
                if((MsgPkg.flagfh==0)&&(MsgPkg.flagfl==0))
                {
                    TempReg_2=ALL_LOW_64B;
                    TempReg_2(15,0)=MsgPkg.imma(15,0);
                }

                if((MsgPkg.flagfh==0)&&(MsgPkg.flagfl==1))
                {
                    TempReg_2=ALL_LOW_64B;
                    TempReg_2(31,16)=MsgPkg.imma(15,0);
                }

                if((MsgPkg.flagfh==1)&&(MsgPkg.flagfl==0))
                {
                    TempReg_2=ALL_LOW_64B;
                    TempReg_2(47,32)=MsgPkg.imma(15,0);
                }

                if((MsgPkg.flagfh==1)&&(MsgPkg.flagfl==1))
                {
                    TempReg_2=ALL_LOW_64B;
                    TempReg_2(63,48)=MsgPkg.imma(15,0);
                }
            }
            TempReg_3 = ALUPE(TempReg_1, TempReg_2, ALU_OR);
            WriteRegFileWide(RegFileWidePkg, MsgPkg.rega, &TempReg_3);

            break;
*/
/*
        case XOR:
            ReadRegFileWide(RegFileWidePkg, MsgPkg.regb, &TempReg_1);
            if(MsgPkg.flagi == 0)
            {
                ReadRegFileWide(RegFileWidePkg, MsgPkg.regc, &TempReg_2);
            }
            else
            {
                if((MsgPkg.flagfh==0)&&(MsgPkg.flagfl==0))
                {
                    TempReg_2=ALL_HIGH_64B;
                    TempReg_2(15,0)=MsgPkg.imma(15,0);
                }

                if((MsgPkg.flagfh==0)&&(MsgPkg.flagfl==1))
                {
                    TempReg_2=ALL_HIGH_64B;
                    TempReg_2(31,16)=MsgPkg.imma(15,0);
                }

                if((MsgPkg.flagfh==1)&&(MsgPkg.flagfl==0))
                {
                    TempReg_2=ALL_HIGH_64B;
                    TempReg_2(47,32)=MsgPkg.imma(15,0);
                }

                if((MsgPkg.flagfh==1)&&(MsgPkg.flagfl==1))
                {
                    TempReg_2=ALL_HIGH_64B;
                    TempReg_2(63,48)=MsgPkg.imma(15,0);
                }
            }
            TempReg_3 = ALUPE(TempReg_1, TempReg_2, ALU_XOR);
            WriteRegFileWide(RegFileWidePkg, MsgPkg.rega, &TempReg_3);

            break;
*/
        case ADD:
            ReadRegFileWide(RegFileWidePkg, MsgPkg.regb, &TempReg_1);
            if(MsgPkg.flagi == 0)
            {
                ReadRegFileWide(RegFileWidePkg, MsgPkg.regc, &TempReg_2);
            }
            else
            {
                if((MsgPkg.flags == 1)&&(MsgPkg.imma[15]==1))
                {TempReg_2 = ALL_HIGH_64B;}
                else
                {TempReg_2 = ALL_LOW_64B;}
                TempReg_2(15,0)=MsgPkg.imma;
            }

            if(MsgPkg.flags == 1)
            {
                TempReg_1s = ALUPES(*(_reg_64b_s *)(&TempReg_1), *(_reg_64b_s *)(&TempReg_2), ALU_ADD);
                TempReg_3 = *(_reg_64b *)(&TempReg_1s);
            }
            else
            {
                TempReg_3 = ALUPE(TempReg_1, TempReg_2, ALU_ADD);
            }
            WriteRegFileWide(RegFileWidePkg, MsgPkg.rega, &TempReg_3);
#ifdef TEST_LOG_PRINT
            printf("ADD--Param1: 0x%x; Param2: 0x%x; Result: 0x%x. \n", (unsigned int)TempReg_1, (unsigned int)TempReg_2, (unsigned int)TempReg_3);
#endif
            break;

        case SUB:
            ReadRegFileWide(RegFileWidePkg, MsgPkg.regb, &TempReg_1);
            if(MsgPkg.flagi == 0)
            {
                ReadRegFileWide(RegFileWidePkg, MsgPkg.regc, &TempReg_2);
            }
            else
            {
                if((MsgPkg.flags == 1)&&(MsgPkg.imma[15]==1))
                {TempReg_2 = ALL_HIGH_64B;}
                else
                {TempReg_2 = ALL_LOW_64B;}
                TempReg_2(15,0)=MsgPkg.imma;
            }

            if(MsgPkg.flags == 1)
            {
                TempReg_1s = ALUPE(*(_reg_64b_s *)(&TempReg_1), *(_reg_64b_s *)(&TempReg_2), ALU_SUB);
                TempReg_3 = *(_reg_64b *)(&TempReg_1s);
            }
            else
            {
                TempReg_3 = ALUPE(TempReg_1, TempReg_2, ALU_SUB);
            }
            WriteRegFileWide(RegFileWidePkg, MsgPkg.rega, &TempReg_3);

            break;

        case MUL:
            ReadRegFileWide(RegFileWidePkg, MsgPkg.regb, &TempReg_1);
            if(MsgPkg.flagi == 0)
            {
                ReadRegFileWide(RegFileWidePkg, MsgPkg.regc, &TempReg_2);
            }
            else
            {
                if((MsgPkg.flags == 1)&&(MsgPkg.imma[15]==1))
                {TempReg_2 = ALL_HIGH_64B;}
                else
                {TempReg_2 = ALL_LOW_64B;}
                TempReg_2(15,0)=MsgPkg.imma;
            }

            if(MsgPkg.flags == 1)
            {
                TempReg_1s = ALUPE(*(_reg_64b_s *)(&TempReg_1), *(_reg_64b_s *)(&TempReg_2), ALU_MUL);
                TempReg_3 = *(_reg_64b *)(&TempReg_1s);
            }
            else
            {
                TempReg_3 = ALUPE(TempReg_1, TempReg_2, ALU_MUL);
            }
            WriteRegFileWide(RegFileWidePkg, MsgPkg.rega, &TempReg_3);
            #ifdef TEST_LOG_PRINT
            printf("ALU.PE.U--Param1: 0x%x; Param2: 0x%x; Result: 0x%x. \n", (unsigned int)TempReg_1, (unsigned int)TempReg_2, (unsigned int)TempReg_3);
            #endif
            break;
/*
        case DVD:
            ReadRegFileWide(RegFileWidePkg, MsgPkg.regb, &TempReg_1);
            if(MsgPkg.flagi == 0)
            {
                ReadRegFileWide(RegFileWidePkg, MsgPkg.regc, &TempReg_2);
            }
            else
            {
                if((MsgPkg.flags == 1)&&(MsgPkg.imma[15]==1))
                {TempReg_2 = ALL_HIGH_64B;}
                else
                {TempReg_2 = ALL_LOW_64B;}
                TempReg_2(15,0)=MsgPkg.imma;
            }

            if(MsgPkg.flags == 1)
            {
                TempReg_1s = ALUPE(*(_reg_64b_s *)(&TempReg_1), *(_reg_64b_s *)(&TempReg_2), ALU_DVD);
                TempReg_3 = *(_reg_64b *)(&TempReg_1s);
            }
            else
            {
                TempReg_3 = ALUPE(TempReg_1, TempReg_2, ALU_DVD);
            }
            WriteRegFileWide(RegFileWidePkg, MsgPkg.rega, &TempReg_3);

            break;
*/
/*
        case MOD:
            ReadRegFileWide(RegFileWidePkg, MsgPkg.regb, &TempReg_1);
            if(MsgPkg.flagi == 0)
            {
                ReadRegFileWide(RegFileWidePkg, MsgPkg.regc, &TempReg_2);
            }
            else
            {
                if((MsgPkg.flags == 1)&&(MsgPkg.imma[15]==1))
                {TempReg_2 = ALL_HIGH_64B;}
                else
                {TempReg_2 = ALL_LOW_64B;}
                TempReg_2(15,0)=MsgPkg.imma;
            }

            if(MsgPkg.flags == 1)
            {
                TempReg_1s = ALUPE(*(_reg_64b_s *)(&TempReg_1), *(_reg_64b_s *)(&TempReg_2), ALU_MOD);
                TempReg_3 = *(_reg_64b *)(&TempReg_1s);
            }
            else
            {
                TempReg_3 = ALUPE(TempReg_1, TempReg_2, ALU_MOD);
            }
            WriteRegFileWide(RegFileWidePkg, MsgPkg.rega, &TempReg_3);

            break;
*/
        case LFT:
            ReadRegFileWide(RegFileWidePkg, MsgPkg.regb, &TempReg_1);
            if(MsgPkg.flagi == 0)
            {
                ReadRegFileWide(RegFileWidePkg, MsgPkg.regc, &TempReg_2);
            }
            else
            {
                TempReg_2 = ALL_LOW_64B;
                TempReg_2(15,0) = MsgPkg.imma;
            }
            TempReg_3 = ALUPE(TempReg_1, TempReg_2, ALU_LFT);

            WriteRegFileWide(RegFileWidePkg, MsgPkg.rega, &TempReg_3);

            #ifdef TEST_LOG_PRINT_SIM
                        printf("LFT:arg1:%llx, arg2:%llx, arg3:%llx. \n", (unsigned long long int)TempReg_1,(unsigned long long int)TempReg_2,(unsigned long long int)TempReg_3);
            #endif

            break;

        case RFT:
            ReadRegFileWide(RegFileWidePkg, MsgPkg.regb, &TempReg_1);
            if(MsgPkg.flagi == 0)
            {
                ReadRegFileWide(RegFileWidePkg, MsgPkg.regc, &TempReg_2);
            }
            else
            {
                TempReg_2 = ALL_LOW_64B;
                TempReg_2(15,0) = MsgPkg.imma;
            }

            TempReg_3 = ALUPE(TempReg_1, TempReg_2, ALU_RFT);
            if((MsgPkg.flags==1)&&(TempReg_1[63]==1))
            {TempReg_3(63,63-TempReg_2) = ALL_HIGH_64B;}

            WriteRegFileWide(RegFileWidePkg, MsgPkg.rega, &TempReg_3);

            break;

        case SGS:

            ReadRegFileWide(RegFileWidePkg, MsgPkg.regb, &TempReg_1);
            if((MsgPkg.flags==1)&&(TempReg_1[MsgPkg.immbh]==1))
            {TempReg_2 = ALL_HIGH_64B;}
            else
            {TempReg_2 = ALL_LOW_64B;}

            TempReg_2(MsgPkg.immbh-MsgPkg.immbl, 0) = TempReg_1(MsgPkg.immbh, MsgPkg.immbl);
            WriteRegFileWide(RegFileWidePkg, MsgPkg.rega, &TempReg_2);
#ifdef TEST_LOG_PRINT_SIM
            printf("MsgPkg.immbh:%ld  MsgPkg.immbl:%ld \n", (long int)MsgPkg.immbh, (long int)MsgPkg.immbl);
            printf("arg1:%lld  arg2:%lld \n", (long long int)TempReg_1, (long long int)TempReg_2);
#endif
            break;

/*
//        	_reg_64b sgs_reg1;
//        	_reg_64b sgs_reg2;
//        	_reg_64b sgs_reg3;

            ReadRegFileWide(RegFileWidePkg, MsgPkg.regb, &TempReg_1);
            if(TempReg_1[31]==1)
            {TempReg_2 = ALL_HIGH_64B;}
            else
            {TempReg_2 = ALL_LOW_64B;}

//           sgs_reg1 = MsgPkg.immbh;
//           sgs_reg2 = MsgPkg.immbl;
//            sgs_reg3 = sgs_reg1 - sgs_reg2;


            TempReg_2(31,0) = TempReg_1(31,0);
            //TempReg_2(MsgPkg.immbh-MsgPkg.immbl, 0) = TempReg_1(MsgPkg.immbh, MsgPkg.immbl);
            //TempReg_2(sgs_reg3, 0) = TempReg_1(sgs_reg1, sgs_reg2);


            WriteRegFileWide(RegFileWidePkg, MsgPkg.rega, &TempReg_2);
            printf("arg1:%x  arg2:%x \n", (unsigned int)TempReg_2, (unsigned int)TempReg_1);
            break;*/


        case CCT:
            ReadRegFileWide(RegFileWidePkg, MsgPkg.regb, &TempReg_1);
            ReadRegFileWide(RegFileWidePkg, MsgPkg.regc, &TempReg_2);
            TempReg_3 = ALL_LOW_64B;
            TempReg_3((MsgPkg.immch-MsgPkg.immcl), 0) = TempReg_2(MsgPkg.immch, MsgPkg.immcl);
            TempReg_3((MsgPkg.immbh-MsgPkg.immbl+MsgPkg.immch-MsgPkg.immcl+1), (MsgPkg.immch-MsgPkg.immcl+1)) = TempReg_1(MsgPkg.immbh, MsgPkg.immbl);
            WriteRegFileWide(RegFileWidePkg, MsgPkg.rega, &TempReg_3);
            #ifdef TEST_LOG_PRINT_SIM
                printf("CCT:arg1:%llx, arg2:%llx, arg3:%llx. \n", (unsigned long long int)TempReg_1,(unsigned long long int)TempReg_2,(unsigned long long int)TempReg_3);
            #endif
            break;

        case RWM:
            ReadRegFileWide(RegFileWidePkg, MsgPkg.regb, &TempReg_1);

            TempReg_1_32b = WeightMemPE[TempReg_1];


            if(TempReg_1_32b[31]==1)
            {TempReg_2 = ALL_HIGH_64B;}
            else
            {TempReg_2 = ALL_LOW_64B;}
            TempReg_2(31,0)=TempReg_1_32b(31,0);

            WriteRegFileWide(RegFileWidePkg, MsgPkg.rega, &TempReg_2);
            #ifdef TEST_LOG_PRINT_SIM

                printf("arg1:%d, arg2:%d. \n", (unsigned int)TempReg_1, (unsigned int)TempReg_2);
            #endif
            break;

        case RPM:
            ReadRegFileWide(RegFileWidePkg, MsgPkg.regb, &TempReg_1);
            TempReg_2 = PotenMemPE[TempReg_1];
            WriteRegFileWide(RegFileWidePkg, MsgPkg.rega, &TempReg_2);

            #ifdef TEST_LOG_PRINT_SIM_LAST
                int PrintHighRPM;
                int PrintLowRPM;
                PrintHighRPM = TempReg_2(63,32);
                PrintLowRPM  = TempReg_2(31,0);

                printf("PE--read 0x%x_%x from PotenMem[%d]. \n", (unsigned int)PrintHighRPM, (unsigned int)PrintLowRPM, (int)TempReg_1);
            #endif

            break;

        case WBW:
            ReadRegFileWide(RegFileWidePkg, MsgPkg.rega, &TempReg_1);
            ReadRegFileWide(RegFileWidePkg, MsgPkg.regb, &TempReg_2);
            WeightMemPE[TempReg_1] = TempReg_2(31,0);

            break;

        case WBP:
            ReadRegFileWide(RegFileWidePkg, MsgPkg.rega, &TempReg_1);
            ReadRegFileWide(RegFileWidePkg, MsgPkg.regb, &TempReg_2);
            PotenMemPE[TempReg_1] = TempReg_2(63,0);

#ifdef TEST_LOG_PRINT_SIM_LAST
            int PrintHighWBP;
            int PrintLowWBP;
            PrintHighWBP = TempReg_2(63,48);
            PrintLowWBP  = TempReg_2(47,0);

            printf("PE--write 0x%llx_%llx to PotenMem[%d]. \n", (unsigned long long int)PrintHighWBP, (unsigned long long int)PrintLowWBP, (int)TempReg_1);
#endif

            break;

        case OPT:
            ReadRegFileWide(RegFileWidePkg, MsgPkg.rega, &TempReg_1);
            ReadRegFileWide(RegFileWidePkg, MsgPkg.regb, &TempReg_2);
            ReadRegFileWide(RegFileWidePkg, MsgPkg.regc, &TempReg_3);
            if (ALUPES(*(ap_int<64> *)(&TempReg_1), *(ap_int<64> *)(&TempReg_2), ALU_JNL))
            {
                //TempReg_1(31,0)=0;
                TempReg_1=0;
                WriteRegFileWide(RegFileWidePkg, MsgPkg.rega, &TempReg_1);
                TempReg_4=0;
                TempReg_4(63,48) = MsgPkg.imma; //mask_clst

                TempReg_4(31,0) = TempReg_3(31,0);
                //write TempReg_3 to output memory
                WriteOutputMem(OutputMemPkg, TempReg_4);

                #ifdef TEST_LOG_PRINT_SIM_LAST
                        int PrintHighOPT;
                        long long int PrintLowOPT;
                        PrintHighOPT = TempReg_4(63,48);
                        PrintLowOPT  = TempReg_4(47,0);

                        printf("PE--write 0x%x_%llx to OutputMem. \n", (unsigned int)PrintHighOPT, (unsigned long long int)PrintLowOPT);
                #endif
            }

            break;

        default:
            break;

    }
}

#endif
