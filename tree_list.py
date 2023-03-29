class Tree_list:
    tr=[]
    empty=0
    def __init__(self,inp:str) -> None:
        inp=inp.split(',')
        mx=0
        inpint=[]
        for i in inp:
            try:
                if mx>int(i):
                    mx=int(i)
                inpint.append(int(i))
            finally: continue
        empty=0
        for i in range(0,mx+2):
            if i not in inpint:
                empty=i
        tr=[]
        for i in inp:
            try:
                tr.append(int(i))
            except :
                tr.append(empty)
        self.tr=tr
        self.empty=empty
            
    def level_inf(self,level:int)->list:
        """ input level number, will return start index and no. of elements for the level"""
        if level == 1: return [0,0]
        st_ind=0
        lvl=1
        n=1
        while lvl <level:
            st_ind=(st_ind*2)+1
            n*=2
            lvl+=1
        return [st_ind,n]  
    
    
    def get_levels(self:list)->int:
        """input length of list to get no. of levels in the tree"""
        n,lvls=1,1
        while n<len(self.tr):
            n=(2*n)+1
            lvls+=1
        return lvls
    
    def post(self:list)->None:
        """input list to get postorder traversal of tree"""
        print(self.tr)
        lvl_count=[0 for i in range(self.get_levels())]
        nlvl=self.get_levels()
        level=nlvl
        st=''
        while lvl_count[0]!=1:
            
            if lvl_count[level-1]%2==0 and lvl_count[level-1]!=0:
                level-=1
                if self.tr[self.level_inf(level)[0]+lvl_count[level-1]]!=self.empty:
                    st=st+str(self.tr[self.level_inf(level)[0]+lvl_count[level-1]])+','
                lvl_count[level-1]+=1        
            
            elif lvl_count[level-1]%2!=0 and level!=nlvl:
                level=nlvl     
            
            if level==nlvl :
                if self.tr[self.level_inf(level)[0]+lvl_count[level-1]]!=self.empty:
                    st=st+str(self.tr[self.level_inf(level)[0]+lvl_count[level-1]])+','                
                lvl_count[level-1]+=1
        print(st[0:len(st)-1])
            


inp=input("Enter the tree as a list, empty nodes should be marked with 'e' and the list should signify a full tree:~ \n")

#                             14
#             12                              15
#     10                              9               17
# 2       11                      4       19           

#such a tree can be written as 14,12,15,10,e,9,17,2,11,e,e,4,19,e,e     
                    
ob=Tree_list(inp)
ob.post()




