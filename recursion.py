def numChars(strings):
    if len(strings) == 0:
        return 0
    return len(strings[0]) + numChars(strings[1:])

def evenOnly(nums):
    if len(nums) == 0:
        return []
    if nums[0] % 2 == 0:
        return [nums[0]] + evenOnly(nums[1:])
    else:
        return evenOnly(nums[1:])
    
def triangular(num):
    if num == 1:
        return 1
    return num + triangular(num-1)

def firstX(string):
    if string[0] == "x":
        return 0
    return 1 + firstX(string[1:])

def uniquePaths(rows, cols):
    if rows == 1 or cols == 1:
        return 1
    return uniquePaths(rows, cols-1) + uniquePaths(rows-1, cols)

def uniquePathsDfs(rows, cols):
    def dfs(r, c):
        if r == rows-1 and c == cols-1: return 1
        if r == rows or c == cols: return 0
        return dfs(r, c+1) + dfs(r+1, c)
    return dfs(0, 0)

def fibonacci(n):
    if n == 0: return 0
    a, b = 0, 1
    for _ in range(1, n):
        a, b = b, a+b
    return b

def uniquePathsMemoised(rows, cols, memo):
    if (rows, cols) in memo:
        return memo[(rows, cols)]
    if rows == 1 or cols == 1:
        return 1
    memo[(rows, cols)] = uniquePathsMemoised(rows-1, cols, memo) + uniquePathsMemoised(rows, cols-1, memo)
    return memo[(rows, cols)]

print("numChars:", numChars(["ab", "c", "def", "ghij"]))
print("evenOnly:", evenOnly([1,2,3,4,5,6,8]))
print("triangular:", triangular(7))
print("firstX:", firstX("abcdefghijklmnopqrstuvwxyz"))
print("uniquePaths:", uniquePaths(3, 7))
print("uniquePathsDfs:", uniquePathsDfs(3, 7))
print("fibonacci:", fibonacci(10))
print("uniquePathsMemoised:", uniquePathsMemoised(10, 20, {}))
print("uniquePaths:", uniquePaths(10, 20))