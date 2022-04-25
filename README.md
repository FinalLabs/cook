# Kook
A simple language that is compiled on runtime!
# Syntax
The syntax is fairly simple, there are 9 keywords; 2 yet to be implemented.

### Implemented
`add`
`sub`
`mul`
`div`
`mod`
`var`
`out`

### Not Implemented
`mov`
`cin`

A few notes, srings are immutable and numbers are the only thing really supported at this point in time; maybe in the future this will change.

# Examples

### Hi World
```
var hi_world = "hi world"
out hi_world
```
The output should just be `hi world`

### Simple addition and subtraction
```
var add_v = 10
add add_v by 20
out add_v

var sub_v = 20
sub sub_v by 10
out sub_v
```
The output on this is simply `30` (newline) `10`

Looking at this, the language is fairly simple and easy to learn; I will leave a dictionary for keywords and what they mean below.

`add` - Addition `add var by 2` <br />
`sub` - Subtraction `sub var by 2` <br />
`mul` - Multiplication `mul var by 2` <br />
`div` - Division `div var by 2` <br />
`mod` - Modulus `mod var by 2` <br />
`var` - Declare Variable `var ten = 10` or with strings `var hi_world = "hi world"` <br />
`out` - Just std::cout or "print" `out var_name` <br />
`mov` - Moving a variable into another variable, or assigning a new value to an existing variable (no syntax for this yet) <br />
`cin` - Just std::cin `cin var_name val` (not implemented) <br />

# Future Syntax

There will be future syntax, possibly implemented further on (obviously).

# Examples

### If statements

```
if var == var1 then
*code here*
end
```

Fairly simple, will add other operators as well most likely

### While loops

```
while var == var2 then
*code here*
end
```
