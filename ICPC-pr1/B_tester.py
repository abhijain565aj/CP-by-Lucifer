import sys
sys.setrecursionlimit(10**7)
n=6
import subprocess
def is_zeros_followed_by_ones(s):
    one_found=False
    for i in range(len(s)):
        if s[i]=='1':
            one_found=True
        elif s[i]=='0' and one_found:
            return False
    return True
class Graph:
    def __init__(self,V):
        self.V=V
        self.adj={}
        self.visited={}
        self.root={}
    def addEdge(self,u,v):
        if u not in self.adj:
            self.adj[u]=[]
        if v not in self.adj:
            self.adj[v]=[]
        self.adj[u].append(v)
        self.adj[v].append(u)
    def dfs(self, root, full_root):
        print(root)
        self.root[ root ]=full_root
        root_copy=list(root)
        self.visited[root]=True
        for neighbor in self.adj.get(root, []):
            if neighbor not in self.visited:
                self.dfs(neighbor, full_root)
g=Graph(2**n)
c=0
for i in range(2**n):
    s=""
    for j in range(n):
        if (i&(1<<j))>0:
            s+="1"
        else:
            s+="0"
    for j in range(n):
        if s[j]=="1":
            t=list(s)
            if j>0:
                t[j-1]="1" if t[j-1]=="0" else "0"
            if j<n-1:
                t[j+1]="1" if t[j+1]=="0" else "0"
            g.addEdge(s, "".join(t))

for i in range(2**n):
    s=""
    for j in range(n):
        if (i&(1<<j))>0:
            s+="1"
        else:
            s+="0"
    if s not in g.visited:
        c+=1
        g.dfs(s, s)
        print("------")