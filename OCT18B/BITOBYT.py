T = int(input())
powers_of_2 = [1] * 62
for i in range(1, 62):
    powers_of_2[i] = powers_of_2[i-1] * 2
while T:
    N = int(input())
    N = N - 1
    qu = N // 26
    rem = N % 26
    if rem < 2:
        print("%d 0 0" % (powers_of_2[qu]))
    elif rem < 10:
        print("0 %d 0" % (powers_of_2[qu]))
    else:
        print("0 0 %d" % (powers_of_2[qu]))
    T = T - 1
