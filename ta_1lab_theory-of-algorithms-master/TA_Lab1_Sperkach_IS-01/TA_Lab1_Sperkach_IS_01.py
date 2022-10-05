
#сортуємо бульбашкою за порядком від парним до непарних
def pairnepair(arr):
  for i in range(len(arr)): 
    for j in range(len(arr)):
        if (j < len(arr) - 1) and (arr[j] % 2 != 0) and (arr[j + 1] % 2 == 0):
            arr[j], arr[j+1] = arr[j+1], arr[j]
            num = 0 

#сортування бульбашкою парні за зростанням
def sortpair(arr, num):
  for i in range(num): 
    for j in range(num):
        if j < num - 1 and arr[j] > arr[j+1]:
            arr[j], arr[j+1] = arr[j+1], arr[j]

#сортування бульбашкою непарні за спаданням
def sortunpair(arr, num):
   for i in range(num, len(arr)):
    for j in range(num, len(arr)):
        if j < len(arr) - 1 and  arr[j] < arr[j+1]:
            arr[j], arr[j+1] = arr[j+1], arr[j]




print("Бульбашкове сортування:")
num = 0 
print("Несортований масив:")
arr = [30, 19, 9, 15, 55, 24, 3, 78, 46, 41]
print(arr)
pairnepair(arr)

for x in range(len(arr)): 
    if arr[x] % 2 == 0:
        num += 1

sortpair(arr, num)
sortunpair(arr, num)

print("Bubble sort:")
print(arr)



print("Improved Bubble sort:")
print(arr)
