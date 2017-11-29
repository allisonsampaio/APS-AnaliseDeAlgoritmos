def subarray_sum(arr)
  max, sum, slice = 0, 0, []
  arr.each_index do |i|
    (i...arr.length).each do |j|
      sum = sum + arr[j]
      max, slice = sum, [i,j]  if sum > max
    end
    sum=0
  end
  [max, slice]
end

p subarray_sum(Array.new(1024) { rand(0...200) - 100 })