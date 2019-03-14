fa = [1] * 10
for i in range(1, 10):
    for j in range(1, i + 1):
        fa[i] *= j

def cal(k):
    l = 0
    while k > 0:
        l += fa[k % 10]
        k //= 10
    return l

cnt = 0
for k in range(1, 1000000):
    ll = [k,]
    l = cal(k)
    while not l in ll:
        ll.append(l)
        l = cal(l)
    if len(ll) == 60:
        cnt += 1
print(cnt)
