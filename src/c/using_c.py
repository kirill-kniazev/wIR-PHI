import ctypes as ct
import numpy as np
import time

lib = ct.CDLL("./test_array.so")

st = time.time()
data_len = 512 * 512
array_len = 10000
my_type = ct.c_int * (data_len * array_len)
sized_array = my_type()
print(f"Allocation took {time.time() - st} seconds")

st = time.time()
# lib.return_array(sized_array)
lib.return_array2(sized_array, array_len, data_len)
print(f"Time: {time.time() - st} sec")  

# int_array = (ct.c_int * 10)()
# lib.flat_array(int_array, 10)
# for e in int_array: print(e)



numpy_array = np.array(sized_array, dtype=np.int32, copy=False)
print(numpy_array)
    
