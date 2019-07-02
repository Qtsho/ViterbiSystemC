slot = []
input_list = [0, 1]
input_state = [[0, 0, 0],
               [0, 0, 1],
               [0, 1, 0],
               [0, 1, 1],
               [1, 0, 0],
               [1, 0, 1],
               [1, 1, 0],
               [1, 1, 1]]

def createTable():
    # Initialize table
    w, h = 9, 16
    table = [[0 for x in range(w)] for y in range(h)]


    # Add input bits
    i = 0
    while i < 15:
        table[i][0] = input_list[0]
        table[i+1][0] = input_list[1]
        i+=2


    # Add input states
    i = 0
    j = 0
    while i < 15 and j < 8:
        table[i][1] = input_state[j][0]
        table[i][2] = input_state[j][1]
        table[i][3] = input_state[j][2]

        table[i+1][1] = input_state[j][0]
        table[i+1][2] = input_state[j][1]
        table[i+1][3] = input_state[j][2]
        i+=2
        j+=1


    # Add output bits
    i = 0
    while i < 16:
        table[i][4] = table[i][0]^table[i][1]^table[i][2]^table[i][3]
        table[i][5] = table[i][0]^table[i][1]^table[i][3]
        i+=1


    # Add next state
    i = 0
    while i < 16:
        table[i][6] = table[i][0]
        table[i][7] = table[i][1]
        table[i][8] = table[i][2]
        i+=1

    return  table
