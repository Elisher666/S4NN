from scipy.io import loadmat
import numpy as np

s4nn = loadmat("SNNusecnn.mat")
f = open("s4nn_weight_c4.txt", "w")
fb = open("s4nn_weight_c4.bin", "wb+")

kernel_c1 = s4nn['cnn'][0][0]['layers'][1][0]['k'][0][0][0][0]     ##This is to open the matlab file. you can store the file at this path.
cnt=0
idx_pe=0
                             ##you should change the range according to your settings.
for idx_row in range(0, 28):
    for idx_col in range(0, 28):
        for idx_kernel in range(300, 400):


            kernel_element_float = kernel_c1[0][idx_kernel][idx_row][idx_col]
            # print(kernel_element_float)
            kernel_element_fixed = int((kernel_element_float * (2 ** 22)))                 ##change the float data into fixed point data and 2^22.
            # print(kernel_element_fixed)

            kernel_element_byte = kernel_element_fixed.to_bytes(
                length=4, byteorder='little', signed=True)
            kernel_element_byte_txt = kernel_element_fixed.to_bytes(
                length=4, byteorder='big', signed=True)
            idx_in_pe = idx_kernel % 100                #both
            idx_pe = idx_kernel / 100                           #change this if you want change the num of PE
            #idx_kernel_real = idx_kernel%4
            #idx_clst_real = idx_kernel/4

            f.write("WeightMemPE_%d[%d] = 0x%s; \n" % (
                idx_pe, cnt, kernel_element_byte_txt.hex()))
            fb.write(kernel_element_byte)


    f.write("\n")


f.close()
fb.close()

print("done")