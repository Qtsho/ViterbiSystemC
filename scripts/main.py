import Encoder
from Encoder import encode
# import Decoder
# import createTable

# input_list = list(input("Provide Input: "))
input_string = "11"
input_list = list(map(int, input_string))
print("Input:", input_list)
print("----------------------")
print(encode(input_list))