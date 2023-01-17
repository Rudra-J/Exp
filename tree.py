import sys
import threading
sys.setrecursionlimit(10**6)
threading.stack_size(2**27)


class TreeOrders:
    def read(self):
        path=r"C:\Users\ASUS\Downloads\21"
        file=open(path)
        c=0
        self.key,self.left,self.right=[],[],[]
        for i in file:
            if c==0: self.n=int(i.split("\n")[0])
            else:
                self.key.append(int(i.split(" ")[0].split("\n")[0])) 
                self.left.append(int(i.split(" ")[1].split("\n")[0])) 
                self.right.append(int(i.split(" ")[2].split("\n")[0])) 
            c+=1

    def _inOrder_(self, node):
        if node == -1:
            return
        self._inOrder_(self.left[node])
        self.result.append(self.key[node])
        self._inOrder_(self.right[node])

    def inOrder(self):
        self.result = []
        self._inOrder_(0)
        return self.result

    def _preOrder_(self, node):
        if node == -1:
            return
        self.result.append(self.key[node])
        self._preOrder_(self.left[node])
        self._preOrder_(self.right[node])

    def preOrder(self):
        self.result = []
        self._preOrder_(0)
        return self.result

    def _postOrder_(self, node):
        if node == -1:
            return
        self._postOrder_(self.left[node])
        self._postOrder_(self.right[node])
        self.result.append(self.key[node])

    def postOrder(self):
        self.result = []
        self._postOrder_(0)
        return self.result

def main():
    tree = TreeOrders()
    tree.read()
    path=r"C:\Users\ASUS\Downloads\21.a"
    file=open(path)
    c=0
    for i in file:
        str=i.split("\n")[0].split(" ")
        if c==0:
            ans=tree.inOrder()
            f=0
            for i in range(len(ans)):
                if ans[i]!=int(str[i]): f=1
            if f==0: print("Success")
        elif c==1:
            ans=tree.preOrder()
            f=0
            for i in range(len(ans)):
                if ans[i]!=int(str[i]): f=1
            if f==0: print("Success")
        elif c==2:
            ans=tree.postOrder()
            f=0
            for i in range(len(ans)):
                if ans[i]!=int(str[i]): f=1
            if f==0: print("Success")
        c+=1
             

threading.Thread(target=main).start()
