
# -*-coding:utf-8-*-
maxl = 10  # 筛选范围
count = 0
ss = []    # 素数
check = [] # 0代表素数，1代表合数。全部初始化为素数。
for x in range(0, maxl+1):
    check.append(0)
# 筛选出 2~10^6 所有素数
for i in range(2, maxl):
    # 如果是素数就存起来
    if check[i] == 0:
        ss.append(i)
        count += 1
    # 循环存起来的素数
    for j in range(0, count):
        # 素数的i倍，肯定是一个合数
        if ss[j]*i > maxl:
            break
        # 将素数的i倍标注为合数，这儿将所有素数视为最小素数，那么最小素数对应的所有合数都会被标注。
        check[ss[j]*i] = 1
        print (i)
        print (check)
        # 循环素数列表，如果被筛选的数能被列表中某个数整除，由于列表中的素数是有序的，所以该素数就是被筛选数的最小素因子。
        # 我们知道上一句代码就是用来筛选出素因子对应合数的，既然合数 i 对应的最小素因子已经在素数列表中了，那么合数 i 肯定
        # 会被改素数给筛选出，所以结束当前循环，没必要用其他素数去筛选 i
        if i%ss[j] == 0:
            break
print(ss[:100])
print (check)