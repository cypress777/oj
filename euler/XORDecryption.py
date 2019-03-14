f = open('p059_cipher.txt', 'r')
s = f.readline()
ss = s.rstrip().split(',')
text = []

for s in ss:
    n = int(s)
    text.append(n)
print("Total words: ", len(text))

def IsValid(n):
    if n > 31 and n < 127:
        return True
    return False

def IsReadable(msg):
    cthe = [32, 116, 104, 101]
    cbe = [32, 98, 101]
    cto = [32, 116, 111]
    cof = [32, 111, 102]
    cand = [32, 97, 110, 100]
    ca = [32, 97]
    cin = [32, 105, 110]
    n = 0
    for k in range(0, len(msg)):
        if (msg[k : k + 4] == cthe or msg[k : k + 4] == cand or
            msg[k: k + 3] == cbe or msg[k: k + 3] == cto or msg[k: k + 3] == cof or msg[k: k + 3] == cin or
            msg[k: k + 2] == ca):
        # if msg[k] == 32:
        # if msg[k] in [32, 44, 46] or (msg[k] > 64 and msg[k] < 91) or (msg[k] > 96 and msg[k] < 123):
            n += 1
    return n

start = [97, 97, 97]
end = [122, 122, 122]

maxkey = []
maxsum = 0
maxcount = 0
maxmsg = []
vnum = 0
for start[0] in range(97, 123):
    for start[1] in range(97, 123):
        for start[2] in range(97, 123):
            k = 0
            n = 0
            sum = 0
            msg = []
            val = True
            for t in text:
                w = t ^ start[k % 3]
                sum += w
                if w < 90 and w > 64:
                    msg.append(w + 32)
                else:
                    msg.append(w)
                k += 1
                if not IsValid(w):
                    val = False

            if val:
                n = IsReadable(msg)
                vnum += 1
                if n > maxcount:
                    maxcount = n
                    maxkey = start[:]
                    maxsum = sum
                    maxmsg = msg[:]


mmsg = []
for c in maxmsg:
    cc = str(unichr(c))
    mmsg.append(cc)
print (maxkey, maxsum, maxcount)
print (mmsg)
print (vnum)