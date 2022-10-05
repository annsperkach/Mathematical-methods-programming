import numpy as np
import random
from call import plot_data

sizes = [10, 100, 1000]  
#sizes = [10]                     
#sizes = [100]                   
#sizes = [1000]                 
                
types = ["random", "best", "worst"]
data_plot = {'random': {'bubble':{}, 'insertion':{}, 'bubble_impr':{}}, 
             'best': {'bubble':{}, 'insertion':{}, 'bubble_impr':{}},
             'worst': {'bubble':{}, 'insertion':{}, 'bubble_impr':{}}}


def generate_data(n, gen_typ="random"):
 
    if gen_type=="best":
        a = [i+1 for i in range(n)]
        return a
    elif gen_type=="worst":
        a = [i+1 for i in reversed(range(n))]
        return a
    else:
        a = [i+1 for i in range(n)]
        random.shuffle(a)
        return a

            
def bubble_sort(arr):  
  #print(arr)
  counter=0
  for i in range(len(arr)-1):
     for j in range(0, len(arr)-1):   
       counter+=1
       if arr[j] > arr[j+1] : 
          arr[j], arr[j+1] = arr[j+1], arr[j]       
  #print (arr) 
  return counter
    
def bubble_impr_sort(arr):
    counter =0
    #print (arr)
    swapped = True 
    endOfList = len(arr)-1
    while swapped:
        swapped = False
        for i in range(endOfList):
            counter += 1
            if arr[i] >= arr[i+1]:
                arr[i],arr[i+1] = arr[i+1],arr[i]
                swapped = True
        endOfList-=1
    #print (arr)
    return counter

def insertion_sort(arr):
    counter = 0       
    for i in range(1,len(arr)): 
        key = arr[i]   
        j = i-1                 
        while j>=0 and arr[j] > key:   
            counter +=1   
            arr[j+1] = arr[j]
            j -= 1
        arr[j+1] = key
        counter += 1                  
    print (arr) 

    min(arr)
    print ("\tМинимальный элемент в insertion sort:", min(arr))
    return counter




for n in sizes:
    print ("\nDATA SIZE: ", n)

    for gen_type in types:
        print( "\n\tDATA TYPE:", gen_type)
        data = generate_data(n, gen_type)
        
        data_bubble = np.copy(data)
        bubble_op_count = bubble_sort(data_bubble)
        print ("\tBubble sort Кол-во сравнений:", int(bubble_op_count))
        data_plot[gen_type]['bubble'][n] = bubble_op_count
        
        data_bubble_impr = np.copy(data)
        bubble_impr_op_count = bubble_impr_sort(data_bubble_impr)
        print ("\tImproved bubble sort Кол-во сравнений:", int(bubble_impr_op_count))
        data_plot[gen_type]['bubble_impr'][n] = bubble_impr_op_count

        data_insertion = np.copy(data)
        insertion_op_count = insertion_sort(data_insertion)
        print ("\tInsertion sort Кол-во сравнений:", int(insertion_op_count))
        data_plot[gen_type]['insertion'][n] = insertion_op_count
        

#Побудова графіків швидкодії алгоритмів
plot_data(data_plot, logarithmic=True, oneplot=True)

