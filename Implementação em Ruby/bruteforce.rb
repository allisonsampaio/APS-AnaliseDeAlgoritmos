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

p subarray_sum(Array.new(1024) { rand(0...200) - 100 })