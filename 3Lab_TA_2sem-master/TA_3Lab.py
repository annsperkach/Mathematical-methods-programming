import numpy as np
from merge_sort import SortAndCountInversitions
from merge_sort import MergeAndCountSplitInversitions
from merge_sort import AllUsersSort
from merge_sort import ResultSort


def InPut():    #include the input
      f=open("input.txt")
      lst = []
      for row in f:
          strs = row.split(' ')
          for s in strs:
              if s != ' ':
                  lst = lst +[int(s)]
      AllUsers = int(lst[0]);
      AllFilms = int(lst[1]);
      array = np.zeros((AllUsers, AllFilms), dtype=int)
      t = 2
      for i in range (AllUsers):
          num = int(lst[t]);
          t+=1
          for j in range(AllFilms):
              array[i][j] = lst[t]
              t+=1
      f.close()
      return (AllUsers, AllFilms, array)

def OutPut(result, User, AllUsers):
    f = open("output.txt", 'wt')
    User +=1
    s = str(User) + '\n'
    f.write(s)
    for i in range(1, AllUsers):
     s1= str(result[i][0])
     s2= str(result[i][1])
     f.write(s1 +' ' + s2 +'\n')



AllUsers, AllFilms, array = InPut()
User = int(input("Choose the User to be compared:"))
User -=1;
array = AllUsersSort(array, User, AllUsers, AllFilms);
result = np.zeros((AllUsers, 2), dtype=int);
t=0;
for i in range(AllUsers):
   if i != User:
        t+=1
        result[t][0]=i+1
        massive = array[i]
        A, result[t][1] = SortAndCountInversitions(list(massive))
result = ResultSort(result, AllUsers)
OutPut(result, User, AllUsers)



