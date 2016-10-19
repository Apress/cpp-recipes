//============================================================================
// Name        : Chapter15-Ubuntu.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include "lua.hpp"

int main()
{
	lua_State* pLuaState{ luaL_newstate() };
	if (pLuaState)
	{
		luaL_openlibs(pLuaState);

		lua_close(pLuaState);
	}

	return 0;
}
