def encode(input_array):
    state=[0,0,0,0]
    output=[]
    output_string = ""
    count = 0

    for i in input_array:
        # print("State3:", state)
        count += 1
        state[0]=i
        # print("State1:", state, "count:", count)

        output1=state[0]^state[1]^state[2]^state[3]
        output2=state[0]^state[1]^state[3]

        popval = state.pop()
        state.insert(0,popval)

        # print("State2:", state, "pop:",popval)
        # print("----------------------")
        output_string+=str(output1)+str(output2)+" "

    return(output_string)