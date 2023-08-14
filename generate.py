import random
test_round=1000
with open("test.txt","w") as f:
    for i in range(test_round):
        length=random.randrange(1, 100)
        for j in range(length):
            f.write(str(random.randrange(-1000, 1000)))
            f.write(" ")
        f.write("\n")

with open("testp1.txt","w") as f1:
    length1 = random.randrange(10, 1000)
    f1.write(str(length1))
    f1.write('\n')
    for i in range(length1):
        f1.write(str(random.randrange(-1000, 1000)))
        f1.write(" ")
        f1.write(str(random.randrange(-1000, 1000)))
        f1.write("\n")
