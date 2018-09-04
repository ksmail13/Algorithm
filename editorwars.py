# https://algospot.com/judge/problem/read/EDITORWARS

def answer():
    (N, Q) = (int(i) for i in input().split(' '))
    main = set(range(N))

    sets = dict()

    for _ in range(Q):
        method, a, b = input().split(' ')
        a, b = int(a), int(b)
        main.discard(a)
        main.discard(b)
        if method == 'ACK':
            if a in sets:
                if b in sets:
                    sets[a] |= sets[b]
                    sets[b] = sets[a]
                else:
                    sets[a].add(b)
                    sets[b] = sets[a]
            elif b in sets:
                sets[b].add(a)
                sets[a] = sets[b]
            else:
                sets[a] = set([a, b])
                sets[b] = sets[a]
        else:
            if a in sets:
                if b in sets:
                    violation = sets[a] & sets[b]

                    if len(violation) > 0:
                        print("CONTRADICTION AT {}".format(a+1))
                        return
                else:
                    if b in sets[a]:
                        print("CONTRADICTION AT {}".format(b+1))
                        return
                    sets[b] = set([b])
            elif b in sets:
                if a in sets[b]:
                    print("CONTRADICTION AT {}".format(a+1))
                    return
                sets[a] = set([a])
            else:
                sets[a] = set([a])
                sets[b] = set([b])

    print("{} {}".format(",".join("{}({})".format(k, len(v)) for k, v in sets.items()), len(main)))





def main():
    [answer() for i in range(int(input()))]

if __name__=='__main__':
    main()
