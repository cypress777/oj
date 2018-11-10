import Permutation as pmt
import MathUtils as mu

prime_tab = mu.genPrimeTab(9999)
tab_len = len(prime_tab)
index = 0
for prime in prime_tab:
    if prime >= 1000:
        break
    index += 1
prime_tab = prime_tab[index : tab_len]

def tmp_convert(lst):
    mult = 1000
    result = 0
    for num in lst:
        result += mult * int(num)
        mult /= 10
    return result

def tmp_count_sub(lst):
    subs_count = {}
    for i in range(0, len(lst) - 2):
        for j in range(i + 1, len(lst) - 1):
            for k in range(j + 1, len(lst)):
                if lst[k] - lst[j] == lst[j] - lst[i]:
                    print(lst[i], lst[j], lst[k])
                    return


sequence_set = set([])
all_set = set([])
for prime in prime_tab:
    all_set.add(prime)
    sequence_set.add(prime)

    next_permutation = pmt.nextPermuteStr([int(i) for i in str(prime)])
    next_num = tmp_convert(next_permutation)

    while (not pmt.isEnd(next_permutation)):
        if next_num == prime or next_num in all_set:
            sequence_set.clear()
            break

        if next_num in prime_tab:
            sequence_set.add(next_num)
            all_set.add(next_num)

        next_permutation = pmt.nextPermuteStr(next_permutation)
        next_num = tmp_convert(next_permutation)

    if len(sequence_set) > 2:
        tmp_count_sub(list(sequence_set))

    sequence_set.clear()