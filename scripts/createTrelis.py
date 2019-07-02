from createTable import createTable

table = createTable()

# Create Trellis
def createTrellis(dsl):
    tw = dsl
    tl = 2**dsl
    # print(tw, tl)
    trellis = [[0 for x in range(tw+1)] for y in range(tl)]

    cs_list = [[0, 0, 0]]
    temp_cs_list = [[0, 0, 0]]

    i = 0
    count = 1

    while i < tw:
        csl = len(temp_cs_list)

        for j in range(0, csl):
            current_state = temp_cs_list[j]
            temp_cs_list.extend(nextState(current_state[0], current_state[1], current_state[2]))

        for k in range(0, count):
            temp_cs_list.pop(0)

        cs_list.extend(temp_cs_list)
        count*=2

        i+=1


    num = tl
    temp_num_list = []
    num_list = []
    while num >= 1:
        temp_num_list.append(int(num))
        num/=2


    i = 0
    k = len(temp_num_list) - 1

    while i < len(temp_num_list) and k >= 0:
        temp_num = temp_num_list[i]
        j = 0
        while j < temp_num:
            num_list.append(temp_num_list[k])
            j+=1
        k-=1
        i+=1

    num_list.reverse()


    temp_trellis = []
    for i in range(0, len(cs_list)):
        for j in range(num_list[i]):
            temp_trellis.append(cs_list[i])


    for i in range(0, tl):
        k=i
        for j in range(0, tw+1):
            trellis[i][j] = temp_trellis[k]
            k+=tl

    return trellis


# Find Next State
def nextState(s1, s2, s3):

    temp_ns_list = []
    temp_ns = [0, 0, 0]

    count = 0

    for i in range(0, len(table)):
        if table[i][1] == s1 and table[i][2] == s2 and table[i][3] == s3:
            temp_ns[0] = table[i][6]
            temp_ns[1] = table[i][7]
            temp_ns[2] = table[i][8]

            temp_ns_list.append(temp_ns[:])

    return temp_ns_list


# Find Hamming Metrics
def score(s1, s2):
    ts1 = list(map(int, s1))
    ts2 = list(map(int, s2))
    score = 0

    if len(ts1) == len(ts2):
        for i in range(0, 2):
            if ts1[i] == ts2[i]:
                score+=1
    else:
        score = 100

    return score


# Find matched states
def matchedState(sa1, sa2, sa3, sb1, sb2, sb3):
    if sa1 == sb1 and sa2 == sb2 and sa3 == sb3:
        return 1
    else:
        return 0