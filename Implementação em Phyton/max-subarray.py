#https://codereview.stackexchange.com/questions/105561/producing-and-comparing-maximum-sub-array-sum-algorithms

#cubic brute force O(n^3)
def max_subarray_cubic(array):
    maximum = float('-inf')
    for i in range(1, len(array)):
        for j in range(i, len(array)):
            current_sum = 0
            for k in range(i, j):
                current_sum += array[k]
            maximum = max(maximum, current_sum)
    return maximum

#quadratic brute force O(n^2)
def max_subarray_quadratic(array):
  maximum = float('-inf')
  for i in range(0, len(array)):
    current = 0
    for j in range(i, len(array)):
       current += array[j]
       maximum = max(current, maximum)
  return maximum

#divide and conquer O(n*lg(n))
def max_cross_sum(array, low, mid, high):
  left_sum = float('-inf')
  sum_ = 0
  for i in range(mid, low, -1):
    sum_ += array[i]
    left_sum = max(left_sum, sum_)

  right_sum = float('-inf')
  sum_ = 0
  for i in range(mid + 1, high):
    sum_ += array[i]
    right_sum = max(right_sum, sum_)
  return left_sum + right_sum


def max_subarray_div_conquer(array, low, high):
  if low == high:
    return array[low]
  else:
    mid = (low + high) / 2
    return max(max_subarray_div_conquer(array, low, mid), 
               max_subarray_div_conquer(array, mid + 1, high),
               max_cross_sum(array, low, mid, high))


#Kadane's algorithm O(n)
def max_subarray_kadane(array):
    current = maximum = array[0]
    for x in array[1:]:
        current = max(x, current + x)
        maximum = max(maximum, current)
    return maximum