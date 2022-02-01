from math import floor

from numpy import double


def calc(theta: str) -> str:
    res = "2."
    b = double(theta)
    for i in range(24):
        b = floor(b) * (b - floor(b) + 1.0)
        a = floor(b)
        res += str(a)

        if len(res) > 26:
            break
    res = res[:26]

    return res

def comp_sm(a: str, b: str) -> bool:
    for i in range(2, min(len(a), len(b))):
        if a[i] == b[i]:
            continue
        else:
            return a[i] < b[i]
    return len(a) < len(b)

if __name__ == '__main__':
    left = "2.2"
    right = "2.4"

    count = 0
    while comp_sm(left, right):
        print("-------------")
        count += 1

        mid = str((double(left) + double(right)) / 2.0)
        res = calc(mid)
        
        print(left, right)
        print(mid)
        print(res)
        print(len(res))

        if count > 100:
            exit()
        if len(mid) >= 26 and res[:26] == mid[:26]:
            exit()

        if comp_sm(res, mid):
            right = mid
        else:
            left = mid
