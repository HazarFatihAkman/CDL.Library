
# CDL.Library
That's a general dynamic array library that let's you to push/pop/remove and etc. in C

# Features
- [Numbers](#numbers)
- [Strings](#strings)

## numbers

supports
 - sort int
 - int
 - long
 - unsigned int
 - double
 - long double
 - float

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

pop
```c
// method definition
n_pop(l);

// example usage
numbers n_list = {0};
n_push(1, &n_list);
n_push(2, &n_list);

n_pop(&n_list);
```

remove
```c
// method definition
n_remove(i, l);

// example usage
numbers n_list = {0};
n_push(10, &n_list);
n_push(20, &n_list);

n_remove(2, &n_list);
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

pop
```c
// method definition
str_pop(l);

// example usage
strings str_list = {0};
str_push("Hazar Fatih Akman", &str_list);
str_push("Github", &str_list);

str_pop(&str_list);
```

remove
```c
// method definition
str_remove(i, l);

// example usage
strings str_list = {0};
str_push("Hazar Fatih Akman", &n_list);
str_push("Github", &n_list);

str_remove(1, &n_list);
```
