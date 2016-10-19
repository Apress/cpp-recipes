for i=1, 10, 1 do
	print("Going for yield " .. i .. "!")
	coroutine.yield()
end