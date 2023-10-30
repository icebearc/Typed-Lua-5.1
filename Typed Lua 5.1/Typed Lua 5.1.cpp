#include <iostream>
#include <fstream>
#include <Windows.h>

extern "C"
{
    #include "lua/lobject.h"
    #include "lua/lua.h"
    #include "lua/lualib.h"
    #include "lua/lauxlib.h"
    #include "lua/ldo.h"
    #include "lua/lopcodes.h"
    #include "lua/lstring.h"
    #include "lua/lvm.h"
    #include "lua/lfunc.h"
    #include "lua/lundump.h"
}

int main()
{
    std::string script = R"(
-- Typed Lua
type Head = { Box : boolean }

local litten : Head = { Box = true }

print(litten.Box)

function add(a: number, b: number): number
    return a + b
end

print(add(1, 2))

local array : { [number] : string } = { "test" }
print(array[1])

local object : { x : number, y : any }

local foo : (number?)

export type Point = { x: number, y: number }
type Array<T> = { [number]: T }
type Something = typeof(string.gmatch("", "%d"))

function spawn(func : () -> void) end

-- Compound assignment
local a = 1
a += 1
print(a)

-- Continue
for i = 1, 3 do
    if i == 2 then continue end

    print(i)
end
)";
    
    lua_State* L = luaL_newstate();
    luaL_openlibs(L);

    if (luaL_loadstring(L, script.c_str()))
    {
        const char* err = lua_tostring(L, -1);
        lua_pop(L, 1);
        std::cout << err << std::endl;
    }
    else
    {
        std::cout << "Compilation Successful!" << std::endl;

        if (lua_pcall(L, 0, 0, 0) == LUA_ERRRUN)
        {
            const char* err = lua_tostring(L, -1);
            lua_pop(L, 1);
            std::cout << "Error: " << err << std::endl;
        }
    }
    return 0;
}