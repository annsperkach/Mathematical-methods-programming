from itertools import islice

class MaxHeap:      #незростаючa пірамідa
    def max(A):                #повернення максимального значення з незростаючої піраміди
        maxim = 0
        for x in range(A.size()):
          if(A.heap[x] > maxim):
               maxim = A.heap[x]
        return maxim
        
    def DelAndReturnMaxEl(A):    #видалення та повернення максимального значення з незростаючої піраміди
        if(len(A.heap) != 0):
            maxelement = max(A.heap)
            IndexMaxEl = A.heap.index(maxelement) 
            A.heap.pop(IndexMaxEl) 
            A.max_heapify(maxelement)
        return maxelement
        
    def IncreaseValue(A, ind, value):    #збільшення значення елементу піраміди за заданим індексом
        if(ind <= A.heap.count()):
            if(A.heap[ind] < value):
                A.heap[ind] = value
                A.max_heapify(A.heap, ind)
    
    def Insert(A, value):        
        A.heap.append(value)
        A.max_heapify(len(A.heap)-1)
        
    def max_heapify(A, ind):     #відновлення властивості незростаючої піраміди для заданого індексу
        left = 2*ind
        right = 2*ind+1
        if left < A.size() and A.heap[left] > A.heap[ind]:
            largest = right
        else:
            largest = ind
          
        if right < A.size() and A.heap[right] > A.heap[largest]:
            largest = right
            
        if largest != ind:
            A.heap[ind], A.heap[largest] = A.heap[largest], A.heap[ind]
            A.max_heapify(A.heap, largest)

    def __init__(A):            
        A.heap = []
        
    def size(A):                   
       return len(A.heap)

class MinHeap:  
    def min(A):
        minim = A.heap[0]
        for x in range(A.size()):
          if(A.heap[x] < minim):
               minim = A.heap[x]
        return minim
        
    def DelAndReturnMinEl(A):                        
        if len(A.heap) != 0:
            minelement = min(A.heap)
            IndexMinEl = A.heap.index(minelement)
            A.heap.pop(IndexMinEl)
            A.min_heapify(minelement)
        return minelement
      
    def DecreaseValue(A, ind, value):
        if(ind <= A.heap.count()):
            if(A.heap[ind] > value):
                A.heap[ind] = value
                A.min_heapify(A.heap, ind)

    def Insert(A, value):
        A.heap.append(value)
        A.min_heapify(len(A.heap)-1)

    def min_heapify(A, ind):
        left = 2*ind 
        right = 2*ind+1 
        if left < A.size() and A.heap[left] < A.heap[ind]: 
            largest = left
        else:
            largest = ind
          
        if right < A.size() and A.heap[right] < A.heap[largest]: 
            largest = right
            
        if largest != ind: 
            A.heap[ind], A.heap[largest] = A.heap[largest], A.heap[ind]
            A.min_heapify(A.heap, largest)

    def size(A):
        return len(A.heap)

    def __init__(A):
        A.heap = []


def GetMedian(value):        #Процедура визначення медіани для значення value
    global Heap_low
    global Heap_high

    if value <= Heap_low.max(): 
        Heap_low.Insert(value)
    else:
        Heap_high.Insert(value)
        
    if Heap_low.size() >= Heap_high.size() + 2:
        m = Heap_low.DelAndReturnMaxEl()
        Heap_high.Insert(m)
    elif Heap_high.size() >= Heap_low.size() + 2:
        m = Heap_high.DelAndReturnMinEl()
        Heap_low.Insert(m)
     
    #Вирахувати поточну медіану
    #якщо кількість елементів парна, то повертаємо найбільший з Heap_low і найменший з Heap_high
    if (Heap_low.size() + Heap_high.size())%2 == 0:
        return (Heap_low.max() , Heap_high.min())
    #якщо кількість елементів непарна, то повертаємо найбільший з Heap_high і найменший з Heap_low
    elif Heap_low.size() > Heap_high.size():
        return Heap_low.max() 
    else:
        return Heap_high.min()


Heap_low = MaxHeap()    #незростаюча піраміда для збереження меншої половини масиву
Heap_high = MinHeap()   #неспадна піраміда для збереження більшої половини масиву

    #our main
input = open("input.txt", 'r')
n = int(input.readline())    
A = []
for element in input:                                
    A.append(int(element)) 
input.close

output = open('is01_sperkach_06_output.txt', 'w')
for ind in range(n):                                    
     output.write(str(GetMedian(A[ind]))+"\n")      #визнаємо медіану підмасиву A
output.close()
    
