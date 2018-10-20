T = int(input())
while T:
    A, B, K = map(int, input().split())
    switches = ( A + B ) // K
    if switches % 2:
        print("COOK")
    else:    
        print("CHEF")
    T = T - 1
