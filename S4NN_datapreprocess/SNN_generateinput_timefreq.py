###########################################################################################
# The implementation of the supervied spiking neural network named S4NN presented in      #
# "S4NN: temporal backpropagation for spiking neural networks with one spike per neuron"  #
# by S. R. Kheradpisheh and T. Masquelier                                                 #
# The paper is availbale at: https://arxiv.org/abs/1910.09495.                            #  
#                                                                                         #
# To run the codes on cpu set GPU=False.                                                  #
# An ipynb version of the code compatible with Google coLab is also available.            # 
###########################################################################################

# Imports
from __future__ import division

# if you have a CUDA-enabled GPU the set the GPU flag as True
GPU=False

import time
from mnist import MNIST

import pandas as pd
import numpy as np
if GPU:
    import cupy as cp  # You need to have a CUDA-enabled GPU to use this package!
else:
    cp=np

# Parameter setting
thr = [100, 100]  # The threshold of hidden and output neurons
lr = [.2, .2]  # The learning rate of hidden and ouput neurons
lamda = [0.000001, 0.000001]  # The regularization penalty for hidden and ouput neurons
b = [5, 48]  # The upper bound of wight initializations for hidden and ouput neurons
a = [0, 0]  # The lower bound of wight initializations for hidden and ouput neurons
Nepoch = 100 # The maximum number of training epochs
NumOfClasses = 10  # Number of classes
Nlayers = 1  # Number of layers
NhidenNeurons = 400  # Number of hidden neurons
Dropout = [0, 0]
tmax = 255  # Simulatin time
GrayLevels = 255  # Image GrayLevels
gamma = 3  # The gamma parameter in the relative target firing calculation

# General settings
loading = True  # Set it as True if you want to load a pretrained model
LoadFrom = "weights_best.npy"  # The pretrained model
saving = False  # Set it as True if you want to save the trained model
best_perf = 0
Nnrn = [NhidenNeurons, NumOfClasses]  # Number of neurons at hidden and output layers
cats = [4, 1, 0, 7, 9, 2, 3, 5, 8, 6]  # Reordering the categories

# General variables
images = []  # To keep training images
labels = []  # To keep training labels
images_test = []  # To keep test images
labels_test = []  # To keep test labels
W = []  # To hold the weights of hidden and output layers
firingTime = []  # To hold the firing times of hidden and output layers
Spikes = []  # To hold the spike trains of hidden and output layers
X = []  # To be used in converting firing times to spike trains
target = cp.zeros([NumOfClasses])  # To keep the target firing times of current image
FiringFrequency = []  # to count number of spikes each neuron emits during an epoch

# loading MNIST dataset
mndata = MNIST('MNIST/')
# mndata.gz = True
# filename ='train-images.idx3-ubyte'
# binfile =open(filename, 'rb')
# mndata =binfile.read()

Images, Labels = mndata.load_training()
Images = np.array(Images)



for i in range(len(Labels)):
    if Labels[i] in cats:
        images.append(np.floor((GrayLevels - Images[i].reshape(28, 28)) * tmax / GrayLevels).astype(int))
        labels.append(cats.index(Labels[i]))

Images, Labels = mndata.load_testing()
Images = np.array(Images)

for i in range(len(Labels)):
    if Labels[i] in cats:
        # images_test.append(TTT[i].reshape(28,28).astype(int))
        images_test.append(np.floor((GrayLevels - Images[i].reshape(28, 28)) * tmax / GrayLevels).astype(int))
        labels_test.append(cats.index(Labels[i]))

## saving the first image input data
#np.save("snn_input_firstimage", images_test[0], allow_pickle=True)
matrix = images_test[0]
matrix_value=images_test[0]
# count = 0

my_array = matrix.reshape(-1)
key = np.unique(my_array)
result = {}
for k in range(0,256):
    mask = (my_array == k)
    y_new = [mask]
    v = np.sum(y_new)
    result[k] = v

col=[1]
df = pd.DataFrame(result,index=col)

# 使用to_excel()函数将表格数据输出为Excel文件
df.to_excel('data.xlsx', index=False)
print(result)

# print(my_array)
#
# for i in range(len(matrix)):
#     for j in range(len(matrix[i])):
#         matrix[i][j] = count
#         count += 1
#
#
# for k in range(0,256):
#     for i in range(len(matrix)):
#         for j in range(len(matrix[i])):
#             if (matrix_value[i][j] == k+1):
#                 print(matrix_value[i][j],'/n',matrix[i][j])

# test=np.reshape(matrix_value,(1,-1))
#np.savetxt('1stpicinput.txt',test, fmt='%s', newline='\n')

# i=1
# for i in range(len(test)+1):
#     if(test[i])
# k=0
# m=0
#
#
# key = np.unique(my_array)
# result = {}
# for k in key:
#     mask = (my_array == k)
#     y_new = [mask]
#     v = y_new.size
#     result[k] = v
# print(result)
