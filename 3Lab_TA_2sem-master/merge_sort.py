import numpy as np

def SortAndCountInversitions(A):  #inversion calculation procedure
   AllUsers =len(A)
   if AllUsers == 1:
       return (A, 0)
   else:
       Left= A[:int(len(A)/2)]
       Right= A[int(len(A)/2):]
       Left, x = SortAndCountInversitions(Left)
       Right, y = SortAndCountInversitions(Right)
       A, z = MergeAndCountSplitInversitions(A, Left, Right)
       return (A, x + y + z)


def MergeAndCountSplitInversitions(A, Left, Right):  #using the method of merge sort and count the split inversitions
    counter=0   #split inversion counter
    n1= len(Left)
    n2 = len(Right)
    i=0
    j=0
    lst=[]
    while i< n1 and j< n2:
        if Left[i] <= Right[j]:
            lst.append(Left[i])   #then go to the end of the list
            i += 1
        else:
            lst.append(Right[j])
            j += 1
            counter += (n1 -i)
    lst= lst + Left[i:]
    lst= lst + Right[j:]
    return lst, counter;

def ResultSort(result, AllUsers):     #sort the massive with result
  for i in range(AllUsers-1):
     for j in range(0, AllUsers-1):   
       if result[j][1] > result[j+1][1] : 
           result[j][1], result[j+1][1] = result[j+1][1],  result[j][1]
           result[j][0], result[j+1][0] = result[j+1][0],  result[j][0]
  return result


def AllUsersSort(array, User, AllUsers, AllFilms):      #sort the massive with AllUsers
  for i in range(AllFilms-1):
     for j in range(0, AllFilms-1):   
       if array[User][j] > array[User][j+1] : 
           for t in  range(AllUsers):
             array[t][j], array[t][j+1] = array[t][j+1], array[t][j]       
  return array
