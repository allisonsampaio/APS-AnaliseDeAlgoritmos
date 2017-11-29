def subarray_sum(arr)
  curr = max = 0
  first, last, curr_first = arr.size, 0, 0
  arr.each_with_index do |e,i|
    curr += e
    if e > curr
      curr = e
      curr_first = i
    end
    if curr > max
      max = curr
      first = curr_first
      last = i
    end
  end
  return max, [first,last]
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

p subarray_sum(arr)