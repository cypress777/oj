import MathUtils as mu

prime_tab = mu.genPrimeTab(8000)

ns = set()
nmax = 50000000

for i in prime_tab:
    n = i * i
    if n > nmax:
        break
    for j in prime_tab:
        nn = n + j * j * j
        if nn > nmax:
            break
        for k in prime_tab:
            nnn = nn + k * k * k * k
            if nnn > nmax:
                break
            else:
                ns.add(nnn)
                
print(len(ns))