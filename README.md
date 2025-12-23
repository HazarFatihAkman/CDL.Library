
# CDL.Library
That's a general dynamic array library that let's you to push/pop/remove/read and etc. in C

# Features
- [Numbers](#numbers)
- [Strings](#strings)

## numbers

dependency

```c
#include "lib/cdl/numbers.h"
```

push 
```c
/// method definition
n_push(x, l);

// example usage
numbers n_list = {0};

// push the value directly
n_push(1, &n_list);

// push the property
int int_val = 2;
n_push(int_val, &n_list);
```

## strings

dependency
```c
#include "lib/cdl/strings.h"
```

push
```c
strings str_list = {0};

// push the value directly
str_push("Hazar Fatih Akman", &str_list);

// push the property
const char *str_val = "Github";
str_push(str_val, &str_list);
```
