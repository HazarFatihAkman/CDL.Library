
# CDL.Library
That's a general dynamic array library that let's you to push/pop/remove and etc. in C

# Features
- [Numbers](#numbers)
- [strings](#strings)

```li_t``` can be used for anything but numbers cause there's more strict rules for number types (int, float, decimal and etc.).

String example can be used for keyValuePair or anything else cause ```li_t``` items's ```void**```. So you push pointers to the list, not to copy the exact value of pointers.

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
#include "lib/cdl/listInterface.h"
```

push
```c
typedef li_t strings;
strings l = {0};

// push the value directly
push_v((void*)"Hazar Fatih Akman", &str_list);

// push the property
const char *str_val = "Github";
push_v((void*)str_val, &str_list);
```

pop
```c
// method definition
pop_v(l);

// example usage
strings str_list = {0};
push_v((void*)"Hazar Fatih Akman", &str_list);
push_v((void*)"Github", &str_list);

pop_v(&str_list);
```

remove
```c
// method definition
remove_at(i, l);

// example usage
strings str_list = {0};
push_v((void*)"Hazar Fatih Akman", &n_list);
push_v((void*)"Github", &n_list);

remove_at(1, &n_list);
```

