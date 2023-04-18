from scipy.io import loadmat
import numpy as np
#cnn = loadmat("../cnn_99.14.mat")
cnn_input_spike_tsp1 = loadmat("matlab.mat")

f = open("s4nn_spike.txt", "w")
fb = open("s4nn_spike.bin", "wb+")

cnn_num = cnn_input_spike_tsp1['cnn_input_spike'][0][0]['time']           ######matlab data. you should put data in the according matlab.
# cnn_idxx = cnn_input_spike_tsp1['cnn_input_spike'][0][0]['id']
cnn_idxy = cnn_input_spike_tsp1['cnn_input_spike'][0][0]['id']

#for idx_img in range(0:1):
idx_instr_offset = 0
cur_time=0
for idx_time in range(0,256):                                           ##change the number according to your timestep
    num_spike_cur_time = cnn_num[0][idx_time]
    for idx_content in range(0, num_spike_cur_time):
        # row_val = cnn_idxx[idx_content][idx_time] - 1
        col_val = cnn_idxy[idx_content][idx_time]
        print(cur_time)
        #spike_format = int(cur_time*(2 ^ 24) + row_val*(2 ^ 5) + col_val)
        spike_format = int(cur_time*(2 ** 24)+col_val)
        spike_format_byte = spike_format.to_bytes(
            length=4, byteorder='little', signed=False)
        spike_format_byte_txt = spike_format.to_bytes(                                 #the length: e.x. length=4    output data format: 0x0000 0000
            length=4, byteorder='big', signed=False)
        f.write("SpikeMemPkg->SpikeMem[0][%d] = 0x%s; " %
                (idx_content+idx_instr_offset, spike_format_byte_txt.hex()))
        f.write("   // timestep: %d,  id: %d, \n" %
                (cur_time, col_val))
        fb.write(spike_format_byte)
    cur_time = idx_time + 1

    idx_instr_offset = idx_instr_offset + num_spike_cur_time

f.close()
fb.close()

print("done")