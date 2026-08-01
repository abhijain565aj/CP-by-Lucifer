import subprocess
import random
for __ in range(100):
    with open("input.txt", 'w') as f:
        n = random.randint(1, 10)
        for _ in range(2):
            print(n , n * (n + 1) // 2, file = f)
            for i in range(n):
                for j in range(i,n):
                    print(i + 1, j + 1, file = f)
            
    subprocess.run()