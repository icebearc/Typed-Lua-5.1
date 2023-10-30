# Typed Lua in Lua 5.1 Implementation

This project was created by me back in early 2021 for a project I was working on. I have recently decided to make some of my repositories public, and this is one of them! The original inspiration for this project was Roblox's Luau language which, at the time, did not have a public repository. [Luau](https://github.com/luau-lang/luau) is now public, so check them out!
Feel free to make contributions to this repository, if you would like :)

## Overview

This repository hosts an implementation of Typed Lua in the Lua 5.1 programming language. Typed Lua extends Lua with static types while preserving the dynamic nature of the language. Typically an implementation of this ensures type safety and offers a seamless integration of types within Lua 5.1, enabling developers to write robust and scalable Lua code.
In this repository, we ONLY support the parsing of types, but not actual type checking. This repository also contains implementations for compound operators and continue statements.

## Features

- **Type Annotations**: Write code with explicit type annotations for variables, functions, and more, enhancing code clarity and maintainability.
- **Interoperability**: Seamlessly interact with existing Lua 5.1 codebases and libraries while enjoying the advantages of typing.
- **Continue statement**: Supports the continue control flow statement present in numerous other languages.
- **Compound assignment operators**: Utilize the power of compound assignment (+=, -=, *=, etc.)

## Examples

### Typed Lua
```lua
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
```

### Compound Assignment
```lua
local a = 1
a += 1
a *= 2
print(a)
```

### Continue Statement
```lua
for i = 1, 3 do
    if i == 2 then continue end

    print(i)
end
```
