local x = 0
for i = 1, #cTable do
  print(i, cTable[i])
  x = x + cTable[i]
end
local average, sum = Sum(cTable[1], cTable[2], cTable[3])
print("Average: " .. average)
print("Sum: " .. sum)
return sum