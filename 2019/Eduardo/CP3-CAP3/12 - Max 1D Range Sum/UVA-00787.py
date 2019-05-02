numbers = []
N = 0
dp = []

def create_dp():
    dp = []
    for i in range(110):
        l = [-1]*110
        dp.append(l)
    return dp

def solve(esq, idx, prod):
    #print(esq,idx,prod)
    if(idx >= N):
        return prod
    if(dp[esq][idx] != -1):
        return dp[esq][idx]
    
    com = solve(esq, idx+1, prod*numbers[idx])
    sem = solve(idx, idx+1, numbers[idx])

    dp[esq][idx] = max(com,sem,prod)
    #print("dp[%d][%d]=%d"%(esq,idx,dp[esq][idx]))
    return dp[esq][idx]


while True:
    try:
        seq = input().split()

        for i in seq:
            num = int(i)
            if(num !=  -999999):
                numbers.append(num)
            else:
                N = len(numbers)
                dp = create_dp()
                print(solve(0,1,numbers[0]))
                numbers = []
    except EOFError:
        break