from createTable import createTable
from createTrelis import matchedState
from createTrelis import score
from createTrelis import nextState

table = createTable()


def sortKey(val):
    return val[0]

# -------------ORGANIZE INPUT DECODE SEQUENCE---------------------------------------------------
decoseq_prelist = []
decoseq_list = []

# decoseq = "01110111010111"
decoseq = "11110111010111"
# decoseq = "01110111"


decoseq_prelist = list(map(int, decoseq))
dsl = int(len(decoseq_prelist))

i = 0
while i < dsl:
    decoseq_pair = [0, 0]
    decoseq_pair[0] = decoseq_prelist[i]
    decoseq_pair[1] = decoseq_prelist[i + 1]
    decoseq_list.append(decoseq_pair)
    i += 2

dsl = len(decoseq_list)
print("dsl:", dsl)
print(decoseq)
# print("------------------")


# -------------------------------------------------------------------------------
# tw = dsl
# tl = 2 ** dsl
#
# print(tw, tl)

path_list = [[[0, 0, 0]]]

pw = len(path_list[0])
pl = len(path_list)

# print(pw, pl)

ns_list = []
temp_ns = []

for dp in range(0, dsl):

    # FIND NEXT STATES OF THE LAST STATES IN CURRENT TRACE
    ns_list.clear()
    # print("-------------")
    # print("pl:", len(path_list))
    for j in range(0, len(path_list)):
        ns = nextState(path_list[j][-1][0], path_list[j][-1][1], path_list[j][-1][2])
        ns_list.extend(ns[:])


    # DOUBLE THE TRACES BEFORE
    temp_path = []
    count = 0
    for m in range(0, len(path_list)):
        for n in range(0, 2):
            temp_path.append(path_list[m][:])


    # ADD THE NEXT STATES TO THE PREVIOUS TRACES THAT HAVE BEEN DOUBLED
    for k in range(0, len(ns_list)):
        temp_path[k].append(ns_list[k][:])

    path_list = temp_path[:]
    # print("upl:", len(path_list))


    # FIND THE OUTPUT BITS WHEN SWITCHING BETWEEN STATES
    output_bits = []
    ob_list = []

    for k in range(0, len(path_list)):
        output_bits.clear()
        for i in range(0, len(path_list[0]) - 1):
            for j in range(0, len(table)):
                if matchedState(path_list[k][i][0], path_list[k][i][1], path_list[k][i][2], table[j][1], table[j][2], table[j][3]) \
                        and matchedState(path_list[k][i + 1][0], path_list[k][i + 1][1], path_list[k][i + 1][2], table[j][6],
                                         table[j][7], table[j][8]):
                    output_bits.append([table[j][4], table[j][5]])
        ob_list.append(output_bits[:])

    print("==============================================================================")
    count = 0
    for item in path_list:
        print(item, "--", count)
        count += 1


    # FIND HAMMING METRIC FOR EACH OUTPUT STATES
    temp_metric = []
    score_list = []

    for i in range(0, len(ob_list[0])):

        score_list.clear()
        for j in range(0, len(ob_list)):
            score_list.append(score(ob_list[j][i], decoseq_list[i]))

        temp_metric.append(score_list[:])

    # ROTATE HAMMING MATRIX
    metric = []
    t_metric = []
    for i in range(0, len(ob_list)):
        t_metric.clear()
        for j in range(0, len(ob_list[0])):
            t_metric.append(temp_metric[j][i])
        metric.append(t_metric[:])

    # CALCULATE THE SUM OF EACH PATH
    sum_list = []
    for i in range(0, len(metric)):
        sum = 0
        for j in range(0, len(metric[0])):
            sum += metric[i][j]
        sum_list.append(sum)

    remove_list = []

    for i in range(0, len(path_list)):
        current_state = path_list[i][-1]
        # print("cs:", current_state)
        matched_list = []

        for j in range(0, len(path_list)):
            if path_list[j][-1] == current_state:
                # print(j)
                matched_list.append(j)

        sum_checklist = []
        for k in range(0, len(matched_list)):
            sum_checklist.append([sum_list[matched_list[k]], matched_list[k]])

        sum_checklist.sort(key=sortKey, reverse=True)
        max_sum = sum_checklist[0][0]

        temp_remove_list = []
        for i in range(0, len(sum_checklist)):
            if sum_checklist[i][0] < max_sum:
                temp_remove_list.append(sum_checklist[i][1])

        remove_list.extend(temp_remove_list)

    updated_remove_list = []

    for item in remove_list:
        if item not in updated_remove_list:
            updated_remove_list.append(item)

    updated_remove_list.sort(reverse=True)

    urll = len(updated_remove_list)

    for i in range(0, urll):
        path_list.pop(updated_remove_list[i])

    print("--------------------------------")
    count = 0
    for item in path_list:
        print(item, "--", count)
        count+=1

    count = 0
    for item in ob_list:
        print(item, "::", count)
        count+=1


# print("--------------------------------------------")
# for item in ob_list:
#     print(item)
#
# print("--------------------------------------------")
# print(decoseq_list)
#

result_list = []
print("--------------------------------------------")
for i in range(0, len(path_list)):
    # print(path_list[i], "--", sum_list[i], "--", i)
    result_list.append([sum_list[i], path_list[i]])

result_list.sort(key=sortKey,reverse=True)

max_path = result_list[0][0]
print(max_path)
for i in range(0, len(result_list)):
    if result_list[i][0] >= max_path:
        print(result_list[i])

final_list = []
for i in range(0, len(result_list)):
    final_list.append(result_list[i][1])

print("====FINAL LIST===========================================================================================")
for item in final_list:
    print(item)


print("====OUTPUT BITS===========================================================================================")
final_output_bits = []
final_ob_list = []

for k in range(0, len(final_list)):
    final_output_bits.clear()
    for i in range(0, len(final_list[0]) - 1):
        for j in range(0, len(table)):
            if matchedState(final_list[k][i][0], final_list[k][i][1], final_list[k][i][2], table[j][1], table[j][2],
                            table[j][3]) \
                    and matchedState(final_list[k][i + 1][0], final_list[k][i + 1][1], final_list[k][i + 1][2],
                                     table[j][6],
                                     table[j][7], table[j][8]):
                final_output_bits.append([table[j][4], table[j][5]])
    final_ob_list.append(final_output_bits[:])

for item in final_ob_list:
    print(item)

print("====FINAL METRICS===========================================================================================")
final_temp_metric = []
final_score_list = []

for i in range(0, len(final_ob_list[0])):

    final_score_list.clear()
    for j in range(0, len(final_ob_list)):
        final_score_list.append(score(final_ob_list[j][i], decoseq_list[i]))

    final_temp_metric.append(final_score_list[:])


print("====FINAL METRICS===========================================================================================")
final_metric = []
final_t_metric = []
for i in range(0, len(final_ob_list)):
    final_t_metric.clear()
    for j in range(0, len(final_ob_list[0])):
        final_t_metric.append(final_temp_metric[j][i])
    final_metric.append(final_t_metric[:])

for item in final_metric:
    print(item)

print("====FINAL SUM 1===========================================================================================")
final_sum_list = []
for i in range(0, len(final_metric)):
    final_sum = 0
    for j in range(0, len(final_metric[0])):
        final_sum += final_metric[i][j]
    final_sum_list.append([final_sum, i])

for item in final_sum_list:
    print(item)

final_sum_list.sort(reverse=True)
final_sum_max = final_sum_list[0][0]
print("FINAL SUM MAX:", final_sum_max)

print("====FINAL PATH RESULT===========================================================================================")

final_DP = []

for i in range(0, len(final_sum_list)):
    # print(final_sum_list[i][0],"::", final_sum_max, "::", final_sum_list[i][1])
    if final_sum_list[i][0] >= final_sum_max:
        final_DP.append(final_list[final_sum_list[i][1]])


for item in final_DP:
    print(item)

# ==== FINAL DECODED SEQUENCE ==========================================================================================
print("====FINAL DECODED SEQUENCE===========================================================================================")
final_input_bits = []
final_ib_list = []

for k in range(0, len(final_DP)):
    final_input_bits.clear()
    for i in range(0, len(final_DP[0]) - 1):
        for j in range(0, len(table)):
            if matchedState(final_DP[k][i][0], final_DP[k][i][1], final_DP[k][i][2], table[j][1], table[j][2],
                            table[j][3]) \
                    and matchedState(final_DP[k][i + 1][0], final_DP[k][i + 1][1], final_DP[k][i + 1][2],
                                     table[j][6],
                                     table[j][7], table[j][8]):
                final_input_bits.append(table[j][0])
    final_ib_list.append(final_input_bits[:])

for item in final_ib_list:
    print(item)


