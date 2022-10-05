import time
import random


def RadixSort(arr, d):           #the function of Radix Sorting
    place = 1                    #first digit
    for i in range(0, d):   
        CountingSort(arr, place)        #call the algorithm of counting sorting
        place *= 10 

def CountingSort(arr, place):     #the function of Counting Sorting
   output = [0] * len(arr)    
   count = [0] * 10     
   for i in range(0, len(arr)):  
       index = int((arr[i] / place)%10) 
       count[index] += 1    
   for i in range(1, 10):
        count[i] += count[i - 1]
   i = len(arr)-1 
   while i >= 0:
        index = int((arr[i] / place)%10) 
        output[count[index] - 1] = arr[i]   
        count[index] -= 1  
        i -= 1  
   for i in range(0, len(arr)):
        arr[i] = output[i]   

        #our main
n = [10, 100]                             #choose the size of the array
d = int(input("Number of digits:"))       #choose the digit number
    
for i in n:
        #arr = [55, 75, 12, 23, 45, 23, 78, 34, 35, 11]
        arr = [random.randint(10**(d-1),10**d-1 ) for x in range(i)]   #our array that are filled by the random numbers
        start = time.perf_counter()  
        RadixSort(arr, d)
        end =  time.perf_counter()
        ResultTime = end - start 
        print (arr)
        print("Size:", i)
        print ("Time:", end,"-", start,"=",ResultTime)   #Elapsed time during the whole program in seconds
        print ("RadixSort time:", ResultTime, "\n")