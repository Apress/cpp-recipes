print("I changed this!")
local x = 0
for i = 1, #cTable do
  print(i, cTable[i])
  x = x + cTable[i]
end
return x