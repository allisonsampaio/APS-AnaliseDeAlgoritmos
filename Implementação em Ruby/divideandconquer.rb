#the maximum-subarray problem applies to problems that consist of finding a maximum sum for a given subarray
#let's say we have an array of stock prices with sell and buy dates, and we find to maximum profit
#to find the maximum profit, we can do the brute force solution
#or we can find the maximum of the array being split on the right-side and left-side
#the maximum must exist within either the right-side, the left-side, or somewhere in between these two arrays
#this is called the divide and conquer approach
#https://github.com/jesusmaldonado/algorithms/blob/master/ch4/subarray.rb

def find_max_subarray(array, low, high)
  return [low, high, array[low]] if high == low
  mid = (low + high)/2
  left_low, left_high, left_sum = find_max_subarray(array, low, mid)
  right_low, right_high, right_sum = find_max_subarray(array, mid + 1, high)
  cross_low, cross_high, cross_sum = find_max_crossing(array, low, mid, high)
  return [left_low, left_high, left_sum] if left_sum >= right_sum && left_sum >= cross_sum
  return [right_low, right_high, right_sum] if right_sum >= left_sum && right_sum >= cross_sum
  return [cross_low, cross_high, cross_sum]
end

def find_max_crossing(array, low, mid, high)
  left_sum = -1
  sum = 0
  max_left = low
  (low...mid).each do |left_index|
    sum = sum + array[left_index]
    if sum > left_sum
      left_sum = sum
      max_left = left_index
    end
  end
  sum = 0
  right_sum = -1
  max_right = high
  (mid..high).each do |right_index|
    sum = sum + array[right_index]
    if sum > right_sum
      right_sum = sum
      max_right = right_index
    end
  end
  [max_left, max_right, left_sum + right_sum]
end

#p find_max_subarray([-1, 3,-1,-4, 2, 7, 1, -3], 0, 7)

##ruby implementation
def max_subarr(arr)
  return arr[0] if arr.size == 1
  mid = arr.length/2
  left = max_subarr(arr[(0...mid)])
  right = max_subarr(arr[(mid...arr.length)])
  cross = max_cross(arr)
  return left if left >= right && left >= cross
  return right if right >= left && right >= cross
  return cross
end

def max_cross(arr)
  mid = arr.length/2
  left_arr = arr[(0...mid)]
  left_sum = -1
  sum = 0
  left_arr.each do |element|
    sum += element
    left_sum = sum if sum >= left_sum
  end
  right_sum = 0
  sum = 0
  right_arr = arr[(mid...arr.length)]
  right_arr.each do |element|
    sum += element
    right_sum = sum if sum >= right_sum
  end
  right_sum + left_sum
end

arr = []
i=0
n = 2**20
File.open("../entradas/entrada1.txt", "r") do |f|
  f.each_line do |line|
    if i == n then
      break
    end
    arr << line.to_i
    i += 1
  end
end

Benchmark.bm(20) do |bm|  # The 20 is the width of the first column in the output.
    bm.report("Tempo: ") { 
      subarray_sum(arr)
    }
end