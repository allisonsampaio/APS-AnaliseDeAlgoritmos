def subarray_sum(arr)
  max, slice = 0, []
  arr.each_index do |i|
    (i...arr.length).each do |j|
      sum = arr[i..j].inject(0, :+)
      max, slice = sum, [i,j]  if sum > max
    end
  end
  [max, slice]
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