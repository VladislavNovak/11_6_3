# Задание 3. Валидация IP-адреса

---
## `Использовано`

`isNumber` для string

`split` для string

`all_of` для итерации по строке

---

## `Что нужно сделать`:

Проверьте, задаёт ли введённая пользователем строка корректный IP-адрес четвёртой версии (IPv4). 
IP-адрес должен представлять из себя четыре числа, разделённые точками без пробелов, причём 
каждое число должно быть в диапазоне от 0 до 255 включительно. Числа не должны содержать ведущих нулей. 
Других символов в строке, кроме вышеописанных, быть не должно.

Пользователь вводит строку, задающую IP-адрес через стандартный ввод. 
В результате программа должна вывести слово Valid, если адрес корректен, и слово Invalid, если это не так.

### `Примеры`

Корректные:
127.0.0.1
255.255.255.255
1.2.3.4
55.77.213.101

Некорректные:
255.256.257.258 (есть числа больше 255)
0.55.33.22. (лишняя точка в конце)
10.00.000.0 (лишние нули)
23.055.255.033 (опять лишние нули)
65.123..9 (две точки подряд)
a.b.c.d (посторонние символы вместо чисел и точек)
