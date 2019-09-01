num = str(raw_input())

cnt = 1

if len(num) == 1 and num == '0':
    print(cnt)
else:
    for i in range(len(num)):
        if num[i] == '0' or num[i] == '2':
            continue

        elif num[i] == '1':
            cnt *= 2

        else:
            cnt = 0
            break
    print(int(cnt / 2))
