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

p subarray_sum(Array.new(1000000) { rand(0...200) - 100 })